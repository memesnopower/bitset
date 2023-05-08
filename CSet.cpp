
#include "CSet.h"
#include <iostream>


CSet::CSet() = default;

CSet::CSet(int N) 
{
	this->N = floor(N + 1 / 32);
	if (this->N == 0)
	{
		Set = new unsigned int[this->N + 1];
	}
	else
	{
		Set = new unsigned int[this->N];
	}
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
	CSet ob(Set1.N);

	ob.Set[0] = Set1.Set[0] | Set2.Set[0];
	return ob;
}

CSet operator-(const CSet& Set1, const CSet& Set2) 
{
	CSet ob(Set1.N);

	ob.Set[0] = Set1.Set[0] & Set2.Set[0];
	return ob;
}

unsigned int* add(CSet& ob1, unsigned int* mainArr, int sizeOfmainArr) //переделать чтобы если кодичество чисел было больше 32, то arr[0] уже будет неверно
{
	for (size_t i = 0; i < sizeOfmainArr; ++i) 
	{
		ob1.Set[0] |= (1 << mainArr[i]);
	}

	return ob1.Set;
}

bool check(CSet& ob1, int num) 
{
	if (ob1.Set[0] & (1 << num)) 
	{
		return 1;
	}
	else {
		return 0;
	}
}

std::ostream& operator<<(std::ostream& os, const CSet& ob) {
	for (size_t i = 0; i < ob.)
}
