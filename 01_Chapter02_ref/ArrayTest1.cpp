// ArrayTest1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ArrayTest1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			_tprintf(_T("�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"));
			nRetCode = 1;
		}
		else
		{
			// �ֿܼ��� �����ڵ� �ѱ� ����� ���� �ʿ��ϴ�.
			_tsetlocale(LC_ALL, _T(""));
#if 1
			CUIntArray array; // ��ü�� �����Ѵ�.
			array.SetSize(10); // �迭 ũ�⸦ �����Ѵ�.
			for(int i=0; i<10; i++)
				array[i] = i*10; // ���� �����Ѵ�.
			for(int i=0; i<10; i++)
				_tprintf(_T("%d "), array[i]); // ���� ����Ѵ�.
			_tprintf(_T("\n"));
#endif
#if 0
			CStringArray array; // ��ü�� �����Ѵ�.
			array.SetSize(5); // �迭 ũ�⸦ �����Ѵ�.
			for(int i=0; i<5; i++){
				CString string;
				string.Format(_T("%d���� �������ϴ�."), (i+1)*10);
				array[i] = string; // ���� �����Ѵ�.
			}
			for(int i=0; i<5; i++)
				_tprintf(_T("%s\n"), array[i]); // ���� ����Ѵ�.
#endif
#if 0
			CUIntArray array;
			array.SetSize(5);
			for(int i=0; i<5; i++)
				array[i] = i;
			/* �迭 ���� ���� */
			array.InsertAt(3, 77); // �ε��� 3 ��ġ�� ���Ҹ� �����Ѵ�.
			for(int i=0; i<array.GetSize(); i++) // ����� �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
			/* �迭 ���� ���� */
			array.RemoveAt(4); // �ε��� 4 ��ġ�� ���Ҹ� �����Ѵ�.
			for(int i=0; i<array.GetSize(); i++)
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
#endif
		}
	}
	else
	{
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		_tprintf(_T("�ɰ��� ����: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
