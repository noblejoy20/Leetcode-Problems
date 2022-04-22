struct LinkedList{
    int key,value;
    LinkedList *next,*prev;
       
    LinkedList(int k,int v){
        key=k;
        value=v;
        next=prev=NULL;
    }
};
class MyHashMap {
private:
    vector<LinkedList*> nodes;
    const int bucket_size=1000;
public:
   
    MyHashMap() {
        Init(nodes);
    }
    
     void Init(vector<LinkedList*>& nodes){
        for(int i=0;i<bucket_size;i++){
            LinkedList* head = new LinkedList(-1,-1);
            LinkedList* tail = new LinkedList(-1,-1);
            head->next=tail;
            tail->prev=head;
            nodes.push_back(head);
        }
    }
    
    void insert(LinkedList *ptr,int key,int value){
        LinkedList* temp = new LinkedList(key,value);
        temp->next=ptr->next;
        ptr->next=temp;
        temp->prev=temp->next->prev;
        temp->next->prev=temp;
    }
    
     int findKey(LinkedList *ptr,int key){
        while(ptr->next!=NULL){
            if(ptr->key==key){ return ptr->value;}
            ptr=ptr->next;
        }
        if(ptr->key==key){ return ptr->value;}
        return -1;
    }
    
    void deleteKey(LinkedList* ptr){
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
    }
    
    void put(int key, int value) { 
        LinkedList* ptr=nodes[key % bucket_size];
        while(ptr->next!=NULL && ptr->next->key!=-1){
            if(ptr->key == key){
                ptr->value = value;
                return;
            }
            ptr=ptr->next;
        }
        if(ptr->key == key){
            ptr->value = value;
            return;
        }                   
        insert(ptr,key,value);               
    }
    
   
    int get(int key) {
        LinkedList* ptr = nodes[key % bucket_size];
        int val = findKey(ptr,key);
        return val;
    }
    
    void remove(int key) {
        LinkedList* ptr = nodes[key % bucket_size];
        while(ptr->next!=NULL){        
            if(ptr->key==key){    
                deleteKey(ptr);
                return;
            }
            ptr=ptr->next;
        }
        if(ptr->key==key){    
            deleteKey(ptr);
            return;
        }  
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */