// BMPDoc.h : CBMPDoc Ŭ������ �������̽��Դϴ�.
//

#pragma once


// CBMPDoc �����Դϴ�.

class CBMPDoc : public CDocument
{
protected:	// serialization������ ��������ϴ�.
	CBMPDoc();
	DECLARE_DYNCREATE(CBMPDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);	// ���� ��/����� ���� �����ǵǾ����ϴ�.
#endif
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS
	virtual void OnFinalRelease();

// �����Դϴ�.
public:
	virtual ~CBMPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	
// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
