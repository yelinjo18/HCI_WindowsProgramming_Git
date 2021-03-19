// Console.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Console.h"

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
#if 0
			CString str;
			str.LoadString(IDS_APP_TITLE);
			_tprintf(_T("Hello from %s!\n"), str);
#endif
#if 0
			CString str1;
			str1 = _T("�ȳ��ϼ���."); // ���ڿ��� ���� �����Ѵ�.
			CString str2(_T("������")); // ���ڿ��� ������ ���ڷ� �����Ѵ�.
			CString str3(str2); // CString ��ü�� ������ ���ڷ� �����Ѵ�.
			// CString ��ü�� ���ڿ��� ���δ�.
			CString str4 = str1 + _T(" ") + str2 + _T(" ��ſ� ���Դϴ�.");
			_tprintf(_T("%s\n"), str1);
			_tprintf(_T("%s\n"), str2);
			_tprintf(_T("%s\n"), str3);
			_tprintf(_T("%s\n"), str4);
			// + = �����ڸ� �̿��Ͽ� ���� ���ڿ��� ���ο� ���ڿ��� �����δ�.
			str4 += _T(" ������");
			_tprintf(_T("%s\n"), str4);
#endif
#if 0
			CString str;
			str.Format(_T("x=%d, y=%d\n"), 100, 200);
			MessageBox(NULL, str, _T("CString::Format() ����"), MB_OK);
#endif
#if 0
			CString str;
			str.LoadString(IDS_APP_TITLE); // ���ڿ� ���ҽ��� �ε��Ѵ�.
			str.Insert(0, _T("Hello from ")); // �� �տ� ���ڿ��� �����Ѵ�.
			str.Append(_T("!")); // �� ���� ���ڿ��� �����δ�.
			MessageBox(NULL, str, _T("CString::LoadString() ����"), MB_OK);
#endif
#if 0
			CPoint pt1(10, 20); // x, y ��ǥ�� ������ ���ڷ� �����Ѵ�.
			POINT pt = {30, 40};
			CPoint pt2(pt); // POINT Ÿ�� ������ ������ ���ڷ� �����Ѵ�.
			_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			pt1.Offset(40, 30); // x, y ��ǥ�� ���� 40, 30�� ���Ѵ�.
			pt2.Offset(20, 10); // x, y ��ǥ�� ���� 20, 10�� ���Ѵ�.
			_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			if(pt1 == pt2) // �� ��ü�� ������ ������ Ȯ���Ѵ�.
				_tprintf(_T("�� ���� ��ǥ�� �����ϴ�.\n"));
			else
				_tprintf(_T("�� ���� ��ǥ�� �ٸ��ϴ�.\n"));
#endif
#if 1
			CRect rect1(0, 0, 200, 100); // ���簢���� ��ǥ�� �������� ���ڷ� �����Ѵ�.
			CRect rect2;
			rect2.SetRect(0, 0, 200, 100); // ���簢���� ��ǥ�� ���� �߿� �����Ѵ�.
			if(rect1 == rect2) // �� ��ü�� ������ ������ Ȯ���Ѵ�.
				_tprintf(_T("�� ���簢���� ��ǥ�� �����ϴ�.\n"));
			else
				_tprintf(_T("�� ���簢���� ��ǥ�� �ٸ��ϴ�.\n"));
			RECT rect = {100, 100, 300, 200};
			CRect rect3(rect); // RECT Ÿ�� ������ ������ ���ڷ� �����Ѵ�.
			_tprintf(_T("%d, %d\n"), rect3.Width(), rect3.Height());

			CPoint pt(200, 150);
			if(rect3.PtInRect(pt)) // ���� ���簢�� ���ο� �ִ��� �Ǵ��Ѵ�.
				_tprintf(_T("���� ���簢�� ���ο� �ֽ��ϴ�.\n"));
			else
				_tprintf(_T("���� ���簢�� �ܺο� �ֽ��ϴ�.\n"));
#endif
#if 0
			CSize size1(100, 200); // ���� ���̸� ������ ���ڷ� �����Ѵ�.
			SIZE size = {100, 200};
			CSize size2(size); // SIZE Ÿ�� ������ ������ ���ڷ� �����Ѵ�.
			_tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
			if(size1 == size2) // �� ��ü�� ������ ������ Ȯ���Ѵ�.
				_tprintf(_T("ũ�Ⱑ �����ϴ�.\n"));
			else
				_tprintf(_T("ũ�Ⱑ �ٸ��ϴ�.\n"));
#endif
#if 0
			// CTime::GetCurrentTime() �Լ��� ���� �ð��� ���Ѵ�.
			CTime tm;
			tm = CTime::GetCurrentTime();
			// ���� �������� ȭ�鿡 ����Ѵ�.
			CString str = tm.Format(_T("%A, %B %d, %Y"));
			_tprintf(_T("%s\n"), str);
			str.Format(_T("���� �ð��� %d�� %d�� %d���Դϴ�."),
				tm.GetHour(), tm.GetMinute(), tm.GetSecond());
			_tprintf(_T("%s\n"), str);
#endif
#if 0
			CTime startTime = CTime::GetCurrentTime();
			Sleep(2000); // 2000 �и��� ����
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str;
			str.Format(_T("%d�� ����!"), elapsedTime.GetTotalSeconds());
			_tprintf(_T("%s\n"), str);
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
