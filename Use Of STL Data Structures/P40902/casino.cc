//#include GFUENTES97 

#include <iostream>
#include <map>
#include <set>


using namespace std;

int main(){
  
  set<string> casino;
  map<string,int> M;
  string nom;
  int guany;
  string comanda;
  map<string,int>::iterator itM;
  
  while(cin >> nom){
  
    cin >> comanda;
    
    if(comanda == "enters"){
      
      if(casino.find(nom) != casino.end()) cout << nom << " is already in the casino" << endl;
      else casino.insert(nom);
      M.insert(pair<string,int>(nom,0));
    }
    else if(comanda == "leaves"){
      if(casino.find(nom) == casino.end()) cout << nom << " is not in the casino" << endl;
      else {
      	casino.erase(nom);
      	itM = M.find(nom);
      	cout << nom << " has won " << itM->second << endl;
      	M.erase(nom);
      }
    }
    else if(comanda == "wins"){
      cin >> guany;
      if(casino.find(nom) == casino.end()) cout << nom << " is not in the casino" << endl;
      else{
      	itM = M.find(nom);
      	int aux = itM->second;
      	aux += guany;
      	itM->second = aux;
	
      }
    }
    
    
  }
  cout << "----------" << endl;
  itM = M.begin();
  while(itM != M.end()){
      cout << itM->first << " is winning " << itM->second << endl;
      ++itM; 
  }
  
  
  
  
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */