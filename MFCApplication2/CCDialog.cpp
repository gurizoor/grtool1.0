// CCDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "afxdialogex.h"
#include "CCDialog.h"
#include "resource.h"
#include <vector>
#include <iostream>


// CCDialog ダイアログ

IMPLEMENT_DYNAMIC(CCDialog, CDialogEx)

CCDialog::CCDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
    , O_String1(_T(""))
    , IEB1(_T(""))
    , IDB1(_T(""))
    , OTX1(_T(""))
{

}

CCDialog::~CCDialog()
{
}



BEGIN_MESSAGE_MAP(CCDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CCDialog::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &CCDialog::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON3, &CCDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCDialog メッセージ ハンドラー


void CCDialog::DoDataExchange(CDataExchange* pDX)
{
    DDX_Control(pDX, O_STATIC1, O_Static1);
    DDX_Text(pDX, IDC_EDIT1, IDB1);
    DDX_Text(pDX, IDC_STATIC2, OTX1);
    DDX_Control(pDX, IDC_STATIC2, OTXB1);
}

void CCDialog::OnBnClickedButton2()
{
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"));
    if (fileDlg.DoModal() == IDOK)
    {
        filePath = fileDlg.GetPathName();

        // ファイルを開いて内容を読み込む
        CStdioFile file;
        CString line;
        //std::vector<CString> lines;  // 行ごとに格納するベクター

        if (file.Open(filePath, CFile::modeRead | CFile::typeText))
        {
            while (file.ReadString(line))
            {
                lines.push_back(line);  // 各行をベクターに格納
            }
            file.Close();
        }

        //MessageBox(lines.at(0));

        // 各行を表示する (例としてメッセージボックスで表示)
        /*for (const auto& line : lines)
        {
            AfxMessageBox(line);
        }*/

        // ここで、必要な他の処理を行うことができます
        O_Static1.SetWindowText(filePath);  // Static Controlにファイルパスを表示
        MessageBox(filePath);               // ファイルパスをメッセージボックスで表示
    }
}


void CCDialog::OnBnClickedButton1()
{
    UpdateData(TRUE);
    int lsize = lines.size() - 1;// TODO: ここにコントロール通知ハンドラー コードを追加します。
    CString str;
    str.Format(_T("%d"), lsize);
    //MessageBox(str);
    //MessageBox(filePath);

    istr = IDB1;
    for (int i = 0; i < lsize; i += 2) {
        int pos = 0;  // 検索を開始する位置
        while ((pos = istr.Find(lines.at(i), pos)) != -1) {
            istr.Delete(pos, _tcslen(lines.at(i)));       // 見つかった位置の文字列を削除
            istr.Insert(pos, lines.at(i + 1));            // 新しい文字列を挿入
            pos += lines.at(i + 1).GetLength();           // 次の検索開始位置を設定
        }
    }
    OTXB1.SetWindowText(istr);
    //MessageBox(IDB1);

}
void CopyToClipboard(const CString& str)
{
    if (OpenClipboard(NULL))
    {
        EmptyClipboard();

        // メモリを割り当ててデータをコピー
        HGLOBAL hClipboardData;
        size_t size = (str.GetLength() + 1) * sizeof(TCHAR);
        hClipboardData = GlobalAlloc(GMEM_DDESHARE, size);

        if (hClipboardData)
        {
            TCHAR* pchData = static_cast<TCHAR*>(GlobalLock(hClipboardData));

            if (pchData)
            {
                _tcscpy_s(pchData, size / sizeof(TCHAR), str);
                GlobalUnlock(hClipboardData);

                // テキストデータをクリップボードに保存
                SetClipboardData(CF_UNICODETEXT, hClipboardData);
            }
        }

        CloseClipboard();
    }
}

void CCDialog::OnBnClickedButton3()
{
    CopyToClipboard(istr); // TODO: ここにコントロール通知ハンドラー コードを追加します。
}
