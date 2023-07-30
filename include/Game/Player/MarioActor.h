#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/Player/FireMarioBall.h"
#include "Game/Player/MarioMessenger.h"
#include "Game/Player/JetTurtleShadow.h"
#include "Game/Player/Mario.h"
#include "Game/Player/MarioAllModel.h"
#include "Game/Player/MarioNullBck.h"
#include "Game/Player/MarioParts.h"
#include "Game/Player/MarioSearchLight.h"
#include "Game/Player/ModelHolder.h"
#include "Game/Player/TornadoMario.h"
#include "Game/Util/Color8.h"

#define PLAYER_MODE_NORMAL 0
#define PLAYER_MODE_RAINBOW 1
#define PLAYER_MODE_FIRE 2
#define PLAYER_MODE_ICE 3
#define PLAYER_MODE_BEE 4
#define PLAYER_MODE_HOPPER 5
#define PLAYER_MODE_TERESA 6
#define PLAYER_MODE_FOO 7
#define PLAYER_MODE_BONE 8
#define PLAYER_MODE_TORNADO 9
#define PLAYER_MODE_YOSHI 10
#define PLAYER_MODE_HORROR 11
#define PLAYER_MODE_CLOUD 12
#define PLAYER_MODE_ROCK 13

#define PAUSE_HORROR_FLAG_TERESA_MARIO 0x1
#define PAUSE_HORROR_FLAG_GLARING_LIGHT 0x2
#define PAUSE_HORROR_FLAG_SUN_LIGHT 0x4

#define PLAYER_MODEL_FLAG_MARIO 0x1
#define PLAYER_MODEL_FLAG_INVINCIBLE 0x2
#define PLAYER_MODEL_FLAG_FIRE 0x4
#define PLAYER_MODEL_FLAG_ICE 0x8
#define PLAYER_MODEL_FLAG_BEE 0x10
#define PLAYER_MODEL_FLAG_HOPPER 0x20
#define PLAYER_MODEL_FLAG_TERESA 0x40
#define PLAYER_MODEL_FLAG_FLYING 0x80
#define PLAYER_MODEL_FLAG_BONE 0x100
#define PLAYER_MODEL_FLAG_TORNADO 0x200
#define PLAYER_MODEL_FLAG_YOSHI 0x400
#define PLAYER_MODEL_FLAG_HORROR 0x800
#define PLAYER_MODEL_FLAG_CLOUD 0x1000
#define PLAYER_MODEL_FLAG_ROCK 0x2000

class MarioActor : public LiveActor {
public:
	MarioActor(const char *);

	virtual ~MarioActor();
	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void movement();
	virtual void draw() const;
	virtual void calcAnim();
	virtual void calcViewAndEntry();
	virtual void unk1();
	virtual void unk2();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void updateHitSensor(HitSensor *);
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual bool receiveMsgPush(HitSensor *, HitSensor *);
	virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveMsgOtherAttack(u32, HitSensor *, HitSensor *);
	// three more virtual functions

	// todo: tons of functions to be documented
	TVec3f* getGravityVec() const;
	void setPlayerMode(u16, bool, bool);

	bool isEnableNerveChange() const;

