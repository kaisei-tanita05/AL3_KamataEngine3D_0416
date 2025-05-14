#pragma once
#include <KamataEngine.h>
#include "Math.h"
#include <math.h>
#include <time.h>
#define _USE_MATH_DEFINE
#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace KamataEngine;

void WorldTransformUpDate(KamataEngine::WorldTransform& worldTransform);

Math* math_ = nullptr;
