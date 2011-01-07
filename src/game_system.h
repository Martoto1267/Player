/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Player.
//
// EasyRPG Player is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG Player is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef _GAME_SYSTEM_H_
#define _GAME_SYSTEM_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include "rpg_music.h"
#include "rpg_sound.h"

////////////////////////////////////////////////////////////
/// Game System namespace
////////////////////////////////////////////////////////////
namespace Game_System {
	enum sys_bgm {
		BGM_Battle,
		BGM_Victory,
		BGM_Inn,
		BGM_Skiff,
		BGM_Ship,
		BGM_Airship,
		BGM_GameOver,

		BGM_Count
	};

	enum sys_sfx {
		SFX_Cursor,
		SFX_Decision,
		SFX_Cancel,
		SFX_Buzzer,
		SFX_BeginBattle,
		SFX_Escape,
		SFX_EnemyAttacks,
		SFX_EnemyDamage,
		SFX_AllyDamage,
		SFX_Evasion,
		SFX_EnemyKill,
		SFX_UseItem,

		SFX_Count
	};

	enum sys_transition {
		Transition_TeleportErase,
		Transition_TeleportShow,
		Transition_BeginBattleErase,
		Transition_BeginBattleShow,
		Transition_EndBattleErase,
		Transition_EndBattleShow,
		Transition_Count
	};

	enum sys_timer {
		Timer1,
		Timer2
	};

	class Timer {
	public:
		int value;
		bool running;
		bool visible;
		bool battle;

		Timer() :
			value(0),
			running(false),
			visible(false),
			battle(false) {}

		void Update();
	};

	////////////////////////////////////////////////////////
	/// Initialize Game System.
	////////////////////////////////////////////////////////
	void Init();

	////////////////////////////////////////////////////////
	/// Play a Music.
	/// @param bgm : music data.
	////////////////////////////////////////////////////////
	void BgmPlay(RPG::Music bmg);

	////////////////////////////////////////////////////////
	/// Play a Sound.
	/// @param se : sound data.
	////////////////////////////////////////////////////////
	void SePlay(RPG::Sound se);

	////////////////////////////////////////////////////////
	/// Get system graphic name.
	/// @return system graphic filename
	////////////////////////////////////////////////////////
	std::string GetSystemName();

	////////////////////////////////////////////////////////
	/// Set the system graphic.
	/// @param system_name : new system name
	////////////////////////////////////////////////////////
	void SetSystemName(std::string system_name);

	////////////////////////////////////////////////////////
	/// Set the system music
	/// @param which : which "context" to set the music for
	/// @param bgm   : the music
	////////////////////////////////////////////////////////
	void SetSystemBGM(int which, RPG::Music bgm);

	////////////////////////////////////////////////////////
	/// Set a system sound effect
	/// @param which : which "context" to set the effect for
	/// @param bgm   : the sound
	////////////////////////////////////////////////////////
	void SetSystemSE(int which, RPG::Sound sfx);

	////////////////////////////////////////////////////////
	/// Set a timer
	/// @param which   : which timer to set
	/// @param seconds : the time in seconds
	////////////////////////////////////////////////////////
	void SetTimer(int which, int seconds);

	////////////////////////////////////////////////////////
	/// Start a timer
	/// @param which   : which timer to start
	/// @param visible : whether the timer is visible
	/// @param visible : whether the timer runs during battle
	////////////////////////////////////////////////////////
	void StartTimer(int which, bool visible, bool battle);

	////////////////////////////////////////////////////////
	/// Stop a timer
	/// @param which   : which timer to stop
	////////////////////////////////////////////////////////
	void StopTimer(int which);

	////////////////////////////////////////////////////////
	/// Update all timers
	////////////////////////////////////////////////////////
	void UpdateTimers();

	////////////////////////////////////////////////////////
	/// Set the system transitions
	/// @param which : which "context" to set the transition for
	/// @param trans : the transition
	////////////////////////////////////////////////////////
	void SetTransition(int which, int transition);

	/// Menu saving option disabled flag.
	extern bool save_disabled;
	extern bool teleport_disabled;
	extern bool escape_disabled;
	extern bool main_menu_disabled;
	extern RPG::Music current_bgm;
	extern RPG::Music memorized_bgm;
	extern RPG::Music system_bgm[BGM_Count];
	extern RPG::Sound system_sfx[SFX_Count];
	extern Timer timers[2];
	extern int transitions[Transition_Count];

	/// Numbers of saves.
	extern unsigned int save_count;
}

#endif
