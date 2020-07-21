
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
	//The class for the game being played
	CGame mGame;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

