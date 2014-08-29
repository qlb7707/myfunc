// ImageProc.cpp : 实现文件
//

#include "stdafx.h"
#include "myfun.h"
#include "ImageProc.h"
#include "afxdialogex.h"


// CImageProc 对话框

IMPLEMENT_DYNAMIC(CImageProc, CDialogEx)

CImageProc::CImageProc(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageProc::IDD, pParent)
{

	m_dir = _T("");
}

CImageProc::~CImageProc()
{
}

void CImageProc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImageProc, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CImageProc::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_VIDEOWRITE, &CImageProc::OnBnClickedVideowrite)
END_MESSAGE_MAP()


// CImageProc 消息处理程序


void CImageProc::OnBnClickedButton1()
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


BOOL CImageProc::OnInitDialog()
{
	CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_fileName.size();
	for(int i=0;i<fileNum;i++)
	{
		CString name;
		int id=dlg->m_fileName[i].ReverseFind('\\');
		name=dlg->m_fileName[i].Right(dlg->m_fileName[i].GetLength()-id-1);
		CListBox *box=(CListBox *)GetDlgItem(IDC_LIST1);
		box->AddString(name);

		//m_listBox.InsertString(_T("1"));

	}
	CDialogEx::OnInitDialog();
	return 0;

}


void CImageProc::OnBnClickedVideowrite()
{

	// TODO: 在此添加控件通知处理程序代码
	
	CString FilePathName;
	CFileDialog dlg(FALSE,_T(".avi"),NULL,OFN_HIDEREADONLY ,_T("(*.avi)|*.avi|(*.mp4)|*.mp4|All Files(*.*)|*.*||"));///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(dlg.DoModal()==IDOK)
	FilePathName=dlg.GetPathName();
	CmyfunDlg *fdlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=fdlg->m_fileName.size();
	IplImage *img=cvLoadImage(ws2s((fdlg->m_fileName[0]).GetBuffer(0)).c_str());
	if(img)
	{
		CvVideoWriter *writer=cvCreateVideoWriter(ws2s(FilePathName.GetBuffer(0)).c_str(),0,25,cvGetSize(img));
		for(int i=0;i<fileNum;i++)
		{
			cvReleaseImage(&img);
			img=cvLoadImage(ws2s((fdlg->m_fileName[i]).GetBuffer(0)).c_str());
			cvWriteFrame(writer,img);
		}
		if(img)cvReleaseImage(&img);
		cvReleaseVideoWriter(&writer);
		MessageBox(_T("保存完毕！"));
	}

}
