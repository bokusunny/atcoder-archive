n = int(input())
x_list = []
y_list = []
for i in range(n):
  x, y = map(int, input().split())
  x_list.append((x, i))
  y_list.append((y, i))

x_list.sort(key=lambda x: x[0])
y_list.sort(key=lambda x: x[0])

dic = dict()
max_x_dis = x_list[-1][0]-x_list[0][0]
max_x_dis_cities = tuple(sorted([x_list[-1][1], x_list[0][1]]))
dic[max_x_dis_cities] = max_x_dis

max_x_dis = x_list[-2][0]-x_list[0][0]
max_x_dis_cities = tuple(sorted([x_list[-2][1], x_list[0][1]]))
dic[max_x_dis_cities] = max_x_dis
if max_x_dis_cities in dic:
  if max_x_dis > dic[max_x_dis_cities]:
    dic[max_x_dis_cities] = max_x_dis
else:
  dic[max_x_dis_cities] = max_x_dis
max_x_dis = x_list[-1][0]-x_list[1][0]
max_x_dis_cities = tuple(sorted([x_list[-1][1], x_list[1][1]]))
dic[max_x_dis_cities] = max_x_dis
if max_x_dis_cities in dic:
  if max_x_dis > dic[max_x_dis_cities]:
    dic[max_x_dis_cities] = max_x_dis
else:
  dic[max_x_dis_cities] = max_x_dis

max_y_dis = y_list[-1][0]-y_list[0][0]
max_y_dis_cities = tuple(sorted([y_list[-1][1], y_list[0][1]]))
if max_y_dis_cities in dic:
  if max_y_dis > dic[max_y_dis_cities]:
    dic[max_y_dis_cities] = max_y_dis
else:
  dic[max_y_dis_cities] = max_y_dis
max_y_dis = y_list[-2][0]-y_list[0][0]
max_y_dis_cities = tuple(sorted([y_list[-2][1], y_list[0][1]]))
if max_y_dis_cities in dic:
  if max_y_dis > dic[max_y_dis_cities]:
    dic[max_y_dis_cities] = max_y_dis
else:
  dic[max_y_dis_cities] = max_y_dis
max_y_dis = y_list[-1][0]-y_list[1][0]
max_y_dis_cities = tuple(sorted([y_list[-1][1], y_list[1][1]]))
if max_y_dis_cities in dic:
  if max_y_dis > dic[max_y_dis_cities]:
    dic[max_y_dis_cities] = max_y_dis
else:
  dic[max_y_dis_cities] = max_y_dis

li = sorted(dic.values(), reverse=True)
print(li[1])