#ifndef PRINT_GRAPH_HPP
#define PRINT_GRAPH_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>

//prim's algorithm
//floyd warshall's algorithm
//dijkstra's algorithm

using namespace std;

void printVector2d(vector<vector<int>> graph){
	cout<<"Graph Original: "<<endl;
	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

#endif