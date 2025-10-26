class MyCircularQueue {
public:
    int* arr = nullptr;
    int size, count;
    int front, rear;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[k];
        count = 0;
        front = 0;
        rear = -1;
    }

    bool enQueue(int value) {
        if (count < size) {
            rear = (rear + 1) % size;
            arr[rear] = value;

            count++;

            return true;
        }
        return false;
    }

    bool deQueue() {
        if (count > 0) {
            front = (front + 1) % size;

            count--;

            return true;
        }
        return false;
    }

    int Front() {
        if (count > 0) {
            return arr[front];
        }
        return -1;
    }

    int Rear() {
        if (count > 0) {
            return arr[rear];
        }
        return -1;
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */