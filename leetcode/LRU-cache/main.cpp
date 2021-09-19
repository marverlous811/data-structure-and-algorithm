#include <stdio.h>
#include <unordered_map>
#include <list>

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/

class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
	}
	~LRUCache() {
		mapper.clear();
		cache.clear();
	}

public:
	int get(int key) {
		if (mapper.find(key) == mapper.end()) {
			return -1;
		}
		auto retval =  mapper[key];
		this->updateToCache(key);
		return retval;
	}

	void put(int key, int value) {
		if (!isValueValid(value) || !isKeyValid(key)) {
			return;
		}
		mapper[key] = value;
		this->updateToCache(key);
	}

	void printAll() {
		for (auto x : mapper)
			printf("{%d %d} ", x.first, x.second);
		printf("\n");
	}

private:
	bool isValueValid(int value) {
		return value >= 0 && value <= 100000;
	}

	bool isKeyValid(int key) {
		return key >= 0 && key < 10000;
	}

	void updateToCache(int key) {
		if (stat.find(key) != stat.end()) {
			cache.erase(stat[key]);
		}
		cache.push_front(key);
		stat[key] = cache.begin();
		if (mapper.size() > size) {
			auto lastKey = cache.back();
			cache.pop_back();
			mapper.erase(mapper.find(lastKey));
			stat.erase(stat.find(lastKey));
		}
	}
private:
	std::unordered_map<int, int> mapper;
	std::unordered_map<int, std::list<int>::iterator> stat;
	std::list<int> cache;
	int size;
};

int main() {
	auto cache = new LRUCache(2);
	cache->put(1, 1);
	cache->put(2, 2);
	cache->printAll();
	printf("find value of key %d: %d\n", 1,cache->get(1));
	cache->put(3, 3);
	printf("find value of key %d: %d\n", 2, cache->get(2));
	cache->put(4, 4);
	cache->printAll();
	printf("find value of key %d: %d\n", 1, cache->get(1));
	printf("find value of key %d: %d\n", 3, cache->get(3));
	printf("find value of key %d: %d\n", 4, cache->get(4));


	return 0;
}