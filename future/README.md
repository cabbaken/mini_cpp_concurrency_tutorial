# Future  
## std::future  
`std::future` can be used to access the result of asynchronous operations.  
A `std::future` object should be created via `std::async()`, `std::packaged_task` or `std::promise`.  
When you want the return value of a asynchronous function, you can get it via `std::future::get()`.  

## std::async()  
```c++
template < class F, class... Args >
std::future<...> std::async( std::launch policy, F&& f,Args&&... args )
```
This function runs the function `f` asynchronously and returns a `std::future` that hold the return value of the function `f`.  
This function will return immediately. We can get the return value of `f` by the `std::future::get()`.  
- `policy`: Can be `std::launch::async` and `std::lanuch::deferred`. Default value is `std::launch::async|std::launch::deferred`.  
- `f`: Callable object to call  
- `args`: Parameters to pass to `f`  

### `policy`
- `std::launch::async`: start a new thread to run the function.  
- `std::launch::deferred`: start to run the function when `std::future` called.  

If `std::launch::async` is not be set, `f` will run in current thread.  
It is not sure that new thread will be created if `policy` is `std::launch::deferred|std::launch::async` because of the different implemention of different compiler.  
example in [async.cpp](async.cpp)  

## std::promise  
`std::promise` provides a way to store a value that is later acquired asynchronously via a `std::future` object created by the `std::promise`.  
In short, `std::promise` is something like condition variable, but it can transfer value with `std::promise::set_value()`.  
You can get the value by the `std::future` that `std::promise::get_future()` provides.  
You can use `std::future::wait()` to wait for the corresponding `std::promise::set_value()`.  
example in [promise.cpp](promise.cpp)
## std::packaged_task  
This class wraps some callable object (function, lambda expression, bind expression, or other function object) so that it can be invoked asynchronously.  
The benefit of using `std::packaged_task` is linking a callable object to a `std::future`.  
You can get the return value of the callable object in different thread by `std::future`.  
example in [packaged_task.cpp](packaged_task.cpp)