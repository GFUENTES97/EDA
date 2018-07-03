//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;



bool busca(vector<vector<char> > &mapa,vector<vector<bool> > &mapa2, int posx, int posy){
  if(mapa[posx][posy] == 't') return true;
  else if(mapa[posx][posy] == 'X') {mapa2[posx][posy] = true; return false;}
  else if(mapa2[posx][posy] == false){
    mapa2[posx][posy] = true;
    return busca(mapa, mapa2,posx,posy+1) or busca(mapa,mapa2,posx+1,posy) or busca(mapa,mapa2,posx-1,posy) or busca(mapa,mapa2,posx,posy-1);
    
  }
  else return false;
  
  
}


int main(){
int files,columnes;

cin >> files >> columnes;
vector<vector<char> > mapa(files+2, vector<char>(columnes+2));
vector<vector<bool> > mapa2(files+2, vector<bool>(columnes+2, false));
for(int i = 0; i<files+2; ++i){
  for(int j = 0; j<columnes+2; ++j) {
    if(i == 0 or j == 0 or i == files+1 or j == columnes+1) mapa[i][j] = 'X';
    else cin >> mapa[i][j];
  }
}

int posx, posy;
cin >> posx >> posy;

if(busca(mapa, mapa2,posx,posy)) cout << "yes" << endl;
else cout << "no" << endl;

}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */