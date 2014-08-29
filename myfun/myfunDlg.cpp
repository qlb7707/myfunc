
// myfunDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "myfun.h"
#include "myfunDlg.h"
#include "afxdialogex.h"
#include "utility.h"
#include "windows.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnOpenvideo();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_OPENVIDEO, &CAboutDlg::OnOpenvideo)
END_MESSAGE_MAP()


// CmyfunDlg �Ի���



CmyfunDlg::CmyfunDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmyfunDlg::IDD, pParent)
	, m_radio(0)
	, m_regionHeight(0)
	, m_regionWidth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_framePos = 0;
	//  m_singleFileName = _T("");
	m_picpos = 0;
}

void CmyfunDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_PICTURE, m_pictureBox);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Text(pDX, IDC_EDIT2, m_regionHeight);
	DDX_Text(pDX, IDC_EDIT3, m_regionWidth);
}

BEGIN_MESSAGE_MAP(CmyfunDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_MFCMENUBUTTON2, &CmyfunDlg::OnBnClickedMfcmenubutton2)
ON_COMMAND(ID_32771, &CmyfunDlg::On32771)
ON_COMMAND(ID_OPENVIDEO, &CmyfunDlg::OnOpenvideo)
ON_WM_TIMER()
ON_COMMAND(ID_WRITEFREAME, &CmyfunDlg::OnWritefreame)
ON_COMMAND(ID_VIDEODIR, &CmyfunDlg::OnVideodir)
ON_BN_CLICKED(IDC_PLAY, &CmyfunDlg::OnBnClickedPlay)
ON_BN_CLICKED(IDC_PAUSE, &CmyfunDlg::OnBnClickedPause)
ON_BN_CLICKED(IDC_NEXT, &CmyfunDlg::OnBnClickedNext)
ON_BN_CLICKED(IDC_SETPOS, &CmyfunDlg::OnBnClickedSetpos)
ON_BN_CLICKED(IDC_PRE, &CmyfunDlg::OnBnClickedPre)
ON_COMMAND(ID_MATTING, &CmyfunDlg::OnMatting)
ON_COMMAND(ID_BATCHPIC, &CmyfunDlg::OnBatchpic)
ON_BN_CLICKED(IDC_NEXTPIC, &CmyfunDlg::OnBnClickedNextpic)
ON_BN_CLICKED(IDC_PREPIC, &CmyfunDlg::OnBnClickedPrepic)
//ON_EN_CHANGE(IDC_EDIT1, &CmyfunDlg::OnEnChangeEdit1)
//ON_BN_CLICKED(IDC_FIXED, &CmyfunDlg::OnBnClickedFixed)
//ON_BN_CLICKED(IDC_RATED, &CmyfunDlg::OnBnClickedRated)
ON_STN_CLICKED(IDC_PICTURE, &CmyfunDlg::OnStnClickedPicture)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_BN_CLICKED(IDC_BUTTON5, &CmyfunDlg::OnBnClickedButton5)
ON_WM_MOUSEMOVE()
//ON_BN_CLICKED(IDC_RADIO1, &CmyfunDlg::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO1, &CmyfunDlg::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO2, &CmyfunDlg::OnBnClickedRadio2)
ON_BN_CLICKED(IDC_RADIO3, &CmyfunDlg::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_COLOR, &CmyfunDlg::OnBnClickedColor)
//ON_EN_CHANGE(IDC_EDIT2, &CmyfunDlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_BUTTON1, &CmyfunDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CmyfunDlg ��Ϣ�������

