#pragma once


// CBaseGridCtrl dialog
#include "resource.h"

#include "GridCtrl/GridCtrl.h"

class CBaseGridCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseGridCtrl)

public:
	CBaseGridCtrl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBaseGridCtrl();

// Dialog Data
	enum { IDD = IDD_DIALOG_BASE_GRID };

public:
  CGridCtrl m_view_data_grid;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnSize(UINT nType, int cx, int cy);
  virtual BOOL OnInitDialog();
};
