#pragma once
#include"myfunDlg.h"

// CImageProc �Ի���

class CImageProc : public CDialogEx
{
	DECLARE_DYNAMIC(CImageProc)

public:
	CImageProc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CImageProc();

// �Ի�������
	enum { IDD = IDD_IMGPROC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_dir;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedVideowrite();
};
