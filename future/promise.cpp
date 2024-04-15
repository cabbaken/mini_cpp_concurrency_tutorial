#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

void t1(std::promise<int> p)
{
        p.set_value(42);  // Notify future
}


int main()
{
        std::promise<int> p;
        std::future<int>  f = p.get_future();
        std::jthread      work_thread(t1, std::move(p));

        // future::get() will wait until the future has a valid result and retrieves it.
        // Calling wait() before get() is not needed
        std::cout << f.get() << '\n';

        return 0;
}