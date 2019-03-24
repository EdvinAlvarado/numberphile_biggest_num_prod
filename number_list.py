from time import time
t0 = time()
file = open("number.txt", "w")

for n in range(int(1e7)):
	n = str(n)
	# if "1" not in n and "5" not in n and "0" not in n:
		# if all(n[i] <= n[i+1] for i in range(len(n)-1)):
	file.write(n)
	file.write(" ")

file.close()
t1 = time()
print(t1-t0)