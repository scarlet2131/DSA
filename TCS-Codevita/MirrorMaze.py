def get_next_direction(x, y, direction, grid):
    """Returns the next direction after hitting a mirror"""
    if grid[x][y] == '/':
        if direction == 'up':
            return 'right'
        elif direction == 'right':
            return 'up'
        elif direction == 'down':
            return 'left'
        elif direction == 'left':
            return 'down'
    elif grid[x][y] == '\\':
        if direction == 'up':
            return 'left'
        elif direction == 'right':
            return 'down'
        elif direction == 'down':
            return 'right'
        elif direction == 'left':
            return 'up'
    return direction  # Continue in the same direction if no mirror

def dfs(x, y, direction, visited, grid):
    """Simulate the light's path and return the length of the loop if found"""
    path = []
    visited_positions = set()  # Track the positions to detect cycles
    
    while True:
        # If out of bounds, no loop can be formed
        if not (0 <= x < len(grid) and 0 <= y < len(grid[0])):
            return 0
        
        # If the current position with direction has been visited, return loop length
        if (x, y, direction) in visited_positions:
            # Find the cycle length
            loop_start = (x, y, direction)
            loop_cells = path[path.index(loop_start):]
            return len(loop_cells)
        
        # Mark the current state as visited and add it to the path
        visited_positions.add((x, y, direction))
        path.append((x, y, direction))
        
        # Move to the next position based on the current direction
        direction = get_next_direction(x, y, direction, grid)
        
        # Directions: (dx, dy) for up, right, down, left
        directions = {
            'up': (-1, 0),
            'right': (0, 1),
            'down': (1, 0),
            'left': (0, -1)
        }
        
        dx, dy = directions[direction]
        x, y = x + dx, y + dy
    
    return 0  # No loop found

def find_maximum_loop(M, N, grid):
    """Find the maximum loop length in the grid"""
    max_loop_cells = 0
    visited = set()
    
    for i in range(M):
        for j in range(N):
            # Try all four possible directions
            for initial_direction in ['up', 'right', 'down', 'left']:
                if grid[i][j] != '0' and (i, j, initial_direction) not in visited:
                    loop_cells = dfs(i, j, initial_direction, visited, grid)
                    max_loop_cells = max(max_loop_cells, loop_cells)
    
    return max_loop_cells

def main():
    # Read input
    M, N = map(int, input().split())  # Grid dimensions
    grid = [input().split() for _ in range(M)]  # Grid structure
    
    # Find and output the maximum loop length
    result = find_maximum_loop(M, N, grid)
    print(result)

# Run the main function to execute the program
if __name__ == "__main__":
    main()
