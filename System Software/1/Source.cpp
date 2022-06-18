#include "Windows.h"
#include "iostream"
#include "versionhelpers.h"
using namespace std;

const char* WindowsVersion()
{
	
	if (!IsWindows10OrGreater())
	{
		return "10";
	}
	else if (!IsWindows8OrGreater())
	{
		return "8";
	}
	else if (!IsWindows7OrGreater())
	{
		return "7";
	}
	else if (!IsWindowsVistaOrGreater())
	{
		return "Vista";
	}
	else if (!IsWindowsXPOrGreater())
	{
		return "XP";
	}
	else return "Unknown";

}

int main()
{
	int n;
	cout << "Enter the starting number: 0 - notepad , 1 - Word , any other number - your own .exe"<<endl;
	cin >> n;

	LPWSTR WStrExeLoc;
	wstring StrExeLoc;

	if (n == 0)
	{
		StrExeLoc = L"c:\\Windows\\notepad.exe textfile";
		
	}
	else if (n == 1)
	{
		StrExeLoc = L"c:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.exe textfile";
		
	}
	else
	{
		wcin >> StrExeLoc;
	}

	WStrExeLoc = (LPWSTR)StrExeLoc.c_str();
	
	
	STARTUPINFO si;//структура,определяет размеры окна процесса и т.п.
	PROCESS_INFORMATION pi;//структура информация о процессе
	ZeroMemory(&si, sizeof(si));// тоже самое, что и ={0}
	ZeroMemory(&pi, sizeof(pi));//заполняем структуры нулями, т.к. их параметры нам не нужны

	CreateProcess 
	(
		NULL,// имя исполняемого модуля
		WStrExeLoc,// Командная строка
		NULL, // Указатель на структуру SECURITY_ATTRIBUTES
		NULL, // Указатель на структуру SECURITY_ATTRIBUTES
		FALSE, // Флаг наследования текущего процесса
		NULL,// Флаги способов создания процесса
		NULL,// Указатель на блок среды
		NULL, // Текущий диск или каталог
		&si, // Указатель нас структуру STARTUPINFO
		&pi // Указатель нас структуру PROCESS_INFORMATION
	);

		
	cout << "Handle: " << pi.hProcess << endl;
	cout << "Process ID: " << pi.dwProcessId << endl;
	cout << "Thread ID: " << pi.dwThreadId << endl;

	//TerminateProcess(pi.hProcess,0);

	system("pause");

	SYSTEM_INFO SystInf;
	GetSystemInfo(&SystInf);

	cout << "\t Hardware Info: \n"
		<< "Processor Type: " << SystInf.wProcessorArchitecture << endl
		<< "Number Of Processor: " << SystInf.wProcessorRevision << endl
		<< "Number Of Cores: " << SystInf.dwNumberOfProcessors << endl
		<< "Minimum application address: " << SystInf.lpMinimumApplicationAddress << endl
		<< "Maximum Application address: " << SystInf.lpMaximumApplicationAddress << endl;

	cout << "Windows Version: " << WindowsVersion() << endl;

	system("pause");

	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&pi1, sizeof(pi1));
	si1.cb = sizeof(si1);
	
	wstring S = L"c:\\Users\\Коптутер\\source\\repos\\Parent\\Debug\\Parent.exe";
	LPWSTR STR = (LPWSTR)S.c_str();

	if (CreateProcess
	(
		NULL,
		STR,
		NULL,
		NULL,
		TRUE,
		NULL,
		NULL,
		NULL,
		&si1,
		&pi1
	))
	{
		WaitForSingleObject(pi1.hProcess, INFINITE);
		CloseHandle(pi1.hThread);
		CloseHandle(pi1.hProcess);
	}
		
	return 0;
}
