#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::mutex mtx;
std::shared_ptr<int> shared_data = std::make_shared<int>(0);

void reader() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            int value = *shared_data;
            std::cout << "Reader: Read value " << value << std::endl;
        }
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void writer() {
    int i = 0;
    while (i<100) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            *shared_data = *shared_data + 1;
            std::cout << "Writer: Wrote value " << *shared_data << std::endl;
        }
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        i++;
    }
}

int main() {
    std::thread reader_thread(reader);
    std::thread writer_thread(writer);

    reader_thread.join();
    writer_thread.join();

    return 0;
}

/**
Efficiency: Continuously acquiring and releasing the lock, even when there's no need to modify the shared data, can introduce unnecessary overhead.
Starvation: If the writer is constantly modifying the data, readers might experience starvation as they're constantly blocked by the writer.
Read-write synchronization: This approach doesn't differentiate between readers and writers, which can lead to performance issues in scenarios with many readers and few writers.
 */
