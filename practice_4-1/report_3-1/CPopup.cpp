// CPopup.cpp: 구현 파일
//

#include "pch.h"
#include "report_3-1.h"
#include "afxdialogex.h"
#include "CPopup.h"


// CPopup 대화 상자

IMPLEMENT_DYNAMIC(CPopup, CDialogEx)

CPopup::CPopup(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TIMER, pParent)
	, m_secode(0)
{

}

CPopup::~CPopup()
{
}

void CPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_secode);
}


BEGIN_MESSAGE_MAP(CPopup, CDialogEx)
END_MESSAGE_MAP()
