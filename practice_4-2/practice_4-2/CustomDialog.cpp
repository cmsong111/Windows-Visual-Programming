// CustomDialog.cpp: 구현 파일
//

#include "pch.h"
#include "practice_4-2.h"
#include "afxdialogex.h"
#include "CustomDialog.h"


// CustomDialog 대화 상자

IMPLEMENT_DYNAMIC(CustomDialog, CDialog)

CustomDialog::CustomDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_input_value(0)
{

}

CustomDialog::~CustomDialog()
{
}

void CustomDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input_value);
}


BEGIN_MESSAGE_MAP(CustomDialog, CDialog)
END_MESSAGE_MAP()


// CustomDialog 메시지 처리기
