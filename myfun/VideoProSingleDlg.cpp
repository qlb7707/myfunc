// VideoProSingleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "myfun.h"
#include "VideoProSingleDlg.h"
#include "afxdialogex.h"



// CVideoProSingleDlg �Ի���

IMPLEMENT_DYNAMIC(CVideoProSingleDlg, CDialogEx)

CVideoProSingleDlg::CVideoProSingleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVideoProSingleDlg::IDD, pParent)
{

	m_dir = _T("");
}

CVideoProSingleDlg::~CVideoProSingleDlg()
{
}

void CVideoProSingleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVideoProSingleDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CVideoProSingleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVideoProSingleDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CVideoProSingleDlg ��Ϣ�������


void CVideoProSingleDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		wchar_t szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    CString str;

    ZeroMemory(szPath, sizeof(szPath));   

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = _T("��ѡ����Ҫ�����Ŀ¼��");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        str.Format(_T("ѡ���Ŀ¼Ϊ %s"),  szPath);
        AfxMessageBox(str);    
    }
    else   
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));
	m_dir=szPath;
}


void CVideoProSingleDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_singleFileName.size();
	for(int i=0;i<fileNum;i++)
	{
		CString fullname;
		CString dstdir;
		fullname=dlg->m_singleFileName[i];
		framewrite(ws2s(fullname.GetBuffer(0)),ws2s(m_dir.GetBuffer()));
	}

	MessageBox(_T("������ɣ�"));
}


BOOL CVideoProSingleDlg::OnInitDialog()
{
	

	CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_singleFileName.size();
	//for(int i=0;i<fileNum;i++)
	//{
		CString name;
		int id=dlg->m_singleFileName[0].ReverseFind('\\');
		name=dlg->m_singleFileName[0].Right(dlg->m_singleFileName[0].GetLength()-id-1);
		CEdit *edit=(CEdit *)GetDlgItem(IDC_EDIT1);
		edit->SetWindowTextW(name);
		

		//m_listBox.InsertString(_T("1"));

	//}
	CDialogEx::OnInitDialog();
	return 0;
}
