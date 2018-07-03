//#include GFUENTES97 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
 
using namespace std;
 
 
typedef pair<double, int> ArcP;
typedef vector< vector<ArcP> > GrafP;
 
int const INFINITY = numeric_limits<int>::max();
 
void dijkstra(const GrafP &G, int x, int y, vector<int> &d,
                     vector<int> &p) {
 
    int n = G.size();
    d = vector<int>(n, INFINITY);
    d[x] = 0;
    p = vector<int>(n, -1);
    vector<bool> S(n, false);   
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push(ArcP(0, x));
    int l = 0;
    while (not Q.empty()) {
        int u = Q.top().second;
        Q.pop();
 
        if (not S[u]) {
            S[u] = true;
            if (u == y) return;
            int m = G[u].size();
            for (int i = 0; i < m; ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v], v));
                }
            }
        }
    }
}
 
void leer_tripletes(GrafP &G, int m) {
    int aux;
    ArcP arco;
    for (int i = 0; i < m; i++) {
        cin >> aux >> arco.second >> arco.first;
        G[aux].push_back(arco);
    }
}
 
void mostrar_camino(const vector<int> &p, int x, int y) {
    stack<int> pila;
    while (y != x) {
        pila.push(y);
        y = p[y];
    }
    pila.push(y);
 
    bool primer = true;
    while(not pila.empty()) {
        if (primer) cout << pila.top();
        else cout << ' ' << pila.top();
        primer = false;
        pila.pop();
    }
    cout << endl;
}
 
int main() {
        int n;
        int m;
        while (cin >> n >> m) {
            GrafP G(n);
            leer_tripletes(G, m);
            vector<int> d;
            vector<int> p;  
 

            int x, y;
            cin >> x >> y;
            vector<int> camino;
            dijkstra(G, x, y, d, p);
            if (d[y] != INFINITY) mostrar_camino(p, x, y);
            else cout << "no path from " << x << " to " << y << endl;
        }
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */