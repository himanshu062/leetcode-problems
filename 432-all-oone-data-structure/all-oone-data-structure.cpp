struct Node {
    int count;
    unordered_set<string> keys;
};

class AllOne {
public:
    void inc(string key) {
        if (const auto it = keyToIterator.find(key); it == keyToIterator.end())
            addNewKey(key);
        else
            incrementExistingKey(it, key);
    }

    void dec(string key) {
        const auto it = keyToIterator.find(key);
        decrementExistingKey(it, key);
    }

    string getMaxKey() {
        return nodeList.empty() ? "" : *nodeList.back().keys.begin();
    }

    string getMinKey() {
        return nodeList.empty() ? "" : *nodeList.front().keys.begin();
    }

private:
    list<Node> nodeList;
    unordered_map<string, list<Node>::iterator> keyToIterator;
    void addNewKey(const string& key) {
        if (nodeList.empty() || nodeList.front().count > 1)
            nodeList.push_front({1, {key}});
        else
            nodeList.front().keys.insert(key);
        keyToIterator[key] = nodeList.begin();
    }
    void incrementExistingKey(
        unordered_map<string, list<Node>::iterator>::iterator it,
        const string& key) {
        const auto listIt = it->second;

        auto nextIt = next(listIt);
        const int newCount = listIt->count + 1;
        if (nextIt == nodeList.end() || nextIt->count > newCount)
            nextIt = nodeList.insert(nextIt, {newCount, {key}});
        else
            nextIt->keys.insert(key);

        keyToIterator[key] = nextIt;
        remove(listIt, key);
    }
    void decrementExistingKey(
        unordered_map<string, list<Node>::iterator>::iterator it,
        const string& key) {
        const auto listIt = it->second;
        if (listIt->count == 1) {
            keyToIterator.erase(it);
            remove(listIt, key);
            return;
        }

        auto prevIt = prev(listIt);
        const int newCount = listIt->count - 1;
        if (listIt == nodeList.begin() || prevIt->count < newCount)
            prevIt = nodeList.insert(listIt, {newCount, {key}});
        else
            prevIt->keys.insert(key);

        keyToIterator[key] = prevIt;
        remove(listIt, key);
    }
    void remove(list<Node>::iterator it, const string& key) {
        it->keys.erase(key);
        if (it->keys.empty())
            nodeList.erase(it);
    }
};