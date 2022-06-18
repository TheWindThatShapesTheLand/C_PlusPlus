#include <iostream>
#include <cmath>
#include <fstream>
#include "Head.h"
using namespace std;
double const Pi = 3.14159265;

double Func(double x)
{
	return double(pow(x, 3) - 2 * fabs(x) - 1);
}
double Divdiff(double x1, double x2, double y1,double y2)
{
	return double((y1-y2)/(x1-x2));
}


int main()
{
	double n,a=-2,b=2;
	int p;
	cout << "Enter the grind points number :";
	cin >> n;
	double* X = new double[n];
	double* Y = new double[n];
	double* T = new double[n];
	cout << "Chebishev grind - 1 or Uniform grind - 2: ";
	cin >> p;
	cout << endl<<endl<<"X points:"<<endl;

	switch (p)
	{
		case 1: 

			for (int i = 0; i < n; i++)

			{
				X[i] = (b+a)/2+((b-a)/2)*cos((((2*i)+1)*Pi)/(2*n+2));
				cout << X[i] << "\t";
				
			}
			break;
		case 2: 

			for (int i = 0; i < n; i++)
			{
				X[i] = a + (i * ((b - a) / (n - 1)));
				cout << X[i] << "\t";
			}
			break;
	}
	cout << endl<<endl<<"Y points:"<<endl;

	for (int i = 0; i < n; i++)
	{
		Y[i] = Func(X[i]);
		T[i] = Y[i];
		cout << Y[i] << "\t";
	}

	cout << endl<<endl<<"Interpolation:"<<endl;

	double** P = new double* [n-1];
	for (int i = 0; i < n-1; i++)
	{
		P[i] = new double[n-1];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			P[i][j] = Divdiff(X[j],X[i+j+1], T[j],T[j+1]);
			T[j] = P[i][j];
			cout << P[i][j]<<'\t';
		}
		cout << endl;
		
	}
	cout << endl;
	ofstream f;
	f.open("Полином.txt");
	int i=0,j=0,m = 1;

	f << "Pn(x)="<<Y[0];

	while (m != n)
	{

		if (P[i][j] >= 0)
		{
			f<<"+"<< P[i][j];
		}
		else if (P[i][j] < 0)
		{
			f <<"-"<<fabs(P[i][j]);
		}
		
		for (int k = 0; k < m; k++)
		{
			if (X[k] >= 0)
			{
				f << "*(x-"<< X[k] << ")";
			}
			else if (X[k] < 0)
			{
				f<<"*(x+" << fabs(X[k]) << ")";
			}
		}
		m++;
		i++;
	}


	f.close();
	system("pause");
	return 0;
}
/*double* Mult = new double[m];
		double* Dif = new double[m];


		while (k + 1 < n)
		{
			for (int i = 0; i <= k + 1; i++)
			{
				for (int j = 0; j < m; j++)
				{

					if (i < k + 1)
					{
						if (i == j && B[i][j] != 0)
						{
							v = B[i][j];

						}
						B[i][j] = B[i][j] / v;

						Mult[r] = B[i][j] * B[k + 1][i];

						Dif[r] = B[k + 1][j] - Mult[r];
						r++;
					}
					else if (i == k + 1)
					{
						if (i == j)
						{
							v = B[i][i];

						}

						B[i][j] = B[i][j] / v;
						r = 0;
					}
				}
				if (i < k + 1)
				{
					swap(B[k + 1], Dif);
					r = 0;
				}

				else if (i == k + 1)
				{
					k++;
					break;

				}

			}

		}
		r = 0;
		v = 0;
		k = 0;


		while (k < n - 1)
		{
			for (int i = n - 1 - k; i > 0; i--)
			{
				for (int j = 0; j < m; j++)
				{
					Mult[r] = B[i + k][j] * B[i - 1][i + k];
					Dif[r] = B[i - 1][j] - Mult[r];

					r++;

				}

				swap(B[i - 1], Dif);
				r = 0;
			}
			k++;
			r = 0;
		}

		r = 0;
		v = 0;
		k = 0;



		delete[] Dif;
		delete[] Mult;*/

		/*else if (j == n)
					{
						B[i][j] = 0;
						oldB[i][j] = 0;

					}*/
					/*else if (j > n)
					{
						if (i + n + 1 == j)
						{
							B[i][j] = 1;
							oldB[i][j] = 1;

						}*/

						/*else
						{
							B[i][j] = 0;
							oldB[i][j] = 0;

						}
					}*/

					/*j < n &&*/