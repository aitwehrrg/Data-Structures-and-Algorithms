#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
struct Entry
{
    K key;
    V value;
    Entry(K key = K{}, V value = V{}) : key(key), value(value) {}
};

template <typename K, typename V, unsigned int MAX>
class HashMap
{
    vector<K> keys;
    list<Entry<K, V> *> dictionary[MAX];
    unsigned int prime;
    unsigned int hash(K key) const;

public:
    HashMap() : prime(1000000007) {} // Pick your favorite prime number
    void insert(K key, V value);
    void remove(K key);
    void update(K key, V value);
    V lookup(K key) const;
    bool exists(K key) const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename K, typename V, unsigned int MAX>
unsigned int HashMap<K, V, MAX>::hash(K key) const
{
    string s = to_string(key);

    unsigned int hash = 0;
    for (char c : s)
        hash += c * prime;
    hash %= MAX;

    return hash;
}

template <typename K, typename V, unsigned int MAX>
void HashMap<K, V, MAX>::insert(K key, V value)
{
    unsigned int index = hash(key);
    if (exists(key))
    {
        cerr << "Key already exists." << endl;
        return;
    }
    keys.push_back(key);
    dictionary[index].push_back(new Entry(key, value));
}

template <typename K, typename V, unsigned int MAX>
void HashMap<K, V, MAX>::remove(K key)
{
    unsigned int index = hash(key);
    for (Entry<K, V> *entry : dictionary[index])
        if (entry->key == key)
        {
            keys.erase(find(keys.begin(), keys.end(), key));
            dictionary[index].remove(entry);
            delete entry;
            return;
        }
    cerr << "Key not found." << endl;
}

template <typename K, typename V, unsigned int MAX>
void HashMap<K, V, MAX>::update(K key, V value)
{
    unsigned int index = hash(key);
    for (Entry<K, V> *entry : dictionary[index])
        if (entry->key == key)
        {
            entry->value = value;
            return;
        }
    cerr << "Key not found." << endl;
}

template <typename K, typename V, unsigned int MAX>
V HashMap<K, V, MAX>::lookup(K key) const
{
    unsigned int index = hash(key);
    for (Entry<K, V> *entry : dictionary[index])
        if (entry->key == key)
            return entry->value;
    cerr << "Key not found." << endl;
    return V{};
}

template <typename K, typename V, unsigned int MAX>
bool HashMap<K, V, MAX>::exists(K key) const
{
    for (K i : keys)
        if (i == key)
            return true;
    return false;
}

template <typename K, typename V, unsigned int MAX>
inline bool HashMap<K, V, MAX>::isEmpty() const { return keys.empty(); }

template <typename K, typename V, unsigned int MAX>
void HashMap<K, V, MAX>::display() const
{
    if (isEmpty())
    {
        cerr << "Hash Map is empty." << endl;
        return;
    }
    cout << "[" << endl;
    for (K key : keys)
        cout << key << " : " << lookup(key) << endl;
    cout << "]" << endl;
}