# Atomic  
Q: Why we need "atomic"?  
A: When multiple threads write to the same variable, the final value of the variable may be false. 
Why does this problem exist?  
You can find the answer in 26.4 of [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)

## std::atomic
Each instantiation and full specialization of the `std::atomic` template defines an atomic type.  
`std::atomic` is neither copyable nor movable.  
if you want to use atomic variable, you should specify the type you want your variable be(use template to implement generics).  
You can find the example in [atomic.cpp](atomic.cpp).  