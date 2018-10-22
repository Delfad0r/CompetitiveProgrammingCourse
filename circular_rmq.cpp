/*
A standard implementantion of a segment tree with lazy propagation.
The "circular" part is implemented by always making two queries/updates,
one in the range [b1, e1) and one in the range [b2,e2). When the given
interval does not wrap around, the second query/update is performed on
the empty range and does not have any effect.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL INF = 1LL << 60;

struct node_t {
    LL v, p;
};

void propagate(node_t& a, node_t& l, node_t& r) {
    l.v += a.p;
    l.p += a.p;
    r.v += a.p;
    r.p += a.p;
    a.p = 0;
}

node_t rt[1 << 19];

LL query(int b, int e, int n = 1, int l = 0, int r = 1 << 18) {
    if(e <= l or r <= b) {
        return INF;
    }
    if(b <= l and r <= e) {
        return rt[n].v;
    }
    propagate(rt[n], rt[2 * n], rt[2 * n + 1]);
    return min(query(b, e, 2 * n, l, (l + r) / 2), query(b, e, 2 * n + 1, (l + r) / 2, r));
}

void update(int b, int e, int v, int n = 1, int l = 0, int r = 1 << 18) {
    if(e <= l or r <= b) {
        return;
    }
    if(b <= l and r <= e) {
        rt[n].v += v;
        rt[n].p += v;
        return;
    }
    propagate(rt[n], rt[2 * n], rt[2 * n + 1]);
    update(b, e, v, 2 * n, l, (l + r) / 2);
    update(b, e, v, 2 * n + 1, (l + r) / 2, r);
    rt[n].v = min(rt[2 * n].v, rt[2 * n + 1].v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    for(int n = 0; n < N; ++n) {
        int a;
        cin >> a;
        update(n, n + 1, a);
    }
    int M;
    cin >> M;
    while(M--) {
        string str;
    	while(str.length() < 2) {
            getline(cin, str);
    	}
        stringstream stream(str);
        int b1, e1, v, b2, e2;
        stream >> b1 >> e1 >> v;
        ++e1;
        if(e1 <= b1) {
            e2 = e1;
            e1 = N;
            b2 = 0;
        } else {
            b2 = e2 = 0;
        }
        if(stream) {
            update(b1, e1, v);
            update(b2, e2, v);
        } else {
            cout << min(query(b1, e1), query(b2, e2)) << '\n';
        }
    }
}
