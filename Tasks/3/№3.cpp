#include <iostream>
#include <string>
using namespace std;

string Fib(string t, string r, int N)
{
	if (N == 0) return t;
	
	else if (N == 1)return r;
	
	else if (N >= 2)
	{
		return Fib(t, r, N - 2) + Fib(t, r, N - 1);
	}

}

int main()
{
	setlocale(LC_ALL, "ru");

	string t,r;
	int N;

	cout << "������ t:";
	cin >> t;
	
	cout << "������� r:";//t � r ��������� ������, �� ������� ������������  
	cin >> r;

	cout << "������� N:"; //����� ���������������� ����� ��������
	cin >> N;
	if (N < 0 || N % 1 != 0|| N >30)//� ���� ���� � 30 ���-��� ���������))
	{
		cout << "������ �����" << endl;
		return 0;
	}

	cout << Fib(t, r, N) << endl;

	system("pause");
	return 0;
}