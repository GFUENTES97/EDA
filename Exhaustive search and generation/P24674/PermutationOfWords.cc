//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;


void completa(int i, vector<string> &paraules, vector<bool>& utilitzats, vector<string>& sortida){
  if(i != paraules.size()){
    for(int k = 0; k<utilitzats.size(); ++k){
      if(utilitzats[k] == false){
	sortida[i] = paraules[k];
	utilitzats[k] = true;
	completa(i+1, paraules, utilitzats, sortida);
	utilitzats[k] = false;
      }
    }
    
    
  }
  
  
  else{
    
    cout << "(" << sortida[0] ;
    for(int j = 1; j<sortida.size(); ++j){
      cout << "," <<  sortida[j];
    }
    cout << ")" << endl;
    
  }
  
}


int main(){

  int n;
  cin >> n;
  string w;
  vector<string> paraules(n);
  vector<string> sortida(n);
  for(int i = 0 ; i<n; ++i) {
    cin >> w;
    paraules[i] = w;
  }
  vector<bool> utilitzats(n,false);
  int i = 0;
  completa(i, paraules, utilitzats, sortida);
  
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */