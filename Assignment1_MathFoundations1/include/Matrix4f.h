// High level design note
// Our matrix should match the behavior of the glm library.
#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <cmath>

// We need to Vector4f header in order to multiply a matrix
// by a vector.
#include "Vector4f.h"

// Matrix 4f represents 4x4 matrices in Math
struct Matrix4f{
private:
    float n[4][4];  // Store each value of the matrix

public:
    Matrix4f() = default;

    // TODO: Row or column major order you decide!
    // Matrix constructor with 9 scalar values.
    Matrix4f( float n00, float n01, float n02, float n03,
              float n10, float n11, float n12, float n13,
              float n20, float n21, float n22, float n23,
              float n30, float n31, float n32, float n33){

        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
        n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
    }

    // Matrix constructor from four vectors.
    // Note: 'd' will almost always be 0,0,0,1
    Matrix4f(const Vector4f& a, const Vector4f& b, const Vector4f& c, const Vector4f& d){
      n[0][0] = a.x; n[0][1] = b.x; n[0][2] = c.x; n[0][3] = d.x;
      n[1][0] = a.y; n[1][1] = b.y; n[1][2] = c.y; n[1][3] = d.y;
      n[2][0] = a.z; n[2][1] = b.z; n[2][2] = c.z; n[2][3] = d.z;
      n[3][0] = a.w; n[3][1] = b.w; n[3][2] = c.w; n[3][3] = d.w;
    }

    // Makes the matrix an identity matrix
    void identity(){
        // TODO:
        n[0][0] = 1; n[0][1] = 0; n[0][2] = 0; n[0][3] = 0;
        n[1][0] = 0; n[1][1] = 1; n[1][2] = 0; n[1][3] = 0;
        n[2][0] = 0; n[2][1] = 0; n[2][2] = 1; n[2][3] = 0;
        n[3][0] = 0; n[3][1] = 0; n[3][2] = 0; n[3][3] = 1;
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    float& operator ()(int i, int j){
      return (n[j][i]);
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    const float& operator ()(int i, int j) const{
      return (n[j][i]);
    }

    // Return a single  vector from the matrix (row or columnn major? hmm).
    Vector4f& operator [](int j){
      return (*reinterpret_cast<Vector4f *>(n[j]));
    }

    // Return a single  vector from the matrix (row or columnn major? hmm).
    const Vector4f& operator [](int j) const{
      return (*reinterpret_cast<const Vector4f *>(n[j]));
    }

    // Make a matrix rotate about various axis
    Matrix4f MakeRotationX(float t){
        // TODO:
        //float xRotation[4][4];
        // xRotation matrix:
        // xRotation[0][0] = 1; xRotation[0][1] = 0; xRotation[0][2] = 0; xRotation[0][3] = 0;
        // xRotation[1][0] = 0; xRotation[1][1] = cos(t); xRotation[1][2] = -sin(t); xRotation[1][3] = 0;
        // xRotation[2][0] = 0; xRotation[2][1] = sin(t); xRotation[2][2] = cos(t); xRotation[2][3] = 0;
        // xRotation[3][0] = 0; xRotation[3][1] = 0; xRotation[3][2] = 0; xRotation[3][3] = 1;
        // Matrix4f xRotation = Matrix4f(1, 0, 0, 0, 0, cos(t), -sin(t), 0, 0, sin(t), cos(t), 0, 0, 0, 0, 1);

        Matrix4f xRotation = Matrix4f();
        xRotation.identity();
        xRotation[1][1] = cos(t);
        xRotation[1][2] = -sin(t);
        xRotation[2][1] = sin(t);
        xRotation[2][2] = cos(t);

        Vector4f Col0 = Vector4f(xRotation[0][0], xRotation[0][1], xRotation[0][2], xRotation[0][3]);
        Vector4f Col1 = Vector4f(xRotation[1][0], xRotation[1][1], xRotation[1][2], xRotation[1][3]);
        Vector4f Col2 = Vector4f(xRotation[2][0], xRotation[2][1], xRotation[2][2], xRotation[2][3]);
        Vector4f Col3 = Vector4f(xRotation[3][0], xRotation[3][1], xRotation[3][2], xRotation[3][3]);

        this->n[0][0] = Dot(Col1, xRotation.operator[](0));
        this->n[0][1] = Dot(Col1, xRotation.operator[](0));
        this->n[0][2] = Dot(Col1, xRotation.operator[](0));
        this->n[0][3] = Dot(Col1, xRotation.operator[](0));


        this->n[0][0] = n[0][0] * xRotation[0][0] + n[0][0] + 
          xRotation[0][1] * n[1][0] +
          xRotation[0][2] * n[2][0] +
          xRotation[0][3] * n[3][0];
        
        Vector4f first = xRotation.operator[](0);
        Vector4f second = xRotation.operator(0)[];


        return(Matrix4f()); // You will need to modify this.
                            // When you test, test against glm_gtx_transform
    }
    Matrix4f MakeRotationY(float t){
        // TODO:
        Matrix4f yRotation = Matrix4f();
        yRotation.identity();
        yRotation[0][0] = cos(t);
        yRotation[0][2] = -sin(t);
        yRotation[2][0] = sin(t);
        yRotation[2][2] = cos(t);



        return(Matrix4f()); // You will need to modify this.
                            // When you test, test against glm_gtx_transform
    }
    Matrix4f MakeRotationZ(float t){
        // TODO:
        Matrix4f zRotation = Matrix4f();
        zRotation.identity();
        zRotation[0][0] = cos(t);
        zRotation[0][1] = -sin(t);
        zRotation[1][0] = sin(t);
        zRotation[1][1] = cos(t);

        return(Matrix4f()); // You will need to modify this.
                            // When you test, test against glm_gtx_transform
    }
    Matrix4f MakeScale(float sx,float sy, float sz){
        // TODO:
        return(Matrix4f()); // You will need to modify this.
                            // When you test, test against glm_gtx_transform
    }


};

// Matrix Multiplication
Matrix4f operator *(const Matrix4f& A, const Matrix4f& B){
  // TODO:
  Matrix4f mat4;

  return mat4;
}

// Matrix multiply by a vector

Vector4f operator *(const Matrix4f& M, const Vector4f& v){
  // TODO:
  Vector4f vec;

  return vec;
}


#endif
