#pragma once


// CBMPView ���Դϴ�.

class CBMPView : public CView
{
	DECLARE_DYNCREATE(CBMPView)

protected:
	CBMPView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CBMPView();

public:
	virtual void OnFinalRelease();
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


