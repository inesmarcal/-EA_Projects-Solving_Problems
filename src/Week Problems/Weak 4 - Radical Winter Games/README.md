# <p align="center">Radical Winter Games</p>
### Description
In a special winter edition of a popular TV game show, players were asked to ski down a hill and to collect flags on their way down. The flags were laid out in a triangular fashion on the hill side, and each flag had a number, an integer between 0 and 99, as illustrated below:

                       7
                    3     8
                 8     1     0
              2     7     4     4
           4     5     2     6     5
Starting at the top of the hill, players were able to ski downhill diagonally, either to the left or to the right, in order to collect the next flag. The player's score was the sum of the numbers in the flags collected.

Write a program to compute the highest score that can be achieved by a player in this game.
##
### Input
The first row indicates the number of test cases. Then, for each test case, the first row indicates the number of rows of the triangle. The following rows contain the triangle data aligned to the left as follows:<br>
7<br>
3 8<br>
8 1 0<br>
2 7 4 4<br>
4 5 2 6 5<br>
##
### Output
The output for each test case is a single number in a line.
##
### Example
#### Example nput
1<br>
5<br>
7<br>
3 8<br>
8 1 0<br>
2 7 4 4<br>
4 5 2 6 5<br>
#### Example output
30
