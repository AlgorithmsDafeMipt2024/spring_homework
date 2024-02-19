#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    } 
    int k;
    cin >> k;
    cout << Func(k, v).first << " " << Func(k,v).second;
}
