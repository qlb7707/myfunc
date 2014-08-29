#pragma once
#include "afxwin.h"
class CMyStatic :
	public CStatic
{
public:
	CMyStatic(void);
	~CMyStatic(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

