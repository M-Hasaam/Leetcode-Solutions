class MyHashSet {
    const int SIZE = 1009;

    int hash(int key) { return key % SIZE; }

    vector<list<int>> Buckets;

    // Buckets (index → linked list)
    // ↓
    // [0]: [0 -> 1010]
    // [1]: []
    // [2]: [2 -> 1011]
    // [3]: []
    // [4]: []
    // [5]: [5 -> 1014]
    // [6]: []
    // [7]: []
    // [8]: []
    // [9]: []
    // [10]: [15]
    // ...
    // [1009]: [1009]

public:
    MyHashSet() { Buckets.resize(SIZE); }

    void add(int key) {
        int i = hash(key);

        for (int val : Buckets[i])
            if (val == key)
                return;

        Buckets[i].push_back(key);
    }

    void remove(int key) {
        int i = hash(key);

        Buckets[i].remove(key);
    }

    bool contains(int key) {
        int i = hash(key);

        for (int val : Buckets[i])
            if (val == key)
                return true;

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */