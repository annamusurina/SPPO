#include <iostream>

using namespace std;

struct element {
	double value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};

void InputList(element*& one, int N) {
	element* p = NULL;
	int i = 0;
	cout << "Введите каждый элемент ";
	while (i < N) {
		element* p1 = new element();
		cin >> p1->value;
		if (one == NULL) {
			one = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		i++;
	}
}

void OutputList(element* l) {
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}

void f1(int n, element* one) {
	element* p2;
	p2 = one;
	element* p3 = p2;
	element* p4 = NULL;
	int max = 0;
	for (int i = 0; i < n; i++, p2 = p2->pointer) {
		int count = 0;
		for (int j = i; j < n; j++) {
			if (p2->value == p3->value) {
				count++;
				p3 = p3->pointer;
			}
		}
		if (max < count) {
			max = count;
			p4 = p2;
		}
	}
	if (max != 0)
		cout << "Самый повторяющийся элемент " << p4->value;
	else
		cout << "Повторяющихся элементов нет" << endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	element* first = NULL;
	int N;

	cout << "Введите длину списка ";
	cin >> N;

	InputList(first, N);
	OutputList(first);

	f1(N, first);
	cout << endl;

	system("pause");
	return 0;
}