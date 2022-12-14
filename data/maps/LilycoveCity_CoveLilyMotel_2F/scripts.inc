LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string	"Yo soy el DISE??ADOR del JUEGO.\p"
	.string	"??Ah, s??? ??Est??s trabajando\n"
	.string	"en una POK??DEX?\p"
	.string	"Cuesta trabajo completarla,\n"
	.string	"pero t?? no desistas.\p"
	.string	"Y, cuando est?? completa,\n"
	.string	"ven a verme.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string	"??Guau! ??Impresionante!\n"
	.string	"??Impresionantemente impresionante!\p"
	.string	"??Tu POK??DEX est?? llena del todo!\n"
	.string	"??Deben de encantarte los POK??MON!\p"
	.string	"Estoy impresionado.\p"
	.string	"Semejante proeza se merece\n"
	.string	"un reconocimiento en condiciones.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string	"??Eh? ??Me hablas a m???\n"
	.string	"Soy el PROGRAMADOR.\p"
	.string	"Me pregunto c??mo ser??n las\n"
	.string	"TRAGAPERRAS por aqu?????$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string	"Soy el DISE??ADOR GR??FICO.\n"
	.string	"??A que los POK??MON de HOENN\l"
	.string	"son particularmente interesantes?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string	"Las PLAYERAS son monas, ??verdad?\n"
	.string	"Combatir contra ellas es de lo\l"
	.string	"m??s motivador???\p"
	.string	"Pero que muy motivador???\p"
	.string	"??Y las GEMELAS! ??No son preciosas?\n"
	.string	"Los combates dobles me encantan.\p"
	.string	"??Es que me lo paso de miedo!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string	"No hay nada que me guste m??s que\n"
	.string	"la brisa marina. ??Qu?? bien se est??!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string	"Nunca puedes saber qui??n\n"
	.string	"ni cu??ndo te va a desafiar.\p"
	.string	"Por eso nunca me voy de casa sin\n"
	.string	"mi consola GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string	"TRETO: Zzz???\p"
	.string	"Zzz??? ??Eh? ??Huy, perd??n!\n"
	.string	"??Estaba echando una cabezadita!\p"
	.string	"He venido a echar un vistazo a esto\n"
	.string	"de los CONCURSOS POK??MON.\p"
	.string	"Debo reconocer que parecen la\n"
	.string	"mar de entretenidos, pero???\p"
	.string	"Dir??s que soy un purista, pero\n"
	.string	"prefiero un buen combate contra\l"
	.string	"un ENTRENADOR duro de pelar.\p"
	.string	"Claro que para gustos, los colores.\p"
	.string	"{PLAYER}{KUN}, espero que a ti te gusten\n"
	.string	"los GIMNASIOS, los CONCURSOS, las\l"
	.string	"TIENDAS de BATALLA, ??vamos, todo!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string	"TRETO: Creo que no se puede ganar\n"
	.string	"un CONCURSO sin una buena estrategia.\p"
	.string	"Yo dir??a que dise??ar estrategias para\n"
	.string	"ganar CONCURSOS tambi??n te ayuda\l"
	.string	"a mejorar como ENTRENADOR.$"

