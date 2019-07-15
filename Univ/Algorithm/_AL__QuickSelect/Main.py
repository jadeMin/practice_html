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

number = input().split()
n = int(number[0])
k = int(number[1])

arr = input().split()

for i in range(0,n):
	arr[i] = int(arr[i])

print(quick_selection(arr, k))
