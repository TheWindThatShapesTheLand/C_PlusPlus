#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "Rus");
	int num = 0, r = 0, k, max = 0, st = 1;
	char one, two;

	cout << "Количество символов?  ";
	cin >> k;

	char* A = new char[k];
	int* S = new int[k + 1];

	for (int i = 0; i < k; i++)
	{
		cin >> A[i];//ввод символов

		one = A[i - 1];
		two = A[i];
		if (one == two || i == k - 1)
		{
			num++;
			S[i] = num;
		}
		else
		{
			S[i] = num;
			num = 1;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (S[i] > max)
		{
			max = S[i];
			st = i;
		}
	}

	cout << "\nС учётом регистра:\n\t";

	if (max > 1)
	{
		for (int i = 0; i < max; i++)
		{
			cout << A[st - 1];
		}
	}
	else
	{
		cout << A[0];
	}
	///////////////////////////////////////////////////////
	for (int i = 0; i < k + 1; i++)
	{
		S[i] = 1;
	}
	num = 1;
	for (int i = 1; i < k; i++)
	{
		one = A[i - 1];
		two = A[i];

		if (two >= 65 && two <= 90)
		{
			two += 32;
		}
		if (one >= 65 && one <= 90)
		{
			one += 32;
		}
		if (one == two)
		{
			num++;
			if (i == k - 1)
			{
				S[i + 1] = num;
			}
		}
		if (two != one)
		{
			S[i] = num;
			num = 1;
		}
	}
	max = 0;
	st = 0;
	for (int i = 0; i < k + 1; i++)
	{
		if (S[i] > max)
		{
			max = S[i];
			st = i;
		}
	}
	st -= max;

	cout << "\nБез учёта регистра:\n\t";

	if (max > 1)
	{
		for (; max > 0; st++)
		{
			cout << A[st];
			max--;
		}
	}
	else
	{
		cout << A[0];
	}

	delete[] A;
	delete[] S;

	system("pause");
	return 0;
}