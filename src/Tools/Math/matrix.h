#ifndef MATRIX_H
#define MATRIX_H

#include "../MIPP/mipp.h"

// ------------------------------------------------------------------------------------------- special function headers

// M   - INTEGER.
//      On entry,  M  specifies  the number  of rows  of the
//      matrix op( A )  and of the  matrix  C.  M  must  be
//      at least  zero.  Unchanged on exit.

// N   - INTEGER.
//      On entry,  N  specifies the number  of columns of the
//      matrix op( B ) and the number of columns of the
//      matrix C. N must be at least zero.  Unchanged on
//      exit.

// K   - INTEGER.
//      On entry,  K  specifies  the number of columns of the
//      matrix op( A ) and the number of rows of the matrix
//      op( B ). K must be at least  zero.  Unchanged on
//      exit.

// complex general matrix multiplication: C = A * B, tB is B transposed, tC is C transposed
template <typename T> 
inline void cgemm(const int M, const int N, const int K,
                  const mipp::vector<T> &A, 
                  const mipp::vector<T> &tB, 
                        mipp::vector<T> &tC) __attribute__((always_inline));

// keep only the real part in C
template <typename T> 
inline void cgemm_r(const int M, const int N, const int K, 
                    const mipp::vector<T> &A, 
                    const mipp::vector<T> &tB, 
                          mipp::vector<T> &tC) __attribute__((always_inline));


#include "matrix.hxx"

#endif /* MATRIX_H */