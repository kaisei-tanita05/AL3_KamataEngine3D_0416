#include "CameraController.h"
#include "Player.h"
#include <algorithm>
#include "Math.h"

using namespace KamataEngine;

void CameraController::Initialize(Camera*camera) {
	
	camera_ = camera;

}

void CameraController::Updata() {
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	//追従対象とオフセットからカメラの座標を計算
	camera_->translation_ = math_->operator+(targetWorldTransform.translation_, targetOffset_);

	//行列を更新
	camera_->UpdateMatrix();
}

void CameraController::Reset() {

	const WorldTransform& targetWorldTransform = target_->GetWorldTransform(); 

	camera_->translation_ = math_->operator+( targetWorldTransform.translation_ , targetOffset_);
}
