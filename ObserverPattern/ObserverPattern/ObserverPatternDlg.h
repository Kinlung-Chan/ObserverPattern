
// ObserverPatternDlg.h : header file
//

#pragma once
#include "CTestWnd.h"

// CObserverPatternDlg dialog
// CObserverPatternDlg���ǹ۲��ߣ�CTestWnd�Ǳ��۲��ߣ���Ҫ��ӦCTestWnd���۲���¼����ͼ̳�CTestWndObserver��ʵ�����е��麯��
class CObserverPatternDlg : public CDialogEx, CTestWndObserver
{
// Construction
public:
	CObserverPatternDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBSERVERPATTERN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void OnTestWndLButtonClicked(UINT nFlags, CPoint point) override;
	void OnTestWndRButtonClicked(UINT nFlags, CPoint point) override;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
