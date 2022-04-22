struct LinkedList{
    int key;
    int value;
    LinkedList* next;
    LinkedList* prev;
    
    LinkedList(){
       next=NULL;
       prev=NULL;
    }
    
    LinkedList(int k,int v){
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
    }
};
class MyHashMap {
private:
    vector<LinkedList*> nodes;
public:
    MyHashMap() {
        for(int i=0;i<1000;i++){
            LinkedList* head = new LinkedList(-1,-1);
            LinkedList* tail = new LinkedList(-1,-1);
            head->next=tail;
            tail->prev=head;
            nodes.push_back(head);
        }
        //nodes.resize(1000,NULL);
    }
    
    void put(int key, int value) {
        int pos = key % 1000;
  
        LinkedList* ptr=nodes[pos];
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

        LinkedList* temp = new LinkedList(key,value);
        temp->next=ptr->next;
        ptr->next=temp;
        temp->prev=temp->next->prev;
        temp->next->prev=temp;
        
    }
    
    int get(int key) {
        int pos = key % 1000;
        LinkedList* ptr = nodes[pos];
        while(ptr->next!=NULL){
            if(ptr->key==key){ return ptr->value;}
            ptr=ptr->next;
        }
        if(ptr->key==key){ return ptr->value;}
        return -1;
    }
    
    void remove(int key) {
        int pos = key % 1000;
        LinkedList* ptr = nodes[pos];
        while(ptr->next!=NULL){        
            if(ptr->key==key){    
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                return;
            }
            ptr=ptr->next;
        }
        if(ptr->key==key){    
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
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