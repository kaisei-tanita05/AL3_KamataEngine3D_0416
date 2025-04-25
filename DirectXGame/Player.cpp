#include "Player.h"
#include <cassert>


void Player::Initialize(KamataEngine::Model* model, uint32_t textureHandle,Camera*camera) 
{ 
	assert(model); 

	textureHandle_ = textureHandle;

	model_ = model;

	worldTransform_.Initialize();

	camera_ = camera;
}

void Player::UpDate() 
{
	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() {}
