# 연습문제 2-3

> 과목별 점수를 입력해 놓도록 프로그램을 구현하시오.


## 메인 로직

```cpp
// 입력 버튼 클릭
void Cpractice23Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	score_list.AddString(input_edit_control);
	input_edit_control = "";
	UpdateData(FALSE);
}
```

## 실행 결과

![practice_2-3](/img/연습문제%202-3.gif)