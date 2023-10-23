# 연습문제 4-2

> 타이머를 활용한 네모 애니메이션

## 주요 코드

```cpp
int now_size = 50;
int timer = 0;
bool is_plus = true;

void Cpractice42Dlg::OnPaint()
{
	if (IsIconic())
	{
		...(생략)...
	}
	else
	{
		CDialogEx::OnPaint();
		CClientDC dc(this);
		dc.Rectangle(100 - now_size, 100 - now_size, 100 + now_size, 100 + now_size);
	}
}


// 그리기 시작
void Cpractice42Dlg::OnDrawStart()
{

	CustomDialog dlg;

	if (dlg.DoModal() == IDOK)
	{
		UpdateData(TRUE);
		timer = dlg.m_input_value * 100;
		SetTimer(ID_TIMER_A, timer, NULL);
		UpdateData(FALSE);
	}
}

// 그리기 종료
void Cpractice42Dlg::OnDrawEnd()
{
	KillTimer(ID_TIMER_A);
}


// 타이머 이벤트 처리기
void Cpractice42Dlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case ID_TIMER_A:
	{
		Invalidate();
		if (is_plus) {
			now_size += 10;
			if (now_size >= 100) {
				is_plus = false;
			}
		}
		else {
			now_size -= 10;
			if (now_size <= 25) {
				is_plus = true;
			}
		}
		SetTimer(ID_TIMER_A, timer, NULL);
		break;
	}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

```

## 실행 결과

| 1초 | 2초 | 3초 |
|:---:|:---:|:---:|
|![1초](/img/연습문제%204-2%201초.gif)|![5초](/img/연습문제%204-2%205초.gif)|![10초](/img/연습문제%204-2%2010초.gif)|

