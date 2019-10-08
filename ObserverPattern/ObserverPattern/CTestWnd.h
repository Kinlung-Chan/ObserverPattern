#pragma once
#include <afxwin.h>
#include <vector>

//����۲��ߵ���Ϊ
class CTestWndObserver
{
public:
	virtual void OnTestWndLButtonClicked(UINT nFlags, CPoint point) = 0;
	virtual void OnTestWndRButtonClicked(UINT nFlags, CPoint point) = 0;
};


//���屻�۲���
class CTestWnd : public CWnd
{
public:
	CTestWnd();
	virtual ~CTestWnd();

	void Attach(CTestWndObserver* pObserver);  //���Ĺ۲���

private:
	std::vector<CTestWndObserver*> m_pObservers;   //����Ĺ۲��߶���ָ�룬�ɸ�����Ҫʹ��vector������һ�飬Ҳ����ֻ����һ��
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

