#pragma once
#include "KamataEngine.h"
#include "Player.h"

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

	KamataEngine::Sprite* sprite_ = nullptr;

	//////3Dモデル
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;
	//
	////カメラ
	KamataEngine::Camera camera_;


	//KamataEngine::DebugCamera* debugCamera_ = nullptr;

	// 自キャラ
	Player* player_ = nullptr;
};