BOOL CmyfunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_hMenu=LoadMenu(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU1));
	::SetMenu(this->GetSafeHwnd(),m_hMenu);
	m_img=NULL;
	m_capture=NULL;
	m_picpos=0;
	m_framePos=0;
	CEdit *edit=(CEdit*)GetDlgItem(IDC_EDIT1);
	CString text,latext;
	text.Format(_T("%d"),m_framePos);
	edit->SetWindowTextW(text);
	CStatic *label=(CStatic*)GetDlgItem(IDC_POS);
	latext.Format(_T("��ǰΪ��%d/%d֡"),m_framePos,0);
	label->SetWindowTextW(latext);
	m_fixedMatting=FALSE;
	m_ratedMatting=FALSE;
	m_startMatting=FALSE;
	m_clr=RGB(0,0,0);
	m_temp=NULL;
	m_regionHeight=100;
	m_regionWidth=100;
	m_radio=0;
	UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CmyfunDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmyfunDlg::OnPaint()
{
	//IplImage *temp=NULL;
	if(m_img)
	{
		m_temp=cvCloneImage(m_img);
		//DrawPicToHDC(temp,IDC_PICTURE);
	}
	
	



	int n=m_rects.size();
	CDC *pDC=GetDlgItem(IDC_PICTURE)->GetDC();
	HDC hdc=pDC->GetSafeHdc();
	CPen pen(PS_SOLID,3,m_clr);
	pDC->SelectObject(&pen);
	CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *oldBrush=pDC->SelectObject(brush);
 	for(int i=0;i<n;i++)
	{
		CRect rect(m_rects[i]);
		cvRectangle(m_temp,cvPoint(m_rects[i].left,m_rects[i].top),cvPoint(m_rects[i].right,m_rects[i].bottom),CV_RGB(GetRValue(m_clr),GetGValue(m_clr),GetBValue(m_clr)));
		//Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
	}
	
	if(m_temp)
	{
		//cvReleaseImage(&m_img);
		//m_img=temp;
		DrawPicToHDC(m_temp,IDC_PICTURE);
		cvReleaseImage(&m_temp);
	}

	brush=pDC->SelectObject(oldBrush);
	ReleaseDC(pDC);
	
	if(m_capture)
	{
		m_framePos=cvGetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES);
		int frames=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT);
		CStatic *label=(CStatic*)GetDlgItem(IDC_POS);
		CString text;
		text.Format(_T("��ǰΪ:%d/%d֡"),m_framePos,frames);
		label->SetWindowTextW(text);
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CmyfunDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CmyfunDlg::On32771()
{
	// TODO: �ڴ���������������
	if(!m_singleFileName.empty()) m_singleFileName.clear();
	/*if(m_capture)
	{
		cvReleaseCapture(&m_capture);
		m_capture=NULL;
		m_img=NULL;
		m_framePos=0;
	}
	if(m_img)
	{
		cvReleaseImage(&m_img);
		m_img=NULL;
	}*/
	Refresh();
	
	//CString FilePathName;
 // CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY ,_T("(*.jpg)|*.jpg|(*.png)|*.png|All Files(*.*)|*.*||"));///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
 // if(dlg.DoModal()==IDOK)
 // FilePathName=dlg.GetPathName();
 // m_singleFileName.push_back(FilePathName);
	//CMenu* mmenu = GetMenu();
	//CMenu* submenu = mmenu->GetSubMenu(3); //�Ӳ˵�ָ��
	//submenu->EnableMenuItem(0, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
	//submenu->EnableMenuItem(3, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
	//if(m_img)
	//{
	//	cvReleaseImage(&m_img);
	//	m_img=NULL;
	//}
	//wstring name=FilePathName.GetBuffer(0);
	//m_img=cvLoadImage(ws2s(name).c_str());
	//DrawPicToHDC(m_img,IDC_PICTURE);

	//if(!m_fileName.empty()) m_fileName.clear();
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
		vector<string> files;
		getFiles(ws2s(CString(szPath).GetBuffer(0)),files);
		int n=files.size();
		for(int i=0;i<n;i++)
		{
			m_singleFileName.push_back(s2ws(files[i]).c_str());
		}
        str.Format(_T("ѡ���Ŀ¼Ϊ %s"),  szPath);
        AfxMessageBox(str);  
		if(m_singleFileName.empty())
		{
			MessageBox(_T("��ѡ��ͼ��Ŀ¼!"));
			return;
		}
		if(m_capture)
		{
			cvReleaseCapture(&m_capture);
			m_framePos=0;
		}
		if(m_img)
		{
			cvReleaseImage(&m_img);
			m_picpos=0;
		}
		m_picpos=0;
		m_img=cvLoadImage(ws2s(m_singleFileName[m_picpos].GetBuffer(0)).c_str());
		(CButton *)GetDlgItem(IDC_PLAY)->EnableWindow(FALSE);
		(CButton *)GetDlgItem(IDC_PAUSE)->EnableWindow(FALSE);
		(CButton *)GetDlgItem(IDC_NEXT)->EnableWindow(FALSE);
		(CButton *)GetDlgItem(IDC_PRE)->EnableWindow(FALSE);
		(CButton *)GetDlgItem(IDC_SETPOS)->EnableWindow(FALSE);
		(CButton *)GetDlgItem(IDC_NEXTPIC)->EnableWindow(TRUE);
		(CButton *)GetDlgItem(IDC_PREPIC)->EnableWindow(TRUE);
	
	
		OnPaint();

		
    }
    else   
	{
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));  
		
	}
}


//void CAboutDlg::OnOpenvideo()
//{
//	// TODO: �ڴ���������������
//	CString FilePathName;
//  CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY ,_T("(*.jpg)|*.jpg|(*.png)|*.png|All Files(*.*)|*.*||"));///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
//  if(dlg.DoModal()==IDOK)
//  FilePathName=dlg.GetPathName();
//  m_fileName.push_back(FilePathName);
//}


void CmyfunDlg::OnOpenvideo()
{
	// TODO: �ڴ���������������
	if(!m_singleFileName.empty()) m_singleFileName.clear();
	CString FilePathName;
	//if(m_capture)
	//{
	//	cvReleaseCapture(&m_capture);
	//	m_capture=NULL;
	//	m_img=NULL;
	//	m_framePos=0;
	//}
	//if(m_img)
	//{
	//	cvReleaseImage(&m_img);
	//	m_img=NULL;
	//	m_picpos=0;
	//}
	Refresh();
	
  CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY ,_T("(*.avi)|*.avi|(*.mp4)|*.mp4|All Files(*.*)|*.*||"));///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
  if(dlg.DoModal()==IDOK)
  FilePathName=dlg.GetPathName();
  m_singleFileName.push_back(FilePathName);
  	CMenu* mmenu = GetMenu();
	CMenu* submenu = mmenu->GetSubMenu(3); //�Ӳ˵�ָ��
	submenu->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED );
	submenu->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED );
	
	wstring name=FilePathName.GetBuffer(0);
	m_capture = cvCreateFileCapture(ws2s(name).c_str());
	
	
	if(!m_capture) return;
	m_img=cvQueryFrame(m_capture);
	(CButton *)GetDlgItem(IDC_PLAY)->EnableWindow(TRUE);
	(CButton *)GetDlgItem(IDC_PAUSE)->EnableWindow(TRUE);
	(CButton *)GetDlgItem(IDC_NEXT)->EnableWindow(TRUE);
	(CButton *)GetDlgItem(IDC_PRE)->EnableWindow(TRUE);
	(CButton *)GetDlgItem(IDC_SETPOS)->EnableWindow(TRUE);
	(CButton *)GetDlgItem(IDC_NEXTPIC)->EnableWindow(FALSE);
	(CButton *)GetDlgItem(IDC_PREPIC)->EnableWindow(FALSE);
	OnPaint();
	//Invalidate();
	//int fps=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS);
	//SetTimer(1,1000/fps,NULL);

}


