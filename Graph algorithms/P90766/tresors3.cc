#include <iostream>
#include <vector>

using namespace std;



void busca(vector<vector<char> > &mapa,vector<vector<bool> > &mapa2, int posx, int posy, int &cont){
  if(mapa[posx][posy] == 't') {
     mapa[posx][posy] = '.';
     cont++;
      
  }
  else if(mapa[posx][posy] == 'X') {mapa2[posx][posy] = true;}
  if(mapa2[posx][posy] == false){
    mapa2[posx][posy] = true;
    busca(mapa, mapa2,posx,posy+1,cont); 
    busca(mapa,mapa2,posx+1,posy, cont); 
    busca(mapa,mapa2,posx-1,posy, cont); 
    busca(mapa,mapa2,posx,posy-1, cont);
    
  }

  
  
}


int main(){
int files,columnes;
int cont = 0;
cin >> files >> columnes;
vector<vector<char> > mapa(files+2, vector<char>(columnes+2));
vector<vector<bool> > mapa2(files+2, vector<bool>(columnes+2, false));
vector<vector<bool> > mapaaux(files+2, vector<bool>(columnes+2, false));
for(int i = 0; i<files+2; ++i){
  for(int j = 0; j<columnes+2; ++j) {
    if(i == 0 or j == 0 or i == files+1 or j == columnes+1) mapa[i][j] = 'X';
    else cin >> mapa[i][j];
  }
}

int posx, posy;
cin >> posx >> posy;

busca(mapa, mapa2,posx,posy, cont);

cout << cont << endl;

}