
#include "CSet.h"

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

	CSet ob1(arr1, N);
	add(ob1, arr1, N);

	std::cout << "Первое множество: " << std::endl;
	std::cout << ob1 << std::endl;

	CSet ob2(arr2, M);
	add(ob2, arr2, M);

	std::cout << "Второе множество: " << std::endl;
	std::cout << ob2 << std::endl;

	CSet ob_copy(arr1, N);
	ob_copy = ob1;

	std::cout << "Конструктор копирования: " << std::endl;
	std::cout << ob_copy << std::endl;

	CSet ob3(arr1, N);
	CSet ob_move(arr1, N);
	add(ob3, arr1, N);
	ob_move = std::move(ob3);

	std::cout << "Конструктор перемещения: " << std::endl;
	std::cout << ob_move << std::endl;

	/*CSet ob_merged(arr1, N);
	CSet ob4(arr1, N);
	CSet ob5(arr2, M);
	add(ob4, arr1, N);
	add(ob5, arr2, M);

	ob_merged = ob4 + ob5;

	std::cout << "Тест operator+ или же объединение множеств: " << std::endl;
	std::cout << ob_merged << std::endl;



	CSet ob_intersection(arr1, N);
	CSet ob6(arr1, N);
	CSet ob7(arr2, M);
	add(ob6, arr1, N);
	add(ob7, arr2, M);

	ob_intersection = ob6 - ob7;

	std::cout << "Тест operator- или же пересечение множеств: " << std::endl;
	std::cout << ob_intersection << std::endl;*/



	delete[] arr1;
	delete[] arr2;
}
