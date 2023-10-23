
// practice_3-3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "practice_3-3.h"
#include "practice_3-3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cpractice33Dlg 대화 상자



Cpractice33Dlg::Cpractice33Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRACTICE_33_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cpractice33Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
}

BEGIN_MESSAGE_MAP(Cpractice33Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cpractice33Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cpractice33Dlg 메시지 처리기

BOOL Cpractice33Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cpractice33Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

BOOL isfirst = true;

void Cpractice33Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else if (isfirst) {
		m_ctlList.AddString(_T("HS_BDIAGONAL"));
		m_ctlList.AddString(_T("HS_CROSS"));
		m_ctlList.AddString(_T("HS_DIAGCROSS"));
		m_ctlList.AddString(_T("HS_FDIAGONAL"));
		m_ctlList.AddString(_T("HS_HORIZONTAL"));
		m_ctlList.AddString(_T("HS_VERTICAL"));
		isfirst = false;
	}
	else
	{
		CDialogEx::OnPaint();

		CClientDC dc(this);

		// 브러쉬 생성
		CBrush brush;

		switch (m_ctlList.GetCurSel())
		{
		case 0:
			brush.CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));
			break;
		case 1:
			brush.CreateHatchBrush(HS_CROSS, RGB(0, 0, 0));
			break;
		case 2:
			brush.CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 0));
			break;
		case 3:
			brush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 0));
			break;
		case 4:
			brush.CreateHatchBrush(HS_HORIZONTAL, RGB(0, 0, 0));
			break;
		case 5:
			brush.CreateHatchBrush(HS_VERTICAL, RGB(0, 0, 0));
		default:
			break;
		}

		CBrush* oldBrush = dc.SelectObject(&brush);
		int size = 200, padding = 50;

		dc.Rectangle(padding, padding, size + padding, size + padding);
		dc.SelectObject(oldBrush);
		brush.DeleteObject();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cpractice33Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cpractice33Dlg::OnBnClickedButton1()
{
	Invalidate();
}
