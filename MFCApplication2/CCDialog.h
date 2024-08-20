#pragma once
#include "afxdialogex.h"
#include <vector>


// CCDialog ダイアログ

class CCDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CCDialog)

public:
	CCDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CCDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString O_String1;
	CStatic O_Static1;
	CString filePath;
	//CString fileContent;
	std::vector<CString> lines;
	afx_msg void OnBnClickedButton1();
	CString IEB1;
	CString IDB1;
	CString OTX1;
	CStatic OTXB1;
	afx_msg void OnBnClickedButton3();
	CString istr;
};
