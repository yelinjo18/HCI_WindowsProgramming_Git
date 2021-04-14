// ListTest2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ListTest2.h"
#include <afxtempl.h> // ���ø� Ŭ���� ���Ǹ� ��� �ִ�.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

// 3���� ��ǥ�� ������ �� �ִ� Ŭ����
// ��� ����� public�� ���� class ��� struct�� ����ϸ� ���� ���ϴ�.
struct Point3D {
	int x, y, z;
	Point3D() {} // ���ø� Ŭ������ ����� ���� �ݵ�� �⺻ �����ڰ� �ʿ��ϴ�.
	Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

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
			// Point3D ��ü�� ������ �� �ִ� ����Ʈ ��ü�� �����Ѵ�.
			CList<Point3D, Point3D&> list;

			// ����Ʈ ���� �����͸� �߰��Ѵ�.
			for(int i=0; i<5; i++)
				list.AddTail(Point3D(i, i*10, i*100));

			// ����Ʈ �� �տ������� ��ȯ�ϸ鼭 �����͸� ����Ѵ�.
			POSITION pos = list.GetHeadPosition();
			while(pos != NULL){
				Point3D pt = list.GetNext(pos);
				_tprintf(_T("%d, %d, %d\n"), pt.x, pt.y, pt.z);
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
