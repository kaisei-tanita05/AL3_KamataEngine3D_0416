#pragma once
#include <KamataEngine.h>
#include "Player.h"
#include "Skydome.h"
#include "MapChipField.h"
#include "CameraController.h"
#include "Enemy.h"

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

	void GenerateBlocks();

private:
	////テクスチャーハンドル
	uint32_t textureHandle_ = 0;

	Sprite* sprite_ = nullptr;

	//////3Dモデル
	Model* model_ = nullptr;

	//ブロックの3Dモデル
	Model* blockModel_ = nullptr;

	WorldTransform worldTransform_;
	

	////カメラ
	Camera camera_;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	DebugCamera* debugCamera_ = nullptr;

	// 自キャラ
	Player* player_ = nullptr;

	// 02_09 10枚目 エネミークラス
	Enemy* enemy_ = nullptr;


	//Math* math_ = nullptr;

	//デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	Skydome* skydome_ = nullptr;

	Model*modelSkydome_ = nullptr;

	Model* modelPlayer_ = nullptr;

	Model* enemy_model_ = nullptr;

	MapChipField* mapChipField_;

	CameraController* CController_ = nullptr;

	// 02_09 10枚目 エネミーモデル
};


