#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;

void selectSort(int* arr, int size)//�������
{
	int tmp, pos;
	for (int i = 0; i < size; ++i) // i - ����� �������� ����
	{
		pos = i;
		tmp = arr[i];
		for (int j = i + 1; j < size; ++j) // ���� ������ ����������� ��������
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp; // ������ ������� ���������� � a[i]
	}
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " | ";
	}
}
///////////////////////////////////////������
//�-��� ��� ������ �������� �����
void swapEl(int* arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

void myShakerSort(int* arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;

		//cout << "\n��������: " << leftMark - 1; // �������� ���������� ��������
	}
}
/////////////////////////////////////////////��������

void merge(int* arr,int size, int l, int r) 
{
	if (r == l)
		return;
	if (r - l == 1) {
		if (arr[r] < arr[l])
			swap(arr[r], arr[l]);
		return;
	}
	int m = (r + l) / 2;
	merge(arr, size, l, m);
	merge(arr, size, m + 1, r);
	int* buf = new int[size];
	int xl = l, xr = m + 1, cur = 0;
	while (r - l + 1 != cur) {
		if (xl > m)
			buf[cur++] = arr[xr++];
		else if (xr > r)
			buf[cur++] = arr[xl++];
		else if (arr[xl] > arr[xr])
			buf[cur++] = arr[xr++];
		else buf[cur++] = arr[xl++];
	}
	for (int i = 0; i < cur; i++)
	{
		arr[i + l] = buf[i];
	}
	delete[] buf;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size;
	cout << "������ �������: ";
	cin >> size;
	int* arr = new int[size];

	for (int k = 0; k < size; k++)
	{
		arr[k] = rand() % 100;
		cout << arr[k] << " | ";
	}
	int num;
	cout << "\n\n����������:\n\t1 �������\n\t2 ���������\n\t3 ���������\n\t4 �������\n\n\t";
	cin >> num;
	
	switch (num)
	{
	case 4:
		
		merge(arr, size, 0, size - 1);
		for (int i = 0; i < size; i++)
			cout << arr[i] << " | ";
		_getch();//#include <conio.h>
		break;
	case 3:	
		myShakerSort(arr, size); // ����������
		cout << "\n������ ����� ����������:\n";
		for (int k = 0; k < size; k++)
		{
			cout << arr[k] << " | ";
		}
		cout << endl;
		break;
	case 2:		
		int temp; // ��������� ���������� ��� ������ ��������� �������
				
		for (int i = 0; i < size - 1; i++) // ���������� ������� ���������
		{
			for (int j = 0; j < size - i - 1; j++) 
			{
				if (arr[j] > arr[j + 1]) 
				{					
					temp = arr[j];// ������ �������� �������
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}		
		for (int i = 0; i < size; i++) // ����� ���������������� ������� �� �����
		{
			cout << arr[i] << " | ";
		}
		cout << endl;		
		break;
	case 1:
		selectSort(arr, size);
		break;

	default:
		break;
	}
	delete[] arr;
	system("pause");
	return 0;
}


	

	


