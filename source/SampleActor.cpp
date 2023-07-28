#include "sample/SampleActor.h"
#include "Game/Util.h"

/*
* A simple custom actor to help you get started with the game's LiveActor system. This actor functions as described:
* - It is invisible and uses no model.
* - It can appear through SW_APPEAR, however, this is not necessary.
* - It uses a single sensor to interact with other objects, specifically the player.
* - The sensor's radius can be specified using Obj_arg0.
* - The sensor forcibly pushes the player away, preventing them from going *inside* the sensor.
* - When the sensor is attacked with a Spin Attack by the player or the Orange Luma, the actor gets killed.
*/

SampleActor::SampleActor(const char *pName) : LiveActor(pName) {

}

void SampleActor::init(const JMapInfoIter &rIter) {
    // Initializes position, rotation and scale from BCSV data
    MR::initDefaultPos(this, rIter);

    // Connects the object to the scene. MapObjMovement affects these four methods:
    // - movement(): Called on every frame.
    // - draw(): Ignored.
    // - calcAnim(): Ignored.
    // - calcViewAndEntry(): Ignored.
    MR::connectToSceneMapObjMovement(this);

    // Allocate array to fit exactly one sensor
    initHitSensor(1);

    // Get radius for sensor from Obj_arg0
    f32 radius = 1000.0f;
    MR::getJMapInfoArg0NoInit(rIter, &radius);

    // Prevent negative radius
    if (radius < 0.0f) {
        radius = 1000.0f;
    }

    // Create sensor with radius
    MR::addHitSensorMapObj(this, "Body", 8, radius, TVec3f(0.0f, 0.0f, 0.0f));

    // Synchronizes appearance with SW_APPEAR. Object will be appeared if SW_APPEAR is invalid (i.e. set to -1)
    MR::useStageSwitchSyncAppear(this, rIter);
}

void SampleActor::attackSensor(HitSensor *pSender, HitSensor *pReceiver) {
    if (MR::isSensorPlayerOrYoshiOrRide(pReceiver)) {
        if (MR::sendArbitraryMsg(ACTMES_PUSH_FORCE, pReceiver, pSender)) {
            OSReport("Push it good, push it real good.\n");
        }
    }
}

bool SampleActor::receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver) {
    if (MR::isMsgPlayerSpinAttackOrSupportTico(msg)) {
        kill();
        return true;
    }

    return false;
}
