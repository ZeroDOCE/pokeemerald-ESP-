BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string	"??Eh, qu?? tal! Si quieres saber algo sobre\n"
	.string	"el FRENTE de BATALLA, yo soy tu hombre.\p"
	.string	"Se puede decir que soy\n"
	.string	"el FOROFO del FRENTE.\p"
	.string	"S??lo para asegurarme,\n"
	.string	"t?? entrenas POK??MON, ??verdad?\p"
	.string	"Pues estar?? encantado de contarte las\n"
	.string	"??ltimas noticias del FRENTE de BATALLA.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string	"??Qu?? tal? ??Has venido a preguntarme\n"
	.string	"qu?? es lo que m??s est?? de moda?$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string	"D??jame pensar???\p"
	.string	"Yo dir??a que???, s??,\n"
	.string	"{STR_VAR_1}, sin duda.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string	"D??jame pensar???\p"
	.string	"Creo que {STR_VAR_1},\n"
	.string	"de TORRE BATALLA, es lo que m??s mola.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string	"??Seguro que no lo sab??as!\p"
	.string	"All?? hay una ENTRENADORA de esas\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es la misteriosa DAMA de la TORRE,\n"
	.string	"y es la que hace y deshace por all??.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la DAMA de la TORRE?\p"
	.string	"Para medir las fuerzas de su adversario,\n"
	.string	"suele usar estos POK??MON:\p"
	.string	"Un POK??MON PSI de tipo PS??QUICO,\n"
	.string	"un POK??MON VOLC??N de tipo FUEGO\l"
	.string	"y un POK??MON DORMIR de tipo NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la DAMA de la TORRE en serio?\p"
	.string	"Cuando pone toda la carne en el asador,\n"
	.string	"parece que usa estos POK??MON:\p"
	.string	"Un POK??MON E??N de tipo PS??QUICO y\n"
	.string	"DRAG??N, un POK??MON TRUENO de tipo\l"
	.string	"EL??CTRICO y un POK??MON DORMIR\l"
	.string	"de tipo NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string	"??Seguro que no lo sab??as!\p"
	.string	"All?? hay un ENTRENADOR de esos\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es el extravagante ASTRO de la C??PULA\n"
	.string	"y es el jefe de all??, vaya.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al ASTRO de la C??PULA?\p"
	.string	"Cuando no quiere cebarse con el rival,\n"
	.string	"suele usar estos tres POK??MON:\p"
	.string	"Un POK??MON DRAG??N de tipo DRAG??N\n"
	.string	"y VOLADOR, un POK??MON PEZ LODO\l"
	.string	"de tipo AGUA y TIERRA, y un POK??MON\l"
	.string	"LLAMA de tipo FUEGO y VOLADOR.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al ASTRO de la C??PULA en serio?\p"
	.string	"Cuando quiere demostrar lo que sabe,\n"
	.string	"suele usar estos tres POK??MON:\p"
	.string	"Un POK??MON E??N de tipo DRAG??N y\n"
	.string	"PS??QUICO, un POK??MON PEZ LODO de tipo\l"
	.string	"AGUA y TIERRA, y un POK??MON PATA\l"
	.string	"HIERRO de tipo ACERO y PS??QUICO.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string	"??Apuesto a que no lo sab??as!\p"
	.string	"All?? hay un ENTRENADOR de esos\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es un tipo un poco raro, pero la cosa\n"
	.string	"es que es el JEFE de la F??BRICA.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al JEFE de la F??BRICA?\p"
	.string	"Si mal no recuerdo, en combate\n"
	.string	"suele alquilar s??lo tres POK??MON:\p"
	.string	"Suele luchar en igualdad\n"
	.string	"de condiciones contra su rival.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al JEFE de la F??BRICA en serio?\p"
	.string	"Aunque el combate vaya en serio,\n"
	.string	"sigue alquilando s??lo tres POK??MON:\p"
	.string	"Siempre lucha en igualdad\n"
	.string	"de condiciones contra su rival.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string	"??Apuesto a que no lo sab??as!\p"
	.string	"All?? hay una ENTRENADORA de esas\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Da un miedo terrible,\n"
	.string	"??es la REINA de la SIERPE!$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la REINA de la SIERPE?\p"
	.string	"Cuando est?? de buenas, suele\n"
	.string	"usar estos tres POK??MON:\p"
	.string	"Un POK??MON COLMILLOS de tipo VENENO,\n"
	.string	"un POK??MON MOHO de tipo BICHO y ROCA,\l"
	.string	"y un POK??MON TIERNO de tipo AGUA.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la REINA de la SIERPE en serio?\p"
	.string	"Cuando est?? furiosa de verdad,\n"
	.string	"suele usar estos tres POK??MON:\p"
	.string	"Un POK??MON COLMILLOS de tipo VENENO,\n"
	.string	"un POK??MON SERPF??RREA de tipo ACERO\l"
	.string	"y TIERRA, y un POK??MON ATROCIDAD\l"
	.string	"de tipo AGUA y VOLADOR.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string	"??Apuesto a que no lo sab??as!\p"
	.string	"All?? hay una ENTRENADORA de esas\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es una belleza, es la MAESTRA del DOJO.\n"
	.string	"Parece que es quien manda all??.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la MAESTRA del DOJO?\p"
	.string	"Cuando est?? calibrando las fuerzas del\n"
	.string	"enemigo, suele usar estos tres POK??MON:\p"
	.string	"Un POK??MON UNICORNIO de tipo BICHO\n"
	.string	"y LUCHA, un POK??MON LUZ LUNAR\l"
	.string	"de tipo SINIESTRO y un POK??MON MUDA\l"
	.string	"de tipo BICHO y FANTASMA.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"a la MAESTRA del DOJO en serio?\p"
	.string	"Cuando da el todo por el todo,\n"
	.string	"suele usar estos tres POK??MON:\p"
	.string	"Un POK??MON LUZ LUNAR de tipo\n"
	.string	"SINIESTRO, un POK??MON SOMBRA de tipo\l"
	.string	"FANTASMA y VENENO, y un POK??MON\l"
	.string	"HONGO de tipo PLANTA y LUCHA.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string	"??Apuesto a que no lo sab??as!\p"
	.string	"All?? hay un ENTRENADOR de esos\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es un ENTRENADOR siniestro llamado\n"
	.string	"AMO del PALACIO, y es el que manda all??.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al AMO del PALACIO?\p"
	.string	"Cuando quiere poner a prueba al rival,\n"
	.string	"dicen que suele usar estos POK??MON:\p"
	.string	"Un POK??MON MURCI??LAGO de tipo VENENO\n"
	.string	"y VOLADOR, un POK??MON HOLGAZ??N de\l"
	.string	"tipo NORMAL y un POK??MON TRANSPORTE\l"
	.string	"de tipo AGUA y HIELO.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al AMO del PALACIO en serio?\p"
	.string	"Cuando se la juega de verdad,\n"
	.string	"dicen que usa estos POK??MON:\p"
	.string	"Un POK??MON LEGENDARIO de tipo FUEGO,\n"
	.string	"un POK??MON HOLGAZ??N de tipo NORMAL\l"
	.string	"y un POK??MON AURORA de tipo AGUA.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string	"??Apuesto a que no lo sab??as!\p"
	.string	"All?? hay un ENTRENADOR de esos\n"
	.string	"que TRETO denomina AS del FRENTE.\p"
	.string	"Es el feroz ENTRENADOR al que llaman\n"
	.string	"REY de la PIR??MIDE,\l"
	.string	"y all?? es como el due??o.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al REY de la PIR??MIDE?\p"
	.string	"Cuando quiere probar al enemigo,\n"
	.string	"usa siempre estos POK??MON:\p"
	.string	"Un POK??MON PICO ROCA de tipo ROCA,\n"
	.string	"un POK??MON ICEBERG de tipo HIELO\l"
	.string	"y un POK??MON HIERRO de tipo ACERO.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string	"??Te has enfrentado alguna vez\n"
	.string	"al REY de la PIR??MIDE en serio?\p"
	.string	"Cuando no se anda con chiquitas,\n"
	.string	"usa siempre estos POK??MON:\p"
	.string	"Un POK??MON CONGELAR de tipo HIELO\n"
	.string	"y VOLADOR, un POK??MON EL??CTRICO\l"
	.string	"de tipo EL??CTRICO y VOLADOR, y un\l"
	.string	"POK??MON LLAMA de tipo FUEGO y VOLADOR.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string	"Claro, hay varios sitios donde puedes\n"
	.string	"enfrentarte en COMBATES DOBLES.\p"
	.string	"Pero digamos que lo b??sico son las\n"
	.string	"SALAS BATALLA de COMBATES DOBLES\l"
	.string	"de la TORRE BATALLA.\p"
	.string	"Es donde se aprende de verdad\n"
	.string	"a entablar COMBATES DOBLES\l"
	.string	"en el FRENTE de BATALLA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string	"Ten cuidado en los combates de aqu??.\p"
	.string	"He o??do que hay ENTRENADORES\n"
	.string	"que han creado estrategias s??lo\l"
	.string	"para los COMBATES DOBLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string	"Cuando creas que dominas los COMBATES\n"
	.string	"DOBLES de aqu??, podr??s pensar en ir\l"
	.string	"a otros lugares donde tambi??n haya.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string	"En el SAL??N BATALLA se juntan\n"
	.string	"todo tipo de ENTRENADORES.\p"
	.string	"??Pi??nsalo, igual hasta te encuentras\n"
	.string	"con tus amigos o con tus seguidores!\l"
	.string	"??Busca y seguro que encuentras!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string	"Si est??s con un amigo, ve a la\n"
	.string	"SALA BATALLA de COMBATES\l"
	.string	"MULTIJUGADOR con CONEXI??N.\p"
	.string	"??Si tu amigo es muy fuerte, prep??rate\n"
	.string	"para enfrentarte a enemigos muy duros!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string	"??Qu?? extraordinario poder adivinatorio!\n"
	.string	"??Nadie puede compararse a mi mentor!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string	"??Qu?? magn??fico poder de observaci??n!\n"
	.string	"??Nadie puede compararse a mi mentor!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string	"??Qu?? incre??ble poder de persuasi??n!\n"
	.string	"??Nadie puede compararse a mi mentor!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string	"??Qu?? sitio m??s raro!???\n"
	.string	"Me da hasta miedo???$"

