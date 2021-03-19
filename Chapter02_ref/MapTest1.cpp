// MapTest1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MapTest1.h"

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

			/* �ǽ� 1 */
			// �� ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�.
			CMapStringToString map;
			map[_T("���")] = _T("Apple");
			map[_T("����")] = _T("Strawberry");
			map[_T("����")] = _T("Grape");
			map[_T("����")] = _T("Milk");
			// Ư�� Ű ���� ���� �����͸� �˻��Ѵ�.
			CString str;
			if(map.Lookup(_T("����"), str))
				_tprintf(_T("���� -> %s\n"), str);
			_tprintf(_T("\n"));

			/* �ǽ� 2 */
			// ���� ��ȯ�ϸ鼭 ��� Ű�� ������ ���� ����Ѵ�.
			POSITION pos = map.GetStartPosition();
			while(pos != NULL){
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			_tprintf(_T("\n"));

			/* �ǽ� 3 */
			map.RemoveKey(_T("����")); // Ű �� "����"�� �ش��ϴ� �����͸� �����Ѵ�.
			map[_T("����")] = _T("Watermelon"); // map.SetAt(_T("����"), _T("Watermelon"));
			// ���� ��ȯ�ϸ鼭 ��� Ű�� ������ ���� ����Ѵ�.
			pos = map.GetStartPosition();
			while(pos != NULL){
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
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
