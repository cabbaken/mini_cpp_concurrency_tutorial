#include <mutex>
#include <thread>
#include <future>
#include <iostream>

std::mutex lock;
int        va = 0;

void t1()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t1 " << std::this_thread::get_id() << "\n";
        va = 1;
}
void t2()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t2 " << std::this_thread::get_id() << "\n";
        va = 2;
}

void t3()
{
        std::lock_guard<std::mutex> l(lock);
        std::cout << "t3 " << std::this_thread::get_id() << "\n";
        va = 3;
}

int main()
{
        std::packaged_task<void(void)> p1(t1);
        std::packaged_task<void(void)> p2(t2);
        std::packaged_task<void(void)> p3(t3);
        auto                           f3 = p3.get_future();
        {
                std::lock_guard<std::mutex> l(lock);
                std::cout << "main " << std::this_thread::get_id() << "\n";
        }
        p1();
        p2();

        std::jthread t(std::move(p3));

        p1.get_future().get();
        p2.get_future().get();
        f3.get();
        std::cout << va << "\n";
        return 0;
}