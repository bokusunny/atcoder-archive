row_num, column_num = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())

grid = []
for _ in range(row_num):
	grid.append(list(input()))

moving_list = [(1, 0), (-1, 0), (0, 1), (0, -1)]

from collections import deque
q = deque([(sy-1, sx-1)])
d_set = {(sy-1, sx-1): 0}

while q:
	coordinate = q.popleft()
	y = coordinate[0]
	x = coordinate[1]
	if y == gy-1 and x == gx-1:
		exit(print(d_set[coordinate]))
	for moving in moving_list:
		y_move = moving[0]
		x_move = moving[1]
		if y+y_move < 0 or row_num-1 < y+y_move or x+x_move < 0 or column_num-1 < x+x_move or grid[y+y_move][x+x_move] == '#' or (y+y_move, x+x_move) in d_set:
			continue

		q.append((y+y_move, x+x_move))
		d_set[(y+y_move, x+x_move)] = d_set[coordinate] + 1