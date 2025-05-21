#include "Player.h"
#include <cassert>

using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model* model,Camera*camera) 
{ 
	assert(model); 

	model_ = model;
	camera_ = camera;

	worldTransform_.Initialize();

	worldTransform_.translation_ = {10.3f, 10.0f, 0.0f};

	worldTransform_.rotation_ = {0.0f, 1.5f, 0.0f};

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
	// }

	// アフィン変換行列の生成
	worldTransform_.matWorld_ = math_->MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Player::Draw() 
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_,*camera_);

	Model::PostDraw();
}
