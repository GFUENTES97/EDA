//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;


void completa(int i, vector<int>& v, int zeros, int m){

  if(i != v.size()){
    if(zeros != 0){
       v[i] = 0;
       completa(i+1, v, zeros-1, m);
	
    }
    if(m != 0){
      v[i] = 1;
      completa(i+1, v, zeros, m-1);
    }
    
  }
   
    
  else{
    cout << v[0];
    for(int j = 1; j<v.size(); ++j) cout << ' ' << v[j];
    cout << endl;
  }
  
}


int main(){
  int n,m, i = 0;
  
  cin >> n >> m;
  int zeros = n - m;
  vector<int> v(n);
  completa(i,v, zeros, m);

}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */