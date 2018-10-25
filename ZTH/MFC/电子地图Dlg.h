// µç×ÓµØÍ¼Dlg.h : header file
//

#if !defined(AFX_DLG_H__684F44F5_9A20_4584_AA36_985F967527CA__INCLUDED_)
#define AFX_DLG_H__684F44F5_9A20_4584_AA36_985F967527CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	int		m_shunxulinkid;
	int		m_Class;
	int		m_branch;
	CString	m_name;
	CString	m_fileip;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileopen();
	afx_msg void Onshuchutxt();
	afx_msg void Onshunxu_linkid();
	afx_msg void OnChangeshunxulinkid();
	afx_msg void Onzhebanlinkid();
	afx_msg void OnFileupdate();
	afx_msg void OnChangeClass();
	afx_msg void OnshunxuClass();
	afx_msg void OnzhebanClass();
	afx_msg void OnChangebranch();
	afx_msg void Onshunxubranch();
	afx_msg void Onzhebanbranch();
	afx_msg void OnChangename();
	afx_msg void Onname();
	afx_msg void Onzhebanname();
	afx_msg void OnButton2();
	afx_msg void Onxuanzelinkid();
	afx_msg void Oncharulinkid();
	afx_msg void Onkuaipailinkid();
	afx_msg void OnButton3();
	afx_msg void Onxuanzeclass();
	afx_msg void Onxuanzebranch();
	afx_msg void OnquicksortClass();
	afx_msg void Onpaopaobranch();
	afx_msg void Onxuanze_branch();
	afx_msg void Oncharubranch();
	afx_msg void Onquicksortbranch();
	afx_msg void Onnamepaopao();
	afx_msg void Onnamexuanze();
	afx_msg void Oncharu();
	afx_msg void Onkuaisu();
	afx_msg void OnChangeip();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__684F44F5_9A20_4584_AA36_985F967527CA__INCLUDED_)
