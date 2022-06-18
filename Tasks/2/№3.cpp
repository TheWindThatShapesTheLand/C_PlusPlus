#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int Q, Z, Z1, X;
	int Sum1, Sum2, Sum01, Sum02;
	

	cout << "Enter Q:";
	cin >> Q;

	if (Q <= 0 || Q % 2 != 0 || Q >= 10)
	{
		cout << "Input Error"; 
		return 0;
	}

	int W = pow(10, Q);

	for (int i = 1; i < W; i++)
	{
		Sum1 = 0;
		Sum2 = 0;
		for (int p = 0; p < Q; p++)
		{
			if (p < Q / 2)
			{
				Z = i / pow(10, p);
				Sum01 = Z % 10;

				Sum1 += Sum01; 
			}

			if (p > (Q / 2) - 1)
			{
				Z1 = i / pow(10, p);
				Sum02 = Z1 % 10;

				Sum2 += Sum02;
			}

		}

		if (Sum1 == Sum2)
		{
			cout << i << "\t";
		}
	}

	system("pause");
	return 0;
}