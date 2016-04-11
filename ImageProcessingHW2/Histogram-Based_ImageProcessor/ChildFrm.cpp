// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// ChildFrm.cpp : CChildFrame Ŭ������ ����
//

#include "stdafx.h"
#include "ImageProcessor.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "HistogramDoc.h"
#include "BMPDoc.h"

#include "MainFrm.h"


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChildFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CChildFrame::OnUpdateFilePrintPreview)
END_MESSAGE_MAP()

int CChildFrame::posX = 0;
int CChildFrame::posY = 0;

// CChildFrame ����/�Ҹ�

CChildFrame::CChildFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	//CDocument* pDoc = GetActiveDocument();
	//if (pDoc->IsKindOf(RUNTIME_CLASS(CHistogramDoc))) {
	//	CHistogramDoc* pBMPDoc = (CHistogramDoc*)pDoc;
	//	//cs.cx = ;
	//	//cs.cy = ;
	//}
	//else if (pDoc->IsKindOf(RUNTIME_CLASS(CBMPDoc))) {
	//	CBMPDoc* pBMPDoc = (CBMPDoc*)pDoc;
	//	cs.cx = pBMPDoc->m_bitmap->GetWidth();
	//	cs.cy = pBMPDoc->m_bitmap->GetHeight();
	//}


		//CBMPDoc* pBMPDoc = (CBMPDoc*)GetActiveDocument();
		//cs.cx = pBMPDoc->m_bitmap->GetWidth();
		//cs.cy = pBMPDoc->m_bitmap->GetHeight();

	//void CChildFrame::OnSize(UINT nType, int cx, int cy)
	//{
	//	CBMPDoc* pBMPDoc = (CBMPDoc*)GetActiveDocument();
	//	if (pBMPDoc) {
	//		cx = pBMPDoc->m_bitmap->GetWidth();
	//		cy = pBMPDoc->m_bitmap->GetHeight();
	//	}

	//	CMDIChildWndEx::OnSize(nType, cx, cy);

	//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//}


	//void CChildFrame::OnSizing(UINT fwSide, LPRECT pRect)
	//{
	//	CBMPDoc* pBMPDoc = (CBMPDoc*)GetActiveDocument();
	//	if (pBMPDoc) {
	//		pRect->left = 0;
	//		pRect->top = 0;
	//		pRect->right = pBMPDoc->m_bitmap->GetWidth();
	//		pRect->bottom = pBMPDoc->m_bitmap->GetHeight();
	//	}

	//	CMDIChildWndEx::OnSizing(fwSide, pRect);

	//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//}


	return TRUE;
}

// CChildFrame ����

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame �޽��� ó����

void CChildFrame::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CChildFrame::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // �μ� �̸� ���� ��带 �ݽ��ϴ�.
	}
}

void CChildFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}


void CChildFrame::ActivateFrame(int nCmdShow)
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
	//if (nCmdShow == -1) {
		rBar->ShowContextCategories(ID_IMAGEPROCESSING, TRUE);
		rBar->ActivateContextCategory(ID_IMAGEPROCESSING);
	//}
	//else {
	//	rBar->ShowContextCategories(ID_IMAGEPROCESSING, FALSE);
	//}

	// ���� �ݵ�� ȣ��
	rBar->RecalcLayout();
	rBar->RedrawWindow();

	SendMessage(WM_NCPAINT, 0, 0);

	CMDIChildWndEx::ActivateFrame(nCmdShow);
}
