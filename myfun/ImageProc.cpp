// ImageProc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "myfun.h"
#include "ImageProc.h"
#include "afxdialogex.h"


// CImageProc �Ի���

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


// CImageProc ��Ϣ�������


void CImageProc::OnBnClickedButton1()
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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString FilePathName;
	CFileDialog dlg(FALSE,_T(".avi"),NULL,OFN_HIDEREADONLY ,_T("(*.avi)|*.avi|(*.mp4)|*.mp4|All Files(*.*)|*.*||"));///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
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
		MessageBox(_T("������ϣ�"));
	}

}
