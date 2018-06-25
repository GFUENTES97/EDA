#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Mat;

Mat producte(const Mat &M1, Mat &M2, int m){
	Mat M3(2,vector<int>(2,0));
	for(int i = 0; i<2; ++i){
		for(int j = 0; j<2; ++j){
			for(int k = 0; k<2; ++k){
				M3[i][j] +=  M1[i][k]*M2[k][j];
				M3[i][j] %= m;
			}
		}
	}
	return M3;
}


void powerofamatrix(const Mat& M, int n, int m, Mat& res){
	
	if(n == 0){
		res[0][0] = 1; res[0][1] = 0; res[1][0] = 0; res[1][1] = 1;
		
	}
	else if(n == 1){
		res[0][0] = (M[0][0])%m; res[0][1] = (M[0][1])%m; 
		res[1][0] = (M[1][0])%m; res[1][1] = (M[1][1])%m;
		
	}

	else if(n % 2 == 0){
		Mat aux(2, vector<int>(2));
		powerofamatrix(M,n/2,m,aux);
	 	res = producte(aux, aux, m);
	}
	else {
		Mat aux(2,vector<int>(2));
		powerofamatrix(M, n-1, m, aux);
		res = producte(M, aux, m);
			
	}
}



int main(){
	
	Mat M1(2, vector<int>(2));
	Mat res(2, vector<int>(2));
	int a,b,c,d;
	while(cin >> a >> b >> c >> d){
		M1[0][0] = a; M1[0][1] = b;
		M1[1][0] = c; M1[1][1] = d;
		int n,m;
		cin >> n >> m;
		powerofamatrix(M1,n,m, res);
		cout << res[0][0] << " " << res[0][1] << endl << res[1][0] << " " << res[1][1] << endl << "----------" << endl;
  	}

}