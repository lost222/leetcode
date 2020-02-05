#include <iostream>
#include <queue>
#include <vector>


using namespace std;


// 复杂度 O(n*log(k))
// q是top K 大的队列 -- 一个最小堆

int findKthLargest(vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;

    for(int i=0; i<k; i++){
        q.push(nums[i]);
    }

    for(int i=k; i<nums.size(); i++) {
        if(nums[i]>q.top()){
            q.push(nums[i]);
            q.pop();
        }
    }

    return q.top();
}



// 可以使用快排的思路
// 1. 对第一个元素 一波快排， 能够把它放到正确的位置上 --- 如果这个位置刚好是倒数第K个， 那么这个元素就是第K大的元素
// 2. 没到倒数第K个，那么对这个元素以后的数组执行（之前的数组比它小，已经不用考虑了）

void my_swap(vector<int>::iterator a, vector<int>::iterator b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 其实没必要传参num 不过真实情况下还是用pos代替iter吧， iter调试中不方便看在哪里
int findKthLargest_quick(int k, vector<int>::iterator begin, vector<int>::iterator end, vector<int>& nums) {
    if(begin == end) {
        return 0;
    }
    if(end - begin == 1) {
        return *begin;
    }
    int val = *begin;
    // 注意i = begin， 极端情况下在begin处相遇
    auto i = begin;
    auto j = end - 1;
    //注意这里， 一定先右边后左边， 不然相遇的时候可能停在奇怪的地方
    while(true) {
        // 从右边找一个比他小的（注意大于等于条件）
        while (*j >= val && i<j){j--;}
        // 从左边找一个比他大的（注意小于等于条件）
        while (*i <= val && i<j){i++;}
        if(i >= j){
            break;
        }
        my_swap(i, j);
    }
    my_swap(begin, i);


    int rank = int(end - i);
    if(rank == k) {
        return *i;
    } else if (rank < k) {
        //在左边
        return findKthLargest_quick(k - rank, begin, i, nums);//不包含i
    } else {
        return findKthLargest_quick(k, i+1, end, nums);
    }
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {7,6,5,4,3,2,1};
    int v = findKthLargest_quick(2, nums.begin(), nums.end(), nums);
    cout<<v<<endl;



    return 0;
}