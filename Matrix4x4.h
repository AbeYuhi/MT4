#pragma once
#include <Vector3.h>
#include <cmath>
#include <cassert>
#include <cmath>

struct Matrix4x4 {
	float m[4][4];
};

Matrix4x4 operator*(const Matrix4x4& num1, const Matrix4x4& num2);

/// <summary>
/// 4x4行列の加算
/// </summary>
/// <param name="matrix1">行列1</param>
/// <param name="matrix2">行列2</param>
/// <returns></returns>
Matrix4x4 Add(Matrix4x4 matrix1, Matrix4x4 matrix2);

/// <summary>
/// 4x4行列の減算
/// </summary>
/// <param name="matrix1">行列1</param>
/// <param name="matrix2">行列2</param>
/// <returns></returns>
Matrix4x4 Subtract(Matrix4x4 matrix1, Matrix4x4 matrix2);

/// <summary>
/// 4x4行列の積
/// </summary>
/// <param name="matrix1">行列1</param>
/// <param name="matrix2">行列2</param>
/// <returns></returns>
Matrix4x4 Multiply(Matrix4x4 matrix1, Matrix4x4 matrix2);

/// <summary>
/// 4x4行列の行列式
/// </summary>
/// <param name="matrix">行列式を求めたい行列</param>
/// <returns></returns>
float Det(Matrix4x4 matrix);

/// <summary>
/// 4x4行列の逆行列
/// </summary>
/// <param name="matrix">逆行列にしたい行列</param>
/// <returns></returns>
Matrix4x4 Inverse(Matrix4x4 matrix);

/// <summary>
/// 4x4行列の転置行列
/// </summary>
/// <param name="matrix">転置させたい行列</param>
/// <returns></returns>
Matrix4x4 Transpose(Matrix4x4 matrix);

/// <summary>
/// 4x4単位行列の作成
/// </summary>
/// <returns></returns>
Matrix4x4 MakeIdentity4x4();

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4 MakeRotateXYZMatrix(const Matrix4x4& matrixX, const Matrix4x4& matrixY, const Matrix4x4& matrixZ);

Matrix4x4 MakeRotateMatrix(const Vector3& rotate);

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float sin, float cos);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);