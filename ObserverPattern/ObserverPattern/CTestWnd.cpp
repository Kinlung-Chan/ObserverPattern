#include "stdafx.h"
#include "CTestWnd.h"


CTestWnd::CTestWnd()
{
}


CTestWnd::~CTestWnd()
{
}


void CTestWnd::Attach(CTestWndObserver* pObserver)
{
	m_pObservers.push_back(pObserver);
}

BEGIN_MESSAGE_MAP(CTestWnd, CWnd)
ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CTestWnd::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	for (int i = 0; i < m_pObservers.size(); i++)
		m_pObservers[i]->OnTestWndRButtonClicked(nFlags, point);

	CWnd::OnRButtonDown(nFlags, point);
}


void CTestWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	for (int i = 0; i < m_pObservers.size(); i++)
		m_pObservers[i]->OnTestWndLButtonClicked(nFlags, point);

	CWnd::OnLButtonDown(nFlags, point);
}
