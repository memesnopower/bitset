
#pragma once
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

class CSet {
	int N;
	unsigned int* Set = nullptr;

public:

	CSet();
	CSet(int N);
	CSet(const CSet& CS);
	CSet(CSet&& MS) noexcept;
	CSet& operator =(const CSet& Set2);
	CSet& operator =(CSet&& Set2) noexcept;
	~CSet();

	CSet& operator++();
	CSet& operator--();
	CSet& operator++(int);
	CSet& operator--(int);

	friend CSet add(CSet& ob, unsigned int* mainArr, int size);
	friend bool check(CSet& ob1, int num);
	friend CSet operator+(const CSet& Set1, const CSet& Set2);
	friend CSet operator-(const CSet& Set1, const CSet& Set2);
	friend std::ostream& operator<<(std::ostream& os, const CSet& ob);
};
