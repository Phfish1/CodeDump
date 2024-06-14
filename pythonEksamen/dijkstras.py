matrix = [
[ 1, 1, 11 ] ,
[ 4, 5, 1 ] ,
[ 7, 8, 9 ]
]

matrix = [
[ 272, 900000, 965, 995, 603, 909, 758, 390, 709, 693 ] ,
[ 9, 600, 806, 201, 905, 688, 294, 860, 6, 501 ] ,
[ 362, 454, 902, 479, 632, 78, 469, 255, 650, 755 ] ,
[ 337, 927, 535, 858, 839, 236, 813, 457, 360, 482 ] ,
[ 153, 742, 367, 793, 749, 870, 413, 81, 961, 165 ] ,
[ 937, 88, 291, 35, 325, 580, 912, 15, 777, 779 ] ,
[ 813, 638, 641, 918, 140, 758, 755, 522, 745, 12 ] ,
[ 902, 978, 273, 9, 80, 498, 850, 863, 651, 123 ] ,
[ 262, 104, 32, 735, 780, 177, 327, 175, 667, 128 ] ,
[ 45, 344, 622, 627, 349, 184, 802, 400, 701, 550 ]
]

def find_neighbours(graph, row, column):
    ### Checks if index exists
    ### Row vertecies represents the direction (DOWN) and the column_vertecies the direction (RIGHT)
    ### THEN we return valid_paths AKA all the directions we can move in from the specified vertecy

    ### Describes which way to go in the graph
    row_vertecies = [+1, 0] 
    column_vertecies = [0, +1]

    valid_paths = [] 

    for direction in range(0, 2):
        ### Get next row either DOWN or RIGHT based on vertecies
        next_row = row + row_vertecies[direction] 
        next_column = column + column_vertecies[direction]

        ### Checks if index is within graph
        if ( (0 <= next_row < len(graph)) and (0 <= next_column < len(graph[0])) ):
            valid_paths.append([next_row, next_column]) ### Add cordinates to valid paths

    return valid_paths ### RETURNS 2D array of cordinates ( array[0-2][2] )



def dijkstras(graph, row, column, shortest): ### Row + Collumn representing the vertex 

    ### "Import" global variables
    global current_cost
    global current_path
    global shortest_path
    
    ### BASE CONDITION that hits when row-and-column is at the last index in the graph
    if row == (len(graph) -1) and column == (len(graph[0]) -1):
        if do_shortest:
            if current_cost < shortest_path["cost"]: 
                ### if path we are on is has less cost than our shortest_path cost
                ## replace shortest_path["Path"] with currentpath
                ## Repplace shortest_cost with current cost
                shortest_path["path"] = current_path.copy() ### Use copy, OR else shortest_path["path"] will be BOUND to the current_path
                shortest_path["cost"] = current_cost

            return ### Returns last vertex in maze is hit
        else:
            if current_cost > shortest_path["cost"]: ### For highest path
                shortest_path["path"] = current_path.copy()
                shortest_path["cost"] = current_cost

            return True
    
    next_paths = find_neighbours(graph, row, column)

    ### THE FOR LOOP "Saves" all the possible paths so it can use it later when recursing backwords
    # This way we can loop through each possible path 
    for path in next_paths: 
    ### Explores every path possible, but if there are no more vertixes to visit go back (recursivly) until you can visit one or if paths are depleted
        
        ### Add next STEP(cordinates) and next cost to Current Path and Cost
        current_path.append( [path[0], path[1]] )
        current_cost += graph[current_path[-1][0]][current_path[-1][1]]

        ### Call recursivly
        dijkstras(graph, path[0], path[1], shortest)

        ### Do this before you recursibly go back, to track which path you are on
        current_cost -= graph[current_path[-1][0]][current_path[-1][1]]
        current_path.pop()

    return shortest_path
    


current_path = []
current_cost = matrix[0][0] 
do_shortest = True

### Create different object depending on if shortest or longest path
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

### TO go from shortest to highest value CHANGE:
# 1 cost from "float("inf")" to 0
# 2 "<" to ">" in "if current_cost < shortest_path["cost"]: ### Change from "<" to ">" for highest cost"
# 3 True to False in "result = dijkstras(matrix, 0, 0, True)"