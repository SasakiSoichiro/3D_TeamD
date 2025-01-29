//================================================
//
//		�^�C�g��	title3D.cpp
//
//			ryuusei.hirata
//================================================
#include "title3D.h"
#include "fade.h"
#include "sound.h"
#include "camera.h"
#include "title.h"
#include "meshfield.h"
#include "light.h"
#include "model.h"

//�^�C�g���̏�����
void InitTitle3D(void)
{
	InitCamera();
	InitTitle();
	InitMeshfield();
	InitLighr();
}

//�^�C�g���̏I������
void UninitTitle3D()
{
	UninitCamera();
	UninitTitle();
	UninitMeshfield();
	UninitLight();
}

//�^�C�g���̍X�V����
void UpdateTitle3D()
{
	UpdateCamera();
	UpdateTitle();
	UpdateMeshfield();
	UpdateLight();
}

//�^�C�g���̕`�揈��
void DrawTitle3D()
{
	DrawMeshfield();
	DrawTitle();
}
