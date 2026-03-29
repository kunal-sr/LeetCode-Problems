#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w, upgraded;
};

bool cmp(Edge &a, Edge &b) {
    return max(a.w, a.upgraded) > max(b.w, b.upgraded);
}

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int maxStability(int n, vector<Edge>& edges, int k) {
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    int used = 0;
    long long total = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            if (k > 0 && e.upgraded > e.w) {
                total += e.upgraded;
                k--;
            } else {
                total += e.w;
            }
            used++;
            if (used == n - 1) break;
        }
    }

    return total;
}

int main() {
    int n = 4, k = 1;

    vector<Edge> edges = {
        {0,1,5,10},
        {1,2,4,8},
        {2,3,3,6},
        {0,3,2,7}
    };

    cout << "Max Stability: "
         << maxStability(n, edges, k) << endl;

    return 0;
}
