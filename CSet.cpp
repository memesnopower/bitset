
#include "CSet.h"


CSet::CSet() = default;

CSet::CSet(int N)
{
	this->N = N;
	this->size_arr = ceil((double)(N + 1) / 32);

	Set = new unsigned int[size_arr] {0};

}

CSet::CSet(const CSet& CS)
{
	N = CS.N;
	this->Set = new unsigned int[N];
	for (size_t i = 0; i < N; ++i)
	{
		this->Set[i] = CS.Set[i];
	}
}

CSet::CSet(CSet&& MS) noexcept
{
	std::swap(N, MS.N);
	std::swap(Set, MS.Set);
}

CSet& CSet::operator =(const CSet& Set2)
{
	if (this != &Set2)
	{
		N = Set2.N;
		if (Set != nullptr)
		{
			delete[] Set;
		}
		Set = new unsigned int[N];
		for (size_t i = 0; i < N; ++i)
		{
			Set[i] = Set2.Set[i];
		}
	}
	return *this;
}

CSet& CSet::operator =(CSet&& Set2) noexcept
{
	if (this != &Set2)
	{
		std::swap(Set, Set2.Set);
		std::swap(N, Set2.N);
	}
	return *this;
}

CSet::~CSet()
{
	if (Set != nullptr)
	{
		delete[] Set;
	}
}

CSet& CSet::operator++() {

	if ((this->N+1) % 32 == 0) {
		this->size_arr++;
		this->N++;
		unsigned int* increment_set = new unsigned int[size_arr];

		for (size_t i = 0; i < size_arr - 1; ++i) {
			increment_set[i] = this->Set[i];
		}
		increment_set[size_arr - 1] = 0;

		delete[] Set;
		Set = increment_set;
		return *this;
	}
	else {
		this->N++;
		return *this;
	}

}

CSet& CSet::operator--() {
	
	if ((this->N + 1) % 32 == 1) {
		size_t old_size_arr = this->size_arr;
		this->size_arr--;
		this->N--;

		if (this->size_arr == 0) {
			unsigned int* decrement_set = nullptr;
			delete[] Set;
			Set = decrement_set;
		}
		else {
			unsigned int* decrement_set = new unsigned int[size_arr];

			for (size_t i = 0; i < size_arr; ++i) {
				if (i == old_size_arr - 1) {
					break;
				}
				else {
					decrement_set[i] = this->Set[i];
				}
			}
			delete[] Set;
			Set = decrement_set;
		}
		return *this;

	}
	else {
		int old_max_num = this->N;
		this->N--;

		for (size_t i = 0; i < size_arr; ++i) {
			size_t element = floor(old_max_num / 32);   //доделать чтобы если было 1 число, то массив был равен nullptr;
			this->Set[element] &= ~(1 << old_max_num);
		}

		return *this;
	}

}

//CSet operator+(const CSet& Set1, const CSet& Set2)
//{
//	if (Set1.N > Set2.N) {
//		CSet ob(Set1.N);
//		size_t new_arr_size = Set2.size_arr + 1;
//		//std::cout << new_arr_size;
//		unsigned int* new_set = new unsigned int[new_arr_size];
//
//		for (size_t i = 0; i < new_arr_size-1; ++i) {
//			new_set[i] = Set2.Set[i];
//		}
//		new_set[new_arr_size - 1] = 0;
//
//		delete[] Set2.Set;
//		Set2.Set = new_set;
//
//		for (size_t i = 0; i < Set1.size_arr; ++i) {
//			ob.Set[i] = Set1.Set[i] | new_set[i];
//		}
//
//		return ob;
//	}
//	
//
//}
//
//CSet operator-(const CSet& Set1, const CSet& Set2)
//{
//	if (Set1.N < Set2.N) {
//		for (size_t i = 0; i < Set1.N; ++i) {
//			CSet ob(Set1.Set, Set1.N);
//			ob.Set[i] = Set1.Set[i] & Set2.Set[i];
//
//			return ob;
//		}
//	}
//	else {
//		for (size_t i = 0; i < Set2.N; ++i) {
//			CSet ob(Set2.Set, Set2.N);
//			ob.Set[i] = Set1.Set[i] & Set2.Set[i];
//
//			return ob;
//		}
//	}
//}

CSet add(CSet& ob, unsigned int* mainArr, int size)
{
	for (size_t i = 0; i < size; ++i) {
		size_t element = floor(mainArr[i] / 32);
		size_t shifts = mainArr[i] - 32 * element;
		ob.Set[element] |= (1 << shifts);
	}
	return ob;
}

bool check(CSet& ob, int num)
{
	for (size_t i = 0; i < ob.N; ++i) {
		if (ob.Set[i] & (1 << num))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


std::ostream& operator<<(std::ostream& os, const CSet& ob) {
	std::vector<size_t> vec;
	os << "Размерность битового массива (1 = 32 бита): " << ob.size_arr << std::endl;
	for (size_t i = 0; i < ob.size_arr; ++i) {
		os << std::bitset<sizeof(ob.Set[i])* CHAR_BIT>(ob.Set[i]);
		os << ".";
	}
	/*for (size_t i = 0; i < ob.N; ++i) {
		for (size_t j = 0; j < 32; ++j) {
			bool flag = (bool((1 << j) & ob.Set[i]));
			if (flag == true) {
				vec.push_back(j);
			}
		}
	}

	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}*/

	return os;
}
