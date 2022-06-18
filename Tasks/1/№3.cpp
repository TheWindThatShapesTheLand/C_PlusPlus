#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	double N, M;

	cout << "Enter N :";
	cin >> N;

	cout << "Enter M :";
	cin >> M;

	if (N > M) return false;

	double n = N, k;
	cout << "Enter k :";
	cin >> k;
	if (k == 0) return false;

	double Sum = 0, Mult = 1;
	for (double n = N; N <= M - N + 1;)
	{
		double a = n;
		a = pow(-1, n + 1) * pow(cos(n / k) - 1 / (pow(k, 2) + k * 10), n) + pow(-1, n) * pow(sin(n * k) + 1 / (10 + k), k + n);

		if (n <= M)
		{
			Sum += a;
			Mult *= a;
			n++;
		}

		if (n > M)
		{
			cout << Sum << endl;
			cout << Mult << endl;
			return false;
		}
	}
	
	if (N = M)  n = pow(-1, n + 1) * pow(cos(n / k) - 1 / (pow(k, 2) + k * 10), n) + pow(-1, n) * pow(sin(n * k) + 1 / (10 + k), k + n);

	Sum += n;
	Mult *= n;

	cout << Sum << endl;
	cout << Mult << endl;

}