#ifndef TEXTURE_H
#define TEXTURE_H

#include "RGUI.h"

namespace RGUI {
	namespace Textures {
		namespace Checkbox {
			namespace R_LG {
				constexpr char* BOX_CHECKED_DARK	= "res/textures/checkbox/r_lg/box_checked_dark.png";
				constexpr char* BOX_CHECKED_LIGHT	= "res/textures/checkbox/r_lg/box_checked_light.png";
				constexpr char* BOX_UNCHECKED_DARK	= "res/textures/checkbox/r_lg/box_unchecked_dark.png";
				constexpr char* BOX_UNCHECKED_LIGHT	= "res/textures/checkbox/r_lg/box_unchecked_light.png";
			}
			namespace R_MD {
				constexpr char* BOX_CHECKED_DARK	= "res/textures/checkbox/r_md/box_checked_dark.png";
				constexpr char* BOX_CHECKED_LIGHT	= "res/textures/checkbox/r_md/box_checked_light.png";
				constexpr char* BOX_UNCHECKED_DARK	= "res/textures/checkbox/r_md/box_unchecked_dark.png";
				constexpr char* BOX_UNCHECKED_LIGHT = "res/textures/checkbox/r_md/box_unchecked_light.png";
			}
			inline namespace Sharp {
				constexpr char* BOX_CHECKED_DARK	= "res/textures/checkbox/sharp/box_checked_dark.png";
				constexpr char* BOX_CHECKED_LIGHT	= "res/textures/checkbox/sharp/box_checked_light.png";
				constexpr char* BOX_UNCHECKED_DARK	= "res/textures/checkbox/sharp/box_unchecked_dark.png";
				constexpr char* BOX_UNCHECKED_LIGHT = "res/textures/checkbox/sharp/box_unchecked_light.png";
			}
		}
		namespace Radio {
			inline namespace Round {
				constexpr char* RADIO_CHECKED_DARK		= "res/textures/radio/round/radio_checked_dark.png";
				constexpr char* RADIO_CHECKED_LIGHT		= "res/textures/radio/round/radio_checked_light.png";
				constexpr char* RADIO_UNCHECKED_DARK	= "res/textures/radio/round/radio_checked_dark.png";
				constexpr char* RADIO_UNCHECKED_LIGHT	= "res/textures/radio/round/radio_checked_light.png";
			}
			namespace Sharp {
				constexpr char* RADIO_CHECKED_DARK		= "res/textures/radio/sharp/radio_checked_dark.png";
				constexpr char* RADIO_CHECKED_LIGHT		= "res/textures/radio/sharp/radio_checked_light.png";
				constexpr char* RADIO_UNCHECKED_DARK	= "res/textures/radio/sharp/radio_checked_dark.png";
				constexpr char* RADIO_UNCHECKED_LIGHT	= "res/textures/radio/sharp/radio_checked_light.png";
			}
		}
	}
}

#endif
