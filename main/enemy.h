//=============================================================================
//
//	�G�̏��� [enemy.h]
// Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _ENEMY_H_//���̃}�N����`������Ă��Ȃ�������
#define _ENEMY_H_//2�e�C���N���[�h�h�~�̃}�N����`
#include "main.h"
#include "model.h"
#define GRAVI (0.05f)			//�d��
#define JUMP (2.0f)
#define OBJ_E (20.0f)
#define EPARTS_MAX (16)
#define EUSEPARTS_MAX (16)

//�G�̏��
typedef enum
{
	ENEMYSTATE_NORMAL = 0,
	ENEMYSTATE_DAMAGE,
	ENEMYSTATE_ACTION,
	ENEMYSTATE_MAX
}ENEMYSTATE;


//���[�V�����̎��
typedef enum
{
	EMOTIONTYPE_NEUTRAL = 0,//���n
	EMOTIONTYPE_MOVE,//�ړ�
	EMOTIONTYPE_ACTION,//�A�N�V����
	EMOTIONTYPE_JUMP,//�W�����v
	EMOTIONTYPE_LANDING,//���n
	EMOTIONTYPE_MAX
}EMOTIONTYPE;

//�L�[�̍\����
typedef struct
{
	float fPosX;//�ʒu
	float fPosY;
	float fPosZ;
	float fRotX;//����
	float fRotY;
	float fRotZ;
}EKEY;

//�L�[���̍\����
typedef struct
{
	int nFlame;//�Đ��t���[��
	EKEY aKey[EPARTS_MAX];//�p�[�c�̍ő吔������//�L�[���

}EKEY_INFO;

//���[�V�������̍\����
typedef struct
{
	bool bLoop;//���[�v���邩�ǂ���
	int nNumKey;//�L�[�̑���
	EKEY_INFO aKeyInfo[10];//�L�[�̍ő吔//�L�[���
}EMOTION_INFO;

//�v���C���[�\����
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 posOld;
	D3DXVECTOR3 size;
	D3DXVECTOR3 move;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 rotDest;
	D3DXMATRIX mtxWorld;//���[���h�}�g���b�N�X
	int nLife;
	int nType;
	int State;
	float fRad;
	bool bUse;

	Model aModel[EPARTS_MAX];	//���f���̃p�[�c��
	int nNumModel;		//���f���̃p�[�c����

	EMOTION_INFO aMotionInfo[8];//���[�V�����̍ő吔
	int nNumMotion;//���[�V�����̑���
	EMOTIONTYPE motionType;//���[�V�����̎��
	bool bLoopMotion;//���[�v���邩�ǂ���
	int nNumKey;//�L�[�̑���
	int nKey;//���݂̃L�[No.
	int nCntMotion;//���[�V�����J�E���^�[

	int nIdxLife;//���C�t�o�[��Idx
	int IdxShadow;
}Enemy;

//�v���g�^�C�v�錾
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(D3DXVECTOR3 pos, int nType);
void LoadEnemy(int nType);
void CollisionEnemy(void);
void HitEnemy(int nCnt, int nDamage);
void CollisionEnemytoEnemy(int nCnt);
Enemy*GetEnemy(void);
int GetNumEnemy();
static const char* EPARTS_FILE[EPARTS_MAX] =
{
	"data\\model\\redcar000.x",//��
	"data\\model\\spear.x",		//��
};


#endif