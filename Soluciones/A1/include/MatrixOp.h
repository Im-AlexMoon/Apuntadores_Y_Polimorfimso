/**
 * @file      MatrixOp.h
 * @brief     Declaración de la clase MatrixOp:
 *            matriz densa mínimal con memoria dinámica, getters y setters.
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

    void set(int i, int j, double v);

    double get(int i, int j) const;

    int  getRows() const { return rows_; }

    int  getCols() const { return cols_; }

private:
    double* data_;   ///< buffer contiguo rows_·cols_ elementos
    int     rows_;   ///< número de filas
    int     cols_;   ///< número de columnas
};

#endif // MATRIXOP_H
