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

	cout << "Ведите t:";
	cin >> t;
	
	cout << "Введите r:";//t и r строковые данные, по которым расскадываем  
	cin >> r;

	cout << "Введите N:"; //номер расскладываемого числа Фибоначи
	cin >> N;
	if (N < 0 || N % 1 != 0|| N >30)//у меня даже с 30 еле-еле подсчитал))
	{
		cout << "Ошибка ввода" << endl;
		return 0;
	}

	cout << Fib(t, r, N) << endl;

	system("pause");
	return 0;
}