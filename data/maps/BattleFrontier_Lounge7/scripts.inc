BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_E, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string	"??Ji, ji, ji, ji!\p"
	.string	"Quiz??s ahora no lo parezca, pero yo\n"
	.string	"en su d??a fui una gran ENTRENADORA.\p"
	.string	"??Dec??an que yo era la BELLA y la bestia!\n"
	.string	"??Las dos juntas!\p"
	.string	"??Mmm?\p"
	.string	"??Qu??????\n"
	.string	"Ah, ??que no me crees?\p"
	.string	"??Pues no te pienses que s??lo\n"
	.string	"soy una pobre viejecita!\l"
	.string	"??Como ??sa de ah?? enfrente!\p"
	.string	"Te lo voy a demostrar.\n"
	.string	"Les puedo ense??ar a tus POK??MON\l"
	.string	"movimientos especiales.\p"
	.string	"Pero las lecciones no son gratis, claro.\n"
	.string	"Yo cobro en PUNTOS de BATALLA.$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string	"??Ji, ji, ji, ji!\p"
	.string	"??Has vuelto para aprender movimientos \n"
	.string	"especiales para tus POK??MON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string	"Bien, bien.\n"
	.string	"??Qu?? quieres que te ense??e?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string	"Conque el movimiento {STR_VAR_1}???\n"
	.string	"Te costar?? {STR_VAR_2} PUNTOS de BATALLA, ??s???$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string	"Bien, bien. Elige entonces el POK??MON\n"
	.string	"que quieres que aprenda el movimiento.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string	"??Pero c??mo???? ??No ves que no tienes\n"
	.string	"suficientes PUNTOS de BATALLA?$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string	"??A que ahora no parezco tan viejecita?\n"
	.string	"??Vengan ac?? esos PUNTOS de BATALLA!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string	"??C??mo!\n"
	.string	"??Ya no quieres????\p"
	.string	"En fin, si quieres aprender algo bueno,\n"
	.string	"??ven a verme cuando quieras!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string	"??Je, je, je, je!\p"
	.string	"S?? que resulta dif??cil de creer, pero yo\n"
	.string	"antes era una ENTRENADORA fant??stica.\p"
	.string	"??Ten??a fama de ser una NADADORA\n"
	.string	"poco menos que invencible! ??En serio!\p"
	.string	"??Mmm?\p"
	.string	"??Qu?? pasa?\n"
	.string	"??No me crees?\p"
	.string	"A diferencia de esa abuelita de ah??,\n"
	.string	"yo a??n tengo mucho que ense??ar.\p"
	.string	"Y puedo demostr??rtelo.\n"
	.string	"Puedo ense??arte movimientos POK??MON\l"
	.string	"???alucinantes???, como dec??s los j??venes.\p"
	.string	"Aunque, claro, aprender un movimiento\n"
	.string	"te costar?? PUNTOS de BATALLA.$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string	"??Je, je, je, je!\p"
	.string	"??Has venido a aprender movimientos \n"
	.string	"especiales para tus POK??MON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string	"Seguro que al ver a esas viejecitas\n"
	.string	"ponerse verdes, pensar??s que no pueden\l"
	.string	"ni verse, ??verdad?\p"
	.string	"Pero yo creo que, si se llevasen tan mal,\n"
	.string	"no estar??an todo el rato juntas, ??no?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string	"Cuando yo era un apuesto JOVEN, esas\n"
	.string	"ancianas de ah?? eran las ENTRENADORAS\l"
	.string	"m??s guapas y m??s fuertes que hab??a.\p"
	.string	"Eran la envidia de todas las dem??s.\p"
	.string	"Ni siquiera la edad ha echado a perder\n"
	.string	"sus encantos, ni sus habilidades.\p"
	.string	"De hecho, jurar??a que sus movimientos\n"
	.string	"POK??MON son ahora m??s perfectos.\p"
	.string	"De todos modos, siento\n"
	.string	"no s?? qu?? al verlas???\p"
	.string	"Ay, el tiempo es tan cruel???$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string	"Restaura hasta\n"
	.string	"la mitad de tus\n"
	.string	"PS m??ximos.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string	"Resta los mismos\n"
	.string	"PS que nivel\n"
	.string	"tenga el agresor.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string	"Roba la mitad del\n"
	.string	"da??o causado\n"
	.string	"a un rival dormido.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string	"Un pu??etazo\n"
	.string	"de gran potencia.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string	"Patada de extrema\n"
	.string	"fuerza.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string	"Ataque corporal\n"
	.string	"que puede\n"
	.string	"paralizar.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string	"Lanza grandes\n"
	.string	"pedruscos. Puede\n"
	.string	"causar retroceso.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string	"Devuelve un golpe\n"
	.string	"f??sico por\n"
	.string	"duplicado.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string	"Una descarga que\n"
	.string	"puede paralizar\n"
	.string	"al enemigo.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string	"Baile que mejora\n"
	.string	"el ATAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string	"Oculta su punto\n"
	.string	"d??bil al rizarse.\n"
	.string	"Sube la DEFENSA.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string	"Fuerte ronquido\n"
	.string	"que puede usarse\n"
	.string	"estando dormido.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string	"Echa lodo en la\n"
	.string	"cara para bajar\n"
	.string	"la PRECISI??N.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string	"Lanza rayos en\n"
	.string	"forma de estrella\n"
	.string	"que no fallan.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string	"Ataque helado que\n"
	.string	"baja la VELOCIDAD.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string	"Resiste el ataque\n"
	.string	"de 1 turno y deja\n"
	.string	"al menos 1 PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string	"Copia los efectos\n"
	.string	"del rival y te los\n"
	.string	"adjudica.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string	"Pu??etazo helado.\n"
	.string	"Puede congelar.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string	"Pu??etazo\n"
	.string	"el??ctrico.\n"
	.string	"Puede paralizar.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string	"Pu??etazo\n"
	.string	"ardiente.\n"
	.string	"Puede quemar.$"
