#pragma once
#include "KamataEngine.h"
#include "Math.h"
#include "UpData.h"
#include "MapChipField.h"

/// <summary>
/// 敵
/// </summary>
class Enemy 
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model_"></param>
	/// <param name="camera_"></param>
	/// <param name="position"></param>
	void Initialize(Model* model, Camera* camera, const Vector3& position);

	/// <summary>
	/// 更新
	/// </summary>
	void UpDate();


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


	
private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	UpData* upData = nullptr;

	// テクスチャハンドル
	//  uint32_t textureHandle_ = 0u;

	Camera* camera_ = nullptr;



	// 02_09 15枚目
	static inline const float kWalkSpeed = 0.02f;
	// 02_09 15枚目
	Vector3 velocity_ = {};

	// 02_09 19枚目
	//最初の角度
	static inline const float kWalkMotionAngleStart = -10.0f;

	
	// 02_09 19枚目
	//最後の角度
	static inline const float kWalkMotionAngleEnd = 40.0f;

	// 02_09 19枚目
	static inline const float kWalkMotionTime = 1.0f;
	// 02_09 20枚目
	float walkTimer = 0.0f;

};
