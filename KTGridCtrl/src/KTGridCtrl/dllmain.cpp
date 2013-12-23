// dllmain.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#include "BaseGridCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE KTGridCtrlDLL = { NULL, NULL };

static CDynLinkLibrary* dll;

//
//extern "C" AFX_EXTENSION_MODULE ExtensionDLL;
class DllInstanceSwitcher
{
public:
    DllInstanceSwitcher()
    {
        m_hInst = AfxGetResourceHandle();
        AfxSetResourceHandle(KTGridCtrlDLL.hResource);
    }

    ~DllInstanceSwitcher()
    {
        AfxSetResourceHandle(m_hInst);
    }

private:
    HINSTANCE m_hInst;
};

#define SWITCH_RESOURCE  DllInstanceSwitcher __SwitchInstance;
//

extern "C" CWnd* __stdcall KTGridCreateControl(CWnd* parent)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = new CBaseGridCtrl(parent);
  dlg->Create(CBaseGridCtrl::IDD, parent);
  dlg->ShowWindow(SW_SHOW);
  return dlg;
}

extern "C" void __stdcall KTGridSetRowCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetRowCount(count);
  }
}

extern "C" void __stdcall KTGridSetColumnCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetColumnCount(count);
  }
}

extern "C" void __stdcall KTGridSetLabelText(CWnd* grid, int row, int column, const TCHAR* text)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
  }
}

extern "C" void __stdcall KTGridSetCellValue(CWnd* grid, int row, int column, const TCHAR* text)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemText(row, column, text);
  }
}

extern "C" void __stdcall KTGridSetRowHeight(CWnd* grid, int row, int height)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetRowHeight(row, height); 
  }
}

extern "C" void __stdcall KTGridSetColumnWidth(CWnd* grid, int column, int width)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetColumnWidth(column, width);
  }
}


extern "C" int __stdcall  KTGridGetColumnCount(CWnd* grid)
{
  int count = 0;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    count = dlg->m_view_data_grid.GetColumnCount();
  }
  return count;
}

extern "C" int __stdcall  KTGridGetRowCount(CWnd* grid)
{
  int count = 0;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    count = dlg->m_view_data_grid.GetRowCount();
  }
  return count;
}

extern "C" void __stdcall  KTGridSetFixedColumnCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetFixedColumnCount(count);
  }
}

extern "C" void __stdcall  KTGridSetFixedRowCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetFixedRowCount(count);
  }
}

extern "C" BOOL __stdcall KTGridShowGridControl(CWnd* w)
{
  return TRUE;
}

extern "C" void __stdcall KTGridSetEditable(CWnd* grid, BOOL s)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetEditable(s);
  }
}

extern "C" BOOL __stdcall KTGridIsEditable(CWnd* grid)
{
  BOOL s = FALSE;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    s = dlg->m_view_data_grid.IsEditable();
  }
  return s;
}

extern "C" void __stdcall KTGridSetBackgroundColor(CWnd* grid, int row, int column, COLORREF color)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemBkColour(row, column, color);
  }
}

extern "C" void __stdcall KTGridSetTextColor(CWnd* grid, int row, int column, COLORREF color)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemFgColour(row, column, color);
  }
}

extern "C" void __stdcall KTGridDeleteControl(CWnd* grid)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->DestroyWindow();
    delete dlg;
  }
}

extern "C" int APIENTRY
  DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  // Remove this if you use lpReserved
  UNREFERENCED_PARAMETER(lpReserved);

  if (dwReason == DLL_PROCESS_ATTACH)
  {
    TRACE0("KTGridCtrl.DLL Initializing!\n");

    // Extension DLL one-time initialization
    if (!AfxInitExtensionModule(KTGridCtrlDLL, hInstance))
      return 0;

    // Insert this DLL into the resource chain
    // NOTE: If this Extension DLL is being implicitly linked to by
    //  an MFC Regular DLL (such as an ActiveX Control)
    //  instead of an MFC application, then you will want to
    //  remove this line from DllMain and put it in a separate
    //  function exported from this Extension DLL.  The Regular DLL
    //  that uses this Extension DLL should then explicitly call that
    //  function to initialize this Extension DLL.  Otherwise,
    //  the CDynLinkLibrary object will not be attached to the
    //  Regular DLL's resource chain, and serious problems will
    //  result.

    dll = new CDynLinkLibrary(KTGridCtrlDLL);

  }
  else if (dwReason == DLL_PROCESS_DETACH)
  {
    TRACE0("KTGridCtrl.DLL Terminating!\n");

    // Terminate the library before destructors are called
    AfxTermExtensionModule(KTGridCtrlDLL);
  }
  return 1;   // ok
}
