```mermaid
classDiagram
    %% Tipos auxiliares usados por MatrixOp
    class OpFunc {
        <<typedef>>
        + double (*)(double, double)
    }

    class DiagonalMemberPtr {
        <<typedef>>
        + void (MatrixOp::*)(int,int) const
    }

    %% Interfaz abstracta
    class IMatrix {
        <<interface>>
        + ~IMatrix()
        + double* determinant()
    }

    %% Implementación concreta
    class MatrixOp {
        - double* data_
        - int rows_
        - int cols_

        + MatrixOp(int rows, int cols)
        + ~MatrixOp()
        + void set(int i, int j, double)
        + double get(int i, int j)
        + void add(const MatrixOp* other, MatrixOp* result)
        + void apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op)
        + void forEachDiagonal(DiagonalMemberPtr fn)
        + void printAt(int i, int j)
        + MatrixOp operator+(const MatrixOp& other)
        + MatrixOp operator-(const MatrixOp& other)
        + double* data() const
        + int size()
        + int getRows()
        + int getCols()
        + double determinant()
    }

    %% Relaciones
    IMatrix <|.. MatrixOp           : implements
    MatrixOp ..> OpFunc            : uses\n(pointer to function)
    MatrixOp ..> DiagonalMemberPtr : uses\n(pointer to member)
    ```
