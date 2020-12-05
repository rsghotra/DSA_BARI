#include<iostream>
#include<queue>
using namespace std;
//graph is represented as adjacency matrix
const int SIZE = 8;

//vtx = starting vtx from where you would like to start the BFS travel

void BFS(int vtx, int M[][8], int n) {
    //initial steps
    queue<int> Q;
    int visited[8] {0};

    cout << vtx << " ";
    Q.push(vtx);
    visited[vtx] = 1;
    int u, v;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        //explore its children
        for(v=1; v < n; ++v) {
            if(M[u][v] == 1 && visited[v] == 0) {
                cout << v << " ";
                Q.push(v);
                visited[v] = 1;
            }
        }
    }
}



void DFS(int vtx, int M[][SIZE], size_t n) {
    static int visited[SIZE]{0};    
    //visit(print) -> Mark Visit -> Explore Adjacent Nodes
    if(visited[vtx] == 0) {
        cout << vtx << " ";
        visited[vtx] = 1;
        for(int j = 1; j < n;++j) {
            if(M[vtx][j] == 1 && visited[j] == 0) {
                DFS(j, M, n);
            }
        }
    }
}


int main() {
    int A[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}
    };

    cout << "\nBFS: Vertex: 1 -> " << flush;
    BFS(1, A, SIZE);

    cout << "\nBFS: Vertex: 4 -> " << flush;
    BFS(4, A, SIZE);

    cout << "\nDFS: Vertex: 1 -> " << flush;
    DFS(1, A, SIZE);
    cout << "\nDFS: Vertex: 4 -> " << flush;
    DFS(4, A, SIZE);

    return 0;

}
