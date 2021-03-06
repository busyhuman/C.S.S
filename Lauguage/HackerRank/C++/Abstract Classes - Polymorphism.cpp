#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
private:
    int cap;
    int sz;
public:
    LRUCache(int c){
        cap = c;
        sz=0;
        tail = NULL;
        head = NULL;
    }
    void set(int key, int val) override{
       Node* node;
       if( tail == NULL){
          sz=1;
          node = new Node(key,val);
          tail = node;
          head = node;
          mp[key] = node;
          return;
       }
       if( mp[key] ){
          node = mp[key];
          node->value = val;

          if( tail == node){
             return;
          }

          node->next->prev = node->prev;
          node->prev = tail;
          node->next = NULL;
          tail->next = node;
          tail = node;
       }
       else{
            node = new Node(tail,NULL,key,val);
            mp[key] = node;
            tail->next = node;
            tail = node;
            
            if(sz < cap){
               sz++;
            }
            else{
               mp.erase(head->key);
               head = head->next;
               delete(head->prev);
               head->prev = NULL;
            }
          
       }

    }
    int get(int key) override{
      
       if( mp[key]){
          return mp[key]->value;
       }
       else{
          return -1;
       }

    }
}; 
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
 
