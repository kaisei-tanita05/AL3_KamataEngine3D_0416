#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() 
{
	//ここにインゲームの初期化処理を書く
	textureHandle_ = TextureManager::Load("mario.png");

	////スプライトインスタンスの生成
	//sprite_ = Sprite::Create(textureHandle_, {100, 50});

	model_ = Model::Create();

	//debugCamera_ = new DebugCamera(1280, 720);

	//自キャラの生成
	player_ = new Player();

	//自キャラの初期化
	player_->Initialize(model_,textureHandle_,&camera_);

	worldTransform_.Initialize();

	camera_.Initialize();
}

void GameScene::Update() 
{
	//ここにインゲームの更新処理を書く
	//debugCamera_->Update();

	//自キャラの更新
	player_->UpDate();
}

void GameScene::Draw() 
{

	//ここに3Dモデルインスタンスの描画
	//model_->Draw(worldTransform_,camera_,textureHandle_);

	player_->Draw();
}

GameScene::~GameScene() 
{ 
	/*delete sprite_;
	delete model_;
	delete debugCamera_;*/
	delete player_;
}
