#pragma once

#include "revolution.h"

class NPCActorItem;
class TalkMessageCtrl;

namespace MR {
	void getNPCItemData(NPCActorItem *, s32);

    bool tryTalkNearPlayer(TalkMessageCtrl *);
};
