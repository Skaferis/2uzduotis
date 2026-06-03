#ifndef PROGRAMOS_VECTOR_H
#define PROGRAMOS_VECTOR_H

#ifdef NUOSAVAS_VECTOR
#include "vector.h"

template <typename T>
using ProgramosVector = Vector<T>;

#else
#include <vector>

template <typename T>
using ProgramosVector = std::vector<T>;

#endif

#endif
