/**
 * @file      MatrixOp.cpp
 * @brief     Implementación de MatrixOp (Ej. A1 y A2).
 * @date      2025-05-30
 */
#include "MatrixOp.h"

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

//A2
void MatrixOp::add(const MatrixOp* other, MatrixOp* result) const
{
    if (!other || !result)
        throw std::invalid_argument("MatrixOp::add – null pointer received");

    if (rows_ != other->rows_ || cols_ != other->cols_ ||
        rows_ != result->rows_ || cols_ != result->cols_)
        throw std::invalid_argument("MatrixOp::add – dimension mismatch");

    const int total = rows_ * cols_;
    for (int k = 0; k < total; ++k)
        result->data_[k] = data_[k] + other->data_[k];
}
