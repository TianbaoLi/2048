
// 2048Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2048.h"
#include "2048Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy2048Dlg 对话框



CMy2048Dlg::CMy2048Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2048Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	PicCtrlList[1][1]=&PicCtrl11;
	PicCtrlList[1][2]=&PicCtrl12;
	PicCtrlList[1][3]=&PicCtrl13;
	PicCtrlList[1][4]=&PicCtrl14;
	PicCtrlList[2][1]=&PicCtrl21;
	PicCtrlList[2][2]=&PicCtrl22;
	PicCtrlList[2][3]=&PicCtrl23;
	PicCtrlList[2][4]=&PicCtrl24;
	PicCtrlList[3][1]=&PicCtrl31;
	PicCtrlList[3][2]=&PicCtrl32;
	PicCtrlList[3][3]=&PicCtrl33;
	PicCtrlList[3][4]=&PicCtrl34;
	PicCtrlList[4][1]=&PicCtrl41;
	PicCtrlList[4][2]=&PicCtrl42;
	PicCtrlList[4][3]=&PicCtrl43;
	PicCtrlList[4][4]=&PicCtrl44;
}

void CMy2048Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC11, PicCtrl11);
	DDX_Control(pDX, IDC_STATIC12, PicCtrl12);
	DDX_Control(pDX, IDC_STATIC13, PicCtrl13);
	DDX_Control(pDX, IDC_STATIC14, PicCtrl14);
	DDX_Control(pDX, IDC_STATIC21, PicCtrl21);
	DDX_Control(pDX, IDC_STATIC22, PicCtrl22);
	DDX_Control(pDX, IDC_STATIC23, PicCtrl23);
	DDX_Control(pDX, IDC_STATIC24, PicCtrl24);
	DDX_Control(pDX, IDC_STATIC31, PicCtrl31);
	DDX_Control(pDX, IDC_STATIC32, PicCtrl32);
	DDX_Control(pDX, IDC_STATIC33, PicCtrl33);
	DDX_Control(pDX, IDC_STATIC34, PicCtrl34);
	DDX_Control(pDX, IDC_STATIC41, PicCtrl41);
	DDX_Control(pDX, IDC_STATIC42, PicCtrl42);
	DDX_Control(pDX, IDC_STATIC43, PicCtrl43);
	DDX_Control(pDX, IDC_STATIC44, PicCtrl44);
}

BEGIN_MESSAGE_MAP(CMy2048Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMy2048Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CMy2048Dlg::OnBnClickedReset)
	ON_BN_CLICKED(IDOK2, &CMy2048Dlg::OnClickedStart)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy2048Dlg 消息处理程序

BOOL CMy2048Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	LoadPng();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2048Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2048Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy2048Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2048Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

int List[5][5];

void CMy2048Dlg::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码
	memset(List,0,sizeof(int)*5*5);
	LoadPng();
}


void CMy2048Dlg::LoadPng(void)
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			CBitmap bm;
			bm.LoadBitmap(IDB_BITMAP1);
			PicCtrlList[i][j]->SetBitmap(HBITMAP(bm));
		}
}


void CMy2048Dlg::OnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	memset(List,0,sizeof(int)*5*5);
	LoadPng();
	//if(Play()==0)MessageBox(_TEXT("Failed!"),_TEXT("Failed!"),MB_OK);
	//else MessageBox(_TEXT("You Got 2048!"),_TEXT("You Got 2048!"),MB_OK);
	Play();
}


void CMy2048Dlg::LoadPng(int x, int y, int k)
{
	CBitmap bm;
	if(k==0)bm.LoadBitmap(IDB_BITMAP1);
	else if(k==2)bm.LoadBitmap(IDB_BITMAP2);
	else if(k==4)bm.LoadBitmap(IDB_BITMAP3);
	else if(k==8)bm.LoadBitmap(IDB_BITMAP4);
	else if(k==16)bm.LoadBitmap(IDB_BITMAP5);
	else if(k==32)bm.LoadBitmap(IDB_BITMAP6);
	else if(k==64)bm.LoadBitmap(IDB_BITMAP7);
	else if(k==128)bm.LoadBitmap(IDB_BITMAP8);
	else if(k==256)bm.LoadBitmap(IDB_BITMAP9);
	else if(k==512)bm.LoadBitmap(IDB_BITMAP10);
	else if(k==1024)bm.LoadBitmap(IDB_BITMAP11);
	else if(k==2048)bm.LoadBitmap(IDB_BITMAP12);
	PicCtrlList[x][y]->SetBitmap(HBITMAP(bm));
}


void CMy2048Dlg::Play(void)
{
	srand((int)time(NULL));
	fill();
	fill();
	display();
	SetTimer(1,200,0);
}


int CMy2048Dlg::produce(int x)
{
	if(x==0)return 2;
	else return 4;
}


void CMy2048Dlg::fill(void)
{
	while(1)
	{
		int p=rand()%4+1;
		int q=rand()%4+1;
		if(List[p][q]==0)
		{
			List[p][q]=produce(rand()%2);
			Sleep(200);
			break;
		}
	}
}


