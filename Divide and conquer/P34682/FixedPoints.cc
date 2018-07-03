//#include GFUENTES97 

#include <iostream>
#include <vector>


using namespace std;

int ibusca(vector<int> &vec, int esq, int dre,int a){
 
    int mig = (esq+dre)/2;
    int diff = mig + 1 - vec[mig]; 
    if(dre<esq) return -2;  // pos = -2 + 1 = -1
    
    if(diff > a){
      esq = mig+1;
      return ibusca(vec,esq,dre,a);
    } 
    else if(diff < a){
      dre = mig-1;
      return ibusca(vec,esq,dre,a);
      
    }
    if(diff == a){
      dre = mig;
      if(dre == esq) return mig;
      else return ibusca(vec,esq,dre,a);
      
    }
    
    
    
  
}

bool busca(vector<int>& vec, int a, int &pos){
  if(vec.size()>1){
    int esq,dre,n = vec.size();
    esq = 0;
    dre = n-1;
    pos =  ibusca(vec,esq,dre,a) + 1; 
  }
  else{
    if(vec.size()==0) return false;
    else if(vec[0]+a == 1) pos = 1;
  }
  if(pos == -1)  return false;
  return true;
  
}


int main(){

  int n,m,a,cont = 1;
  while(cin >> n){
   
  vector<int> vec(n);
  for(int i =0;i<n;++i) cin >> vec[i];
  cin >> m;  // m = numero de 'a' que buscamos
  cout << "Sequence #" << cont << endl;
  ++cont;
  for(int i = 0; i<m; ++i){
      int pos = -1;
      cin >> a;
      bool b = busca(vec,a,pos);
      if(b) cout << "fixed point for " << a << ": " << pos << endl;
      else cout << "no fixed point for " << a << endl;
    
  }
  cout << endl;
  }
  
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */