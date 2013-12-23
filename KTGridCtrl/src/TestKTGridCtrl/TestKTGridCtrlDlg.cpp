
// TestKTGridCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestKTGridCtrl.h"
#include "TestKTGridCtrlDlg.h"
#include "afxdialogex.h"


#include "KTGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

CWnd* CreateGridControl(CWnd* parent);

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestKTGridCtrlDlg dialog




CTestKTGridCtrlDlg::CTestKTGridCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestKTGridCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestKTGridCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestKTGridCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_WM_SIZE()
END_MESSAGE_MAP()


// CTestKTGridCtrlDlg message handlers

BOOL CTestKTGridCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


  CWnd* parent = GetDlgItem(IDC_STATIC_SHEET);

  m_view_data_grid.CreateControl(parent);

  m_view_data_grid.ShowWindow(SW_SHOW);

  m_view_data_grid.SetRowCount(10);
  m_view_data_grid.SetColumnCount(10);

  m_view_data_grid.SetFixedColumnCount(1);
  m_view_data_grid.SetFixedRowCount(1);
  m_view_data_grid.SetTextColor(1, 1, RGB(255, 0, 0));
  m_view_data_grid.SetBackgroundColor(1, 1, RGB(255, 255, 0));
  m_view_data_grid.SetCellValue(1, 1, _T("100"));

  m_view_data_grid.SetRowHeight(2, 50);

  for (int i = 0; i < 10; ++i) {
    TCHAR value[MAX_PATH + 1] = {0};
    _sntprintf(value, MAX_PATH, _T("%d"), i + 1);
    m_view_data_grid.SetCellValue(i, 0, value);
    m_view_data_grid.SetCellValue(0, i, value);
  }



  // set grid2

  m_view_data_grid2.CreateControl(parent);

  m_view_data_grid2.ShowWindow(SW_SHOW);

  m_view_data_grid2.SetRowCount(10);
  m_view_data_grid2.SetColumnCount(10);
  m_view_data_grid2.SetEditable(FALSE);

  m_view_data_grid2.SetFixedColumnCount(1);
  m_view_data_grid2.SetFixedRowCount(1);
  m_view_data_grid2.SetTextColor(1, 1, RGB(255, 0, 0));
  m_view_data_grid2.SetBackgroundColor(1, 1, RGB(255, 255, 0));
  m_view_data_grid2.SetCellValue(1, 1, _T("100"));
  m_view_data_grid2.SetCellValue(2, 1, _T("Can't editable"));

  m_view_data_grid2.SetRowHeight(2, 50);

  for (int i = 0; i < 10; ++i) {
    TCHAR value[MAX_PATH + 1] = {0};
    _sntprintf(value, MAX_PATH, _T("%d"), i + 1);
    m_view_data_grid2.SetCellValue(i, 0, value);
    m_view_data_grid2.SetCellValue(0, i, value);
  }

  LayoutGUI();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestKTGridCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestKTGridCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestKTGridCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestKTGridCtrlDlg::OnSize(UINT nType, int cx, int cy)
{
  CDialogEx::OnSize(nType, cx, cy);

  LayoutGUI();

}


void  CTestKTGridCtrlDlg::LayoutGUI()
{
  CWnd* parent = GetDlgItem(IDC_STATIC_SHEET);

  CRect rc;

  GetClientRect(&rc);

  int space = 5;
  rc.left += space;
  rc.top += space;
  rc.right -= space;
  rc.bottom -= space;

  if (parent) parent->MoveWindow(&rc);



  if (parent) {
    CRect rect;
    parent->GetWindowRect(&rect);
    ScreenToClient(&rect);

    CRect rect1 = rect;
    CRect rect2 = rect;

    rect1.right -= (rect.Width() / 2);
    rect2.left += (rect.Width() / 2);

    m_view_data_grid.MoveWindow(&rect1);
    m_view_data_grid2.MoveWindow(&rect2);
  }

  Invalidate(TRUE);
}