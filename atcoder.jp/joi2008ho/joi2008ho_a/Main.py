n = int(input())
table = []
last_color = None
for rock_i in range(n):
  # 0: white, 1: black
  rock_color = int(input())
  if rock_i%2 == 0:
    if last_color == None:
      table.append(1)
      last_color = rock_color
    elif last_color == rock_color:
      table[-1] += 1
    else:
      table.append(1)
      last_color = rock_color
  else:
    if rock_color == last_color:
      table[-1] += 1
    else:
      flipped = table.pop()
      if len(table) > 0:
        table[-1] += flipped+1
      else:
        table.append(flipped+1)
      last_color = rock_color

reversed_table = list(reversed(table))
print(sum(reversed_table[last_color::2]))