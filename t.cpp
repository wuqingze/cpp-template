#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

std::queue<int> task_queue;
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;
const int max_queue_size = 10;

void producer() {
    for (int i = 0; i < 100; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_producer.wait(lock, [] { return task_queue.size() < max_queue_size; });

        task_queue.push(i);
        std::cout << "Produced task " << i << std::endl;

        lock.unlock();
        cv_consumer.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [] { return !task_queue.empty(); });

        int task = task_queue.front();
        task_queue.pop();
        std::cout << "Consumed task " << task << std::endl;

        lock.unlock();
        cv_producer.notify_one();

        if (task == 99) break;
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
