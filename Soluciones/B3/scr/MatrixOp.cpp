/**
 * @file      MatrixOp.cpp
 * @brief     Implementación de MatrixOp (A1–A4 + B1–B3).
 * @date      2025-05-30
 */
#include "MatrixOp.h"
#include <iostream>

// ctor / dtor
MatrixOp::MatrixOp(int rows, int cols)
    : data_(nullptr), rows_(rows), cols_(cols)
{
    if (rows_ <= 0 || cols_ <= 0)
        throw std::invalid_argument("rows and cols must be positive");

    data_ = new double[static_cast<std::size_t>(rows_) * cols_]{};
}

MatrixOp::~MatrixOp()
{
    delete[] data_;
    data_ = nullptr;
}

// getters / setters 
void MatrixOp::set(int i, int j, double v)
{
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("MatrixOp::set – index out of range");

    data_[i * cols_ + j] = v;
}

double MatrixOp::get(int i, int j) const
{
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("MatrixOp::get – index out of range");

    return data_[i * cols_ + j];
}

// (A2)
void MatrixOp::add(const MatrixOp* other, MatrixOp* result) const
{
    if (!other || !result)
        throw std::invalid_argument("MatrixOp::add – null pointer");

    if (rows_ != other->rows_ || cols_ != other->cols_ ||
        rows_ != result->rows_ || cols_ != result->cols_)
        throw std::invalid_argument("MatrixOp::add – dimension mismatch");

    const int total = rows_ * cols_;
    for (int k = 0; k < total; ++k)
        result->data_[k] = data_[k] + other->data_[k];
}

//(A3)
void MatrixOp::apply(const MatrixOp* A,
                     const MatrixOp* B,
                     MatrixOp*       out,
                     OpFunc          op) const
{
    if (!A || !B || !out || !op)
        throw std::invalid_argument("MatrixOp::apply – null pointer");

    if (A->rows_ != B->rows_ || A->cols_ != B->cols_ ||
        A->rows_ != out->rows_ || A->cols_ != out->cols_)
        throw std::invalid_argument("MatrixOp::apply – dimension mismatch");

    const int total = A->rows_ * A->cols_;
    for (int k = 0; k < total; ++k)
        out->data_[k] = op(A->data_[k], B->data_[k]);
}

// (A4)
void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int, int) const) const
{
    if (!fn) throw std::invalid_argument("MatrixOp::forEachDiagonal – null fn");

    const int n = std::min(rows_, cols_);
    for (int i = 0; i < n; ++i)
        (this->*fn)(i, i);
}

void MatrixOp::printAt(int i, int j) const
{
    std::cout << get(i, j) << ' ';
}

// B1
MatrixOp MatrixOp::operator+(const MatrixOp& other) const
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Dimensiones incompatibles");

    MatrixOp result(rows_, cols_);
    const int total = rows_ * cols_;
    for (int k = 0; k < total; ++k)
        result.data_[k] = data_[k] + other.data_[k];

    return result;
}

MatrixOp MatrixOp::operator-(const MatrixOp& other) const
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Dimensiones incompatibles");

    MatrixOp result(rows_, cols_);
    const int total = rows_ * cols_;
    for (int k = 0; k < total; ++k)
        result.data_[k] = data_[k] - other.data_[k];

    return result;
}

// B3 
double MatrixOp::determinant() const
{
    if (rows_ != cols_)
        throw std::logic_error("determinant – matriz no cuadrada");

    if (rows_ == 2) {
        return get(0,0)*get(1,1) - get(0,1)*get(1,0);
    }

    if (rows_ == 3) {
        double a = get(0,0), b = get(0,1), c = get(0,2);
        double d = get(1,0), e = get(1,1), f = get(1,2);
        double g = get(2,0), h = get(2,1), i = get(2,2);

        return a*e*i + b*f*g + c*d*h
             - c*e*g - b*d*i - a*f*h;
    }

    throw std::logic_error("Implementar para 2×2 o 3×3");
}
