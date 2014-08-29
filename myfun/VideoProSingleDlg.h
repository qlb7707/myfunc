#pragma once
#include "myfunDlg.h"

// CVideoProSingleDlg 对话框

class CVideoProSingleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVideoProSingleDlg)

public:
	CVideoProSingleDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVideoProSingleDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_dir;
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
