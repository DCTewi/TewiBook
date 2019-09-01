#ifndef HASHTABLEMODEL_H
#define HASHTABLEMODEL_H

#include <string>
#include <vector>
#include <cstring>

/**
 * \brief Hash 值类型
 */
typedef unsigned int Hash_t;

/**
 * 哈希表的一种简易实现
 * 键为 string 类型
 * 值为模板类型
 */
template <class T>
class HashTable
{
private:
    /**
     * @brief The Node struct
     * 哈希表的节点
     */
    struct Node
    {
        /**
         * @brief 对应的键
         */
        std::string key;
        /**
         * @brief 对应的值
         */
        T value;
        /**
         * @brief 链式前向星的下一个节点
         */
        unsigned long next;
    };

    /**
     * @brief 哈希取模值
     */
    static const Hash_t HASH_MAX = static_cast<int>(1e5 + 5);

    /**
     * @brief 取字符串哈希(基于BKDRHash)
     * @param str 字符串
     * @return 哈希值
     */
    static Hash_t hash(std::string str);

    /**
     * @brief 链式前向星头指针
     */
    unsigned long _head[HASH_MAX];
    /**
     * @brief 链式前向星边集
     */
    std::vector<Node> _edges;

public:
    /**
     * @brief 默认构造函数
     */
    HashTable();
    /**
     * @brief 默认析构函数
     */
    ~HashTable();

    /**
     * @brief 取值操作符
     * @param key 键
     * @return 值
     */
    T &operator[] (std::string key);
};

template <class T>
HashTable<T>::HashTable()
{
    // 初始化头指针
    memset(_head, 0, sizeof(_head));
}

template <class T>
HashTable<T>::~HashTable()
{
}

template <class T>
Hash_t HashTable<T>::hash(std::string str)
{
    static unsigned int seed = 131; // BKDRHash种子
    unsigned int hash = 0; // 哈希结果
    for (auto it : str)
    {
        hash = hash * seed + static_cast<unsigned int>(it);
    }
    // 返回哈希值并取模
    return (hash & 0x7fffFFFF) % HASH_MAX;
}

template <class T>
T &HashTable<T>::operator[] (std::string key)
{
    Hash_t hash_value = hash(key); // 取哈希
    // 遍历哈希表头
    for (auto i = _head[hash_value]; i; i = _edges[i].next)
    {
         // 获取到值, 返回引用
        if (_edges[i].key == key) return _edges[i].value;
    }
    // 没有该键, 创建新键值对
    _edges.emplace_back(Node{key, -1, _head[hash_value]});
    _head[hash_value] = _edges.size() - 1;
    // 返回新值引用
    return _edges[_edges.size() - 1].value;
}

#endif // HASHTABLEMODEL_H