void CmyfunDlg::DrawPicToHDC(IplImage * img, UINT ID)
{
	if(!img)return ;
	CDC *pDC = GetDlgItem(ID)->GetDC();
	//CRect prect;
	//GetDlgItem(ID)->GetClientRect(&prect);
	if(img->width>653||img->height>425)
	{
		double rt1=653.0/img->width;
		double rt2=425.0/img->height;
		double rt;
		if(rt1>rt2)
			rt=rt2;
		else
			rt=rt1;
		IplImage *temp=cvCreateImage(cvSize(cvRound(img->width*rt),cvRound(img->height*rt)),img->depth,img->nChannels);
		IplImage *temptemp=cvCreateImage(cvSize(cvRound(img->width*rt),cvRound(img->height*rt)),img->depth,img->nChannels);
		cvResize(m_img,temp);
		cvResize(img,temptemp);
		if(!m_capture)
		{
			cvReleaseImage(&m_img);

		}
		cvReleaseImage(&img);
		m_img=temp;
		img=temptemp;
		m_temp=temptemp;
	}
	HDC hDC= pDC->GetSafeHdc();
	CRect dlgRect;
	this->GetClientRect(&dlgRect);
	int x,y;
	x=(653-(img->width))/2;
	y=(425-(img->height))/2;
	CRect rect((653-(img->width))/2,(425-(img->height))/2,(653+(img->width))/2,(425+(img->height))/2);
	
	
	//GetDlgItem(ID)->GetClientRect(&rect);
	GetDlgItem(ID)->MoveWindow(rect,1);
	CRect picRect;
	GetDlgItem(ID)->GetClientRect(&picRect);
	
	CvvImage cimg;
	cimg.CopyOf( img ); // ����ͼƬ
	cimg.DrawToHDC( hDC, &picRect ); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC( pDC );

}


void CmyfunDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(1==nIDEvent)
	{
		if(m_img=cvQueryFrame(m_capture))
		{
			DrawPicToHDC(m_img,IDC_PICTURE);
			OnPaint();
		}
		else
		{
			OnPaint();
			cvSetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES,0);
			KillTimer(1);
			
		}
		
		/*m_framePos=cvGetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES);
		int frames=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT);
		CStatic *label=(CStatic*)GetDlgItem(IDC_POS);
		CString text;
		text.Format(_T("��ǰΪ:%d/%d֡"),m_framePos,frames);
		label->SetWindowTextW(text);*/
		
		//Invalidate();
		
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CmyfunDlg::OnWritefreame()
{
	// TODO: �ڴ���������������
	/*if(m_img)
	{
		cvReleaseImage(&m_img);
		m_img=NULL;
	}
	if(m_capture)
	{
		cvReleaseCapture(&m_capture);
		m_capture=NULL;
	}*/
	if(m_singleFileName.empty())
	{
		MessageBox(_T("��ѡ����Ƶ����ƵĿ¼!"));
		return;
	}
	int fileNum=m_singleFileName.size();
	 CVideoProSingleDlg dlg;
	dlg.DoModal();
}


void CmyfunDlg::OnVideodir()
{
	// TODO: �ڴ���������������
	
	if(!m_fileName.empty()) m_fileName.clear();
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
		vector<string> files;
		getFiles(ws2s(CString(szPath).GetBuffer(0)),files);
		int n=files.size();
		for(int i=0;i<n;i++)
		{
			m_fileName.push_back(s2ws(files[i]).c_str());
		}
        str.Format(_T("ѡ���Ŀ¼Ϊ %s"),  szPath);
        AfxMessageBox(str);    

		/*if(m_img)
		{
			cvReleaseImage(&m_img);
			m_img=NULL;
		}
		if(m_capture)
		{
			cvReleaseCapture(&m_capture);
			m_capture=NULL;
		}*/
		if(m_fileName.empty())
		{
			MessageBox(_T("��ѡ����Ƶ����ƵĿ¼!"));
			return;
		}
		int fileNum=m_fileName.size();
		CWriteFrameDlg dlg;
		dlg.DoModal();

    }
    else   
	{
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));  
		return;
	}

}


void CmyfunDlg::OnBnClickedPlay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_rects.clear();
	//m_radio=0;
	if(!m_capture)
	{
		MessageBox(_T("�����Ƶ�ļ���"));
		return;
	}
	int fps=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS);
	SetTimer(1,1000/fps,NULL);
	UpdateData(FALSE);
}


void CmyfunDlg::OnBnClickedPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}


