#include "MST.h"
#include <iostream>
#include <list>
#include <stdio.h>
#include <array>
#include <stack>
#include <queue>





MST::MST(float** input, int size) {
	adjacentMatrix = input;
	key = new int[size];   
  mstSet = new bool[size];  
	parent = new int[size];
  tsp = new int[size];
  parent_tsp = new int[size];
	N = size;
  degree = new int[size];
  tsp15 = new int[size];
  parent_tsp15 = new int[size];
  minMatchEdgeSet = (float**)calloc(N, sizeof(float *));

  for(int i=0; i<N ; ++i) {
    minMatchEdgeSet[i] = (float*)calloc(N, sizeof(float));
  }


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
     key[0] = 0;  // Make key 0 so that this vertex is first vertex
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
             parent[v]  = u, key[v] = adjacentMatrix[u][v], tsp[v] = adjacentMatrix[u][v];

           //cout << degree[v] << endl;
     }
     for(int i = 0; i < N; i++){
        if(parent[i] != -1){
          degree[i]++;
          degree[parent[i]]++;
        }
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

  else if(option == TSP1_5) {
    for(int index = 0; index < N; index++) {
        sum += tsp15[index];
    }
    /*for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {

        sum += minMatchEdgeSet[i][j];
      }
    }*/
    mean = sum;
  }

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

  else if(option == TSP1_5) {
    for(int index = 0; index < N; index++) {
        sum += tsp15[index];
    }
    std = sum * sum;
  }
	return std;
}

