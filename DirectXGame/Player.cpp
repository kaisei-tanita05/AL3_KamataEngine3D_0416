#include "Player.h"
#include <cassert>
#include <numbers>
#include "UpData.h"

using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model* model,Camera*camera,const Vector3 &position) 
{ 
	assert(model); 

	model_ = model;
	camera_ = camera;

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	//worldTransform_.translation_ = {5.0f, 5.0f, 0.0f};

	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;

}

void Player::UpDate() 
{
	// for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
	// 	for (WorldTransform*& worldTransformBlock : worldTransformBlockLine) {
	// 		if (!worldTransformBlock)
	// 			continue;
	// 		// アフィン変換行列の生成
	// 		worldTransformBlock->matWorld_ = math_->MakeAffineMatrix(worldTransformBlock->scale_, worldTransformBlock->rotation_, worldTransformBlock->translation_);
	// 
	// 		// 定数バッファに転送する
	// 		worldTransformBlock->TransferMatrix();
	// 	}
	// 

	//移動入力
	//接地状態
	//左右移動操作
	if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {
	
		//左右加速
		Vector3 acceleration = {};
		if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		
			acceleration.x += kAcceleration;

			if (lrDirection_ != LRDirection::kRight) {
				lrDirection_ = LRDirection::kRight;
			}


		}else if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		
			acceleration.x -= kAcceleration;

			if (lrDirection_ != LRDirection::kLeft) {
				lrDirection_ = LRDirection::kLeft;
			}

		}

		//加速/減速
		velocity_ = math_->Add(acceleration,velocity_);
	}

	//移動
	worldTransform_.translation_ = math_->Add(velocity_, worldTransform_.translation_);

	//行列更新
	upData->WorldTransformUpData(worldTransform_);

	//旋回制御
	//左右の自キャラ角度テーブル
	float destinationRotationYTable[] = {
		std::numbers::pi_v<float> / 2.0f, 
		std::numbers::pi_v<float> * 3.0f / 2.0f
	};

	//状態に応じた角度を取得する
	float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];

	//自キャラの角度を設定する
	worldTransform_.rotation_.y = destinationRotationY;

}

void Player::Draw() 
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_,*camera_);

	Model::PostDraw();
}
