BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string	"??Y t?? qu?? es lo que quieres?\p"
	.string	"??No ves que estamos ocupados?\n"
	.string	"??O es que no puedes esperar?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string	"Anda, mira, a primera vista\n"
	.string	"se ve que ENTRENAS con fiereza.\p"
	.string	"Je, je, je???\n"
	.string	"Oye, te propongo una cosa.\p"
	.string	"Hemos formado un grupillo aqu??,\n"
	.string	"y solemos jugar a un juego que va\l"
	.string	"sobre el FRENTE de BATALLA.\p"
	.string	"Las reglas son muy sencillas.\p"
	.string	"Primero, elegimos uno de los escenarios\n"
	.string	"que hay en el FRENTE de BATALLA.\p"
	.string	"Luego, cada uno elige a un ENTRENADOR\n"
	.string	"que vaya a participar en el desaf??o\l"
	.string	"de ese escenario y apostamos por ??l\l"
	.string	"nuestros PUNTOS de BATALLA.\p"
	.string	"El que apueste por el ENTRENADOR que\n"
	.string	"consiga el mejor resultado, se lleva\l"
	.string	"los PUNTOS de BATALLA de los dem??s.\p"
	.string	"??F??cil, verdad?\n"
	.string	"Pues eso.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera luchar en el COMBATE INDIVIDUAL\l"
	.string	"de la TORRE BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera luchar en el COMBATE DOBLE\l"
	.string	"de la TORRE BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera luchar en el COMBATE M??LTIPLE\l"
	.string	"de la TORRE BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en el TORNEO de COMBATES\l"
	.string	"INDIVIDUALES de la C??PULA BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en el TORNEO de COMBATES\l"
	.string	"DOBLES de la C??PULA BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en el TORNEO de COMBATES\l"
	.string	"con TRUEQUE INDIVIDUALES\l"
	.string	"en la F??BRICA BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en el TORNEO de COMBATES\l"
	.string	"con TRUEQUE DOBLES\l"
	.string	"en la F??BRICA BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera luchar en el COMBATE sin TUTELA\l"
	.string	"INDIVIDUAL del PALACIO BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera luchar en el COMBATE sin TUTELA\l"
	.string	"DOBLE del PALACIO BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en el TORNEO con JUEZ\l"
	.string	"en el DOJO BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en la ELECCI??N\l"
	.string	"de COMBATES en la SIERPE BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string	"Estoy buscando a un ENTRENADOR que\n"
	.string	"quiera entrar en la EXPEDICI??N\l"
	.string	"de COMBATES en la PIR??MIDE BATALLA.\p"
	.string	"Pero, hasta ahora, no he visto a nadie\n"
	.string	"que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string	"Creo que t?? tambi??n podr??as ganar algo.\n"
	.string	"As?? que, ??qu?? me dices?\l"
	.string	"??Aceptar??as ese desaf??o por m???$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string	"Perfecto??? ??Qu?? tal si me prestas\n"
	.string	"algunos de tus PUNTOS de BATALLA?\p"
	.string	"Conf??a en m??, s?? agradecer los favores\n"
	.string	"con creces.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string	"??Genial, genial!\n"
	.string	"??Cu??ntos me puedes prestar?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string	"??Oh, no, no, no! ??No tienes suficientes\n"
	.string	"PUNTOS de BATALLA!\p"
	.string	"??Yo que t?? no ir??a por ah?? burl??ndome de\n"
	.string	"la gente ni haci??ndole perder el tiempo!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string	"??Je, je, je! ??Muchas gracias!\n"
	.string	"??Venga, adelante!$"
	
BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string	"??Te espera el COMBATE INDIVIDUAL\n"
	.string	"de la TORRE BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??Nuestra fortuna est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string	"??Te espera el COMBATE DOBLE\n"
	.string	"de la TORRE BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string	"??Te espera el COMBATE M??LTIPLE\n"
	.string	"de la TORRE BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string	"??Te espera el TORNEO de COMBATES\n"
	.string	"INDIVIDUALES de la C??PULA BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string	"??Te espera el TORNEO de COMBATES\n"
	.string	"DOBLES de la C??PULA BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string	"??Te espera el TORNEO de COMBATES\n"
	.string	"con TRUEQUE INDIVIDUALES\l"
	.string	"de la F??BRICA BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string	"??Te espera el TORNEO de COMBATES\n"
	.string	"con TRUEQUE DOBLES\l"
	.string	"de la F??BRICA BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string	"??Te espera el COMBATE sin TUTELA\n"
	.string	"INDIVIDUAL del PALACIO BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string	"??Te espera el COMBATE sin TUTELA\n"
	.string	"DOBLE del PALACIO BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string	"??Te espera el TORNEO con JUEZ\n"
	.string	"del DOJO BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string	"??Te espera la ELECCI??N de COMBATES\n"
	.string	"de la SIERPE BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string	"??Te espera la EXPEDICI??N de COMBATES\n"
	.string	"de la PIR??MIDE BATALLA!\p"
	.string	"??No puedes perder!\n"
	.string	"??No me falles!\l"
	.string	"??El futuro de los dos est?? en tus manos!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string	"Ah, eres t?????\n"
	.string	"Buen intento???\p"
	.string	"Siento dec??rtelo, pero no puedo\n"
	.string	"devolverte tus PUNTOS de BATALLA???\p"
	.string	"??Tendremos que motivarnos para\n"
	.string	"hacerlo mejor la pr??xima vez!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string	"??Eh, hola!\p"
	.string	"??Sab??a que pod??as!\n"
	.string	"??Sab??a que lo har??as!\l"
	.string	"Gracias a ti, ??hemos ganado los dos!\p"
	.string	"Toma, tus PUNTOS de BATALLA\n"
	.string	"y, por supuesto, ??tu recompensa!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string	"{PLAYER} obtuvo\n"
	.string	"{STR_VAR_1} PUNTOS de BATALLA.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string	"Antes de aceptar otro desaf??o,\n"
	.string	"??habla antes conmigo!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string	"????No te interesa?!\n"
	.string	"??No deber??as tener miedo de probar!$"

BattleFrontier_Lounge3_Text_Oh::
	.string	"Oh???$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string	"??He apostado otra vez por\n"
	.string	"el ENTRENADOR equivocado!\p"
	.string	"Quiz??s deber??a combatir yo misma,\n"
	.string	"como hacen los dem??s???$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string	"Ese ENTRENADOR???\p"
	.string	"Es bueno, pero no lo veo con el aguante\n"
	.string	"necesario para la C??PULA BATALLA???$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string	"??Yo reconozco a un ENTRENADOR\n"
	.string	"ganador nada m??s verlo! ??Ji, ji, ji!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string	"Pero esos ENTRENADORES???\n"
	.string	"??Qu?? est??n haciendo?\l"
	.string	"Deber??an estar combatiendo, ??no?$"
