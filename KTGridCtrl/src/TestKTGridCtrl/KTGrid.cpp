/*
 * This utility must use MFC extension dynamic link library
 * It is interface for grid control c++ language
 * 2013 @ KT corp.
 * 2021 @ Flexus3D INC.
 * zhangyong.ni@gmail.com
 * alexander@flexus3d.com
 */

#include "stdafx.h"

#include "KTGrid.h"


static HMODULE grid_ctrl_inst = NULL;

typedef CWnd* (__stdcall * TKTGridCreateControl)(CWnd*);
typedef CWnd* (__stdcall * TKTGridDeleteControl)(CWnd*);
typedef void (__stdcall * TKTGridSetCellValue)(CWnd*, int, int, const TCHAR*);
typedef void (__stdcall * TKTGridSetRowCount)(CWnd*, int);
typedef void (__stdcall * TKTGridSetColumnCount)(CWnd*, int);

typedef void (__stdcall * TKTGridSetRowHeight)(CWnd*, int, int);
typedef void (__stdcall * TKTGridSetColumnWidth)(CWnd*, int, int);
typedef int (__stdcall * TKTGridGetColumnCount)(CWnd*);
typedef int (__stdcall * TKTGridGetRowCount)(CWnd*);
typedef void (__stdcall * TKTGridSetFixedColumnCount)(CWnd*, int);
typedef void (__stdcall * TKTGridSetFixedRowCount)(CWnd*, int);
typedef void (__stdcall * TKTGridSetEditable)(CWnd*, BOOL);
typedef BOOL (__stdcall * TKTGridIsEditable)(CWnd* grid);
typedef void (__stdcall * TKTGridSetBackgroundColor)(CWnd*, int, int, COLORREF);
typedef void (__stdcall * TKTGridSetTextColor)(CWnd*, int, int, COLORREF);

static TKTGridCreateControl MyKTGridCreateControl = NULL;
static TKTGridDeleteControl MyKTGridDeleteControl = NULL;
static TKTGridSetCellValue MyKTGridSetCellValue = NULL;
static TKTGridSetRowCount MyKTGridSetRowCount = NULL;
static TKTGridSetColumnCount MyKTGridSetColumnCount = NULL;
static TKTGridSetRowHeight MyKTGridSetRowHeight = NULL;

static TKTGridSetColumnWidth MyKTGridSetColumnWidth = NULL;
static TKTGridGetColumnCount MyKTGridGetColumnCount = NULL;
static TKTGridGetRowCount MyKTGridGetRowCount = NULL;
static TKTGridSetFixedColumnCount MyKTGridSetFixedColumnCount = NULL;
static TKTGridSetFixedRowCount MyKTGridSetFixedRowCount = NULL;

static TKTGridSetEditable MyKTGridSetEditable = NULL;
static TKTGridIsEditable MyKTGridIsEditable = NULL;
static TKTGridSetBackgroundColor MyKTGridSetBackgroundColor = NULL;
static TKTGridSetTextColor MyKTGridSetTextColor = NULL;

CWnd*  KTGridCreateControl(CWnd* parent)
{
  CWnd* control = NULL;
  if (MyKTGridCreateControl) {
    control = MyKTGridCreateControl(parent);
  }

  return control;
}

static BOOL LoadKTGridCtrlDll(const TCHAR* filename)
{
  grid_ctrl_inst = LoadLibrary(filename);

  if (!grid_ctrl_inst) return FALSE;

  MyKTGridCreateControl = (TKTGridCreateControl)GetProcAddress(grid_ctrl_inst, "ESGridCreateControl");
  MyKTGridDeleteControl = (TKTGridDeleteControl)GetProcAddress(grid_ctrl_inst, "ESGridDeleteControl");
  MyKTGridSetRowCount = (TKTGridSetRowCount)GetProcAddress(grid_ctrl_inst, "ESGridSetRowCount");
  MyKTGridSetColumnCount = (TKTGridSetColumnCount)GetProcAddress(grid_ctrl_inst, "ESGridSetColumnCount");
  MyKTGridSetCellValue = (TKTGridSetCellValue)GetProcAddress(grid_ctrl_inst, "ESGridSetCellValue");
  MyKTGridSetRowHeight = (TKTGridSetRowHeight)GetProcAddress(grid_ctrl_inst, "ESGridSetRowHeight");

  MyKTGridSetColumnWidth = (TKTGridSetColumnWidth)GetProcAddress(grid_ctrl_inst, "ESGridSetColumnWidth");
  MyKTGridGetColumnCount = (TKTGridGetColumnCount)GetProcAddress(grid_ctrl_inst, "ESGridGetColumnCount");
  MyKTGridGetRowCount = (TKTGridGetRowCount)GetProcAddress(grid_ctrl_inst, "ESGridGetRowCount");
  MyKTGridSetFixedColumnCount = (TKTGridSetFixedColumnCount)GetProcAddress(grid_ctrl_inst, "ESGridSetFixedColumnCount");
  MyKTGridSetFixedRowCount = (TKTGridSetFixedRowCount)GetProcAddress(grid_ctrl_inst, "ESGridSetFixedRowCount");

  MyKTGridSetEditable = (TKTGridSetEditable)GetProcAddress(grid_ctrl_inst, "ESGridSetEditable");
  MyKTGridIsEditable = (TKTGridIsEditable)GetProcAddress(grid_ctrl_inst, "ESGridIsEditable");
  MyKTGridSetBackgroundColor = (TKTGridSetBackgroundColor)GetProcAddress(grid_ctrl_inst, "ESGridSetBackgroundColor");
  MyKTGridSetTextColor = (TKTGridSetTextColor)GetProcAddress(grid_ctrl_inst, "ESGridSetTextColor");

  return TRUE;
}

