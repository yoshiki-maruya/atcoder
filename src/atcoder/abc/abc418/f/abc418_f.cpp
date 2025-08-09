#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>
#define Graph vector<vector<int>>
#define wGraph vector<vector<Edge>>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
        cout << i;
  }
*/
/* for (auto& x: X) {
        cin >> x;
    }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define zrep(i, n) for (int i = 0; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

#define INF INT_MAX
#define LINF LLONG_MAX

struct Point {
    ll x;
    ll y;
};

const ll MOD = 998244353;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

const int MAXN_COMB = 400005;
ll fact[MAXN_COMB];
ll invFact[MAXN_COMB];

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN_COMB; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

ll nCr_mod_p(int n, int r) {
    if (r < 0 || n < r) {
        return 0;
    }
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

struct Matrix {
    ll mat[2][2];
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix identity_matrix() {
    Matrix I;
    I.mat[0][0] = I.mat[1][1] = 1;
    return I;
}

Matrix calculate_matrix(int p1, int a1, int p2, int a2) {
    Matrix M;
    int len = p2 - p1;
    int k = a2 - a1;
    if (k < 0 || len <= 0) return M;
    M.mat[0][0] = nCr_mod_p(len - k, k);
    M.mat[0][1] = nCr_mod_p(len - 1 - k, k);
    M.mat[1][0] = nCr_mod_p(len - k, k - 1);
    M.mat[1][1] = nCr_mod_p(len - 1 - k, k - 1);
    return M;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int key;
    Matrix mat, prod;
    unsigned int priority;
    unique_ptr<Node> l, r;

    Node(int k, Matrix m) : key(k), mat(m), prod(m), priority(rng()), l(nullptr), r(nullptr) {}
};

void update_prod(Node* t) {
    if (!t) return;
    Matrix left_prod = t->l ? t->l->prod : identity_matrix();
    Matrix right_prod = t->r ? t->r->prod : identity_matrix();
    t->prod = multiply(right_prod, multiply(t->mat, left_prod));
}

void split(unique_ptr<Node> t, int key, unique_ptr<Node>& l, unique_ptr<Node>& r) {
    if (!t) {
        l = nullptr;
        r = nullptr;
        return;
    }
    if (t->key < key) {
        split(move(t->r), key, t->r, r);
        l = move(t);
    } else {
        split(move(t->l), key, l, t->l);
        r = move(t);
    }
    update_prod(l.get());
    update_prod(r.get());
}

unique_ptr<Node> merge(unique_ptr<Node> l, unique_ptr<Node> r) {
    if (!l || !r) return l ? move(l) : move(r);
    if (l->priority > r->priority) {
        l->r = merge(move(l->r), move(r));
        update_prod(l.get());
        return l;
    } else {
        r->l = merge(move(l), move(r->l));
        update_prod(r.get());
        return r;
    }
}

void insert(unique_ptr<Node>& t, unique_ptr<Node> item) {
    if (!t) {
        t = move(item);
        update_prod(t.get());
        return;
    }
    unique_ptr<Node> t1, t2;
    split(move(t), item->key, t1, t2);
    t = merge(move(t1), merge(move(item), move(t2)));
    update_prod(t.get());
}

void erase(unique_ptr<Node>& t, int key) {
    unique_ptr<Node> t1, t2, t3;
    split(move(t), key, t1, t2);
    split(move(t2), key + 1, t2, t3);
    t = merge(move(t1), move(t3));
    update_prod(t.get());
}

vector<ll> fib;
void precompute_fib(int n) {
    fib.resize(n + 3);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n + 2; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

    int n, q;
    cin >> n >> q;

    precompute_fib(n);

    map<int, int> checkpoints;
    checkpoints[0] = 0;

    unique_ptr<Node> treap_root = nullptr;
    
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        if (checkpoints.count(x)) {
            auto it = checkpoints.find(x);
            auto prev_it = prev(it);
            auto next_it = next(it);
            erase(treap_root, x);
            if (next_it != checkpoints.end()) {
                erase(treap_root, next_it->first);
                Matrix m = calculate_matrix(prev_it->first, prev_it->second, next_it->first, next_it->second);
                insert(treap_root, make_unique<Node>(next_it->first, m));
            }
            checkpoints.erase(it);
        }

        if (y != -1) {
            checkpoints[x] = y;
            auto it = checkpoints.find(x);
            auto prev_it = prev(it);
            auto next_it = next(it);
            
            if (next_it != checkpoints.end()) {
                erase(treap_root, next_it->first);
                Matrix m2 = calculate_matrix(x, y, next_it->first, next_it->second);
                insert(treap_root, make_unique<Node>(next_it->first, m2));
            }
            Matrix m1 = calculate_matrix(prev_it->first, prev_it->second, x, y);
            insert(treap_root, make_unique<Node>(x, m1));
        }
        
        Matrix total_m = treap_root ? treap_root->prod : identity_matrix();
        ll ways_t = total_m.mat[0][0];
        ll ways_c = total_m.mat[1][0];

        int last_p = checkpoints.rbegin()->first;
        int len_last = n - last_p;
        
        ll final_ans = (ways_t * fib[len_last + 2] + ways_c * fib[len_last + 1]) % MOD;
        cout << (final_ans + MOD) % MOD << endl;;
    }

    return 0;
}