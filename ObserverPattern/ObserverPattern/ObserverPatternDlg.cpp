
// ObserverPatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ObserverPattern.h"
#include "ObserverPatternDlg.h"
#include "afxdialogex.h"
#include "CTestWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CObserverPatternDlg dialog



CObserverPatternDlg::CObserverPatternDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OBSERVERPATTERN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CObserverPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CObserverPatternDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CObserverPatternDlg message handlers

BOOL CObserverPatternDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CObserverPatternDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CObserverPatternDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CObserverPatternDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CTestWnd* wnd = new	CTestWnd();
	wnd->Create(NULL, _T("Test Wnd"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 100, 100), this, 1234);
	wnd->Attach(this);
	return 0;
}


void CObserverPatternDlg::OnTestWndLButtonClicked(UINT nFlags, CPoint point)
{
	GetDlgItem(IDC_STATIC)->SetWindowText(_T("OnTestWndLButtonClicked"));
}


void CObserverPatternDlg::OnTestWndRButtonClicked(UINT nFlags, CPoint point) 
{
	GetDlgItem(IDC_STATIC)->SetWindowText(_T("OnTestWndRButtonClicked"));
}
