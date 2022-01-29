class MyCircularDeque {
private:
    int size,rear,front,k;
    vector<int> arr;
public:
    MyCircularDeque(int k) {
        size=0;
        rear=0;
        front=0;
        this->k=k;
        arr.resize(k);
    }
    
    bool insertFront(int value) {
        if(size==k) return false;
        
        if(size==0) front=rear=0;
        else front = (front-1+k)%k;
        
        arr[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==k) return false;
        
        if(size==0) front=rear=0;
        else rear = (rear+1)%k;
        
        arr[rear]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        
        front = (front+1) % k;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        
        rear = (rear-1+k) % k;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */