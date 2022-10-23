from importlib.resources import path
import numpy as np
import cv2
from collections import deque

img = np.zeros((40,40,3), np.uint8)

red = [0, 0, 255]
blue = [255, 0, 0]
white = [255, 255, 255]
grey = [127, 127, 127]
green = [60, 255, 60] 
black=(0,0,0) 


import random
# m=0
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
#bfs

path_col=grey
gol_col=red


img1=img   #randomly generated image


class Node():
    def __init__(self, index, parent):
        self.x = index[0]
        self.y = index[1]
        self.parent = parent

def show_path(end, start):
    print("ending point:", end.x, end.y)
    print("starting point: ", start.x, start.y)
    current = end
    while(current != start):    
        img1[current.x][current.y] = green
        current = current.parent
    
def bfs(start):  
    q = deque()
    q.append(start)
    
    
    cv2.namedWindow('path', cv2.WINDOW_NORMAL)
    while len(q):
        current = q.pop()  #for dfs its just pop
        i, j = current.x, current.y
        
        cv2.imshow('path', img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        
        if j+1 < img.shape[1]: 
                
            if (img[i][j+1]!=black).any() and (img[i][j+1] != path_col).any():
                if (img[i][j+1] == gol_col).all():
                    break   
                
                img[i][j+1] = path_col  
                n = Node((i, j+1), current)
                q.append(n)
        if i+1 < img.shape[0]:
            
            if (img[i+1][j] !=black).any() and (img[i+1][j] != path_col).any():
                if (img[i+1][j] == gol_col).all():
                    break
                
                img[i+1][j] = path_col
                n = Node((i+1, j), current)
                q.append(n)
        if j-1 > 0:
            
            if (img[i][j-1]!=black).any() and (img[i][j-1] != path_col).any():
                if (img[i][j-1] == gol_col).all():
                    break
                
                img[i][j-1] = path_col
                n = Node((i, j-1), current)
                q.append(n)
        if i-1 > 0:
            
            if (img[i-1][j]!=black).any() and (img[i-1][j] != path_col).any():
                if (img[i-1][j] == gol_col).all():
                    break
                
                img[i-1][j] = path_col
                n = Node((i-1, j), current)
                q.append(n)
                        
    show_path(current, start)  


start = Node((180,7), None)
bfs(start)


cv2.namedWindow('final', cv2.WINDOW_NORMAL)
cv2.imshow("final", img1)
cv2.waitKey(0)
