#linear search
def linear_search(array,key):
           for i in range(len(array)):
                      if array[i]==key:
                                 return(i)
           else:
                      return(-1)

arr=[8,4,7,6,2,5]
key=5
i=linear_search(arr,key)
if i!=-1:
           print(key ,"is at index ",i)                          
else:
           print(key,"not found")
