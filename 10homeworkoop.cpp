// 10homeworkoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class Matrix {
private:
    int rows;//����������, �������������� ���������� ����� � �������. 
    int cols;//����������, �������������� ���������� �������� � �������
    T** data;// ��������� �� ���������, ������� ����� ��������� �� ���� ������, ��� ����� ��������� �������� �������.

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {// ����������� ������� ������ ������� � �������� ����������� ����� � ��������
        data = new T * [rows]; // ��������� ������ ��� �������
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {// ���������� ,����������� ����������� ���������� ������ ��� ������ �������
        
        for (int i = 0; i < rows; ++i) {// ������� ������ �������
            delete[] data[i];
        }
        delete[] data;
    }

    void fillFromKeyboard() {// �����,������� ��������� ������ �������� ������� � ����������
        std::cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void fillRandom() {// �����,������� ��������� ������� ���������� �������
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = static_cast<T>(rand());// �������� ���������� � ���� �
            }
        }
    }

    void print() const {// �����,������� ������� ���������� ������� 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& other) const {// ������� �������� ������
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions mismatch"); //���� ������� ������ �� ���������, ������������� ����������
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {// �������� ��������� ������
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions mismatch");//���� ������� ������ �� ���������, ������������� ���������� 
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {// �������� ��������� ������
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions mismatch");//���� ���������� �������� ������ ������� �� ����� ���������� ����� ������ �������, ������������� ����������
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& other) const {//�������� ������� ������
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions mismatch");//���� ������� ������ �� ��������� ��� ������ ������� �������� ������� ��������, ������������� ����������
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (other.data[i][j] == 0) {
                    throw std::runtime_error("Division by zero");
                }
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    T findMax() const {// ����� ������� ������������ ������� � ������� � ���������� ��� ��������
        T maxElement = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > maxElement) {
                    maxElement = data[i][j];
                }
            }
        }
        return maxElement;
    }

    T findMin() const {// ����� ������� ����������� ������� � ������� � ���������� ��� ��������
        T minElement = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < minElement) {
                    minElement = data[i][j];
                }
            }
        }
        return minElement;
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";//���������� ����������� ������ ���������� ����� �������
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";//���������� ����������� ������ ���������� �������� �������
    std::cin >> cols;
        Matrix<int> matrix1(rows, cols);
    matrix1.fillFromKeyboard();// ����� ������ ��� ���������� ������� ����������,������� ���� ������������
    std::cout << "Matrix 1:\n";
    matrix1.print();

    Matrix<int> matrix2(rows, cols);// ������� ������ � ������ �� ���������
    matrix2.fillRandom();
    std::cout << "Matrix 2:\n";
    matrix2.print();

    try {
        Matrix<int> matrixSum = matrix1 + matrix2;// �������� ������
        std::cout << "Matrix Sum:\n";
        matrixSum.print();

        Matrix<int> matrixDiff = matrix1 - matrix2;// ��������� ������
        std::cout << "Matrix Difference:\n";
        matrixDiff.print();

        Matrix<int> matrixProduct = matrix1 * matrix2;// ��������� ������
        std::cout << "Matrix Product:\n";
        matrixProduct.print();

        Matrix<int> matrixQuotient = matrix1 / matrix2;// ������� ������
        std::cout << "Matrix Quotient:\n";
        matrixQuotient.print();

        int maxElement = matrix1.findMax();// ���������� ������������� ��������
        std::cout << "Max Element: " << maxElement << std::endl;

        int minElement = matrix1.findMin();
        std::cout << "Min Element: " << minElement << std::endl;// ���������� ������������ ��������
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;//��������� ����������
    }

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
