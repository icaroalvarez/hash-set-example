#pragma once
#include <vector>
#include <list>
#include <cstdint>

class HashSet
{
public:
    explicit HashSet(unsigned int totalBuckets);

    void insert(std::int64_t value);

    void erase(std::int64_t value);

    bool contains(std::int64_t value) const;

    unsigned int size() const;

    unsigned int collisionCount() const;

private:
    unsigned int totalBuckets;
    std::vector<std::list<std::int64_t>> table;
    unsigned int totalElements;

    unsigned int calculateHash(std::int64_t value) const;
};



