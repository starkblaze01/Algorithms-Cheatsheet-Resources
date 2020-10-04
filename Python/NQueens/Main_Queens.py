from functions import dev

n = int(input('Introduce the number of queens: '))
sols = 0
solpos = dict()

for i in range(1, n+1):
    q = 1
    pos = [[1, i]]
    [q, pos, n, sols, solpos] = dev(q, pos, n, sols, solpos)

print('There are %d solutions!' % sols)

print(solpos)
