// dllmain.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#include "BaseGridCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE ESGridCtrlDLL = { NULL, NULL };

static CDynLinkLibrary* dll;

//
//extern "C" AFX_EXTENSION_MODULE ExtensionDLL;
class DllInstanceSwitcher
{
public:
    DllInstanceSwitcher()
    {
        m_hInst = AfxGetResourceHandle();
        AfxSetResourceHandle(ESGridCtrlDLL.hResource);
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

extern "C" CWnd* __stdcall ESGridCreateControl(CWnd* parent)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = new CBaseGridCtrl(parent);
  dlg->Create(CBaseGridCtrl::IDD, parent);
  dlg->ShowWindow(SW_SHOW);
  return dlg;
}

extern "C" void __stdcall ESGridSetRowCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetRowCount(count);
  }
}

extern "C" void __stdcall ESGridSetColumnCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetColumnCount(count);
  }
}

extern "C" void __stdcall ESGridSetLabelText(CWnd* grid, int row, int column, const TCHAR* text)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
  }
}

extern "C" void __stdcall ESGridSetCellValue(CWnd* grid, int row, int column, const TCHAR* text)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemText(row, column, text);

  }
}

extern "C" void __stdcall ESGridSetRowHeight(CWnd* grid, int row, int height)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetRowHeight(row, height); 
  }
}

extern "C" void __stdcall ESGridSetColumnWidth(CWnd* grid, int column, int width)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetColumnWidth(column, width);
  }
}


extern "C" int __stdcall  ESGridGetColumnCount(CWnd* grid)
{
  int count = 0;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    count = dlg->m_view_data_grid.GetColumnCount();
  }
  return count;
}

extern "C" int __stdcall  ESGridGetRowCount(CWnd* grid)
{
  int count = 0;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    count = dlg->m_view_data_grid.GetRowCount();
  }
  return count;
}

extern "C" void __stdcall  ESGridSetFixedColumnCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetFixedColumnCount(count);
  }
}

extern "C" void __stdcall  ESGridSetFixedRowCount(CWnd* grid, int count)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetFixedRowCount(count);
  }
}

extern "C" BOOL __stdcall ESGridShowGridControl(CWnd* w)
{
  return TRUE;
}

extern "C" void __stdcall ESGridSetEditable(CWnd* grid, BOOL s)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetEditable(s);
  }
}

extern "C" BOOL __stdcall ESGridIsEditable(CWnd* grid)
{
  BOOL s = FALSE;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    s = dlg->m_view_data_grid.IsEditable();
  }
  return s;
}

extern "C" BOOL __stdcall ESGridSortItem(CWnd* grid, int n, BOOL state)
{
  BOOL s = FALSE;
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    s = dlg->m_view_data_grid.SortItems(0, state);
  }

  return s;
}

extern "C" void __stdcall ESGridSetBackgroundColor(CWnd* grid, int row, int column, COLORREF color)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemBkColour(row, column, color);
  }
}

extern "C" void __stdcall ESGridSetTextColor(CWnd* grid, int row, int column, COLORREF color)
{
  SWITCH_RESOURCE;
  CBaseGridCtrl* dlg = (CBaseGridCtrl*)grid;
  if (dlg) {
    dlg->m_view_data_grid.SetItemFgColour(row, column, color);
  }
}

extern "C" void __stdcall ESGridDeleteControl(CWnd* grid)
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
    TRACE0("ESGridCtrl.DLL Initializing!\n");

    // Extension DLL one-time initialization
    if (!AfxInitExtensionModule(ESGridCtrlDLL, hInstance))
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

    dll = new CDynLinkLibrary(ESGridCtrlDLL);

  }
  else if (dwReason == DLL_PROCESS_DETACH)
  {
    TRACE0("ESGridCtrl.DLL Terminating!\n");

    // Terminate the library before destructors are called
    AfxTermExtensionModule(ESGridCtrlDLL);
  }
  return 1;   // ok
}