int CMy2048Dlg::get_key(void)
{
	while(1)
	{
		if(GetAsyncKeyState(VK_UP))return 1;
		else if(GetAsyncKeyState(VK_DOWN))return 2;
		else if(GetAsyncKeyState(VK_LEFT))return 3;
		else if(GetAsyncKeyState(VK_RIGHT))return 4;
	}
}


int CMy2048Dlg::dfs_up(int i, int j)
{
	if(List[i][j]==0)return 0;
	else if(i==1)return List[i][j];
	else if(dfs_up(i-1,j)==0)
	{
		List[i-1][j]=List[i][j];
		List[i][j]=0;
		return dfs_up(i-1,j);
	}
	else if(dfs_up(i-1,j)==List[i][j])
	{
		List[i-1][j]*=2;
		List[i][j]=0;
		return 0;
	}
	else return List[i][j];
}


bool CMy2048Dlg::check_up(void)
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==0)
				for(int k=i;k<=4;k++)
					if(List[k][j]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==List[i+1][j]&&List[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}


void CMy2048Dlg::deal_up(void)
{
	for(int i=2;i<=4;i++)
		for(int j=1;j<=4;j++)
			dfs_up(i,j);
}


int CMy2048Dlg::dfs_down(int i, int j)
{
	if(List[i][j]==0)return 0;
	else if(i==4)return List[i][j];
	else if(dfs_down(i+1,j)==0)
	{
		List[i+1][j]=List[i][j];
		List[i][j]=0;
		return dfs_down(i+1,j);
	}
	else if(dfs_down(i+1,j)==List[i][j])
	{
		List[i+1][j]*=2;
		List[i][j]=0;
		return 0;
	}
	else return List[i][j];
}


bool CMy2048Dlg::check_down(void)
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==0)
				for(int k=i;k>=1;k--)
					if(List[k][j]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==List[i+1][j]&&List[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}


void CMy2048Dlg::deal_down(void)
{
	for(int i=3;i>=1;i--)
		for(int j=1;j<=4;j++)
			dfs_down(i,j);
}


int CMy2048Dlg::dfs_left(int i, int j)
{
	if(List[i][j]==0)return 0;
	else if(j==1)return List[i][j];
	else if(dfs_left(i,j-1)==0)
	{
		List[i][j-1]=List[i][j];
		List[i][j]=0;
		return dfs_left(i,j-1);
	}
	else if(dfs_left(i,j-1)==List[i][j])
	{
		List[i][j-1]*=2;
		List[i][j]=0;
		return 0;
	}
	else return List[i][j];
}


bool CMy2048Dlg::check_left(void)
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==0)
				for(int k=j;k<=4;k++)
					if(List[i][k]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if(List[i][j]==List[i][j+1]&&List[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}


void CMy2048Dlg::deal_left(void)
{
	for(int i=1;i<=4;i++)
		for(int j=2;j<=4;j++)
			dfs_left(i,j);
}


int CMy2048Dlg::dfs_right(int i, int j)
{
	if(List[i][j]==0)return 0;
	else if(j==4)return List[i][j];
	else if(dfs_right(i,j+1)==0)
	{
		List[i][j+1]=List[i][j];
		List[i][j]=0;
		return dfs_right(i,j+1);
	}
	else if(dfs_right(i,j+1)==List[i][j])
	{
		List[i][j+1]*=2;
		List[i][j]=0;
		return 0;
	}
	else return List[i][j];
}


bool CMy2048Dlg::check_right(void)
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==0)
				for(int k=j;k>=1;k--)
					if(List[i][k]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if(List[i][j]==List[i][j+1]&&List[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}


void CMy2048Dlg::deal_right(void)
{
	for(int i=1;i<=4;i++)
		for(int j=3;j>=1;j--)
			dfs_right(i,j);
}


int CMy2048Dlg::check(void)
{
	int b=1;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			if(List[i][j]==0&&b==1)
			{
				b=0;
				break;
			}
			else if(List[i][j]==2048&&b==1)
			{
				b=2048;
				break;
			}
		}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=4;j++)
			if(List[i][j]==List[i+1][j]&&List[i][j]!=0)
				{
					b=0;
					break;
				}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if(List[i][j]==List[i][j+1]&&List[i][j]!=0)
				{
					b=0;
					break;
				}
	return b;
}


void CMy2048Dlg::display(void)
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			LoadPng(i,j,List[i][j]);
}


void CMy2048Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//while(1)
	{
		switch(get_key())
		{
			case 1:
				if(check_up()==1)
				{
					deal_up();
					fill();
				}
				break;
			case 2:
				if(check_down()==1)
				{
					deal_down();
					fill();
				}
				break;
			case 3:
				if(check_left()==1)
				{
					deal_left();
					fill();
				}
				break;
			case 4:
				if(check_right()==1)
				{
					deal_right();
					fill();
				}
				break;
			default:
				break;
		}
		if(check()==2048)
		{
			display();
			MessageBox(_TEXT("You Got 2048!"),_TEXT("You Got 2048!"),MB_OK);
			exit(0);
		}
		else if(check()==1)
		{
			display();
			MessageBox(_TEXT("Failed!"),_TEXT("Failed!"),MB_OK);
			exit(0);
		}
	}
	display();
	CDialogEx::OnTimer(nIDEvent);
}
