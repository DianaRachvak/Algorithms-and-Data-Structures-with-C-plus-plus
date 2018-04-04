#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<int> intQueue;

    for(int i=1; i<=10; i++)
        intQueue.push(i);

    intQueue.pop();

    cout<<intQueue.size()<<endl;

    return 0;
}
