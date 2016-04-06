// BMPView.cpp : CBMPView Ŭ������ ���� �����Դϴ�.
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessor.h"
#endif

#include "BMPDoc.h"
#include "BMPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBMPView

IMPLEMENT_DYNCREATE(CBMPView, CView)

BEGIN_MESSAGE_MAP(CBMPView, CView)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBMPView, CView)
END_DISPATCH_MAP()

// ����: IID_IBMPView�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {615CB34A-1700-4769-91F1-130F47067028}
static const IID IID_IBMPView =
{ 0x615CB34A, 0x1700, 0x4769,{ 0x91, 0xF1, 0x13, 0xF, 0x47, 0x6, 0x70, 0x28 } };

BEGIN_INTERFACE_MAP(CBMPView, CView)
	INTERFACE_PART(CBMPView, IID_IBMPView, Dispatch)
END_INTERFACE_MAP()


// CBMPView ����/�Ҹ��Դϴ�.

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


// CBMPView �׸����Դϴ�.

void CBMPView::OnDraw(CDC* pDC)
{
	CBMPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.

	/* ��� ��� */
	Graphics graphicsDC(*pDC);	// gdi+ �׸��⸦ ���� ��ü https://msdn.microsoft.com/en-us/library/windows/desktop/ms534453(v=vs.85).aspx

	/****************************** ���� ���۸� ******************************/
	CRect rect;
	GetClientRect(rect);
	Bitmap bmpCanvas(rect.right, rect.bottom);		// ĵ���� ��Ʈ�� ����
	Graphics graphicsCanvas(&bmpCanvas);			// ĵ���� �׷��Ƚ� ����
	graphicsCanvas.Clear(Color::White);				// ĵ���� ���� ����
	/*************************************************************************/
	//graphicsCanvas.SetSmoothingMode(SmoothingModeHighQuality);	// Antialising

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	if (pDoc->m_bitmap) {
		CRect rect(0,0, pDoc->m_bitmap->GetWidth(), pDoc->m_bitmap->GetHeight());
		CRgn abv;
		abv.CreateRectRgnIndirect(&rect);

		//GetParentFrame()->MoveWindow(&rect);
		//GetParentFrame()->SetWindowRgn(abv, true);
		//SetWindowRgn(abv, true);
		
		//rect.left = 0;
		//rect.top = 0;
		//rect.right = pDoc->m_bitmap->GetWidth();
		//rect.bottom = pDoc->m_bitmap->GetHeight();
		graphicsCanvas.DrawImage(pDoc->m_bitmap, 0, 0);
	}
		

	/**************************************** ���� ���۸� ****************************************/
	graphicsDC.DrawImage(&bmpCanvas, rect.left, rect.top, rect.right, rect.bottom);	// ĵ���� �׸���
	/*********************************************************************************************/
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

CBMPDoc* CBMPView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBMPDoc)));
	return (CBMPDoc*)m_pDocument;
}
#endif //_DEBUG


// CBMPView �޽��� ó�����Դϴ�.
