
// CALDlg.h : 头文件
//

#pragma once


// CCALDlg 对话框
class CCALDlg : public CDialogEx
{
// 构造
public:
	CCALDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	int flag;
	int x;
	double temp;
	int c1,c2,c3,c4,c5,c6;
	//double hour,min,sec,hour1,min1,sec1;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void check(CString &s);
public:
	CString m_str;
	double mermory;
	afx_msg void OnClicked0();
	afx_msg void OnClicked1();
	afx_msg void OnClicked2();
	afx_msg void OnClicked3();
	afx_msg void OnClicked4();
	afx_msg void OnClicked5();
	afx_msg void OnClicked6();
	afx_msg void OnClicked7();
	afx_msg void OnClicked8();
	afx_msg void OnClicked9();
	afx_msg void OnClickedAdd();
	afx_msg void OnClickedCut();
	afx_msg void OnClickedRide();
	afx_msg void OnClickedDivide();
	afx_msg void OnClickedEqual();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClicked1dividex();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedSqart();
	afx_msg void OnBnClickedMadd();
	CString m_str1;
	CString m_str2;
	afx_msg void OnBnClickedMr();
	afx_msg void OnBnClickedMc();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
