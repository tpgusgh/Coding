#리스트 평탄화 코드 작성 시험문제임
lst = [1,2,3] + [4,5,6]
example = [[1,2,3],[4,[5,6]],7,[8,9]]
def flatten(data) :
  output = []
  for item in data:
    if type(item) == list:
      output += flatten(item)
      print('output',output)
    else:
      output.append(item) #output = [1]
      print('append',item)
  return output


print(flatten(example))
