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

#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CBMPView

IMPLEMENT_DYNCREATE(CBMPView, CView)

BEGIN_MESSAGE_MAP(CBMPView, CView)
	ON_WM_ACTIVATE()
	ON_COMMAND(ID_IMAGEPROCESSING, &CBMPView::OnImageprocessing)
	ON_UPDATE_COMMAND_UI(ID_IMAGEPROCESSING, &CBMPView::OnUpdateImageprocessing)
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

void CBMPView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	//CBMPDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	//CRect frameRect;
	//CRect viewRect;

	//GetFrame()->GetWindowRect(&frameRect);

	//GetFrame()->GetClientRect(&viewRect);

	//GetFrame()->MoveWindow(GetFrame()->posX, GetFrame()->posY, pDoc->m_bitmap->GetWidth() + frameRect.Width() - viewRect.Width(), pDoc->m_bitmap->GetHeight() + frameRect.Height() - viewRect.Height());
	//GetFrame()->posX += 26;
	//GetFrame()->posY += 26;
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
	graphicsCanvas.Clear(Color::Azure);				// ĵ���� ���� ����
	/*************************************************************************/
	//graphicsCanvas.SetSmoothingMode(SmoothingModeHighQuality);	// Antialising

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	if (pDoc->m_bitmap) {
		CRect rect(0,0, pDoc->m_bitmap->GetWidth(), pDoc->m_bitmap->GetHeight());
		//CRgn abv;
		//abv.CreateRectRgnIndirect(&rect);

		//GetParentFrame()->MoveWindow(&rect);
		//GetParentFrame()->SetWindowRgn(abv, true);
		//SetWindowRgn(abv, true);
		
		//rect.left = 0;
		//rect.top = 0;
		//rect.right = pDoc->m_bitmap->GetWidth();
		//rect.bottom = pDoc->m_bitmap->GetHeight();
		//CRect winRect;
		//CRect cliRect;
		//GetParentFrame()->GetWindowRect(&winRect);
		//GetParentFrame()->GetClientRect(&cliRect);

		//GetParentFrame()->MoveWindow(winRect.left, winRect.top, pDoc->m_bitmap->GetWidth() + winRect.Width() - cliRect.Width(), pDoc->m_bitmap->GetHeight() + winRect.Height() - cliRect.Height());

		graphicsCanvas.DrawImage(pDoc->m_bitmap, 0, 0, pDoc->m_bitmap->GetWidth(), pDoc->m_bitmap->GetHeight());
	}
		
	//CRect rect2;
	//rect.top = 0;
	//rect.left = 0;
	//rect.bottom = pDoc->m_bitmap->GetHeight();
	//rect.right = pDoc->m_bitmap->GetWidth();
	//GetParentFrame()->MoveWindow(&rect2);
	

	//CRect rDialer;
	//GetWindowRect(&rDialer); /* r comes out in screen coordinates */
	//ScreenToClient(&rDialer); // MoveWindow needs coordinates in parent window 
	//rDialer.right = rDialer.left + pDoc->m_bitmap->GetWidth();
	//rDialer.bottom = rDialer.top + pDoc->m_bitmap->GetHeight();
	////MoveWindow(&rDialer);

	//AdjustWindowRect(&rDialer, WS_OVERLAPPEDWINDOW, false);

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

CBMPDoc* CBMPView::GetDocument() const	// ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBMPDoc)));
	return (CBMPDoc*)m_pDocument;
}

CChildFrame* CBMPView::GetFrame() const	// ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(CView::GetParentFrame()->IsKindOf(RUNTIME_CLASS(CChildFrame)));
	return (CChildFrame*)CView::GetParentFrame();
}
#endif //_DEBUG


// CBMPView �޽��� ó�����Դϴ�.





void CBMPView::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CView::OnActivate(nState, pWndOther, bMinimized);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	//CMFCRibbonBar* rBar = ((CMainFrame*)GetTopLevelFrame())->GetRibbonBar();

	//	rBar->ShowContextCategories(ID_IMAGEPROCESSING, FALSE);


	//// ���� �ݵ�� ȣ��
	//rBar->RecalcLayout();
	//rBar->RedrawWindow();

	//SendMessage(WM_NCPAINT, 0, 0);
}


void CBMPView::OnImageprocessing()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CBMPView::OnUpdateImageprocessing(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.

	pCmdUI->Enable();
}
