#pragma once

#include "JSystem/JGeometry/TVec.h"

namespace JGeometry {
	template<typename T>
	struct TPartition3 {

	};

	template<>
	struct TPartition3<f32> {
		inline TPartition3() { }

		void set(const TVec3<f32> &, const TVec3<f32> &);
		void set(const TVec3<f32> &, const TVec3<f32> &, const TVec3<f32> &);

		TVec3<f32> mNormal;
		f32 mDot;
	};
};

typedef JGeometry::TPartition3<f32> TPartitionf;
