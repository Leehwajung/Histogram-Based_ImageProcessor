// BMPFrm.cpp : CBMPFrame Ŭ������ ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessor.h"

#include "BMPFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "BMPView.h"
#include "BMPDoc.h"

#include "MainFrm.h"


// CBMPFrame

IMPLEMENT_DYNCREATE(CBMPFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CBMPFrame, CMDIChildWndEx)
	ON_WM_CHILDACTIVATE()
	ON_WM_NCACTIVATE()
	ON_COMMAND(ID_IP_HE, &CBMPFrame::OnIpHistogramEqualization)
	ON_COMMAND(ID_IP_BCS, &CBMPFrame::OnIpBasicContrastStretching)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBMPFrame, CMDIChildWndEx)
END_DISPATCH_MAP()

// ����: IID_IBMPFrame�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {49124138-EE54-4C37-9CB5-71965CF97CC5}
static const IID IID_IBMPFrame =
{ 0x49124138, 0xEE54, 0x4C37,{ 0x9C, 0xB5, 0x71, 0x96, 0x5C, 0xF9, 0x7C, 0xC5 } };

BEGIN_INTERFACE_MAP(CBMPFrame, CMDIChildWndEx)
	INTERFACE_PART(CBMPFrame, IID_IBMPFrame, Dispatch)
END_INTERFACE_MAP()


// CBMPFrame ����/�Ҹ��Դϴ�.

CBMPFrame::CBMPFrame()
{

	EnableAutomation();
}

CBMPFrame::~CBMPFrame()
{
}


BOOL CBMPFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	if (!CMDIChildWndEx::PreCreateWindow(cs))
		return FALSE;

	cs.cx = 512;
	cs.cy = 512;

	return TRUE;
}

void CBMPFrame::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�.  �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CMDIChildWndEx::OnFinalRelease();
}


//CBMPView* CBMPFrame::GetActiveView()
//{
//	return (CBMPView*)CFrameWnd::GetActiveView();
//}

CBMPDoc* CBMPFrame::GetActiveDocument()
{
	return (CBMPDoc*)CFrameWnd::GetActiveDocument();
}


// CBMPFrame �����Դϴ�.

#ifdef _DEBUG
void CBMPFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CBMPFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG


// CBMPFrame �޽��� ó�����Դϴ�.

void CBMPFrame::ActivateFrame(int nCmdShow)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CBMPDoc *pDoc = GetActiveDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect winRect, cliRect;
	GetWindowRect(&winRect);
	GetClientRect(&cliRect);

	Bitmap *pBitmap = pDoc->m_bitmap;
	if (pBitmap) {
		int cx = pDoc->m_bitmap->GetWidth() + winRect.Width() - cliRect.Width() + 4;
		int cy = pDoc->m_bitmap->GetHeight() + winRect.Height() - cliRect.Height() + 4;
		SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_SHOWWINDOW);
	}

	CMDIChildWndEx::ActivateFrame(nCmdShow);
}

void CBMPFrame::OnChildActivate()
{
	CMDIChildWndEx::OnChildActivate();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// Activate ribbon context category: ����ó��
	CMFCRibbonBar *pRibbon = ((CMainFrame*)GetTopLevelFrame())->GetRibbonBar();
	pRibbon->ShowContextCategories(ID_IMAGEPROCESSING, TRUE);
	pRibbon->ActivateContextCategory(ID_IMAGEPROCESSING);

	pRibbon->RecalcLayout();
	pRibbon->RedrawWindow();
}

BOOL CBMPFrame::OnNcActivate(BOOL bActive)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// Inactivate ribbon context category: ����ó��
	CMFCRibbonBar *pRibbon = ((CMainFrame*)GetTopLevelFrame())->GetRibbonBar();
	pRibbon->ShowContextCategories(ID_IMAGEPROCESSING, FALSE);

	pRibbon->RecalcLayout();
	pRibbon->RedrawWindow();

	return CMDIChildWndEx::OnNcActivate(bActive);
}

void CBMPFrame::OnIpHistogramEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	// ���� CBMPDoc�� ������
	CBMPDoc *pSrcDoc = GetActiveDocument();
	ASSERT_VALID(pSrcDoc);
	if (!pSrcDoc)
		return;

	// �ű� BMP ���� (CBMPDoc) ����
	CDocTemplate *pTml = pSrcDoc->GetDocTemplate();
	pTml->OpenDocumentFile(NULL);

	// ���� CBMPDoc���κ��� ����
	CBMPFrame *pDstFrm = (CBMPFrame*)((CMainFrame*)AfxGetMainWnd())->GetActiveFrame();
	CBMPView *pDstView = (CBMPView*)pDstFrm->GetActiveView();
	CBMPDoc *pDstDoc = pDstView->GetDocument();
	pDstDoc->copyFrom(pSrcDoc);

	// Histogram Equalization
	pDstDoc->HistogramEqualization();

	// ���� ����
	CString newTitle("equalized_");
	newTitle.Append(pSrcDoc->GetTitle());
	pDstDoc->SetTitle(newTitle);

	// ���� �°� �ٽ� �׸���
	pDstFrm->ActivateFrame();
	pDstView->Invalidate();
}


void CBMPFrame::OnIpBasicContrastStretching()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

}
