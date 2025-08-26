#pragma once
#include "Fade.h"
#include "KamataEngine.h"
#include "UpData.h"

class Operate 
{
public:

	enum class Phase {
		kFadeIn,  // フェードイン
		kMain,    // メイン部
		kFadeOut, // フェードアウト
	};

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() const { return finished_; }

	

};
