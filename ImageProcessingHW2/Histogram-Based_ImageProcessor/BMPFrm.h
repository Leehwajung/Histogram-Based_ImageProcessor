// BMPFrm.h : CBMPFrame Ŭ������ �������̽��Դϴ�.
//

#pragma once


// CBMPFrame

class CBMPFrame : public CMDIChildWndEx
{
	DECLARE_DYNAMIC(CBMPFrame)
public:
	CBMPFrame();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
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
};
