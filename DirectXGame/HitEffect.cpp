#include <cassert>
#include <random>
#include <numbers>
#include "HitEffect.h"
#include "Math.h"

using namespace KamataEngine;

//静的メンバ変数の実体
Model* HitEffect::model_ = nullptr;

Camera* HitEffect::camera_ = nullptr;

//newの失敗を検出
HitEffect* HitEffect::Create(const KamataEngine::Vector3& position) {

	HitEffect* instance = new HitEffect();
	assert(instance);

	instance->Initialize(position);

	return instance;
}

//インスタンス生成
HitEffect* instance = new HitEffect();