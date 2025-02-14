#ifndef _UI_H_
#define _UI_H_

#include <string>
#include "timer.h"
#include "vbrush.h"

namespace ui {
	struct app_data {
		const char*	version;
		timer::cpu_ms	tm;
	};

	struct mhw_data {
		struct player_info {
			bool		used = false,
					left_session = false;
			std::wstring	name;
			int32_t		damage = 0;

		};

		struct monster_info {
			bool		used = false;
			const char*	name = "<N/A>";
			float		hp_total = -1.0,
					hp_current = -1.0,
					body_size = 0;
			float		size = 0.0;
			const char*	crown = "";
		};

		std::wstring	session_id,
				host_name;
		player_info	players[4];
		monster_info	monsters[3];
	};

	enum draw_flags {
		SHOW_MONSTER_DATA = 1,
		SHOW_CROWN_DATA = 2,
	};

	extern void draw(vbrush::iface* b, const size_t flags, const app_data& ad, const mhw_data& d, const bool no_color, const bool compact_display);
}

#endif // _UI_H_

