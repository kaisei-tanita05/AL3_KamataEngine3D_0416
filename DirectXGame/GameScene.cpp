#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() 
{
	//ここにインゲームの初期化処理を書く
	textureHandle_ = TextureManager::Load("mario.png");

	//スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});

	model_ = Model::Create();

	debugCamera_ = new DebugCamera(1280, 720);

	//自キャラの生成
	player_ = new Player();

	//自キャラの初期化
	player_->Initialize();
}

void GameScene::Update() 
{
	//ここにインゲームの更新処理を書く
	debugCamera_->Update();

	//自キャラの更新
	player_->UpDate();
}

void GameScene::Draw() 
{
	//スプライト描画前処理
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	model_->Draw

	Sprite::PostDraw();

	player_->Draw();

}

GameScene::~GameScene() 
{ 
	delete sprite_;
	delete model_;
	delete debugCamera_;
	delete player_;
}
