# Lock
In fact, locks work as a role of making the critical section executes like atomic instruction. To access critical sections, you need to acquire lock around them.  
The basic function of lock:
- lock
- unlock

## std::mutex  
The mutex class is a synchronization primitive that can be used to protect critical section from being simultaneously accessed by multiple threads.  
You call `std::mutex::lock()` before accessing critical section, and call `std::mutex::unlock()` when leaving.  
example in [lock.cpp](lock.cpp)  

## std::lock_guard  
When a `std::lock_guard` object is created, it attempts to take ownership of the mutex it is given(perform `pthread_mutex_lock()`).  
When control leaves the scope in which the `std::lock_guard` object was created, the `std::lock_guard` is destructed and the mutex is released(perform `pthread_mutex_unlock()`).  
example in [lock_guard.cpp](lock_guard.cpp)

## std::unique_lock  
The use of `std::unique_lock` is similar to `std::mutex` and `std::lock_guard`. It takes ownership of the mutex when it is created, and you can control the locking and unlocking of the mutex.  
It is also provide RAII-style machanism for owning a mutex for the duration of a scoped block.  
The benefit of this is that in case some exception is thrown, you are sure that the mutex will unlock when leaving the scope where the `std::unique_lock` is defined.  
example in [unique_lock](unique_lock.cpp)