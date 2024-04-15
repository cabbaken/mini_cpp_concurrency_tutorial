#include <mutex>
#include <thread>
#include <future>
#include <iostream>

std::mutex lock;

void t1()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t1 " << std::this_thread::get_id() << "\n";
}
void t2()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t2 " << std::this_thread::get_id() << "\n";
}

void t3()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t3 " << std::this_thread::get_id() << "\n";
}

int main()
{
        auto f1 = std::async(std::launch::async, t1);
        auto f2 = std::async(std::launch::deferred, t2);
        auto f3 = std::async(t3);
        {
                std::lock_guard<std::mutex> l(lock);
                std::cout << "main " << std::this_thread::get_id() << "\n";
        }

        f1.get();
        f2.get();
        f3.get();

        return 0;
}