#pragma once
//#include "Model.h"
//#include "Matrix/MatrixTransform.h"
//#include"Vector/VectorTransform.h"


#include "Input.h"
#include "Model.h"
#include <list>
#include "Matrix/MatrixTransform.h"
#include"Vector/VectorTransform.h"
#include <PlayerBullet.h>


class Enemy {
public:
	void Initialize(Model* model, uint32_t textureHandle3_);

	void Update();

	void Draw(ViewProjection& viewProjection);


	

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	float angle = 0;

	// テクスチャハンドル
	uint32_t textureHandle3_ = 0u;

	MatrixTransform* matrix_ = new MatrixTransform();
	VectorTransform* vectorTransform_ = new VectorTransform();

};
