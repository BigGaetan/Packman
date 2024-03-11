
// PackmanView.h : interface de la classe CPackmanView
//

#pragma once


class CPackmanView : public CView
{
protected: // création à partir de la sérialisation uniquement
	CPackmanView() noexcept;
	DECLARE_DYNCREATE(CPackmanView)

// Attributs
public:
	CPackmanDoc* GetDocument() const;

// Opérations
public:

// Substitutions
public:
	virtual void OnDraw(CDC* pDC);  // substitué pour dessiner cette vue
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implémentation
public:
	virtual ~CPackmanView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // version Debug dans PackmanView.cpp
inline CPackmanDoc* CPackmanView::GetDocument() const
   { return reinterpret_cast<CPackmanDoc*>(m_pDocument); }
#endif

