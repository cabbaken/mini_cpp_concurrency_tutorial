# Condition variable
## std::condition_variable  
`std::condition_variable` is a synchronization primitive used with a `std::mutex` to block one or more threads until another thread both modifies a shared variable (the condition) and notifies the `std::condition_variable`.  
In short, when you have at least two threads and you want to make one thread run when certain condition is met, you use condition variable.  

To use condition variable, the thread that wants to modify the shared variable should:
1. Acquire a `std::mutex`.
2. If the lock is owned, modify the shared variable.
3. Call `std::condition_variable::notify_one()`.  

The other thread that wants to wait for the condition variable to change needs to:
1. Acquire a `std::mutex`(usually be `std::unique_lock<std::mutex>`) to protect the shared variable.  
2. Call `std::condition_variable::wait()`(this function atomically releases the mutex and suspends thread execution until the condition variable is notified).  
3. Check the condition and determine whether to run based on  the conditon.  

## std::condition_variable::wait()  
- `std::condition_variable::wait(std::unique_lock<std::mutex>& lock, Predicate pred)`  
	- `lock` is the lock which must be locked by the calling thread.  
	- `pred` is the predicate to check whether the waiting can be completed. It should be a FunctionObject.  

`wait` causes the current thread to block until the condition variable is notified or a spurious wakeup occurs.  
`wait` atomically calls `lock.unlock()` and blocks this thread.  
This thread will be unblocked when `notify_one` or `notify_all` is executed.  
When this thread unblocked, call `lock.lock()`. 

## std::condition_variable::notify()  
- `std::condition_variable::notify_one()`  
If any threads are waiting on this condition variable, calling `notify_one` unblocks one of the waiting threads.

- `std::condition_variable::notify_all()`  
If any threads are waiting on this condition variable, calling `notify_all` unblocks all of the waiting threads.




example in [condition_variable](condition_variable.cpp)