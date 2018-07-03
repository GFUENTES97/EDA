//#include GFUENTES97 

#include <iostream>
#include <map>


using namespace std;

int main(){
  
  int x,y,n;

  while(cin >> x >> y >> n){

	  map<int,int> M;
	  int cont = 0;
	  bool trobat = false;
	  M.insert(pair<int,int>(n,cont));
	  map<int,int>::iterator it;
	  
	  while(not trobat and n<=100000000){
	    
	    ++cont;
	    
	    if(n%2 == 0) n = n/2 + x;
	    else n = n*3 + y;
	    
	    if(M.find(n) != M.end()) {
	    	it = M.find(n);
	    	trobat = true;
	    }
	    else M.insert(pair<int,int>(n,cont));
	  
	  }
	  
	  if(n<=100000000){
	    int a = it->second;
	    int longitud = cont - a;
	    cout << longitud << endl;
	  }
	  else cout << n << endl;
  }

}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */