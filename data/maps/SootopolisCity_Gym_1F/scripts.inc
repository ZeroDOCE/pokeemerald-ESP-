SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string	"Eh, ??c??mo lo llevas, {PLAYER}?\n"
	.string	"??Camino del CAMPEONATO?\p"
	.string	"GALANO, el L??DER del GIMNASIO\n"
	.string	"de ARREC??POLIS es un maestro\l"
	.string	"de los POK??MON de tipo AGUA.\p"
	.string	"Y, si quieres llegar hasta GALANO,\n"
	.string	"tendr??s que superar un suelo helado.\p"
	.string	"Lo siento, pero no puedo decirte m??s.\p"
	.string	"??El resto tendr??s que descubrirlo t??!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string	"??Guau! ??Has vencido incluso a GALANO,\n"
	.string	"que seg??n dicen es el mejor de HOENN!\p"
	.string	"Muy bien, comprueba tu FICHA\n"
	.string	"de ENTRENADOR.\p"
	.string	"Si tienes todas las MEDALLAS, puedes\n"
	.string	"aceptar el desaf??o de la LIGA POK??MON.$"
	
SootopolisCity_Gym_1F_Text_JuanIntro:
	.string	"Quisiera explicarte algo.\n"
	.string	"No s?? si sabr??s???\l"
	.string	"Uf, no s?? por qu?? me da corte???\p"
	.string	"Ver??s, yo ense???? a PLUBIO todo lo que\n"
	.string	"se puede saber sobre los POK??MON.\p"
	.string	"Cuando acab??, renunci?? a mi puesto\n"
	.string	"como L??DER de GIMNASIO.\p"
	.string	"Decid?? confiar esa responsabilidad\n"
	.string	"a PLUBIO.\p"
	.string	"Sin embargo, retom?? mi puesto\n"
	.string	"por una raz??n de peso???\p"
	.string	"Pero ya basta de charlas???\n"
	.string	"Deber??amos luchar, ??no?\p"
	.string	"Quisiera que fueras testigo\n"
	.string	"de nuestra maestr??a.\p"
	.string	"??Mis POK??MON y yo hemos\n"
	.string	"creado una gran ilusi??n acu??tica!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string	"??Ja, ja, ja! ??Magn??fico!\n"
	.string	"La victoria es tuya.\p"
	.string	"Tengo el presentimiento de que\n"
	.string	"tu destreza te llevar?? a lo m??s alto.\p"
	.string	"No obstante, en comparaci??n conmigo\n"
	.string	"o PLUBIO, te falta elegancia.\p"
	.string	"Puede que sea una buena idea\n"
	.string	"prestarte mi traje???\p"
	.string	"??Te lo presto????\n"
	.string	"??No te lo presto? ???\p"
	.string	"??Que no, que es broma!\p"
	.string	"??Te voy a dar algo mejor! ??Aqu??\n"
	.string	"tienes la MEDALLA LLUVIA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string	"{PLAYER} recibi?? la MEDALLA LLUVIA\n"
	.string	"de GALANO.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string	"La MEDALLA LLUVIA te concede la\n"
	.string	"obediencia total de todos tus POK??MON\l"
	.string	"a cada una de tus ??rdenes.\p"
	.string	"Tambi??n te permite usar el movimiento\n"
	.string	"de la MO CASCADA, que hace posible\l"
	.string	"que subas por cualquier catarata.\p"
	.string	"Y, adem??s, para que nunca olvides\n"
	.string	"nuestro combate, toma esto???$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string	"La MT que te he dado contiene\n"
	.string	"HIDROPULSO.\p"
	.string	"Lanza ondas ultras??nicas que pueden\n"
	.string	"confundir a tu rival.\p"
	.string	"Es una pasada???$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string	"Acabas de registrar a GALANO,\n"
	.string	"el L??DER de GIMNASIO, en el POK??NAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string	"Los ENTRENADORES que han reunido\n"
	.string	"todas las MEDALLAS de GIMNASIO\l"
	.string	"de HOENN deben dar el siguiente paso???\p"
	.string	"??La LIGA POK??MON!\p"
	.string	"Viaja al extremo oriental de HOENN,\n"
	.string	"a la isla de COLOSALIA.\l"
	.string	"La LIGA POK??MON est?? all??.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string	"S??lo te queda una MEDALLA\n"
	.string	"por obtener en HOENN.\p"
	.string	"Si quieres llegar hasta la LIGA\n"
	.string	"POK??MON, debes conseguirla\l"
	.string	"en el GIMNASIO de ARBORADA.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string	"GIMNASIO POK??MON de ARREC??POLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string	"GIMNASIO POK??MON de ARREC??POLIS\p"
	.string	"NUEVOS ENTRENADORES CERTIFICADOS:\n"
	.string	"{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string	"GALANO: Ah, este GIMNASIO por fin\n"
	.string	"ha vuelto a ser un oasis de serenidad???\p"
	.string	"Pero nuestro peque??o maremoto\n"
	.string	"ha regresado para ponernos a prueba.\p"
	.string	"??Ser?? un placer darte satisfacci??n!\p"
	.string	"??Estar?? dispuesto a enfrentarme\n"
	.string	"a ti todas las veces que quieras!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string	"??Ja, ja, ja! La victoria es tuya.\n"
	.string	"??Me has derrotado una vez m??s!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string	"GALANO: Si te propusiera que fueras\n"
	.string	"mi aprendiz, te negar??as, lo s??.\p"
	.string	"Quisiera ofrecerte mi abrigo\n"
	.string	"como regalo.\p"
	.string	"Pero tambi??n lo rechazar??as,\n"
	.string	"estoy convencido.\p"
	.string	"??Y eso, sin duda, demuestra\n"
	.string	"la nobleza de tu car??cter!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string	"GALANO: Ah, este GIMNASIO por fin\n"
	.string	"ha vuelto a ser un oasis de serenidad???\p"
	.string	"Pero nuestro peque??o maremoto\n"
	.string	"ha regresado para ponernos a prueba.\p"
	.string	"??Ser?? un placer darte satisfacci??n!\p"
	.string	"Pero no, no, no. Ni hablar.\n"
	.string	"S??lo tienes un POK??MON.\p"
	.string	"Te agradecer??a que regresaras\n"
	.string	"con dos o incluso m??s POK??MON.$"

