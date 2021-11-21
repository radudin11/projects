import sys


class Graph():
    def __init__(self, vertices):
        self.verticies = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]

    def printSolution1(self, src, dest, dist):
        if(dist[dest] == sys.maxsize):
            print("There is no path to {}".format(dest))
        else:
            print("Shortest distance form {} to {} is {}".format(
                src, dest, dist[dest]))

    def printSolution2(self, src, dist):
        print("Distances from node {}: ".format(src))
        for node in range(self.verticies):
            if(dist[node] == sys.maxsize):
                print("There is no path to {}".format(node))
            else:
                print("To node {}: {}".format(node, dist[node]))

    def minDistance(self, dist, visited):
        min = sys.maxsize
        for v in range(self.verticies):
            if(dist[v] < min and visited[v] == False):
                min = dist[v]
                index_min = v

        return index_min

    def isShorter(self, origin, destiantion, dist):
        if dist[destiantion] > dist[origin] + self.graph[destiantion][origin]:
            return True
        return False

    def dijkstra(self, src, **kwargs):
        dest = kwargs.get("destination", None)
        if dest:
            dest = int(dest)
        dist = [sys.maxsize] * self.verticies
        visited = [False] * self.verticies
        dist[src] = 0
        solution = False
        while(not solution):

            current_vertext = self.minDistance(dist, visited)
            visited[current_vertext] = True
            if dest and current_vertext == dest:
                break

            solution = True
            for adjacent_vertex in range(self.verticies):
                if self.graph[current_vertext][adjacent_vertex] > 0 and \
                        visited[adjacent_vertex] == False:
                    solution = False
                    if self.isShorter(current_vertext, adjacent_vertex, dist):
                        dist[adjacent_vertex] = dist[current_vertext] + \
                            self.graph[current_vertext][adjacent_vertex]
        if bool(dest):
            self.printSolution1(src, dest, dist)
        else:
            self.printSolution2(src, dist)


def getSource():
    while True:
        try:
            src = int(input("Give te starting point: "))
            return src
        except:
            print("Unknown input")


def hasDestination():
    while(True):
        check_destination = input("Do you want a destination point?[Y/n]: ")
        if check_destination.lower() in "y ":
            return True
        elif check_destination.lower() == "n":
            return False
        else:
            print("Unknown input, reloading...")


def getDestination():
    while True:
        try:
            dest = int(input("Give the end point: "))
            return dest
        except:
            print("Unknown input")

# main
g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
           [4, 0, 8, 0, 0, 0, 0, 11, 0],
           [0, 8, 0, 7, 0, 4, 0, 0, 2],
           [0, 0, 7, 0, 0, 14, 0, 0, 0],
           [0, 0, 0, 0, 0, 0, 0, 0, 0],
           [0, 0, 4, 14, 0, 0, 2, 0, 0],
           [0, 0, 0, 0, 0, 2, 0, 1, 6],
           [8, 11, 0, 0, 0, 0, 1, 0, 7],
           [0, 0, 2, 0, 0, 0, 6, 7, 0]
           ]
# Program implements dijkstra's algorithm on the graph above.

# After the source node is given you can choose to either 
# set a destination node(default) or show distances to 
# every node from the source

src = getSource()
if hasDestination():
    dest = getDestination()
    g.dijkstra(src, destination = dest)
else:
    g.dijkstra(src)