#include "MST.h"
#include <iostream>
#include <list>
#include <stdio.h>
#include <array>
#include <stack>

MST::MST(float** input, int size) {
	adjacentMatrix = input;
	key = new int[size];   
  mstSet = new bool[size];  
	parent = new int[size];
  tsp = new int[size];
  parent_tsp = new int[size];
	N = size;
}

MST::~MST() {

}


//use Prim's algorithm or Kruskal algorithm. 
//Copied from'http://www.geeksforgeeks.org/greedy-
//algorithms-set-5-prims-minimum-spanning-tree-mst-2/'

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
		cout << parent[i] <<" - "<< i <<"  "<< 
    adjacentMatrix[i][parent[i]] << endl;
	}
}

//calculate mean of all edges in the MST
float MST::calMean(int option) {
	float mean = 0.0;
  float sum = 0.0;

  //For calculating the mean of the MST edge cost
	if(option == MST_1) {
    //find the total edge cost sum
    for(int index = 0; index < N; index++) {
        sum += key[index];
    }
		mean = sum ;	
  }

  //For calculating the mean of the TSP2 edge cost
  else if(option == TSP2) {
    //find the total edge cost sum
    for(int index = 0; index < N; index++) {
        sum += tsp[index];
    }
    mean = sum;
  }

  else if(option == TSP1_5) {}

	return mean;
}

//calculate standard deviation of all edges in the MST
float MST::calStd(int option) {
	float std = 0.0;
  float sum = 0.0;

	if(option == MST_1) {
		for(int index = 0; index < N; index++) {
        sum += key[index];
    }
    std = sum * sum;
  }

  else if(option == TSP2) {
    for(int index = 0; index < N; index++) {
        sum += tsp[index];
    }
    std = sum * sum;
  }
  else if(option == TSP1_5) {}
	return std;
}

void MST::makeTSP2() {

  //make a Eulerian tour by DFS
  bool *visited = new bool[N];
  //cout << endl;
  //cout << "Before" << endl;
  //cout << "Vertex - " << "Incoming edge weight" << endl;
  for(int index = 0; index < N; index++) {
    visited[index] = false;
    //cout << "KEY[" << index << "] - " << key[index] << endl;
  }
  //cout << endl;

  list<int> *path = new list<int>;


  stack<int> s;
  s.push(0);
  int curr;
 
  while(!s.empty()){
    curr = s.top();
    s.pop();
    path->push_back(curr);
    visited[curr] = true;

    for(int v = 0; v < N; v++) {
      if(parent[v]==curr && !visited[v]) 
        s.push(v);
    }
  }

  int pre = 0;
  for(list<int>::iterator i = path->begin(); i!=path->end(); i++){
    curr = *i;
    parent_tsp[curr] = pre;
    //cout << *i << " ";
    pre = curr;
  }
  parent_tsp[0] = pre;

  for(int i = 0; i < N; i++){
    tsp[i] = adjacentMatrix[i][parent_tsp[i]];
    
  }

  //cout << endl;
  //cout << "After" << endl;
  //cout << "Vertex - " << "Incoming edge weight" << endl;
  for(int index = 0; index < N; index++) {
    //cout << "KEY[" << index << "] - " << key[index] << endl;
  }
  //cout << endl;
	
  //call to local function calMean(2)
  //cout << "TSP2: "<< calMean(2) << endl;
}

void MST::printTSP2() {
  cout << endl;
  cout << endl;
  cout<<"TSP2"<<endl;
  //cout<<"Edge   Weight"<<endl;
  for (int i = 0; i < N; i++) {
    //cout << parent_tsp[i] <<" - "<< i <<"  "<< tsp[i] << endl;
  }
}

void MST::makeTSP1_5() {

  bool *visited = new bool[N];
  for(int index = 0; index < N; index++) {
    visited[index] = false;
  }

  //keep track of degrees of all vertices
  stack<int> s;

  for(int index = 0; index < N; index++) {
    cout << "KEY[" << index << "] - " << key[index] << endl;
    //x = the number of edges at key[index];
    //if(x % 2 != 0)
      //s.push(index);
  }
  


  //find all vertices of odd degrees
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
