#include <leetcode/problems/LC460_LFUCache.h>

LeetCode::Problems::LC460::LFUCache::LFUCache(const int capacity) : capacity(capacity), size(0) {
}

int LeetCode::Problems::LC460::LFUCache::get(const int key) {
    increaseFrequency(key);
    return read(key);
}

void LeetCode::Problems::LC460::LFUCache::put(const int key, const int value) {
    if (const int oldValue = read(key);
        oldValue == -1) {
        size++;
        if (size > capacity)
            evict();
    }

    write(key, value);
    increaseFrequency(key);
}

int LeetCode::Problems::LC460::LFUCache::read(const int key) {
    if (const auto itr = keyIteratorPairMap.find(key);
        itr != keyIteratorPairMap.end())
        return itr->second.second->second;

    return -1;
}

void LeetCode::Problems::LC460::LFUCache::write(const int key, const int value) {
    if (const auto itr = keyIteratorPairMap.find(key);
        itr != keyIteratorPairMap.end()) {
        *itr->second.second = {key, value};
        return;
    }

    auto outerListItr = allValues.begin();
    if (outerListItr == allValues.end() || outerListItr->first != 0) {
        allValues.emplace_front(0, InnerList());
        outerListItr = allValues.begin();
    }

    auto &[_, innerList] = *outerListItr;
    innerList.emplace_front(key, value);

    auto innerListItr = innerList.begin();

    keyIteratorPairMap[key] = {outerListItr, innerListItr};
}

void LeetCode::Problems::LC460::LFUCache::increaseFrequency(const int key) {
    const auto itr = keyIteratorPairMap.find(key);

    if (itr == keyIteratorPairMap.end())
        return;

    const auto [oldOuterListItr, oldInnerListItr] = itr->second;

    auto &outerList = allValues;
    auto &[oldFrequency, oldInnerList] = *oldOuterListItr;
    const auto value = oldInnerListItr->second;

    const int newFrequency = oldFrequency + 1;

    auto newOuterListItr = std::next(oldOuterListItr);
    if (newOuterListItr == outerList.end() || newOuterListItr->first != newFrequency)
        newOuterListItr = outerList.insert(newOuterListItr, {newFrequency, InnerList()});

    auto &newInnerList = newOuterListItr->second;

    newInnerList.emplace_front(key, value);
    auto newInnerListItr = newInnerList.begin();
    keyIteratorPairMap[key] = {newOuterListItr, newInnerListItr};

    oldInnerList.erase(oldInnerListItr);
    if (oldInnerList.empty())
        outerList.erase(oldOuterListItr);
}

void LeetCode::Problems::LC460::LFUCache::evict() {
    const auto key = allValues.front().second.back().first;
    keyIteratorPairMap.erase(key);
    allValues.front().second.pop_back();
    if (allValues.front().second.empty())
        allValues.pop_front();
    size--;
}
