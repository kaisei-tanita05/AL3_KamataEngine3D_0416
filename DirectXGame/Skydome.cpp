#include "Skydome.h"

void Skydome::Initialize(Model*model,Camera*camera) 
{
	assert(model);
	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();

}

void Skydome::Update() 
{
	worldTransform_.TransferMatrix();
}

void Skydome::Draw() { 

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_, *camera_);

	Model::PostDraw();
}
