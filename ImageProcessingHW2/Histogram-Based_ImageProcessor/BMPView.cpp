// BMPView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "BMPView.h"


// CBMPView

IMPLEMENT_DYNCREATE(CBMPView, CView)

CBMPView::CBMPView()
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();
}

CBMPView::~CBMPView()
{
}

void CBMPView::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�.  �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CView::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CBMPView, CView)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBMPView, CView)
END_DISPATCH_MAP()

// ����: IID_IBMPView�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {615CB34A-1700-4769-91F1-130F47067028}
static const IID IID_IBMPView =
{ 0x615CB34A, 0x1700, 0x4769, { 0x91, 0xF1, 0x13, 0xF, 0x47, 0x6, 0x70, 0x28 } };

BEGIN_INTERFACE_MAP(CBMPView, CView)
	INTERFACE_PART(CBMPView, IID_IBMPView, Dispatch)
END_INTERFACE_MAP()


// CBMPView �׸����Դϴ�.

void CBMPView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CBMPView �����Դϴ�.

#ifdef _DEBUG
void CBMPView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CBMPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBMPView �޽��� ó�����Դϴ�.
