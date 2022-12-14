LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string	"??Ah?? va! ??Est??s viajando sin compa????a?\n"
	.string	"??Si eres muy joven! ??Qu?? valiente eres!\p"
	.string	"Seguro que mis hijos podr??an aprender\n"
	.string	"un par de cosas de ti.\p"
	.string	"Yo soy la MAESTRA de los {POKEBLOCK}S.\p"
	.string	"Si me pongo un poco en serio, vaya,\n"
	.string	"hago unos {POKEBLOCK}S incre??bles.\p"
	.string	"??Te apetece aprender un par\n"
	.string	"de cosas de m???$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string	"??Seguro? ??De verdad?\p"
	.string	"??A veces tambi??n hay que pedir\n"
	.string	"ayuda a los dem??s, sabes!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string	"??Muy bien! ??Se ve que piensas!\n"
	.string	"Esto va a ser un poco largo,\l"
	.string	"as?? que escucha.\p"
	.string	"??Atenci??n, all?? voy!\p"
	.string	"Si te fijas, ver??s que los {POKEBLOCK}S\n"
	.string	"est??n clasificados seg??n su masa.\p"
	.string	"Cuanta menos masa tengan,\n"
	.string	"mejor es el resultado. ??No lo olvides!\p"
	.string	"Un buen {POKEBLOCK} tiene poca\n"
	.string	"masa y mucha eficacia.\p"
	.string	"Un POK??MON puede comer m??s\n"
	.string	"{POKEBLOCK}S buenos que {POKEBLOCK}S\l"
	.string	"normales.\p"
	.string	"Y esto es muy importante???\p"
	.string	"Si quieres que tus {POKEBLOCK}S sean\n"
	.string	"suaves, usa diferentes tipos de BAYA.\p"
	.string	"Recuerda que el tipo de BAYA influye\n"
	.string	"en la suavidad de los {POKEBLOCK}S.\p"
	.string	"Y otra cosa m??s???\p"
	.string	"Cuanta m??s gente mezcle BAYAS,\n"
	.string	"m??s suaves ser??n los {POKEBLOCK}S.\p"
	.string	"Por eso debes hablar con la gente\n"
	.string	"y hacer {POKEBLOCK}S juntos.\p"
	.string	"Eso es todo lo que necesitas saber\n"
	.string	"para hacer buenos {POKEBLOCK}S.\p"
	.string	"Si todos tuvieran POK??MON cari??osos,\n"
	.string	"{POKEBLOCK}S suaves y muchos amigos,\l"
	.string	"el mundo ser??a un lugar mejor.\p"
	.string	"????nimo y no te rindas!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string	"Cuando mi mujer tuvo cuatrillizos,\n"
	.string	"casi me dio un ataque???\p"
	.string	"Pero ahora, cuando los veo jugar\n"
	.string	"juntos, me siento tan feliz???$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string	"Estamos entablando COMBATES\n"
	.string	"M??LTIPLES y s?? que voy a ganar.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string	"Nos encanta mezclar cosas\n"
	.string	"en el CENTRO de R??CORDS.\p"
	.string	"Pero ??qu?? se mezcla all???$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string	"Vamos a hacer {POKEBLOCK}S buen??simos\n"
	.string	"con una LICUABAYAS.$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string	"Quiero poder fardar de POK??MON, por\n"
	.string	"eso vamos a apuntarnos a un CONCURSO.$"

