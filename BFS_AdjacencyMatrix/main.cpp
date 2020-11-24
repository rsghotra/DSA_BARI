#include<iostream>
#include<queue>
using namespace std;

/*
    - Adjacency Matrix Implementation of BFS of Undirected Graph
    - Imagine a 2D array to from top - down. 1x1 array is Top-Down; Not Left-Right
    - we always send cols in TWO D array. Row is what we used to send it before
*/

void BFS(int vtx, int M[][8], int rows) {
    //variables
    int u; //repreesenting rows
    int v; //representing cols
    //setup
    queue<int> Q;
    int Visited[8] = {0};

    //Initial Step
    cout << vtx << " ";
    Q.emplace(vtx);
    Visited[vtx] = 1;

    //iterative steps + Visiting node;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        //visite adjacent vertices
        for(v = 1; v <= 8; v++) {
            //watch out = node must also be non-visited
            if(M[u][v] == 1 && Visited[v] == 0) {
                cout << v << " ";
                Visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}


int main() {
    //Size of Adjacenty Matrix: Depends on Number of Vertexes: NxN
    int M[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 1 -> " << flush;
    BFS(1, M, 8);
    cout << "Vertex: 4 -> " << flush;
    BFS(4, M, 8);
    return 0;
}