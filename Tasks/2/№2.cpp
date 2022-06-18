/*Реализовать перестановку равных по длине частей двух массивов A, B.Реализовать
через функцию, параметры - два указателя на динамические массивы A, B, номер
начального элемента замены m, количество элементов замены n.*/
#include<iostream>
#include<time.h>
using namespace std;

void Change(int *A, int *B, int n, int m, int D1, int D2)//создаём функцию, которая будет нам всё менять
{
	for (int i = n - 1; i < n + m - 1; i++)//???каким-то образом делаем перестановку(происходит что-то интересное)????
	{
		A[i] += B[i];
		B[i] = A[i] - B[i];
		A[i] -= B[i];
	}

	for (int i = 0; i < D1; i++)//выводим переставленный 1-ый массив
	{
		cout << A[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < D2; i++)//выводим переставленный 2-ой массив
	{
		cout << B[i] << "\t";
	}
}


 int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int  D1, D2, n, m ,r;

	cout << "Длина массива 1:";
	cin >> D1;
	cout << "Длинна массива 2:";
	cin >> D2;

	 if ( D1 != D2)
	 {
		 cout << "Ошибка ввода";
		 return 0;
	 }
	
	int *A = new int [D1];//1 массив
	for (int i = 0; i < D1; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << "\t";
	}

	cout << endl;

	int* B = new int[D2];//2 массив
	for (int i = 0; i < D2; i++)
	{
		B[i] = rand() % 10;
		cout << B[i] << "\t";
	}

	cout << endl << "C какого по какой элемент заменить?:";
	cin >> n >> m;

	if(m > D1 || m > D2 || n > D1 || n > D2 || n <= 0 || n > m)
	{
		cout << "Ошибка ввода";
		return 0;
	}
	
	Change(A, B, n, m, D1, D2);

	delete[] A;
	delete[] B;

	system("pause");
	return 0;
}