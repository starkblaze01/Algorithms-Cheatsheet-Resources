from importlib.resources import path
import numpy as np
import cv2
import time
from collections import deque

img = np.zeros((40,40,3), np.uint8)

red = [0, 0, 255]
blue = [255, 0, 0]
white = [255, 255, 255]
grey = [127, 127, 127]
green = [60, 255, 60] 
black=(0,0,0) 
import random

for i in range(40):
    for j in range(40):
        k=random.random()
        if(k>0.08):
            # print(k)
            # m+=1
            img[i][j]=white

     

img = cv2.resize(img,(200,200)) 
for i in range(200):
    for j in range(200):
        if (img[i][j]!=white).all():
            img[i][j]=black

img[180][7]=blue  #here one can define the starting and ending coordinates
img[120][15]=red   

#dijkstra's
obs_col=black
gol_col=red



w, h, c = img.shape
print(img.shape)

img_copy = img.copy()

class Node():
    def __init__(self, parent, position):
        self.parent = parent
        self.position = position
        self.g = np.inf
        self.h = np.inf
        self.f = np.inf

def get_min_dist_node(open_list):
    min_dist = np.inf
    min_node = None
    for node in open_list:
        if open_list[node].f < min_dist:
            min_dist = open_list[node].f
            min_node = open_list[node]
    return min_node

def get_dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return (((x1-x2)**2 + (y1-y2)**2))**0.5

def obstacle(position):
    x, y = position
    if (img[y][x]==obs_col).all():#
        return True
    return False

def goal_reached(position):
    x, y = position
    if (img[y][x]==gol_col).all():#
        return True
    return False

def show_path(node):#
    print('show path')
    current_node = node
    path = []
    while current_node is not None:
        path.append(current_node.position)
        current_node = current_node.parent
    path.reverse()
    for i in range(len(path)-1):
        cv2.line(img_copy, path[i], path[i+1], blue,1)
        # img_copy[path[i].position[1]][path[i+1].position[0]] = green
    cv2.namedWindow('final path', cv2.WINDOW_NORMAL)
    cv2.imshow("final path", img_copy)
    cv2.imwrite("final_path.png", img_copy)
    if cv2.waitKey(1) == 'q':
        cv2.destroyAllWindows()
        return

def astar_algorithm(start, end):
    print('astar called')
    open_list = {}
    closed_list = []
    start_node =  Node(None, start)
    start_node.g = start_node.h = start_node.f = 0
    open_list[start] = start_node
    while len(open_list)>0:
        # print("dict size = ", len(open_list))
        current_node = get_min_dist_node(open_list)

        print(current_node.position)#

        img[current_node.position[1]][current_node.position[0]] = grey
        open_list.pop(current_node.position)

        # print("greyed")

        if current_node.position == end:
            print("Goal Reached")
            show_path(current_node)
            return

        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])
            if(node_position[0]>199)or(node_position[1]>199)or(node_position[0]<1)or(node_position[1]<1):
                continue
            
            if node_position in closed_list:
                # print("closed list")
                continue
            if obstacle(node_position):
                # print("Obstacle")
                continue

            # print("New pos")
            
            img[node_position[1]][node_position[0]] = blue
            new_node = Node(current_node, node_position)

            new_node.g = current_node.g + get_dist(current_node.position, new_node.position)
            new_node.h = 0  #zero for dijkstra
            new_node.f = new_node.g + new_node.h

            if new_node.position in open_list:
                if new_node.g < open_list[new_node.position].g:
                    open_list[new_node.position] = new_node
            else:
                open_list[new_node.position] = new_node
        
        if current_node.position not in closed_list:
            closed_list.append(current_node.position)
        
        cv2.namedWindow('path_finding', cv2.WINDOW_NORMAL)
        cv2.imshow("path_finding", img)
        if cv2.waitKey(1)& 0xFF==ord('q'):
            break
    show_path(current_node)      
         
            
    




start = (7,180)
end = (15, 120)



begin_ = time.time()     #algorithm time =  118.80660343170166 in the test cases
astar_algorithm(start, end)
end = time.time()


print("algorithm time = ", (end-begin_))

cv2.namedWindow("path_finding", cv2.WINDOW_NORMAL)
cv2.imshow("path_finding", img)

cv2.waitKey(0)
cv2.destroyAllWindows()
