#include "CSet.h"

CSet::CSet() = default;

CSet::CSet(size_t n) : n(n) {
	size_arr = ceil((double)(n + 1) / 32);

	set = new uint[size_arr] {0};
}

void CSet::add(size_t size, uint* arr) {
	for (size_t i = 0; i < size; ++i) {
		size_t element = floor(arr[i] / 32);
		size_t shifts = arr[i] - 32 * element;
		set[element] |= (1 << shifts);
	}
}

CSet::CSet(const CSet& copySet) {
	n = copySet.n;
	size_arr = copySet.size_arr;
	set = new uint[size_arr];

	for (size_t i = 0; i < size_arr; ++i) {
		set[i] = copySet.set[i];
	}
}

CSet& CSet::operator=(const CSet& set2) {
	if (this != &set2) {
		n = set2.n;
		size_arr = set2.size_arr;

		delete_memory();

		set = new uint[size_arr];
		for (size_t i = 0; i < size_arr; ++i) {
			set[i] = set2.set[i];
		}	
	}

	return *this;
}

CSet::CSet(CSet&& moveSet) noexcept {
	std::swap(n, moveSet.n);
	std::swap(size_arr, moveSet.size_arr);
	std::swap(set, moveSet.set);
}

CSet& CSet::operator= (CSet&& set2) noexcept {
	
	if (this != &set2) {
		std::swap(n, set2.n);
		std::swap(size_arr, set2.size_arr);
		std::swap(set, set2.set);
	}
	return *this;
}



CSet::~CSet() {

	delete_memory();
}



std::ostream& operator<< (std::ostream& os, const CSet& ob) {

	os << "Size 1/32: " << ob.size_arr << "\n";

	// Reversed the sequence of bits for convenience.

	int r = 0;
	for (size_t i = 0; i < ob.size_arr; ++i) {
		const int size = sizeof(ob.set[i]) * CHAR_BIT;
		for (size_t j = 0; j < size; ++j) {
			r = r << 1 | (ob.set[i] & 1);
			ob.set[i] >>= 1;
		}
		std::bitset<size> bits(r);
		os << bits << " ";
	}

	return os;
}
