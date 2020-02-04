#include <iostream>
#include <stack>
#include <string>
using namespace std;




int main() {
    std::cout << "Hello, World!" << std::endl;

    string s = "osss";
    for(string::iterator i=s.begin(); i!=s.end();i++) {
        cout<<*i<<" ";
    }


    return 0;
}