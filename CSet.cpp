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
	size_arr = CS.size_arr;
	N = CS.N;
	this->Set = new unsigned int[size_arr];
	for (size_t i = 0; i < size_arr; ++i)
	{
		this->Set[i] = CS.Set[i];
	}
}

CSet::CSet(CSet&& MS) noexcept
{
	std::swap(size_arr, MS.size_arr);
	std::swap(N, MS.N);
	std::swap(Set, MS.Set);
}

CSet& CSet::operator =(const CSet& Set2)
{
	if (this != &Set2)
	{
		size_arr = Set2.size_arr;
		N = Set2.N;
		if (Set != nullptr)
		{
			delete[] Set;
		}
		Set = new unsigned int[size_arr];
		for (size_t i = 0; i < size_arr; ++i)
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
		std::swap(size_arr, Set2.size_arr);
		std::swap(N, Set2.N);
	}
	return *this;
}

CSet& CSet::operator++() {

	if ((this->N + 1) % 32 == 0) {
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
		if (N == 0) {
			this->Set = nullptr;
		}
		else {
			for (size_t i = 0; i < size_arr; ++i) {
				size_t element = floor(old_max_num / 32);  
				this->Set[element] &= ~(1 << old_max_num);
			}
		}


		return *this;
	}

}

CSet& CSet::operator++(int) {
	CSet temp(*this);
	if ((this->N + 1) % 32 == 0) {
		this->size_arr++;
		this->N++;
		unsigned int* increment_set = new unsigned int[size_arr];

		for (size_t i = 0; i < size_arr - 1; ++i) {
			increment_set[i] = this->Set[i];
		}
		increment_set[size_arr - 1] = 0;

		delete[] Set;
		Set = increment_set;
		return temp;
	}
	else {
		this->N++;
		return temp;
	}
}

CSet& CSet::operator--(int) {
	CSet temp(*this);
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
		return temp;

	}
	else {
		int old_max_num = this->N;
		this->N--;
		if (N == 0) {
			this->Set = nullptr;
		}
		else {
			for (size_t i = 0; i < size_arr; ++i) {
				size_t element = floor(old_max_num / 32);
				this->Set[element] &= ~(1 << old_max_num);
			}
		}


		return temp;
	}
}

//CSet operator+(const CSet& Set1, const CSet& Set2) {
//	
//	size_t max = 0;
//	size_t min = 0;
//	max = std::max(Set1.size_arr, Set2.size_arr);
//	min = std::min(Set1.size_arr, Set2.size_arr);
//	unsigned int* set = new unsigned int[max];
//	CSet ob(max);
//
//	if (min == Set1.size_arr) {
//		for (size_t i = 0; i < min; ++i) {
//			set[i] = Set1.Set[i];
//		}
//
//		for (size_t i = min; i < max; ++i) {
//			set[i] = 0;
//		}
//
//		for (size_t i = 0; i < max; ++i) {
//			ob.Set[i] = set[i] | Set2.Set[i];
//		}
//
//		return ob;
//	}
//	else {
//		for (size_t i = 0; i < min; ++i) {
//			set[i] = Set2.Set[i];
//		}
//
//		for (size_t i = min; i < max; ++i) {
//			set[i] = 0;
//		}
//
//		for (size_t i = 0; i < max; ++i) {
//			ob.Set[i] = set[i] | Set1.Set[i];
//		}
//
//		return ob;
//	}
//
//	delete[] set;
//	//size_t max = 0;
//	//size_t min = 0;
//	//max = std::max(Set1.size_arr, Set2.size_arr);
//	//min = std::min(Set1.size_arr, Set2.size_arr);
//	//std::cout << "max" << max;
//	//std::cout << "min" << min;
//	//unsigned int* merged_set = new unsigned int[max];
//
//	//CSet ob(max);
//	//if (min == Set1.size_arr) {
//	//	unsigned int* more_set = new unsigned int[max];
//
//	//	/*for (size_t i = 0; i < Set1.size_arr; ++i) {
//	//		std::cout << Set1.Set[i];
//	//	}
//	//	std::cout << std::endl;*/
//
//	//	for (size_t i = 0; i < min; ++i) {
//	//		more_set[i] = Set1.Set[i];
//	//	}
//
//	//	for (size_t i = 0; i < max - min; ++i) {
//	//		more_set[i + min] = 0;
//	//	}
//	//	
//	//	for (size_t i = 0; i < max; ++i) {
//	//		ob.Set[i] = Set2.Set[i] | more_set[i];
//	//	}
//
//	//	delete[] more_set;
//
//	//	return ob;
//	//}
//	//else {
//	//	unsigned int* more_set = new unsigned int[max];
//	//	for (size_t i = 0; i < min; ++i) {
//	//		more_set[i] = Set2.Set[i];
//	//	}
//
//	//	for (size_t i = 0; i < max-min; ++i) {
//	//		more_set[i + min] = 0;
//	//	}
//
//	//	for (size_t i = 0; i < max; ++i) {
//	//		ob.Set[i] = Set1.Set[i] | more_set[i];
//	//	}
//	//	delete[] more_set;
//
//	//	return ob;
//	//}
//	
//	
//}

CSet operator-(const CSet& Set1, const CSet& Set2) {
	size_t min = 0;
	min = std::min(Set1.size_arr, Set2.size_arr);

	unsigned int* less = new unsigned int[min];
	CSet ob(min);

	if (min == Set1.size_arr) {
		for (size_t i = 0; i < min; ++i) {
			less[i] = Set2.Set[i];
		}

		for (size_t i = 0; i < min; ++i) {
			ob.Set[i] = less[i] & Set1.Set[i];
		}

	}
	else {
		for (size_t i = 0; i < min; ++i) {
			less[i] = Set1.Set[i];
		}

		for (size_t i = 0; i < min; ++i) {
			ob.Set[i] = less[i] & Set2.Set[i];
		}

	}

	
	if (less != nullptr) {
		delete[] less;
	}

	return ob;
}

CSet::~CSet()
{
	if (Set != nullptr)
	{
		delete[] Set;
	}
}

CSet add(CSet& ob, unsigned int* mainArr, int size)
{
	for (size_t i = 0; i < size; ++i) {
		size_t element = floor(mainArr[i] / 32);
		size_t shifts = mainArr[i] - 32 * element;
		ob.Set[element] |= (1 << shifts);
	}
	return ob;
}

std::ostream& operator<<(std::ostream& os, const CSet& ob) {
	std::vector<size_t> vec;
	os << "Размерность битового массива (1 = 32 бита): " << ob.size_arr << std::endl;
	for (size_t i = 0; i < ob.size_arr; ++i) {
		os << std::bitset<sizeof(ob.Set[i]) * CHAR_BIT>(ob.Set[i]);
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
