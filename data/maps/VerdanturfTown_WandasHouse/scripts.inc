VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string	"BLASCO: Me has vencido, {PLAYER}, pero\n"
	.string	"ahora eso me importa un comino???\p"
	.string	"Porque tengo un nuevo objetivo\n"
	.string	"en la vida. Junto a mi RALTS,\l"
	.string	"voy a desafiar a los GIMNASIOS POK??MON\l"
	.string	"y convertirme en un gran ENTRENADOR.\p"
	.string	"No me pierdas de vista, {PLAYER}.\n"
	.string	"Voy a ser m??s fuerte que t??.\p"
	.string	"Y, cuando lo sea, te voy a desafiar\n"
	.string	"a otro combate???$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string	"BLASCO: Obs??rvame bien, {PLAYER}.\n"
	.string	"Voy a ser m??s fuerte que t??.\p"
	.string	"Y, cuando lo sea, te voy a desafiar\n"
	.string	"a otro combate???$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string	"T??O: ??Ey, {PLAYER}{KUN}!\n"
	.string	"BLASCO est?? al lado.\p"
	.string	"Pero primero quiero contarte\n"
	.string	"una cosa???\p"
	.string	"Este entorno natural est?? sentando\n"
	.string	"a BLASCO de maravilla.\p"
	.string	"Quiz??s no sea s??lo el entorno.\n"
	.string	"Los POK??MON tambi??n tendr??n que ver???$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string	"BLASCO se ha ido???\n"
	.string	"Se ha marchado sin decir ni mu???$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string	"T??O: ??Es cierto que BLASCO\n"
	.string	"se ha ido tan lejos ??l solito?\p"
	.string	"Bueno, no deber??a extra??arme:\n"
	.string	"??es el hijo de mi hermano!$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string	"CLARA: ??T?? eras????\n"
	.string	"Ah, s??, ya s??.\p"
	.string	"Eres {PLAYER}. BLASCO siempre est??\n"
	.string	"hablando de ti.\p"
	.string	"Soy la prima de BLASCO.\n"
	.string	"??Es un placer!\p"
	.string	"Creo que a BLASCO se le ve mucho\n"
	.string	"m??s sano y animado desde que est?? aqu??.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string	"CLARA: No te preocupes por BLASCO.\n"
	.string	"Sabe cuidarse ??l solo.\p"
	.string	"Conozco a mi primo y adem??s\n"
	.string	"no est?? solo: tiene a sus POK??MON.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string	"Gracias a ti, puedo ver a mi novia\n"
	.string	"cada d??a. ??Que si estoy contento?\l"
	.string	"??Acaso no se ve? Je, je, je???$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string	"El novio de mi hija es de lo m??s\n"
	.string	"lanzado y apasionado.\p"
	.string	"Ha estado cavando el t??nel\n"
	.string	"sin parar s??lo para poder verla.\p"
	.string	"Mi hija est?? un poco preocupada,\n"
	.string	"por eso va al t??nel cada dos por tres.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string	"Es asombroso. ??El novio de mi hija\n"
	.string	"ha estado cavando el t??nel a mano!\p"
	.string	"??No me lo puedo creer!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string	"Si algo le pasara a BLASCO, nunca\n"
	.string	"podr??a volver a mirar a sus padres\l"
	.string	"a la cara, cuando volviera a PETALIA???$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string	"??BLASCO ha estado en COLOSALIA?\p"
	.string	"??Sus padres, que viven en PETALIA,\n"
	.string	"estar??an at??nitos si lo supieran!$"

