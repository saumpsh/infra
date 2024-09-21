#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::mutex mtx;

struct MyData {
    int value;
    std::string message;
    MyData(int _value, std::string _message):value(_value),message(_message){}
    // void setter(int _value, std::string _message){
    //     value = _value;
    //     message = _message;
    // }

};

std::shared_ptr<MyData> shared_data = std::make_shared<MyData>(5, "Parag");

void reader() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Reader: Value: " << shared_data->value << ", Message: " << shared_data->message << std::endl;
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
            if(i%2 == 0){
                shared_data->value = 4;
                shared_data->message = "Kaushil";
            }else{
                shared_data->value = 7;
                shared_data->message = "Saumil";
            }
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
