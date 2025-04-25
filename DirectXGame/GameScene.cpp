#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() 
{
	//ここにインゲームの初期化処理を書く
	textureHandle_ = TextureManager::Load("mario.png");

	////スプライトインスタンスの生成
	//sprite_ = Sprite::Create(textureHandle_, {100, 50});

	model_ = Model::Create();

	blockModel_ = Model::Create();

	//debugCamera_ = new DebugCamera(1280, 720);

	//自キャラの生成
	player_ = new Player();

	//自キャラの初期化
	player_->Initialize(model_,textureHandle_,&camera_);

	worldTransform_.Initialize();

	camera_.Initialize();

	//要素数
	const uint32_t kNumBlockHorizontal = 20;

	//ブロック1個分の横幅
	const float kBlockWidth = 2.0f;

	//要素数を変更する
	worldTransformBlocks_.resize(kNumBlockHorizontal);

	//キューブの生成
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {
		worldTransformBlocks_[i] = new WorldTransform();

		worldTransformBlocks_[i]->Initialize();

		worldTransformBlocks_[i]->translation_.x = kBlockWidth * i;

		worldTransformBlocks_[i]->translation_.y = 0.0f;
	}
}

void GameScene::Update() 
{
	//ここにインゲームの更新処理を書く
	//debugCamera_->Update();

	//自キャラの更新
	player_->UpDate();

	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) 
	{
		//アフィン変換行列の生成


		worldTransformBlock->matWorld_=
	}
}

void GameScene::Draw() 
{

	//ここに3Dモデルインスタンスの描画
	//model_->Draw(worldTransform_,camera_,textureHandle_);

	player_->Draw();
}

GameScene::~GameScene() 
{ 
	//delete sprite_;
	//delete debugCamera_;
	delete player_;

	delete model_;

	delete blockModel_;

	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		delete worldTransformBlock;
	}

	worldTransformBlocks_.clear();
}
