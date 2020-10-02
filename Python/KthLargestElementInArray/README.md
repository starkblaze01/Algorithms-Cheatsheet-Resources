## Find the Kth Largest Element in the array

### Explanation: 
You are given an Array containing certain elements your task is to find the Kth (1st,2nd,3rd...) from the array

#### Input:
```py
$ 1 2 3 5 4
$ 2
```

#### Output:
```sh
$ The Kth Largest(2) element is: 4
```

#### Solution:
There can be multiple approaches for solving this problem however I'm explaining the best posible solution regarding time consumption

T- O(N + K*log(N)) where N is the number of elements in Array and K is the position of Kth Largest Element

* create a min heap out of given array and assign all values in negatives
* pop all nodes before k-1 elements
* finally pop the kth element and return it