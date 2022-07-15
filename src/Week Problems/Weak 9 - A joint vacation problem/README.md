# <p align="center">A joint vacation problem</p>
### Description
This Summer you are going on vacations with some friends and you are planning the places to visit. You have already decided which place to start at and where you want your vacation to end. However, since you are on a tight budget you need to make sure that you spend the least amount of money possible, which means that you might not be able to visit all possible places. You have done the math and know exactly how much you will spend on traveling (on gas, tolls, etc.) from each place A to every other place B. The question now is: how inexpensive can you make your vacation?<br><br>
<img src=https://i.imgur.com/sfzfGEI.png />

##
### Input
The first line gives the number of places (n), and the id number of the place you are finish at (you always start at place 1). Then, n lines follow, each with the id of a place and the list of costs of travelling directly from that place to all others. If it is impossible to go directly from one place to the other, then the cost is -1.
##
### Output
The minimum possible cost of the vacation.
##
### Constraints
n ≤ 200
##
### Example
#### Example input:
6 6<br>
1 0 1 2 8 -1 -1<br>
2 -1 0 -1 -1 3 -1<br>
3 -1 -1 0 5 3 8<br>
4 -1 -1 -1 0 -1 12<br>
5 -1 -1 -1 -1 0 4<br>
6 -1 -1 -1 -1 -1 0
#### Example output:
8