static BOOL FreeKTGridCtrlDll()
{
  if (grid_ctrl_inst) FreeLibrary(grid_ctrl_inst);
  grid_ctrl_inst = NULL;

  return TRUE;
}


BOOL InitKTGrid(const TCHAR* path)
{
  TCHAR filename[MAX_PATH + 1] = {0};
  _sntprintf(filename, MAX_PATH, _T("%s\\ESGridCtrl.dll"), path);
  return LoadKTGridCtrlDll(filename);
}


void UnInitKTGrid()
{
  FreeKTGridCtrlDll();
}

KTGrid::KTGrid():
  m_base_grid(NULL)
{
}

KTGrid::~KTGrid()
{
  if (m_base_grid && MyKTGridDeleteControl) {
    MyKTGridDeleteControl(m_base_grid);
    m_base_grid = NULL;
  }
}


BOOL KTGrid::CreateControl(CWnd* parent)
{
  if (MyKTGridCreateControl) {
    m_base_grid = MyKTGridCreateControl(parent);
  }
  return m_base_grid != NULL;
}

void KTGrid::SetRowCount(int count)
{
  if (m_base_grid && MyKTGridSetRowCount)
    MyKTGridSetRowCount(m_base_grid, count);
}

void KTGrid::SetColumnCount(int count)
{
  if (m_base_grid && MyKTGridSetColumnCount)
    MyKTGridSetColumnCount(m_base_grid, count);
}

int KTGrid::GetRowCount()
{
  int count = 0;
  if (m_base_grid && MyKTGridGetRowCount)
    count = MyKTGridGetRowCount(m_base_grid);
  return count;
}

int KTGrid::GetColumnCount()
{
  int count = 0;
  if (m_base_grid && MyKTGridGetColumnCount)
    count = MyKTGridGetColumnCount(m_base_grid);
  return count;
}

void KTGrid::SetFixedRowCount(int count)
{
  if (m_base_grid && MyKTGridSetFixedRowCount)
    MyKTGridSetFixedRowCount(m_base_grid, count);
}

void KTGrid::SetFixedColumnCount(int count)
{
  if (m_base_grid && MyKTGridSetFixedColumnCount)
    MyKTGridSetFixedColumnCount(m_base_grid, count);
}

void KTGrid::SetRowHeight(int row, int height)
{
  if (m_base_grid && MyKTGridSetRowHeight)
    MyKTGridSetRowHeight(m_base_grid, row, height);
}

void KTGrid::SetColumnWidth(int column, int width)
{
  if (m_base_grid && MyKTGridSetColumnWidth)
    MyKTGridSetColumnWidth(m_base_grid, column, width);
}

void KTGrid::SetCellValue(int row, int column, const TCHAR* text)
{
  if (m_base_grid && MyKTGridSetCellValue)
    MyKTGridSetCellValue(m_base_grid, row, column, text);
}

void KTGrid::SetBackgroundColor(int row, int column, COLORREF color)
{
  if (m_base_grid && MyKTGridIsEditable) {
    MyKTGridSetBackgroundColor(m_base_grid, row, column, color);
  }
}

void KTGrid::SetTextColor(int row, int column, COLORREF color)
{
  if (m_base_grid && MyKTGridIsEditable) {
    MyKTGridSetTextColor(m_base_grid, row, column, color);
  }
}

BOOL KTGrid::IsEditable()
{
  BOOL s = FALSE;
  if (m_base_grid && MyKTGridIsEditable) {
    s = MyKTGridIsEditable(m_base_grid);
  }

  return s;
}

void KTGrid::SetEditable(BOOL s)
{
  if (m_base_grid && MyKTGridIsEditable) {
    MyKTGridSetEditable(m_base_grid, s);
  }
}

void KTGrid::MoveWindow(const CRect& rect)
{
  if (m_base_grid && m_base_grid->GetSafeHwnd()) {
    m_base_grid->MoveWindow(&rect);
  }
}

void KTGrid::ShowWindow(int cmd)
{
  if (m_base_grid && m_base_grid->GetSafeHwnd())
    m_base_grid->ShowWindow(cmd);
}