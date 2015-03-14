#include "common.h"
#include "point.h"
#include "MST.h"
#include "Minmatching/PerfectMatching.h"

/*
This project is a starter code and wrappers for CSE101W15 Implementation 
project.

point.h - uniform random pointset generator

MST.h - minimum spanning tree

PerfectMatching.h - interface to min cost perfect matching code 

-------------------------------------
PerfectMatching is from the paper:

Vladimir Kolmogorov. "Blossom V: A new implementation of a minimum cost 
perfect matching algorithm."

In Mathematical Programming Computation (MPC), July 2009, 1(1):43-67.

sourcecode : pub.ist.ac.at/~vnk/software/blossom5-v2.05.src.tar.gz

*/

void LoadInput(int& node_num, int& edge_num, int*& edges, int*& weights, 
										float** adjacentMatrix, int N) {
	int e = 0;
	node_num = N;
	edge_num = N*(N-1)/2 ; //complete graph

	edges = new int[2*edge_num];
	weights = new int[edge_num];

	for(int i = 0; i < N ; ++i) {
		for(int j = i+1 ; j< N ; ++j) {
			edges[2*e] = i;
			edges[2*e+1] = j;
			weights[e] = adjacentMatrix[i][j];
			e++;
		}
	}

	if (e != edge_num) { 
		cout<<"the number of edge is wrong"<<endl;

		exit(1); 
	}
}

void PrintMatching(int node_num, PerfectMatching* pm) {
	int i, j;

	for (i=0; i<node_num; i++) {
		j = pm->GetMatch(i);
		if (i < j) printf("%d %d\n", i, j);
	}
}

int main() {

	int W, H, N;

	set< pair<int,int> > generatedPointset1;
	set< pair<int,int> > generatedPointset2;
	set< pair<int,int> > generatedPointset3;
	set< pair<int,int> > generatedPointset4;

	float** adjacentMatrix1;
	float** adjacentMatrix2;
	float** adjacentMatrix3;
	float** adjacentMatrix4;
	
	Point pointset1;
	Point pointset2;
	Point pointset3;
	Point pointset4;

	//max(W,H,N) should be < 20000 because of memory limitation
	W = /*11588*/7;
	H = /*13772*/7;
	N = /*9824*/6;

	cout<<"W: "<<W<<" H: "<<H<<" N:"<<N<<endl;


	//pointset and adjacency matrix for graph 1
	pointset1.generatePoint(W, H, N); 
	pointset1.printPointset();
	generatedPointset1 = pointset1.getPointset();
	adjacentMatrix1 = pointset1.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 2
	pointset2.generatePoint(W, H, N); 
	//pointset2.printPointset();
	generatedPointset2 = pointset2.getPointset();
	adjacentMatrix2 = pointset2.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 3
	pointset3.generatePoint(W, H, N); 
	//pointset3.printPointset();
	generatedPointset3 = pointset3.getPointset();
	adjacentMatrix3 = pointset3.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset4.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset4 = pointset4.getPointset();
	adjacentMatrix4 = pointset4.getAdjacentMatrix();


	//Deliverable A: From pointset and adjacentMatrix -> MST
	MST mst1(adjacentMatrix1, N);
	//MST mst2(adjacentMatrix2, N);
	//MST mst3(adjacentMatrix3, N);
	//MST mst4(adjacentMatrix4, N);

	mst1.makeTree();
	//mst2.makeTree();
	//mst3.makeTree();
	//mst4.makeTree();

	
	mst1.printMST();
	

	//MST Mean Cost Calculation
 	//float totalMeanSum = mst1.calMean(1) +
 						 //mst2.calMean(1) +
 						 //mst3.calMean(1) +
 						 //mst4.calMean(1);

 	//hardcoded for 4 trials
 	//float totalMean = totalMeanSum / 4;

 	//MST STD Calculation
 	//float totalMSTSquaredSum = (mst1.calStd(1) +
 							   //mst2.calStd(1) +
 							   //mst3.calStd(1) +
 							   //mst4.calStd(1)) / 4;

    //float totalMSTStd =  sqrt(totalMSTSquaredSum - (totalMean * totalMean));


	
	//Deliverable B: Find TSP2 path from the constructed MST
	//You won't need any wrappers for B.
	//mst1.makeTSP2();
	//mst2.makeTSP2();
	//mst3.makeTSP2();
	//mst4.makeTSP2();

    //mst1.printTSP2();
    
	//TSP Mean Cost
    //float totalTSPMeanSum = mst1.calMean(2) +
 						 	//mst2.calMean(2) +
 						 	//mst3.calMean(2) +
 						 	//mst4.calMean(2);
 	//hardcoded for 4 trials
 	//float totalTSPMean = totalTSPMeanSum / 4;

 	/*TSP STD 
 	float squaredSum1 = mst1.calStd(2); 
 	float squaredSum2 = mst2.calStd(2);
 	float squaredSum3 = mst3.calStd(2);
 	float squaredSum4 = mst4.calStd(2);

 	float totalTSPSquaredSum = (squaredSum1 + squaredSum2 + 
 							squaredSum3 + squaredSum4) / 4;

 	float totalTSP2STD = sqrt(totalTSPSquaredSum-(totalTSPMean*totalTSPMean));
	*/

	//Deliverable C: Find TSP1.5 path from the constructed MST

    mst1.makeTSP1_5();
    //mst2.makeTSP1p5
    //mst3.makeTSP1p5
    //mst4.makeTSP1p5
	


 	//Print out the final result here. 
 	//Mean and STD of Deliverable A, B, and C. 

 	/*Print out the Mean!
 	cout << "[Mean]" << endl;
 	cout << "MST: " << totalMean << endl;
 	cout << "TSP2: " << totalTSPMean << endl;
 	cout << "TSP1p5: ur mom" << endl; 
 	cout << endl;

 	//Print out the STDs!
 	cout << "[STD]" << endl; 
 	cout << "MST: " << totalMSTStd << endl;
 	cout << "TSP2: " << totalTSP2STD << endl;
 	cout << "TSP1p5: ur mom" << endl;
 	cout << endl;
	*/


	//Find the perfect minimum-weight matching 
	struct PerfectMatching::Options options;
	int i, e, node_num = N, edge_num = N*(N-1)/2;
	int* edges;
	int* weights;
	PerfectMatching *pm = new PerfectMatching(node_num, edge_num);

	LoadInput(node_num, edge_num, edges, weights, adjacentMatrix1, N);

	for (e=0; e<edge_num; e++) {
		pm->AddEdge(edges[2*e], edges[2*e+1], weights[e]);
	}

	pm->options = options;
	pm->Solve();

	double cost=ComputePerfectMatchingCost(node_num,edge_num,edges,weights,pm);
	printf("Total cost of the perfect min-weight matching = %.1f\n", cost);
	
	PrintMatching(node_num, pm);

	delete pm;
	delete [] edges;
	delete [] weights;
	
	return 0;
}