void CmyfunDlg::OnBnClickedNext()
{
	m_rects.clear();
	if(!m_capture)
	{
		MessageBox(_T("�����Ƶ�ļ���"));
		return;
	}
	m_img=cvQueryFrame(m_capture);
	//Invalidate();
	if(!m_img)
	{
		MessageBox(_T("��Ƶ������"));
		return;
	}
	//m_framePos=cvGetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES);
	//int frames=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT);
	//CStatic *label=(CStatic*)GetDlgItem(IDC_POS);
	//CString text;
	//text.Format(_T("��ǰΪ:%d/%d֡"),m_framePos,frames);
	//label->SetWindowTextW(text);
	OnPaint();
	//UpdateWindow();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CmyfunDlg::OnBnClickedSetpos()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_rects.clear();
	CEdit *edit=(CEdit *)GetDlgItem(IDC_EDIT1);
	CString setpos;
	edit->GetWindowTextW(setpos);
	int n=atoi(ws2s(setpos.GetBuffer(0)).c_str());
	int total=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT);
	if(n<=total&&n>0)
		m_framePos=n;
	else
	{
		MessageBox(_T("���벻�Ϸ���"));
		return;
	}
	cvSetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES,m_framePos-1);
	m_img=cvQueryFrame(m_capture);
	OnPaint();
}


void CmyfunDlg::OnBnClickedPre()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_rects.clear();
	m_framePos-=2;
	if(!m_capture)
	{
		MessageBox(_T("�����Ƶ�ļ���"));
		return;
	}
	//m_img=cvQueryFrame(m_capture);
	//Invalidate();
	if(m_framePos<0)
	{
		MessageBox(_T("�ѵ���Ƶ��ͷ��"));
		return;
	}

	cvSetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES,m_framePos);
	m_img=cvQueryFrame(m_capture);
	OnPaint();
}


void CmyfunDlg::OnMatting()
{
	// TODO: �ڴ���������������
}


void CmyfunDlg::OnBatchpic()
{
	// TODO: �ڴ���������������
	if(!m_fileName.empty()) m_fileName.clear();
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
		vector<string> files;
		getFiles(ws2s(CString(szPath).GetBuffer(0)),files);
		int n=files.size();
		for(int i=0;i<n;i++)
		{
			m_fileName.push_back(s2ws(files[i]).c_str());
		}
        str.Format(_T("ѡ���Ŀ¼Ϊ %s"),  szPath);
        AfxMessageBox(str);  
		if(m_fileName.empty())
		{
			MessageBox(_T("��ѡ��ͼ���ͼ��Ŀ¼!"));
			return;
		}

		/*if(m_capture)
		{
			cvReleaseCapture(&m_capture);
			m_capture=NULL;
			m_framePos=0;
		}

		if(m_img)
		{
			cvReleaseImage(&m_img);
			m_img=NULL;
		}
		
		
		int fileNum=m_fileName.size();
		m_img=cvLoadImage(ws2s(m_fileName[0].GetBuffer(0)).c_str());
		OnPaint();*/
		CImageProc dlg;
		dlg.DoModal();


    }
    else   
	{
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));  
		
	}
}


void CmyfunDlg::OnBnClickedNextpic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_rects.clear();
	if(m_singleFileName.empty())
	{
		MessageBox(_T("û���ļ���"));
		return;
	}
	if(m_picpos+1==m_singleFileName.size())
	{
		MessageBox(_T("���һ�ţ�"));
		return;
	}
	m_picpos++;
	if(m_capture&&m_img)
	{
		cvReleaseCapture(&m_capture);
		m_capture=NULL;
		m_framePos=0;
	}
	else if(m_img)
	{
		cvReleaseImage(&m_img);
		m_img=NULL;
	}
	m_img=cvLoadImage(ws2s(m_singleFileName[m_picpos].GetBuffer(0)).c_str());
	OnPaint();


	
}


void CmyfunDlg::OnBnClickedPrepic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_rects.clear();
	if(m_singleFileName.empty())
	{
		MessageBox(_T("û���ļ���"));
		return;
	}
	if(m_picpos==0)
	{
		MessageBox(_T("��һ�ţ�"));
		return;
	}
	m_picpos--;
	if(m_capture)
	{
		cvReleaseCapture(&m_capture);
		m_capture=NULL;
		m_framePos=0;
	}
	if(m_img)
	{
		cvReleaseImage(&m_img);
		m_img=NULL;
	}
	m_img=cvLoadImage(ws2s(m_singleFileName[m_picpos].GetBuffer(0)).c_str());
	OnPaint();

}


