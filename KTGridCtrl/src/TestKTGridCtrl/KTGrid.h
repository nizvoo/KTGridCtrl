#ifndef __KT_GRID_H__
#define __KT_GRID_H__


/*
 * This utility must use MFC extension dynamic link library
 * It is interface for grid control c++ language
 * 2013 @ KT corp.
 * zhangyong.ni@gmail.com
 */

BOOL InitKTGrid(const TCHAR* path);
void UnInitKTGrid();

class KTGrid
{
public:
  KTGrid();
  virtual ~KTGrid();
public:
  BOOL CreateControl(CWnd* parent);

public:
  void SetRowCount(int count);
  void SetColumnCount(int count);

  int GetRowCount();
  int GetColumnCount();

  void SetFixedRowCount(int count);
  void SetFixedColumnCount(int count);

  void SetRowHeight(int row, int height);
  void SetColumnWidth(int column, int width);

  void SetCellValue(int row, int column, const TCHAR*);

  void SetBackgroundColor(int row, int column, COLORREF color);
  void SetTextColor(int row, int column, COLORREF color);

  BOOL IsEditable();
  void SetEditable(BOOL s);

  void ShowWindow(int cmd);

public:
  void MoveWindow(const CRect& rect);
private:
  CWnd* m_base_grid;
};

#endif