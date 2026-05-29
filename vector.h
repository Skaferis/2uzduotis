#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#include <cstddef>
#include <memory>

/**
 * @brief Nuosavas dinaminio masyvo konteineris, kuriamas kaip std::vector alternatyva.
 *
 * Pirmame etape realizuotas tik klasės karkasas, tipų sinonimai
 * ir bazinės informacinės funkcijos: size(), capacity(), empty().
 * Kitos funkcijos bus pridedamos atskirais commit'ais.
 *
 * @tparam T saugomo elemento tipas
 * @tparam Allocator atminties skirstytuvas
 */
template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = value_type*;
    using const_iterator = const value_type*;

private:
    allocator_type alloc_;
    pointer data_;
    size_type size_;
    size_type capacity_;

public:
    /**
     * @brief Sukuria tuščią Vector konteinerį.
     */
    Vector() noexcept(noexcept(allocator_type()))
        : alloc_(allocator_type()), data_(nullptr), size_(0), capacity_(0) {}

    /**
     * @brief Grąžina elementų kiekį konteineryje.
     */
    size_type size() const noexcept {
        return size_;
    }

    /**
     * @brief Grąžina rezervuotos atminties talpą.
     */
    size_type capacity() const noexcept {
        return capacity_;
    }

    /**
     * @brief Patikrina, ar konteineris tuščias.
     */
    bool empty() const noexcept {
        return size_ == 0;
    }
};

#endif
