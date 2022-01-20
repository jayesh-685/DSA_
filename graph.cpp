#include "bits/stdc++.h"
using namespace std;

/* A Graph is a data structure that consists of the following two components:
A finite set of vertices also called nodes.
A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(digraph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.
Directed Graphs: The Directed graphs are such graphs in which edges are directed in a single direction.
Undirected Graphs: Undirected graphs are such graphs in which the edges are directionless or in other words bi-directional. That is, if there is an edge between vertices u and v then it means we can use the edge to go from both u to v and v to u.

no of edges in a directed graph = sum of indegrees or sum of out degrees.
Maximum no of edges in directed graph = v * (v-1) 
For a undirected graph, sum of degrees is twice the no of edges and maximum no of edges is (v*(v-1)/2) */