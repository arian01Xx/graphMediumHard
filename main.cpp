#include "solutionFive.hpp"
#include "printGraph.hpp"

int main(){

	SolutionFive solution5;
    int nFive=6; int distanceFive=2;
    vector<vector<int>> points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    int outFive=solution5.findTheCity(nFive,points,distanceFive);
    printVector2d(points);
    cout<<"Find The City problem: "<<endl;
    cout<<outFive<<endl;

	return 0;
}