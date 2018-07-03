//#include GFUENTES97 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<char> VC;
typedef vector<VC> VCC;
typedef vector<bool> VB;
typedef vector<VB> VBB;
typedef pair<int,int> pos;

void calcula_max_dist(VCC &tablero, VBB positions, VII distancias, queue<pos> cua, bool &queden, bool primer, int &dist){
	while(cua.empty()==false){
		pos pos_act = cua.front();
		cua.pop();
		if(tablero[pos_act.first][pos_act.second] == 't'){
			tablero[pos_act.first][pos_act.second] = '.';
			dist = distancias[pos_act.first][pos_act.second] + 1;
		}
		if(tablero[pos_act.first][pos_act.second] == '.' or primer){
			primer = false;
			if(positions[pos_act.first+1][pos_act.second] == false){
				positions[pos_act.first+1][pos_act.second] = true;
				distancias[pos_act.first+1][pos_act.second] = distancias[pos_act.first][pos_act.second] + 1;
				cua.push(make_pair(pos_act.first+1, pos_act.second));
			}
			if(positions[pos_act.first-1][pos_act.second] == false){
				positions[pos_act.first-1][pos_act.second] = true;
				distancias[pos_act.first-1][pos_act.second] = distancias[pos_act.first][pos_act.second] + 1;
				cua.push(make_pair(pos_act.first-1, pos_act.second));
			}
			if(positions[pos_act.first][pos_act.second+1] == false){
				positions[pos_act.first][pos_act.second+1] = true;
				distancias[pos_act.first][pos_act.second+1] = distancias[pos_act.first][pos_act.second] + 1;
				cua.push(make_pair(pos_act.first, pos_act.second+1));
			}
			if(positions[pos_act.first][pos_act.second-1] == false){
				positions[pos_act.first][pos_act.second-1] = true;
				distancias[pos_act.first][pos_act.second-1] = distancias[pos_act.first][pos_act.second] + 1;
				cua.push(make_pair(pos_act.first, pos_act.second-1));
			}
		}
		else positions[pos_act.first][pos_act.second] = true;
	}
	queden = false;
}


int main(){
	
	int n,m;
	cin >> n >> m;
	VCC tablero(n+2,VC(m+2));
	VBB positions(n+2, VB(m+2, false));
	VII distancias(n+2, VI(m+2, -1));
	for(int i = 0; i<n+2; ++i){
		for(int j = 0; j<m+2; ++j){
			if(i == 0 or j == 0 or i == n+1 or j==m+1) tablero[i][j] = 'X';
			else cin >> tablero[i][j];
		}
	}
	queue<pos> cua;
	pos posinici;
	cin >> posinici.first >> posinici.second;
	cua.push(posinici);
	positions[posinici.first][posinici.second] = true;
	bool queden = true;
	int dist = -1;
	while(queden){
		calcula_max_dist(tablero, positions, distancias, cua, queden, true, dist); 
	}
	if(dist!=-1){
		cout << "maximum distance: " << dist << endl;
	} 
	else{
		cout << "no treasure can be reached" << endl;
	}

}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */