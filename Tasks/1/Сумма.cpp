#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	float sum = 0;

	cout << "Введите число n: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i < n + 1; i++)
	{
		sum = sum + (float)1 / i;
	}

	cout << "Сумма ряда 1/n = " << sum;
	cout << endl << endl;

	system("pause");

	return 0;
}