# 본 문제는 python 의 빠른 기초 학습을 위해 설계된 문제로서 python 코드 제출을 기준으로 설명되어 있습니다. 
# ------

# "연도.월.일"을 입력받아 "일-월-연도" 순서로 바꿔 출력해보자.

# 참고
# y, m, d = input().split('.')
# 과 같이 변수들을 순서대로 나열하면 구분기호를 기준으로 잘라 순서대로 저장한다.



# 입력
# 연도, 월, 일이 닷('.')으로 구분되어 입력된다.


# 출력
# 대시(마이너스 기호)를 구분기호로 사용해서
# 일-월-연도로 바꿔 출력한다.



y, m, d = input().split('.')
print(f"{d}-{m}-{y}")
