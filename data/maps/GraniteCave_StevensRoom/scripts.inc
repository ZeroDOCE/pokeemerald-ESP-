.set LOCALID_STEVEN, 1

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM47
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string	"Soy M??XIMO.\p"
	.string	"Soy un aficionado a las rocas extra??as,\n"
	.string	"por eso viajo mucho.\p"
	.string	"??Y eso?\n"
	.string	"??Es una CARTA para m???$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string	"M??XIMO: Muy bien, gracias.\p"
	.string	"Te has tomado muchas molestias\n"
	.string	"para tra??rmela. Quiero agradec??rtelo.\p"
	.string	"A ver c??mo???\n"
	.string	"Ya s??, te dar?? esta MT.\p"
	.string	"Contiene mi movimiento favorito:\n"
	.string	"ALA DE ACERO.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string	"M??XIMO: Pareces un entrenador\n"
	.string	"muy capaz.\p"
	.string	"Si sigues entrenando, podr??as incluso\n"
	.string	"vencer en el CAMPEONATO de la\l"
	.string	"LIGA POK??MON alg??n d??a. Eso creo.\p"
	.string	"Ya s??, ya que nos conocemos,\n"
	.string	"registr??monos en nuestros POK??NAV.\p"
	.string	"No te arrepentir??s???$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string	"Acabas de registrar a M??XIMO\n"
	.string	"en el POK??NAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string	"Ahora me tengo que ir a todo correr.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string	"Oh, la MOCHILA est?? llena???\n"
	.string	"Qu?? mala pata???$"

