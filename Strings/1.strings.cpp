/*  
  https://www.hackerrank.com/challenges/c-tutorial-strings/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q; // number of arrays and queries
    cin>>n>>q;
    vector<int> arr[n];
    for(int i=0;i<n;i++){
        int arrsize = 0;
        cin>>arrsize;
        for(int j =0;j<arrsize;j++){
            int temp;
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    //responding to queries
    for(int i_q=0;i_q<q;i_q++){
        int i,j;
        cin>>i>>j;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<arr[i].at(j)<<endl;
    }
