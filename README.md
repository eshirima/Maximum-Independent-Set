# Maximum-Independent-Set

Introduction to Graph Algorithms
Spring 2016
# Project Problem
The Maximum Independent Set problem is a classical problem in computer
science. It asks, given a graph G = (V, E), for the largest set S ⊂ V of vertices
such that no two vertices in S are adjacent, i. e., for all u, v ∈ S, uv /∈ E.
The problem is well studied and there are a lot of approaches to solve it.
However, there is no efficient algorithm known to find an optimal solution for
this problem and most computer scientist believe that such an algorithm does
not exist.

# What to Do
Implement an algorithm which finds a preferably large set of independent
vertices (i. e., vertices which are not adjacent to each other) in a given graph.
Your program does not need to find an optimal solution.
To get started, have a look in the Maximum Clique problem and Minimum
Vertex Cover problem. Both problems are closely related to the Maximum
Independent Set problem. Feel free to implement an existing algorithm or to
develop your own heuristic. For your final submission, write up to one page
explaining the main idea behind your algorithm.

# Program
For a given input, you program has a maximal runtime of 30 seconds. You can
use the languages C#, C++, Java, or Python (one of them). Do not use third party
libraries. Keep your code simple, clean, and readable, and keep the number of
files small. I recommend that you use a git-repository and send me the link.

# Input
The input will be given as text (UTF-8) over the standard-input. The first line will
contain an integer n which states the number of vertices. After this, there will
be n lines. Each line represents one vertex. It contains the number of neighbours
of this vertex followed by the list of neighbours (0-based indices).

# Example.
4
3 1 2 3
1 0
1 0
1 0
0
1
3 2

# Output
Write an ordered list of vertex indices as text to the standard-output (separated
by space). For example, for the graph given above, the output for the optimal
solution would be
1 2 3
