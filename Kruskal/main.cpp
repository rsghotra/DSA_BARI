#include<iostream>
using namespace std;

/*

*/

const int E = 9;
const int V = 7;


int edges[3][E] {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18},
};

//size of set equals number of vertices + 1 as we are
//using zero
int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1};

//number of edges; using 1
int included[E] = {0};
//According to MST defination - if there will be V-1 edges
int t[2][V-1];


int find(int u) {
    while(set[u] > 0) {
        u = set[u];
    }
    return u;
}

void Union(int u, int v) {
    
    //find parent u and v
    int x = find(u);
    int y = find(v);

    if(x != y) {
        if(set[x] < set[y]) {
            set[x]=set[x] + set[y];
            set[y] = x;
        } else {
            set[y]=set[x] + set[y];
            set[x] = y;
        }
    }
}


void PrintMCST(){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << t[0][i] << "]-----[" << t[1][i] << "]" << endl;
    }
    cout << endl;
}

int main() {
    //kruskal chalega number of vertices tak'
    int i = 0; // traverse 2-D Edge Array - The INPUT
    int j; // traverse the 2-D Edge Array to find minimum
    int k; //marker which will be used to include in the array
    int u, v;
    int min;
    while(i < V - 1) {
        min = INT32_MAX;
        //I have to find minimum cost edge from edge 2D array
        for(j=0; j < E; ++j) {
            //pick up that edge which is not included in the included array and it is of minimum cost
            if(included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        //Now we have found the min cost edge in first iteration. Now, need to see if we can join them or not
        if(find(u) != find(v)) {
            //if they do not share parent then this edge can be included
            //Two things to do:
            //  1. Do Union of the two
            //  2. Update output
            Union(find(u), find(v));
            t[0][i] = u;
            t[1][i] = v;
            i++;
        }
        //mark the edge to be included
        included[k] = 1;
    }

    PrintMCST();
}