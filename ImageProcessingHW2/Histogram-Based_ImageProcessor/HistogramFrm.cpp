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

// HistogramFrm.cpp : CHistogramFrame Ŭ������ ����
//

#include "stdafx.h"
#include "ImageProcessor.h"

#include "HistogramFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MainFrm.h"

#include "HistogramView.h"
#include "HistogramDoc.h"


// CHistogramFrame

IMPLEMENT_DYNCREATE(CHistogramFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CHistogramFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CHistogramFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CHistogramFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHistogramFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CHistogramFrame::OnUpdateFilePrintPreview)
END_MESSAGE_MAP()


// CHistogramFrame ����/�Ҹ�

CHistogramFrame::CHistogramFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CHistogramFrame::~CHistogramFrame()
{
}


BOOL CHistogramFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	cs.style &= ~WS_MAXIMIZEBOX;
	cs.cx = 256;
	cs.cy = 512;

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

	//void CHistogramFrame::OnSize(UINT nType, int cx, int cy)
	//{
	//	CBMPDoc* pBMPDoc = (CBMPDoc*)GetActiveDocument();
	//	if (pBMPDoc) {
	//		cx = pBMPDoc->m_bitmap->GetWidth();
	//		cy = pBMPDoc->m_bitmap->GetHeight();
	//	}

	//	CMDIChildWndEx::OnSize(nType, cx, cy);

	//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//}


	//void CHistogramFrame::OnSizing(UINT fwSide, LPRECT pRect)
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


CHistogramView* CHistogramFrame::GetActiveView()
{
	return (CHistogramView*)CFrameWnd::GetActiveView();
}

CHistogramDoc* CHistogramFrame::GetActiveDocument()
{
	return (CHistogramDoc*)CFrameWnd::GetActiveDocument();
}


// CHistogramFrame ����

#ifdef _DEBUG
void CHistogramFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CHistogramFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CHistogramFrame �޽��� ó����

void CHistogramFrame::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CHistogramFrame::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // �μ� �̸� ���� ��带 �ݽ��ϴ�.
	}
}

void CHistogramFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}

