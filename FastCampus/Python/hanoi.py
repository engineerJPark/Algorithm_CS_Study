def hanoi(n, pos_start, pos_purpose, pos_temp):
	if n == 1:
		print(pos_start, "to", pos_purpose)
		return
	hanoi(n - 1, pos_start, pos_temp, pos_purpose)
	print(pos_start, "to", pos_purpose)
	hanoi(n - 1, pos_temp, pos_purpose, pos_start)
	
	
	
print('case n=1\n')
hanoi(1,1,3,2)
print('case n=2\n')
hanoi(2,1,3,2)
print('case n=3\n')
hanoi(3,1,3,2)
