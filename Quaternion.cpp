#include "Quaternion.h"

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs) {
	Quaternion ans;

	ans.w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
	ans.x = lhs.y * rhs.z - lhs.z * rhs.y + rhs.w * lhs.x + lhs.w * rhs.x;
	ans.y = lhs.z * rhs.x - lhs.x * rhs.z + rhs.w * lhs.y + lhs.w * rhs.y;
	ans.z = lhs.x * rhs.y - lhs.y * rhs.x + rhs.w * lhs.z + lhs.w * rhs.z;
	return ans;
}

Quaternion IdentityQuaternion(){
	return { 0.0f, 0.0f, 0.0f, 1.0f };
}

Quaternion Conjugate(const Quaternion& quaternion){
	return { -quaternion.x, -quaternion.y, -quaternion.z, quaternion.w };
}

float Norm(const Quaternion& quaternion){
	return sqrtf(powf(quaternion.w, 2) + powf(quaternion.x, 2) + powf(quaternion.y, 2) + powf(quaternion.z, 2));
}

Quaternion Normalize(const Quaternion& quaternion){
	float norm = Norm(quaternion);
	Quaternion ans;
	ans.w = quaternion.w / norm;
	ans.x = quaternion.x / norm;
	ans.y = quaternion.y / norm;
	ans.z = quaternion.z / norm;
	return ans;
}

Quaternion Inverse(const Quaternion& quaternion){
	Quaternion conjugate = Conjugate(quaternion);
	float norm = Norm(quaternion);

	Quaternion ans;
	ans.w = conjugate.w / powf(norm, 2);
	ans.x = conjugate.x / powf(norm, 2);
	ans.y = conjugate.y / powf(norm, 2);
	ans.z = conjugate.z / powf(norm, 2);
	return ans;
}

void ScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label) {
	Novice::ScreenPrintf(x, y, "%6.02f, %6.02f, %6.02f, %6.02f : %s", quaternion.x, quaternion.y, quaternion.z, quaternion.w, label);
}