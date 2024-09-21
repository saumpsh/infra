#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <chrono>

// Signal handler to catch SIGINT
std::atomic<bool> stop_thread(false);

void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "SIGINT received. Stopping thread..." << std::endl;
        stop_thread.store(true);  // Set the stop flag to true
    }
}

// Long-running thread function that takes the stop flag as a reference
void long_running_task(std::atomic<bool>& a_stop_flag) {
    while (!a_stop_flag.load()) {
        std::cout << "Thread running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate work
    }
    std::cout << "Thread stopping gracefully." << std::endl;
}

int main() {
    // Register the signal handler
    std::signal(SIGINT, signal_handler);

    // Start the long-running thread, passing the stop flag by reference
    std::thread worker(long_running_task, std::ref(stop_thread));

    // Wait for the worker thread to finish (after receiving SIGINT)
    worker.join();

    std::cout << "Main thread exiting." << std::endl;
    return 0;
}
