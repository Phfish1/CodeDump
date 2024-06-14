maze = [
[1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ] ,
[1, 0, 1, 0, 1, 1, 1, 1, 0, 1 ] ,
[1, 1, 1, 0, 1, 1, 0, 1, 0, 1 ] ,
[0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ] ,
[1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ] ,
[1, 0, 1, 1, 1, 1, 0, 1, 0, 0 ] ,
[1, 0, 1, 0, 0, 0, 0, 0, 0, 1 ] ,
[1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ] ,
[1, 1, 0, 0, 0, 1, 1, 1, 0, 1 ]
]

def mark_vertexes(graph):
    ### Create new 2D gonna be Array
    marked_vertexes = []

    ### Loop trough each element in the 2D array
    for i in range(0, len(graph)):
        
        ### Make each row
        marked_vertexes.append([])

        for j in range(0, len(graph[i])):

            ### Set each element in column == False
            marked_vertexes[i].append(False) 

    return marked_vertexes

def find_neighbours(graph, row, column):
    ### Checks if index exists, then checks if you can go to neighbour AKA if number == 1 
    ### THEN Check if vertex is marked / already visited
    ### Row vertecies represents the directions (UP, DOWN) and the column_vertecies the directions (LEFT, RIGHT)
    ### THEN we return valid_paths AKA all the directions we can move in from the specified vertecy

    row_vertecies = [-1, +1, 0, 0]
    column_vertecies = [0, 0, -1, +1]

    valid_paths = []

    for direction in range(0, 4):
        next_row = row + row_vertecies[direction]
        next_column = column + column_vertecies[direction]

        ### Checks if within maze bounds
        if ( (0 <= next_row < len(graph)) and (0 <= next_column < len(graph[0])) ): ### UP
            if graph[next_row][next_column] != 0: ### Checks if stone
                if not marked_maze[next_row][next_column]: ### Checks if already visisted (Marked)
                    
                    ### Append to valid paths
                    valid_paths.append([next_row, next_column])

    return valid_paths

def dfs(graph, row, column): ### Row + Collumn representing the vertex

    ### BASE CASE
    # Returns True when last vertex in maze is hit 
    if row == (len(graph) -1) and column == (len(graph[0]) -1):
        return True
    
    # Shows program you have already been to this vertex
    marked_maze[row][column] = True 

    next_paths = find_neighbours(graph, row, column)

    ### Explores every path possible, 
    #  but if there are no more vertixes to visit go back 
    # (recursivly) until you can visit one ("stored" in for loop) or if paths are depleted

    for path in next_paths: 
        if dfs(graph, path[0], path[1]):
            # If base condition is hit CONTINUE to return Treu
                                                                #true_path.append([path[0], path[1]]) ### retrace paths back to start (not needed anymore though)
            return True

    
    
    return False



### Creates an identical maze but all 0s
marked_maze = mark_vertexes(maze)


is_solvable = dfs(maze, 0, 0)

print(f"Is the MAZE solvable: \033[1m{is_solvable}\033[00m") ### \033 = specify colour, [1m = bold, [00m = reset 