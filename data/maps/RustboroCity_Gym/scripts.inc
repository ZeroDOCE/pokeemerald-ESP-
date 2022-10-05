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
	.string	"Eh, ¿qué tal vamos?\p"
	.string	"¡Escucha algo que te va a interesar!\n"
	.string	"¿Vas camino del CAMPEONATO?\p"
	.string	"Yo no soy ENTRENADOR, pero te puedo\n"
	.string	"dar un par de buenos consejos.\p"
	.string	"¡Así me gusta! ¡Te voy a decir cómo\n"
	.string	"ganar el CAMPEONATO POKéMON!\p"
	.string	"Un ENTRENADOR tiene que reunir\n"
	.string	"MEDALLAS de GIMNASIO, ¿no?\p"
	.string	"¡Pero ganar a los LÍDERES no es\n"
	.string	"pan comido!\p"
	.string	"¡Y ahí entro yo!\n"
	.string	"Puedo asesorarte como nadie.\p"
	.string	"PETRA, la LÍDER del GIMNASIO,\n"
	.string	"usa POKéMON de tipo ROCA.\p"
	.string	"El tipo ROCA es muy resistente, pero no\n"
	.string	"tiene ninguna oportunidad si se usan\l"
	.string	"movimientos de tipo AGUA o PLANTA.\p"
	.string	"Si derrotas a la LÍDER, ven a verme.\p"
	.string	"Venga, ¡valor y al toro!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string	"¡Guau, vaya pedazo de victoria!\n"
	.string	"¡Seguro que ha sido por todo lo que\l"
	.string	"te he animado desde aquí!\p"
	.string	"¡Genial!\n"
	.string	"Consulta tu FICHA de ENTRENADOR.\p"
	.string	"La MEDALLA PIEDRA que has conseguido\n"
	.string	"debería figurar ahí.\p"
	.string	"En otras palabras…\p"
	.string	"¡Has dado el primer paso que te llevará\n"
	.string	"a la cima!\p"
	.string	"¡Tiene que ser superemocionante!$"

RustboroCity_Gym_Text_JoshIntro:
	.string	"A los ENTRENADORES no debes tomarnos\n"
	.string	"a la ligera… ¡Ahora verás por qué!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string	"Me has dejado a cuadros…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string	"¡Todavía no has visto ni una pizca\n"
	.string	"del terrible poder del tipo ROCA!$"
	
RustboroCity_Gym_Text_TommyIntro:
	.string	"¡Si no puedes vencerme a mí, ya puedes\n"
	.string	"olvidarte de derrotar a PETRA!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string	"Vaya, se diría que tienes potencial…$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string	"Pero PETRA es mucho más fuerte\n"
	.string	"que yo de aquí a Lima.\p"
	.string	"¡Mejor no te confíes!$"

