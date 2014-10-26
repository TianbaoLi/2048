
// 2048Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy2048Dlg 对话框
class CMy2048Dlg : public CDialogEx
{
// 构造
public:
	CMy2048Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY2048_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedReset();
	afx_msg void OnClickedStart();
	virtual void LoadPng(void);
	CStatic PicCtrl11;
	CStatic PicCtrl12;
	CStatic PicCtrl13;
	CStatic PicCtrl14;
	CStatic PicCtrl21;
	CStatic PicCtrl22;
	CStatic PicCtrl23;
	CStatic PicCtrl24;
	CStatic PicCtrl31;
	CStatic PicCtrl32;
	CStatic PicCtrl33;
	CStatic PicCtrl34;
	CStatic PicCtrl41;
	CStatic PicCtrl42;
	CStatic PicCtrl43;
	CStatic PicCtrl44;
	CStatic *PicCtrlList[5][5];
	void LoadPng(int x, int y, int k);
	void Play(void);
	int produce(int x);
	void fill(void);
	int get_key(void);
	int dfs_up(int i, int j);
	bool check_up(void);
	void deal_up(void);
	int dfs_down(int i, int j);
	bool check_down(void);
	void deal_down(void);
	int dfs_left(int i, int j);
	bool check_left(void);
	void deal_left(void);
	int dfs_right(int i, int j);
	bool check_right(void);
	void deal_right(void);
	int check(void);
	void display(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
