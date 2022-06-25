#pragma once

#include "JSystem/JGeometry/TPartition.h"

namespace JGeometry {
	template<typename T>
	struct THexahedron3 {

	};

	template<>
	struct THexahedron3<f32> {
		inline THexahedron3() { }

		bool mayIntersectBall3(const TVec3<f32> center, f32 radius) const;

		TPartition3<f32> mPlanes[6];
	};
};

typedef JGeometry::THexahedron3<f32> THex3f;
