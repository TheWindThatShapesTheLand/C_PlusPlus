#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int sum = 0 , x, a, b = 0;
	double aver;

	cout << "Сколько чисел вы хотите ввести? ";
	cin >> a;

	for (int i = 0; i < a ;i++)
	{
		cout << "Введите число: ";
		cin >> x;
		if (x > 0)
		{
			sum += x;
			b++;
		}
	}
	aver = (double)sum / b;
	cout << "Среднее арифметическое положительных чисел = " << aver;

	system ("pause");
}
