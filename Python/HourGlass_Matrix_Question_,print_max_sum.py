def max_sum(grid):
    mxsum=-99999999
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if j+2 >= len(grid[i]) or i+2 >= len(grid[j]):
                continue
            sum=(grid[i][j]+grid[i][j+1]+grid[i][j+2])+(grid[i+1][j+1])+(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2])
            if sum > mxsum:
                mxsum=sum
            else:
                continue
    return mxsum

grid=[]
for i in range(6):
    l=[int(i) for i in input().split()]
    grid.append(l)
