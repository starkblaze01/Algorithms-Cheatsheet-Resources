## QR Generation using Householder matrix

#### Requirements

* [python3](https://www.python.org/downloads/)
* [numpy](https://pypi.org/project/numpy/)

#### How to run?

```py
$ python3 QR_decomposition.py
```

A prompt will show up 

* Enter the number of rows
* Enter the number of columns
* Make sure the number of rows >= columns

Using the input number of rows and columns a random matrix is generated which is then QR decomposed and the result is printed.


#### Example 

```sh
$ python3 QR_decomposition.py

Please enter the number of rows - 3

Please enter the number of columns - 3

Original Matrix
[[0.36998481 0.04720026 0.40415631]
[0.22602066 0.50157193 0.99947069]
[0.11852663 0.91833707 0.32616769]]

Q:
[[-0.823159  0.434521  0.365514]
[-0.502861 -0.258914 -0.824678]
[-0.263703 -0.862644  0.431631]]

R:
[[-0.449469 -0.533243 -0.921292]
[-0.       -0.901553 -0.364529]
[-0.        0.       -0.535733]]
```
