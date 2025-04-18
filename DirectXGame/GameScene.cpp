#include "GameScene.h"
#include "imgui.h"

using namespace KamataEngine;


void GameScene::Initialize() 
{
	//ここにインゲームの初期化処理を書く
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");

	sprite_ = Sprite::Create(textureHandle_, {100, 50});

	// 3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//カメラの初期化
	camera_.Initialize();

	//サウンドデータの読み込み
	soundDateHandle_ = Audio::GetInstance()->LoadWave("fanfare.wav");

	//音声再生
	Audio::GetInstance()->PlayWave(soundDateHandle_);

	//音声再生
	voiceHandle_ = Audio::GetInstance()->PlayWave(soundDateHandle_, true);

	//ライン描画が参照するカメラを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetCamera(&camera_);

	//デバッグカメラの生成
	deBugCamera_ = new DebugCamera(1280, 720);

	//軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetCamera(&deBugCamera_->GetCamera());
}

void GameScene::Update() 
{
	//ここにインゲームの更新処理を書く

	//スプライトの今の座標を取得
	Vector2 position = sprite_->GetPosition();
	//座標を{2,1}移動
	position.x += 2.0f;
	position.y += 1.0f;

	//移動した座標をスプライトに反映
	sprite_->SetPosition(position);

	//スペースキーを押した瞬間
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		//音声停止
		Audio::GetInstance()->StopWave(voiceHandle_);
	}

	//デバッグテキストの表示
	ImGui::Begin("Debug1");
	//float3入力ボックス
	ImGui::InputFloat3("InputFloat3", inputFloat3);
	//float3スライダー
	ImGui::SliderFloat3("SliderFloat3", inputFloat3, 0.0f, 1.0f);
	//ImGui::Text("Kamata Tarou %d %d %d", 2050, 12, 31);
	ImGui::End();
	//デモウィンドウの表示を有効化
	ImGui::ShowDemoWindow();

	//デバッグカメラの更新
	deBugCamera_->Update();
}

void GameScene::Draw() 
{
	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	//ここにスプライトインスタンスの描画処理を記述する
	sprite_->Draw();

	//スプライト描画後処理
	Sprite::PostDraw();

	

	//3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	//ここに3Dモデルインスタンスの描画処理を記述する
	model_->Draw(worldTransform_, deBugCamera_->GetCamera(), textureHandle_);

	//3Dモデル描画後処理
	Model::PostDraw();

	//ラインを描画する
	//											始点座標		終点座標		色(RGBA)
	PrimitiveDrawer::GetInstance()->DrawLine3d({0, 0, 0}, {0, 10, 0}, {1.0f, 0.0f, 0.0f, 1.0f});
}


GameScene::~GameScene() 
{
	delete sprite_; 
	delete model_;
	delete deBugCamera_;
}