#pragma once
#include "myfunDlg.h"

// CVideoProSingleDlg �Ի���

class CVideoProSingleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVideoProSingleDlg)

public:
	CVideoProSingleDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVideoProSingleDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_dir;
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
