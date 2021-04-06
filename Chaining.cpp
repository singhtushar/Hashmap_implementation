#include<bits/stdc++.h>

using namespace std;

struct Bucket {
    set<int> s;
    void add(int x) {
        s.insert(x);
    }
    void remove(int x) {
        s.erase(x);
    }
    bool search(int x) {
        return (s.find(x) != s.end());
    }
};

class HashMap {
    int num_of_buckets;
    Bucket *container;
    int hash(int x) {
        return (x % num_of_buckets);
    }
public:
    HashMap(int x) {
        num_of_buckets = x;
        container = new Bucket[num_of_buckets];
    }
    void insert(int x) {
        int b_no = hash(x);
        container[b_no].add(x);
    }
    void erase(int x) {
        int b_no = hash(x);
        container[b_no].remove(x);
    }
    bool find(int x) {
        int b_no = hash(x);
        return (container[b_no].search(x));
    }
};

int main() {

    return 0;
}
