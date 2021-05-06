import math

a,b,x = map(int, input().split())

if a**2*b-x == 0:
  print(0)
elif x <= a**2*b/2:
  print(90-math.degrees(math.atan(2*x/(a*b**2))))
else:
  print(90-math.degrees(math.atan(a**3/(2*(a**2*b-x)))))