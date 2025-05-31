/**
 * @file      MatrixOp.h
 * @brief     Declaración de la clase MatrixOp (Ej. A1 + A2).
 * @date      2025-05-30
 * @author    Alexander Luna
 */
#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdexcept>
#include <cstddef>

class MatrixOp
{
public:
    MatrixOp(int rows, int cols);
    ~MatrixOp();

    void   set(int i, int j, double v);
    double get(int i, int j) const;

    void   add(const MatrixOp* other, MatrixOp* result) const;

    int    getRows() const { return rows_; }
    int    getCols() const { return cols_; }

private:
    double* data_;
    int     rows_;
    int     cols_;
};

#endif // MATRIXOP_H
