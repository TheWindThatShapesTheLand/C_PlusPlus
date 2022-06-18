#include "iostream"
#include "cmath"
#include "fstream"
using namespace std;
const double Pi = 3.14159265359;
const double eps = pow(10, -8);

int main()
{
	cout << "Our Equasion:" << endl
		<< "d^2 u/ dx^2 = - d^2 u/ dy^2" << endl
		<< "u(x,0) = 40Sin(Pi*x/2), u(x,1) = 40" << endl
		<< "u(0, y) = 40y^2, u(1,y) = 40" << endl << endl;
		
	double a = 0, b = 1, A = 0, B = 1, h, t;

	cout << "Enter step : h = ";
	cin >> h;



	t = pow(h,2)/4;

	int m = (b - a) / h;

	int n = (B - A) / t;

	double** E = new double* [n];
	for (int i = 0; i < n; i++)
	{
		E[i] = new double[m];
	}

	double** U = new double* [n];
	for (int i = 0; i <= n; i++)
	{
		U[i] = new double[m];
	}

	double** U2 = new double* [n];
	for (int i = 0; i <= n; i++)
	{
		U2[i] = new double[m];
	}

	double** Un = new double* [n];
	for (int i = 0; i <= n; i++)
	{
		Un[i] = new double[m];
	}

	
	double Norm = 1;
	ofstream pres;
	pres.open("SolutionPres.txt");
	for (int k = 0; k < 1; k++)
	{
		double* q = new double[n];
		for (int i = 0; i <= n; i++)
		{
			q[i] = A + i * t;

			U[i][0] = 40 * q[i];
			U[i][m] = 40;

			Un[i][0] = 40 * q[i];
			Un[i][m] = 40;

		}

		double* w = new double[m];
		for (int i = 0; i <= m; i++)
		{
			w[i] = a + i * h;

			U[0][i] = 40 * sin((Pi / 2) * w[i]);
			U[n][i] = 40;

			Un[0][i] = 40 * sin((Pi / 2) * w[i]);
			Un[n][i] = 40;

		}

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (i != 0 && j != 0 && i != n && j != m)
				{
					U[i][j] = 0.25 * (U[0][j] + U[i][0] + U[n][j] + U[j][m]);

				}
			}

		}


		do
		{
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					if (i != 0 && j != 0 && i != n && j != m)
					{

						Un[i][j] = 0.25 * (U[i - 1][j] + U[i + 1][j] + U[i][j - 1] + U[i][j + 1]);
						if (fabs(Un[i][j] - U[i][j]) < Norm)
						{
							Norm = fabs(Un[i][j] - U[i][j]);
							

						}

					}

				}

			}



			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					if (i != 0 && j != 0 && i != n && j != m)
					{
						U[i][j] = Un[i][j];
						Un[i][j] = NULL;
					}
				}
			}


		} while (Norm > eps);


		Norm = 1;

		h = 2 * h;
		t = 2 * t;

		if (k == 0)
		{
			ofstream out;
			out.open("Solution.txt");
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{

					out << q[i] << " " << w[j] << " " << U[i][j] << " ";


				}

			}
			out.close();
		}
		else
		{
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					if (i != 0 && j != 0 && i != n && j != m)
					{

						E[i][j] = (fabs(U2[i][j] - U[i][j + j])) / (pow(2, 2) - 1);
						pres << E[i][j] << " ";
					}
					U2[i][j] = U[i][j];
					U[i][j] = NULL;
				}
				pres << endl;

			}

			m = (b - a) / h;
			n = (B - A) / t;
		}


	}
	pres.close();

	
	return 0;
}