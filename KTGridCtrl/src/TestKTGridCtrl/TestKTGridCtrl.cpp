
// TestKTGridCtrl.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestKTGridCtrl.h"
#include "TestKTGridCtrlDlg.h"

#include "KTGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestKTGridCtrlApp

BEGIN_MESSAGE_MAP(CTestKTGridCtrlApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestKTGridCtrlApp construction

CTestKTGridCtrlApp::CTestKTGridCtrlApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CTestKTGridCtrlApp object

CTestKTGridCtrlApp theApp;


// CTestKTGridCtrlApp initialization
static BOOL KTGetUserAppPath(TCHAR* buf, DWORD maxlen)
{
  DWORD ret = GetModuleFileName(NULL, buf, MAX_PATH);
  if (ret > maxlen) return FALSE;
  if (ret != _tcslen(buf)) return FALSE;

  for (size_t i = _tcslen(buf) - 1; i >= 0; --i) {
    if (buf[i] == _T('/') || buf[i] == _T('\\')) {
      buf[i] = _T('\0');
      break;
    }
  }
  return TRUE;
}

BOOL CTestKTGridCtrlApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

  TCHAR path[MAX_PATH + 1] = {0};
  if (KTGetUserAppPath(path, MAX_PATH)) {
    InitKTGrid(path);
  }



	CTestKTGridCtrlDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CTestKTGridCtrlApp::ExitInstance() 
{
  UnInitKTGrid();

  return CWinApp::ExitInstance();
}


