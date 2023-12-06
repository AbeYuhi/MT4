#pragma once
#include <Novice.h>
#include <math.h>

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

//描画
void ScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label);