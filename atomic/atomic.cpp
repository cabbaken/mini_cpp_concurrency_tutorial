#include <atomic>
#include <thread>
#include <iostream>
#include <vector>

int              nonatomic_var = 0;
std::atomic<int> atomic_var(0);

void f()
{
        for (int i = 0; i < 10000; ++i)
        {
                nonatomic_var++;
                atomic_var++;
        }
}

signed main()
{
        {
                std::vector<std::jthread> t;
                for (int i = 0; i < 10; ++i)
                        t.emplace_back(f);
        }
        std::cout << nonatomic_var << "\n";
        std::cout << atomic_var << "\n";
        return 0;
}