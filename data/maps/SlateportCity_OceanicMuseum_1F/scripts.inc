.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM46
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string	"Hola. ??ste es el MUSEO OCE??NICO.\p"
	.string	"La entrada cuesta 50??.\n"
	.string	"??Quieres entrar?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string	"Disfruta de la visita.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string	"Vaya, lo siento, pero parece que\n"
	.string	"no tienes bastante dinero???$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string	"??Ah, s??? ??Vienes con el grupo\n"
	.string	"que entr?? justo antes?\p"
	.string	"??Pues llegas tarde!\n"
	.string	"??Date prisa para alcanzarles!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string	"??Nosotros, el EQUIPO AQUA, existimos\n"
	.string	"por el bien de la humanidad!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string	"Nos dijeron que vini??ramos aqu??\n"
	.string	"y eso hemos hecho, pero???\p"
	.string	"Nuestro JEFE no est?? y sin ??l\n"
	.string	"no somos nada.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string	"Si birlara todas las cosas\n"
	.string	"que hay aqu??, ??me har??a rico?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string	"Todo lo que aprenda aqu?? puedo\n"
	.string	"aplicarlo con fines malvados???$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string	"??Si nuestro mat??n no la hubiera\n"
	.string	"pifiado en CIUDAD F??RRICA,\l"
	.string	"no tendr??amos que estar aqu??!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string	"Yo no ten??a 50??, as?? que tuve que\n"
	.string	"burlar a la recepcionista para entrar.\l"
	.string	"??No fue nada f??cil!$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string	"Quiero aprender todo lo que pueda\n"
	.string	"sobre el mar y aplicarlo al combate.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string	"Me entra un mareo horrible\n"
	.string	"cada vez que veo el mar???\p"
	.string	"??Ojal?? pudiera ser tan valiente\n"
	.string	"como el CAP. BABOR!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string	"El mar es tan, tan grande y tan,\n"
	.string	"tan profundo???\p"
	.string	"Seguro que hay muchos POK??MON\n"
	.string	"de los que nunca hemos o??do hablar.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string	"Quiero un POK??MON marino.\p"
	.string	"Abrazarlo resultar??a tan\n"
	.string	"fresquito y agradable???$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string	"??Aaaaah!\n"
	.string	"??Qu?? haces aqu???\p"
	.string	"??Yo? Soy el miembro del EQUIPO\n"
	.string	"AQUA al que diste una paliza en el\l"
	.string	"T??NEL FERVERGAL, ??recuerdas?\p"
	.string	"??Hala, toma!\n"
	.string	"??Y espero que me perdones!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string	"Esa MT va m??s contigo que\n"
	.string	"conmigo.\p"
	.string	"??Hasta nunca, espero!\n"
	.string	"??Jua, ja, ja, ja!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string	"??Encima esto!\n"
	.string	"??Toma esto y deja que me largue!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string	"Un l??quido azul fluye en espiral dentro\n"
	.string	"de un recipiente de cristal.\p"
	.string	"?????ste es un experimento que se sirve\n"
	.string	"de la fuerza del viento para recrear\l"
	.string	"un TORBELLINO.???$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string	"Una bola roja sube y baja dentro\n"
	.string	"de un recipiente de cristal.\p"
	.string	"?????ste es un experimento que se sirve\n"
	.string	"del principio de la flotabilidad para\l"
	.string	"simular una CASCADA.???$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string	"Se trata de una muestra de tierra\n"
	.string	"del fondo oce??nico.\p"
	.string	"???A lo largo de miles de a??os, los\n"
	.string	"restos org??nicos se van depositando\l"
	.string	"en el fondo del mar y crean capas.\p"
	.string	"Mediante el an??lisis de estas capas\n"
	.string	"sedimentarias, se puede aprender mucho\l"
	.string	"sobre el pasado m??s remoto.???$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string	"Se trata de una muestra de arena\n"
	.string	"de playa.\p"
	.string	"???El agua de los r??os erosiona las rocas\n"
	.string	"de las monta??as, las fragmenta y las\l"
	.string	"entierra en el lecho de los mismos.\p"
	.string	"Son reducidas a gravilla por la fricci??n\n"
	.string	"del agua y acaban deposit??ndose\l"
	.string	"en las playas.???$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string	"MINI-INFO OCE??NICA 1\n"
	.string	"??Por qu?? el agua del mar es azul?\p"
	.string	"???La luz se compone de muchos colores.\p"
	.string	"Cuando la luz atraviesa el agua,\n"
	.string	"la mayor??a de estos colores son\l"
	.string	"absorbidos, sobre todo los rojos.\p"
	.string	"La luz azul se dispersa m??s f??cilmente,\n"
	.string	"por eso el mar tiene ese color.???$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string	"MINI-INFO OCE??NICA 2\n"
	.string	"??Por qu?? el mar es salado?\p"
	.string	"???El agua del mar contiene sal disuelta\n"
	.string	"bajo forma de iones de sodio y cloruro.\p"
	.string	"Estos iones se separan de las rocas y\n"
	.string	"llegan al mar por la acci??n de la lluvia.\p"
	.string	"La alta concentraci??n de sal disuelta\n"
	.string	"hace que el mar sea salado.???$"
	
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string	"MINI-INFO OCE??NICA 3\n"
	.string	"??Qu?? es mayor? ??La tierra o el mar?\p"
	.string	"???El mar cubre alrededor de un 70% del\n"
	.string	"planeta, y el resto es tierra firme.\p"
	.string	"Por lo tanto, el mar es m??s del doble\n"
	.string	"de grande que la tierra.???$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string	"Se trata de un f??sil con crestas\n"
	.string	"onduladas.\p"
	.string	"???La marea erosiona el suelo\n"
	.string	"del fondo oce??nico.\p"
	.string	"Las corrientes marcan el suelo\n"
	.string	"con peque??as crestas y valles.\p"
	.string	"Si este suelo termina fosiliz??ndose,\n"
	.string	"recibe el nombre de marca f??sil.???$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string	"Una extra??a m??quina est?? rotando\n"
	.string	"bajo una c??pula de cristal.\p"
	.string	"Quiz??s sirva para medir la\n"
	.string	"profundidad de algo???$"

