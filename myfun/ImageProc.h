#pragma once
#include"myfunDlg.h"

// CImageProc 对话框

class CImageProc : public CDialogEx
{
	DECLARE_DYNAMIC(CImageProc)

public:
	CImageProc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CImageProc();

// 对话框数据
	enum { IDD = IDD_IMGPROC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_dir;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedVideowrite();
};
