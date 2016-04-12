// BMPFrm.h : CBMPFrame Ŭ������ �������̽��Դϴ�.
//

#pragma once

// CBMPFrame

#include "BMPView.h"
#include "BMPDoc.h"

class CBMPFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CBMPFrame)
public:
	CBMPFrame();

// Ư���Դϴ�.
public:
	virtual CBMPView* GetActiveView();
	virtual CBMPDoc* GetActiveDocument();

// �۾��Դϴ�.
public:

// �������Դϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnFinalRelease();

// �����Դϴ�.
public:
	virtual ~CBMPFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	virtual void ActivateFrame(int nCmdShow = -1);
};
