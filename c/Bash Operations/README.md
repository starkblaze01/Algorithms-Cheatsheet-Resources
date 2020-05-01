# Baisc bash operations implemented in C

## How to run:
```
$ gcc main.c
$ ./a.out
```

## Operations implemented:
-  ls : Display all files and folders
    - -l : display files/directories(not hidden) with permissions, size, last modified time etc
    - -a : display all files/directories(hidden inclusive) with permissions, size, last modified time etc

-  pwd : Dispaly current path

-  mkdir `<dir name>` : create a new directory with a supplied file name
    - -v : verbose
    - -p : create a directory with supplied absoute path

-  rmdir `<dir name>` : remove a directory with supplied dir name(if empty) 
    - -r : Force delete a directory through unlinking its contents
    - -v : verbose
    - -p : delete a directory with supplied absolute path

-  cd `<dir name>` : Change current directory to the supplied directory 
    - cd .. : Go to previous directory
    - cd : Go to home directory

-  exit: to exit

#### Note:
- There can be only single space between command name,parameters and tags(though leading or trailing white spaces in input command doesn't matter)
- There can be only single deletion/creation per command rmdir/mkdir respectively