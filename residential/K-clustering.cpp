#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };
double dist(Point a, Point b) { return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); }

int main(){
    int n, k, iterations;
    cin >> n >> k >> iterations; // points, clusters, iterations
    vector<Point> points(n);
    for(int i=0;i<n;i++) cin >> points[i].x >> points[i].y;

    vector<Point> centroids(points.begin(), points.begin()+k);
    vector<int> labels(n);

    for(int it=0; it<iterations; it++){
        // Assign clusters
        for(int i=0;i<n;i++){
            double minDist = 1e9;
            for(int j=0;j<k;j++){
                double d = dist(points[i], centroids[j]);
                if(d < minDist){ minDist=d; labels[i]=j; }
            }
        }
        // Update centroids
        vector<int> count(k,0);
        vector<Point> newCentroids(k,{0,0});
        for(int i=0;i<n;i++){
            newCentroids[labels[i]].x += points[i].x;
            newCentroids[labels[i]].y += points[i].y;
            count[labels[i]]++;
        }
        for(int j=0;j<k;j++){
            if(count[j]>0){
                newCentroids[j].x /= count[j];
                newCentroids[j].y /= count[j];
            }
        }
        centroids = newCentroids;
    }

    for(int i=0;i<n;i++)
        cout<<"Point "<<i<<" -> Cluster "<<labels[i]<<"\n";

    return 0;
}
