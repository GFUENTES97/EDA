#include <iostream>

using namespace std;


int potencia(int n, int k, int m){

  if(k == 0) return 1;
  if(k%2 == 0){
  
      int a =  potencia(n,k/2,m);
      return (a*a)%m;
      
  }
  else{
    int a =  potencia(n,(k-1)/2,m);
    return (((a*a)%m)*n)%m;
  }
  
}


int main(){

  int n,k,m;
  while(cin >> n >> k >> m){
    
      cout << potencia(n,k,m) << endl;
  }
  
}
