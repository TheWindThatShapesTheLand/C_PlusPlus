#include <iostream>
#include <cmath>

using namespace std;


double F(int n)
{
	int a, b, x, y, p, q;
	int k = 13;
	
	a = k;
	b = 2*k + 1;
	x = 3*k + 2;
	y =pow(k,2) + 2*k - 1;
	p = 5 * k - 1;
	q =pow(k,2) + 11*k - 3;

	while(n >= 0)
	{
		if (n == 0) return a;
		else if (n == 1)
		{
			return b;
		}
		else if(n == 2)
		{
			return double (x * b) / (1 - y);
		}
		else if (n == 3)
		{
			return double (p * b + q * F(n-1));
		}
		else if (n >= 4) 
		{

			if (n % 2 == 0)
			{
				return double(x * F(n/2) + y * F((n / 2)+1));
			}

			else if (n % 2 != 0)
			{

				return double(p * F((n-1)/2) + q * F(((n - 1) / 2) + 1 ));

			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;

	cout << "¬ведите n:";
	cin >> n;
	if (n < 0|| n % 1 != 0)
	{
		cout << "ќшибка ввода" << endl;
		return 0;
	}

	cout <<F(2*n) << endl << F(2*n+1) << endl;

	system("pause");
	return 0;
}