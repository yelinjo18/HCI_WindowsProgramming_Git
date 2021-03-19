// ArrayTest2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "ArrayTest2.h"
#include <afxtempl.h> // 템플릿 클래스 정의를 담고 있다.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

// 3차원 좌표를 저장할 수 있는 클래스
// 모든 멤버가 public일 때는 class 대신 struct를 사용하면 좀더 편리하다.
struct Point3D {
	int x, y, z;
	Point3D() {} // 템플릿 클래스에 사용할 때는 반드시 기본 생성자가 필요하다.
	Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

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
			// Point3D 객체를 저장할 수 있는 배열 객체를 생성한다.
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
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
