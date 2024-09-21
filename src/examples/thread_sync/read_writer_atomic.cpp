#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include <atomic>

struct MyData {
    int value;
    std::string message;
    MyData(int _value, std::string _message):value(_value),message(_message){}
};

std::atomic<std::shared_ptr<MyData>> shared_data;

void reader() {
    while (true) {
        auto data = shared_data.load();
        if (data) {
            std::cout << "Reader: Value: " << data->value << ", Message: " << data->message << std::endl;
        } else {
            std::cout << "Reader: No data available" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void writer() {
    int i = 0;
    while (i<100) {
        // *shared_data = *shared_data + 1;
        // std::cout << "Writer: Wrote value " << *shared_data << std::endl;
        auto newData = std::make_shared<MyData>(5, "Saumil");
        shared_data.store(newData);
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
