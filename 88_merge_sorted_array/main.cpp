#include <iostream>
#include <vector>

using namespace std;


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i , j, k = m + n - 1 ;
        i = m - 1; j = n - 1;
        while(i>-1 && j>-1) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while(j>-1){
            nums1[k--] = nums2[j--];
        }
        while(i>-1){
            nums1[k--] = nums1[i--];
        }
    }


    void out_vec(vector<int> v) {
        for(vector<int>::iterator i = v.begin(); i < v.end(); i++) {
            cout<<" "<<*i;
        }
        cout<<endl;
    }


int main() {
    std::cout << "Hello, World!" << std::endl;

//    int a[6] = { 1, 2, 3, 0, 0, 0 };
//    int b[3] = {2, 5, 6};
//
//    vector<int> vect(a, a+6);
//    vector<int> vect2(b, b+3);
//
//    merge(vect, 3, vect2, 3);
//    out_vec(vect);


    int a = - 19;
    cout<<a/10<<" "<<a%10<<endl;

    return 0;
}