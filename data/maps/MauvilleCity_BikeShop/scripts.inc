MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string	"Bueno, bueno, bueno, ??a qui??n tenemos\n"
	.string	"aqu??? ??Una personita con muchos br??os!\p"
	.string	"??Mi nombre? Me llaman ANACLETO y soy\n"
	.string	"el propietario de esta tienda de bicis.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string	"ANACLETO: Esas DEPORTIVAS\n"
	.string	"est??n que dan asquito???\p"
	.string	"??Vienes de muy lejos?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string	"ANACLETO: ??De veras?\p"
	.string	"Entonces supongo que no necesitas\n"
	.string	"ninguna BICI???$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string	"ANACLETO: Aj??, aj??, entiendo???\n"
	.string	"S??, s??, ya veo???\p"
	.string	"As?? que has venido nada menos\n"
	.string	"que desde VILLA RA??Z???\p"
	.string	"??Impresionante!\n"
	.string	"??Est?? en el quinto pino!\p"
	.string	"Si tuvieras una de mis BICIS, podr??as\n"
	.string	"ir a cualquier sitio en un periquete\l"
	.string	"mientras el viento acaricia tu rostro.\p"
	.string	"Ya s??: ??te voy a dar una BICI!\p"
	.string	"Pero espera un segundo???\p"
	.string	"No te he dicho que hay dos tipos\n"
	.string	"de BICIS???\p"
	.string	"La BICI CARRERA y la BICI ACROB??TICA.\p"
	.string	"La BICI CARRERA es para aquellos a los\n"
	.string	"que les gusta poner cara de velocidad.\p"
	.string	"La BICI ACROB??TICA es para aquellos\n"
	.string	"a los que les gusta hacer virguer??as.\p"
	.string	"Soy la mar de majo, as?? que puedes\n"
	.string	"elegir la que m??s te mole.\p"
	.string	"??Cu??l te llevas?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string	"{PLAYER} eligi?? la BICI CARRERA.$"
	
MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string	"{PLAYER} eligi?? la BICI ACROB??TICA.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string	"ANACLETO: Si de repente te apetece\n"
	.string	"cambiar de BICI, ven a verme.$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string	"ANACLETO: ??Hola!\n"
	.string	"??Vienes a cambiar de BICI?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string	"ANACLETO: ??No hay problema!\n"
	.string	"Te la cambio en un moment??n.$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string	"{PLAYER} cambi?? la BICI CARRERA \n"
	.string	"por la BICI ACROB??TICA.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string	"{PLAYER} cambi?? la BICI ACROB??TICA\n"
	.string	"por la BICI CARRERA.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string	"ANACLETO: Bien, bien.\n"
	.string	"Me alegro de que te guste.$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string	"??Eh? ??Qu?? le ha pasado a la BICI\n"
	.string	"que te he dado?\p"
	.string	"Ah, ya, la has guardado en tu PC.\p"
	.string	"Bueno, pues s??cala de ah??\n"
	.string	"y te la cambiar?? encantado.\p"
	.string	"??Espero que cuando viajes el viento\n"
	.string	"siempre te venga de espalda!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string	"Trabajar aqu?? me est?? ense??ando\n"
	.string	"un mont??n sobre BICIS.\p"
	.string	"Si quieres saber todos los secretos\n"
	.string	"de tu BICI, echa un vistazo\l"
	.string	"a los manuales que hay ah?? detr??s.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string	"Es un manual sobre la BICI CARRERA.\p"
	.string	"??Qu?? cap??tulo quieres leer?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string	"La BICI se mueve en la direcci??n\n"
	.string	"que eliges en el + Panel de Control.\p"
	.string	"Ir?? cogiendo velocidad poco a poco.\p"
	.string	"Para parar, suelta el + Panel de\n"
	.string	"Control. La BICI perder?? velocidad\l"
	.string	"gradualmente hasta detenerse.\p"
	.string	"??Quieres leer otro cap??tulo?$"
	
MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string	"La BICI CARRERA es muy r??pida,\n"
	.string	"pero tarda un poco en detenerse.\p"
	.string	"Doblar las esquinas puede resultar\n"
	.string	"complicado.\p"
	.string	"Suelta el + Panel de Control justo\n"
	.string	"antes de llegar a la esquina para\l"
	.string	"reducir la velocidad.\p"
	.string	"??Quieres leer otro cap??tulo?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string	"Por toda la regi??n de HOENN hay\n"
	.string	"peque??as pendientes arenosas.\p"
	.string	"La consistencia de la arena dificulta\n"
	.string	"la ascensi??n de la pendiente.\p"
	.string	"Sin embargo, si tienes una BICI\n"
	.string	"CARRERA, puedes subir sin problemas.\p"
	.string	"??Quieres leer otro cap??tulo?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string	"Es un manual sobre la BICI ACROB??TICA.\p"
	.string	"??Qu?? cap??tulo quieres leer?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string	"Pulsa el Bot??n B mientras est??s en la\n"
	.string	"BICI para elevar la rueda delantera.\p"
	.string	"Usa el + Panel de Control para dar\n"
	.string	"vueltas con la rueda levantada.\p"
	.string	"Esta t??cnica se llama ???el caballito???.\p"
	.string	"??Quieres leer otro cap??tulo?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string	"Mant??n pulsado el Bot??n B mientras\n"
	.string	"la BICI est?? parada y empezar?? a dar\l"
	.string	"saltos en el sitio.\p"
	.string	"Esta t??cnica se llama ???saltitos???.\p"
	.string	"Si a continuaci??n usas el + Panel de\n"
	.string	"Control, puedes moverte dando saltos.\p"
	.string	"??Quieres leer otro cap??tulo?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string	"Pulsa el Bot??n B y el + Panel de Control\n"
	.string	"al mismo tiempo para saltar.\p"
	.string	"Pulsa el + Panel de Control hacia los\n"
	.string	"lados para dar un salto lateral.\p"
	.string	"P??lsalo hacia arriba o abajo para que\n"
	.string	"la BICI cambie de direcci??n durante\l"
	.string	"el salto.\p"
	.string	"??Quieres leer otro cap??tulo?$"

