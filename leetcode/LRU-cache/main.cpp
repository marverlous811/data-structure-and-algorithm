#include <stdio.h>
#include <unordered_map>
#include <list>

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
		if (cache.size() > 0) {
			cache.remove(key);
		}
		cache.push_front(key);
		if (mapper.size() > size) {
			auto lastKey = cache.back();
			cache.pop_back();
			mapper.erase(mapper.find(lastKey));
		}
	}
private:
	std::unordered_map<int, int> mapper;
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