#pragma once

#include "revolution.h"

class ScenarioData;

class GalaxyStatusAccessor {
public:
	GalaxyStatusAccessor(const ScenarioData *pScenarioData);

	const char* getName() const;

	s32 getPowerStarNum() const;
	s32 getGreenStarNum() const;
	s32 getZoneNum() const;
	int getZoneId(const char *pZoneName) const;
	const char* getZoneName(int zoneId) const;
	const char* getAppearPowerStarObjName(s32 scenario) const;

	s32 getCometScenarioId() const;
	bool isValidComet(s32 scenario) const;
	const char* getCometName(s32 scenario) const;
	s32 getCometLimitTimer(s32 scenario) const;
	bool isHiddenStar(s32 scenario) const;
	bool isGreenStar(s32 scenario) const;
	bool isNotNormalStar(s32 scenario) const;
	bool isGrandStar(s32 scenario) const;
	bool hasPowerStar(s32 scenario) const;
	bool isOwnBronzeStar(s32 scenario) const;
	bool isCompletedNoGreen() const;
	bool isCompletedWithGreen() const;
	bool isCompletedGreenStars() const;
	s32 getPowerStarNumOwnedTotal() const;
	bool isOpened() const;
	bool isOpenScenario(s32 scenario) const;
    bool isExistPowerStarAtScenario(s32, s32) const;
	s32 getWorldNo() const;
	s32 getPowerStarNumOwned() const;
	s32 getGreenStarNumOwned() const;

	ScenarioData* mScenarioData; // _0
};

namespace MR {
	GalaxyStatusAccessor makeGalaxyStatusAccessor(const char *pStageName);
	GalaxyStatusAccessor makeCurrentGalaxyStatusAccessor();
};
