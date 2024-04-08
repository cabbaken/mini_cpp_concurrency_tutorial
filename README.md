# Modern C++ concurrency lib minimum tutorial
## Intro
Modern C++ includes built-in support for:
- [Thread](#thread)
- [Atomic](#atomic)
- [Mutex](#mutex)
- [Condition variable](#condition-variable)
- [Future](#future)

It's confuse when you see these classes, and I will write this note to record my learning process.  
(This is a simple tutorial for modern c++ beginner.)

## [Thread](thread/README.md#thread)
[Thread](https://en.wikipedia.org/wiki/Thread_(computing)) is the base of concurrency. Threads allow multiple functions to execute concurrently.  
- [thread](thread/README.md#stdthread)  
- [jthread](thread/README.md#stdjthread)  

## [Atomic](atomic/README.md#atomic)
- [atomic](atomic/README.md#stdatomic)  

## Lock  
You know something about POSIX lock API such as `pthread_mutex_init()`, `pthread_mutex_lock()`, `pthread_mutex_unlock()`.  
The class `std::mutex` encapsulate pthread lock lib.
- [mutex](lock/README.md#stdmutex)  

The class `std::lock_guard` is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
- [lock_guard](lock/README.md#stdlock_guard)  

The use of `std::unique_lock` is similar to `std::mutex`.  
- [unique_lock](lock/README.md#stdunique_lock)

## Condition variable

## Future