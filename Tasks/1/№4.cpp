#include <iostream>
using namespace std;

int main()
{
	long long int N, div = 2;
	cout << "Enter N: ";
	cin >> N;

	if (N <= 1) return 0;

	while (N >= 2)
	{
		while (N % div == 0) 
		{
			cout << div << " ";
			N = N / div;
		}
		div++;
	}
	return 0;
	system ("pause");
}



	


