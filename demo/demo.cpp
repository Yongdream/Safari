#include <pthread.h>
#include <iostream>
#include <queue>
#include <unistd.h>

using namespace std;

template<typename T>
class BlockQueue {
private:
	bool isFull() {
		return que.size() == _capacity;
	}

	bool isEmpty() {
		return que.empty();
	}

public:
	BlockQueue(int cap = 5) :_capacity(cap) {
		pthread_init_mutex(&_mutex, NULL);
		pthread_init_cond(&_full, NULL);
		pthread_init_cond(&_empty, NULL);
	}
	~BlockQueue() {
		pthread_mutex_destory(&_mutex);
		pthread_cond_destory(&_full);
		pthread_cond_destory(&_empty);
	}
public:
	void push(const T& data) {
		pthread_mutex_lock(&_mutex);
		while (isFull()) {
			pthread_cond_wait(&_full, &_mutex);
		}
		que.push(data);
		pthread_cond_signal(&_empty);
		pthread_mutex_unlock(&_mutex);
	}
	
	void pop(T& data) {
		pthread_mutex_lock(&_mutex);
		while (isEmpty()) {
			pthread_cond_wait(&_empty, &_mutex);
		}
		data = que.front();
		que.pop();
		pthread_cond_signal(&_full);
		pthread_mutex_unlock(&_mutex);
	}
private:
	queue<T> que;
	int _capacity;
	pthread_mutex_t _mutex;
	pthread_cond_t _full;
	pthread_cond_t _empty;
};