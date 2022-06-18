#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N, M, C, R;
	int s;
	
	cout << "������� ���������� ����� N(������� 1): ";
	cin >> N;
	if (N <= 0 || N >= 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}

	cout << "������� ���������� �������� M(������� 1): ";
	cin >> M;
	if (M <= 0 || M >= 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}

	cout << "������� ���������� ����� C(������� 2) : ";
	cin >> C;
	if (C <= 0 || C >= 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}

	cout << "������� ���������� �������� R(������� 2) : ";
	cin >> R;
	if (R <= 0 || R >= 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}

	if (M != C)
	{
		cout << "\n������ ������� �������� ������\n";
		return 0;
	}

	int** T = new int* [N];//������ �������
	for (int t = 0; t < N; t++)
	{
		T[t] = new int[M];
	}

	int** A = new int* [C];//������ �������
	for (int i = 0; i < C; i++)
	{
		A[i] = new int[R];
	}

	int** F = new int* [N];//������ �������
	for (int t = 0; t < N; t++)
	{
		F[t] = new int[R];
	}

	for (int t = 0; t < N; t++)//��������� 1 �������
	{
		for (int i = 0; i < M; i++)
		{
			T[t][i] = rand() % 100;
			cout << T[t][i] << "\t";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (int i  = 0; i < C; i++)//��������� 2 �������
	{
		for (int j = 0; j < R; j++)
		{
			A[i][j] = rand() % 100;
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (int t = 0; t < N; t++)//��������� 3 ������� (�������� 1 �� 2)
	{
		for (int j = 0; j < R; j++)
		{
			s = 0;
			for (int i = 0; i < M; i++)
			{
				s+= T[t][i] * A[i][j];
			}
			F[t][j] = s;
			cout << F[t][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) { delete[] T[i]; }//������� ������������ �������
	delete[] T;
	for (int i = 0; i < C; i++) { delete[] A[i]; }
	delete[] A;
	for (int i = 0; i < N; i++) { delete[] F[i]; }
	delete[] F;

	system("pause");
	return 0;
}