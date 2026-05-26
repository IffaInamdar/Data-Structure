#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int tsp(vector<vector<int> >&graph){
    int n = graph.size();
    vector<bool> visited(n,false);
    int total_cost = 0;
    int current_node = 0;
    visited[0] = true;

    for(int count = 1;count<n;count++){
        int next_node = -1;
        int min_cost = INT_MAX;
        for(int i = 0;i<n;i++){
            if(!visited[i]&& graph[current_node][i] !=0 &&graph[current_node][i]< min_cost){
                min_cost = graph[current_node][i];
                next_node = i;
            }
        }

        visited[next_node] = true;
        total_cost += min_cost;
        current_node = next_node;
    }
    total_cost += graph[current_node][0];
    return total_cost;
}

int main(){
    vector<vector<int> > graph = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    cout<<"Minimum cost of the tour :"<<tsp(graph)<<endl;
    return 0;
}