#include "worldMatrix.h"

void WorldTransformUpDate(KamataEngine::WorldTransform& worldTransform) {
	worldTransform.matWorld_ = math_->MakeAffineMatrix(worldTransform.scale_, worldTransform.rotation_, worldTransform.translation_);

	worldTransform.TransferMatrix();
}
