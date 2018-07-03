//#include GFUENTES97 

#include <iostream>
#include <vector>

using namespace std;


bool resistant_search(double x, const vector<double>& v)
{
  if (v.size() == 0) return false;
  int l = 0, r = v.size() - 1, mid;
  while (l + 1 < r) {
    mid = (l+r)/2;
    if (v[mid] == x || v[mid-1] == x || v[mid+1] == x) return true;
    else if (v[mid] > x) r = mid;
    else l = mid;
  }
  return ((x == v[l]) || (x == v[r]));
}

/*
int main()
{

   int n;
   cin >> n;
   vector<double> v(n);
   for(int i = 0; i<n; ++i){
      cin >> v[i];
   }
   double x;
   cout << "Introduce el valor a buscar" << endl;
   cin >> x;
   if(resistant_search(x,v)) cout << "Si que se encuentra!" << endl;
   else cout << "No se encuentra" << endl;


}*/



/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 12:51:57
 * 
 */