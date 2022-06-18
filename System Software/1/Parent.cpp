#include "Windows.h"
#include "iostream"
#include "fstream"
#include "string"
#include "cstdlib"
using namespace std;

struct emp
{
	int num;
	char name[10];
	double grade;
};

auto GetWstring = [](const string str)->wstring
{
	const char* c = str.c_str();
	const size_t cSize = str.size() + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);
	wstring w_string(wc);
	delete[] wc;
	return w_string;
};

int main()
{
	string NotxtName;
	cout << "Enter The File Name (without .txt):\n";
	cin >> NotxtName;
	string Name = NotxtName +".txt";

	int m;
	cout << "Enter The Number Of The Students: ";
	cin >> m;

	cout << "\t Enter The Information About The Students:" << endl<<endl;

	ofstream out;
	out.open(Name);

	string str = Name;
	str.append(" ");

	out << "Total Number Of The Students: " << m << endl << endl << '\t'
		<< "The Information About The Students : " << endl;

	for (int i = 1; i <= m; i++)
	{
		emp NewStudent;

		cout << "Student Number " << i << ": " << endl
			 << "Enter The Student's Book Number: ";
		cin >> NewStudent.num;
		out << "Student Number " << i << ": " << endl
			<< "Student's Book Number: " << NewStudent.num << endl;

		str.append(to_string(i));
		str.append(" ");
		str.append(to_string(NewStudent.num));
		str.append(" ");

		cout << "Enter The Student's Name: ";
		cin >> NewStudent.name;
		out << "Student's Name: " << NewStudent.name << endl;

		str.append(NewStudent.name);
		str.append(" ");

		cout << "Enter the Student's Grade On Average: ";
		cin >> NewStudent.grade;
		out << "Student's Grade On Average: " << NewStudent.grade << endl<<endl;
		cout << endl;

		str.append(to_string(NewStudent.grade).erase(1));

		if (i < m)
		{
			str.append(" ");
		}
	}
	cout << endl;
	
	out.close();

	ifstream in;
	in.open(Name);
	string line;

	while (getline(in,line))
	{
		cout << line << endl;
	}
	cout << endl;

	in.close();

	wstring Path = L"c:\\Users\\Коптутер\\source\\repos\\Child\\Debug\\Child.exe " + GetWstring(str); ;

	LPWSTR UltPath = (LPWSTR)Path.c_str();
	STARTUPINFO si2;
	PROCESS_INFORMATION pi2;
	ZeroMemory(&si2, sizeof(si2));
	ZeroMemory(&pi2, sizeof(pi2));

	if (CreateProcess
	(
		NULL,
		UltPath,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		&si2,
		&pi2
	))
	{
		WaitForSingleObject(pi2.hProcess, INFINITE);
		CloseHandle(pi2.hThread);
		CloseHandle(pi2.hProcess);
	}

	system("pause");

	ifstream last;
	last.open(Name);
	string line2;

	while (getline(last, line2))
	{
		cout << line2 << endl;
	}
	cout << endl;

	
	return 0;
}