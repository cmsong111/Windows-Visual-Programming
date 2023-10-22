# 연습문제 2-1

## 문제 정의
특정 컨트롤에 대해 비활성화 시키기 위해서는 "GetDlgItem" 함수를 사용한다. 이 함수는 컨트롤의 핸들을 반환한다. 이 핸들을 이용하여 "EnableWindow" 함수를 사용하여 컨트롤을 비활성화 시킨다. 이를 이용하여 다음과 같은 프로그램을 작성하라.

![](/img/연습문제%202-1.gif)


## 문제 풀이

```cpp
void Cpractice11Dlg::OnBnClickedRadio1()
{
	GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
}


void Cpractice11Dlg::OnBnClickedRadio2()
{
	GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
}
```