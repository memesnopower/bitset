#include <bitset>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

typedef unsigned int uint;

class CSet {

public:
	CSet();
	CSet(size_t n);
	CSet(const CSet& copySet);
	CSet& operator=(const CSet& set2);
	CSet(CSet&& moveSet) noexcept;
	CSet& operator= (CSet&& set2) noexcept;
	~CSet();

	CSet& operator++();
	CSet& operator--();
	CSet operator++(int);
	CSet operator--(int);


	void add(size_t size, uint* arr);
	bool check(uint num) const;
	friend std::ostream& operator<< (std::ostream& os, const CSet& ob);
	friend CSet operator+(const CSet& set1, const CSet& set2);
	friend CSet operator-(const CSet& set1, const CSet& set2);


private:
	size_t n = 0; 
	size_t size_arr = 0;
	uint* set = nullptr;

	void delete_memory() {
		if (set != nullptr) {
			delete[] set;
		}
	}

};
