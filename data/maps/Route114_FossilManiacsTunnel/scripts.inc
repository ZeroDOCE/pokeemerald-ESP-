.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string	"Soy el FOSILMAN??ACO???\n"
	.string	"Me ense??as un F??SIL y lo flipo???\p"
	.string	"??Quieres un F??SIL?\p"
	.string	"Me parece muy bien, pero todos los que\n"
	.string	"hay aqu?? son m??os, s??lo m??os???\p"
	.string	"Si necesitas desesperadamente\n"
	.string	"un F??SIL, ve al desierto. All?? hay rocas\l"
	.string	"y arena que quiz??s escondan F??SILES???$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string	"Has encontrado un F??SIL, ??no?\n"
	.string	"Qu?? bien??? Qu?? envidia me das???\p"
	.string	"??Qu?? vas a hacer con ese F??SIL?\p"
	.string	"Por lo que cuentan, DEVON est??\n"
	.string	"investigando c??mo reanimar\l"
	.string	"POK??MON a partir de F??SILES.\p"
	.string	"A m?? me chiflan mis F??SILES, as??\n"
	.string	"que no se me ocurrir??a hacer eso.$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string	"Los F??SILES son tan??? guays???\n"
	.string	"Me encantan???$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string	"Oh???\n"
	.string	"Ese camino es peligroso???\p"
	.string	"Yo estaba excavando, ??sabes????\n"
	.string	"Y de repente se derrumb?? la pared???\p"
	.string	"Creo que debajo hay una cueva gigante???\p"
	.string	"Pero a m?? no me interesa porque no\n"
	.string	"creo que haya F??SILES ah?????$"

