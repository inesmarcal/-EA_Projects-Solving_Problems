# <p align="center">A new chess game</p>
### Description
You are working on a new chess computer game with an infinite chessboard and only knights. Of course, you cannot have an infinite chessboard because you don't have infinite RAM! But you can compute the largest chessboard that you need since you know the current location of the knights and how many moves they can do.

The goal is to know the number of distinct chessboard cells that can be visited by n knights after a given number of moves of each knight. You can assume that two or more knights can be in the same cell at the same time.

We remind you that a knight can perform 8 different moves, as shown in the picture below.<br><br>
<img src=https://i.imgur.com/lSTnzy1.jpg />

##
### Input
The first line indicates the number of knights (1 <= n <= 30). Then, n lines follow. Each line gives the position (x,y) of a knight in the chessboard as well as the number of moves m (0 <= m <= 7) that it is allowed to perform. You may assume that knights never travel beyond coordinates -200 to 200.
##
### Output
For each test case, print the number of distint cells that can be visited by the n knights.
##
### Example
#### Example input:
4<br>
-1 -1 2<br>
2 2 1<br>
3 3 3<br>
4 4 3<br>
#### Example output:
155
