#include <windows.h>

int __cdecl wmain(int argc, wchar_t* argv[], wchar_t* envp[]) {
	if (argv[1] == NULL) return 1;

	WCHAR* commandLine = GetCommandLineW();
	WCHAR* lineToPass = NULL;

	if (argv[2] != NULL) lineToPass = commandLine + lstrlenW(argv[0]) + lstrlenW(argv[1]) + 4;
	ShellExecuteW(NULL, L"runas", argv[1], lineToPass, NULL, SW_SHOW); // Replace L"runas" with L"open" to get quiet startup without elevation.

	return 0;
}