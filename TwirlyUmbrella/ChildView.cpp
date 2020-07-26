
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

// Redrawn every 60 miliseconds
const int TimeBetweenFrames = 60;

// CChildView

CChildView::CChildView()
{
	mPreviousDrawTime = 0;
	mFrequency = 0;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
//	ON_WM_XBUTTONDOWN()
ON_WM_KEYDOWN()
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
	//The first time The program is painted, a timer is started
	if (mFirstPaint == true)
	{
		SetTimer(1, TimeBetweenFrames, nullptr);
		LARGE_INTEGER time;
		LARGE_INTEGER frequency;

		//Find the current ticks and the tick frequency
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&frequency);

		//Set the first draw time, and the frequency
		mPreviousDrawTime = time.QuadPart;
		mFrequency = static_cast<double>(frequency.QuadPart);

		mFirstPaint = false;
	}
	//Get the current tick
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	//Elapsed time = (time - oldtime) / tickrate
	double timeElapsed = static_cast<double>((time.QuadPart - mPreviousDrawTime) / mFrequency);
	mPreviousDrawTime = time.QuadPart;

	mGame.Update(timeElapsed);

	CPaintDC paintdc(this); // device context for painting
	//To reduce flickering
	CDoubleBufferDC dc(&paintdc); // device context for painting
	Gdiplus::Graphics graphics(dc.m_hDC);

	//Get the size of the client to scale the graphics
	CRect clientSize;

	GetClientRect(&clientSize);

	mGame.OnDraw(&graphics, clientSize.Width(), clientSize.Height());
}


/** Stops the background from being erased to reduce flickering issues
* \param pDc The pdc object
* \returns false always
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return false;
}

/** When a button is pushed
* \param nChar The button pushes
* \param nRepCnt The number of times pushed
* \param nFlags Additional flags
*/
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SPACE) 
	{
		mGame.jump();
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

/**
* Redraw after a period of time
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate(); //Redraws the game
	CWnd::OnTimer(nIDEvent);
}