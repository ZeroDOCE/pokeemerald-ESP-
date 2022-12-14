SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string	"Ejem, ejem??? ??Soy el PRESIDENTE\n"
	.string	"del CLUB de FANS de POK??MON!\p"
	.string	"Naturalmente, el PRESIDENTE\n"
	.string	"es la persona m??s importante???\p"
	.string	"Nadie me iguala entrenando POK??MON.\n"
	.string	"??Nadie!\p"
	.string	"Bueno, te voy a explicar qu?? son\n"
	.string	"los CONCURSOS POK??MON.\p"
	.string	"??Son competiciones donde puedes\n"
	.string	"mostrar tus POK??MON al mundo mundial!\p"
	.string	"Pero siempre tienen lugar en el quinto\n"
	.string	"pino, as?? que no puedo participar mucho.\p"
	.string	"Por eso nos reunimos aqu??, para\n"
	.string	"que todo el mundo pueda fardar\l"
	.string	"de POK??MON, aunque sea un poco.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string	"Ya me gustar??a ver al POK??MON de alg??n\n"
	.string	"ENTRENADOR que haya participado\l"
	.string	"en alg??n CONCURSO POK??MON???$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string	"Ejem, ejem??? ??Ya veo que has\n"
	.string	"participado en un CONCURSO POK??MON!\p"
	.string	"Estoy deseando ver c??mo\n"
	.string	"has criado a tu POK??MON.\p"
	.string	"Es maravilloso ver c??mo los dem??s\n"
	.string	"ENTRENADORES cuidan a sus POK??MON.\p"
	.string	"Me encantan las caras satisfechas\n"
	.string	"de los POK??MON bien entrenados???\p"
	.string	"Y las cari??osas miradas de sus\n"
	.string	"orgullosos ENTRENADORES???\p"
	.string	"Ay, ver tanta felicidad me llena\n"
	.string	"de gozo???\p"
	.string	"??Oh, pero disc??lpame, empiezo\n"
	.string	"a hablar y no paro!\p"
	.string	"Te lo ruego, perm??teme examinar tu\n"
	.string	"POK??MON, a ver cu??nto ha crecido.$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string	"??Qu?? tal est?? creciendo tu\n"
	.string	"POK??MON? D??jame examinarlo???$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string	"Aj????? Muy bien???\n"
	.string	"Ya veo???$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string	"Mmmm??? No est?? mal, pero\n"
	.string	"tampoco est?? bien???\p"
	.string	"??T??, que entrenas POK??MON,\n"
	.string	"deber??as esforzarte m??s con ??ste!\p"
	.string	"Una sugerencia??? ??Por qu?? no\n"
	.string	"le das m??s {POKEBLOCK}S?$"
	
SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string	"Vaya, vaya???\p"
	.string	"Tu POK??MON est?? creciendo\n"
	.string	"muy bien. ??Te mereces un premio!\p"
	.string	"L??stima que no tengas sitio\n"
	.string	"en la MOCHILA???$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string	"??Tu {STR_VAR_1} est?? creciendo\n"
	.string	"a un ritmo impresionante!\l"
	.string	"??Qu?? magn??fico ejemplar!\p"
	.string	"Pero, si le das esto, crecer??\n"
	.string	"a??n mejor. ??Te lo digo yo!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string	"Dale el PA??UELO ROJO a un POK??MON.\p"
	.string	"??As?? todo el mundo podr?? ver\n"
	.string	"lo carism??tico que es!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string	"Dale el PA??UELO AZUL a un POK??MON.\p"
	.string	"??De esta manera conseguir??s realzar\n"
	.string	"su belleza a??n m??s!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string	"Dale el PA??UELO ROSA a un POK??MON.\p"
	.string	"??Con ??l lograr??s que parezca a??n\n"
	.string	"m??s dulce de lo que ya es!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string	"Dale el PA??UELO VERDE a un POK??MON.\p"
	.string	"??Potenciar?? su ingenio!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string	"Dale el PA??UELO AMARILLO a un POK??MON.\p"
	.string	"??Le har?? ser mucho m??s duro\n"
	.string	"de lo que es ahora!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string	"Lo siento, pero no me queda nada\n"
	.string	"m??s que darte??? ??Nada de nada!\p"
	.string	"Despu??s de todo, tienes el don de\n"
	.string	"saber entrenar POK??MON sin recurrir\l"
	.string	"continuamente a objetos, ??no?$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string	"Me encanta ver POK??MON que\n"
	.string	"quieren a sus ENTRENADORES.\p"
	.string	"Los POK??MON son muy sensibles a los\n"
	.string	"sentimientos de sus ENTRENADORES.\p"
	.string	"Si tratas a tus POK??MON con amor\n"
	.string	"y cari??o, te corresponder??n.\p"
	.string	"Cuando tus POK??MON te quieran\n"
	.string	"un poco m??s, vuelve a verme.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string	"Tu POK??MON te adora.\p"
	.string	"??Como has demostrado tener un gran\n"
	.string	"coraz??n, el CLUB de FANS te regala esto!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string	"Los POK??MON son muy sensibles a los\n"
	.string	"sentimientos de los ENTRENADORES.\p"
	.string	"Si tratas a tus POK??MON con amor\n"
	.string	"y cari??o, te corresponder??n.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string	"Si continuamente dejas que tus POK??MON\n"
	.string	"caigan debilitados durante un combate,\l"
	.string	"acabar??n por resentirse de esto.\p"
	.string	"Muy pronto empezar??n a perder\n"
	.string	"confianza en su ENTRENADOR.\p"
	.string	"En otras palabras, terminar??s\n"
	.string	"por no gustarles ni un pelo.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string	"??A los POK??MON les gusta\n"
	.string	"que se les d?? objetos?\p"
	.string	"No s??, los m??os se pusieron muy\n"
	.string	"contentos cuando les di PROTE??NA.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string	"SKITTY: Skitiiiiii???$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string	"ZIGZAGOON: Zigzaaaa???$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string	"AZUMARILL: ??Marimari?$"

