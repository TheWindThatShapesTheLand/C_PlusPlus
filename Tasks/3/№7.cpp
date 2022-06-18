#include<iostream>
#include<ctime>
using namespace std;

void bubbleSort(double** arr, int size)//////пузырёк
{	
	double* temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*arr[j] < *arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int c;
	cout << "Размер массива: ";
	cin >> c;

	double* T = new double[c];
	double** P = new double* [c];

	for (int i = 0; i < c; i++)
	{		
		T[i] = rand() % 100;
	}	
	for (int i = 0; i < c; i++)
	{
		P[i] = &T[i];
	}

	cout << endl;

	for (int i = 0; i < c; i++)
	{
		cout << T[i] << " - " << P[i] << "\n";
	}

	bubbleSort(P, c);

	cout << "\n//////////////////////////////////////////" <<endl;

	for (int i = 0; i < c; i++)
	{		
		cout << P[i] << " - " << *P[i] << "\n";
	}
	cout << endl;
	delete[] T;
	delete[] P;

	system("pause");
	return 0;
}