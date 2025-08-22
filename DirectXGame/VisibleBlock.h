#pragma once

#include "KamataEngine.h"
#include "Math.h"

using namespace KamataEngine;

class VisibleBlock {
public:
    // 修正: 構造体名を修正し、メンバーをクラスの直接のメンバーに変更
    WorldTransform* worldTransform = nullptr;
    bool isVisible = false;

    // 02_10 スライド14枚目
	AABB GetAABB();

    Vector3 GetWorldPosition();

    // キャラクターの当たり判定サイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;
};
