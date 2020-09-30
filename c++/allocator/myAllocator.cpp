
#include <atomic>
#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <set>

namespace myAllocator {

    std::atomic_int g_memory_used(0);
    template<typename T> 
    class Allocator: public std::allocator<T>{
    
    
    private:
        using Base = std::allocator<T>;
        using Pointer = typename std::allocator_traits<Base>::pointer;
        using SizeType = typename std::allocator_traits<Base>::size_type;

    public:
        Pointer allocate(SizeType n){
            g_memory_used.fetch_add(n * sizeof(T));
            return Base::allocate(n);
        }

        void deallocate(Pointer p, SizeType n){
            g_memory_used.fetch_sub(n * sizeof(T));
            Base::deallocate(p,n);
        }

    };
}


template <template <typename T, typename AllocT> typename ContainerT >
void test(){
    std::cout << __PRETTY_FUNCTION__ << std:: endl;
    std::cout << "Memory usage before: " << myAllocator::g_memory_used.load() << std::endl;
    
    ContainerT<int, myAllocator::Allocator<int>> containter;
    for(int i = 0; i < 1000; ++i){
        containter.insert(std::end(containter),i);
    }

    std::cout << "Memory Usage after: " << myAllocator::g_memory_used.load() << std::endl;

}


int main(){
    test<std::vector>();
    test<std::list>();

}
