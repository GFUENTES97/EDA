#include <iostream>
#include <map> 

using namespace std;

int main(){

	map<string,int> bossa;
	map<string,int>::iterator it;

	string comanda, paraula;


	while(cin >> comanda){

		if(comanda == "minimum?"){
			if(bossa.empty()) cout << "indefinite minimum" << endl;
			else{
				it = bossa.begin();
				cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
				}
		}

		else if(comanda == "maximum?"){
			if(bossa.empty()) cout << "indefinite maximum" << endl;
			else{
				it = bossa.end();
				--it;
				cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl; 
			}
		}
		else if(comanda == "store"){
			cin >> paraula;
			it = bossa.find(paraula);

			if(it == bossa.end()) bossa.insert(pair<string,int>(paraula,1));	
			else it->second++;  	
		}
		else if(comanda == "delete"){
			cin >> paraula;
			it = bossa.find(paraula);
			if(it != bossa.end()){
				if(it->second == 1) bossa.erase(paraula);
				else it->second--; 
			}
		}

	}

}