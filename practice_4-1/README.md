# 연습문제 4-1

> 시간을 입력받고, 해당 시간 이후에 원이 사라지는 창을 만들어라

## 실행 예시

```cpp

#include "CPopup.h"

void Creport31Dlg::OnDrawCircle()
{
	UpdateData(TRUE);
	CClientDC dc(this);
	
	CPopup PopupDialog;
	int timer = 0;
	if (PopupDialog.DoModal() == IDOK) {
		timer = PopupDialog.m_secode;
		dc.Ellipse(100, 100, 50, 50);

		timer = PopupDialog.m_secode * 1000;
		// SetTimser(타이머 ID, 타이머 시간, 콜백 함수)
		SetTimer(1, timer, NULL);
	}

	UpdateData(FALSE);
	
}


// 우클릭시 메뉴가 나오도록
void Creport31Dlg::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu* menu_bar = AfxGetMainWnd()->GetMenu();
	CMenu* menu = menu_bar->GetSubMenu(0);
	ASSERT(menu);

	menu ->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void Creport31Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	Invalidate();

	CDialogEx::OnTimer(nIDEvent);
}

```

## 실행 결과

![practice_4-1](/img/연습문제%204-1.gif)