#include "CCDialog.h"

// MFCApplication2Dlg.h : ヘッダー ファイル
//

#pragma once


// CMFCApplication2Dlg ダイアログ
class CMFCApplication2Dlg : public CDialogEx
{
// コンストラクション
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic statictext2;
	CStatic statictext3;

private:
	bool check1 = true;
	CCDialog childw;
};
