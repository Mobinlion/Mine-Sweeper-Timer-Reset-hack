// MineSweeper_TimeReset.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"


#define KILO 1000

void potato ( void )
{
	float abc = 0;
	char abc2[KILO];
	char abc3[MAX_PATH];
	memset(abc2, '\0', sizeof(abc2));
	HANDLE hdl = GetModuleHandle(NULL);
	HANDLE hdl2 = hdl;
	
	GetModuleFileName((HMODULE)hdl, abc3, MAX_PATH);
	hdl = (HANDLE)((char*)(hdl) + 0x868B4);
	int kalam;

	ReadProcessMemory(GetCurrentProcess(), (void*)hdl, &kalam, sizeof(int), NULL);

	kalam += 0xC;

	ReadProcessMemory(GetCurrentProcess(), (void*)kalam, &kalam, sizeof(int), NULL);

	kalam += 0x24;

	ReadProcessMemory(GetCurrentProcess(), (void*)kalam, &kalam, sizeof(int), NULL);

	//kalam += 0x1C;  //time
	kalam += 0x1C; //no. of mines





	sprintf(abc2, "base of exe: %p\r\n added: %p\r\n %s\r\n\r\n%d", hdl2, hdl, abc3, kalam );
	

	MessageBox(NULL, abc2, "hello", 1);

	WriteProcessMemory(GetCurrentProcess(), (void*)kalam, (void*)&abc, sizeof(float), NULL);

	CloseHandle(hdl);
	CloseHandle(hdl2);
	//HMODULE penn = NULL;
	//GetModuleHandleExA( GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, "C:\\Users\\Godzilla\\Documents\\Visual Studio 2008\\Projects\\MineSweeper_TimeReset\\Debug\\MineSweeper_TimeReset.dll", &penn);
	//FreeLibraryAndExitThread( penn , NULL);

	return;

}