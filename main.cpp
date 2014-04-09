#include <stdio.h>
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	si.cb = sizeof(STARTUPINFO);

	LPTSTR line = L"/c start /wait snipsnip & pasta | b2p | pipe2file";
	BOOL res = CreateProcess(L"C:\\windows\\system32\\cmd.exe", line, NULL, NULL, FALSE,
		CREATE_UNICODE_ENVIRONMENT | CREATE_NO_WINDOW,
		NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	return 0;
}