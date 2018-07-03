//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;

void completa(int i, vector<int>& v){
  if(i != v.size()){
    v[i] = 0;
    completa(i+1,v);
    v[i] = 1;
    completa(i+1,v);
  }
  else{
    cout << v[0];
    for(int j = 1; j<v.size(); ++j) cout << ' ' << v[j];
    cout << endl;
  }

}


int main(){
  int i = 0;
  int n;
  cin >> n;
  vector<int> v(n);
  completa(i, v);

}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */