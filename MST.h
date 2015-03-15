#include "common.h"
#include <list>

#pragma once

class MST {
public:
	float** adjacentMatrix;
	int* parent; //Array to store constructed MST
	int* key; //Key values used to pick minimum weight edge in cut
	bool* mstSet; //To represent set of vertices not yet included in MST
  int* tsp;
  int* parent_tsp;
  int N; //the size of pointset
  int* degree;
  int* tsp15;
  int* parent_tsp15;
  float** minMatchEdgeSet;

	MST(float** adjacentMatrix, int size);
	~MST();

	//deliverable a
	void makeTree();
	void printMST();

	//deliverable b
	void makeTSP2();
	void printTSP2();
  //void DFS(int index, bool visited[]);

	//deliverable c
	void makeTSP1_5();
	bool in_edgeSet(int parent, int current, list<std::pair<int, int>> edge_set);
	bool all_visited(bool* visited);
	
	float calMean(int option);
	float calStd(int option);

private:
	list<std::pair<int, int>> minimumMatching(int *array/*, list<std::pair<int, int>>* edge_set*/);
	list<std::pair<int, int>> combine(list<std::pair<int, int>>);
	int minKey(int key[], bool mstSet[]);

};
