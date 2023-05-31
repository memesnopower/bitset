#include <iostream>
#include "CSet.h"

int main() {
	size_t size = 3;
	size_t size2 = 5;

	uint* arr = new uint[size]{ 1, 3, 31};
	uint* arr2 = new uint[size2]{ 1, 2, 4, 5, 32};
	CSet ob1(31);
	ob1.add(3, arr);
	CSet ob2(32);
	ob2.add(5, arr2);

	std::cout << "ob1" << std::endl;
	std::cout << ob1 << std::endl;

	std::cout << "ob2" << std::endl;
	std::cout << ob2 << std::endl;

	CSet ob3(31);
	ob3.add(3, arr);

	std::cout << "++ob" << std::endl;
	std::cout << ++ob3 << std::endl;

	CSet ob4(32);
	ob4.add(5, arr2);

	std::cout << "--ob" << std::endl;
	std::cout << --ob4<< std::endl;

	CSet ob5(31);
	ob5.add(3, arr);

	std::cout << "ob++" << std::endl;
	std::cout << ob5++ << std::endl;

	CSet ob6(32);
	ob6.add(5, arr2);

	std::cout << "ob--" << std::endl;
	std::cout << ob6-- << std::endl;



	CSet ob7(31);
	ob7.add(3, arr);
	CSet ob8(32);
	ob8.add(5, arr2);

	std::cout << "ob1+ob2" << std::endl;
	std::cout << ob7+ob8 << std::endl;


	CSet ob9(31);
	ob9.add(3, arr);
	CSet ob10(32);
	ob10.add(5, arr2);
	
	std::cout << "ob1-ob2" << std::endl;
	std::cout << ob10 - ob9 << std::endl;


	delete[] arr;
	delete[] arr2;
	return 0;
}
