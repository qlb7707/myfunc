#pragma once
#include "afxwin.h"
#include "utility.h"

// CWriteFrameDlg �Ի���

class CWriteFrameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWriteFrameDlg)

public:
	CWriteFrameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWriteFrameDlg();

// �Ի�������
	enum { IDD = IDD_WRITEFRAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
