#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max(T const& a, T const& b){
    return a < b ? b : a;
}

int main(){
    int i = 39;
    int j = 20;
    cout << "Max(i,j): " << Max(i,j) <<endl;

    double f1 = 13.5;
    double f2 = 20.7;

    cout << "Max(i,j): " << Max(f1,f2) <<endl;

    string s1 = "Hello";
    string s2 = "Word";

    cout << "Max(i,j): " << Max(s1,s2) <<endl;
    
    return 0;
}