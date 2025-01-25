def flood_fill(grid, x, y, new_color):
    rows, cols = len(grid), len(grid[0])
    original_color = grid[x][y]
    if original_color == new_color:
        return

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] != original_color:
            return
        grid[r][c] = new_color
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    dfs(x, y)

# Usage
grid = [
    [1, 1, 1],
    [1, 1, 0],
    [1, 0, 1]
]
flood_fill(grid, 1, 1, 2)
print("Flood Fill Result:", grid)