RustboroCity_Gym_Text_MarcIntro:
	.string	"Ya sé que estamos en medio de una\n"
	.string	"ciudad, pero no te servirá de nada.\p"
	.string	"Mis POKéMON ROCA no se andan\n"
	.string	"con chiquitas. ¡Échate a temblar!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string	"¡Por todos los peñascos!\n"
	.string	"¡Tú sí que no te andas con chiquitas!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string	"Nuestra LÍDER te dará tu merecido.\p"
	.string	"A pesar de su juventud, escogió el\n"
	.string	"tipo ROCA y eso demuestra carácter.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string	"Hola, soy PETRA, la LÍDER del\n"
	.string	"GIMNASIO POKéMON de CIUDAD FÉRRICA.\p"
	.string	"Me convertí en LÍDER para poder\n"
	.string	"aplicar lo que había aprendido en la\l"
	.string	"ESCUELA de ENTRENADORES POKéMON.\p"
	.string	"¿Me harías el favor de enseñarme tus\n"
	.string	"POKéMON y tus técnicas de combate?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string	"Pues…\n"
	.string	"he perdido…\p"
	.string	"Parece que aún no he aprendido\n"
	.string	"bastante…\p"
	.string	"Qué se le va a hacer.\p"
	.string	"Según las reglas de la LIGA POKéMON,\n"
	.string	"los ENTRENADORES deben recibir\l"
	.string	"esto si derrotan a un LÍDER.\p"
	.string	"Te entrego la MEDALLA PIEDRA oficial\n"
	.string	"de la LIGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string	"{PLAYER} recibió la MEDALLA PIEDRA\n"
	.string	"de PETRA.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string	"La MEDALLA PIEDRA potencia el poder\n"
	.string	"de ATAQUE de tus POKéMON.\p"
	.string	"También les permite usar la MO CORTE\n"
	.string	"fuera del combate.\p"
	.string	"Además, quiero darte esto.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string	"La MT39 contiene TUMBA ROCAS.\p"
	.string	"No sólo inflige daño al lanzar rocas\n"
	.string	"a tu rival, sino que también reduce\l"
	.string	"la VELOCIDAD de éste.\p"
	.string	"Si usas una MT, puedes enseñar\n"
	.string	"ese movimiento a un POKéMON.\p"
	.string	"¡Pero recuerda que sólo la podrás\n"
	.string	"usar una vez y ya está!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string	"Ya que eres tan fuerte, deberías\n"
	.string	"desafiar a otros LÍDERES.\p"
	.string	"Pero antes lucha contra muchos\n"
	.string	"ENTRENADORES para ganar experiencia.$"

RustboroCity_Gym_Text_GymStatue:
	.string	"GIMNASIO POKéMON de CIUDAD FÉRRICA$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string	"GIMNASIO POKéMON de CIUDAD FÉRRICA\p"
	.string	"NUEVOS ENTRENADORES CERTIFICADOS:\n"
	.string	"{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string	"¡Bip, bip!\p"
	.string	"PETRA: ¡Hola, {PLAYER}!\n"
	.string	"Aquí PETRA, de CIUDAD FÉRRICA.\p"
	.string	"Me ha dicho MARCIAL que estás\n"
	.string	"escalando puestos en la jerarquía\l"
	.string	"de ENTRENADORES a ojos vistas.\p"
	.string	"Pero, la verdad, no quiero pensar\n"
	.string	"que no puedo vencerte…\p"
	.string	"En el GIMNASIO nos entrenamos\n"
	.string	"a fondo para cuando vuelvas.\p"
	.string	"¡Estamos deseando desafiarte!\n"
	.string	"¡No nos hagas esperar mucho!\p"
	.string	"¡Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string	"Acabas de registrar a PETRA,\n"
	.string	"la LÍDER de GIMNASIO, en el POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string	"PETRA: Me alegra volver a verte.\n"
	.string	"Como sabes, soy PETRA, la LÍDER\l"
	.string	"de este GIMNASIO.\p"
	.string	"Seguro que hemos adquirido mucha\n"
	.string	"experiencia desde la última vez.\p"
	.string	"Así que habrá que comprobar todo lo\n"
	.string	"que hemos mejorado… ¡A luchar!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string	"Grrr…\n"
	.string	"He perdido otra vez…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string	"PETRA: Todavía tengo mucho que\n"
	.string	"aprender de los combates POKéMON.\p"
	.string	"¡Saber eso me da aún más ánimos\n"
	.string	"para seguir entrenándome y mejorar!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string	"PETRA: Me alegra volver a verte.\n"
	.string	"Como sabes, soy PETRA, la LÍDER\l"
	.string	"de este GIMNASIO.\p"
	.string	"Seguro que hemos adquirido mucha\n"
	.string	"experiencia desde la última vez.\p"
	.string	"Así que habrá que comprobar todo lo\n"
	.string	"que hemos mejorado…\p"
	.string	"Oh, no…\n"
	.string	"¿Sólo llevas un POKéMON contigo?\p"
	.string	"Pues necesitas al menos otro más.\n"
	.string	"Si no, no podremos luchar.$"