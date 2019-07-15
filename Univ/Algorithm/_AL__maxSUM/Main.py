# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
def quick_selection(arr, k):
	pivot = arr[(len(arr)+1)//2 - 1]
	left, mid, right = [], [], []
	for i in range(len(arr)):
		if arr[i] < pivot:
			left.append(arr[i])
		elif arr[i] > pivot:
			right.append(arr[i])
		else:
			mid.append(arr[i])

	if k <= len(left):
		return quick_selection(left, k)
	elif k > len(left) + len(mid):
		return quick_selection(right, k - (len(left) + len(mid)))
	else:
		return pivot

number = input()
n = int(number)

arr = input().split()

for i in range(0,n):
	arr[i] = int(arr[i])

b1 = quick_selection(arr, n)
b2 = quick_selection(arr, n-1)
b3 = quick_selection(arr, n-2)
s1 = quick_selection(arr, 1)
s2 = quick_selection(arr, 2)

big3s = b1 * b2 * b3
big2s = b1 * b2 * b3
small3s = s1 * s2 * b1
small2s = s1 * s2

if big3s > big2s:
	bigger1 = big3s
else:
	bigger1 = big2s
	
if small3s > small2s:
	bigger2 = small3s
else:
	bigger2 = small2s
	
if bigger1 > bigger2:
	print(bigger1)
else:
	print(bigger2)