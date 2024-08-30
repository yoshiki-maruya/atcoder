#ifndef UNION_FIND_H
#define UNION_FIND_H

class UnionFind {
   public:
    int par[100009];
    int siz[100009];

    void init(int N) {
        for (int i = 1; i <= N; i++) {
            par[i] = -1;
        }
        for (int i = 1; i <= N; i++) {
            siz[i] = 1;
        }
    }

    int root(int x) {
        while (true) {
            if (par[x] == -1) {
                break;
            }
            x = par[x];
        }
        return x;
    }

    void unite(int u, int v) {
        int RootU = root(u);
        int RootV = root(v);

        if (RootU == RootV) {
            return;
        }

        if (siz[RootU] < siz[RootV]) {
            par[RootU] = RootV;
            siz[RootU] += siz[RootV];
        } else {
            par[RootV] = RootU;
            siz[RootV] += siz[RootU];
        }
    }

    bool same(int u, int v) {
        return root(u) == root(v);
    }
};

#endif