#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// ȫ�ֱ��� �����߳��л�
int turn = 0;

// ������
mutex mtx;

// �������� ���ڽ��̼�ͨ��
condition_variable cv;

// �̺߳���
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

		// ����Ƿ�ﵽ����������
		if (count >= 10) { // ���10��"AB"
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
//	// �ȴ��߳̽���
//	t1.join();
//	t2.join();
//
//	return 0;
//}