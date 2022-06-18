#include <iostream>

using namespace std;

/*Пусть задана матрица размером N строк на M столбцов(N<= 100, M<= 100).
Необходимо вывести на консоль матрицу, в которой все значения элементов
являются их координатами расположения в матрице.Номер строки и номер
столбца должен быть разделен запятой, элементы разделяются точкой с запятой.*/

int main() {
	setlocale(LC_ALL, "ru");
	const int R = 10; 
	const int C = 10;

	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < R; j++)
		{
			arr[i][j] = i;
			cout << arr[i][j] << ",";
			arr[i][j] = j;
			cout << arr[i][j] << ";" << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
