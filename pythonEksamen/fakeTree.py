matrix = [
[ 0 ] ,
[ 2, 4 ] ,
[ 0, 5, 6 ],
[ 7, 2, 9, 10 ],
[ 25, 11, 1, 0, 5 ],
[ 1, 88, 51, 88, 61, 4 ],
[ 93, 12, 73, 36, 71, 65, 34 ],
[ 233, 5, 2, 1, 6, 7, 55, 1 ],
[ 16, 111, 213, 9, 23, 433, 1, 34, 13 ],
[ 5, 23, 453, 789, 123, 200, 212, 345, 556, 99 ]
]

def find_neighbours(graph, row, column):

    ### Diffrent row vertecies specifying you always must go down
    row_vertecies = [+1, +1, +1]
    column_vertecies = [0, +1, -1]

    valid_paths = []

    for direction in range(0, 3):
        next_row = row + row_vertecies[direction]
        next_column = column + column_vertecies[direction]

        ### Now check if index is within range of current row and column
        if ( (0 <= next_row < len(graph)) and (0 <= next_column < len(graph[row])) ):
            valid_paths.append([next_row, next_column])

    return valid_paths

def dijkstras(graph, row, column, shortest): ### Row + Collumn representing the vertex 
    global current_cost
    global current_path
    global shortest_path
    

    ### BASE CONDITION
    if row == (len(graph) -1): ### Returns True when last vertex in maze is hit
        
        ### IF CONDITION TO SEPERATE between shortest and longest
        if shortest:
            if current_cost < shortest_path["cost"]: ### Change from "<" to ">" for highest cost
                shortest_path["path"] = current_path.copy() ### Use copy, OR else shortest_path["path"] will be BOUND to the current_path
                shortest_path["cost"] = current_cost
            return True
        else:
            if current_cost > shortest_path["cost"]: ### Change from "<" to ">" for highest cost
                shortest_path["path"] = current_path.copy() ### Use copy, OR else shortest_path["path"] will be BOUND to the current_path
                shortest_path["cost"] = current_cost
            return True
    
    next_paths = find_neighbours(graph, row, column)

    ### Loop trough each path
    for path in next_paths: ### Explores every path possible, but if there are no more vertixes to visit go back (recursivly) until you can visit one or if paths are depleted
        current_path.append( [path[0], path[1]] )
        current_cost += graph[current_path[-1][0]][current_path[-1][1]]

        dijkstras(graph, path[0], path[1], shortest)

        current_cost -= graph[current_path[-1][0]][current_path[-1][1]]
        current_path.pop()

    return shortest_path
    


current_path = []
current_cost = matrix[0][0]

### Condition to do shortest or longst path
do_shortest = True
if do_shortest:
    shortest_path = {
        "path": [],
        "cost": float("inf") # Change to 0 for highest path
    }
elif not do_shortest:
    shortest_path = {
        "path": [],
        "cost": 0 # Change to 0 for highest path
    }

result = dijkstras(matrix, 0, 0, do_shortest)

print(result)


