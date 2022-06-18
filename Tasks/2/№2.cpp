/*����������� ������������ ������ �� ����� ������ ���� �������� A, B.�����������
����� �������, ��������� - ��� ��������� �� ������������ ������� A, B, �����
���������� �������� ������ m, ���������� ��������� ������ n.*/
#include<iostream>
#include<time.h>
using namespace std;

void Change(int *A, int *B, int n, int m, int D1, int D2)//������ �������, ������� ����� ��� �� ������
{
	for (int i = n - 1; i < n + m - 1; i++)//???�����-�� ������� ������ ������������(���������� ���-�� ����������)????
	{
		A[i] += B[i];
		B[i] = A[i] - B[i];
		A[i] -= B[i];
	}

	for (int i = 0; i < D1; i++)//������� �������������� 1-�� ������
	{
		cout << A[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < D2; i++)//������� �������������� 2-�� ������
	{
		cout << B[i] << "\t";
	}
}


 int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int  D1, D2, n, m ,r;

	cout << "����� ������� 1:";
	cin >> D1;
	cout << "������ ������� 2:";
	cin >> D2;

	 if ( D1 != D2)
	 {
		 cout << "������ �����";
		 return 0;
	 }
	
	int *A = new int [D1];//1 ������
	for (int i = 0; i < D1; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << "\t";
	}

	cout << endl;

	int* B = new int[D2];//2 ������
	for (int i = 0; i < D2; i++)
	{
		B[i] = rand() % 10;
		cout << B[i] << "\t";
	}

	cout << endl << "C ������ �� ����� ������� ��������?:";
	cin >> n >> m;

	if(m > D1 || m > D2 || n > D1 || n > D2 || n <= 0 || n > m)
	{
		cout << "������ �����";
		return 0;
	}
	
	Change(A, B, n, m, D1, D2);

	delete[] A;
	delete[] B;

	system("pause");
	return 0;
}