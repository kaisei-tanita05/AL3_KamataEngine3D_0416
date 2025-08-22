#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;

class VisibleBlock {
public:
	struct visibleBlock {
		WorldTransform* worldTransform = nullptr;
		bool isVisible = false;
	};
};
