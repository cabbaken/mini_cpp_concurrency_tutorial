# Thread
## std::thread  
### Constructor  
- `thread() noexcept`  
Creates a new std::thread object which does not represent a thread, so this instance should not call `std::thread::join()`.  

- `thread(thread&& other) noexcept`  
Move constructor. Constructs the `std::thread` object to represent the thread of execution that was represented by other. After this call other no longer represents a thread of execution.  
	- `other`: another thread object to construct this thread object with.  

- `template< class F, class... Args > explict thread(F&& f, Args&&... args)`  
Creates a new `std::thread` object and associates it with a thread of execution. The new thread of execution will start executing.  
	- `f`: Callable object to execute in the new thread (a callable object can be seen as a function pointer, or an object of a class type that overloads operator().)  
	- `args`: arguments to pass to the new function.  
### Note
- You can analogise thread constructor to `pthread_create()` in POSIX system, `std::thread::join()` to `pthread_join()`.  
- Threads begin execution immediately upon construction of the associated thread object.  
- The arguments to the thread function are moved or copied by value. If a reference argument needs to be passed to the thread function, it has to be wrapped (e.g., with std::ref or std::cref).  
	```C++
	std::thread t1(f1,std::ref(n));
	```
example in [thread.cpp](thread.cpp)
## std::jthread
### Note
`std::jthread` has the same general behavior as `std::thread`, except that jthread automatically rejoins on destruction, and can be cancelled/stopped in certain situations.  
This class need C++20.  
example in [jthread.cpp](jthread.cpp)