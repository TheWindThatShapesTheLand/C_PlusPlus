#include <iostream>

using namespace std;

/*����� ������ ������� �������� N ����� �� M ��������(N<= 100, M<= 100).
���������� ������� �� ������� �������, � ������� ��� �������� ���������
�������� �� ������������ ������������ � �������.����� ������ � �����
������� ������ ���� �������� �������, �������� ����������� ������ � �������.*/

int main()
{

	setlocale(LC_ALL, "ru");

	int R;
	int C;
	cout << "������� 2 �����:\t";
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << i << "," << j << ";" << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}