#pragma once

#include "revolution.h"

namespace JGeometry {
	template<typename T>
	class TUtil {
	public:
	};

	template<>
	class TUtil<f32> {
	public:
		static f32 PI();

		static f32 asin(f32);
		static f32 acos(f32);

		static f32 sqrt(f32);
		static f32 inv_sqrt(f32);

		static f32 clamp(f32, f32, f32);
		
		static bool epsilonEquals(f32, f32, f32);
	};
};
