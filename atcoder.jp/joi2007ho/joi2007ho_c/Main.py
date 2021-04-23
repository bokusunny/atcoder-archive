pillar_num = int(input())
pillar_coordinate_set = {tuple(map(int, input().split())) for _ in range(pillar_num)}

ans = 0
for pillar_coordinate1 in pillar_coordinate_set:
	pil1_x = pillar_coordinate1[0]
	pil1_y = pillar_coordinate1[1]
	for pillar_coordinate2 in pillar_coordinate_set:
		pil2_x = pillar_coordinate2[0]
		pil2_y = pillar_coordinate2[1]
		if not (pil1_x <= pil2_x and pil1_y < pil2_y): continue

		if (pil1_x+pil2_x)%2 != (pil1_y+pil2_y)%2: continue

		center_x = (pil1_x+pil2_x)/2
		center_y = (pil1_y+pil2_y)/2
		expected1 = (int(center_x-center_y+pil1_y), int(center_y+center_x-pil1_x))
		expected2 = (int(center_x-center_y+pil2_y), int(center_y+center_x-pil2_x))

		if expected1 in pillar_coordinate_set and expected2 in pillar_coordinate_set:
			ans = max(ans, ((expected1[0]-expected2[0])**2+(expected1[1]-expected2[1])**2)//2)

print(ans)