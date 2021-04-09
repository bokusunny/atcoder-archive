def my_removesuffix(s, suffix):
    return s[:-len(suffix)] if s.endswith(suffix) else s

def removeEndingGivenWord(s):
  words = ['dream', 'dreamer', 'erase', 'eraser']

  for word in words:
    if not s.endswith(word):
      continue
    else:
      return my_removesuffix(s, word)
 
  return False
 
S = input()
 
while True:
  if len(S) == 0:
    print('YES')
    break
 
  S = removeEndingGivenWord(S)
  if S == False:
    print('NO')
    break