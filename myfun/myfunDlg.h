
// myfunDlg.h : 头文件
//

#pragma once
#include<vector>
using namespace std;
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "CvvImage.h"
#include "WriteFrameDlg.h"
#include "VideoProSingleDlg.h"
#include "ImageProc.h"
#include "mystatic.h"
// CmyfunDlg 对话框
class CmyfunDlg : public CDialogEx
{
// 构造
public:
	CmyfunDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYFUN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcmenubutton2();
	HMENU m_hMenu;
	afx_msg void On32771();
	vector<CString> m_fileName;
	afx_msg void OnOpenvideo();
	void DrawPicToHDC(IplImage * img, UINT ID);
	IplImage *m_img;
	CvCapture *m_capture;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnWritefreame();
	afx_msg void OnVideodir();
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedSetpos();
	int m_framePos;
	afx_msg void OnBnClickedPre();
//	CString m_singleFileName;
	vector<CString> m_singleFileName;
	afx_msg void OnMatting();
	afx_msg void OnBatchpic();
	int m_picpos;
	afx_msg void OnBnClickedNextpic();
	afx_msg void OnBnClickedPrepic();
//	afx_msg void OnEnChangeEdit1();
//	afx_msg void OnBnClickedFixed();
	bool m_fixedMatting;
	bool m_ratedMatting;
//	afx_msg void OnBnClickedRated();
	afx_msg void OnStnClickedPicture();
//	CMyStatic m_pictureBox;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint m_pt1;
	CPoint m_pt2;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	vector<CRect> m_rects;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool m_startMatting;
	void Refresh(void);
//	afx_msg void OnBnClickedRadio1();
	int m_radio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedColor();
	COLORREF m_clr;
	IplImage *m_temp;
//	afx_msg void OnEnChangeEdit2();
	int m_regionHeight;
	int m_regionWidth;
	afx_msg void OnBnClickedButton1();
};
