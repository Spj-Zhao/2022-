template<class T>
class my_sharedPtr {
    int* count;
    T* ptr;
    my_sharedPtr() :ptr(nullptr), count(new int){};
    my_sharedPtr(T* m) : ptr(m), (new int)(1) {
        *count = 1;
    };
    ~my_sharedPtr() {
        --(*count);
        if (*count == 0) {
            delete count;
            delete ptr;
            count = nullptr;
            ptr = nullptr;
        }
    }
    my_sharedPtr(const my_sharedPtr<T>& my) {
        count = my.count;
        ptr = my.ptr;
        ++(*count);
    }

    //operator = 当使用一个shared_ptr给另一个shared_ptr赋值的时候这里需要注意
    //    由于指针指向发生变化，原来的_ptr指针的引用计数要–，且当达到了0的时候要注意回收原来指针的空间
    //    _ptr又指向了新的_ptr, 则新的_ptr指针的引用计数要++
    my_sharedPtr& oprerator= (const my_sharedPtr<T> & my){
        if (my == this) {
            return this;
        }
        if (--*count == 0) {
            delete count;
            delete ptr;
            count = nullptr;
            ptr = nullptr;
        }
        ++*my.count;
        count = my.count;
        ptr = my.ptr;
        return *this;
    }

    T* operator->() {
        return ptr;
    }
    
    //operator* 解引用运算符，直接返回底层指针的引用，即共享的地址空间内容
    T& operator*() {
        return *ptr;
    }


};