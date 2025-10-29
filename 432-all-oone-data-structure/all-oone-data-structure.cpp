struct Bucket {
    int count;
    unordered_set<string> keys;
    Bucket *next, *prev;

    Bucket(int c) {
        count = c;
        next = nullptr;
        prev = nullptr;
    }
};

class AllOne {

    unordered_map<string, Bucket*> keyBucket;
    Bucket *head = nullptr, *tail = nullptr;

    Bucket* insertAfter(Bucket* curr, int newCount) {

        Bucket* toAdd = new Bucket(newCount);

        toAdd->next = curr->next;
        curr->next = toAdd;
        toAdd->prev = curr;
        toAdd->next->prev = toAdd;

        return toAdd;
    }

    bool removeifEmpty(Bucket* toDel) {
        if (toDel != head && toDel != tail && toDel->keys.empty()) {
            toDel->prev->next = toDel->next;
            toDel->next->prev = toDel->prev;
            delete toDel;
            return true;
        }
        return false;
    }

public:
    AllOne() {
        head = new Bucket(INT_MIN);
        tail = new Bucket(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {

        if (keyBucket.count(key) == 0) {

            Bucket* first = head->next;

            if (first == tail || first->count > 1)
                first = insertAfter(head, 1);

            first->keys.insert(key);
            keyBucket[key] = first;

        } else {
            Bucket* curr = keyBucket[key];
            int newCount = curr->count + 1;

            Bucket* nextBucket = curr->next;
            if (nextBucket == tail || nextBucket->count > newCount)
                nextBucket = insertAfter(curr, newCount);

            nextBucket->keys.insert(key);
            curr->keys.erase(key);

            keyBucket[key] = nextBucket;

            removeifEmpty(curr);
        }
    }

    void dec(string key) {
        if (keyBucket.count(key) == 0)
            return;

        Bucket* curr = keyBucket[key];
        int newCount = curr->count - 1;

        if (newCount == 0) {
            curr->keys.erase(key);

            keyBucket.erase(key);
        } else {
            Bucket* prevBucket = curr->prev;

            if (prevBucket == head || prevBucket->count < newCount)
                prevBucket = insertAfter(prevBucket, newCount);

            prevBucket->keys.insert(key);
            curr->keys.erase(key);

            keyBucket[key] = prevBucket;
        }

        removeifEmpty(curr);
    }

    string getMaxKey() {
        Bucket* last = tail->prev;

        if (last == head || last->keys.empty())
            return "";

        return *(last->keys.begin());
    }

    string getMinKey() {
        Bucket* first = head->next;

        if (first == tail || first->keys.empty())
            return "";

        return *(first->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */