#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V = 4;
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Example graph
    dist[0][0] = 0; dist[0][1] = 5; dist[0][2] = INF; dist[0][3] = 10;
    dist[1][0] = INF; dist[1][1] = 0; dist[1][2] = 3; dist[1][3] = INF;
    dist[2][0] = INF; dist[2][1] = INF; dist[2][2] = 0; dist[2][3] = 1;
    dist[3][0] = INF; dist[3][1] = INF; dist[3][2] = INF; dist[3][3] = 0;

    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << "All pairs shortest path:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