//void CmyfunDlg::OnEnChangeEdit1()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//#1015
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


//void CmyfunDlg::OnBnClickedFixed()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	m_fixedMatting=TRUE;
//	m_ratedMatting=FALSE;
//}


//void CmyfunDlg::OnBnClickedRated()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	m_fixedMatting=FALSE;
//	m_ratedMatting=TRUE;
//}


void CmyfunDlg::OnStnClickedPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CmyfunDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(!m_img)return;
	if(m_ratedMatting)
	{
		m_startMatting=TRUE;
		RECT rc;
		POINT pt;
		GetCursorPos(&pt);
		//ClientToScreen(&point);
		::GetWindowRect(::GetDlgItem(this->m_hWnd,IDC_PICTURE),&rc);
		CRect picRect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&picRect);

		if(PtInRect(&rc,pt))
		{
			m_startMatting=TRUE;
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt);
			m_pt1.x=pt.x;//point.x-picRect.left;
			m_pt1.y=pt.y;//point.y-picRect.top;
			m_rects.push_back(CRect(m_pt1,m_pt1));
		}
	}
	if(m_fixedMatting)
	{
		int n=m_rects.size();
		if(n==0)return;
		CRect rect=m_rects[n-1];
		m_rects.push_back(rect);

	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CmyfunDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(!m_img) return;
	if(m_ratedMatting)
	{
		
		RECT rc;
		POINT pt;
		GetCursorPos(&pt);
		//ClientToScreen(&point);
		::GetWindowRect(::GetDlgItem(this->m_hWnd,IDC_PICTURE),&rc);
		CRect picRect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&picRect);
		if(PtInRect(&rc,pt))
		{
			m_rects.pop_back();
			m_startMatting=FALSE;
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt);
			m_pt2.x=pt.x;//point.x-picRect.left;
			m_pt2.y=pt.y;//point.y-picRect.top;
			CRect rect(m_pt1.x,m_pt1.y,m_pt2.x,m_pt2.y);
			//m_rects.push_back(rect);
			CPoint center((rect.left+rect.right)/2,(rect.top+rect.bottom)/2);
			CRect region(center.x-rect.Width()/2,center.y-rect.Height()/2,center.x+rect.Width()/2,center.y+rect.Height()/2);
			m_rects.push_back(region);
		
		CDC *pDC=GetDlgItem(IDC_PICTURE)->GetDC();
		HDC hdc=pDC->GetSafeHdc();


		//Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
		Rectangle(hdc,region.left,region.top,region.right,region.bottom);
		OnPaint();
		ReleaseDC(pDC);
		}
		m_startMatting=FALSE;
	}


	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmyfunDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	string saveName,dir2frm;
	if(!m_rects.empty()) 
		m_rects.pop_back();
	if(m_capture)
	{
		CString add;
		int id=m_singleFileName[0].ReverseFind('.');
		add.Format(_T("frame_%04d"),m_framePos);
		//int id2=m_singleFileName[0].ReverseFind('\\');Ϊ�˵õ��ļ�Ŀ¼
		dir2frm=ws2s(m_singleFileName[0].Left(id).GetBuffer(0))+'\\'+ws2s(add.GetBuffer(0));//add.Format(_T("frame_%04d"),m_framePos);
		CreateDirectory(m_singleFileName[0].Left(id),NULL);
		int n=m_rects.size();
		for(int i=0;i<n;i++)
		{
			CString rectNo;
			rectNo.Format(_T("_%d.jpg"),i);
			saveName=dir2frm+ws2s(rectNo.GetBuffer(0));
			CRect rect=m_rects[i];
			CvRect roi=cvRect(rect.left,rect.top,rect.Width(),rect.Height());
			cvSetImageROI(m_img,roi);
			IplImage *crop=cvCreateImage(cvSize(roi.width,roi.height),m_img->depth,m_img->nChannels);
			cvCopy(m_img,crop);
			cvSaveImage(saveName.c_str(),crop);
			cvResetImageROI(m_img);
			cvReleaseImage(&crop);		

		}
		

	}
	else if(m_img)
	{
		CString add;
		string picName,temp;
		int id=m_singleFileName[m_picpos].ReverseFind('.');
		//add.Format(_T("picture_%04d"),m_framePos);
		int id2=m_singleFileName[m_picpos].ReverseFind('\\');
		dir2frm=ws2s(m_singleFileName[m_picpos].Left(id2).GetBuffer(0));//+ws2s(add.GetBuffer(0));//add.Format(_T("frame_%04d"),m_framePos);
		CreateDirectory(s2ws(dir2frm+"\\Crop").c_str(),NULL);
		temp=ws2s(m_singleFileName[m_picpos].Right(m_singleFileName[m_picpos].GetLength()-id2).GetBuffer(0));
		picName=temp.substr(0,temp.length()-4);
		int n=m_rects.size();
		for(int i=0;i<n;i++)
		{
			CString rectNo;
			rectNo.Format(_T("_%d.jpg"),i);
			saveName=dir2frm+"\\Crop\\"+picName+ws2s(rectNo.GetBuffer(0));
			CRect rect=m_rects[i];
			CvRect roi=cvRect(rect.left,rect.top,rect.Width(),rect.Height());
			cvSetImageROI(m_img,roi);
			IplImage *crop=cvCreateImage(cvSize(roi.width,roi.height),m_img->depth,m_img->nChannels);
			cvCopy(m_img,crop);
			cvSaveImage(saveName.c_str(),crop);
			cvResetImageROI(m_img);
			cvReleaseImage(&crop);		

		}
		
	}
	m_rects.clear();
}


void CmyfunDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(!m_img) return;
	if(m_startMatting&&m_ratedMatting)
	{
		RECT rc;
		POINT pt;
		GetCursorPos(&pt);
		//ClientToScreen(&point);
		::GetWindowRect(::GetDlgItem(this->m_hWnd,IDC_PICTURE),&rc);
		CRect picRect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&picRect);

		if(PtInRect(&rc,pt))
		{
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt);
			CRect rect(m_pt1.x,m_pt1.y,pt.x,pt.y);
			m_rects.pop_back();
			m_rects.push_back(rect);
			OnPaint();
			//re
			/*CDC *pDC=GetDlgItem(IDC_PICTURE)->GetDC();
			HDC hdc=pDC->GetSafeHdc();
			*/
			//OnPaint();
			/*CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
			CBrush *oldBrush=pDC->SelectObject(brush);
			Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
			brush=pDC->SelectObject(oldBrush);*/
			//ReleaseDC(pDC);
			//OnPaint();
		}
		
	}
	if(m_fixedMatting)
	{
		UpdateData(FALSE);
		RECT rc;
		POINT pt;
		GetCursorPos(&pt);
		//ClientToScreen(&point);
		::GetWindowRect(::GetDlgItem(this->m_hWnd,IDC_PICTURE),&rc);
		CRect picRect;
		GetDlgItem(IDC_PICTURE)->GetClientRect(&picRect);
		CPoint pt1=CPoint(pt.x-m_regionWidth/2,pt.y-m_regionHeight/2);
		CPoint pt2=CPoint(pt.x+m_regionWidth/2,pt.y-m_regionHeight/2);
		CPoint pt3=CPoint(pt.x-m_regionWidth/2,pt.y+m_regionHeight/2);
		CPoint pt4=CPoint(pt.x+m_regionWidth/2,pt.y+m_regionHeight/2);
		if(PtInRect(&rc,pt4)&&PtInRect(&rc,pt1)&&PtInRect(&rc,pt2)&&PtInRect(&rc,pt3))
		{
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt1);
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt2);
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt3);
			GetDlgItem(IDC_PICTURE)->ScreenToClient(&pt4);
			CRect rect(pt1.x,pt1.y,pt4.x,pt4.y);
			if(!m_rects.empty())
				m_rects.pop_back();
			m_rects.push_back(rect);
			OnPaint();
			//m_rects.pop_back();

		}


	}


	CDialogEx::OnMouseMove(nFlags, point);

}


