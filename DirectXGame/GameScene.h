#pragma once
#include "KamataEngine.h"

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

//スプライト
	KamataEngine::Sprite* sprite_ = nullptr;

	//3Dモデル
	KamataEngine::Model* model_ = nullptr;

	//ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	//カメラ
	KamataEngine::Camera camera_;

	//テクスチャーハンドル
	uint32_t textureHandle_ = 0;

	//サウンドデータハンドル
	uint32_t soundDateHandle_ = 0;

	//音声再生ハンドル
	uint32_t voiceHandle_ = 0;

	float inputFloat3[3] = {0, 0, 0};

	//デバッグカメラ
	KamataEngine::DebugCamera* deBugCamera_ = nullptr;
};
