
#include "CSet.h"


CSet::CSet() = default;

CSet::CSet(int N)
{
	this->N = N;
	this->size_arr = ceil((double)(N + 1) / 32);

	//std::cout << this->N << std::endl;

	Set = new unsigned int[size_arr] {0};

	/*for (size_t i = 0; i < this->N; ++i)
	{
		this->Set[i] = 0;
	}*/
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

	if (this->N % 32 == 0) {
		this->size_arr++;
		this->N++;
		unsigned int* new_set = new unsigned int[size_arr];

		for (size_t i = 0; i < size_arr-1; ++i) {
			new_set[i] = this->Set[i];
		}
		new_set[size_arr - 1] = 0;

		delete[] Set;
		Set = new_set;
		return *this;
	}
	else {
		this->N++;
		return *this;
	}

}

//CSet& CSet::operator--() {
//	int old_size = 0;
//	old_size = this->N;
//	this->N--;
//
//	if (N == 0) {
//		unsigned int* new_set = nullptr;
//		delete[] Set;
//		Set = new_set;
//	}
//	else {
//		unsigned int* new_set = new unsigned int[N];
//
//		for (size_t i = 0; i < N; ++i) {
//			if (i == old_size - 1) {
//				break;
//			}
//			else {
//				new_set[i] = this->Set[i];
//			}
//		}
//
//		delete[] Set;
//		Set = new_set;
//	}
//	return *this;
//}
//
//CSet operator+(const CSet& Set1, const CSet& Set2)
//{
//	/*std::vector<size_t> vec;
//	for (size_t i = 0; i < Set1.N; ++i) {
//		vec.push_back(Set1.Set[i]);
//	}
//
//	for (size_t i = 0; i < Set2.N; ++i) {
//		vec.push_back(Set2.Set[i]);
//	}
//	unsigned int* arr = new unsigned int[vec.size()];
//
//	for (size_t i = 0; i < vec.size(); ++i) {
//		arr[i] = vec[i];
//	}
//	CSet ob(arr, vec.size());
//
//	return ob;
//
//	delete[] arr;*/
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
	os << "Размерность битового массива (1 = 32 бита): " << ob.N << std::endl;
	for (size_t i = 0; i < ob.N; ++i) {
		os << std::bitset<sizeof(ob.Set[i]) * CHAR_BIT>(ob.Set[i]);
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
