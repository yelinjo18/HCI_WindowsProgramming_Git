// MapTest1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MapTest1.h"

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

			/* 실습 1 */
			// 맵 객체를 생성하고 초기화한다.
			CMapStringToString map;
			map[_T("사과")] = _T("Apple");
			map[_T("딸기")] = _T("Strawberry");
			map[_T("포도")] = _T("Grape");
			map[_T("우유")] = _T("Milk");
			// 특정 키 값을 가진 데이터를 검색한다.
			CString str;
			if(map.Lookup(_T("딸기"), str))
				_tprintf(_T("딸기 -> %s\n"), str);
			_tprintf(_T("\n"));

			/* 실습 2 */
			// 맵을 순환하면서 모든 키와 데이터 값을 출력한다.
			POSITION pos = map.GetStartPosition();
			while(pos != NULL){
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			_tprintf(_T("\n"));

			/* 실습 3 */
			map.RemoveKey(_T("우유")); // 키 값 "우유"에 해당하는 데이터를 삭제한다.
			map[_T("수박")] = _T("Watermelon"); // map.SetAt(_T("수박"), _T("Watermelon"));
			// 맵을 순환하면서 모든 키와 데이터 값을 출력한다.
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
		// TODO: 오류 코드를 필요에 따라 수정합니다.
		_tprintf(_T("심각한 오류: GetModuleHandle 실패\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
