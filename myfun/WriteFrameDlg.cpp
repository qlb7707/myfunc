// WriteFrameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "myfun.h"
#include "WriteFrameDlg.h"
#include "afxdialogex.h"
#include "myfunDlg.h"


// CWriteFrameDlg 对话框

IMPLEMENT_DYNAMIC(CWriteFrameDlg, CDialogEx)

CWriteFrameDlg::CWriteFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWriteFrameDlg::IDD, pParent)
{

	m_dir = _T("");
}

CWriteFrameDlg::~CWriteFrameDlg()
{
}

void CWriteFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_FILELIST, m_listBox);
}


BEGIN_MESSAGE_MAP(CWriteFrameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CWriteFrameDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_FILELIST, &CWriteFrameDlg::OnLbnSelchangeFilelist)
	ON_BN_CLICKED(IDC_BUTTON2, &CWriteFrameDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CWriteFrameDlg 消息处理程序


void CWriteFrameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	wchar_t szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;

    ZeroMemory(szPath, sizeof(szPath));   

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = _T("请选择需要打包的目录：");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
        str.Format(_T("选择的目录为 %s"),  szPath);
        AfxMessageBox(str);    
    }
    else   
        AfxMessageBox(_T("无效的目录，请重新选择"));
	m_dir=szPath;

	
}


void CWriteFrameDlg::OnLbnSelchangeFilelist()
{
	// TODO: 在此添加控件通知处理程序代码
}


//BOOL CWriteFrameDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// TODO:  在此添加额外的初始化
//	CmyfunDlg dlg=AfxGetMainWnd();
//	int fileNum=dlg.m_fileName.size();
//	for(int i=0;i<fileNum;i++)
//	{
//		CString name;
//		int id=dlg.m_fileName[i].ReverseFind('\\');
//		name=dlg.m_fileName[i].Left(id);
//		m_listBox.AddString(name);
//
//	}
//	//vector<CString>names=dlg.m_fileName;
//
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// 异常: OCX 属性页应返回 FALSE
//}


BOOL CWriteFrameDlg::OnInitDialog()
{
	
	CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_fileName.size();
	for(int i=0;i<fileNum;i++)
	{
		CString name;
		int id=dlg->m_fileName[i].ReverseFind('\\');
		name=dlg->m_fileName[i].Right(dlg->m_fileName[i].GetLength()-id-1);
		CListBox *box=(CListBox *)GetDlgItem(IDC_FILELIST);
		box->AddString(name);

		//m_listBox.InsertString(_T("1"));

	}
	CDialogEx::OnInitDialog();
	return 0;

}


void CWriteFrameDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_fileName.size();
	for(int i=0;i<fileNum;i++)
	{
		CString fullname;
		CString dstdir;
		fullname=dlg->m_fileName[i];
		framewrite(ws2s(fullname.GetBuffer(0)),ws2s(m_dir.GetBuffer()));
	}

	MessageBox(_T("处理完成！"));

}
