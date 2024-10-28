# Ricardo Alfredo Calvo Perez
# A01028889
# 07/10/2024

# El programa recibe dos números enteros M y N, seguido de M líneas de N valores booleanos(0|1) separados por un espacio, por la entrada estándar que representan el laberinto.
# Un 1 representa una casilla en la que es posible moverse, un 0 es una casilla por la que NO se puede pasar.
# El origen o casilla de inicio es siempre la casilla (0,0) y la salida o meta es siempre la casilla (M-1, N-1)
# La salida del programa es una matriz de valores booleanos (0|1) que representan el camino para salir del laberinto.
# Primero debe mostrarse la solución utilizando la técnica de backtracking, y luego utilizando la técnica de ramificación y poda.


# ---------------------------
# Main functions
# ---------------------------

def get_user_input_maze():
    # Get the dimensions of the maze
    M = int(input("Enter the number of rows (M): "))
    N = int(input("Enter the number of columns (N): "))

    maze = []

    print("Enter the maze row by row (0 for walls, 1 for paths):")
    for i in range(M):
        while True:
            row_input = input(f"Row {i+1}: ")
            row = list(map(int, row_input.split()))
            
            if len(row) != N:
                # Conditions to get proper input
                print(f"Please enter exactly {N} numbers separated by spaces.")
            elif any(num not in (0, 1) for num in row): 
                # Condition to only get 0 or 1
                print("Please enter only 0s and 1s.")
            else:
                # add values to list 
                maze.append(row)
                break

    return maze

def is_safe(maze, x, y, M, N):
    # Check if the (x, y) position is valid within the maze
    return 0 <= x < M and 0 <= y < N and maze[x][y] == 1

# --------------------------- 
# Backtracking Solution
# ---------------------------

# Complexity O(N * M)

def solve_maze_backtracking(maze):
    M = len(maze)  # Number of rows
    N = len(maze[0])  # Number of columns
    
    # Initialize the solution list of lists
    solution = [[0 for _ in range(N)] for _ in range(M)]
    
    if backtrack(maze, 0, 0, solution, M, N):
        # Conditions for posible case
        return solution
    else:
        print("No solution found using backtracking.")
        return None

def backtrack(maze, x, y, solution, M, N):
    # If we have reached the goal (M-1, N-1), mark the exit
    if x == M - 1 and y == N - 1:
        solution[x][y] = 1
        return True

    if is_safe(maze, x, y, M, N):
        solution[x][y] = 1  # Mark this cell as part of the path
        
        # Move down
        if backtrack(maze, x + 1, y, solution, M, N):
            return True
        
        # Move right
        if backtrack(maze, x, y + 1, solution, M, N):
            return True
        
        # Move up
        if backtrack(maze, x - 1, y, solution, M, N):
            return True
        
        # Move left
        if backtrack(maze, x, y - 1, solution, M, N):
            return True
        
        # If no direction is valid
        solution[x][y] = 0
        return False

# ---------------------------
# Branch and Bound Solution
# ---------------------------

# Complexity O(N * M) 

import heapq

def branch_and_bound(maze):
    M = len(maze)  # Number of rows
    N = len(maze[0])  # Number of columns
    solution = [[0 for _ in range(N)] for _ in range(M)]
    
    # Priority queue for (cost, x, y, path)
    queue = [(0, 0, 0, [(0, 0)])]  # (cost, x, y, path)
    visited = set((0, 0))  # Set of visited cells
    
    while queue:
        cost, x, y, path = heapq.heappop(queue)
        
        # If we've reached the goal
        if (x, y) == (M - 1, N - 1):
            for i, j in path:
                solution[i][j] = 1
            return solution
        
        # Explore neighbors (right, down, left, up)
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if is_safe(maze, nx, ny, M, N) and (nx, ny) not in visited:
                visited.add((nx, ny))
                heapq.heappush(queue, (cost + 1, nx, ny, path + [(nx, ny)]))
    
    print("No solution found using branch and bound.")
    return None

# Main program
maze = get_user_input_maze()

# Solve the maze using backtracking
solution_backtracking = solve_maze_backtracking(maze)
if solution_backtracking:
    print("\nSolution using backtracking:")
    for row in solution_backtracking:
        print(row)

# Solve the maze using branch and bound
solution_bb = branch_and_bound(maze)
if solution_bb:
    print("\nSolution using branch and bound:")
    for row in solution_bb:
        print(row)
