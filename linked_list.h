
#include <cctype>
#include <iostream>
#include <cassert>
#include <string>
#include <utility>


using namespace std;

namespace utec
{
    template <typename T>
    struct node_t {
        T value_ = 0;
        node_t* next_ = nullptr;
    };

    inline namespace first {
        template <typename T>
        class linked_list_t {
        private:
            utec::node_t<T> * head_ = nullptr;
            utec::node_t<T> * tail_ = nullptr;
            size_t size_ = 0;
        public:
            // constructors
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);
            linked_list_t&operator=(const linked_list_t& other);
            linked_list_t(linked_list_t&& other) noexcept ;
            linked_list_t&operator=(linked_list_t&& other) noexcept ;

            // destroyers
            ~linked_list_t();

            // add operations
            void push_front(T value);
            void push_back(T value);
            void insert(size_t index, T value);

            // remove operations
            void pop_front();
            void pop_back();
            void erase(size_t index);

            // traversal operations
            T& item(size_t index);
            const T& item(size_t index) const;

            // get size of list
            size_t size() const;
        };
    }
}


