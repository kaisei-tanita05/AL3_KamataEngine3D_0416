#pragma once
#include <KamataEngine.h>
#include <cstdint>

using namespace KamataEngine;

/// <summary>
/// ヒット演出用エフェクト
/// </summary>
class HitEffect {

public:
	enum class State {
		kSpread, // 拡大中
		kFade,   // フェードアウト中
		kDead    // 死亡
	};

	// 02_16 10枚目(SetModel,SetCamera)
	static void SetModel(Model* model) { model_ = model; }

	static void SetCamera(Camera* camera) { camera_ = camera; }

	void Initialize(const Vector3& position);

	void Update();

	void Draw();

	static HitEffect* Create(const KamataEngine::Vector3& position);

private:
	// モデル(借りてくる用)
	static Model* model_;

	// カメラ(借りてくる用)
	static Camera* camera_;
};
