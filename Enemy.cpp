#include "Enemy.h"
//#include"WorldTransformEx.cpp"

void Enemy::Initialize(Model* model, uint32_t textureHandle3) {
	// NULLポインタチェック
	assert(model);
	model_ = model;
	textureHandle3_ = textureHandle3;
	worldTransform_.translation_ = {1.0f,1.0f, 1.0f};
	worldTransform_.Initialize();
};

void Enemy::Update() {
	// 行列を定数バッファに転送

	const float kClientVeloctiy = 0.2f;
	Vector3 move = {0, 0, 0};

	// 回転速さ{ラジアン/frame}
	const float kRotSpeed = 0.02f;


	angle += 0.1;

	worldTransform_.translation_.x  =  (cos(angle) * 10);
	worldTransform_.translation_.y =  (sin(angle) * 10);



	//worldTransform_.translation_ = vectorTransform_->Add(worldTransform_.translation_, move);

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	
	// 行列の更新
	worldTransform_.TransferMatrix();
};



void Enemy::Draw(ViewProjection& viewProjection) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection, textureHandle3_);
};