#include "MST.h"
#include <iostream>
#include <list>
#include <stdio.h>
#include <array>
#include <stack>

MST::MST(int** input, int size) {
	adjacentMatrix = input;
	key = new int[size];   
  mstSet = new bool[size];  
	parent = new int[size];
  tsp = new int[size];
	N = size;
}

MST::~MST() {

}


//use Prim's algorithm or Kruskal algorithm. 
//Copied from 'http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/'

void MST::makeTree() { 

     // Initialize all keys as INFINITE
     for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < N-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < N; v++)
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if adjacentMatrix[u][v] is smaller than key[v]
          if (adjacentMatrix[u][v] && mstSet[v] == false && adjacentMatrix[u][v] <  key[v])
             parent[v]  = u, key[v] = adjacentMatrix[u][v], tsp[v] =
               adjacentMatrix[u][v];
     }
}

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int MST::minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < N; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void MST::printMST() {
	cout<<endl;
	cout<<"Minimum spanning tree from the adjacency matrix"<<endl;
	cout<<"Edge   Weight"<<endl;
	for (int i = 1; i < N; i++) {
		cout << parent[i] <<" - "<< i <<"  "<< adjacentMatrix[i][parent[i]] << endl;
	}
}

//calculate mean of all edges in the MST
float MST::calMean(int option) {
	float mean = 0.0;
	if(option == MST_1) {

		//calculate ur mom
		int sum = 0;
		for(int i = 0; i < N; ++i) {
			sum = sum + key[i]; 
		}
		mean = sum / N;	
  }

  else if(option == TSP2) {}

  else if(option == TSP1_5) {}

	return mean;
}

//calculate standard deviation of all edges in the MST
float MST::calStd(int option) {
	float std = 0.0;

	if(option == MST_1) {
		//calculate
  }

  else if(option == TSP2) {}
  else if(option == TSP1_5) {}
	return std;
}

void MST::makeTSP2() {

  stack<int> s;
	//make a Eulerian tour by DFS
  bool *visited = new bool[N];
  for(int index = 0; index < N; index++) {
    visited[index] = false;
    cout << "CURRENT KEY: " << key[index] << endl;
  }

  //mark the the first node as visited
  visited[0] = true;
 
  s.push(0);
  int leaf = -1;
  while(!s.empty()) {
    //if (leaf != -1)
    //add current leaf edge, then set leaf = -1
    int curr = s.top();
    cout << s.top() << endl;
    s.pop();
    visited[curr] = true;
    if(leaf != -1) {
      parent[leaf] = curr;
      tsp[leaf] = adjacentMatrix[curr][leaf];
      leaf = -1;
    }

    int count = 0;
    for(int v = 0; v < N; v++) {
      if(adjacentMatrix[curr][v] == key[v] && !visited[v]) {
        s.push(v);
        count++;
      }
    }

    if(count == 0) 
      leaf = curr;
  }


  for(int i = 0; i < N; i++){
    cout << "Vertice " << i << " Weight " << tsp[i];
  }

  //starting from the very beginning...fasten your seatbelts
  //for(int index = 0; index < N; index++) {
   // if(visited[index] == false)

 // }


  /*Mark all vertices as not visited
  bool *visited = new bool[V];
  for(int index = 0; i < V; ++i)
    visited[index] = false;
*/
  

	//add shortcuts if a vertex has no detours.
  //cout << "MAKE TSP UR MOM" << endl;
	//calculate heuristic TSP cost
	
  //call to local function calMean(2)
  //cout << "TSP2: "<< calMean(2) << endl;
}

/*
 * COOL FUNCTION DAFUQ
 *
 *
void MST::DFS(int index, bool visited[]) {
  
  //Mark the current node as visited
  visited[index] = true;

  //Search for all vertices adjacent to this current node
  //how do we use the adjacency matrix to do this exactly?
  //
    
}*/


void MST::makeTSP1_5() {
	
	//construct minimum-weight-matching for the given MST
	minimumMatching();

	//make all edges has even degree by combining mimimum-weight matching and MST
	combine();

	//calculate heuristic TSP cost 
}

void MST::minimumMatching() { //if you choose O(n^2)
	//find minimum-weight matching for the MST. 
	
	//you should carefully choose a matching algorithm to optimize the TSP cost.
} 

void MST::combine() {
	//combine minimum-weight matching with the MST to get a multigraph which has vertices with even degree
}