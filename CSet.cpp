#include "CSet.h"


CSet::CSet() = default;

CSet::CSet(int N) 
{
	this->N = ceil(((double) N + 1) / 32);

	Set = new unsigned int[this->N];

	for (size_t i = 0; i < this->N; ++i)	
	{
		this->Set[i] = 0;
	}
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



CSet operator+(const CSet& Set1, const CSet& Set2) 
{
	if (Set1.N > Set2.N) {
		CSet ob(Set1.N);
		ob.Set[0] = Set1.Set[0] | Set2.Set[0];

		return ob;
	}
	else {
		CSet ob(Set2.N);
		ob.Set[0] = Set1.Set[0] | Set2.Set[0];

		return ob;
	}

}

CSet operator-(const CSet& Set1, const CSet& Set2) 
{
	if (Set1.N > Set2.N) {
		CSet ob(Set1.N);
		ob.Set[0] = Set1.Set[0] & Set2.Set[0];

		return ob;
	}
	else {
		CSet ob(Set2.N);
		ob.Set[0] = Set1.Set[0] & Set2.Set[0];

		return ob;
	}
}

CSet add(CSet& ob, unsigned int* mainArr, int size)
{
	for (size_t i = 0; i < size; ++i) 
	{
		ob.Set[0] |= (1 << mainArr[i]);
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
		os << std::bitset<sizeof(ob.Set[i])* CHAR_BIT>(ob.Set[i]) << std::endl;
	}
	for (size_t i = 0; i < ob.N; ++i) {
		for (size_t j = 0; j < 32; ++j) {
			bool flag = (bool((1 << j) & ob.Set[i]));
			if (flag == true) {
				vec.push_back(j);
			}
		}
	}

	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}

	return os;
}	
