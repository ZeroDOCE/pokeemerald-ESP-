.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM36
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string	"??Qu?? es lo que est?? de moda? ??Pues\n"
	.string	"???{STR_VAR_1}???, claro!\p"
	.string	"??No puedo imaginarme lo que ser??a la\n"
	.string	"vida sin ???{STR_VAR_1}???!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string	"??Qu?? es lo que est?? de moda? ??Pues\n"
	.string	"???{STR_VAR_1}???, claro!\p"
	.string	"Pero ya empiezo a hartarme un poco???\p"
	.string	"Deber??a enterarme de lo que est??\n"
	.string	"a la ??ltima de verdad???$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string	"Estoy ense??ando a mi POK??MON todo\n"
	.string	"sobre ???{STR_VAR_1}???,\l"
	.string	"pero no acaba de funcionar???\p"
	.string	"Creo que el pobre no da m??s de s?????$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string	"Estoy estudiando algo supermol??n:\n"
	.string	"?????{STR_VAR_1}???!\p"
	.string	"??Crees que de veras existe un v??nculo\n"
	.string	"entre ???{STR_VAR_1}???\l"
	.string	"y ???{STR_VAR_2}????$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string	"??Oh!\n"
	.string	"??Entonces mi corazonada era cierta!\p"
	.string	"??Cada vez estoy m??s cerca de ser\n"
	.string	"superguay y supermoderno! ??Yupi!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string	"????C??mo?!\n"
	.string	"????En serio?!\p"
	.string	"Ya estoy muy mayor para estar al\n"
	.string	"tanto de las ??ltimas tendencias???$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string	"Toda esta historia de\n"
	.string	"???{STR_VAR_1}??????\l"
	.string	"??Ha salido en la tele o algo?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string	"??Y al otro lado del mar???\p"
	.string	"todo el mundo dice tambi??n\n"
	.string	"???{STR_VAR_1}????$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string	"Colecciono art??culos oficiales\n"
	.string	"???{STR_VAR_1}???.\p"
	.string	"Tengo mu??ecos oficiales\n"
	.string	"???{STR_VAR_1}??????,\p"
	.string	"ropa de marca\n"
	.string	"???{STR_VAR_1}??????\p"
	.string	"y libros ilustrados oficiales\n"
	.string	"???{STR_VAR_1}???.\p"
	.string	"??Y es todo m??o!\n"
	.string	"??Se mira, pero no se toca!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string	"???DIFERENCIANDO UN BUEN\n"
	.string	"???{STR_VAR_1}??? DE UN\l"
	.string	"???{STR_VAR_1}??? MALO??????\p"
	.string	"???LA CONEXI??N ENTRE\n"
	.string	"???{STR_VAR_1}??? Y\l"
	.string	"LOS POK??MON??????\p"
	.string	"???EL ???{STR_VAR_1}???\n"
	.string	"??TIL??????\p"
	.string	"Hay un mont??n de libros que tratan de\n"
	.string	"???{STR_VAR_1}???.$"

DewfordTown_Hall_Text_TrendsScream:
	.string	"El t??tulo es ???EL GRITO DE\n"
	.string	"{STR_VAR_1}???.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string	"El t??tulo es ???LA SONRISA DE\n"
	.string	"{STR_VAR_1}???.$"

DewfordTown_Hall_Text_LastTrend:
	.string	"El t??tulo es ???EL ??LTIMO\n"
	.string	"{STR_VAR_1}???.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string	"El t??tulo es ???EL NACIMIENTO DE\n"
	.string	"{STR_VAR_1}???.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string	"He visto ???{STR_VAR_1}???\n"
	.string	"y mola cantidubi.\p"
	.string	"Me ha hecho flipar en colores.\p"
	.string	"??Era asombroso!\n"
	.string	"??Lo m??s de lo m??s!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string	"Oh, no, no y no.\p"
	.string	"Crees haber visto\n"
	.string	"???{STR_VAR_1}??????\l"
	.string	"Pero es de mentira???\p"
	.string	"Para ser aut??ntico, deber??a tener???,\n"
	.string	"??c??mo lo dir??a yo????, fuerza y\l"
	.string	"delicadeza al mismo tiempo???\p"
	.string	"Bah, qu?? m??s da??? ??Es chul??simo!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string	"??yeme. He compuesto una canci??n\n"
	.string	"sobre ???{STR_VAR_1}???.\p"
	.string	"???{STR_VAR_1}???\n"
	.string	"es muy popular actualmente.\p"
	.string	"??Vale, esc??chala!\p"
	.string	"??Oh, oh, {STR_VAR_1}!\n"
	.string	"??La, la, la!\p"
	.string	"??S??lo {STR_VAR_1}!\n"
	.string	"??La, la, la!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string	"Jo, colega???\p"
	.string	"Antes de chafar del todo\n"
	.string	"???{STR_VAR_1}???,\l"
	.string	"deber??as aprender a cantar???$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string	"Pero como dec??a yo antes, habr??a\n"
	.string	"que juntarse y organizar una fiesta\l"
	.string	"???{STR_VAR_1}???\l"
	.string	"en la isla.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string	"??Qu?? idea tan buena!\p"
	.string	"Por fin sabremos qui??n es el as de\n"
	.string	"???{STR_VAR_1}???.\l"
	.string	"??Una idea buen??sima!\p"
	.string	"??A partir de hoy, todo girar?? alrededor\n"
	.string	"de ???{STR_VAR_1}???!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string	"Estaba pensando una cosa???\p"
	.string	"??No opinas tambi??n que\n"
	.string	"???{STR_VAR_1}??? ha\l"
	.string	"pasado de ser una moda a ser\l"
	.string	"parte de nuestras vidas?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string	"??Perd??n?\n"
	.string	"??Tanto como eso?\p"
	.string	"Sin embargo, es verdad que tenemos\n"
	.string	"a ???{STR_VAR_1}???\l"
	.string	"en la cabeza a todas horas.\p"
	.string	"??Pero, en lo que respecta a pensar\n"
	.string	"en ???{STR_VAR_1}???,\l"
	.string	"nadie te gana, coleguita!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string	"Si t?? y yo unimos fuerzas, seremos\n"
	.string	"invencibles en todo lo que concierne\l"
	.string	"a ???{STR_VAR_1}???.$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string	"??Escucha, colega!\p"
	.string	"??Seremos el D??O\n"
	.string	"???{STR_VAR_1}???!\p"
	.string	"??No te parece buena idea?\n"
	.string	"??Ja, ja, ja, ja!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string	"En mi opini??n, BOMBA LODO est??\n"
	.string	"en su mejor momento. Es lo mejor.\p"
	.string	"??Eh? ??Me est??s diciendo que no\n"
	.string	"sabes lo que es BOMBA LODO?\p"
	.string	"Qu?? pena, penita, pena.\n"
	.string	"Pues te voy a dar una, f??jate t??.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string	"Me encanta BOMBA LODO.\p"
	.string	"Pero tambi??n me gustan los POK??MON\n"
	.string	"que saben el movimiento\l"
	.string	"???{STR_VAR_1}???.$"

