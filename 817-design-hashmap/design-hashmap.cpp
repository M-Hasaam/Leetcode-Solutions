class MyHashMap {

    struct Pair {
        int key = 0, val = 0;
    };

    static const int size = 1000;
    vector<Pair> bucket[size];

    int gethash(int i) { return i % size; }

public:
    MyHashMap() {}

    void put(int key, int value) {
        int idx = gethash(key);

        for (auto& b : bucket[idx]) {
            if (b.key == key) {
                b.val = value;
                return;
            }
        }

        bucket[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = gethash(key);

        for (auto& b : bucket[idx]) {
            if (b.key == key) {
                return b.val;
            }
        }

        return -1;
    }

    void remove(int key) {
        int idx = gethash(key);

        for (auto it = bucket[idx].begin(); it < bucket[idx].end(); it++) {
            if (it->key == key) {
                bucket[idx].erase(it);
                return;
            }
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