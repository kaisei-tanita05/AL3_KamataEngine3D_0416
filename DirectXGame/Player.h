#pragma once
#include "KamataEngine.h"
#include "Math.h"

using namespace KamataEngine;

class Player 
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model*model_,Camera*camera_);

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

	// std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
};
