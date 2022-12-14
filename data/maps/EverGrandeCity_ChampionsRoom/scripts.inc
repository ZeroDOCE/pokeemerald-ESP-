.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string	"PLUBIO: Hola, {PLAYER}{KUN}.\p"
	.string	"En ARREC??POLIS hiciste un gran\n"
	.string	"trabajo. Lograste poner fin a la crisis\l"
	.string	"sin ayuda.\p"
	.string	"Bueno???\p"
	.string	"No ser??a justo decir que no\n"
	.string	"contaste con ninguna ayuda.\p"
	.string	"Lo cierto es que lograste superar\n"
	.string	"las dificultades gracias al trabajo\l"
	.string	"en equipo con tus POK??MON.\p"
	.string	"Los ENTRENADORES damos objetos\n"
	.string	"a nuestros POK??MON y les ense??amos\l"
	.string	"t??cnicas de lucha para fortalecerlos.\p"
	.string	"Pero tambi??n podemos aprender\n"
	.string	"mucho de los POK??MON.\p"
	.string	"Y es ah?? donde hay que demostrar\n"
	.string	"lo lejos que se ha llegado con respecto\l"
	.string	"a otros ENTRENADORES.\p"
	.string	"??Por ejemplo, ahora mismo!\p"
	.string	"??Qui??n baila con m??s elegancia\n"
	.string	"con sus POK??MON en HOENN?\p"
	.string	"??Lleg?? la hora de saberlo!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string	"Has derrotado al CAMPE??N???\p"
	.string	"Has hecho un trabajo magn??fico.\n"
	.string	"Tu elegancia ha sido innegable,\l"
	.string	"ha rozado casi la perfecci??n???\p"
	.string	"??Me inclino ante ti, {PLAYER}{KUN}!\p"
	.string	"??Dominas el arte de entrenar\n"
	.string	"POK??MON!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string	"PLUBIO: Esos POK??MON que has usado\n"
	.string	"en combate???\p"
	.string	"A veces danzaban con delicadeza,\n"
	.string	"como una ligera brisa, y otras\l"
	.string	"atacaban con la furia del rayo.\p"
	.string	"Supiste guiar a tus POK??MON con\n"
	.string	"una elegancia sutil y firme a la par.\p"
	.string	"??Tu magistral ejecuci??n\n"
	.string	"me ha deslumbrado incluso a m??!\p"
	.string	"Puedes vanagloriarte de haber llegado\n"
	.string	"a la cima de la LIGA POK??MON.\p"
	.string	"La regi??n de HOENN tiene el orgullo\n"
	.string	"de proclamarte???$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string	"AURA: ??{PLAYER}{KUN}!\p"
	.string	"Te voy a dar un consejo antes de que\n"
	.string	"te enfrentes al CAMPE??N, ??te parece?$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string	"AURA: ??Eh? ??Qu?? ha pasado? ??Qu???\p"
	.string	"{PLAYER}{KUN}???\n"
	.string	"??Entonces ya est???\l"
	.string	"??Lo has logrado?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string	"BRUNO: ??{PLAYER}!\p"
	.string	"??Quieres que te d?? alg??n consejo\n"
	.string	"antes de enfrentarte al CAMPE??N?$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string	"BRUNO: {PLAYER}???\p"
	.string	"Pero??? ??me est??s diciendo????\n"
	.string	"??Que has vencido al CAMPE??N?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string	"PROF. ABEDUL: ??Lo ves?\n"
	.string	"??Qu?? te hab??a dicho, {RIVAL}?\p"
	.string	"??No te dije que no ten??as que\n"
	.string	"preocuparte por {PLAYER}{KUN}?\p"
	.string	"Si yo lo sab??a???\n"
	.string	"{PLAYER}{KUN}, lo has logrado.\p"
	.string	"Cuando o?? que hab??as derrotado\n"
	.string	"a tu propio padre en el GIMNASIO\l"
	.string	"de PETALIA, vi tu potencial???\p"
	.string	"??Y ahora te has hecho\n"
	.string	"con el CAMPEONATO!\p"
	.string	"??Qu?? orgulloso estoy!\p"
	.string	"??D??nde tienes la POK??DEX?\n"
	.string	"A ver, d??jame ver???$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string	"PROF. ABEDUL: Pues eso, ??felicidades!\p"
	.string	"Ya puedes entrar con orgullo\n"
	.string	"en la ??ltima sala.$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string	"PLUBIO: {PLAYER}{KUN}???\p"
	.string	"A ver si lo digo bien???\p"
	.string	"??El CAMPEONATO es tuyo!\p"
	.string	"Acomp????ame???$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string	"PLUBIO: Lo siento, pero???\p"
	.string	"s??lo los ENTRENADORES que se han\n"
	.string	"convertido en CAMPEONES pueden pasar.\p"
	.string	"Tendr??s que esperar fuera\n"
	.string	"con el PROF. ABEDUL.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string	"AURA: ??Y por qu???\p"
	.string	"Brrrrr???\p"
	.string	"Bueno, vale, las reglas son las reglas???\p"
	.string	"??{PLAYER}{KUN}!\n"
	.string	"??Felicidades de coraz??n!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string	"BRUNO: Pero yo quiero entrar???\p"
	.string	"En fin, si son las reglas???\p"
	.string	"??{PLAYER}, adelante!\n"
	.string	"??Mi m??s sincera enhorabuena!$"

