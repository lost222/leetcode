#include <iostream>
#include <vector>
#include <climits>

using namespace std;



int reverse(int x) {

    int factor  =  x < 0 ? -1 : 1;

    x = x < 0 ? -x : x;

    vector<int> save;



     
    int ans = 0;
    int d = 1;
    for(vector<int>::iterator i=save.end() - 1; i>=save.begin(); i--) {
        if(d > INT_MAX /100) {return 0;}
        if(ans > INT_MAX - (*i)*d){return 0;}
        ans += (*i) * d;
        d *= 10;
    }

    ans *= factor;
    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    int i =  129 ;
    int ans = reverse(i);
    cout<<ans<<endl;


    return 0;
}