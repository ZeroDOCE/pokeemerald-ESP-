.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string	"Soy el ENCARGADO de la GUARDER??A.\p"
	.string	"Ayudo a los ENTRENADORES a cuidar\n"
	.string	"de sus preciosos POK??MON.\p"
	.string	"Si quieres que me encargue del tuyo,\n"
	.string	"ve a hablar con mi mujer.$"

Route117_Text_DoYouWantEgg:
	.string	"??Ah, eres t??!\p"
	.string	"??Hemos cuidado de tu POK??MON y vaya\n"
	.string	"sorpresa que nos hemos llevado!\p"
	.string	"??Tu POK??MON ha tenido un HUEVO!\p"
	.string	"No sabemos c??mo ha sucedido,\n"
	.string	"pero es de tu POK??MON, seguro.\p"
	.string	"??Lo quieres?$"

Route117_Text_YourMonIsDoingFine:
	.string	"??Ah, eres t??! Me alegro de verte.\n"
	.string	"Tu {STR_VAR_1} est?? estupendamente.$"

Route117_Text_IllKeepIt:
	.string	"Muy bien, entonces me seguir??\n"
	.string	"ocupando de ??l. ??Gracias!$"

Route117_Text_YouHaveNoRoomForIt:
	.string	"No tienes sitio para ??l???\n"
	.string	"Vuelve cuando lo tengas.$"

Route117_Text_ReceivedEgg:
	.string	"{PLAYER} recibi?? el HUEVO del\n"
	.string	"ENCARGADO de la GUARDER??A.$"

Route117_Text_TakeGoodCareOfIt:
	.string	"Cu??dalo bien.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string	"Por cierto, con respecto a tu\n"
	.string	"{STR_VAR_1}, parece que se ha hecho\l"
	.string	"amigo del {STR_VAR_3} de {STR_VAR_2}.\p"
	.string	"Es incluso posible que haya\n"
	.string	"recibido una CARTA.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string	"If you want to pick up your POK??MON,\n"
	.string	"have a word with my wife.$"

Route117_Text_YourMonsAreDoingFine:
	.string	"??Ah, eres t??! Tu {STR_VAR_1} y el\n"
	.string	"{STR_VAR_2} est??n muy bien.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string	"Yo me lo quedar??a.\n"
	.string	"Pero imagino que lo quieres.$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string	"Soy la ENCARGADA de la GUARDER??A.\p"
	.string	"Podemos ocuparnos de tus POK??MON.\p"
	.string	"??Quieres que cuidemos de alguno?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string	"??Qu?? POK??MON quieres que cuidemos?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string	"Estupendo, nos ocuparemos de tu\n"
	.string	"{STR_VAR_1} cuanto sea necesario.\p"
	.string	"Vuelve cuando quieras.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string	"Podemos cuidar a dos de tus POK??MON.\n"
	.string	"??Quieres que cuidemos de otro m??s?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string	"Mi marido te estaba buscando.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string	"Muy bien.\n"
	.string	"Vuelve cuando quieras.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string	"No tienes bastante dinero.$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string	"??Quieres llevarte el otro tambi??n?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string	"Muy bien.\n"
	.string	"Vuelve cuando quieras.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string	"??Ah, eres t??! Me alegro de verte.\n"
	.string	"Y t?? te alegrar??s de saber esto???$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string	"Tu {STR_VAR_1} ha crecido\n"
	.string	"estos niveles: ??{STR_VAR_2}!$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string	"Tu equipo POK??MON est?? lleno.\n"
	.string	"Haz un hueco y vuelve a verme.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string	"Which POK??MON will you take back?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string	"Si quieres llevarte a tu {STR_VAR_1},\n"
	.string	"tendr??s que pagar {STR_VAR_2}??.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string	"??Perfecto!\n"
	.string	"Aqu?? tienes a tu POK??MON.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string	"{PLAYER} recogi?? a {STR_VAR_1} de\n"
	.string	"la GUARDER??A POK??MON.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string	"Anda, pero si s??lo tienes un POK??MON???\p"
	.string	"Vuelve cuando tengas alguno m??s.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string	"??Quieres recoger un POK??MON?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string	"Si me dejas ese POK??MON,\n"
	.string	"no podr??s entablar combates.\p"
	.string	"Vuelve en otra ocasi??n.$"

Text_EggHatchHuh:
	.string	"??Y esto?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string	"??Eh?\n"
	.string	"A ver, a ver.\p"
	.string	"Si me dejas ese POK??MON aqu??, \n"
	.string	"s??lo te quedar??s con uno en forma.\p"
	.string	"Ser?? mejor que atrapes alguno m??s,\n"
	.string	"vamos, digo yo.$"
