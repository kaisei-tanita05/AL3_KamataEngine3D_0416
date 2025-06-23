#include "Enemy.h"
#include "UpData.h"
#include <numbers>
#include <algorithm>
#include "Math.h"
#include "MapChipField.h"
#include <cassert>

using namespace KamataEngine;

void Enemy::Initialize(Model* model, Camera* camera, const Vector3& position) {

	assert(model);

	// 02_09 7枚目
	model_ = model;
	// 02_09 7枚目
	camera_ = camera;
	// 02_09 7枚目
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	// 02_09 7枚目 角度調整
	worldTransform_.rotation_.y = std::numbers::pi_v<float> * 3.0f / 2.0f;

	// 02_09 16枚目
	velocity_ = {-kWalkSpeed, 0, 0};
	// 02_09 20枚目
	walkTimer = 0.0f;
}

	// 02_09 スライド5枚目
	void Enemy::UpDate() {

		// 02_09 16枚目 移動
		worldTransform_.translation_ += velocity_;

		// 02_09 20枚目
		walkTimer += 1.0f / 60.0f;

		// 02_09 23枚目 回転アニメーション
		//worldTransform_.rotation_.x = std::sin(std::numbers::pi_v<float> * 2.0f * walkTimer / kWalkMotionTime);

		float param = std::sin(std::numbers::pi_v<float> * 2.0f * walkTimer / kWalkMotionTime);

		float degree = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 2.0f;

		worldTransform_.rotation_.x = degree * (std::numbers::pi_v<float> / 180.0f);

		// 02_09 スライド8枚目 ワールド行列更新
	    upData->WorldTransformUpData(worldTransform_);
	}

	// 02_09 スライド5枚目
	void Enemy::Draw() {
		// 02_09 スライド9枚目  モデル描画
		model_->Draw(worldTransform_, *camera_);

	}
