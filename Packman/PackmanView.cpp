
// PackmanView.cpp : implémentation de la classe CPackmanView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "Packman.h"
#endif

#include "PackmanDoc.h"
#include "PackmanView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPackmanView

IMPLEMENT_DYNCREATE(CPackmanView, CView)

BEGIN_MESSAGE_MAP(CPackmanView, CView)
	// Commandes d'impression standard
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPackmanView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// construction/destruction de CPackmanView

CPackmanView::CPackmanView() noexcept
{
	// TODO: ajoutez ici du code de construction

}

CPackmanView::~CPackmanView()
{
}

BOOL CPackmanView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// dessin de CPackmanView

void CPackmanView::OnDraw(CDC* /*pDC*/)
{
	CPackmanDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ajoutez ici le code de dessin pour les données natives
}


// impression de CPackmanView


void CPackmanView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPackmanView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// préparation par défaut
	return DoPreparePrinting(pInfo);
}

void CPackmanView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez une initialisation supplémentaire avant l'impression
}

void CPackmanView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez un nettoyage après l'impression
}

void CPackmanView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPackmanView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// diagnostics de CPackmanView

#ifdef _DEBUG
void CPackmanView::AssertValid() const
{
	CView::AssertValid();
}

void CPackmanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPackmanDoc* CPackmanView::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPackmanDoc)));
	return (CPackmanDoc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages de CPackmanView
