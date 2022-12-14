FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string	"Nadie me cree, pero he visto un\n"
	.string	"POK??MON gigantesco en el cielo.\p"
	.string	"Parec??a que se retorc??a. Iba volando\n"
	.string	"en direcci??n a la RUTA 131.\p"
	.string	"Mmm??? Hueles a chamuscado???\p"
	.string	"??Has estado en un volc??n o algo as???$"

FortreeCity_Text_SomethingBlockingGym:
	.string	"Quiero ir al GIMNASIO POK??MON,\n"
	.string	"pero hay algo bloqueando el camino.\p"
	.string	"Despu??s de todas las molestias que me\n"
	.string	"he tomado, he tenido que ir a entrenar\l"
	.string	"a la RUTA 120???$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string	"Tengo junto a m?? a mi POK??MON favorito.\n"
	.string	"Seguro que esta vez venzo a ALANA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string	"La tierra absorbe el agua de lluvia\n"
	.string	"y los ??rboles absorben esa agua.\p"
	.string	"CIUDAD ARBORADA existe porque\n"
	.string	"tenemos agua y tierra.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string	"Todas las casas de la ciudad est??n\n"
	.string	"construidas sobre ??rboles.\p"
	.string	"Gracias a nuestro estilo de vida,\n"
	.string	"todos aqu?? somos alegres y sanos.\p"
	.string	"Vamos, m??rame a m?????,\n"
	.string	"??estoy hecho un chaval!$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string	"Vivir en la copa de los ??rboles mola.\p"
	.string	"Pero a veces entran POK??MON de tipo\n"
	.string	"BICHO por la ventana???\l"
	.string	"??Y te pegan cada susto???!$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string	"Algunos POK??MON evolucionan cuando\n"
	.string	"los intercambias o al menos eso dicen.$"

FortreeCity_Text_SomethingUnseeable:
	.string	"Algo invisible corta el paso.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string	"Algo invisible corta el paso.\p"
	.string	"??Usas el DETECTOR DEVON?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string	"{PLAYER} us?? el DETECTOR DEVON.\p"
	.string	"??Un POK??MON invisible se ha vuelto\n"
	.string	"totalmente visible!\p"
	.string	"??El POK??MON ha huido asustado!$"

FortreeCity_Text_CitySign:
	.string	"CIUDAD ARBORADA\n"
	.string	"???La ciudad arb??rea que juega\l"
	.string	"con la naturaleza.???$"

FortreeCity_Text_GymSign:
	.string	"GIMNASIO POK??MON de CIUDAD ARBORADA\n"
	.string	"L??DER: ALANA\p"
	.string	"???La amante de los p??jaros POK??MON\n"
	.string	"que planea en las alturas.???$"
