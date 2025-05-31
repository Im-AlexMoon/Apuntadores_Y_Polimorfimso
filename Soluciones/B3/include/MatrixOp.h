/**
 * @file      MatrixOp.h
 * @brief     Declaración de MatrixOp (A1–A4 + B1–B3).
 * @date      2025-05-30
 * @author    Alexander Luna
 */
#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdexcept>
#include <cstddef>
#include <algorithm>   

template<typename T>
T maxValue(const T* arr, int n);

//  B3: interfaz IMatrix
class IMatrix {
public:
    virtual ~IMatrix() = default;
    virtual double determinant() const = 0;
};

using OpFunc = double (*)(double, double);   ///< A3

//  MatrixOp
class MatrixOp : public IMatrix
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

    // B1
    MatrixOp operator+(const MatrixOp& other) const;
    MatrixOp operator-(const MatrixOp& other) const;

    // B3
    double  determinant() const override;

    int            getRows() const { return rows_; }
    int            getCols() const { return cols_; }
    const double*  data()   const { return data_; }
    int            size()   const { return rows_ * cols_; }

private:
    double* data_;
    int     rows_;
    int     cols_;
};

#endif // MATRIXOP_H

template<typename T>
T maxValue(const T* arr, int n)
{
    if (!arr || n <= 0)
        throw std::invalid_argument("maxValue – arreglo nulo o tamaño inválido");

    T maxv = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxv) maxv = arr[i];

    return maxv;
}
