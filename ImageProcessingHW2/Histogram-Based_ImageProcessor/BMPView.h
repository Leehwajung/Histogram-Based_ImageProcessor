// BMPView.h : CBMPView Ŭ������ �������̽��Դϴ�.
//

#pragma once


// CBMPView ���Դϴ�.

class CBMPView : public CView
{
protected: // serialization������ ��������ϴ�.
	CBMPView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	DECLARE_DYNCREATE(CBMPView)

// Ư���Դϴ�.
public:
	CBMPDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnFinalRelease();
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CBMPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

#ifndef _DEBUG  // BMPView.cpp�� ����� ����
inline CBMPDoc* CBMPView::GetDocument() const
   { return reinterpret_cast<CBMPDoc*>(m_pDocument); }
#endif
