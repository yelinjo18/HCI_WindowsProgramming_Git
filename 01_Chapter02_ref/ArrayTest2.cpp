// ArrayTest2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ArrayTest2.h"
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
			// Point3D ��ü�� ������ �� �ִ� �迭 ��ü�� �����Ѵ�.
			CArray<Point3D, Point3D&> array;
			array.SetSize(5);
			for(int i=0; i<5; i++){
				Point3D pt(i, i*10, i*100);
				array[i] = pt;
			}
			for(int i=0; i<5; i++){
				Point3D pt = array[i];
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
