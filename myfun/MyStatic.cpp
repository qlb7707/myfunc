#include "stdafx.h"
#include "MyStatic.h"


CMyStatic::CMyStatic(void)
{
}


CMyStatic::~CMyStatic(void)
{
}
BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CMyStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox(_T("aaa!"));

	CStatic::OnLButtonDown(nFlags, point);
}
