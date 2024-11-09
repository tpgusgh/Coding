import random
import time

wlist = ['cat', 'dog', 'fog', 'monkey', 'mouse', 'panda', 'frog', 'snake', 'wolf']
print("타작게임 준비되었으면 엔터!")
input()

start = time.time()

com = random.choice(wlist)

n=1

while n <= 5:
    print(com)
    player = input()
    if player == com:
        print("통과")
        n +=1
        com = random.choice(wlist)
    else:
        print("다시 도전!")

end = time.time()
wt = end - start
print(f'타자시간: {wt:.2f}초')
