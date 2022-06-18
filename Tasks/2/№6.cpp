#include <iostream>
#include <time.h>
using namespace std;

int Check(int** T, int M, int N, int r, int i, int j, int w)
{
	if (w < r + 1 && i + r < N - 1 && j + r < M - 1)
	{
		if (T[i + r][j] == 1 && T[i + r][j + 1] == 1)
		{
			if (T[i][j + r] == 1)
			{
				i++;
				w++;
				return Check(T, M, N, r, i, j, w);
			}

			else if (T[i][j + r] == 0)
			{
				r--;
				return r;
			}
		}

		else if (T[i + r][j] == 0 || T[i + r][j + 1] == 0)

		{
			r--;
			return r;
		}
	}

	else
	{
		r++;
		return r;
	}
}

int Matr(int** T, int N, int M, int i, int j, int r, int e)
{
	int w = 0;

	if (i < N - 1 && j < M - 1)
	{
		if (T[i][j] == 1 && T[i + 1][j] == 1 && T[i][j + 1] == 1 && T[i + 1][j + 1] == 1)
		{
			Check(T, M, N, r, i, j, w);
			j++;
			return Matr(T, N, M, i, j, r, e);
		}

		else
		{
			if (r > e)
			{
				e = r;
				r = 2;
				j++;
				return Matr(T, N, M, i, j, r, e);
			}

			else if (r <= e)
			{
				r = 2;
				j++;
				return Matr(T, N, M, i, j, r, e);
			}
		}
	}

	else if (i < N - 1 && j >= M - 1)
	{
		j = 0;
		i++;
		return Matr(T, N, M, i, j, r, e);
	}

	else if (i == N - 1)
	{
		e = 1;
		return e;
	}
}

int main()
{
	srand(time(0));

	int i = 0, j = 0, r = 2, e = 2;

	int N;
	cout << "Enter N lines:";
	cin >> N;

	int M;
	cout << "Enter M colums:";
	cin >> M;

	if (N <= 0 || M <= 0)
	{
		cout << "Input error";
		return 0;
	}

	int** T = new int* [N];
	for (int i = 0; i < N; i++)
	{
		T[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			T[i][j] = rand() % 2;
			cout << T[i][j] << " ";
		}
		cout << endl;
	}

	int S = Matr(T, N, M, i, j, r, e) + 1;

	cout << endl << "max  square sub-matrix 1:" << S << "x" << S << endl;

	int** V = new int* [S];
	for (int i = 0; i < S; i++)
	{
		V[i] = new int[S];
	}

	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			V[i][j] = 1 + rand() % 1;
			cout << V[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++)
	{
		delete[] T[i];
	}
	delete[] T;

	for (int i = 0; i < S; i++)
	{
		delete[] V[i];
	}
	delete[] V;

	return 0;
}