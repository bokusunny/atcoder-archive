_ = input()
array = list(map(int, input().split()))
times = 0
def check_even(l):
  tmp = []
  for a in l:
    if a%2==0:
      tmp.append(a/2)
    else:
      return False
  return tmp
 
while True:
  result = check_even(array)
  if result:
    times += 1
    array = result
  else:
    break
    
print(times)