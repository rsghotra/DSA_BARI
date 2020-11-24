#include<iostream>
#include<queue>
using namespace std;

/*
    - Adjacency Matrix Implementation of DFS of Undirected Graph
    - Recursive
    - Similar to PREORDER OF TREE
*/

void DFS(int vtx, int M[][8], int rows) {
    static int Visited[8] = {0};
    if(Visited[vtx] != 0) {
        return;
    } else {
        cout << vtx << " " << flush;
        Visited[vtx] = 1;
        for(int v = 1; v <8; v++) {
            if(M[vtx][v] == 1 && Visited[v] == 0) {
                DFS(v, M, 8);
            }
        }
    }
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
    DFS(4, M, 8);
    cout << endl;
    //CAN'T RUN TWICE BECAYSE STATIC ARRAY IS FULL
    return 0;
}