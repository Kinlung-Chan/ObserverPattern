#pragma once
#include <afxwin.h>
#include <vector>

//定义观察者的行为
class CTestWndObserver
{
public:
	virtual void OnTestWndLButtonClicked(UINT nFlags, CPoint point) = 0;
	virtual void OnTestWndRButtonClicked(UINT nFlags, CPoint point) = 0;
};


//定义被观察者
class CTestWnd : public CWnd
{
public:
	CTestWnd();
	virtual ~CTestWnd();

	void Attach(CTestWndObserver* pObserver);  //订阅观察者

private:
	std::vector<CTestWndObserver*> m_pObservers;   //保存的观察者对象指针，可根据需要使用vector来保存一组，也可以只保存一个
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

