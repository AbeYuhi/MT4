#pragma once
#include <Novice.h>
#include <math.h>
#include "Vector3.h"
#include "Matrix4x4.h"

struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};

//積
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
//単位
Quaternion IdentityQuaternion();
//共役
Quaternion Conjugate(const Quaternion& quaternion);
//ノルム
float Norm(const Quaternion& quaternion);
//正規化
Quaternion Normalize(const Quaternion& quaternion);
//逆
Quaternion Inverse(const Quaternion& quaternion);

//任意回転軸を表すQuaternion
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);

//ベクトルをQuaternionで回転させた結果のベクトル
Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion);

//回転行列
Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

//描画
void ScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label);