.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string	"AURA: ??{PLAYER}{KUN}, cu??nto tiempo!\p"
	.string	"??Anda! Mientras yo estaba en los ba??os\n"
	.string	"termales, t?? has ganado la MEDALLA\l"
	.string	"del GIMNASIO de LAVACALDA.\p"
	.string	"Debes de haber atrapado buenos\n"
	.string	"POK??MON??? ??O no? ??Es m??s\l"
	.string	"bien que los has entrenado t???\p"
	.string	"Creo que te mereces esto???$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string	"AURA: Con estas GAFAS AISLANTES,\n"
	.string	"no tendr??s problemas para atravesar el\l"
	.string	"desierto que hay cerca de la RUTA 111.\p"
	.string	"Pero hay que ver, {PLAYER}{KUN}???\n"
	.string	"Nada menos que luchando en GIMNASIOS???\p"
	.string	"Est??s esforz??ndote tanto para\n"
	.string	"asegurarte de no perder contra m?????\p"
	.string	"{PLAYER}{KUN}, ??sabes?, voy a ir a retar\n"
	.string	"a tu padre al GIMNASIO de PETALIA.\p"
	.string	"??Nos vemos!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string	"BRUNO: ??{PLAYER}! ??Ya hace un tiempo\n"
	.string	"que no nos vemos! ??Qu?? tal te va?\p"
	.string	"Aj?????\n"
	.string	"??Qu?? buena colecci??n de MEDALLAS!\p"
	.string	"Muy bien, te lo has ganado.\n"
	.string	"Te voy a dar esto???$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string	"BRUNO: P??ntelas si piensas acercarte\n"
	.string	"al desierto que hay por la RUTA 111.\p"
	.string	"Algunos POK??MON viven exclusivamente\n"
	.string	"en el desierto. B??scalos.\p"
	.string	"En cuanto a m?????\n"
	.string	"Estoy pens??ndome desafiar a NORMAN,\l"
	.string	"el L??DER del GIMNASIO de PETALIA.\p"
	.string	"Al contrario que t??, {PLAYER}, tu padre\n"
	.string	"s?? que parece un tipo duro.\p"
	.string	"??Ya nos veremos!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string	"Tengo un HUEVO.\p"
	.string	"Pens?? que cubri??ndolo con arena\n"
	.string	"caliente en los ba??os termales se\l"
	.string	"abrir??a, pero qu?? va???\p"
	.string	"Me han dicho que ser??a mejor que\n"
	.string	"estuviera con otros POK??MON.\p"
	.string	"T?? entrenas POK??MON, ??no? Y tus\n"
	.string	"POK??MON parecen estar en forma.\p"
	.string	"As?? que ??qu?? me dices?\n"
	.string	"??Llevar??as este HUEVO contigo?$"
	
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string	"??Bien! ??Espero que corras muchas\n"
	.string	"aventuras junto a mi HUEVO!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string	"{PLAYER} recibi?? un HUEVO.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string	"Oooh??? Tienes demasiados POK??MON.\n"
	.string	"No te queda sitio para este HUEVO???$"

LavaridgeTown_Text_AsYouWishThen:
	.string	"Como desees???\p"
	.string	"Pero si cambias de opini??n sobre el\n"
	.string	"HUEVO, ven a verme.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string	"De vez en cuando, aparece un HUEVO\n"
	.string	"en la GUARDER??A POK??MON.\p"
	.string	"Vamos, eso dicen por ah?????$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string	"Extraemos toda el agua caliente que\n"
	.string	"necesitamos, pero la fuente no se seca.\p"
	.string	"??A que parece magia?\p"
	.string	"Estos ba??os termales parecen casi\n"
	.string	"volcanes. Los canales de agua\l"
	.string	"subterr??nea se calientan con el\l"
	.string	"magma y luego salen a la superficie.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string	"Aqu?? enterradito en la arena caliente\n"
	.string	"estoy tan???, ay???\p"
	.string	"Tan calentito, tan a gustito???\p"
	.string	"??Eh? ??Ayyyyy!\p"
	.string	"??Un POK??MON me ha dado un pellizco\n"
	.string	"en el trasero!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string	"??A ti tambi??n te gustan los ba??os\n"
	.string	"termales?\p"
	.string	"Es curioso, la gente joven no suele\n"
	.string	"interesarse por esto???$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string	"Yo me ba??o en las aguas termales\n"
	.string	"cada d??a del a??o.\p"
	.string	"Son tan ben??ficas que sin duda me\n"
	.string	"convertir??n en una L??DER de GIMNASIO\l"
	.string	"tan fuerte como CANDELA.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string	"Imag??nate que la gente metiera a los\n"
	.string	"POK??MON en los ba??os termales???\p"
	.string	"??Tendr??amos ba??os el??ctricos, ba??os\n"
	.string	"de burbujas, ba??os de lava???!$"

LavaridgeTown_Text_HotSpringsClaims:
	.string	"Aseguran que estos ba??os termales\n"
	.string	"son buenos para los nervios, los dolores\l"
	.string	"musculares, los problemas amorosos,\l"
	.string	"los granos, los bolsillos sin blanca???$"

LavaridgeTown_Text_TownSign:
	.string	"PUEBLO LAVACALDA\p"
	.string	"BA??OS TERMALES del CENTRO POK??MON\n"
	.string	"?????No hay nada m??s relajante!???$"

LavaridgeTown_Text_GymSign:
	.string	"GIMNASIO POK??MON de PUEBLO LAVACALDA\n"
	.string	"L??DER: CANDELA\l"
	.string	"?????No te acerques mucho, que quemo!???$"

LavaridgeTown_Text_HerbShopSign:
	.string	"HERBOLARIO POK??MON\n"
	.string	"???Sabe fatal, pero te sienta genial.???$"
