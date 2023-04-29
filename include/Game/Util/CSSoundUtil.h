#pragma once

#include "revolution.h"

/* FINISHED */

namespace MR {
    s32 getCSSoundID(const char *pCSSoundName);

    void startCSSound(s32 csSoundID, const char *pCsSoundName, s32, s32 wiimote, f32 volume);
    void startCSSound(const char *pCsSoundName, const char *pSystemSoundName, s32 wiimote, s32, f32 volume);
    void startCSSound1P(const char *pCsSoundName, s32, f32 volume);
    void startCSSound2P(const char *pCsSoundName, const char *pSystemSoundName, s32, f32 volume);

    void stopCSSound(s32 fadeTime, s32 wiimote);
    void stopAndStartCSSound1P(const char *pCsSoundName, s32 fadeTime, const char *pSystemSoundName, s32, f32 volume);
    void stopAndStartCSSound2P(const char *pCsSoundName, s32 fadeTime, const char *pSystemSoundName, s32, f32 volume);

    void startCSSoundAfterPlayed(const char *pCsSoundName, s32 wiimote);
};
