
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"
#include <memory>

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	///The class for the game being played
	CGame mGame;
	/// An indicator for the first paint, for timing purposes
	bool mFirstPaint = true;
	///The last time the game was drawn
	long long mPreviousDrawTime;
	///Rate the timer is ticked
	double mFrequency; 
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

