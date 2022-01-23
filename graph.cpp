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

/* DFS
The Depth-First Traversal or the DFS traversal of a Graph is used to traverse a graph depth wise. That is, it in this traversal method, we start traversing the graph from a node and keep on going in the same direction as far as possible. When no nodes are left to be traversed along the current path, backtrack to find a new possible path and repeat this process until all of the nodes are visited.

We can implement the DFS traversal algorithm using a recursive approach. While performing the DFS traversal the graph may contain a cycle and the same node can be visited again, so in order to avoid this we can keep track of visited array using an auxiliary array. On each step of the recursion mark, the current vertex visited and call the recursive function again for all the adjacent vertices.
 */

void dfs (vector <int> adj[], int s, vector <bool> &visited) {
	cout << s << " ";
	visited[s] = true;
	for (int i: adj[s]) {
		if (visited[i] == false)
			dfs(adj, i, visited);
	}
}

// if graph is disconnected
void dfs_rec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            dfs_rec(adj,u,visited);
    }
}

int dfs_dis(vector<int> adj[], int V){
    bool visited[V]; 
	int count = 0;
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false) {
			count++;
            dfs_rec(adj,i,visited);
		}
    }
	return count;
}
// O(V+E)
/* each vertex is enqueued at most once, and hence dequeued at most once. The operations of enqueuing and dequeuing take O(1) time, and so the total time devoted to queue operations is O(V). Because the procedure scans the adjacency list of each vertex only when the vertex is dequeued, it scans each adjacency list at most once. Since the sum of the lengths of all the adjacency lists is Theta(E), the total time spent in scanning adjacency lists is O(E). The overhead for initialization is O(V),and thus the total running time of the BFS procedure is O(V+E). Thus, breadth-first search runs in time linear in the size of the adjacency-list representation of G. */

// shortest path in unweighted graph
// we use bfs since it traverses graph in shortest path manner

void shortestPathUnweighted (vector <int> adj[], int v, int s) {
	vector <bool> visited (v, false);
	queue <int> q;
	vector <int> distance (v, INT_MAX);

	distance[s] = 0;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i: adj[curr]) {
			if (visited[i] == false) {
				q.push(i);
				visited[i] = true;
				distance[i] = distance[curr] + 1;
			}
		}
	}

	for (int x: distance)
		cout << x << " ";
	cout << endl;
}

// detect cycle undirected graph
// can be done with both dfs and bfs
/* for every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not a parent of v, then there is a cycle in the graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle. */

bool detectCycleDFS_rec (vector <int> adj[], int s, int p, vector <bool> visited) {
	visited[s] = true;
	for (int i: adj[s]) {
		if (visited[i] == false) {
			if (detectCycleDFS_rec(adj, i, s, visited) == true)
				return true;
		} else if (i != p) {
			return true;
		}
	}
	return false;
}

bool detectCycleDFS (vector <int> adj[], int v) {
	vector <bool> visited (v, false);
	for (int i=0; i<v; i++) {
		if (!visited[i]) {
			if (detectCycleDFS_rec(adj, i, -1, visited) == true)
				return true;
		}	
	}
	return false;
}

// just maintain a parent array if you want to use bfs
bool detectCycleBFS (vector <int> adj[], int v, int s) {
	vector <bool> visited (v, false);
	vector <int> parent (v, -1);
	queue <int> q;

	visited[s] = true;
	q.push(s); 

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i: adj[curr]) {
			if (!visited[i]) {
				visited [i] = true;
				q.push(i);
				parent[i] = curr;
			} else if (i != parent[curr]) {
				return true;
			}
		}
		return false;
	}
}

// detect cycle in a directed graph usign dfs
// here we also maintain an additional array to keep track of vertices which are already in the recursion stack and if we visit them again during our recursive call then there is a loop

bool detectCycleDirected_dfsRec (vector <int> adj[], vector <bool> &visited, vector <bool> &rec, int s) {
	visited[s] = true;
	rec[s] = true;	// s is pushed to the stack

	for (int i: adj[s]) {
		if (visited[i] == false && detectCycleDirected_dfsRec(adj, visited, rec, i)) 
			return true;
		else if (rec[i] == true) 
			return true;	
	}
	rec[s] = false;	  // popped of the stack, is still marked visited
	return false;
}

bool detectCycleDirected_dfs (vector <int> adj[], int v) {
	vector <bool> visited (v, false);
	vector <bool> rec (v, false);

	for (int i=0; i<v; i++) {
		if (visited[i] == false && detectCycleDirected_dfsRec(adj, visited, rec, i))
			return true;
	}
	return false;
}
// O(V+E)

/* In computer science, a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. Precisely, a topological sort is a graph traversal in which each node v is visited only after all its dependencies are visited. A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG). Any DAG has at least one topological ordering, */

/* Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 
 

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighbouring nodes.
If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty. */

void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        cout<<u<<" "; 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
    } 
}

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
	addEdge(adj, 0, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 3, 4);
	printGraph(adj, V);

	// bfs(adj, V, 0);

	// vector <bool> visited (V+1, false);
	// dfs(adj, 0, visited);

	shortestPathUnweighted(adj, V, 0);
}