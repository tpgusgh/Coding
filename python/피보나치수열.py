#메모할 딕셔너리
memo = {
    1: 1,
    2: 1,
}
count = 0
def fibo(n):
  global count
  count += 1
  if n in memo:
    return memo[n]
  else:
    output = fibo(n-1) + fibo(n-2)
    memo[n] = output
    return output

n = int(input("몇 번째 피보나치 수를 계산할까요? "))
# 결과 출력
print(f"{n}번째 피보나치 수는 {fibo(n)}입니다.")
print(f"총 연산횟수 : {count}")
print(memo )
