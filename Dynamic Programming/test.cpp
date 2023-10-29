#include<iostream>
using namespace std;
int main () {
    if (__cplusplus == 199711L)
    cout << "The current version is C++98\n";
    else if (__cplusplus == 201103L)
    cout << "The current version is C++11\n";
    else if (__cplusplus == 201402L) 
    cout << "The current version is C++14\n";
    else if (__cplusplus == 201703L)
    cout << "The current version is C++17\n";
    else
    cout << "It is pre-standard C++\n";
}