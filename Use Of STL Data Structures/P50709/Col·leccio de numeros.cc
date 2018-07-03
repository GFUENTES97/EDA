//#include GFUENTES97 

#include <iostream>
#include <queue>

using namespace std;

int main(){
 
  priority_queue<int> cua;
  char a;
  int x;
  
  while(cin >> a){
  if(a >= 'A' && a <= 'Z'){
    if(a == 'S'){
      cin >> x;
      cua.push(x);
    }
    else if(a == 'A' && not cua.empty()){
      cout << cua.top() << endl;
    }
    else if(a == 'R' && not cua.empty()){
      cua.pop();
    }
    else if(a == 'I' && not cua.empty()){
      int aux = cua.top();
      cin >> x;
      aux += x;
      cua.pop();
      cua.push(aux);
    }
    else if(a == 'D' && not cua.empty()){
      int aux = cua.top();
      cin >> x;
      aux -= x;
      cua.pop();
      cua.push(aux);
      
    }
    else cout << "error!" << endl;
    
  }
    
  }
  
  
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */