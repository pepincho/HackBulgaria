#include <iostream>

class HeapSort {
public:
	void sort(int*, int);
private:
	//void heapify(int*, int);
	//void swap(int, int, int*);
	void sift(int*, int, int);
};

void HeapSort::sort(int* sequence, int size) {

	int i = size / 2;

	while (i--) {
		sift(sequence, i, size);
	}

	i = size;

	while (--i) {
		std::swap(sequence[0], sequence[i]);
		sift(sequence, 0, i);
	}
}

void HeapSort::sift(int* pArr, int pos, int size) {
	
	// ������� ��������, ����� ������ �� �� �����������
	int elem = pArr[pos];

	int ni = pos; // ������ �� ����� �����
	int si = pos * 2 + 1; // ������ �� ����� ���������

	while (si < size) {

		// � ������� succ � �������� �� ����� ���������.
		// ��� ��� ����� ��������� � ��� � ��-�����,
		// ������ �� ��������� succ
		if (si < size - 1 && pArr[si] < pArr[si + 1]) {
			si++;
		}

		// ���� succ e ��������� �� ��-������� �� ����� ����������

		// ��� ���������, ����� ������ � ��-����� �� ��-������� ���������,
		// ����������� ��������
		if (elem > pArr[si]) {
			break;
		}

		pArr[ni] = pArr[si];
		ni = si;
		si = si * 2 + 1;
	}

	pArr[ni] = elem;
}

//int main() {
//
//	int sizeArr;
//	std::cout << "sizeArr: ";
//	std::cin >> sizeArr;
//
//	int* arr = new (std::nothrow) int[sizeArr];
//
//	for (int i = 0; i < sizeArr; i++) {
//		std::cin >> arr[i];
//	}
//
//	HeapSort test;
//
//	test.sort(arr, sizeArr);
//
//	std::cout << "result:" << std::endl;
//	for (int i = 0; i < sizeArr; i++) {
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;

//	return 0;

//}