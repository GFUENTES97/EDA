#include <iostream>
#include <vector>

using namespace std;

int cerca(double &x, const vector<double>& v, int e, int d){
    
    if(e>d) return -1;
    else{
      int m = (e+d)/2;
      if(x>v[m]) return cerca(x,v,m+1,d);
      else if(x<v[m])return cerca(x,v,e,m-1);
      else if(x==v[m] and m>0){
	if (v[m-1]<x) return m;
	else if(x==v[m] and v[m-1]==x) return cerca(x,v,e,m-1);
      }
      else if(x==v[m]) return m;
      else return -1;
      
      
    }
  
}


int first_occurrence(double x, const vector<double>& v){
  
    int e = 0, d=v.size()-1;
    return cerca(x,v,e,d);

}
