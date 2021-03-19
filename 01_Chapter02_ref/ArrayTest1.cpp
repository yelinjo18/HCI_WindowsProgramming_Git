// ArrayTest1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "ArrayTest1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 오류 코드를 필요에 따라 수정합니다.
			_tprintf(_T("심각한 오류: MFC를 초기화하지 못했습니다.\n"));
			nRetCode = 1;
		}
		else
		{
			// 콘솔에서 유니코드 한글 출력을 위해 필요하다.
			_tsetlocale(LC_ALL, _T(""));
#if 1
			CUIntArray array; // 객체를 생성한다.
			array.SetSize(10); // 배열 크기를 설정한다.
			for(int i=0; i<10; i++)
				array[i] = i*10; // 값을 대입한다.
			for(int i=0; i<10; i++)
				_tprintf(_T("%d "), array[i]); // 값을 출력한다.
			_tprintf(_T("\n"));
#endif
#if 0
			CStringArray array; // 객체를 생성한다.
			array.SetSize(5); // 배열 크기를 설정한다.
			for(int i=0; i<5; i++){
				CString string;
				string.Format(_T("%d년이 지났습니다."), (i+1)*10);
				array[i] = string; // 값을 대입한다.
			}
			for(int i=0; i<5; i++)
				_tprintf(_T("%s\n"), array[i]); // 값을 출력한다.
#endif
#if 0
			CUIntArray array;
			array.SetSize(5);
			for(int i=0; i<5; i++)
				array[i] = i;
			/* 배열 원소 삽입 */
			array.InsertAt(3, 77); // 인덱스 3 위치에 원소를 삽입한다.
			for(int i=0; i<array.GetSize(); i++) // 변경된 배열의 크기만큼 반복한다.
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
			/* 배열 원소 삭제 */
			array.RemoveAt(4); // 인덱스 4 위치의 원소를 삭제한다.
			for(int i=0; i<array.GetSize(); i++)
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
#endif
		}
	}
	else
	{
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
