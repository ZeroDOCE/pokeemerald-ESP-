SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string	"??Je, je! ??Hola! ??Soy el INSPECTOR\n"
	.string	"de los MOTES! ??El adivinador de nombres!\p"
	.string	"Estar?? encantado de evaluar\n"
	.string	"el nombre de tu POK??MON, je, je.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string	"??Qu?? nombre de POK??MON\n"
	.string	"quieres que adivine y eval??e?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string	"Mmmmm??? {STR_VAR_1}, ??a que s???\n"
	.string	"No est?? mal, no est?? mal???\p"
	.string	"Pero ??no crees que podr??amos\n"
	.string	"encontrar un nombre a??n mejor?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string	"As?? me gusta. A ver???\n"
	.string	"??Cu??l ser?? el nuevo nombre?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string	"??Ya est??! ??A partir de ahora, el nombre\n"
	.string	"de este POK??MON ser?? {STR_VAR_1}!\p"
	.string	"Es un nombre mucho mejor que\n"
	.string	"el anterior, ??qu?? suerte tienes!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string	"Entiendo???\n"
	.string	"Entonces vuelve cuando quieras.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string	"??Ya est??! ??A partir de ahora, el nombre\n"
	.string	"de este POK??MON ser?? {STR_VAR_1}!\p"
	.string	"No parece muy diferente del anterior\n"
	.string	"y, sin embargo, es much??simo mejor.\l"
	.string	"??Qu?? suerte tienes!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string	"Mmmm??? ??Ser?? {STR_VAR_1}!\p"
	.string	"??He aqu?? un mote magn??fico!\n"
	.string	"??Absolutamente irreprochable!\p"
	.string	"Har??s bien en querer mucho\n"
	.string	"a tu {STR_VAR_1} de ahora en adelante.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string	"Pero vamos a ver???\n"
	.string	"??Esto es s??lo un HUEVO!$"

