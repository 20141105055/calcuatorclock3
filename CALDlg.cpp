
// CALDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CAL.h"
#include "CALDlg.h"
#include "afxdialogex.h"
#include "math.h"

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


// CCALDlg 对话框




CCALDlg::CCALDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCALDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_str = _T("");
	m_str1 = _T("");
	m_str2 = _T("");
	c1=180;
	c2=174;
	c3=180;
	c4=174;
	c5=180;
	c6=174;
	//hour1=hour-4;
	//min1=min-4;
	//sec1=sec-4;
}

void CCALDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_EDIT2, m_str1);
	DDX_Text(pDX, IDC_EDIT3, m_str2);
}

BEGIN_MESSAGE_MAP(CCALDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CCALDlg::OnClicked0)
	ON_BN_CLICKED(IDC_1, &CCALDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CCALDlg::OnClicked2)
	ON_BN_CLICKED(IDC_3, &CCALDlg::OnClicked3)
	ON_BN_CLICKED(IDC_4, &CCALDlg::OnClicked4)
	ON_BN_CLICKED(IDC_5, &CCALDlg::OnClicked5)
	ON_BN_CLICKED(IDC_6, &CCALDlg::OnClicked6)
	ON_BN_CLICKED(IDC_7, &CCALDlg::OnClicked7)
	ON_BN_CLICKED(IDC_8, &CCALDlg::OnClicked8)
	ON_BN_CLICKED(IDC_9, &CCALDlg::OnClicked9)
	ON_BN_CLICKED(IDC_Add, &CCALDlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_Cut, &CCALDlg::OnClickedCut)
	ON_BN_CLICKED(IDC_Ride, &CCALDlg::OnClickedRide)
	ON_BN_CLICKED(IDC_Divide, &CCALDlg::OnClickedDivide)
	ON_BN_CLICKED(IDC_Equal, &CCALDlg::OnClickedEqual)
	ON_BN_CLICKED(IDC_Dot, &CCALDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_Percent, &CCALDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_1Dividex, &CCALDlg::OnBnClicked1dividex)
	ON_BN_CLICKED(IDC_C, &CCALDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_Backspace, &CCALDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_CE, &CCALDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_Sqart, &CCALDlg::OnBnClickedSqart)
	ON_BN_CLICKED(IDC_Madd, &CCALDlg::OnBnClickedMadd)
	ON_BN_CLICKED(IDC_MR, &CCALDlg::OnBnClickedMr)
	ON_BN_CLICKED(IDC_MC, &CCALDlg::OnBnClickedMc)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCALDlg 消息处理程序

BOOL CCALDlg::OnInitDialog()
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
	SetTimer(1,10,NULL);
	SetTimer(2,600,NULL);
	SetTimer(3,3600,NULL);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCALDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCALDlg::OnPaint()
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
HCURSOR CCALDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCALDlg::OnClicked0()
{
	
	UpdateData(true);
	m_str = m_str+L"0";
	m_str1 = m_str1+L"0";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked1()
{
	UpdateData(true);
	m_str = m_str+L"1";
	m_str1 = m_str1+L"1";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked2()
{
	UpdateData(true);
	m_str = m_str+L"2";
	m_str1 = m_str1+L"2";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked3()
{
	UpdateData(true);
	m_str = m_str1+L"3";
	m_str1 = m_str+L"3";
	UpdateData(false);
	
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked4()
{
	UpdateData(true);
	m_str = m_str+L"4";	
	m_str1 = m_str1+L"4";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked5()
{
	UpdateData(true);
	m_str = m_str+L"5";
	m_str1 = m_str1+L"5";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked6()
{
	UpdateData(true);
	m_str = m_str+L"6";
	m_str1 = m_str1+L"6";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked7()
{
	UpdateData(true);
	m_str = m_str+L"7";
	m_str1 = m_str1+L"7";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked8()
{
	UpdateData(true);
	m_str = m_str+L"8";
	m_str1 = m_str1+L"8";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClicked9()
{
	UpdateData(true);
	m_str = m_str+L"9";
	m_str1 = m_str1+L"9";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClickedAdd()
{
	UpdateData(true);
	flag=1;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"+";
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClickedCut()
{
	
	UpdateData(true);
	flag=2;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"-";
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClickedRide()
{
	UpdateData(true);
	flag=3;
	temp = _ttof(m_str);
	m_str="";
	temp = _ttof(m_str1);
	m_str1=m_str1+L"*";
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClickedDivide()
{
	UpdateData(true);
	flag=4;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"/";
	UpdateData(false);

	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnClickedEqual()
{
	
	if(flag==1)
	{
		UpdateData(true);
		temp = temp+_ttof(m_str);
	}	
	if(flag==2)
	{
		UpdateData(true);
		temp = temp- _ttof(m_str);
	}
	if(flag==3)
	{
		UpdateData(true);
		temp = temp*_ttof(m_str);
	}
	if(flag==4)
	{
		UpdateData(true);
		if( _ttof(m_str)==0)
		{
			m_str="error";
		}
		else
		{
			temp =temp / _ttof(m_str);
		}
	}
	if(flag==5)
	{
	    UpdateData(true);
		temp=temp/100;
	}
	if(flag==6)
	{
	    UpdateData(true);
		temp=1/temp;
	}
	if(flag==7)
	{
		UpdateData(true);
		temp=sqrt(temp);
	}
	if(flag==8)
	{
		UpdateData(true);
		mermory=0;
		mermory=mermory+temp;
	}
	if(flag==9)
	{
        UpdateData(true);
		temp=mermory;
	}
	while(m_str.Right(1)=="0.")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	    UpdateData(false);
    }
	m_str.Format(L"%lf",temp);
	check(m_str);
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}
void CCALDlg::check(CString &s)
{
	while(s.Right(1)=="0")
		s.Delete(s.GetLength()-1,1);
}


void CCALDlg::OnBnClickedDot()
{
	UpdateData(true);
	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedPercent()
{
	UpdateData(true);
	flag=5;
	temp=_ttof(m_str);
	m_str= "";
	temp = _ttof(m_str1);
	m_str1 =m_str1+L"%";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}





void CCALDlg::OnBnClicked1dividex()
{
	UpdateData(true);
	flag=6;
	temp = _ttof(m_str);
	m_str="";
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedC()
{
	UpdateData(true);
	m_str="0.";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedBackspace()
{
	m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedCe()
{
	UpdateData(true);
	m_str="";
	m_str1="";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedSqart()
{
	flag=7;
	UpdateData(true);
	temp = _ttof(m_str);
	m_str ="";
	temp = _ttof(m_str1);
	m_str1 =m_str1+L"sqrt";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedMadd()
{
	UpdateData(true);
	flag=8;
	//m_str2=m_str;
	temp = _ttof(m_str1);
	x=0;
	x++;
	if(x=1)
	{
		m_str2="";
		m_str2 = m_str2+L"M+";
	}
	m_str1="";
	m_str="";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CCALDlg::OnBnClickedMr()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=9;
	m_str1="";
	check(m_str);
	UpdateData(true);
	m_str.Format(L"%lf",temp);
	UpdateData(false);
}


void CCALDlg::OnBnClickedMc()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str2="";
	UpdateData(false);
}


void CCALDlg::OnTimer(UINT_PTR nIDEvent)
{
	//CTime time= CTime::GetCurrentTime();
    // hour=time.GetHour();
	 //min=time.GetMinute();
	// sec=time.GetSecond();
	// hour=hour*30;
	// min=min*6;
	
	int x,x1,y,y1,x2,y2,x3,y3,x4,y4,x5,y5,ox=400,oy=200;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
	{
	int r=100;
	CDC *pDC;
	CPen newpen,*oldpen;
	newpen.CreatePen(PS_SOLID,1,RGB(240,240,240));
	pDC=GetDC();
	oldpen=pDC->SelectObject(&newpen);
	x=ox+r*sin(c1*3.1415926/180);
	y=oy+r*cos(c1*3.1415926/180);
	pDC->MoveTo(ox,oy);
	pDC->LineTo(x,y);
	c1=c1-6;
	CDC *pDC1;
	CPen newpen1;
	newpen1.CreatePen(PS_SOLID,1,RGB(0,0,250));
	pDC1=GetDC();
	oldpen=pDC1->SelectObject(&newpen1);
	x1=ox+r*sin(c2*3.1415926/180);
	y1=oy+r*cos(c2*3.1415926/180);
	pDC1->MoveTo(ox,oy);
	pDC1->LineTo(x1,y1);
	c2=c2-6;
	}
	if(nIDEvent==2)
	{
	int r=50;
	CDC *pDC2;
	CPen newpen2,*oldpen;
	newpen2.CreatePen(PS_SOLID,4,RGB(240,240,240));
	pDC2=GetDC();
	oldpen=pDC2->SelectObject(&newpen2);
	x2=ox+r*sin(c3*3.1415926/180);
	y2=oy+r*cos(c3*3.1415926/180);
	pDC2->MoveTo(ox,oy);
	pDC2->LineTo(x2,y2);
	c3=c3-6;
	CDC *pDC3;
	CPen newpen3;
	newpen3.CreatePen(PS_SOLID,4,RGB(0,250,0));
	pDC3=GetDC();
	oldpen=pDC3->SelectObject(&newpen3);
	x3=ox+r*sin(c4*3.1415926/180);
	y3=oy+r*cos(c4*3.1415926/180);
	pDC3->MoveTo(ox,oy);
	pDC3->LineTo(x3,y3);
	c4=c4-6;
	}
	if(nIDEvent==3)
	{
	int r=25;
	CDC *pDC4;
	CPen newpen4,*oldpen;
	newpen4.CreatePen(PS_SOLID,6,RGB(240,240,240));
	pDC4=GetDC();
	oldpen=pDC4->SelectObject(&newpen4);
	x4=ox+r*sin(c5*3.1415926/180);
	y4=oy+r*cos(c5*3.1415926/180);
	pDC4->MoveTo(ox,oy);
	pDC4->LineTo(x4,y4);
	c5=c5-6;
	CDC *pDC5;
	CPen newpen5;
	newpen5.CreatePen(PS_SOLID,6,RGB(250,0,0));
	pDC5=GetDC();
	oldpen=pDC5->SelectObject(&newpen5);
	x5=ox+r*sin(c6*3.1415926/180);
	y5=oy+r*cos(c6*3.1415926/180);
	pDC5->MoveTo(ox,oy);
	pDC5->LineTo(x5,y5);
	c6=c6-6;
	}
	
	CDC *pDC6,newpen7;
	pDC6=GetDC();
	CPen pen(PS_SOLID,6,RGB(0,0,255));
	CPen* pOldPen=pDC6->SelectObject(&pen);
	pDC6->TextOutW(300,200,L"9");
	pDC6->TextOutW(400,100,L"12");
	pDC6->TextOutW(500,200,L"3");
	pDC6->TextOutW(400,300,L"6");
    CDC *pDC7,*Oldpen1;
	pDC7=GetDC();
    CPen pen1(PS_SOLID,6,RGB(0,0,255));
   // CPen* pOldPen1=pDC7->SelectObject(&Oldpen1);
    pDC7->SelectStockObject(NULL_BRUSH);
    pDC7->Ellipse(ox - 100, oy - 100 , ox +100, oy +100);
	CDialogEx::OnTimer(nIDEvent);
}
