#include "iostream"
#include "fstream"
#include "cmath"
using namespace std;

int main()
{
	cout << "Our ODE:" << endl << "y'[x] + y[x] == 3*Sin[x]" << endl;

	double a = 0, b= 0.5;
	/*cout << "Enter the beginig of interval: a = ";
	cin >> a;
	cout << "Enter the end of interval: b = ";
	cin >> b;*/

	double y0 = 1;
	/*cout << "Enter the IC of Y: y(0) = ";
	cin >> y0;*/

	double h = 0.025;
	/*cout << "Enter step: h = ";
	cin >> h;*/

	int m = (b - a) / h;
	int m1 = m;

	double* Y = new double[m];
	double* Y2 = new double[m];
	double* E = new double[m];

	int v1, v2;
	cout << "Set precision: 1 - O(h), 2 - O(h^2), 3 - O(h^3) , 4 - O(h^4): ";
	cin >> v1;

	if (v1 != 1)
	{
		cout << "What method?(1-3): ";
		cin >> v2;
	}
	else
	{
		v2 = 1;
	}

	ofstream out;
	ofstream pres;

	Y[0] = y0;


	for (int j = 0; j <= 3; j++)
	{
		double Norm = 0;
		double* w = new double[m];//Равномерная сетка
		for (int i = 0; i <= m; i++)
		{
			w[i] = a + i * h;

		}

		for (int i = 1; i <= m + 1; i++)
		{
			double DeltaY, K0, K1, K2, K3;

			switch (v1)
			{
			case 4://Методы 4 порядка точности
				switch (v2)
				{
				case 1:

					if (j == 0 && i == 1)
					{
						out.open("Solution4.txt");
						pres.open("SolutionPres4.txt");

					}

					K0 = h * (w[i - 1] * Y[i - 1]);
					K1 = h * (((w[i - 1]) + (h / 2)) * ( Y[i - 1] + (K0 / 2)));
					K2 = h * (((w[i - 1]) + (h / 2)) * (Y[i - 1] + (K1 / 2)));
					K3 = h * (((w[i - 1]) + h)* (Y[i - 1] + K2));

					DeltaY = (K0 + 2 * K1 + 2 * K2 + K3) / 6;

					break;

				case 2:

					if (j == 0 && i == 1)
					{
						out.open("Solution4.txt");
						pres.open("SolutionPres4.txt");

					}

					K0 = h * (3 * sin(w[i - 1]) - Y[i - 1]);
					K1 = h * (3 * sin(w[i - 1]) + (h / 3) - Y[i - 1] + (K0 / 3));
					K2 = h * (3 * sin(w[i - 1]) + (2 * h / 3) - Y[i - 1] - (K0 / 2) + K1);
					K3 = h * (3 * sin(w[i - 1]) + h - Y[i - 1] + K0 - K1 + K2);

					DeltaY = (K0 + 3 * K1 + 3 * K2 + K3) / 8;

					break;

				case 3:

					if (j == 0 && i == 1)
					{
						out.open("Solution4.txt");
						pres.open("SolutionPres4.txt");

					}

					K0 = h * (3 * sin(w[i - 1]) - Y[i - 1]);
					K1 = h * (3 * sin(w[i - 1]) + (h / 4) - Y[i - 1] + (K0 / 4));
					K2 = h * (3 * sin(w[i - 1]) + (h / 2) - Y[i - 1] + (K1 / 2));
					K3 = h * (3 * sin(w[i - 1]) + h - Y[i - 1] + K0 - 2 * K1 + K2);

					DeltaY = (K0 + 4 * K2 + K3) / 6;

					break;
				}
				break;

			case 3://Методы 3-его порядка точности

				switch (v2)
				{
				case 1:

					if (j == 0 && i == 1)
					{
						out.open("Solution3.txt");
						pres.open("SolutionPres3.txt");

					}

					K0 = h * ((w[i - 1]) * (Y[i - 1]));
					K1 = h * (((w[i - 1]) + (h / 2)) * (Y[i - 1] + (K0 / 2)));
					K2 = h *(((w[i - 1]) + (h / 2)) * (Y[i - 1] - K0 + 2 * K1));

					DeltaY = (K0 + 4 * K1 + K2) / 6;

					break;

				case 2:

					if (j == 0 && i == 1)
					{
						out.open("Solution3.txt");
						pres.open("SolutionPres3.txt");

					}

					K0 = h * (3 * sin(w[i - 1]) - Y[i - 1]);
					K1 = h * (3 * sin(w[i - 1]) + (h / 3) - Y[i - 1] + (K0 / 3));
					K2 = h * (3 * sin(w[i - 1]) + (2 * h / 3) - Y[i - 1] + (2 * K1 / 3));

					DeltaY = (K0 + 3 * K2) / 4;

					break;

				case 3:

					if (j == 0 && i == 1)
					{
						out.open("Solution3.txt");
						pres.open("SolutionPres3.txt");

					}

					K0 = h * (3 * sin(w[i - 1]) - Y[i - 1]);
					K1 = h * (3 * sin(w[i - 1]) + (h / 2) - Y[i - 1] + (K0 / 2));
					K2 = h * (3 * sin(w[i - 1]) + (3 * h / 4) - Y[i - 1] + (3 * K1 / 4));

					DeltaY = (2 * K0 + 3 * K1 + 4 * K2) / 9;

					break;
				}
				break;

			case 2://Методы 2-ого порядка точности

				switch (v2)
				{
				case 1:

					if (j == 0 && i == 1)
					{
						out.open("Solution2.txt");
						pres.open("SolutionPres2.txt");


					}

					K0 = h * (w[i - 1] * Y[i - 1]);
					K1 = h * (((w[i - 1]) + h) * (Y[i - 1] + K0));

					DeltaY = (K0 + K1) / 2;

					break;

				case 2:

					if (j == 0 && i == 1)
					{
						out.open("Solution2.txt");
						pres.open("SolutionPres2.txt");

					}

					K0 = h * ((w[i - 1]) * Y[i - 1]);
					K1 = h * (((w[i - 1]) + (h / 2))*(Y[i - 1] + (K0 / 2)));

					DeltaY = K1;

					break;

				case 3:

					if (j == 0 && i == 1)
					{
						out.open("Solution2.txt");
						pres.open("SolutionPres2.txt");

					}

					K0 = h * (((w[i - 1]) * Y[i - 1]));
					K1 = h * (((w[i - 1]) + (2 * h / 3)) *( Y[i - 1] + (2 * K0 / 3)));

					DeltaY = (K0 + 3 * K1) / 4;

					break;
				}
				break;

			case 1://Метод 1-ого порядка точности

				if (j == 0 && i == 1)
				{
					out.open("Solution1.txt");
					pres.open("SolutionPres1.txt");

				}

				K0 = h * ((w[i - 1]) * Y[i - 1]);

				DeltaY = K0;

				break;

			}

			Y[i] = Y[i - 1] + DeltaY;
		

			if (j != 0 )
			{


				if ((fabs(Y[i-1] - Y2[i+i-1])) > Norm)
				{
					Norm = fabs(Y[i-1] - Y2[i+i-1]);
					

				}

			}

			if (j == 0)
			{
				out << w[i - 1] << endl
					<< Y[i - 1] << endl;
			}
		}

		

		for (int i = 0; i <= m; i++)
		{
			Y2[i] = Y[i];

			if (i == m && j == 0)
			{
				cout << "Our Solution: y(" << b << ")= ";
				cout << Y[i] << endl;

			}

			Y[i] = NULL;
		}

		Y[0] = y0;
		

		if (j != 0)
		{
			
			pres <<h/2<<" "<< Norm / (pow(2,v1)-1) << endl;
		}

		h = 2 * h;
		m = (b - a) / h;
	}

	pres.close();
	out.close();

	return 0;
}