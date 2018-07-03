//#include GFUENTES97 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<double, int> WArc;
typedef vector<vector<WArc> > WGraph;
int n,m;

void readGraph(WGraph &G, int m){
	for (int i = 0; i < m; ++i)
	{
		int x;
		WArc arc;
		cin >> x >> arc.second >> arc.first;
		G[x].push_back(arc);
	}
}

void dijkstra(const WGraph &G, int s, int y, vector<double>& d, vector<int> &p, int &distancia){
	vector<bool> S(n, false);
	priority_queue<WArc, vector<WArc>, greater<WArc> >Q;
	Q.push(WArc(0,s));
	while(not Q.empty()){
		int u = Q.top().second; Q.pop();
		if(not S[u]){
			S[u] = true;
			if(u==y) {distancia = d[u]; return;}
			for(int i = 0; i<G[u].size(); ++i){
				WArc a = G[u][i];
				int v = a.second;
				double c = a.first;
				if(d[v] > d[u] + c){
					d[v] = d[u]+c;
					p[v] = u;
					//if(v == y) {if(d[v] < distancia or distancia == 0) distancia = d[v];}
					Q.push(WArc(d[v], v));
				}
			}
		}
		
	}
}

void mostraGraph(const WGraph &G){
	for(int i = 0; i<n; ++i){
		cout << i << " -> ";
		for(int j = 0; j<G[i].size(); ++j){
			WArc a = G[i][j];
			cout << "(" << a.first << ")" << a.second << " ";
		}
		cout << endl;
	}
}

int main(){
	
	while(cin >> n >> m){
		WGraph G(n);
		readGraph(G, m);
		int x,y;
		cin >> x >> y;
		vector<double> d(n, 200000);
		d[x] = 0;
		vector<int> p(n, -1);
		int dist = -1;
		dijkstra(G, x, y, d, p, dist);
		if(dist != -1) cout << dist << endl;
		else cout << "no path from " << x << " to " << y << endl; 
	}
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */