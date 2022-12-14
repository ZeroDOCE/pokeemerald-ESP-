.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string	"??Aqu?? ponemos a prueba la suerte\n"
	.string	"de los ENTRENADORES!\p"
	.string	"??Te doy la bienvenida\n"
	.string	"a la SIERPE BATALLA!\p"
	.string	"Yo ser?? tu primera gu??a si aceptas\n"
	.string	"el desaf??o de la ELECCI??N de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string	"Dime, pues, ??aceptas el desaf??o\n"
	.string	"de la ELECCI??N de COMBATES?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string	"Si aceptas entrar aqu??, te enfrentar??s\n"
	.string	"a la llamada ELECCI??N de COMBATES.\p"
	.string	"Las reglas de la ELECCI??N de COMBATES\n"
	.string	"son muy simples???\p"
	.string	"Elige uno de los tres caminos y llega\n"
	.string	"a la ??ltima sala de la SIERPE BATALLA.\l"
	.string	"As?? de sencillo.\p"
	.string	"Pero recuerda: lo que te encuentres\n"
	.string	"en el camino que elijas, depender??\l"
	.string	"??nicamente de tu fortuna???\p"
	.string	"Si alcanzas la meta, recibir??s como\n"
	.string	"recompensa PUNTOS de BATALLA.\p"
	.string	"Si quieres interrumpir el desaf??o, habla\n"
	.string	"con cualquiera de mis compa??eras\l"
	.string	"que est??n en las salas grandes.\p"
	.string	"Si no guardas antes de salirte\n"
	.string	"del juego, se te descalificar??.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string	"Esperamos que vuelvas\n"
	.string	"pronto por aqu??.$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string	"El desaf??o se disputa en dos niveles:\n"
	.string	"el nivel 50 y el nivel libre. ??Cu??l eliges?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string	"Una l??stima???\p"
	.string	"No tienes tres POK??MON que puedan\n"
	.string	"participar en la ELECCI??N de COMBATES.\p"
	.string	"Necesitas tres POK??MON diferentes\n"
	.string	"de nivel 50 o inferior.\p"
	.string	"Adem??s, deben sostener distintos\n"
	.string	"tipos de objeto.\p"
	.string	"Los HUEVOS{STR_VAR_1} participar.\p"
	.string	"Vuelve cuando cumplas las condiciones\n"
	.string	"para aceptar el desaf??o.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string	"Una l??stima???\p"
	.string	"No tienes tres POK??MON que puedan\n"
	.string	"participar en la ELECCI??N de COMBATES.\p"
	.string	"Necesitas tres POK??MON diferentes\n"
	.string	"para poder participar.\p"
	.string	"Adem??s, deben sostener distintos\n"
	.string	"tipos de objeto.\p"
	.string	"Los HUEVOS{STR_VAR_1} participar.\p"
	.string	"Vuelve cuando cumplas las condiciones\n"
	.string	"para aceptar el desaf??o.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string	"Selecciona los tres POK??MON con los\n"
	.string	"que quieres combatir.$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string	"Antes de comenzar tu ELECCI??N de\n"
	.string	"COMBATES, debo guardar la partida.\l"
	.string	"??Est??s de acuerdo?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string	"Pasa por aqu??.$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string	"El desaf??o ha terminado???\p"
	.string	"Voy a guardar tus resultados.\n"
	.string	"Espera unos instantes.$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string	"Has logrado finalizar el desaf??o???\p"
	.string	"Debo reconocer??? que has tenido\n"
	.string	"mucha fortuna???$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string	"Vamos a guardar tus resultados.\n"
	.string	"Espera unos instantes.$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "To commemorate your completion of\n"
	.string "the Battle Choice challenge, we award\l"
	.string "you these Battle Point(s)???$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "You appear to have reached the limit\n"
	.string "for Battle Points???\p"
	.string "Please exchange some Battle Points\n"
	.string "for prizes, then return???$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string	"Una l??stima???\p"
	.string	"Se te olvid?? guardar la partida antes\n"
	.string	"de abandonar el desaf??o???\p"
	.string	"Me temo que se te ha descalificado???$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string	"Enhorabuena???\p"
	.string	"Has conseguido derrotar a la REINA\n"
	.string	"de la SIERPE y superar la gran prueba???$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string	"Premiaremos tu incre??ble fortuna\n"
	.string	"con PUNTOS de BATALLA???$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string	"??Grrr! ??La he pifiado!\n"
	.string	"??Y s??lo me quedaba una sala!\p"
	.string	"En este lugar hay que tener cuidado\n"
	.string	"con venenos, paralizantes y dem??s.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string	"Aunque no te lo creas, he terminado\n"
	.string	"el desaf??o 10 veces sin tener que\l"
	.string	"enfrentarme nunca a un ENTRENADOR.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string	"??Oye! ??Oye!\p"
	.string	"??No crees que aqu?? podr??as sacarles\n"
	.string	"mucho partido a las habilidades\l"
	.string	"especiales de los POK??MON?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "What is this weird place?\n"
	.string "I can't figure it out at all!\p"
	.string "I've taken the challenge a bunch\n"
	.string "of times, but all I ever do is run into\l"
	.string "TRAINERS whichever path I choose.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string	"Aqu?? est??n expuestas las reglas\n"
	.string	"de la ELECCI??N de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string	"??Qu?? cap??tulo quieres leer?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string	"La MOCHILA y el POK??NAV no pueden\n"
	.string	"usarse en la ELECCI??N de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string	"Durante la ELECCI??N de COMBATES,\n"
	.string	"las BAYAS o HIERBAS que sostengan los\l"
	.string	"POK??MON s??lo tendr??n efecto una vez.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string	"Durante la ELECCI??N de COMBATES,\n"
	.string	"el orden de salida de tus POK??MON\l"
	.string	"no puede cambiarse.\p"
	.string	"El orden debe fijarse antes de comenzar\n"
	.string	"el desaf??o.$"

