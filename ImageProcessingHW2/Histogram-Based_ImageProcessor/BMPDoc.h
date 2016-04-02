#pragma once

// CBMPDoc �����Դϴ�.

class CBMPDoc : public CDocument
{
	DECLARE_DYNCREATE(CBMPDoc)

public:
	CBMPDoc();
	virtual ~CBMPDoc();

	virtual void OnFinalRelease();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // ���� ��/����� ���� �����ǵǾ����ϴ�.
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
