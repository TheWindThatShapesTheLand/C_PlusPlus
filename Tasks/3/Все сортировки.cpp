#include <iostream>
#include <time.h>
using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
};

void SelectionSort(int* arr, int size);
void ScheikerSort(int* arr, int size);
void InsertSort(int* arr, int size);
int* block_sort(int* arr, int size);
void heapsort(int* arr, int size);



void TreeSort(int* arr, int size);
void add_to_tree(int val, Tree* Tr);
void Print_mas(Tree* Tr);
void delete_tree(Tree* Tr);



int main()
{
	srand(time(NULL));
	int Length = 100;
	int* arr = new int[Length];
	for (int i = 0; i < Length; i++)
	{
		arr[i] = rand();
		//cout << arr[i] << endl;
	}
	cout << endl << endl;
	heapsort(arr, Length);

	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << endl;
	}
	cin.get();
	cin.get();
	return 0;

}
void SelectionSort(int* arr, int size)//работает
{
	int temp(INT_MIN),pos(0);
	for (unsigned i = 0; i < size; i++)
	{
		for (unsigned j = 0; j < size - i; j++)
			if (arr[j] >= temp)
			{
				pos = j;
				temp = arr[j];
			}
		arr[pos] = arr[size - i - 1];
		arr[size - i - 1] = temp;
		temp = INT_MIN;
		pos = 0;
	}
}
void ScheikerSort(int* arr, int size)//работает
{
	int leftMark = 1;
	int rightMark = size - 1;
	int temp(0);
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i])
			{
				temp = arr[i - 1];
				arr[i - 1] = arr[i]; // перестановка элементов массива
				arr[i]= temp;
			}
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i])
			{
				temp = arr[i - 1];
				arr[i - 1] = arr[i]; // перестановка элементов массива
				arr[i] = temp;
			}
		rightMark--;
	}
}
void InsertSort(int* arr, int size)//работает
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < size; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[item + 1] = arr[item]; // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
}
void TreeSort(int* arr, int size)
{
	Tree* Tr=new Tree;
	Tr->val = arr[0];
	Tr->left = NULL;
	Tr->right = NULL;
	for (int i = 1; i < size; i++)
		add_to_tree(arr[i], Tr);
	Print_mas(Tr);
	delete_tree(Tr);

}
void add_to_tree(int val,Tree* Tr)
{
	Tree* q;
	q = Tr;
	while (Tr != NULL)
	{
		q = Tr;
		if (val >= Tr->val)
			Tr = Tr->right;
		else
			Tr = Tr->left;
	}
	Tree* zam = new Tree;
	zam->val = val;
	zam->left = NULL;
	zam->right = NULL;
	if (val >= q->val)
		q->right = zam;
	else
		q->left = zam;
}
void Print_mas(Tree* Tr)
{
	if (Tr != NULL)
	{
		Print_mas(Tr->left);
		cout << Tr->val << endl;
		Print_mas(Tr->right);
	}

}
void delete_tree(Tree* Tr)
{
	if (Tr != NULL)
	{
		delete_tree(Tr->left);
		delete_tree(Tr->right);
	}
	delete Tr;
}

int* block_sort(int* arr, int size)//Пусть блоков будет 3
{
	if (size > 3)
	{
		int max(INT_MIN), min(INT_MAX), n(3), k(0);
		int* kolvo_num = new int[n];
		for (unsigned i = 0; i < n; i++)
			kolvo_num[i] = 0;
		for (unsigned i = 0; i < size; i++)
		{
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		k = (max - min) / n;
		for (unsigned i = 0; i < size; i++)
		{
			if ((arr[i] >= min) && (arr[i] < min + k))
				kolvo_num[0] += 1;
			if ((arr[i] >= min + k) && (arr[i] < min + 2 * k))
				kolvo_num[1] += 1;
			if ((arr[i] >= min + 2 * k) && (arr[i] <= max))
				kolvo_num[2] += 1;
		}
		int* first = new int[kolvo_num[0]];
		int* two = new int[kolvo_num[1]];
		int* three = new int[kolvo_num[2]];

		int n_1(0), n_2(0), n_3(0);
		for (unsigned i = 0; i < size; i++)
		{
			if ((arr[i] >= min) && (arr[i] < min + k))
			{
				first[n_1] = arr[i];
				n_1++;
			}
			if ((arr[i] >= min + k) && (arr[i] < min + 2 * k))
			{
				two[n_2] = arr[i];
				n_2++;
			}
			if ((arr[i] >= min + 2 * k) && (arr[i] <= max))
			{
				three[n_3] = arr[i];
				n_3++;
			}
		}

		block_sort(first, kolvo_num[0]);
		block_sort(two, kolvo_num[1]);
		block_sort(three, kolvo_num[2]);
		
		
		for (unsigned i = 0; i < kolvo_num[0]; i++)
			arr[i] = first[i];
		for (unsigned i = 0; i < kolvo_num[1]; i++)
			arr[i+ kolvo_num[0]] = two[i];
		for (unsigned i = 0; i < kolvo_num[2]; i++)
			arr[i + kolvo_num[0]+ kolvo_num[1]] = three[i];
		delete first;
		delete two;
		delete three;
		delete kolvo_num;
	}
	else
	{
		int zam(0);
		for (int i = 0; i < size - 1; i++)
			for (int j = 0; j < size - 1; j++)
				if (arr[j] > arr[j + 1])
				{
					zam = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = zam;
				}
	}
	return arr;
}
void heapsort(int* arr,int size)
{
	int zam;
	for (unsigned j = 0; j < size; j++)
	{
			for (int i = ((size - j) / 2); i >=0; i--)//формируем пирамидку 
				{
					if (2*i+1< size - j)
					if (arr[i] < arr[2 * i+1])
					{
						zam = arr[i];
						arr[i] = arr[2 * i+1];
						arr[2 * i+1] = zam;
					}
					if (2 * i + 2 < size - j)
					if (arr[i] < arr[2 * i+2])
					{
						zam = arr[i];
						arr[i] = arr[2 * i+2];
						arr[2 * i+2] = zam;
					}
				}
		zam = arr[0];
		arr[0] = arr[size-j-1];
		arr[size - j-1] = zam;
	}

}