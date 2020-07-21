
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "TwirlyUmbrella.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC paintdc(this); // device context for painting
	//To reduce flickering
	CDoubleBufferDC dc(&paintdc); // device context for painting
	Gdiplus::Graphics graphics(dc.m_hDC);
	mGame.OnDraw(&graphics);
}


/** Stops the background from being erased to reduce flickering issues
* \param pDc The pdc object
* \returns false always
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{

	return false;
}
