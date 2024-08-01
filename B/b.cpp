#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <cmath>  

using namespace std;

struct Star {
    int x, y;
    int id;
};

struct Edge {
    int u, v;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]); // 路径压缩  
    }
    return parent[i];
}

void unionSets(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

double distance(const Star& s1, const Star& s2) {
    return sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2));
}

double kruskalMST(vector<Star>& stars, int N) {
    vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edges.push_back({ i, j, distance(stars[i], stars[j]) });
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(N);
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    double totalWeight = 0;
    int connectedComponents = N;

    for (const auto& edge : edges) {
        if (connectedComponents == 1) break; // 如果所有星星都已连接，则停止  
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unionSets(parent, edge.u, edge.v);
            totalWeight += edge.weight;
            --connectedComponents;
        }
    }

    if (connectedComponents != 1) {
        throw runtime_error("The stars cannot be connected into a single component.");
    }

    return totalWeight;
}

int main() {
    int N;
    cin >> N;
    vector<Star> stars(N);
    for (int i = 0; i < N; ++i) {
        cin >> stars[i].x >> stars[i].y;
        stars[i].id = i; // 只是为了方便调试，实际不需要  
    }

    try {
        double minCost = kruskalMST(stars, N);
        cout << "The minimum cost to connect all stars is: " << minCost << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}