void CmyfunDlg::Refresh(void)
{
	if(m_capture)
	{
		cvReleaseCapture(&m_capture);
		m_capture=NULL;
		m_framePos=0;
	}
	else if(m_img)
	{
		cvReleaseImage(&m_img);
		m_img=NULL;
		m_picpos=0;
	}
	if(!m_rects.empty())
		m_rects.clear();
	m_pt1.x=0;
	m_pt1.y=0;
	m_pt2.x=0;
	m_pt2.y=0;

}


//void CmyfunDlg::OnBnClickedRadio1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}


void CmyfunDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch(m_radio)
	{
	case 0:
		m_fixedMatting=FALSE;
		m_ratedMatting=FALSE;
		if(!m_rects.empty())
			m_rects.clear();
		OnPaint();
		break;
	case 1:
		m_fixedMatting=TRUE;
		m_ratedMatting=FALSE;
		break;
	case 2:
		m_fixedMatting=FALSE;
		m_ratedMatting=TRUE;
		break;
	}

}


void CmyfunDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch(m_radio)
	{
	case 0:
		m_fixedMatting=FALSE;
		m_ratedMatting=FALSE;
		break;
	case 1:
		m_fixedMatting=TRUE;
		m_ratedMatting=FALSE;
		break;
	case 2:
		m_fixedMatting=FALSE;
		m_ratedMatting=TRUE;
		break;
	}
}


void CmyfunDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch(m_radio)
	{
	case 0:
		m_fixedMatting=FALSE;
		m_ratedMatting=FALSE;
		break;
	case 1:
		m_fixedMatting=TRUE;
		m_ratedMatting=FALSE;
		break;
	case 2:
		m_fixedMatting=FALSE;
		m_ratedMatting=TRUE;
		break;
	}
}


void CmyfunDlg::OnBnClickedColor()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dlg;

        dlg.m_cc.Flags |=CC_RGBINIT;

        dlg.m_cc.rgbResult=m_clr;//��ס�û�����ɫѡ��

        if(IDOK==dlg.DoModal())

        {

                m_clr=dlg.m_cc.rgbResult;

        }
}


//void CmyfunDlg::OnEnChangeEdit2()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//#1015
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


void CmyfunDlg::OnBnClickedButton1()
{
	CString FilePathName;
	if(!m_capture)
	{
		MessageBox(_T("error!"));
		return;
	}
	if(m_rects.empty())
	{
		MessageBox(_T("error!"));
		return;
	}
	CString dir,name;
	string savedir;
	int id;
	id=m_singleFileName[0].ReverseFind('\\');
	dir=m_singleFileName[0].Left(id);
	name=m_singleFileName[0].Right(m_singleFileName[0].GetLength()-id);
	savedir=ws2s(dir.GetBuffer(0))+"\\crop";
	CreateDirectory(s2ws(savedir).c_str(),NULL);
	//CString
	//CFileDialog dlg(FALSE,_T("avi"),m_singleFileName[0],OFN_HIDEREADONLY ,_T("(*.avi)|*.avi|(*.mp4)|*.mp4|All Files(*.*)|*.*||"));///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
    //if(dlg.DoModal()==IDOK)
    //FilePathName=dlg.GetPathName();
	int fps=cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS);
	CvVideoWriter *writer=cvCreateVideoWriter((savedir+"\\"+ws2s(name.GetBuffer(0))).c_str(),0,fps,cvSize(m_rects[0].Width(),m_rects[0].Height()));
	IplImage *frame,*crop;
	
	CvRect rect=cvRect(m_rects[0].left,m_rects[0].top,m_rects[0].Width(),m_rects[0].Height());
	cvSetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES,0);
	while((frame=cvQueryFrame(m_capture)))
	{
		crop=cvCreateImage(cvSize(rect.width,rect.height),frame->depth,frame->nChannels);
		cvSetImageROI(frame,rect);
		cvCopy(frame,crop);
		cvResetImageROI(frame);
		cvWriteFrame(writer,crop);
		cvReleaseImage(&crop);
	}
	cvReleaseVideoWriter(&writer);
	cvSetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES,m_framePos-1);
	m_img=cvQueryFrame(m_capture);
	MessageBox(_T("finish!"));

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