void MST::makeTSP2() {

  //make a Eulerian tour by DFS
  bool *visited = new bool[N];
  for(int index = 0; index < N; index++) {
    visited[index] = false;
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

}

void MST::printTSP2() {
  cout << endl;
  cout << endl;
  cout<<"TSP2"<<endl;
  cout<<"Edge   Weight"<<endl;
  for (int i = 0; i < N; i++) {
    cout << parent_tsp[i] <<" - "<< i <<"  "<< tsp[i] << endl;
  }
}

void MST::makeTSP1_5() {

  bool *visited = new bool[N];
  /*for(int index = 0; index < N; index++) {
    visited[index] = false;
  }*/
  int *odd_vertices = new int[N];

  //cout << "Vertex  -  Degree" << endl;
  for(int i = 0; i < N; i++) {
    if(degree[i] % 2 != 0) {
      odd_vertices[i] = i;
      //cout << i << " - " << degree[i] << endl; 
    }
    else
      odd_vertices[i] = -1;
  }

  //find all vertices of odd degrees
	//construct minimum-weight-matching for the given MST
  list<std::pair<int, int>> edge_set;
	edge_set = minimumMatching(odd_vertices/*, edge_set*/);
  //cout << "RETURNED FROM FUNCTION" << endl;

  /*for(list<std::pair<int, int>>::iterator it = edge_set.begin(); it != edge_set.end(); it++){
    cout << "U: " << (*it).first << " V: " << (*it).second << " Edge Weight: " << 
        adjacentMatrix[(*it).first][(*it).second] << endl;
  }*/

	//make all edges have even degree by combining mimimum-weight matching 
  //and MST
	edge_set = combine(edge_set);
 // cout << "\nIN TSP1_5: " << endl;
  /*for(list<std::pair<int, int>>::iterator it = edge_set.begin(); it != edge_set.end(); it++){
    cout << "U: " << (*it).first << " V: " << (*it).second << " Edge Weight: " << 
        adjacentMatrix[(*it).first][(*it).second] << endl;
  }*/

	/*calculate heuristic TSP cost 
  int sum = 0;

  for(int i = 0; i < N; i++) {

    for(int j = 0; j < N; j++) {

      sum += minMatchEdgeSet[i][j];
    }
  }*/



  for(int index = 0; index < N; index++) {
    visited[index] = false;
    //cout << "KEY[" << index << "] - " << key[index] << endl;
  }
  //cout << endl;
  list<int> *path = new list<int>;
  stack<int> s;
  s.push(0);//first key in edge set, then for all edges in edge set whose parent is x
  int curr;
 
  while(!s.empty()){
    curr = s.top();
    s.pop();
    path->push_back(curr);
    visited[curr] = true;

    for(int v = 0; v < N; v++) {
      if(!visited[v] && (minMatchEdgeSet[curr][v]>0 || minMatchEdgeSet[v][curr]>0)) 
        s.push(v);
    }
  }
  int pre = 0;
  list<int>::iterator i = path->begin();
  //curr = i*;
  //int first = *i;
  
  path->unique();

  for(i=path->begin(); i!=path->end(); i++) {
    curr = *i;
    parent_tsp15[curr] = pre;
    cout << *i << " ";
    pre = curr;
  }
  parent_tsp15[0] = pre;

  for(int i = 0; i < N; i++){
    tsp15[i] = adjacentMatrix[i][parent_tsp15[i]];
    
  }
}

bool MST::in_edgeSet(int parent, int current, list<std::pair<int, int>> edge_set){
  for(list<std::pair<int, int>>::iterator it = edge_set.begin(); it != edge_set.end(); it++){
    if(((*it).first == parent && (*it).second == current) || ((*it).first == current && (*it).second == parent)){
      return true;
    }
  }
  return false;
}


list<std::pair<int, int>> MST::minimumMatching(int *array/*, list<std::pair<int, int>>* ret*/) { //if you choose O(n^2)
  //find minimum-weight matching for the MST. 
	/* iterate through the list
   * first elem = i
   * continue iteration -- it* , compare dist, find min, */
	//you should carefully choose a matching algorithm to optimize the TSP cost.
  int count = 0;
  bool *edges = new bool[N];
  for(int i = 0; i < N; i++)
    edges[i] = false;
  std::priority_queue<std::pair<std::pair<int, int>, int>> pq;
  for(int i = 0; i < N; i++) {
    if(array[i] != -1) {
      for(int j = 0; j < N; j++) {
        if(array[j] != -1 && adjacentMatrix[i][j]!=0) {


          pq.push(std::make_pair(std::make_pair(i,j), -adjacentMatrix[i][j]));
            count++;
            //cout << count << " ";
            //cout << "Vertex U: " << i << " Vertex V: " << j << 
            //" Edge Value: " << adjacentMatrix[i][j] << endl;
        } 
      } //end inner for loop
    }
  } //end outer for loop

  //list that holds a vertex pair and edge value
  list<std::pair<int, int>> ret;
  std::pair<std::pair<int, int>, int> curr;
  
  while(!pq.empty()){
    curr = pq.top();
    pq.pop();

    //make sure that the value is orignally null otherwise there is something there!!
    if(!edges[curr.first.first] && !edges[curr.first.second]) {

      ret.push_back(make_pair(curr.first.first, curr.first.second));
      edges[curr.first.first] = true;
      edges[curr.first.second] = true;
    }
  }
  return ret;
} 

list<std::pair<int, int>> MST::combine(list<std::pair<int, int>> edge_set) {
	//combine minimum-weight matching with the MST to get a multigraph 
  //which has vertices with even degree
  bool *visited = new bool[N];
  for(int index = 0; index < N; index++) {
    visited[index] = false;
  }

  stack<int> s;
  s.push(0);
  int curr;
  //Add edges in edge_set to minMatchEdgeSet
  for(list<std::pair<int,int>>::iterator i = edge_set.begin(); i!=edge_set.end(); i++){
    minMatchEdgeSet[(*i).first][(*i).second] = adjacentMatrix[(*i).first][(*i).second];
  }
  //Add edges in MST to minMatchEdgeSet
  while(!s.empty()){
    curr = s.top();
    s.pop();

    if(parent[curr]>=0) {
      minMatchEdgeSet[parent[curr]][curr]=adjacentMatrix[parent[curr]][curr];
      edge_set.push_back(std::make_pair(curr, parent[curr]));
      visited[curr] = true;
    }

    for(int v = 0; v < N; v++) {
      if(parent[v]==curr)// && !visited[v]) 
        s.push(v);
    }
    
  }
  /*cout << "minimum edge matching matrix: " << endl;
    for(int u = 0; u < N; u++) {

      for(int v = 0; v < N; v++) {
        cout << minMatchEdgeSet[u][v] << "  ";
      }
      cout << endl;
    }*/

  return edge_set;

}
