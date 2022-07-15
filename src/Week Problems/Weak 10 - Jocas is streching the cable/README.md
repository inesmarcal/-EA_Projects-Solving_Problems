# <p align="center">Jocas is streching the cable</p>
### Description
Jocas is now working in a telecomunication company as a network technician. He has to connect several computer networks with cable at the University of Coimbra but he wants to do it as cheap as possible, that is, using the least amount of cable.
The amount of cable to connect two nodes is given by the Euclidean distance between them, which can be implemented as follows:

	 (double) sqrt( fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2))
	
Note that each network that already exists is implemented as a tree, and the overall network structure to be built should also be a tree.
The following figure illustrates the idea.<br><br>
<img src=https://i.imgur.com/yp90uih.png /> <img src=https://i.imgur.com/nUyty4E.png />
            

<b>Maximum points:</b> 175

<b>Hint:</b> A tree does not contain cycles.
##
### Task
Given the current network structure, connect the different components such that the final network structure forms a tree and uses the least amount of cable. Note that the structure of each component, which is also a tree, cannot be modified.
##
### Input
The first line gives the number of nodes (n), numbered from 1 to n. Then, n lines follow, each with x and y coordinates (as integers) of the each node. The n+1-th line gives the number of existent connections (m) between pairs of nodes. Then, m+1 lines follow, each of which contains two integers corresponding to the two nodes that are connected. Other test cases may follow.
## 
### Output
Your program should output the mininum length of the new cable to be installed. The output should be rounded to two decimal places. For instance, use
	printf("%.2lf\n",amount)
	
where amount is the length of the cable.
##
### Constraints
n ≤ 750 and m ≤ 1000
##
### Example
#### Example input:
4<br>
103 104<br>
104 100<br>
104 106<br>
100 100<br>
1<br>
4 2<br>
4<br>
103 10<br>
104 100<br>
104 3<br>
100 9999<br>
1<br>
4 2<br>
	
#### Example output:
6.36<br>
97.08
