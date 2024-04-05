#include<thread>
#include<iostream>

void f1(int& t)
{
	for(int i=0;i<100000;++i) {
		std::cout<<"f1 running\n";
		t++;
	}
}

class c1
{
public:
	int n=0;
	void f2()
	{
		for(int i=0;i<100000;++i) {
			n++;
			std::cout<<"c1 running\n";
		}
	}
};

class c2
{
public:
	int n=0;
	void operator()()
	{
		for(int i=0;i<100000;++i) {
			n++;
			std::cout<<"c2 running\n";
		}
	}
};

signed main()
{
	int n=0;
	c1 a;
	c2 b;

	// template< class F, class... Args > explict thread(F&& f, Args&&... args)
	std::thread t1(f1,std::ref(n));
	// thread(thread&& other) noexcept
	std::thread t2(std::move(t1));
	// thread() noexcept
	std::thread t3;
	// template< class F, class... Args > explict thread(F&& f, Args&&... args)
	std::thread t4(&c1::f2,&a);
	// template< class F, class... Args > explict thread(F&& f, Args&&... args)
	std::thread t5(b);
	
	t2.join();
	t4.join();
	t5.join();
	
	// t3.join(); error!
	std::cout<<n<<" "<<a.n<<" "<<b.n<<"\n";
	return 0;
}