	u8 _90;
	s32 _94;
	s32 _98[64];
	s32 _198;
	s32 _19C;
	s32 _1A0;
	u8 _1A4;
	u8 _1A5;
	f32 _1A8;
	s32 _1AC;
	u8 _1B0;
	u8 _1B1;
	MtxPtr _1B4[8];
	s32 _1D4[8];
	Mtx _1F4;
	Mtx _224;
	s16 _254;
	s16 _256;
	s16 _258;
	s32 _25C;
	s16 _260;
	Mtx _264;
	Mtx _294;
	s32 _2C4;
	Mtx _2C8;
	Mtx _2F8;
	Mtx _328;
	Mtx _358;
	Mtx _388;
	Mtx _3B8;
	Mtx _3E8;
	Mtx _418;
	Mtx _448;
	Mtx _478;
	Mtx _4A8;
	s16 _4D8;
	f32 _4DC;
	u8 _4E0;
	u8 _4E1;
	u8 _4E2;
	Mtx _4E4;
	u8 _514;
	u8 _515;
	u8 _516;
	s32 _518;
	s16 _51C;
	u8 _51E;
	s32 _520;
	s32 _524;
	TVec3f _528;
	TVec3f _534;
	TVec3f _540;
	s32 _54C;
	s16 _550;
	s16 _552;
	s16 _554;
	f32 _558;
	Color8 _55C;
	u8 _560;
	u8 _561;
	s32 _564;
	MarioMessenger* mMarioMessenger; // _568
	u8 _56C;
	u8 _56D;
	u8 _56E;
	s16 _570;
	u8 _572;
	u8 _573;
	u32* _574;
	s32 _578;
	u8 _57C;
	u32* mCollisionShadow; // _580
	Mario* mMario; // _584
	u32* mMarioAnimator; // _588
	u32* mMarioEffect; // _58C
	s32 _590;
	TVec3f _594;
	f32 _5A0;
	f32 _5A4;
	f32 _5A8;
	f32 _5AC;
	f32 _5B0;
	f32 _5B4;
	TVec3f _5B8;
	TVec3f _5C4;
	TVec3f _5D0;
	TVec3f _5DC;
	TVec3f _5E8;
	TVec3f _5F4;
	TVec3f _600;
	TVec3f _60C;
	TVec3f _mUpVec; // _618
	TVec3f _624;
	TVec3f _630;
	TVec3f _63C;
	TVec3f _648;
	TVec3f _654;
	s16 _660;
	s16 _662;
	s16 _664;
	u8 _666;
	s16 _668;
	TVec3f _66C;
	TVec3f _678;
	TVec3f _684;
	TVec3f _690;
	s32 _69C;
	u8 _6A0;
	f32 _6A4;
	s16 _6A8;
	s32 _6AC;
	s32 _6B0;
	s32 _6B4;
	s16 _6B8;
	s32 _6BC;
	s32 _6C0;
	s32 _6C4;
	s32 _6C8;
	u8 _6CC;
	s16 _6CE;
	s16 _6D0;
	s16 _6D2;
	f32 _6D4;
	TVec3f _6D8;
	u8 _6E4;
	u8 _6E5;
	TVec3f _6E8;
	s16 _6F4;
	s16 mModelFlags; // _6F6
	u16 mPlayerMode; // _6F8
	s16 _6FA;
	s16 _6FC;
	s16 _6FE;
	s16 _700;
	u8 _702;
	u8 _703;
	u8 _704;
	u8 _705;
	u8 _706;
	u8 _707;
	s32 _708;
	s32 _70C;
	HitSensor* _710[16];
	s32 _750;
	s32 _754;
	s32 _758;
	s32 _75C;
	f32 _760;
	s32 _764;
	u8 _768;
	u8 _769;
	bool _76A;
	u8 _76B;
	TVec3f _76C;
	f32 _778;
	s32 _77C;
	s32 _780;
	s32 _784;
	s32 _788;
	s32 _78C;
	s32 _790;
	s32 _794;
	s32 _798;
	f32 _79C;
	f32 _7A0;
	f32 _7A4;
	TVec3f _7A8;
	TVec3f _7B4;
	s32 _7C0[128]; // is this a pointer array?
	u8 _9C0;
	f32 _9C4;
	f32 _9C8;
	f32 _9CC[128];
	s32 _BCC[64];
	s16 _CCC;
	s16 _CCE;
	s16 _CD0;
	s32 _CD4[64];
	u8 _DD4[64];
	s32 _E14;
	s32 _E18;
	s32 _E1C;
	s32 _E20;
	bool mIsInRush; // _E24
	u8 _E25;
	s32 _E28;
	u8 _E2C;
	TVec3f _E30;
	u8 _E3C;
	u8 _E3D;
	s16 _E3E;
	s16 _E40;
	s16 _E42;
	s16 _E44;
	u8 _E46;
	u32* _E48[8];
	u8 _E68;
	TVec3f _E6C;
	f32 _E78;
	u8 _E7C;
	u8 _E7D;
	TornadoMario* mTornadoModel; // _E80
	u8 _E84;
	MarioParts* mSpinTicoModel; // _E88
	s32 _E8C;
	s32 _E90;
	JetTurtleShadow* mJetTurtleShadow; // _E94
	MarioParts* mTeresaModel; // _E98
	ModelHolder* mIceModel; // _E9C
	MarioParts* mFreezeModel; // _EA0
	ModelHolder* mInvincibleModel; // _EA4
	f32 _EA8;
	f32 _EAC;
	s32 _EB0;
	TVec3f _EB4;
	ModelHolder* mBeeModel; // _EC0
	MarioParts* mBeeWingModel; // _EC4
	u32* mBeeFur; // _EC8
	u8 _ECC;
	u8 _ECD;
	s16 _ECE;
	TVec3f _ED0;
	ModelHolder* mHopperModel; // _EDC
	ModelHolder* mBoneModel; // _EE0
	u32* mYoshiHolder; // _EE4
	ModelHolder* mHorrorModel; // _EE8
	ModelHolder* mCloudModel; // _EEC
	u32* mCloudMarioHat; // _EF0
	ModelHolder* mRockModel; // _EF4
	u8 _EF8;
	u8 _EF9;
	u8 _EFA;
	u8 _EFB;
	u8 _EFC;
	u8 _EFD;
	MarioAllModel* mMarioAllModel; // _F00
	s32 _F04;
	s32 _F08;
	TVec3f _F0C;
	u8 _F18;
	u8 _F19;
	s32 _F1C;
	s32 _F20;
	s32 _F24;
	s32 _F28;
	s32 _F2C;
	s32 _F30;
	u8 _F34;
	u8 _F35;
	u8 _F36;
	u8 _F37;
	s32 _F38;
	u8 _F3C;
	s32 _F40;
	TVec3f _F44;
	f32 _F50;
	f32 _F54;
	f32 _F58;
	f32 _F5C;
	f32 _F60;
	f32 _F64;
	f32 _F68;
	f32 _F6C;
	s32 _F70;
	s32 _F74;
	u32** mIceSteps; // _F78
	s16 _F7C;
	FireMarioBall* mFireBalls[5]; // _F80
	s32 _F94;
	u8 _F98;
	s16 _F9A;
	u8 _F9C;
	s16 _F9E;
	s32 _FA0;
	s32 _FA4;
	s32 _FA8;
	s32 _FAC;
	s16 _FB0;
	MarioNullBck* _FB4;
	bool _FB8;
	u8 _FB9;
	u8 _FBA;
	s16 _FBC;
	u8 _FBE;
	s16 _FC0;
	s16 _FC2;
	s32 _FC4;
	s32 _FC8;
	s32 _FCC;
	TVec3f _FD0;
	TVec3f _FDC;
	u8 _FE8;
	u8 _FE9;
	u8 _FEA;
	u8 _FEB;
	s16 _FEC;
	s16 _FEE;
	s16 _FF0;
	s16 _FF2;
	s32 _FF4;
	s32 _FF8;
	u8 _FFC;
	s32 _1000;
	s32 _1004;
	u8 _1008;
	u8 _1009;
	s16 _100A;
	s16 _100C;
	u8 _100E;
	u8 _100F;
	u8 _1010;
	TVec3f _1014;
	TVec3f _1020;
	TVec3f _102C;
	TVec3f _1038;
	TVec3f _1044;
	u8 _1050;
	u8 _1051;
	u8 _1052;
	u8 _1053;
	s32 _1054;
	TVec3f _1058;
	u8 _1064;
	u8 _1065;
	u8 _1066;
	u8 _1067;
	u8 _1068[4]; // unused
	s32 _106C;
	u8 _1070;
	u32* _1074;
	u32* _1078;
	u32* _107C;
	u32* _1080; // something with matrixvaluegetter
	u32* _1084; // rasterscroll
	u32* _1088;
	u32* _108C;
	s32 _1090;
	s32 _1094;
};
