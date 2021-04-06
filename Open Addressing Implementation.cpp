#include<bits/stdc++.h>
using namespace std;

class myHash{
    int *arr;
    int cap, size;
    int hash(int key){
        return (key%cap);
    }
public:
    myHash(int x){
        cap=x;
        size=0;
        arr = new int[cap];
        for(int i=0;i<cap;i++) arr[i]=-1;
    }
    bool search(int key){
        int b_no = hash(key);
        int i = b_no;
        while(arr[i]!=-1){
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==b_no)
                return false;
        }
        return false;
    }
    bool insert(int key){
        if(size==cap)
            return false;
        int b_no = hash(key);
        int i = b_no;
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i=(i+1)%cap;
            if(i==b_no)
                return false;
        }
        if(arr[i]==key)
            return false;
        arr[i]=key;
        size++;
        return true;
    }
    bool erase(int key){
        int b_no = hash(key);
        int i = b_no;
        while(arr[i]!=-1){
            if(arr[i]==key){
                arr[i]=-2;
                size--;
                return true;
            }
            i=(i+1)%cap;
            if(i==b_no)
                return false;
        }
        return false;
    }
    void print(){
        if(size==0)
            return;
        for(int i=0;i<cap;i++){
            if(arr[i]!=-1 && arr[i]!=-2)
                cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main(){
    myHash hm(10);
    hm.insert(10);
    hm.insert(2);
    hm.insert(5);
    hm.insert(7);
    hm.erase(5);
    hm.print();
    return 0;
}
