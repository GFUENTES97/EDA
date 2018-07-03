//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std; 

int U;

bool legal(int i, vector<int> v, int x){
	for(int k = 0; k<x; ++k){
		if(v[k] == i) return false;
		else if( (i-v[k]) == (x-k) ) return false;
		else if( (v[k]-i) == (x-k) ) return false;
	}

	return true;
}

void reinas(vector<int>& v, int k){
	if(k == U){
		for(int i = 0; i<U; ++i){
		for(int j = 0; j<U; ++j){
			if(j==v[i]) cout << "Q";
			else cout << ".";
		}
		cout << endl;
	}
	cout << endl;
	}
	if(k < U){
		for(int i = 0; i<U; ++i){
			if(legal(i,v,k)){
				v[k] = i;
				reinas(v,k+1);
			}
		}
	}

}

int main(){
	cin >> U;
	vector<int> v(U);
	reinas(v, 0);
	
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */