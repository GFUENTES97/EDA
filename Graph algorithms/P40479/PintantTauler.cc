#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<vector<char> > tauler;
typedef pair<int,int> pos;

void pinta(queue<pos> cua, char c, bool primer){
	while(cua.empty() == false){
		pos act = cua.front();
		cua.pop();
		if(tauler[act.first][act.second] == '.' or primer){
			primer = false;
			tauler[act.first][act.second] = c;
			if(tauler[act.first+1][act.second] != '#'){
				pos aux;
				aux.first = act.first+1;
				aux.second = act.second;
				cua.push(aux);
			}
			if(tauler[act.first-1][act.second] != '#'){
				pos aux;
				aux.first = act.first-1;
				aux.second = act.second;
				cua.push(aux);
			}
			if(tauler[act.first][act.second+1] != '#'){
				pos aux;
				aux.first = act.first;
				aux.second = act.second+1;
				cua.push(aux);
			}
			if(tauler[act.first][act.second-1] != '#'){
				pos aux;
				aux.first = act.first;
				aux.second = act.second-1;
				cua.push(aux);
			}
		}
	}
	
}

int main(){
	while(cin >> n >> m){
		tauler = vector<vector<char> >(n, vector<char>(m));
		vector<queue<pos> > veccues;
		for (int i = 0; i < n; ++i)
		{
			for(int j = 0; j<m; ++j){
				cin >> tauler[i][j];
				if((tauler[i][j] >= 'a' and tauler[i][j] <= 'z') or (tauler[i][j] >= 'A' and tauler[i][j] <= 'Z')){
					queue<pos> cua;
					pos x;
					x.first = i;
					x.second = j;
					cua.push(x);
					veccues.push_back(cua);
				}
			}
		}
		for(int i = 0; i<veccues.size(); ++i){
			pos p;
			p = veccues[i].front();
			char c = tauler[p.first][p.second];
			pinta(veccues[i], c, true);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << tauler[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}