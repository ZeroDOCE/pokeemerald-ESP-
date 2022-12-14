FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string	"Eh, ??c??mo lo llevas, {PLAYER}?\n"
	.string	"??Camino del CAMPEONATO?\p"
	.string	"ALANA, la L??DER del GIMNASIO\n"
	.string	"de ARBORADA, es una maestra\l"
	.string	"de los POK??MON de tipo VOLADOR.\p"
	.string	"Ella est?? al fondo del GIMNASIO,\n"
	.string	"tras las puertas giratorias.\p"
	.string	"Est?? esperando a los ENTRENADORES\n"
	.string	"que quieren volar a lo m??s alto.\p"
	.string	"Muy bien, ??adelante!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string	"??Lo has hecho!\n"
	.string	"??Has conseguido despegar!$"

FortreeCity_Gym_Text_JaredIntro:
	.string	"??Observa con qu?? elegancia lucha\n"
	.string	"mi POK??MON P??JARO!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string	"T?????\n"
	.string	"eres muy fuerte???$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string	"Un ENTRENADOR ha de ser listo y saber\n"
	.string	"reaccionar ante cualquier situaci??n.\p"
	.string	"??Y t??? ??Tienes el ingenio que hace\n"
	.string	"falta para llegar a nuestra L??DER?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string	"Los amantes de los POK??MON P??JARO\n"
	.string	"desean ser miembros de este GIMNASIO.\p"
	.string	"Y, los que somos miembros ya???,\n"
	.string	"??no podemos permitirnos perder!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string	"Era una carga demasiado pesada\n"
	.string	"para m?????$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string	"El mundo es enorme y hay montones\n"
	.string	"de ENTRENADORES muy fuertes.\p"
	.string	"Por eso debo seguir entrenando\n"
	.string	"y mejorando cada vez m??s.$"

FortreeCity_Gym_Text_FlintIntro:
	.string	"??ALANA, nuestra L??DER de GIMNASIO,\n"
	.string	"no tiene por qu?? perder tiempo contigo!\p"
	.string	"??Yo me sobro para vencerte!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string	"Qu?? dir?? ALANA???\n"
	.string	"??He perdido!$"
	
FortreeCity_Gym_Text_FlintPostBattle:
	.string	"ALANA es la L??DER definitiva:\n"
	.string	"??tiene fuerza y car??cter!\p"
	.string	"Ella no va a dejarse ganar???$"

FortreeCity_Gym_Text_AshleyIntro:
	.string	"ALANA me ense???? todo lo que s??,\n"
	.string	"no te pienses que ser?? tan f??cil???$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string	"Me han derrotado???$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string	"La gente de ARBORADA vive mucho\n"
	.string	"m??s tranquila desde que est?? ALANA.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string	"Cuando ALANA entra en combate,\n"
	.string	"su rostro brilla con determinaci??n???\p"
	.string	"??Pero no dejar?? que lo veas\n"
	.string	"con tus propios ojos!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string	"??Argh!\n"
	.string	"No he logrado detenerte.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string	"??Ser?? mejor que te andes con cuidado!\n"
	.string	"??No te distraigas frente a ALANA\l"
	.string	"o te har?? picadillo en un periquete!$"

FortreeCity_Gym_Text_DariusIntro:
	.string	"Sabr??s que hay much??simas clases\n"
	.string	"de POK??MON de tipo VOLADOR???\p"
	.string	"??O no ten??as ni idea?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string	"??Ya veo que te sabes la lecci??n!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string	"No hay duda de que has vencido, pero\n"
	.string	"ve con pies de plomo. Los POK??MON\l"
	.string	"de nuestra L??DER ALANA son cosa seria.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string	"Soy ALANA, la L??DER del GIMNASIO\n"
	.string	"de ARBORADA.\p"
	.string	"He unido fuerzas con los POK??MON\n"
	.string	"P??JARO y alzado el vuelo.\p"
	.string	"Por duro que fuera el combate, siempre\n"
	.string	"hemos vencido con gracia y donaire.\p"
	.string	"??Ahora ver??s con qu?? elegancia te\n"
	.string	"derrotan mis POK??MON P??JARO!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string	"Nunca antes hab??a visto a ning??n\n"
	.string	"ENTRENADOR capaz de dirigir a sus\l"
	.string	"POK??MON con m??s arte que yo???\p"
	.string	"Debo reconocer tama??a proeza como\n"
	.string	"se merece. Toma esta MEDALLA.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string	"{PLAYER} recibi?? la MEDALLA PLUMA\n"
	.string	"de ALANA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string	"Con la MEDALLA PLUMA te obedecer??n\n"
	.string	"todos los POK??MON hasta el nivel 70,\l"
	.string	"incluso los que has intercambiado.\p"
	.string	"Tambi??n podr??s usar el movimiento\n"
	.string	"de la MO VUELO fuera de los combates.\p"
	.string	"Adem??s quiero hacerte un regalo???$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string	"La MT40 contiene GOLPE A??REO.\p"
	.string	"Es veloc??simo: ning??n POK??MON\n"
	.string	"deber??a ser capaz de evitarlo.\p"
	.string	"Absolutamente ninguno???$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string	"Acabas de registrar a ALANA,\n"
	.string	"la L??DER de GIMNASIO, en el POK??NAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string	"Aunque he ca??do ante ti, seguir??\n"
	.string	"siendo fiel a mis POK??MON P??JARO.$"

FortreeCity_Gym_Text_GymStatue:
	.string	"GIMNASIO POK??MON de CIUDAD ARBORADA$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string	"GIMNASIO POK??MON de CIUDAD ARBORADA\p"
	.string	"NUEVOS ENTRENADORES CERTIFICADOS:\n"
	.string	"{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string	"ALANA: Los humanos no podemos\n"
	.string	"escapar a la fuerza de la gravedad.\p"
	.string	"Pero, con mucho trabajo y esfuerzo,\n"
	.string	"podemos llegar a lo m??s alto.\p"
	.string	"Has coronado la cumbre y te has\n"
	.string	"hecho con el CAMPEONATO.\p"
	.string	"??Estoy deseando ver c??mo\n"
	.string	"emprendes el vuelo!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string	"Esta nueva victoria te ha dado alas???$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string	"ALANA: Aunque he perdido,\n"
	.string	"mi esp??ritu permanece intacto.\p"
	.string	"S?? que puedo alzar el vuelo\n"
	.string	"y tocar las nubes.\p"
	.string	"??Y eso har??!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string	"ALANA: Los humanos no podemos\n"
	.string	"escapar a la fuerza de la gravedad.\p"
	.string	"Pero, con mucho trabajo y esfuerzo,\n"
	.string	"podemos llegar a lo m??s alto.\p"
	.string	"Has coronado la cumbre y te has\n"
	.string	"hecho con el CAMPEONATO.\p"
	.string	"??Estoy deseando ver c??mo\n"
	.string	"emprendes el vuelo!\p"
	.string	"Oh, no???\n"
	.string	"??S??lo llevas un POK??MON contigo?\p"
	.string	"Vuelve cuando tengas al menos\n"
	.string	"dos POK??MON.$"
