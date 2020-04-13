//
// Created by utec on 4/11/20.
//
#include<iostream>
#include "linked_list.h"

template <typename T>
utec::first::linked_list_t<T>::linked_list_t(const utec::linked_list_t<T>&other) {
    if (other.size() == 0) {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    else {
        size_ = other.size_;
        auto a = other.head_;
        auto b = other.tail_;
        head_ = new node_t<T>{ a->value_, a.next };
        tail_ = new node_t<T>{ b->value_, nullptr };
    }
}
template <typename T>
utec::linked_list_t<T>&utec::first::linked_list_t<T>::operator=(const utec::linked_list_t<T>&other) {
    if (other.size_ == 0) {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return *this;
    }
    else if (this == other) 
        return *this;
    while (--size_)
        pop_front();
    
    size_t temp_i = other.size();
    size_ = temp_i;
    auto temp = other.head_;
    head_ = new node_t<T>{ temp.value_, nullptr };
    

    while (--temp_i) {
        temp = temp->next_;
        this->push_back(temp->value_);
    }
    tail_ = temp;

    return *this;
}

template <typename T>
utec::first::linked_list_t<T>::linked_list_t(utec::linked_list_t<T>&&other) noexcept {
    size_ = move(other.size());
    head_ = move(other.head_);
    tail_ = move(other.tail_);
    other.head_ = nullptr;
    other.tail_ = nullptr;
}
template <typename T>
utec::linked_list_t<T>&utec::first::linked_list_t<T>::operator=(utec::linked_list_t<T>&&other) noexcept {
    auto temp = head_;
    while (temp != nullptr) {
        auto next = temp.next_;
        delete temp;
        temp = next;
    }
    size_ = move(other.size());
    head_ = move(other.head_);
    tail_ = move(other.tail_);
    other.head_ = nullptr;
    other.tail_ = nullptr;
     
    // TO DO
    return *this;
}
template <typename T>
utec::first::linked_list_t<T>::~linked_list_t() {
    auto temp = head_;
    while (temp != nullptr) {
        auto next = temp->next_;
        delete temp;
        temp = next;
    }
    size_ = 0;
    head_ = tail_ = nullptr;

}
template <typename T>
void utec::first::linked_list_t<T>::push_front(T value) {

    /*
    auto node = new node_t{value, head_}
    head_ = node;
    */
    head_ = new node_t<T>{value, head_};
    if (tail_ == nullptr) tail_ = head_;
    size_++;

}
template <typename T>
void utec::first::linked_list_t<T>::push_back(T value) {
    if(tail_!=nullptr){
        node_t* temp = new node_t<T>{ value,nullptr };
        tail_->next_ = temp;
        tail_ = temp;
        temp = nullptr;

        size_++; 
        
    }
    else { tail_ = new node_t<T>{ value,nullptr }; size_++; }
    if (head_ == nullptr) head_ = tail_;
}
template <typename T>
void utec::first::linked_list_t<T>::insert(size_t index, T value) {
    if (index > size_) { std::cout << "Error"; }
    else {
        if (index == 0) {
            head_ = new node_t<T>{ value, head_ };
            if (tail_ == nullptr) tail_ = head_;
            size_++;
        }
        else if (index == size_) {
            if (tail_ != nullptr) {
                node_t* temp = new node_t<T>{ value,nullptr };
                tail_->next_ = temp;
                tail_ = temp;
                temp = nullptr;

                size_++;

            }
            else { tail_ = new node_t<T>{ value,nullptr }; size_++; }
            if (head_ == nullptr) head_ = tail_;}
        else {
            auto temp = head_;
            while (--index != 0)
                temp = temp->next;
            temp->next = new node_t<T>{ item,temp->next };
            size++;
        }
            
        }
    }


template <typename T>
void utec::first::linked_list_t<T>::pop_front() {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto next = head_->next_;
        delete head_;
        head_ = next;
        size_--;
    }
}
template <typename T>
void utec::first::linked_list_t<T>::pop_back() {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto temp = head_;
        int temp_2 = size - 1;
            while (--temp_2 != 0)
                temp = temp->next;
        delete tail_;
        tail_ = temp;
        temp = nullptr;
            size--;
    }
    
}
template <typename T>
void utec::first::linked_list_t<T>::erase(size_t index) {
    if (index > size_) { std::cout << "Error"; }
    else {
        if (index == 0) {
            if (head_ == tail_) {
                delete head_;
                head_ = tail_ = nullptr;
                size_ = 0;
            }
            else {
                auto next = head_->next_;
                delete head_;
                head_ = next;
                size_--;
            }
        }
        else if (index == size_) {
            if (head_ == tail_) {
                delete head_;
                head_ = tail_ = nullptr;
                size_ = 0;
            }
            else {
                auto temp = head_;
                int temp_2 = size - 1;
                while (--temp_2 != 0)
                    temp = temp->next;
                delete tail_;
                tail_ = temp;
                temp = nullptr;
                size_--;
            }
            
        }
        else {
            index++;
            auto temp = head_;
            auto temp_2;
            auto temp_3;
            while (--index != 0) {
                if (index == 2)
                {
                     temp_2 = temp;
                }
                else if (index == 1) {
                     temp_3 = temp;
                }

                temp = temp->next;
            }
            temp->next =temp_3;
            delete temp_2;
            size++;
        }

    }
}
template <typename T>
T &utec::first::linked_list_t<T>::item(size_t index) {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}
template <typename T>
const T &utec::first::linked_list_t<T>::item(size_t index) const {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}
template <typename T>
size_t utec::first::linked_list_t<T>::size() const {
    return size_;
}
