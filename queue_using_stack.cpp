#include<iostream>
#include<stack>
using namespace std;
class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue()
    {
        //constructor
    }
    void push_1(int val)
    {
        s1.push(val);
    }
     int pop_1()//pops using only one stack and another internal function call stack(recursive)
    {
        if(s1.empty())
            return NULL;
        else
            return pop_1_util();

    }
    int pop_1_util()//function called recursively
    {
        int val;
        int pop_value;
        if(s1.size()!=1)
        {
            val=s1.top();
            s1.pop();
            pop_value=pop_1_util();
        }
        else
        {
            int v=s1.top();
            s1.pop();
            return v;
        }
        s1.push(val);
        return pop_value;
    }






    void push_2(int a)//uses 2 stacks to push at bottom of stack
    {
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(a);
        while(s2.empty()==false)
        {
            s1.push(s2.top());
            s2.pop();
        }

    }
    int pop_2()
    {
        int val=s1.top();
        s1.pop();
        return val;

    }
};
int main()
{
    MyQueue myQueue;
    myQueue.push_1(1);
    myQueue.push_1(2);
    myQueue.push_1(3);
    cout<<myQueue.pop_1();
    cout<<myQueue.pop_1();
    cout<<myQueue.pop_1();



}
