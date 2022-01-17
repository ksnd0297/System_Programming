




#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int ReadStringAndWrite(void);

int _tmain(int argc, TCHAR* argv[])
{
	int state = 0;
	while (1)
	{
		state = ReadStringAndWrite();
		if (state == -1)
		{
			_tprintf(_T("Some problem occured! \n"));
			break;
		}

		if (state == 0)
		{
			_tprintf(_T("Graceful exit! \n"));
			break;
		}
	}

	return 0;
}

int ReadStringAndWrite(void)
{
	FILE* fPtr = NULL;
	TCHAR* strBufPtr = NULL;

	__try
	{
		fPtr = _tfopen(_T("string.dat"), _T("a+t"));
		if (fPtr == NULL)
			return -1;

		DWORD strLen = 0;
		_tprintf(_T("Input string length(0 to exit) : "));
		_tscanf(_T("%d"), &strLen);

		if (strLen == 0) // 정상적 종료
			return 0;

		strBufPtr = (TCHAR*)malloc((strLen + 1) * sizeof(TCHAR));
		if (strBufPtr == NULL)
			return -1;

		_tprintf(_T("Input string : "));
		_tscanf(_T("%s"), strBufPtr);

		_ftprintf(fPtr, _T("%s \n"), strBufPtr); // 파일에 출력 (저장)
	}
	__finally
	{
		if (fPtr != NULL)
			fclose(fPtr);

		if (strBufPtr != NULL)
			free(strBufPtr);
	}

	return 1;
}