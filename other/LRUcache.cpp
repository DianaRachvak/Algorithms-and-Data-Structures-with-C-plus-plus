/* We can use stl container list as a double
   ended queue to store the cache keys, with
   the descending time of reference from front
   to back and a set container to check presence
   of a key. But to fetch the address of the key
   in the list using find(), it takes O(N) time.
    This can be optimized by storing a reference
    (iterator) to each key in a hash map. */
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    // store keys of cache
    list<pair<string,string>> dq;
    // store references(iterator) to each key in a hash map
    unordered_map<pair<string, string>, list<string>::iterator> ma;
    int csize; //maximum capacity of cache

public:
    LRUCache(int n)  { csize = n; }

    /* Refers key x with in the LRU cache */
    void refer(string x, string y)
    {
        // not present in cache
        if (ma.find(pair<x,y>) == ma.end()){
            if (dq.size() == csize){// cache is full
                //delete least recently used element
                ma.erase(dq.back());
                dq.pop_back();
            }
        }
        else  dq.erase(ma[pair<x,y>]);// present in cache

        // update reference
        dq.push_front(pair<x,y>);
        ma[pair<x,y>] = dq.begin();
    }

    // display contents of cache
    void print() {
        //for (auto it = dq.begin(); it != dq.end(); it++)
          //  cout << (*it) << endl;
          for_each(dq.begin(), next(dq.begin(), 2), std::ref(pr))
    }
    void pr(dq::reference x) {
        cout<<x.first<<" "<<x.last;
    }
};

// Driver program to test above functions
int main() {
    LRUCache ca(4);

    ca.refer("1 Given a binary tree");
    ca.refer("2 return the left-most node");
    ca.refer("3 of each level in the tree");
    ca.refer("4 I used an altered implementation");
    ca.refer("5 keep track of the current depth");
    ca.refer("6 and stored left-most values in an array");

    ca.print();
    return 0;
}
