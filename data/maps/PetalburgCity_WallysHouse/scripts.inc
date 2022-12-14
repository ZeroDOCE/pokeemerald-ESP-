.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHM03Surf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHM03Surf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM03
	setflag FLAG_RECEIVED_HM03
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string	"T?? eres???\n"
	.string	"S??, t?? eres {PLAYER}{KUN}, ??verdad?\p"
	.string	"Gracias por jugar con BLASCO\n"
	.string	"hace un rato.\p"
	.string	"El pobrecito siempre ha sido\n"
	.string	"un chico enfermizo.\p"
	.string	"Lo hemos enviado con unos parientes\n"
	.string	"que viven en PUEBLO VERDEGAL.\p"
	.string	"All?? el aire est?? mucho m??s limpio\n"
	.string	"y es m??s sano que aqu??.\p"
	.string	"??C??mo? ??Que d??nde est?? BLASCO?\n"
	.string	"??Ya se ha ido!\p"
	.string	"Me pregunto d??nde estar??\n"
	.string	"en estos momentos???$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string	"Me pregunto c??mo le ir?? a BLASCO???$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string	"??Hola, {PLAYER}{KUN}! Espero que no\n"
	.string	"te moleste haber venido hasta aqu??.\p"
	.string	"Nuestro BLASCO se ha curado\n"
	.string	"del todo mientras estaba\l"
	.string	"en PUEBLO VERDEGAL.\p"
	.string	"??Y todo gracias a ti!\p"
	.string	"Cuando BLASCO se fue, le ayudaste\n"
	.string	"a atrapar un POK??MON, ??verdad?\p"
	.string	"Creo que eso le hizo muy feliz.\p"
	.string	"Y tambi??n me hizo muy feliz\n"
	.string	"a m??, su padre.\p"
	.string	"Es estupendo que BLASCO\n"
	.string	"tenga amigos tan buenos como t??.\p"
	.string	"Estoy tan contento que quiero\n"
	.string	"darte esto como agradecimiento.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string	"Si tu POK??MON puede hacer SURF,\n"
	.string	"podr??s ir a cantidad de sitios.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string	"BLASCO pronto volver?? a casa.\n"
	.string	"Qu?? ganas tengo???$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string	"??Ah, s??? ??Te has encontrado con\n"
	.string	"BLASCO en CIUDAD COLOSALIA?\p"
	.string	"Venga, {PLAYER}{KUN}, no digas\n"
	.string	"tonter??as.\p"
	.string	"Puede que est?? m??s fuerte que\n"
	.string	"antes, pero no puede haber ido\l"
	.string	"tan lejos ??l solo???$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string	"BLASCO estaba content??simo\n"
	.string	"cuando nos dijo que hab??a atrapado\l"
	.string	"un POK??MON.\p"
	.string	"Hac??a siglos que no lo hab??a visto\n"
	.string	"sonre??r as?????$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string	"Quiero contarte algo, pero no\n"
	.string	"se lo digas a mi marido???\p"
	.string	"BLASCO se fue de PUEBLO VERDEGAL\n"
	.string	"sin decir nada a nadie.\p"
	.string	"BLASCO es d??bil, pero tiene una gran\n"
	.string	"fuerza de voluntad.\p"
	.string	"Estoy convencida de que volver??\n"
	.string	"muy pronto hecho un hombret??n.$"

