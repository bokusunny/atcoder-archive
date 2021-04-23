N, M = map(int, input().split())
ks_list = [list(map(int, input().split())) for _ in range(M)]
p_list = list(map(int, input().split()))

ans = 0
for i in range(2**N):
	on_switches = set()
	for j in range(N):
		if (i >> j & 1): on_switches.add(j+1)

	patterns = 0
	all_bulb_lightened_flag = True
	for i, ks in enumerate(ks_list):
		switch_count = 0
		for s in ks[1:]:
			if s in on_switches:
				switch_count += 1

		if switch_count % 2 == p_list[i]:
			pass
		else:
			all_bulb_lightened_flag = False
			break

	if all_bulb_lightened_flag: ans += 1

print(ans)