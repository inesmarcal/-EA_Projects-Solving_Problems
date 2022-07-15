# <p align="center">(Un)social network</p>
### Description
Nowadays, everybody knows many, many people. So much so, that the producers of a TV game show are finding it increasingly difficult to find enough people to take part in their show. Given a set of members of a social network, they want to know the size of the largest group of people such that none of its members know one another.

<img src=https://i.imgur.com/hNVG4aS.jpg/>

##
### Input
For each test case, the number of members, n, and the number of connections between members, m, are given in the first line, separated by white space. Then, in each of the next m lines, a pair of values, also separated by white space, indicates that two members of the network know each other. Members are numbered from 0 to n-1. Note that some members may not know anyone in the network.
##
### Output
The output for each test case consists of a single line with the maximum size of a group of members who do not know one another.
##
### Example
#### Example input 1:
6 6<br>
0 1<br>
0 2<br>
0 3<br>
0 4<br>
0 5<br>
1 5<br>
#### Example input 2:
30 21<br>
15 10<br>
6 25<br>
12 20<br>
17 20<br>
20 11<br>
18 4<br>
1 19<br>
5 22<br>
14 4<br>
24 13<br>
7 8<br>
21 24<br>
24 8<br>
11 18<br>
20 19<br>
0 16<br>
28 13<br>
16 10<br>
27 24<br>
22 16<br>
16 21<br>
#### Example output 1:

4
#### Example output 2:

19
