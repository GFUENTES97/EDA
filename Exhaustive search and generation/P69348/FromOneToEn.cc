//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;

void completa(int i, vector<int>& v,vector<bool>& utilitzats){
  if(i != v.size()){
    for(int k = 0; k<v.size(); k++){
      
      if(utilitzats[k] == false){
	  utilitzats[k] = true;
	  v[i] = k+1;
	  completa(i+1, v, utilitzats);
	  utilitzats[k] = false;
	
      }
      
    }
    
  }
  else{
    
    cout << "(" << v[0] ;
    for(int j = 1; j<v.size(); ++j){
      cout << "," <<  v[j];
    }
    cout << ")" << endl;
    
  }
    
  
}


int main(){
  int n; 
  cin >> n;
  int i = 0;
  vector<int> v(n);
  vector<bool> utilitzats(n,false);
  completa(i, v, utilitzats);
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */