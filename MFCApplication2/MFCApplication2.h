
// MFCApplication2.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCApplication2App:
// このクラスの実装については、MFCApplication2.cpp を参照してください
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
