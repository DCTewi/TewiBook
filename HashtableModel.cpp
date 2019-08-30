#include "HashtableModel.h"

template <class T>
Hash_t HashTable<T>::hash(std::string str)
{
    static unsigned int seed = 131;
    unsigned int hash = 0;
    for (auto it : str)
    {
        hash = hash * seed + static_cast<unsigned int>(it);
    }
    return (hash & 0x7fffFFFF) % HASH_MAX;
}

template <class T>
T &HashTable<T>::operator[] (std::string key)
{
    Hash_t hash_value = hash(key);
    for (auto i = _head[hash_value]; i; i = _edges[i].next)
    {
        if (_edges[i].key == key) return _edges[i].value;
    }
    _edges.emplace_back(Node{key, -1, _head[hash_value]});
    _head[hash_value] = _edges.size() - 1;
    return _edges[_edges.size() - 1].value;
}

template <class T>
HashTable<T>::HashTable()
{
    memset(_head, 0, sizeof(_head));
}

template <class T>
HashTable<T>::~HashTable()
{

}
