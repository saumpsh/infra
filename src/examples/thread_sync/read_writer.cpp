#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::shared_ptr<int> shared_data = std::make_shared<int>(0);

void reader() {
    while (true) {
        int value = *shared_data;
        std::cout << "Reader: Read value " << value << std::endl;
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void writer() {
    int i = 0;
    while (i<100) {
        *shared_data = *shared_data + 1;
        std::cout << "Writer: Wrote value " << *shared_data << std::endl;
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
