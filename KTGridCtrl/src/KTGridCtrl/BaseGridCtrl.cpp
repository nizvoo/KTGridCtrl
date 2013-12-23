// BaseGridCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "BaseGridCtrl.h"
#include "afxdialogex.h"


// CBaseGridCtrl dialog

IMPLEMENT_DYNAMIC(CBaseGridCtrl, CDialogEx)

CBaseGridCtrl::CBaseGridCtrl(CWnd* pParent /*=NULL*/)
  : CDialogEx(CBaseGridCtrl::IDD, pParent)
{

}

CBaseGridCtrl::~CBaseGridCtrl()
{
}

void CBaseGridCtrl::DoDataExchange(CDataExchange* pDX)
{
  DDX_Control(pDX, IDC_VIEW_DATA_GRID, m_view_data_grid);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBaseGridCtrl, CDialogEx)
  ON_WM_SIZE()
END_MESSAGE_MAP()


// CBaseGridCtrl message handlers


void CBaseGridCtrl::OnSize(UINT nType, int cx, int cy)
{
  CDialogEx::OnSize(nType, cx, cy);

  CRect rect;
  GetClientRect(&rect);
  //ScreenToClient(&rect);
  int space = 0;
  rect.left -= space;
  rect.right -= space;
  rect.top -= space;
  rect.bottom -= space;

  if (m_view_data_grid.GetSafeHwnd())
    m_view_data_grid.MoveWindow(rect);
}


BOOL CBaseGridCtrl::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  /*
  m_view_data_grid.SetColumnCount(4);
  m_view_data_grid.SetRowCount(16);
  m_view_data_grid.SetFixedRowCount(1);
  m_view_data_grid.SetFixedColumnCount(1);

  m_view_data_grid.SetEditable(false);
  */
  m_view_data_grid.ShowWindow(SW_SHOW);
  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
