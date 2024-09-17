#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool
{
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    void enqueueTask(const std::function<void()> &task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

    void workerThread();
};

ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
    for (size_t i = 0; i < numThreads; ++i)
    {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers)
    {
        worker.join();
    }
}

void ThreadPool::enqueueTask(const std::function<void()> &task)
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.push(task);
    }
    condition.notify_one();
}

void ThreadPool::workerThread()
{
    while (true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this]
                           { return stop || !tasks.empty(); });
            if (stop && tasks.empty())
            {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

void printTable(int number, int start, int end, int threadNumber)
{
    for (int i = start; i <= end; ++i)
    {
        std::cout << "Thread " << threadNumber << ": " << number << " * " << i << " = " << number * i << std::endl;
    }
}

int main()
{
    int number = 7;     // Number to print the multiplication table for
    int tableSize = 20; // The size of the multiplication table (1 to 20)
    int numThreads = 4; // Number of threads to use

    ThreadPool pool(numThreads);

    int chunkSize = tableSize / numThreads;
    int remainder = tableSize % numThreads;

    int start = 1;
    for (int i = 0; i < numThreads; ++i)
    {
        int end = start + chunkSize - 1;
        if (i == numThreads - 1)
        {
            end += remainder; // Assign the remainder to the last thread
        }
        pool.enqueueTask([=]
                         { printTable(number, start, end, i + 1); });
        start = end + 1;
    }

    // Destructor of ThreadPool will wait for all tasks to finish

    std::cout << "All tasks have been enqueued." << std::endl;
    return 0;
}

