RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string	"Eh, ??qu?? tal vamos?\p"
	.string	"??Escucha algo que te va a interesar!\n"
	.string	"??Vas camino del CAMPEONATO?\p"
	.string	"Yo no soy ENTRENADOR, pero te puedo\n"
	.string	"dar un par de buenos consejos.\p"
	.string	"??As?? me gusta! ??Te voy a decir c??mo\n"
	.string	"ganar el CAMPEONATO POK??MON!\p"
	.string	"Un ENTRENADOR tiene que reunir\n"
	.string	"MEDALLAS de GIMNASIO, ??no?\p"
	.string	"??Pero ganar a los L??DERES no es\n"
	.string	"pan comido!\p"
	.string	"??Y ah?? entro yo!\n"
	.string	"Puedo asesorarte como nadie.\p"
	.string	"PETRA, la L??DER del GIMNASIO,\n"
	.string	"usa POK??MON de tipo ROCA.\p"
	.string	"El tipo ROCA es muy resistente, pero no\n"
	.string	"tiene ninguna oportunidad si se usan\l"
	.string	"movimientos de tipo AGUA o PLANTA.\p"
	.string	"Si derrotas a la L??DER, ven a verme.\p"
	.string	"Venga, ??valor y al toro!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string	"??Guau, vaya pedazo de victoria!\n"
	.string	"??Seguro que ha sido por todo lo que\l"
	.string	"te he animado desde aqu??!\p"
	.string	"??Genial!\n"
	.string	"Consulta tu FICHA de ENTRENADOR.\p"
	.string	"La MEDALLA PIEDRA que has conseguido\n"
	.string	"deber??a figurar ah??.\p"
	.string	"En otras palabras???\p"
	.string	"??Has dado el primer paso que te llevar??\n"
	.string	"a la cima!\p"
	.string	"??Tiene que ser superemocionante!$"

RustboroCity_Gym_Text_JoshIntro:
	.string	"A los ENTRENADORES no debes tomarnos\n"
	.string	"a la ligera??? ??Ahora ver??s por qu??!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string	"Me has dejado a cuadros???$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string	"??Todav??a no has visto ni una pizca\n"
	.string	"del terrible poder del tipo ROCA!$"
	
RustboroCity_Gym_Text_TommyIntro:
	.string	"??Si no puedes vencerme a m??, ya puedes\n"
	.string	"olvidarte de derrotar a PETRA!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string	"Vaya, se dir??a que tienes potencial???$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string	"Pero PETRA es mucho m??s fuerte\n"
	.string	"que yo de aqu?? a Lima.\p"
	.string	"??Mejor no te conf??es!$"

