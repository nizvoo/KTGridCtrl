
// TestKTGridCtrlDlg.h : header file
//

#pragma once

#include "KTGrid.h"

// CTestKTGridCtrlDlg dialog
class CTestKTGridCtrlDlg : public CDialogEx
{
// Construction
public:
	CTestKTGridCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTKTGRIDCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnSize(UINT nType, int cx, int cy);

  void LayoutGUI();

  KTGrid m_view_data_grid;
  KTGrid m_view_data_grid2;
};
