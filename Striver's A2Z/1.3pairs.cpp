# include <bits/stdc++.h>

using namespace std;
void print(){
    cout << "SR";
    pair <int,int> p = {1,3};
    cout << p.first;
    cout << p.second;
    pair < int , pair <int,int> > p = { 1, {3,4} };
    cout << p.second.second;
    pair <int, int> arr [] = { {1,2} , {3,4} , {5,6} };
    cout << arr[1].second;
}
int main () {
    print();
    
    
    
}
