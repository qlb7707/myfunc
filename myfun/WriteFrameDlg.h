#pragma once
#include "afxwin.h"
#include "utility.h"

// CWriteFrameDlg 对话框

class CWriteFrameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWriteFrameDlg)

public:
	CWriteFrameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWriteFrameDlg();

// 对话框数据
	enum { IDD = IDD_WRITEFRAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_dir;
	afx_msg void OnLbnSelchangeFilelist();
//	CListBox m_listBox;
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
