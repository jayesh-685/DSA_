#include "bits/stdc++.h"
using namespace std;

/* A Graph is a data structure that consists of the following two components:
A finite set of vertices also called nodes.
A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(digraph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.
Directed Graphs: The Directed graphs are such graphs in which edges are directed in a single direction.
Undirected Graphs: Undirected graphs are such graphs in which the edges are directionless or in other words bi-directional. That is, if there is an edge between vertices u and v then it means we can use the edge to go from both u to v and v to u.

no of edges in a directed graph = sum of indegrees or sum of out degrees.
Maximum no of edges in directed graph = v * (v-1) 
For a undirected graph, sum of degrees is twice the no of edges and maximum no of edges is (v*(v-1)/2) 

Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex 'u' to vertex 'v' are efficient and can be done O(1).

finding all vertices adjacent to u: Theta(v)
finding degree of u: Theta(v)

Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.
*/

// adjacency matrix implementation
class Graph {
  private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
};

/* Adjacency List: Graph can also be implemented using an array of lists. That is every index of the array will contain a complete list. Size of the array is equal to the number of vertices and every index i in the array will store the list of vertices connected to the vertex numbered i. Let the array be array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above example undirected graph. */
/* space required for undirected graph = Theta(V+2*E) and for directed graph Theta(V+E)
Checking if there is an edge from u to v and removing a edge is Theta(V) operation
Finding degree of u and adding a edge is a Theta(1) operation
Finding all adjacent of u is theta(degree(u)) operation */

// adjacency list implementaion

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

/* The Breadth First Traversal or BFS traversal of a graph is similar to that of the Level Order Traversal of Trees.

The BFS traversal of Graphs also traverses the graph in levels. It starts the traversal with a given vertex, visits all of the vertices adjacent to the initially given vertex and pushes them all to a queue in order of visiting. Then it pops an element from the front of the queue, visits all of its neighbours and pushes the neighbours which are not already visited into the queue and repeats the process until the queue is empty or all of the vertices are visited.

The BFS traversal uses an auxiliary boolean array say visited[] which keeps track of the visited vertices. That is if visited[i] = true then it means that the i-th vertex is already visited.

Complete Algorithm:
Create a boolean array say visited[] of size V+1 where V is the number of vertices in the graph.
Create a Queue, mark the source vertex visited as visited[s] = true and push it into the queue.
Until the Queue is non-empty, repeat the below steps:
Pop an element from the queue and print the popped element.
Traverse all of the vertices adjacent to the vertex poped from the queue.
If any of the adjacent vertex is not already visited, mark it visited and push it to the queue. */

void bfs (vector <int> adj[], int v, int s) {
	vector <bool> visited (v+1, false);
	queue <int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for (int x: adj[curr]) {
			if (visited[x] == false) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

// if no source is given and graph may be disconnected

void bfs (vector <int> adj[], int v, int s, vector <bool> &visited) {
	queue <int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for (int x: adj[curr]) {
			if (visited[x] == false) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

// we also calculate no of islands in the graph (no of connected components)
int bfs_dis (vector <int> adj[], int v) {
	int count=0;
	vector <bool> visited (v+1, false);
	for (int i=0; i<v; i++) {
		if (visited[i] == false) {
			count++;
			bfs(adj, v, i, visited);
		}
	}
	return count;
}
// O(V+E)   // v is also included because of corner case where all vertices are disconnected
// can find shortes path for unweighted graphs


int main() {
	// Graph g(4);

	// g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(1, 2);
	// g.addEdge(2, 0);
	// g.addEdge(2, 3);

	// g.toString();

	int V = 5;
	// array of vectors
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);

	bfs(adj, V, 0);
}