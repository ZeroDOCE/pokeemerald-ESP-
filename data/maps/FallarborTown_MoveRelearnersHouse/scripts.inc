.set LOCALID_MOVE_RELEARNER, 1

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string	"Soy el TUTOR de MOVIMIENTOS.\p"
	.string	"Me s?? todos los movimientos que\n"
	.string	"aprenden los POK??MON. Todos, toditos,\l"
	.string	"todos. Y adem??s los puedo ense??ar.\p"
	.string	"Si quieres, puedo ense??ar a uno\n"
	.string	"de tus POK??MON un movimiento.\p"
	.string	"Lo har?? por una insignificante ESCAMA\n"
	.string	"CORAZ??N. Es que las colecciono.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string	"??S??! ????sa es! ??Una aut??ntica ESCAMA\n"
	.string	"CORAZ??N! ??Una de las de verdad!\p"
	.string	"A ver que lo adivine, ??quieres que\n"
	.string	"ense??e un movimiento a tu POK??MON?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string	"??Qu?? POK??MON quieres que lo aprenda?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string	"??Qu?? movimiento quieres que aprenda?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string	"Perdona???\p"
	.string	"Parece que no puedo ense??ar ning??n\n"
	.string	"movimiento a ese POK??MON???$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string	"{PLAYER} entreg?? una ESCAMA CORAZ??N\n"
	.string	"a cambio de la lecci??n.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string	"Si tu POK??MON necesita aprender\n"
	.string	"un movimiento, vuelve con una ESCAMA\l"
	.string	"CORAZ??N.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string	"??Eh? No puedo ense??ar absolutamente\n"
	.string	"ning??n movimiento a un HUEVO???$"

