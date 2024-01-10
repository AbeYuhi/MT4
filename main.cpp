#include <Novice.h>
#include "Vector3.h"
#include "Vector3_Math.hpp"
#include "Matrix4x4.h"
#include "Quaternion.h"

const char kWindowTitle[] = "K022G0032";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Quaternion rotation0 = MakeRotateAxisAngleQuaternion(Vector3{0.71f, 0.71f, 0.0f}, 0.3f);
	Quaternion rotation1 = MakeRotateAxisAngleQuaternion(Vector3{0.71f, 0.0f, 0.71f}, 3.141592f);

	rotation0 = Normalize(rotation0);
	rotation1 = Normalize(rotation1);

	Quaternion inpterpolate0 = Slerp(rotation0, rotation1, 0.0f);
	Quaternion inpterpolate1 = Slerp(rotation0, rotation1, 0.3f);
	Quaternion inpterpolate2 = Slerp(rotation0, rotation1, 0.5f);
	Quaternion inpterpolate3 = Slerp(rotation0, rotation1, 0.7f);
	Quaternion inpterpolate4 = Slerp(rotation0, rotation1, 1.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		ScreenPrintf(0, 0, inpterpolate0, "t = 0.0f");
		ScreenPrintf(0, 20, inpterpolate1, "t = 0.3f");
		ScreenPrintf(0, 40, inpterpolate2, "t = 0.5f");
		ScreenPrintf(0, 60, inpterpolate3, "t = 0.7f");
		ScreenPrintf(0, 80, inpterpolate4, "t = 1.0f");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
