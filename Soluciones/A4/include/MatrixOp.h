/**
 * @file      MatrixOp.h
 * @brief     MatrixOp (Ej. A1–A4).
 * @date      2025-05-30
 * @author    Alexander Luna
 */
#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdexcept>
#include <cstddef>
#include <algorithm>   

using OpFunc = double (*)(double, double);   

class MatrixOp
{
public:
    MatrixOp(int rows, int cols);
    ~MatrixOp();

    // A1
    void   set(int i, int j, double v);
    double get(int i, int j) const;

    // A2
    void   add  (const MatrixOp* other, MatrixOp* result) const;

    // A3
    void   apply(const MatrixOp* A,
                 const MatrixOp* B,
                 MatrixOp*       out,
                 OpFunc          op) const;

    // A4
    void   forEachDiagonal(void (MatrixOp::*fn)(int, int) const) const;

    void   printAt(int i, int j) const;

    int    getRows() const { return rows_; }
    int    getCols() const { return cols_; }

private:
    double* data_;
    int     rows_;
    int     cols_;
};

#endif // MATRIXOP_H

