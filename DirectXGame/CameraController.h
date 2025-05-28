#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Player;

class CameraController {
	
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Camera*camera);

	void Updata();

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

private:

	Camera* camera_ = nullptr;

	Player* target_ = nullptr;

	Math* math_ = nullptr;

	Vector3 targetOffset_ = {0, 0, -15.0f};

};
