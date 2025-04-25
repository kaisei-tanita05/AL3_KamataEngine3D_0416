#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include <vector>

using namespace KamataEngine;

//ゲームシーン
class GameScene 
{
public:

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	~GameScene();

private:
	////テクスチャーハンドル
	uint32_t textureHandle_ = 0;

	Sprite* sprite_ = nullptr;

	//////3Dモデル
	Model* model_ = nullptr;

	//ブロックの3Dモデル
	Model* blockModel_ = nullptr;

	WorldTransform worldTransform_;
	//
	////カメラ
	Camera camera_;

	std::vector<WorldTransform*> worldTransformBlocks_;

	//KamataEngine::DebugCamera* debugCamera_ = nullptr;

	// 自キャラ
	Player* player_ = nullptr;
};


