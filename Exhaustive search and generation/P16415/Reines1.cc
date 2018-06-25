#include <iostream>
#include <vector>

using namespace std;

bool legal(int i, vector<int> &T){

  for(int k = 0; k<i; ++k){
    if(T[k]==T[i] or T[i]-i==T[k]-k or T[i]+i == T[k]+k) return false;
  }
  return true;
}


void recursiva(int i, vector<int> &T, int &cont){

  if(i != T.size()){
    for(int r = 0; r<T.size(); r++){
      T[i] = r;
      if(legal(i, T)){
	       recursiva(i+1, T, cont);
      }     
    }   
  }
  else cont++;

}


int main(){
  int cont = 0;
  int n;
  cin >> n;
  vector<int> T(n);
  int i = 0;
  recursiva(i,T, cont);
  cout << cont << endl;  
}
