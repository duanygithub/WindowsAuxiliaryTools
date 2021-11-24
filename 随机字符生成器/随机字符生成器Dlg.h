
// 随机字符生成器Dlg.h: 头文件
//

#pragma once

// C随机字符生成器Dlg 对话框
class C随机字符生成器Dlg : public CDialogEx
{
// 构造
public:
	C随机字符生成器Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

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
	// 保存生成后的字符串
//	CEdit Result;
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClickedCheck1();
	afx_msg void OnChangeEdit2();
};