RustboroCity_Gym_Text_MarcIntro:
	.string	"Ya s?? que estamos en medio de una\n"
	.string	"ciudad, pero no te servir?? de nada.\p"
	.string	"Mis POK??MON ROCA no se andan\n"
	.string	"con chiquitas. ????chate a temblar!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string	"??Por todos los pe??ascos!\n"
	.string	"??T?? s?? que no te andas con chiquitas!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string	"Nuestra L??DER te dar?? tu merecido.\p"
	.string	"A pesar de su juventud, escogi?? el\n"
	.string	"tipo ROCA y eso demuestra car??cter.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string	"Hola, soy PETRA, la L??DER del\n"
	.string	"GIMNASIO POK??MON de CIUDAD F??RRICA.\p"
	.string	"Me convert?? en L??DER para poder\n"
	.string	"aplicar lo que hab??a aprendido en la\l"
	.string	"ESCUELA de ENTRENADORES POK??MON.\p"
	.string	"??Me har??as el favor de ense??arme tus\n"
	.string	"POK??MON y tus t??cnicas de combate?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string	"Pues???\n"
	.string	"he perdido???\p"
	.string	"Parece que a??n no he aprendido\n"
	.string	"bastante???\p"
	.string	"Qu?? se le va a hacer.\p"
	.string	"Seg??n las reglas de la LIGA POK??MON,\n"
	.string	"los ENTRENADORES deben recibir\l"
	.string	"esto si derrotan a un L??DER.\p"
	.string	"Te entrego la MEDALLA PIEDRA oficial\n"
	.string	"de la LIGA POK??MON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string	"{PLAYER} recibi?? la MEDALLA PIEDRA\n"
	.string	"de PETRA.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string	"La MEDALLA PIEDRA potencia el poder\n"
	.string	"de ATAQUE de tus POK??MON.\p"
	.string	"Tambi??n les permite usar la MO CORTE\n"
	.string	"fuera del combate.\p"
	.string	"Adem??s, quiero darte esto.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string	"La MT39 contiene TUMBA ROCAS.\p"
	.string	"No s??lo inflige da??o al lanzar rocas\n"
	.string	"a tu rival, sino que tambi??n reduce\l"
	.string	"la VELOCIDAD de ??ste.\p"
	.string	"Si usas una MT, puedes ense??ar\n"
	.string	"ese movimiento a un POK??MON.\p"
	.string	"??Pero recuerda que s??lo la podr??s\n"
	.string	"usar una vez y ya est??!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string	"Ya que eres tan fuerte, deber??as\n"
	.string	"desafiar a otros L??DERES.\p"
	.string	"Pero antes lucha contra muchos\n"
	.string	"ENTRENADORES para ganar experiencia.$"

RustboroCity_Gym_Text_GymStatue:
	.string	"GIMNASIO POK??MON de CIUDAD F??RRICA$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string	"GIMNASIO POK??MON de CIUDAD F??RRICA\p"
	.string	"NUEVOS ENTRENADORES CERTIFICADOS:\n"
	.string	"{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string	"??Bip, bip!\p"
	.string	"PETRA: ??Hola, {PLAYER}!\n"
	.string	"Aqu?? PETRA, de CIUDAD F??RRICA.\p"
	.string	"Me ha dicho MARCIAL que est??s\n"
	.string	"escalando puestos en la jerarqu??a\l"
	.string	"de ENTRENADORES a ojos vistas.\p"
	.string	"Pero, la verdad, no quiero pensar\n"
	.string	"que no puedo vencerte???\p"
	.string	"En el GIMNASIO nos entrenamos\n"
	.string	"a fondo para cuando vuelvas.\p"
	.string	"??Estamos deseando desafiarte!\n"
	.string	"??No nos hagas esperar mucho!\p"
	.string	"??Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string	"Acabas de registrar a PETRA,\n"
	.string	"la L??DER de GIMNASIO, en el POK??NAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string	"PETRA: Me alegra volver a verte.\n"
	.string	"Como sabes, soy PETRA, la L??DER\l"
	.string	"de este GIMNASIO.\p"
	.string	"Seguro que hemos adquirido mucha\n"
	.string	"experiencia desde la ??ltima vez.\p"
	.string	"As?? que habr?? que comprobar todo lo\n"
	.string	"que hemos mejorado??? ??A luchar!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string	"Grrr???\n"
	.string	"He perdido otra vez???$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string	"PETRA: Todav??a tengo mucho que\n"
	.string	"aprender de los combates POK??MON.\p"
	.string	"??Saber eso me da a??n m??s ??nimos\n"
	.string	"para seguir entren??ndome y mejorar!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string	"PETRA: Me alegra volver a verte.\n"
	.string	"Como sabes, soy PETRA, la L??DER\l"
	.string	"de este GIMNASIO.\p"
	.string	"Seguro que hemos adquirido mucha\n"
	.string	"experiencia desde la ??ltima vez.\p"
	.string	"As?? que habr?? que comprobar todo lo\n"
	.string	"que hemos mejorado???\p"
	.string	"Oh, no???\n"
	.string	"??S??lo llevas un POK??MON contigo?\p"
	.string	"Pues necesitas al menos otro m??s.\n"
	.string	"Si no, no podremos luchar.$"
