#include "HashSet.h"
#include <algorithm>

HashSet::HashSet(unsigned int totalBuckets)
        :totalBuckets{totalBuckets}, table{totalBuckets}, totalElements{0}
{
}

void HashSet::insert(std::int64_t value)
{
    const auto hash{calculateHash(value)};
    auto it{std::find(table.at(hash).begin(), table.at(hash).end(), value)};
    const auto valueNotFound{it == table.at(hash).end()};
    if(valueNotFound)
    {
        table[hash].push_back(value);
        totalElements++;
    }
}

void HashSet::erase(std::int64_t value)
{
    const auto hash{calculateHash(value)};
    for(const auto it : table.at(hash))
    {
        if(it == value)
        {
            table.at(hash).remove(it);
            totalElements--;
            return;
        }
    }
}

bool HashSet::contains(std::int64_t value) const
{
    const auto hash{calculateHash(value)};
    auto it{std::find(table.at(hash).begin(), table.at(hash).end(), value)};
    return it not_eq table.at(hash).end();
}

unsigned int HashSet::size() const
{
    return totalElements;
}

unsigned int HashSet::collisionCount() const
{
    unsigned int totalCollisions{0};
    for(const auto& valueList : table)
    {
        const auto valueListSize{valueList.size()};
        const auto moreThanOneElement{valueListSize > 1};
        if(moreThanOneElement)
        {
            totalCollisions+=(valueListSize-1);
        }
    }
    return totalCollisions;
}

unsigned int HashSet::calculateHash(std::int64_t value) const
{
    return value % totalBuckets;
}