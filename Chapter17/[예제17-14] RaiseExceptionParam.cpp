




#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define SATTUS_DEFAULT_USER_DEFINED_EXPT ((DWORD)0xE0000008L)

void SoftwareException(void);
DWORD FilterFunction(LPEXCEPTION_POINTERS exptPtr);

int _tmain(int argc, TCHAR* argv[])
{
	SoftwareException();
	_tprintf(_T("End of the _tmain \n"));

	return 0;
}

void SoftwareException(void)
{
	TCHAR* exptString[] = {
		(TCHAR*)_T("Exception String one!"),
		(TCHAR*)_T("Exception String Two!"),
		(TCHAR*)_T("Exception String Three!")
	};

	__try
	{
		RaiseException(SATTUS_DEFAULT_USER_DEFINED_EXPT, 0, 3, (ULONG_PTR*)exptString);
	}
	__except (FilterFunction(GetExceptionInformation()))
	{
		DWORD exptType = GetExceptionCode();
		_tprintf(_T("Recv : exception code : 0x%x \n"), exptType);
	}
}

DWORD FilterFunction(LPEXCEPTION_POINTERS exptPtr)
{
	PEXCEPTION_RECORD exptRecord = exptPtr->ExceptionRecord;

	switch (exptRecord->ExceptionCode)
	{
	case SATTUS_DEFAULT_USER_DEFINED_EXPT:
		_tprintf(_T("STATUS_DEFAULT_USER_DEFINED_EXPT exception \n"));
		_tprintf(_T("Exception code : 0x%x \n"), exptRecord->ExceptionCode);
		_tprintf(_T("Exception flags: %d \n"), exptRecord->ExceptionFlags);
		_tprintf(_T("Exception param num : %d \n"), exptRecord->NumberParameters);
		_tprintf(_T("String one : %s \n"), (TCHAR*)exptRecord->ExceptionInformation[0]);
		_tprintf(_T("String two : %s \n"), (TCHAR*)exptRecord->ExceptionInformation[1]);
		_tprintf(_T("String three : %s \n"), (TCHAR*)exptRecord->ExceptionInformation[2]);
		break;

	default:
		break;
	}

	return EXCEPTION_EXECUTE_HANDLER;
}