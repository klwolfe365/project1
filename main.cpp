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
	set< pair<int,int> > generatedPointset5;
	set< pair<int,int> > generatedPointset6;
	set< pair<int,int> > generatedPointset7;
	set< pair<int,int> > generatedPointset8;
	set< pair<int,int> > generatedPointset9;
	set< pair<int,int> > generatedPointset10;
	set< pair<int,int> > generatedPointset11;
	set< pair<int,int> > generatedPointset12;
	set< pair<int,int> > generatedPointset13;
	set< pair<int,int> > generatedPointset14;
	set< pair<int,int> > generatedPointset15;

	float** adjacentMatrix1;
	float** adjacentMatrix2;
	float** adjacentMatrix3;
	float** adjacentMatrix4;
	float** adjacentMatrix5;
	float** adjacentMatrix6;
	float** adjacentMatrix7;
	float** adjacentMatrix8;
	float** adjacentMatrix9;
	float** adjacentMatrix10;
	float** adjacentMatrix11;
	float** adjacentMatrix12;
	float** adjacentMatrix13;
	float** adjacentMatrix14;
	float** adjacentMatrix15;
	
	Point pointset1;
	Point pointset2;
	Point pointset3;
	Point pointset4;
	Point pointset5;
	Point pointset6;
	Point pointset7;
	Point pointset8;
	Point pointset9;
	Point pointset10;
	Point pointset11;
	Point pointset12;
	Point pointset13;
	Point pointset14;
	Point pointset15;

	//max(W,H,N) should be < 20000 because of memory limitation
	W = 11588;
	H = 13772;
	N = 9824;

	cout<<"W: "<<W<<" H: "<<H<<" N:"<<N<<endl;


	//pointset and adjacency matrix for graph 1
	pointset1.generatePoint(W, H, N); 
	//pointset1.printPointset();
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

	//pointset and adjacency matrix for graph 4
	pointset5.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset5 = pointset5.getPointset();
	adjacentMatrix5 = pointset5.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset6.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset6 = pointset6.getPointset();
	adjacentMatrix6 = pointset6.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset7.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset7 = pointset7.getPointset();
	adjacentMatrix7 = pointset7.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset8.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset8 = pointset8.getPointset();
	adjacentMatrix8 = pointset8.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset9.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset9 = pointset9.getPointset();
	adjacentMatrix9 = pointset9.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset10.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset10 = pointset10.getPointset();
	adjacentMatrix10 = pointset10.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset11.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset11 = pointset11.getPointset();
	adjacentMatrix11 = pointset11.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset12.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset12 = pointset12.getPointset();
	adjacentMatrix12 = pointset12.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset13.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset13 = pointset13.getPointset();
	adjacentMatrix13 = pointset13.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset14.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset14 = pointset14.getPointset();
	adjacentMatrix14 = pointset14.getAdjacentMatrix();

	//pointset and adjacency matrix for graph 4
	pointset15.generatePoint(W, H, N); 
	//pointset4.printPointset();
	generatedPointset15 = pointset15.getPointset();
	adjacentMatrix15 = pointset15.getAdjacentMatrix();


	//Deliverable A: From pointset and adjacentMatrix -> MST
	MST mst1(adjacentMatrix1, N);
	MST mst2(adjacentMatrix2, N);
	MST mst3(adjacentMatrix3, N);
	MST mst4(adjacentMatrix4, N);
	MST mst5(adjacentMatrix5, N);
	MST mst6(adjacentMatrix6, N);
	MST mst7(adjacentMatrix7, N);
	MST mst8(adjacentMatrix8, N);
	MST mst9(adjacentMatrix9, N);
	MST mst10(adjacentMatrix10, N);
	MST mst11(adjacentMatrix11, N);
	MST mst12(adjacentMatrix12, N);
	MST mst13(adjacentMatrix13, N);
	MST mst14(adjacentMatrix14, N);
	MST mst15(adjacentMatrix15, N);



	mst1.makeTree();
	mst2.makeTree();
	mst3.makeTree();
	mst4.makeTree();
	mst5.makeTree();
	mst6.makeTree();
	mst7.makeTree();
	mst8.makeTree();
	mst9.makeTree();
	mst10.makeTree();
	mst11.makeTree();
	mst12.makeTree();
	mst13.makeTree();
	mst14.makeTree();
	mst15.makeTree();
	
	
	//mst1.printMST();
	

	//MST Mean Cost Calculation
 	float totalMeanSum = mst1.calMean(1) +
 						 mst2.calMean(1) +
 						 mst3.calMean(1) +
 						 mst4.calMean(1) +
 						 mst5.calMean(1) +
 						 mst6.calMean(1) +
 						 mst7.calMean(1) +
 						 mst8.calMean(1) +
 						 mst9.calMean(1) +
 						 mst10.calMean(1) +
 						 mst11.calMean(1) +
 						 mst12.calMean(1) +
 						 mst13.calMean(1) +
 						 mst14.calMean(1) +
 						 mst15.calMean(1);

 	//hardcoded for 4 trials
 	float totalMean = totalMeanSum / 15;

 	//MST STD Calculation
 	float totalMSTSquaredSum = (mst1.calStd(1) +
 							   	mst2.calStd(1) +
 							   	mst3.calStd(1) +
 							   	mst4.calStd(1) +
 							   	mst5.calStd(1) +
 							   	mst6.calStd(1) +
 							   	mst7.calStd(1) +
 							   	mst8.calStd(1) +
 							   	mst9.calStd(1) +
 							   	mst10.calStd(1) +
 							   	mst11.calStd(1) +
 							   	mst12.calStd(1) +
 							   	mst13.calStd(1) +
 							   	mst14.calStd(1) +
 							   	mst15.calStd(1)) / 15;

    float totalMSTStd =  sqrt(totalMSTSquaredSum - (totalMean * totalMean));


	
	//Deliverable B: Find TSP2 path from the constructed MST
	//You won't need any wrappers for B.
	mst1.makeTSP2();
	mst2.makeTSP2();
	mst3.makeTSP2();
	mst4.makeTSP2();
	mst5.makeTSP2();
	mst6.makeTSP2();
	mst7.makeTSP2();
	mst8.makeTSP2();
	mst9.makeTSP2();
	mst10.makeTSP2();
	mst11.makeTSP2();
	mst12.makeTSP2();
	mst13.makeTSP2();
	mst14.makeTSP2();
	mst15.makeTSP2();

    //mst1.printTSP2();
    
	//TSP Mean Cost
    float totalTSPMeanSum = mst1.calMean(2) +
 						 	mst2.calMean(2) +
 						 	mst3.calMean(2) +
 						 	mst4.calMean(2) +
 						 	mst5.calStd(2) +
 							mst6.calStd(2) +
 							   	mst7.calStd(2) +
 							   	mst8.calStd(2) +
 							   	mst9.calStd(2) +
 							   	mst10.calStd(2) +
 							   	mst11.calStd(2) +
 							   	mst12.calStd(2) +
 							   	mst13.calStd(2) +
 							   	mst14.calStd(2) +
 							   	mst15.calStd(2);
 	//hardcoded for 4 trials
 	float totalTSPMean = totalTSPMeanSum / 15;

 	//TSP STD 
 	float squaredSum1 = (mst1.calStd(2) +
 							mst2.calStd(2) +
 							mst3.calStd(2) +
 							mst4.calStd(2) +
 							mst5.calStd(2) +
 							mst6.calStd(2) +
 							mst7.calStd(2) +
 							mst8.calStd(2) +
 							mst9.calStd(2) +
 							mst10.calStd(2) +
 							mst11.calStd(2) +
 							mst12.calStd(2) +
 							mst13.calStd(2) +
 							mst14.calStd(2) +
 							mst15.calStd(2));
 


 	float totalTSPSquaredSum = (squaredSum1 / 15);
 	float totalTSP2STD = sqrt(totalTSPSquaredSum-(totalTSPMean*totalTSPMean));
	

	//Deliverable C: Find TSP1.5 path from the constructed MST

    mst1.makeTSP1_5();
    mst2.makeTSP1_5();
    mst3.makeTSP1_5();
    mst4.makeTSP1_5();
    mst5.makeTSP1_5();
    mst6.makeTSP1_5();
    mst7.makeTSP1_5();
    mst8.makeTSP1_5();
    mst9.makeTSP1_5();
    mst10.makeTSP1_5();
    mst11.makeTSP1_5();
    mst12.makeTSP1_5();
    mst13.makeTSP1_5();
    mst14.makeTSP1_5();
    mst15.makeTSP1_5();

    //TSP Mean Cost
    float totalTSP15MeanSum = mst1.calMean(3) +
 						 	  mst2.calMean(3) +
 						 	  mst3.calMean(3) +
 						 	  mst4.calMean(3) +
 						 	  mst5.calMean(3) +
 						 	  mst6.calMean(3) +
 						 	  mst7.calMean(3) +
 						 	  mst8.calMean(3) +
 						 	  mst9.calMean(3) +
 						 	  mst10.calMean(3) +
 						 	  mst11.calMean(3) +
 						 	  mst12.calMean(3) +
 						 	  mst13.calMean(3) +
 						 	  mst14.calMean(3) +
 						 	  mst15.calMean(3); 
 	//hardcoded for 4 trials
 	float totalTSP15Mean = totalTSP15MeanSum / 15;

 	//MST STD Calculation
 	float totalTSP15SquaredSum = (mst1.calStd(3) +
 							   	  mst2.calStd(3) +
 							   	  mst3.calStd(3) +
 							   	  mst4.calStd(3) +
 							   	  mst5.calStd(3) +
 							   	  mst6.calStd(3) +
 							   	  mst7.calStd(3) +
 							   	  mst8.calStd(3) +
 							   	  mst9.calStd(3) +
 							   	  mst10.calStd(3) +
 							   	  mst11.calStd(3) +
 							   	  mst12.calStd(3) +
 							   	  mst13.calStd(3) +
 							   	  mst14.calStd(3) +
 							   	  mst15.calStd(3)) / 15;

    float totalTSP15Std =  sqrt(totalTSP15SquaredSum - (totalTSP15Mean * totalTSP15Mean));
	

 	//Print out the final result here. 
 	//Mean and STD of Deliverable A, B, and C. 

 	//Print out the Mean!
 	cout << endl;
 	cout << endl;
 	cout << "[Mean]" << endl;
 	cout << "MST: " << totalMean << endl;
 	cout << "TSP2: " << totalTSPMean << endl;
 	cout << "TSP1p5: " << totalTSP15Mean << endl; 
 	cout << endl;

 	//Print out the STDs!
 	cout << "[STD]" << endl; 
 	cout << "MST: " << totalMSTStd << endl;
 	cout << "TSP2: " << totalTSP2STD << endl;
 	cout << "TSP1p5: " << totalTSP15Std << endl;
 	cout << endl;
	


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
