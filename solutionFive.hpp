#ifndef SOLUTION_FIVE_HPP
#define SOLUTION_FIVE_HPP

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

class SolutionFive{
public:
	//algoritmo de floyd-warshall
	int n, distanceThreshold;
	int dist[100][100];

	void FW(vector<vector<int>>& edges){ //cada uni vector cuenta con 3 elementos
		fill(&dist[0][0], &dist[0][0]+100*100, 1e9);
		for(int i=0; i<n; i++){
			dist[i][i]=0; //1 1 2 2 3 3
			//distancia de un nodo hacia si mismo es cero
		}
		//primera dibujada de dist
		for(auto& e: edges){
			int u=e[0], v=e[1], w=e[2];
			if(w<=distanceThreshold){
				//de esta forma se dibuja la matriz
				dist[u][v]=dist[v][u]=w;
				//este void llena la matriz dist con las ciudades con menos peso
			}
		}
		//main loop - actualizacion de dist
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
					//de esta forma se exploran caminos...
				}
			}
		}
	}
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
		this->n=n;
		this->distanceThreshold=distanceThreshold;
		FW(edges);
		int min_cnt=n, city=-1; 
		for(int i=0; i<n; i++){
			int cnt=-1;
			for(int j=0; j<n; j++){
				if(dist[i][j]<=distanceThreshold){
					cnt++;
				}
			}
			if(cnt <= min_cnt){
				min_cnt=cnt;
				city=i;
			}
		}
		return city;
	}
};

#endif