
# <p align="center">Party icebreaker</p>
### Description
To cellebrate its success, a new company throws a really big party. Everyone who is someone in town is invited. To help people get to know each other, each guest is given a card with a number (a positive integer) upon arrival, and asked to find two other guests in the crowd to form a group of three such that:
* there is at least one man and one woman in the group
* the sum of the numbers held by the two women (or two men) in the group is equal to the number held by the man (or woman, respectively).

The first group to meet these conditions will win 60.000€, or so say the party organizers...<br>
Since nobody could form such a group until the end of the party, some people demanded that all cards be collected to see whether the game was rigged so that the prize would not have to be paid. It is your job to find out whether, given the numbers handed out at the party, it was possible to win the game and claim the prize.
##
### Input
For each test case, the number of guests, n, is given in the first line, and each guest's number is given in the next n lines. To distinguish between men and women at the party, men's numbers were recorded as negative numbers, whereas women's numbers were recorded as positive. The end of the test case is indicated by a line containing "0". A new test case may then follow.
##
### Output
The output for each test case consists of a single line saying "Fair" if the game was fair and a winning group could indeed be found. Otherwise, the output must be "Rigged".
##
### Example
#### Example input:
8<br>
-1<br>
3<br>
5<br>
-2<br>
6<br>
2<br>
-5<br>
7<br>
0<br>
4<br>
-1<br>
-2<br>
1<br>
2<br>
0<br>
##
#### Example output:
Fair<br>
Rigged<br>
