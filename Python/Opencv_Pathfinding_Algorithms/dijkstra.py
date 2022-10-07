import numpy as np
import cv2
from collections import deque

# color define
white = [255,255,255]
red = [0,0,255]
blue = [255,0,0]
green = [0,255,0]
black =[0,0,0]

img = cv2.imread('Image.png',cv2.IMREAD_COLOR)
# img = cv2.resize(img,(50,50))
img = cv2.resize(img,(100,100))

l,w,t = img.shape

# To get start and end point
switch1 = True
switch2 = True
for i in range(l):
    for j in range(w):
        if switch1:
            if (img[i,j] == red).all():
                start = (i,j)
                switch1 = False
        if switch2:
            if (img[i,j] == blue).all():
                end = (i,j)
                switch2 = False

def calcDist(point,current):
    return (point[0] - current[0])**2 + (point[1] - current[1])**2
    
def iswell(img,x,y):
    return (x>=0 and x<img.shape[0] and y >=0 and y<img.shape[1])
         
def dijkstra(img,start,end):
    h,w,t = img.shape
    dist = np.full((h,w), fill_value= np.inf)
    dist[start] = 0
    parent = np.zeros((h,w,2))
    visited = np.zeros((h,w))
    current = start
    visited[start] = 1
    while current != end:
        print(current)
        visited[current] = 1
        for i in range(-1,2):
            for j in range(-1,2):
                point = (current[0]+i,current[1]+j)
                if iswell(img,point[0],point[1]) and visited[point] != 2 and not (img[point][0] == white[0] and img[point][1] == white[1] and img[point][2] == white[2]):
                    if calcDist(point,current) + dist[current]  < dist[point]:
                        dist[point] = calcDist(point,current) + dist[current] 
                        # visited[point] = 1
                        parent[point[0],point[1]] = [current[0],current[1]]
        min = np.inf
        for i in range(h):
            for j in range(w):
                if min > dist[i,j] and visited[i,j] != 1:
                    min = dist[i,j]
                    current = (i,j)
        showPath(img,current,start,parent)   
            
def showPath(img,current,start,parent):
    new = np.copy(img)
    while current != start:
        var = int(parent[current][0]) , int(parent[current][1])
        
        new[int(var[0]),int(var[1])] = green
        current = (var[0],var[1])

    cv2.namedWindow('window',cv2.WINDOW_NORMAL)
    cv2.imshow('window',new)
    cv2.waitKey(1)
                    
# print(img[end])

dijkstra(img,start,end)

cv2.namedWindow('final', cv2.WINDOW_NORMAL)
cv2.imshow("final", img)
cv2.waitKey(0)

cv2.destroyAllWindows()