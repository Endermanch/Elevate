#include <windows.h>

int __cdecl wmain(int argc, wchar_t* argv[], wchar_t* envp[]) {
	if (argv[1] == NULL) return 1;

	WCHAR* commandLine = GetCommandLineW();
	WCHAR* lineToPass = NULL;
	WCHAR* mode;
	if (argv[2] != NULL) lineToPass = commandLine + lstrlenW(argv[0]) + lstrlenW(argv[1]) + 4;
	switch (argv[2]) {
		case "-r":
			mode = L"runas";
			break;
		case "-o":
			mode = L"open";
			break;
	}
	/**
	runas elevate the command, where open execute it in quiet, without elevation.
	**/
	ShellExecuteW(NULL, mode, argv[1], lineToPass, NULL, SW_SHOW);
	return 0;
}
