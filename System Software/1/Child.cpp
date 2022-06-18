#include "Windows.h"
#include "iostream"
#include "fstream"
#include "string"
using namespace std;

int main(int argc, char *argv[])
{
	
	for (int i = 0; i < argc; i++)
	{
		cout << "[" << i << "] ";
		cout << argv[i] << endl;
	}
	system("pause");

	string Name = argv[1];
	string Open = "C:\\Users\\Коптутер\\source\\repos\\sppo_1\\sppo_1\\" + Name;
	string line;
	
	ifstream in;
	ofstream of;

	in.open(Open);
	of.open("C:\\Users\\Коптутер\\source\\repos\\sppo_1\\sppo_1\\tempor.txt");

	int j = 3;

	while (getline(in,line))
	{
		
		if (line.empty() == FALSE)
		{
			string linesup = line;

			if( linesup.erase(linesup.size() - 1) == "Student's Grade On Average: ")
			{
				int i = stoi(argv[j]);
				double NewGrade;

				cout << "New Grade for Student Number " << i << ": ";
				cin >> NewGrade;
				of << "Student's Grade On Average: " << NewGrade<<endl;

				j = j + 4;

			}
			else
			{
				of << line << endl;
			}
		}
		else
		{
			of << line << endl;
		}
	}
	const char* D = Name.c_str();
	in.close();
	rename(D,"DELETE.txt");
	remove("DELETE.txt");
	of.close();
	rename("tempor.txt", D);

	return 0;
}