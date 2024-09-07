#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// 全局变量 用于线程切换
int turn = 0;

// 互斥锁
mutex mtx;

// 条件变量 用于进程间通信
condition_variable cv;

// 线程函数
void thread_func(int id) {
	int count = 0;
	char c = (id == 0) ? 'A' : 'B';

	while (1) {
		unique_lock<mutex> lck(mtx);
		cv.wait(lck, [id] {return turn == id; });
		cout << c << flush;
		turn = (id + 1) % 2;
		cv.notify_one();
		++count;

		// 检查是否达到最大输出次数
		if (count >= 10) { // 输出10次"AB"
			lck.unlock();
			cv.notify_all();
			return;
		}
	}
}


//int main() {
//	thread t1(thread_func, 0);
//	thread t2(thread_func, 1);
//
//	// 等待线程结束
//	t1.join();
//	t2.join();
//
//	return 0;
//}