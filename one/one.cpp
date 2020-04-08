#include <iostream>
#include <cmath>

using namespace std;

double f1(double n) {
	double v;
	if (n < 0)
		v = sin(n) * sin(n) + cos(n) * cos(n);
	else
		v = sin(n * n);
	return v;
}

double f2(double& x) {
	x = f1(x);
	return x;
}

int main() {
	setlocale(LC_ALL, "rus");

	double x, y, b;
	cout << "Введите первое значение ";
	cin >> x;
	cout << "Введите количество ";
	cin >> y;
	cout << "Введите шаг ";
	cin >> b;

	double n = x;
	cout << endl;

	cout << "Работа первой функции " << endl;

	for (int i = 1; i <= y; i++, x += b) {
		cout << "Значение " << x << " результат " << f1(x);
		cout << endl;
	}
	cout << endl;

	cout << "Работа второй функции " << endl;

	for (int i = 1; i <= y; i++, n += b) {
		cout << "Результат " << f2(n);
		cout << endl;
	}

	system("pause");
	return 0;
}