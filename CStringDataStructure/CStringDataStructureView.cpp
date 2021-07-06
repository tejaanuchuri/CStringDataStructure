
// CStringDataStructureView.cpp : implementation of the CCStringDataStructureView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CStringDataStructure.h"
#endif

#include "CStringDataStructureDoc.h"
#include "CStringDataStructureView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCStringDataStructureView

IMPLEMENT_DYNCREATE(CCStringDataStructureView, CView)

BEGIN_MESSAGE_MAP(CCStringDataStructureView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCStringDataStructureView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCStringDataStructureView construction/destruction

CCStringDataStructureView::CCStringDataStructureView() noexcept
{
	// TODO: add construction code here

}

CCStringDataStructureView::~CCStringDataStructureView()
{
}

BOOL CCStringDataStructureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCStringDataStructureView drawing

void CCStringDataStructureView::OnDraw(CDC* /*pDC*/)
{
	CCStringDataStructureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCStringDataStructureView printing


void CCStringDataStructureView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCStringDataStructureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCStringDataStructureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCStringDataStructureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCStringDataStructureView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCStringDataStructureView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCStringDataStructureView diagnostics

#ifdef _DEBUG
void CCStringDataStructureView::AssertValid() const
{
	CView::AssertValid();
}

void CCStringDataStructureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCStringDataStructureDoc* CCStringDataStructureView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCStringDataStructureDoc)));
	return (CCStringDataStructureDoc*)m_pDocument;
}
#endif //_DEBUG


// CCStringDataStructureView message handlers
