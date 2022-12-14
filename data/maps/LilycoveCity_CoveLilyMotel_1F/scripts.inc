.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string	"Qu?? interesante: han duplicado\n"
	.string	"el n??mero de clientes usando\l"
	.string	"POK??MON como reclamo.\p"
	.string	"Mmmm??? Quiz??s deber??a escoger\n"
	.string	"un POK??MON como mascota del hostal.\p"
	.string	"Puede que as?? consiga que vengan\n"
	.string	"m??s hu??spedes???$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string	"Oh, disculpa. Estaba viendo la tele\n"
	.string	"y no te he visto llegar.\p"
	.string	"Es que desde que lleg?? el EQUIPO\n"
	.string	"AQUA, no vienen turistas, as?? que\l"
	.string	"no esperaba a nadie???$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string	"??Oye, quita de ah??, que no\n"
	.string	"eres transparente!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string	"??Incre??ble! ??Me est??s diciendo que un\n"
	.string	"POK??MON encontr?? un objeto perdido?\p"
	.string	"Qu?? interesante: si tuvi??ramos un\n"
	.string	"POK??MON tan listo como ??se???,\p"
	.string	"??recuperar??amos todo lo que perdieran\n"
	.string	"nuestros hu??spedes!$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string	"Oh, disculpa. Estaba viendo la tele\n"
	.string	"y no te he visto llegar.\p"
	.string	"Me han dicho que alguien ha destrozado\n"
	.string	"la GUARIDA del EQUIPO AQUA.\p"
	.string	"Gracias a eso, la gente ha perdido el\n"
	.string	"miedo y acabo de recibir a un grupo.\p"
	.string	"Son todos de la misma empresa???\n"
	.string	"??C??mo era? Ah, s??, GAME algo???$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string	"??Incre??ble! ??Me est??s diciendo que un\n"
	.string	"POK??MON guardi??n pill?? a un ladr??n?\p"
	.string	"Qu?? interesante: si tuvi??ramos\n"
	.string	"un POK??MON tan fuerte como ??se???,\p"
	.string	"??podr??amos ofrecer el mejor servicio\n"
	.string	"de seguridad a nuestros hu??spedes!$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string	"Oh, disculpa. Estaba viendo la tele\n"
	.string	"y no te he visto llegar.\p"
	.string	"Ah, s??. Acaba de llegar un gran\n"
	.string	"grupo de hu??spedes.\p"
	.string	"Pertenecen a la empresa GAME FREAK,\n"
	.string	"as?? que deben de crear videojuegos.\p"
	.string	"??Huy, huy, creo que tengo que irme\n"
	.string	"a prepararles la cena!$"

