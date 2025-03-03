#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "main.h"
#define MAX_CAMERA (2)

//�\����
typedef struct
{
	D3DXVECTOR3 posV;			//	���_
	D3DXVECTOR3 posR;			//	�����_
	D3DXVECTOR3 vecU;			//	������x�N�g��
	D3DXMATRIX mtxProjection;	//	�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX mtxView;			//	�r���[�}�g���b�N�X
	D3DXVECTOR3 rot;			//	����
	float fDistance;			//	���_���璍���_�̋���
	D3DXVECTOR3 posRDest;
	D3DXVECTOR3 posVDest;
	D3DVIEWPORT9 viewport;
	float deltaX;
	float deltaY;
	POINT cursorPos;
	POINT prevCursorPos;
}Camera;

//	�Ղ�Ƃ�����
void InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(int nIdx);
void MouseWheel(int zDelta);
Camera* GetCamera(void);
bool IsLook(void);

#endif // !_CAMERA_H_
