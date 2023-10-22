# 계산기 프로그램

대화상자 기반의 프로젝트를 만들어보자.


## 메인 로직
```cpp

int value = 0;
int cal = 0;

// + 버튼
void Cpractice22Dlg::OnBnClickedButton1()
{
	value = GetDlgItemInt(IDC_EDIT1);
	cal = 1;
	SetDlgItemInt(IDC_EDIT1, 0);
}

// - 버튼
void Cpractice22Dlg::OnBnClickedButton2()
{
	value = GetDlgItemInt(IDC_EDIT1);
	cal = 2;
	SetDlgItemInt(IDC_EDIT1, 0);

}
// * 버튼
void Cpractice22Dlg::OnBnClickedButton3()
{
	value = GetDlgItemInt(IDC_EDIT1);
	cal = 3;
	SetDlgItemInt(IDC_EDIT1, 0);
}

// / 버튼
void Cpractice22Dlg::OnBnClickedButton4()
{
	value = GetDlgItemInt(IDC_EDIT1);
	cal = 4;
	SetDlgItemInt(IDC_EDIT1, 0);

}

// = 버튼
void Cpractice22Dlg::OnBnClickedButton5()
{
	switch (cal)
	{
	case 1:
		value = value + GetDlgItemInt(IDC_EDIT1);
		SetDlgItemInt(IDC_EDIT1, value);
		break;
	case 2:
		value = value - GetDlgItemInt(IDC_EDIT1);
		SetDlgItemInt(IDC_EDIT1, value);
		break;
	case 3:
		value = value * GetDlgItemInt(IDC_EDIT1);
		SetDlgItemInt(IDC_EDIT1, value);
		break;
	case 4:
		if (value == 0) {
			MessageBox(_T("0으로 나눌 수 없습니다."), _T("경고"), MB_OK);
			break;
		}
		value = value / GetDlgItemInt(IDC_EDIT1);
		SetDlgItemInt(IDC_EDIT1, value);
		break;
	default:
		cal = 0;
		break;
	}

}

// 지움 버튼
void Cpractice22Dlg::OnBnClickedButton6()
{
	SetDlgItemInt(IDC_EDIT1, 0);
	value = 0;
	cal = 0;

}
```

## 결과

|더하기|빼기|
|:---:|:---:|
|![](/img//연습문제%202-2%20더하기.gif) |![](/img/연습문제%202-2%20빼기.gif) |
|곱하기|나누기|
|![](/img/연습문제%202-2%20곱하기.gif) |![](/img/연습문제%202-2%20나누기.gif) |