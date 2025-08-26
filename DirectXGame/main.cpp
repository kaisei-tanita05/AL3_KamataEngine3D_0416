#include "GameScene.h"
#include "Player.h"
#include "KamataEngine.h"
#include "TitleScene.h"
#include "GameOver.h"
#include "GameClear.h"
#include <Windows.h>

using namespace KamataEngine;

TitleScene* titleScene = nullptr;
GameScene* gameScene = nullptr;
GameOver* gameOverScene = nullptr;
GameClear* gameClearScene = nullptr;

// 02_12 25枚目(Scene sceneまで)
enum class Scene {
	kUnknown = 0,
	kTitle,
	kGame,
	kGameOver,
	kGameClear,
};

// 現在シーン（型）
Scene scene = Scene::kUnknown;

// 02_12 29枚目
void ChangeScene() {

	switch (scene) {
	case Scene::kTitle:
		if (titleScene->IsFinished()) {
			// シーン変更
			scene = Scene::kGame;
			delete titleScene;
			titleScene = nullptr;
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;

	case Scene::kGame:
		// 02_12 30枚目
		if (gameScene->IsFinished()) {
			Player* player_ = gameScene->GetPlayer();
			// シーン変更
			if (player_->IsDead()) {
				scene = Scene::kGameOver;
				delete gameScene;
				gameScene = nullptr;
				gameOverScene = new GameOver;
				gameOverScene->Initialize();
			}else if (player_->IsGoal()) {
				scene = Scene::kGameClear;
				delete gameScene;
				gameScene = nullptr;
				gameClearScene = new GameClear;
				gameClearScene->Initialize();
			}
		}
		break;

	case Scene::kGameOver:
		if (gameOverScene->IsFinished()) {
			scene = Scene::kTitle;
			delete gameOverScene;
			gameOverScene = nullptr;
			titleScene = new TitleScene;
			titleScene->Initialize();
		}

		break;

	case Scene::kGameClear:
		if (gameClearScene->IsFinished()) {
			scene = Scene::kTitle;
			delete gameClearScene;
			gameClearScene = nullptr;
			titleScene = new TitleScene;
			titleScene->Initialize();
		}
		break;
	}
}

// 02_12 31枚目
void UpDataScene() {

	switch (scene) {
	case Scene::kTitle:
		titleScene->Update();
		break;
	case Scene::kGame:
		gameScene->Update();
		break;
	case Scene::kGameOver:
		gameOverScene->Update();
		break;
	case Scene::kGameClear:
		gameClearScene->Update();
		break;
	}
}

// 02_12 32枚目
void DrawScene() {
	switch (scene) {
	case Scene::kTitle:
		titleScene->Draw();
		break;
	case Scene::kGame:
		gameScene->Draw();
		break;
	case Scene::kGameOver:
		gameOverScene->Draw();
		break;
	case Scene::kGameClear:
		gameClearScene->Draw();
		break;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {


	KamataEngine::Initialize();

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	scene = Scene::kTitle;
	titleScene = new TitleScene;
	titleScene->Initialize();

	//gameScene->Initialize();

	// メインループ
	while (true) {

		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// シーン切り替え
		ChangeScene();

		// 現在シーン更新
		UpDataScene();

		// 描画更新
		dxCommon->PreDraw();

		// ゲームシーンの描画
		DrawScene();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	// 02_12 35枚目 各種解放
	delete titleScene;
	delete gameScene;
	delete gameOverScene;
	delete gameClearScene;

	// nullptrの代入
	gameScene = nullptr;

	KamataEngine::Finalize();

	return 0;
}
