#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <new>
#include <stdexcept>
#include <utility>

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
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

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

    void reallocate(size_type new_capacity) {
        pointer new_data = static_cast<pointer>(::operator new(new_capacity * sizeof(T)));
        size_type constructed = 0;

        try {
            for (; constructed < size_; ++constructed) {
                new (new_data + constructed) T(std::move(data_[constructed]));
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                new_data[i].~T();
            }
            ::operator delete(new_data);
            throw;
        }

        for (size_type i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        ::operator delete(data_);

        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector()
        : data_(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_type count)
        : data_(nullptr), size_(0), capacity_(0) {
        if (count == 0) {
            return;
        }

        data_ = static_cast<pointer>(::operator new(count * sizeof(T)));
        capacity_ = count;

        size_type constructed = 0;
        try {
            for (; constructed < count; ++constructed) {
                new (data_ + constructed) T();
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                data_[i].~T();
            }
            ::operator delete(data_);
            data_ = nullptr;
            capacity_ = 0;
            throw;
        }

        size_ = count;
    }

    Vector(size_type count, const T& value)
        : data_(nullptr), size_(0), capacity_(0) {
        if (count == 0) {
            return;
        }

        data_ = static_cast<pointer>(::operator new(count * sizeof(T)));
        capacity_ = count;

        size_type constructed = 0;
        try {
            for (; constructed < count; ++constructed) {
                new (data_ + constructed) T(value);
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                data_[i].~T();
            }
            ::operator delete(data_);
            data_ = nullptr;
            capacity_ = 0;
            throw;
        }

        size_ = count;
    }

    Vector(const Vector& other)
        : data_(nullptr), size_(0), capacity_(0) {
        if (other.size_ == 0) {
            return;
        }

        data_ = static_cast<pointer>(::operator new(other.size_ * sizeof(T)));
        capacity_ = other.size_;

        size_type constructed = 0;
        try {
            for (; constructed < other.size_; ++constructed) {
                new (data_ + constructed) T(other.data_[constructed]);
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                data_[i].~T();
            }
            ::operator delete(data_);
            data_ = nullptr;
            capacity_ = 0;
            throw;
        }

        size_ = other.size_;
    }

    Vector(Vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector(std::initializer_list<T> values)
        : data_(nullptr), size_(0), capacity_(0) {
        reserve(values.size());

        try {
            for (const auto& value : values) {
                push_back(value);
            }
        } catch (...) {
            clear();
            deallocate_storage();
            throw;
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            Vector temp(other);
            std::swap(data_, temp.data_);
            std::swap(size_, temp.size_);
            std::swap(capacity_, temp.capacity_);
        }

        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            deallocate_storage();

            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        return *this;
    }

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

    reference operator[](size_type index) {
        return data_[index];
    }

    const_reference operator[](size_type index) const {
        return data_[index];
    }

    reference at(size_type index) {
        if (index >= size_) {
            throw std::out_of_range("Vector::at index is out of range");
        }
        return data_[index];
    }

    const_reference at(size_type index) const {
        if (index >= size_) {
            throw std::out_of_range("Vector::at index is out of range");
        }
        return data_[index];
    }

    reference front() {
        return data_[0];
    }

    const_reference front() const {
        return data_[0];
    }

    reference back() {
        return data_[size_ - 1];
    }

    const_reference back() const {
        return data_[size_ - 1];
    }

    pointer data() {
        return data_;
    }

    const_pointer data() const {
        return data_;
    }


    iterator begin() {
        return data_;
    }

    const_iterator begin() const {
        return data_;
    }

    const_iterator cbegin() const {
        return data_;
    }

    iterator end() {
        return data_ + size_;
    }

    const_iterator end() const {
        return data_ + size_;
    }

    const_iterator cend() const {
        return data_ + size_;
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(cend());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(cbegin());
    }

    void clear() {
        destroy_elements();
    }

    void swap(Vector& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    void shrink_to_fit() {
        if (capacity_ == size_) {
            return;
        }

        if (size_ == 0) {
            deallocate_storage();
            return;
        }

        reallocate(size_);
    }

    void reserve(size_type new_capacity) {
        if (new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        new (data_ + size_) T(value);
        ++size_;
    }

    void push_back(T&& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        new (data_ + size_) T(std::move(value));
        ++size_;
    }

    template <typename... Args>
    reference emplace_back(Args&&... args) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        new (data_ + size_) T(std::forward<Args>(args)...);
        ++size_;

        return back();
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
            data_[size_].~T();
        }
    }

    void resize(size_type new_size) {
        if (new_size < size_) {
            for (size_type i = new_size; i < size_; ++i) {
                data_[i].~T();
            }
            size_ = new_size;
        } else if (new_size > size_) {
            reserve(new_size);
            size_type constructed = size_;

            try {
                for (; constructed < new_size; ++constructed) {
                    new (data_ + constructed) T();
                }
            } catch (...) {
                for (size_type i = size_; i < constructed; ++i) {
                    data_[i].~T();
                }
                throw;
            }

            size_ = new_size;
        }
    }

    void resize(size_type new_size, const T& value) {
        if (new_size < size_) {
            for (size_type i = new_size; i < size_; ++i) {
                data_[i].~T();
            }
            size_ = new_size;
        } else if (new_size > size_) {
            reserve(new_size);
            size_type constructed = size_;

            try {
                for (; constructed < new_size; ++constructed) {
                    new (data_ + constructed) T(value);
                }
            } catch (...) {
                for (size_type i = size_; i < constructed; ++i) {
                    data_[i].~T();
                }
                throw;
            }

            size_ = new_size;
        }
    }

    void assign(size_type count, const T& value) {
        clear();
        reserve(count);

        size_type constructed = 0;
        try {
            for (; constructed < count; ++constructed) {
                new (data_ + constructed) T(value);
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                data_[i].~T();
            }
            throw;
        }

        size_ = count;
    }

    void assign(std::initializer_list<T> values) {
        clear();
        reserve(values.size());

        size_type constructed = 0;
        try {
            for (const auto& value : values) {
                new (data_ + constructed) T(value);
                ++constructed;
            }
        } catch (...) {
            for (size_type i = 0; i < constructed; ++i) {
                data_[i].~T();
            }
            throw;
        }

        size_ = values.size();
    }

    iterator insert(const_iterator position, const T& value) {
        size_type index = static_cast<size_type>(position - cbegin());
        if (index > size_) {
            throw std::out_of_range("Vector::insert position is out of range");
        }

        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        if (index == size_) {
            new (data_ + size_) T(value);
            ++size_;
            return data_ + index;
        }

        new (data_ + size_) T(std::move(data_[size_ - 1]));

        for (size_type i = size_ - 1; i > index; --i) {
            data_[i] = std::move(data_[i - 1]);
        }

        data_[index] = value;
        ++size_;

        return data_ + index;
    }

    iterator insert(const_iterator position, T&& value) {
        size_type index = static_cast<size_type>(position - cbegin());
        if (index > size_) {
            throw std::out_of_range("Vector::insert position is out of range");
        }

        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        if (index == size_) {
            new (data_ + size_) T(std::move(value));
            ++size_;
            return data_ + index;
        }

        new (data_ + size_) T(std::move(data_[size_ - 1]));

        for (size_type i = size_ - 1; i > index; --i) {
            data_[i] = std::move(data_[i - 1]);
        }

        data_[index] = std::move(value);
        ++size_;

        return data_ + index;
    }

    iterator insert(const_iterator position, size_type count, const T& value) {
        size_type index = static_cast<size_type>(position - cbegin());
        if (index > size_) {
            throw std::out_of_range("Vector::insert position is out of range");
        }

        if (count == 0) {
            return data_ == nullptr ? nullptr : data_ + index;
        }

        Vector temp;
        temp.reserve(size_ + count);

        for (size_type i = 0; i < index; ++i) {
            temp.push_back(data_[i]);
        }

        for (size_type i = 0; i < count; ++i) {
            temp.push_back(value);
        }

        for (size_type i = index; i < size_; ++i) {
            temp.push_back(data_[i]);
        }

        swap(temp);

        return data_ + index;
    }

    iterator erase(const_iterator position) {
        size_type index = static_cast<size_type>(position - cbegin());
        if (index >= size_) {
            throw std::out_of_range("Vector::erase position is out of range");
        }

        for (size_type i = index; i + 1 < size_; ++i) {
            data_[i] = std::move(data_[i + 1]);
        }

        --size_;
        data_[size_].~T();

        return data_ + index;
    }

    iterator erase(const_iterator first, const_iterator last) {
        size_type first_index = static_cast<size_type>(first - cbegin());
        size_type last_index = static_cast<size_type>(last - cbegin());

        if (first_index > last_index || last_index > size_) {
            throw std::out_of_range("Vector::erase range is out of range");
        }

        if (first_index == last_index) {
            return data_ == nullptr ? nullptr : data_ + first_index;
        }

        size_type count = last_index - first_index;

        for (size_type i = first_index; i + count < size_; ++i) {
            data_[i] = std::move(data_[i + count]);
        }

        for (size_type i = size_ - count; i < size_; ++i) {
            data_[i].~T();
        }

        size_ -= count;

        return data_ + first_index;
    }
};


template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    for (typename Vector<T>::size_type i = 0; i < lhs.size(); ++i) {
        if (!(lhs[i] == rhs[i])) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs) {
    typename Vector<T>::size_type i = 0;

    while (i < lhs.size() && i < rhs.size()) {
        if (lhs[i] < rhs[i]) {
            return true;
        }
        if (rhs[i] < lhs[i]) {
            return false;
        }
        ++i;
    }

    return lhs.size() < rhs.size();
}

template <typename T>
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs < rhs);
}

template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs) noexcept {
    lhs.swap(rhs);
}

#endif
