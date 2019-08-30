#ifndef HASHTABLEMODEL_H
#define HASHTABLEMODEL_H

#include <string>
#include <vector>
#include <cstring>

typedef unsigned int Hash_t;

template <class T>
class HashTable
{
private:
    struct Node
    {
        std::string key;
        T value;
        unsigned long next;
    };

    static const Hash_t HASH_MAX = static_cast<int>(1e5 + 5);

    static Hash_t hash(std::string str);

    unsigned long _head[HASH_MAX];
    std::vector<Node> _edges;

public:
    HashTable();
    ~HashTable();

    T &operator[] (std::string key);
};

#endif // HASHTABLEMODEL_H
