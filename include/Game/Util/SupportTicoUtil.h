#pragma once

#include "revolution.h"

class LiveActor;
class HitSensor;

namespace MR {
	void setSupportTicoAttachRangeGliBird();
	void resetSupportTicoAttachRangeGliBird();
	void setSupportTicoAttachRangeTubeSlider();
	void resetSupportTicoAttachRangeTubeSlider();

	void offSupportTicoControl();
	void onSupportTicoControl();

	bool attachSupportTicoToTarget(const LiveActor *pTarget);
	void joinSupportPlayGroup(LiveActor *pActor);

	bool isNeedExplainSupportTico();
	bool isMsgSupportPlayGroupStart(u32 msg);
	bool isMsgSupportPlayGroupStop(u32 msg);

	bool sendMsgSupportPlayGroupStart(LiveActor *pActor);
	bool sendMsgSupportPlayGroupStop(LiveActor *pActor);
	bool sendMsgSupportTicoSpin(HitSensor *pSender, HitSensor *pReceiver);
};
