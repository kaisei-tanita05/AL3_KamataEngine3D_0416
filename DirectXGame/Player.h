#pragma once
#include "KamataEngine.h"
#include "Math.h"
#include "UpData.h"

using namespace KamataEngine;

class Player 
{
public:

	//左右
	enum class LRDirection {
		kRight,
		kLeft,
	};

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model*model_,Camera*camera_,const Vector3 &position);

	/// <summary>
	/// 更新
	/// </summary>
	void UpDate();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	// uint32_t textureHandle_ = 0u;

	Camera* camera_ = nullptr;

	Math* math_ = nullptr;

	UpData* upData = nullptr;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.02f;

	LRDirection lrDirection_ = LRDirection::kRight;

	//接地状態フラグ
	bool onGround_ = true;

	//最大落下速度(下方向)
	static inline const float kLimitFallSpeed = 0.02f;

	//ジャンプ初速(上方向)
	static inline const float kJumpAcceleration = 10.0f;

	// std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
};
