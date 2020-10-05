def dfs(grid, row, col):
    """
    :type grid: List[List[str]]
    :type row : int
    :type col : int
    :rtype    : int
    """

    # Checking for Out of Bounds
    if (row < 0 or col < 0 or row > len(grid)-1 or col > len(grid[row])-1 or grid[row][col] == '0'):
        return 0

    # Assigning the traversed the element to a '0'
    grid[row][col] = '0'

    # Recursive DFS calls to traverse through the neighbors

    # Below the element
    dfs(grid, row+1, col)
    # Above the element
    dfs(grid, row-1, col)
    # To the right of the element
    dfs(grid, row, col+1)
    # To the left of the element
    dfs(grid, row, col-1)

    # Returning 1 after successful traversing from all the neighbors
    return 1


def numIslands(grid):
    """
    :type grid: List[List[str]]
    :rtype    : int
    """

    # Initializing variable which will keep track of Possible Islands
    numIslands = 0

    # Traversing through whole grid and Finding neighbors using DFS
    # where we encounter 1

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == '1':
                numIslands += dfs(grid, row, col)

    return numIslands


if __name__ == '__main__':
    grid = [["1", "1", "0", "0", "0"],
            ["1", "1", "0", "0", "0"],
            ["1", "0", "1", "0", "0"],
            ["0", "0", "0", "1", "1"]
            ]

    result = numIslands(grid)
    print(f'Number of Islands possible from the grid is {result}.')
