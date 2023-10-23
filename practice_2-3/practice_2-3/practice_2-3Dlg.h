
// practice_2-3Dlg.h: 헤더 파일
//

#pragma once


// Cpractice23Dlg 대화 상자
class Cpractice23Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cpractice23Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE_23_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox score_list;
	CString input_edit_control;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
