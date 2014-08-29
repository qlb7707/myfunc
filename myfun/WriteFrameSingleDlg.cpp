#include "stdafx.h"
#include "WriteFrameSingleDlg.h"
#include "myfunDlg.h"

CWriteFrameSingleDlg::CWriteFrameSingleDlg(void)
{
}


CWriteFrameSingleDlg::~CWriteFrameSingleDlg(void)
{
}


BOOL CWriteFrameSingleDlg::OnInitDialog()
{
	CmyfunDlg *dlg=(CmyfunDlg *)AfxGetApp()->m_pMainWnd;
	int fileNum=dlg->m_singleFileName.size();
	for(int i=0;i<fileNum;i++)
	{
		CString name;
		int id=dlg->m_fileName[i].ReverseFind('\\');
		name=dlg->m_singleFileName[i].Right(dlg->m_singleFileName[i].GetLength()-id-1);
		CListBox *box=(CListBox *)GetDlgItem(IDC_FILELIST1);
		box->AddString(name);

		//m_listBox.InsertString(_T("1"));

	}
	CDialogEx::OnInitDialog();
	return 0;


}
