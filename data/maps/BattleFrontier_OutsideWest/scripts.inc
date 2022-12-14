.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string	"????sta es la C??PULA BATALLA!\n"
	.string	"??La ruta a la fama pasa por aqu??!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string	"????sta es la F??BRICA BATALLA!\n"
	.string	"??Hazte con el POK??MON m??s fuerte!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string	"????sta es la SIERPE BATALLA!\n"
	.string	"??Elige el mejor de los tres caminos!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string	"??sta es la TORRE BATALLA.\p"
	.string	"Los ENTRENADORES traen a sus mejores\n"
	.string	"POK??MON para luchar en combates\l"
	.string	"eliminatorios.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string	"Buenas, ??vienes para coger el ferry?\n"
	.string	"??Puedo ver tu TICKET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string	"{PLAYER} no tiene ning??n TICKET???\p"
	.string	"Cu??nto lo lamento.\p"
	.string	"Necesitas un TICKET para poder\n"
	.string	"subir a bordo del ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string	"{PLAYER} ense???? el TICKET???\p"
	.string	"Perfecto. Todo est?? en regla.\p"
	.string	"??Ad??nde te gustar??a ir?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string	"Muy bien, rumbo a CIUDAD PORTUAL.$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string	"Muy bien, rumbo a CIUDAD CALAGUA.$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string	"??Esperamos que vuelvas a navegar\n"
	.string	"con nosotros!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string	"Sube a bordo y espera a que zarpemos.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string	"Sube. ??Ad??nde te gustar??a ir?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string	"Les doy mil vueltas a todos mis amigos.\n"
	.string	"Pero aqu?????\l"
	.string	"He hecho el rid??culo.$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string	"Quiero ir a la TORRE BATALLA,\n"
	.string	"pero no la encuentro, y eso que tengo\l"
	.string	"un mapa del FRENTE de BATALLA???\p"
	.string	"??Es que este sitio es muy grande!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string	"Quer??a llegar lo antes posible\n"
	.string	"para ponerme a luchar.\p"
	.string	"Pero me he mareado en el barco???\n"
	.string	"Uajjj???$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string	"No te creas que al FRENTE de BATALLA\n"
	.string	"puede venir cualquiera, ??eh?\p"
	.string	"Aqu?? s??lo invitan a los ENTRENADORES\n"
	.string	"que han demostrado que valen.\p"
	.string	"Por eso muchos ENTRENADORES\n"
	.string	"ni han o??do hablar de este lugar.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string	"Eh, colega???\p"
	.string	"??Seguro que podemos combatir\n"
	.string	"aunque no tengamos ni un POK??MON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string	"??Claro! ??Seguro que no pasa nada!\p"
	.string	"Creo???\p"
	.string	"Recuerda lo que dijo el gorila ese del\n"
	.string	"mostrador: ?????Yo te presto\l"
	.string	"los POK??MON!???.$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string	"Eso de ah?? es la F??BRICA BATALLA.\n"
	.string	"Ah?? te prestan POK??MON muy fuertes.\p"
	.string	"Siempre me he preguntado qui??n ser??\n"
	.string	"el guapo que los entrena???$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string	"Me da miedo entrar en la SIERPE\n"
	.string	"BATALLA con todos esos SEVIPER???\p"
	.string	"Pe-pero, ya que he llegado hasta aqu??,\n"
	.string	"tendr?? que conquistarlo todo, ??no?\l"
	.string	"Ay, ay, ay???$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string	"??Vamos a jugar a piedra, papel o tijeras!\n"
	.string	"Una, dos, y???\p"
	.string	"??tres!\p"
	.string	"Mmm???$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string	"??S??! ??Gan??!\n"
	.string	"??Entrar?? en la SIERPE BATALLA!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string	"Oh, no???\n"
	.string	"He perdido.\p"
	.string	"Hoy no es mi d??a de suerte.\n"
	.string	"Creo que tendr?? que dejar lo de\l"
	.string	"la SIERPE BATALLA para ma??ana.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string	"Creo que soy el ??nico de por aqu?? que, \n"
	.string	"por alguna raz??n que se me escapa,\l"
	.string	"prefiere pescar a combatir.\p"
	.string	"??C??mo????\p"
	.string	"??Que aqu?? no pica nada?\n"
	.string	"Vaya, qu?? fastidio???$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string	"??Hoy no pienso parar de combatir hasta\n"
	.string	"que no haya ganado un s??mbolo! ??Ea!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string	"??Eh? ??T?? tambi??n piensas entrar\n"
	.string	"en la C??PULA BATALLA?\p"
	.string	"Pues te deseo toda la suerte del mundo.\n"
	.string	"Ojal?? ganemos los dos\l"
	.string	"y nos encontremos en la final.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string	"??Abuelito, por aqu??!\n"
	.string	"??La C??PULA BATALLA est?? aqu??!\l"
	.string	"??Venga, a por ellos, abuelito!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string	"Ah, conque esto es la C??PULA BATALLA???\n"
	.string	"??No pienso dejarme ganar por ninguno\l"
	.string	"de esos a los que llaman CABALLEROS!\p"
	.string	"Pero ??por d??nde se entra a este sitio?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string	"Todav??a me acuerdo de cuando aqu??\n"
	.string	"no hab??a nada.\p"
	.string	"Pero mira ahora??? ??Incre??ble!\n"
	.string	"??Esto tiene que verlo mi madre!$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string	"??Por fin estoy en el FRENTE de BATALLA!\p"
	.string	"??Ya ver??s c??mo triunfo aqu?? con\n"
	.string	"todos mis encantos y habilidades!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string	"??am, ??am???\p"
	.string	"Esta plaza est?? llena de tipos duros,\n"
	.string	"??no crees?\p"
	.string	"??am, ??am???$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string	"??am, ??am???\p"
	.string	"El otro d??a me encontr?? con una chica\n"
	.string	"en la SIERPE BATALLA.\p"
	.string	"Ten??a unos ojos que daban miedo.\p"
	.string	"??am, ??am???\p"
	.string	"Estaba indignada: ???????Vas a dejar de\n"
	.string	"comer de una vez?!???, me dijo.\l"
	.string	"Y luego me machac??.\p"
	.string	"Lo pas?? fatal, menuda experiencia tan\n"
	.string	"traum??tica, oye. Qu?? mal lo pas?????\p"
	.string	"??am, ??am???$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string	"Pero ????qu?? est??s diciendo, chaval?!\n"
	.string	"??Menuda tonter??a!\p"
	.string	"??Sabes lo que te digo?\n"
	.string	"??Que era a m?? a quien miraba!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string	"????Que qu???!\n"
	.string	"??Bah!\p"
	.string	"??Eso fue porque estabas\n"
	.string	"sentada a mi lado, lista!\p"
	.string	"??El ASTRO de la C??PULA me estaba\n"
	.string	"mirando a m??! ??Y s??lo a m??!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string	"??Venga, ya!\n"
	.string	"??Dejad de discutir! ??Parec??is cr??os!\p"
	.string	"??Menudos fans de pacotilla!\n"
	.string	"??No os merec??is animar\l"
	.string	"ni a un L??DER de GIMNASIO!\p"
	.string	"??El ASTRO de la C??PULA es para m??!\n"
	.string	"??Es mi ??nico ??dolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string	"Mira a ??sos de ah?? discutiendo???\p"
	.string	"Resulta dif??cil de creer, pero antes\n"
	.string	"eran ENTRENADORES, y de los buenos.\p"
	.string	"Vamos, que eran famosos y todo.\p"
	.string	"Pero en un torneo, hubo un ENTRENADOR\n"
	.string	"que los eclips?? completamente.\p"
	.string	"Les dio una paliza tremenda a todos.\p"
	.string	"Y ahora son sus fans incondicionales\n"
	.string	"y van a animarlo a la C??PULA BATALLA\l"
	.string	"siempre que participa en un torneo.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string	"Dicen que han visto a un POK??MON\n"
	.string	"que tiene una cola largu??sima en alg??n\l"
	.string	"sitio del FRENTE de BATALLA.\p"
	.string	"Tiene que ser adorable, seguro???\p"
	.string	"Los desaf??os pueden esperar.\n"
	.string	"??Yo quiero encontrar a ese POK??MON!$"

