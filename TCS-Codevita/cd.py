from collections import defaultdict

def route_the_balls():
    N = int(input().strip())  # Number of junction routes
    graph = defaultdict(list)
    
    # Read the junction routes and build the graph
    for _ in range(N):
        junction_data = input().strip().split()
        junction = junction_data[0]
        for neighbor in junction_data[1:]:
            graph[junction].append(neighbor)
            graph[neighbor].append(junction)  # Since the graph is undirected
    
    # Read the sequence of ball colors
    ball_colors = input().strip().split()
    
    # To track the currently open paths at each junction
    last_opened = {}  # This will store the last opened path from each junction
    
    total_openings = 0  # Total number of openings
    
    # Function to perform DFS and find the path
    def find_path(start, target):
        visited = set()
        path = []
        
        def dfs(junction):
            if junction in visited:
                return False
            visited.add(junction)
            path.append(junction)
            if junction == target:
                return True
            for neighbor in graph[junction]:
                if dfs(neighbor):
                    return True
            path.pop()
            return False
        
        dfs(start)
        return path
    
    # Process each ball color
    for color in ball_colors:
        path = find_path('source', color)  # Get the path for the current ball
        current_openings = 0
        
        # print(f"\nProcessing ball with color {color}:")
        # print(f"Path for {color}: {path}")
        
        # For each step in the path, open the necessary paths
        for i in range(len(path) - 1):
            junction = path[i]
            next_junction = path[i + 1]
            path_tuple = (junction, next_junction)
            
            # If the current path from junction is already open, we skip it
            if junction in last_opened and last_opened[junction] == next_junction:
                # print(f"Path {junction} -> {next_junction} is already open, skipping.")
                continue
            
            # Otherwise, open the path and update the path at this junction
            last_opened[junction] = next_junction
            current_openings += 1
            # print(f"Opening path {junction} -> {next_junction}")
        
        total_openings += current_openings
        # print(f"Total openings after processing {color}: {total_openings}")
    
    # Output the total number of path openings
    # print(f"\nFinal Total Openings: {total_openings}")
    print(total_openings,end="")

# Main method to invoke the function
if __name__ == "__main__":
    route_the_balls()
