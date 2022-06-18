#include <iostream>
#include <iomanip>
using namespace std;

bool peresechenie(int X, int Y, int x1, int y1, int x2, int y2)
{
	double Ua, Ub;
	if (x1 == x2 && x1 != 0 && x2 != 0)
	{
		Ua = (x1 * (Y - y1) - (y2 - y1) * (X - x1)) / -x1;
		Ub = (X - x1) / x1;
	}
	else if (x1 == 0 || x2 == 0)
	{
		Ua = (x1 * (Y - y1) - (y2 - y1) * (X - x1));
		Ub = (X - x1);
	}
	else
	{
		Ua = ((x2 - x1) * (Y - y1) - (y2 - y1) * (X - x1)) / -(x2 - x1);
		Ub = (X - x1) / (x2 - x1);
	}

	if (0 <= Ub && Ub <= 1 && Ua >= 0)
	{
		return true;
	}
	else return false;
}


int main()
{
	setlocale(0, "Rus");
	int x, y, N, X, Y, ch;
	int a1, a2, b1, b2;

	cout << "Количество вершин многоугольника \n N(больше 2!)  = ";
	cin >> N;
	if (N <= 2)
	{
		cout << "\n\n\tN<= 2\n\n";
		system("pause");
		return 0;
	}
	int** T = new int* [N];
	for (int i = 0; i < N; i++)
	{
		T[i] = new int[2];
	}
	for (int i = 0; i < N; i++)//вершины многоугольника
	{
		cout << "\nx ";
		cin >> x;
		cout << "\ny ";
		cin >> y;
		T[i][0] = x;
		T[i][1] = y;
	}

	for (int i = 0; i < N; i++)//меняет местами
	{
		if (i < N - 1 && T[i][0] > T[i + 1][0])
		{
			swap(T[i][0], T[i + 1][0]);
			swap(T[i][1], T[i + 1][1]);
		}
		else if (i == N - 1 && T[i][0] < T[0][0])
		{
			swap(T[i][0], T[0][0]);
			swap(T[i][1], T[0][1]);
		}
	}
	for (int i = 0; i < N; i++)//выводит точки
	{
		for (int j = 0; j < 2; j++)
		{
			cout << setw(4) << T[i][j];
		}
		cout << endl << endl;
	}

	cout << "\nX = ";//точка
	cin >> X;
	cout << "\nY = ";
	cin >> Y;

	for (int i = 0; i < N; i++)//если точка на вершине
	{
		if (T[i][0] == X && T[i][1] == Y)
		{
			cout << "\n\nВнутри\n\n";

			for (int i = 0; i < N; i++)
			{
				delete[] T[i];
			}
			delete[] T;

			system("pause");
			return 0;
		}

	}
	for (int i = 0; i < N; i++)
	{
		ch = 0;
		for (int j = 0; j < 2; j++)
		{
			if (j == 0 && i < N - 1)
			{
				a1 = T[i][j];
				a2 = T[i + 1][j];
				b1 = T[i][j + 1];
				b2 = T[i + 1][j + 1];
				if (peresechenie(X, Y, a1, b1, a2, b2) == 1)
				{
					ch++;
				}
			}
			else if (j == 1 && i == N - 1)
			{
				a1 = T[0][j];
				a2 = T[i][j];
				b1 = T[0][0];
				b2 = T[i][0];
				if (peresechenie(X, Y, T[0][j], T[0][0], T[i][j], T[i][0]) == 1)
				{
					ch++;
				}
			}
			else if (j == 1 && i < N - 1)
			{
				a1 = T[i][j];
				a2 = T[i][0];
				b1 = T[0][0];
				b2 = T[i + 1][0];
				if (peresechenie(X, Y, T[i][j], T[i][0], T[i + 1][j], T[i + 1][0]) == 1)
				{
					ch++;
				}
			}
		}
	}

	if (ch % 2 == 0)
	{
		cout << "\n\nВнутри\n\n";
	}
	else if (ch % 2 != 0)
	{
		cout << "\n\nСнаружи\n\n";
	}

	for (int i = 0; i < N; i++)
	{
		delete[] T[i];
	}
	delete[] T;

	system("pause");
	return 0;
}
