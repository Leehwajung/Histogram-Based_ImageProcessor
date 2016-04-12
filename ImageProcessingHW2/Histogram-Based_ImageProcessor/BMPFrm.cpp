// BMPFrm.cpp : CBMPFrame Ŭ������ ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessor.h"

#include "BMPFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "BMPDoc.h"

#include "MainFrm.h"


// CBMPFrame

IMPLEMENT_DYNCREATE(CBMPFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CBMPFrame, CMDIChildWndEx)
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

	CDocument* pDoc = GetActiveDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	CRect winRect, cliRect;
	GetWindowRect(&winRect);
	GetClientRect(&cliRect);

	CSize sizeImg;


	if (pDoc->IsKindOf(RUNTIME_CLASS(CBMPDoc))) {
		sizeImg.cx = ((CBMPDoc*)pDoc)->m_bitmap->GetWidth();
		sizeImg.cy = ((CBMPDoc*)pDoc)->m_bitmap->GetHeight();
		int cx = sizeImg.cx + winRect.Width() - cliRect.Width() + 4;
		int cy = sizeImg.cy + winRect.Height() - cliRect.Height() + 4;


		SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_SHOWWINDOW);
	}

	CMFCRibbonBar* rBar = ((CMainFrame*)GetTopLevelFrame())->GetRibbonBar();
	rBar->ShowContextCategories(ID_IMAGEPROCESSING, TRUE);
	rBar->ActivateContextCategory(ID_IMAGEPROCESSING);

	// ���� �ݵ�� ȣ��
	rBar->RecalcLayout();
	rBar->RedrawWindow();

	SendMessage(WM_NCPAINT, 0, 0);

	CMDIChildWndEx::ActivateFrame(nCmdShow);
}
