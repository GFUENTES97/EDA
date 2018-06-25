#include <iostream>
#include <vector>

using namespace std;

int position(double x, const vector<double>& v, int left, int right){
    
    int m = (left+right)/2;
    if(left>right || (left == right && v[m]!=x)) return -1;
    if(v[m] == x) return m;
    if(v[m] > x) return position(x,v,left,m);
    if(v[m] < x) return position(x,v,m,right);
}

