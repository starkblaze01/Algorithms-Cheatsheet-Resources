n = 3
m = 3
M = [[1, 3, 3],
     [2, 1, 4],
     [0, 6, 4]]
if m>1:
	for i in range(n-2,-1,-1):
		for j in range(m):
			if j==0:
				M[j][i]+=max(M[0][i+1],M[1][i+1])
			elif j==m-1:
				M[j][i]+=max(M[-1][i+1],M[-2][i+1])
			else:
				M[j][i]+=max(M[j+1][i+1],M[j][i+1],M[j-1][i+1])
	mx=-2**32
	for i in range(m):
		if M[i][0]>mx:
			mx=M[i][0]
	print(mx)
else:
	print(sum(M[0]))
