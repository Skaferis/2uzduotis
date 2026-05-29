#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

template <typename T>
class Vector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = value_type*;
    using const_iterator = const value_type*;

private:
    pointer data_;
    size_type size_;
    size_type capacity_;

    void destroy_elements() {
        for (size_type i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        size_ = 0;
    }

    void deallocate_storage() {
        ::operator delete(data_);
        data_ = nullptr;
        capacity_ = 0;
    }

public:
    Vector()
        : data_(nullptr), size_(0), capacity_(0) {}

    ~Vector() {
        clear();
        deallocate_storage();
    }

    size_type size() const {
        return size_;
    }

    size_type capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        destroy_elements();
    }
};

#endif
