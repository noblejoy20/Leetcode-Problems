class LRUCache {
public:
    struct Node{
        int data;
        int key;
        Node* next;
        Node* prev;
        Node(int d=-1,int k=-1){
            data=d;
            key=k;
            next=prev=NULL;
        }
    };
    Node* head=new Node();
    Node* tail=new Node();
    unordered_map<int,Node*> umap;
    int cap;
    
    LRUCache(int capacity) {
        umap.clear();
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* temp){
       Node* curr = head->next;
        temp->next = curr;
        temp->prev = head;
        curr->prev = temp;
        head->next = temp;
    }
    
    void deleteNode(Node* temp){
        Node* next=temp->next;
        Node* prev=temp->prev;
        prev->next=next;
        next->prev=prev;
    }
    int get(int key) {
        if(umap.find(key)!=umap.end()){
            Node* temp=umap[key];
            int result=temp->data;
            deleteNode(temp);
            umap.erase(key);
            addNode(temp);
            umap[key]=head->next;
            return result;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            Node* temp=umap[key];
            if(temp->data!=value){
                temp->data=value;
            }
            deleteNode(temp);
            addNode(temp);
            umap.erase(key);
            
            umap[key]=temp;
        }else{
            if(umap.size()==cap){
                Node* temp=tail->prev;
                int delkey=temp->key;
                deleteNode(temp);
                umap.erase(delkey);
            }
            Node* newNode=new Node(value,key);
            addNode(newNode);
            umap[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */