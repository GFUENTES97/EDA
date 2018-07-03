//#include GFUENTES97 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> tasques;


void escriu(vector<int> &sol){

    for(int i = 0; i<sol.size();++i){
        if(i==0) cout << sol[0];
        else cout << " " << sol[i];
    }
    cout << endl;
}

void ordena(vector<int> sol, vector<int> pred, vector<vector<int> > prio){
    int m = prio.size();
    priority_queue<int, vector<int>, greater<int> > pQ;
    for(int i = 0; i<pred.size(); ++i){
        if(pred[i] == 0) pQ.push(i);
    }
    while(!pQ.empty()){
        int tasca = pQ.top(); pQ.pop();
        sol.push_back(tasca);
        for (int i = 0; i < prio[tasca].size(); ++i)
        {
            pred[prio[tasca][i]]--;
            if(pred[prio[tasca][i]] == 0) pQ.push(prio[tasca][i]);
        }
    }
    escriu(sol);
   
}

int main(){
    int x;
    while(cin >> n >> x){
        tasques = vector<int>(n,0);
        vector<int> pred;
        vector<int> sol;
        vector<vector<int> > prio;
        prio = vector<vector<int> >(n);
        pred = vector<int>(n);
        for(int i = 0; i<n; ++i) tasques[i] = i;
        for(int i = 0; i<x; ++i){
            int a,b;
            cin >> a >> b;
            pred[b]++;
            prio[a].push_back(b);
        }
        ordena(sol,pred,prio);
    }
}

/* 
 * 
 *  last update: 
 * 
 *  03/07/2018 14:05:30
 * 
 */