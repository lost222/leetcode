#include <iostream>
#include <queue>
// 一个简单的循环队列实现
// 注意声明size， 但是只能保存size - 1个元素
// 在这个前提下， 注意emptyy 和 full 条件


template <typename T>
class my_queue {
private:
    int size;
    T * arr;
public:
    my_queue(int n);
    int front;
    int rear;
    bool full();
    bool empty();
    void push_back(T v);
    const T head();
    T pop();
    ~my_queue();
    int length();

};

template <typename T>
bool my_queue<T>::full() {
    return (rear + 2) % size == front;
}

template <typename T>
int my_queue<T>::length() {
    return (rear - front + 1 + size) % size;
}

template <typename T>
bool my_queue<T>::empty() {
    return (rear+1) % size == front;
}


template <typename T>
my_queue<T>::my_queue(int n):size(n) {
    arr = new T[size];
    rear = 0;
    front = 1;
}

template <typename T>
my_queue<T>::~my_queue() {
    delete[] arr;
    arr = NULL;
}

template <typename T>
const T my_queue<T>::head() {
    return arr[front];
}

template <typename T>
void my_queue<T>::push_back(T v) {
    rear = (rear+1) % size;
    arr[rear] = v;
}

template <typename T>
T my_queue<T>::pop() {
    T v =  arr[front];
    front = (front+1) % size;
    return v;
}





int main() {
    std::cout << "Hello, World!" << std::endl;

    std::queue<int> q1;
    q1.front();
    q1.size();

    my_queue<int> myQueue(100);



    return 0;

}