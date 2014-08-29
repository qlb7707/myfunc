#pragma once
#include "writeframedlg.h"
class CWriteFrameSingleDlg :
	public CWriteFrameDlg
{
public:
	CWriteFrameSingleDlg(void);
	~CWriteFrameSingleDlg(void);
	enum { IDD = IDD_WRITEFRAME1 };
	virtual BOOL OnInitDialog();
};

