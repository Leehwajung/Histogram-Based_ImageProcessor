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

// HistogramView.cpp : CHistogramView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessor.h"
#endif

#include "HistogramDoc.h"
#include "HistogramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHistogramView

IMPLEMENT_DYNCREATE(CHistogramView, CView)

BEGIN_MESSAGE_MAP(CHistogramView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHistogramView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CHistogramView ����/�Ҹ�

CHistogramView::CHistogramView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHistogramView::~CHistogramView()
{
}

BOOL CHistogramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}


// CHistogramView �׸���

void CHistogramView::OnDraw(CDC* pDC)
{
	CHistogramDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	int height = 256;
	int width = 256;

	int rwsize = (((width)+31) / 32 * 4); // ���� ���� �׻� 4����Ʈ�� ������� ��

	BITMAPINFO* BmInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));

	BmInfo->bmiHeader.biBitCount = 8;
	BmInfo->bmiHeader.biClrImportant = 256;
	BmInfo->bmiHeader.biClrUsed = 256;
	BmInfo->bmiHeader.biCompression = 0;
	BmInfo->bmiHeader.biHeight = height;
	BmInfo->bmiHeader.biPlanes = 1;
	BmInfo->bmiHeader.biSize = 40;
	BmInfo->bmiHeader.biSizeImage = rwsize*height;
	BmInfo->bmiHeader.biWidth = width;
	BmInfo->bmiHeader.biXPelsPerMeter = 0;
	BmInfo->bmiHeader.biYPelsPerMeter = 0;

	for (int i = 0; i<256; i++) { // Palette number is 256
		BmInfo->bmiColors[i].rgbRed = BmInfo->bmiColors[i].rgbGreen = BmInfo->bmiColors[i].rgbBlue = i;
		BmInfo->bmiColors[i].rgbReserved = 0;
	}
	SetDIBitsToDevice(pDC->GetSafeHdc(), 1, 0, 256, 256, 0, 0, 0, 256, pDoc->m_HistogramImage, BmInfo, DIB_RGB_COLORS);

	delete BmInfo;
}


// CHistogramView �μ�


void CHistogramView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHistogramView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CHistogramView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CHistogramView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CHistogramView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHistogramView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHistogramView ����

#ifdef _DEBUG
void CHistogramView::AssertValid() const
{
	CView::AssertValid();
}

void CHistogramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHistogramDoc* CHistogramView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHistogramDoc)));
	return (CHistogramDoc*)m_pDocument;
}
#endif //_DEBUG


// CHistogramView �޽��� ó����
