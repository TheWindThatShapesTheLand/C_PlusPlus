#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int N, M;
	int j = 0, a = 0, r = 1;


	cout << "������� ���������� ����� : ";
	cin >> N;
	if (N <= 0 || N > 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}


	cout << "������� ���������� �������� : ";
	cin >> M;
	if (M <= 0 || M > 100)
	{
		cout << "\n������ �����\n";
		return 0;
	}

	int** T = new int* [N];
	for (int i = 0; i < N; i++)
	{
		T[i] = new int[M];
	}//c����� �������. ������ � (�� �������� N � M) � ����������� ������ ��� ����


	for (int i = 0; i <= N * M; i++)
	{
		a++;
		for (j = a - 1; j < M - a + 1; j++)
		{
			T[a - 1][j] = r++;
		}   //����� ����


		for (j = a; j < N - a + 1; j++)
		{
			T[j][M - a] = r++;
		}   // ������ ����


		for (j = M - a - 1; j >= a - 1; j--)
		{
			T[N - a][j] = r++;
		}   //������ ���


		for (j = N - a - 1; j >= a; j--)
		{
			T[j][a - 1] = r++;
		}   //����� ���
	}


	for (int i = 0; i < N; i++)//������� ������������ �������� � ���������
	{
		for (j = 0; j < M; j++)
		{
			cout << setw(4) << T[i][j];
		}

		cout << endl;
	}


	for (int i = 0; i < N; i++)
	{
		delete[] T[i];
	}


	delete[] T;//������� ������ �� ������� � ��� ����, ����� ������ �� ����������


	system("pause");
	return 0;
}