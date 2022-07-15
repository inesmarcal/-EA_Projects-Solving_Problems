# <p align="center">Zé Manel is setting up a computer network</p>
### Description
Zé Manel is now working as a computer engineer. His first job is to set up a computer network in a company. The network topology must be a tree, that is, the highest level of the network consists of a root node, which is connected to a single or multiple nodes in the level below by a point-to-point link. These lower level nodes are also connected to a single or multiple nodes in the next level down and so on.
In addition to the tree structure, there are some constraints that he must take into account:
1. In order to reduce costs, the amount of cable used should be the least possible.
2. The maximum number of point-to-point links from a node in the network is bounded by some value.

Therefore, given the cost of adding a feasible point-to-point link to each pair of network nodes, Zé Manel has to design the network with the tree topology that minimizes the cost and such that the number of point-to-point links that can be establish from each node does not exceed a given number.
##
### Input
Each test case starts with the number of network nodes (n), the number of feasible point-to-point links (m) and the maximum number of feasible point-to-point links for any node (k). Then, m lines follow. Each line contains three integers: the first two correspond to the network nodes IDs for which a point-to-point link can be established, and the third corresponds to the cost of establishing the link with cable. Note that your program cannot add a point-to-point link that is not considered to be feasible (for instance, breaking the tree structure or exceeding the bound on the number of allowed links). Also, any node can be the root.
##
### Output
Find the network as described above. In case there is no possibility of designing such network due to some constraint, the output should be "NO WAY!". Otherwise, output the minimum cost.
##
### Constraints
n ≤ 12<br>
m ≤ 40<br>
k ≤ n
##
### Example
#### Example input:
6 9 3<br>
1 2 1<br>
1 4 62<br>
1 6 99<br>
2 3 1<br>
2 6 34<br>
3 4 1<br>
3 5 13<br>
4 5 1<br>
5 6 99<br>
5 10 3<br>
1 2 70<br>
1 3 75<br>
1 4 62<br>
1 5 40<br>
2 3 25<br>
2 4 47<br>
2 5 14<br>
3 4 93<br>
3 5 5<br>
4 5 20<br>
6 6 3<br>
1 2 70<br>
1 3 23<br>
2 3 13<br>
4 5 43<br>
4 6 16<br>
5 6 45<br>
#### Example output:
38<br>
90<br>
NO WAY!<br>
