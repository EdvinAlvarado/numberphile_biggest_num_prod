import numpy as np
# n = 12677889
def multdigits(n):
	# strn = str(n)
	lst = [int(x) for x in str(n)]
	# print("%i: %i" % (counter, n))
	# print(np.prod(lst))

	# if "1" not in strn and "5" not in strn and "0" not in strn:
	if 1 not in lst or 5 not in lst or 0 not in lst or 4 not in lst:
		# if all(lst[i] <= lst[i+1] for i in range(len(lst)-1)):
		counter = 0
		while len(lst) != 1:
			counter += 1
			n = np.prod(lst)
			# print("%i: %i" % (counter, n))
			lst = [int(x) for x in str(n)]
		# print("%i: %i" % (counter, n))
		return counter
	return 0

# print(int(1e6))
max_n = 0
for n in range(1, int(1e6)):
	max_n = max(multdigits(n), max_n)
	# print(max_n)

print(max_n)