@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string	"Este POK??MON ya ha ganado\n"
	.string	"el CONCURSO de BELLEZA???\p"
	.string	"??Y sabes qu??? ??Hoy ha ganado\n"
	.string	"el CONCURSO de INGENIO!\p"
	.string	"Soy tan bueno que no me lo creo???$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string	"He entrado en un mont??n de CONCURSOS\n"
	.string	"para ver c??mo funciona este tinglado.\p"
	.string	"Si est??s en un CONCURSO de CARISMA,\n"
	.string	"usa movimientos carism??ticos para\l"
	.string	"ganar m??s puntos.\p"
	.string	"Vamos, que los movimientos ingeniosos\n"
	.string	"o dulces no servir??n de gran cosa???$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string	"Ese jovencito que gan?? antes ten??a\n"
	.string	"un buen mont??n de {POKEBLOCK}S diferentes.\p"
	.string	"??Crees que usando muchas cosas\n"
	.string	"de ??sas resulta m??s f??cil ganar?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string	"Guau??? Este sitio es gigantesco???\p"
	.string	"Se respira tanta tensi??n??? No es en\n"
	.string	"absoluto como esas SALAS de CONCURSO\l"
	.string	"perdidas en medio de la nada???$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string	"PRESENTADORA: Muy bien. POK??MON\n"
	.string	"ingeniosos y ENTRENADORES\l"
	.string	"respectivos, ??est??is listos?\p"
	.string	"??Dad lo mejor de vosotros!\n"
	.string	"??A exhibirse!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string	"JUEZ: ??Te est?? gustando el CONCURSO?\p"
	.string	"Vuelve con tres amigos m??s y todos\n"
	.string	"podr??is participar en uno.$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string	"Ay, ay, ay, ay???\n"
	.string	"??Me he equivocado de CONCURSO!\p"
	.string	"He apuntado a un POK??MON duro\n"
	.string	"a un CONCURSO de INGENIO???\p"
	.string	"??Venga, d??jalos patidifusos\n"
	.string	"con un ingenioso GOLPE ROCA!$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string	"Durante a??os he aplicado todos\n"
	.string	"mis conocimientos para entrenar\l"
	.string	"un POK??MON ingenioso como ??l solo.\p"
	.string	"Dudo mucho que los POK??MON\n"
	.string	"de unos renacuajos puedan superarlo???\p"
	.string	"Cari??o, ??ves todo bien desde ah???$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string	"??Toma ya!\p"
	.string	"??Si mi POK??MON hace alarde\n"
	.string	"de un movimiento ingenioso ahora,\l"
	.string	"el p??blico se va a volver loco!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string	"??Oh, no!\p"
	.string	"El CHUPAVIDAS de mi querido ZUBAT\n"
	.string	"es tan guay que lo he usado varias\l"
	.string	"veces seguidas???\p"
	.string	"??Pero estos cabezas de chorlito no\n"
	.string	"han sabido apreciarlo en absoluto!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string	"??Adelante! ??Amorcito, eres el mejor!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string	"Aun cuando los ENTRENADORES apuntan\n"
	.string	"al mismo tipo de POK??MON, cada uno\l"
	.string	"se exhibe con un movimiento distinto.\p"
	.string	"Porque, claro, ??todo el mundo\n"
	.string	"tiene su propio estilo de lucha!$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string	"Creo que esos POK??MON parecen mucho\n"
	.string	"m??s ingeniosos que sus ENTRENADORES.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string	"Por mucho que venga, estos CONCURSOS\n"
	.string	"de INGENIO me siguen encantando.\p"
	.string	"Ese color verde es tan??? agudo???\n"
	.string	"Es tan, tan??? intelectual???$"
	
LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string	"PRESENTADORA: ??T?? tambi??n participas\n"
	.string	"en el CONCURSO de BELLEZA?\l"
	.string	"??Pues suerte!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string	"JUEZ: Todos los POK??MON que hay aqu??\n"
	.string	"son un modelo de perfecta belleza.\p"
	.string	"??Huy, en vez de admirarlos tanto,\n"
	.string	"deber??a darles una puntuaci??n!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string	"Este POK??MON es de una BELLEZA\n"
	.string	"sin igual??? No tiene rival.\p"
	.string	"Sin duda el p??blico se quedar??\n"
	.string	"admirado al verlo.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string	"??Aaaaah!\p"
	.string	"He peinado y arreglado a mi POK??MON\n"
	.string	"especialmente para el CONCURSO???\p"
	.string	"Pero me he pasado???\n"
	.string	"Y ahora su bonito pelo est?? todo tieso???\p"
	.string	"????Qu?? puedo hacer?!$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string	"Este RAYO AURORA es deslumbrante.\n"
	.string	"El JUEZ no podr?? ni verlo.\p"
	.string	"Eh, un momento???\n"
	.string	"??Entonces no servir?? de nada!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string	"Este bonito POK??MON se parece\n"
	.string	"a m?? cuando era joven, clavadito.\p"
	.string	"Pues, cuando se lo dije a mi marido,\n"
	.string	"no pudo aguantarse la risa.\p"
	.string	"Y, digo yo, ??d??nde est?? la gracia?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string	"Yo creo que a cualquiera le hace\n"
	.string	"ilusi??n ganar un CONCURSO\l"
	.string	"de BELLEZA, ??o no?$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string	"??Ja, ja, ja!\p"
	.string	"??Mira bien todos esos POK??MON!\n"
	.string	"??Son tan bonitos que deslumbran!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string	"La belleza natural no basta.\p"
	.string	"Hay que potenciarla un poco para\n"
	.string	"conseguir una imagen tan estupenda\l"
	.string	"como la de mi POK??MON.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string	"PRESENTADORA: ??Huy, hola!\n"
	.string	"??Estamos en mitad de un CONCURSO!\p"
	.string	"Ve a registrarte primero si quieres\n"
	.string	"participar, ??vale?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string	"JUEZ: ??Nunca hab??a visto exhibiciones\n"
	.string	"tan dulces y encantadoras como ??stas!\p"
	.string	"Por ejemplo, ese HIDROCHORRO tan\n"
	.string	"adorable merece una gran puntuaci??n.$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string	"Oh, no, un POK??MON ha distra??do\n"
	.string	"a mi dulce AZURILL???$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string	"Mi POK??MON nunca ha vencido luchando,\n"
	.string	"??pero ya ver??s como gana el CONCURSO!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string	"La DANZA P??TALO de mi POK??MON\n"
	.string	"es un prodigio de elegancia.\p"
	.string	"No dejar?? que nadie le moleste\n"
	.string	"durante su actuaci??n.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string	"Todo el mundo piensa que su POK??MON\n"
	.string	"es el m??s dulce de todos.\p"
	.string	"Pero yo s?? que, cuando el m??o haga\n"
	.string	"una exhibici??n de DULZURA???,\p"
	.string	"??se llevar?? la palma!$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string	"Mi hijo est?? participando\n"
	.string	"en el CONCURSO.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string	"??Adelante, cari??o!\n"
	.string	"??Tu POK??MON es el mejor!$"
	
LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string	"Creo que esa chica de ah??\n"
	.string	"es la m??s dulce de toda la sala.\p"
	.string	"??C??mo? ??Que compiten los POK??MON,\n"
	.string	"no sus ENTRENADORES?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string	"Oooooh, al ver a esos POK??MON tan\n"
	.string	"dulces, me entran ganas de tener uno???\p"
	.string	"??Me voy a atrapar unos cuantos!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string	"ESCENARIO del CONCURSO de BELLEZA\n"
	.string	"??LOS POK??MON M??S GUAPOS!$"
	
LilycoveCity_ContestHall_Text_CuteContestStage:
	.string	"ESCENARIO del CONCURSO de DULZURA\n"
	.string	"??LOS POK??MON M??S ACHUCHABLES!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string	"ESCENARIO del CONCURSO de INGENIO\n"
	.string	"??LOS POK??MON M??S LISTOS!$"

