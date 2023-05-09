
#include "CSet.h"

int maxNum(unsigned int* arr, int size) {
	int key = 0;
	size_t i = 0;
	for (size_t j = 1; j < size; j++) {
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
			arr[i + 1] = key;
		}
	}
	return arr[size - 1];
}

int main() {
	setlocale(LC_ALL, "rus");

	int N = 0;
	int M = 0;

	std::cout << "Введите размерность первого множества: " << std::endl;
	std::cin >> N;
	std::cout << "Введите размерность второго множества: " << std::endl;
	std::cin >> M;

	unsigned int* arr1 = new unsigned int[N];
	unsigned int* arr2 = new unsigned int[M];

	std::cout << "Введите первый массив: " << std::endl;
	for (size_t i = 0; i < N; ++i) {
		std::cin >> arr1[i];
	}

	std::cout << "Введите второй массив: " << std::endl;
	for (size_t i = 0; i < M; ++i) {
		std::cin >> arr2[i];
	}

	//std::cout << maxNum(arr1, N);

	int max1 = maxNum(arr1, N);
	int max2 = maxNum(arr2, M);
	CSet ob1(max1);
	add(ob1, arr1, N);

	std::cout << ob1 << std::endl;
	
	CSet ob2(max2);
	add(ob2, arr2, M);
	std::cout << ob2 << std::endl;


	delete[] arr1;
	delete[] arr2;
}
