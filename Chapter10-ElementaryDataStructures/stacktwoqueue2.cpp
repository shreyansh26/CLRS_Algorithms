#include <iostream>
#include <queue>
using namespace std;
queue<int> q1;
queue<int> q2;

void push(int num){
    q1.push(num);
}

int pop(){
    if(q1.empty())
        return -1;

    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
    }
    int res = q1.front();
    q1.pop();
    swap(q1,q2);
    return res;
}

int main() {

push(1);
push(2);
push(3);
cout<<pop()<<" ";
cout<<pop()<<" ";
cout<<pop()<<" ";
cout<<pop()<<" ";
return 0;
}
