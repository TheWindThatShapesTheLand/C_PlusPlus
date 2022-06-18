#include"iostream"
#include"cmath"
#include"fstream"
using namespace std;

int main()
{
	cout << "Our Equasion:" << endl
		<< "du/dt + v * du/dx = 0" << endl
		<< "u(t,0) = 0, u(0,x) = [x, x <= 0.5; 1-x, 0.5 < x < 1; 0, x => 1]" << endl
		<< "0 <= x <= 10" << endl;

	double a = 0, b = 10, h, v, A, B,temp=0;

	cout << "Enter step X: h = ";
	cin >> h;

	cout << "Enter the beginig of time interval: A = ";
	cin >> A;
	cout << "Enter the end of time interval: B = ";
	cin >> B;

	cout << "Enter const V: v = ";
	cin >> v;

	double t = h / v;

	int m = (b - a) / h;

	int n = (B - A) / t;

	//double* Ut = new double[n];
	double** E = new double* [n];
	for (int i = 0; i < n; i++)
	{
		E[i] = new double[m];
	}
	double** Ux = new double* [n];
	for (int i = 0; i <= n; i++)
	{
		Ux[i] = new double[m];
	}
	double** Ux2 = new double* [n];
	for (int i = 0; i <= n; i++)
	{
		Ux2[i] = new double[m];
	}

	double* q = new double[n];
	double* w = new double[m];

	for (int i = 0; i <= n; i++)
	{
		q[i] = A + i * t;
		//cout << q[i] << endl;
		//Ut[i] = 0;

	}

	for (int i = 0; i <= m; i++)
	{
		w[i] = a + i * h;

		if (w[i] <= 0.5)
		{
			Ux[0][i] = w[i];

		}
		else if (w[i] >= 1)
		{
			Ux[0][i] = 0;
		}
		else
		{
			Ux[0][i] = 1 - w[i];
		}
		//cout << Ux[0][i] << endl;
	}
	//system("pause");


	ofstream out;
	ofstream pres;
	out.open("Sol.txt");
	pres.open("SolP.txt");

	for (int k = 0; k < 5; k++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (j == 0)
			{
				for (int i = 0; i <= m; i++)
				{

					out << q[j] << " " << w[i] << " " << Ux[j][i] << " ";

				}
				out << endl;

			}
			else
			{

				for (int i = 0; i <= m; i++)
				{
					if (i == 0)
					{
						Ux[j][i] = 0;

					}
					else
					{
						Ux[j][i] = (1 - ((v * t) / h)) * Ux[j - 1][i] + ((v * t) / h) * Ux[j - 1][i - 1];

					}
					out << q[j] << " " << w[i] << " " << Ux[j][i] << " ";

					
				}
				
				out << endl;

				
			}


		}
		
		h = 2 * h;
		t = 2 * t;

	

		for (int j = 1; j <n; j++)
		{
			for (int i = 1; i < m; i++)
			{

				if (k != 0 && i != m-1)
				{
					E[j][i] = (abs(Ux[j][i] - Ux2[j+j+1][i+i])) / (pow(2, 2) - 1);
					cout << E[j][i] << " ";
					
			

				}
				Ux2[j][i] = Ux[j][i];

				Ux[j][i] = NULL;

				

			}
			cout << endl;
			
		}
		
		m = (b - a) / h;
		n = (B - A) / t;
		if (k != 0)
		{
			
			pres << endl<<endl;
			
		}

			
		

	}

	out.close();
	pres.close();

	return 0;
}