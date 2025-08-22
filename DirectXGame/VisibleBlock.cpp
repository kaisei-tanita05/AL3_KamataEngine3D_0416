#include "VisibleBlock.h"


AABB VisibleBlock::GetAABB() { 
	Vector3 worldPos = GetWorldPosition();

	AABB aabb;

	aabb.min = {worldPos.x - kWidth / 2.0f, worldPos.y - kHeight / 2.0f, worldPos.z - kWidth / 2.0f};
	aabb.max = {worldPos.x + kWidth / 2.0f, worldPos.y + kHeight / 2.0f, worldPos.z + kWidth / 2.0f};

	return aabb;
}

Vector3 VisibleBlock::GetWorldPosition() {

	Vector3 worldPos;

	// ワールド行列の平行移動成分を取得（ワールド座標）
	worldPos.x = worldTransform->matWorld_.m[3][0];
	worldPos.y = worldTransform->matWorld_.m[3][1];
	worldPos.z = worldTransform->matWorld_.m[3][2];

	return worldPos;
}