.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string	"Cada d??a es tan duro???\p"
	.string	"??Que qu?? es duro?\n"
	.string	"??Hace falta preguntar?\p"
	.string	"Pues levantarse para ir\n"
	.string	"a trabajar, claro.\p"
	.string	"Llevo fatal lo de madrugar???$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string	"??Anda, hola!\n"
	.string	"??Te doy la bienvenida a mi casa!\p"
	.string	"Una preguntilla??? ??Has\n"
	.string	"hecho de canguro alguna vez?\p"
	.string	"Ver??s, acabo de ser padre y lo\n"
	.string	"cierto es que estoy algo perdido.\p"
	.string	"Ahora tengo un problemilla???\n"
	.string	"Mi hija ANAPEL se r??e muy poco.\p"
	.string	"Creo que se reir??a m??s\n"
	.string	"si le dijera algo divertido.\p"
	.string	"??No sabr??s alguna expresi??n\n"
	.string	"graciosa, por casualidad?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string	"He estado diciendo ???{STR_VAR_1}???\n"
	.string	"a ANAPEL para divertirla.\p"
	.string	"??No sabr??s de alguna otra expresi??n\n"
	.string	"que tenga m??s gracia?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string	"??Vaya, qu?? bien!\n"
	.string	"??Y cu??l es?$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string	"Oh, ??en serio?\p"
	.string	"Bueno, pues, si se te ocurre\n"
	.string	"algo, soy todo o??dos.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string	"Ah, ya veo.\n"
	.string	"Pues vamos a o??rla, ??vale?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string	"{STR_VAR_1}.\n"
	.string	"{STR_VAR_1}.\p"
	.string	"??Genial! ??????Se r??e!!!\n"
	.string	"??Qu?? contento que estoy!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string	"Ah, ya veo.\n"
	.string	"Pues vamos a o??rla, ??vale?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string	"{STR_VAR_1}.\n"
	.string	"{STR_VAR_1}.\p"
	.string	"Mmmm??? No le hace ni pizca de gracia.\n"
	.string	"Puede que ANAPEL sea una ni??a seria???$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string	"As?? que no se te ocurre nada.\n"
	.string	"Pues a ver si yo pienso algo???\p"
	.string	"Mmm???\n"
	.string	"??Qu?? tal ???{STR_VAR_1}????\l"
	.string	"A ver si funciona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string	"{STR_VAR_1}.\n"
	.string	"{STR_VAR_1}.\p"
	.string	"Mmmm??? No le hace ni pizca de gracia.\n"
	.string	"Puede que ANAPEL sea una ni??a seria???$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string	"As?? que no se te ocurre nada.\n"
	.string	"Pues entonces voy a intentar\l"
	.string	"hacerle re??r con lo que dije antes.\p"
	.string	"Pero, si tuvieras alguna sugerencia,\n"
	.string	"no dudes en dec??rmelo, ??vale?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string	"??Gracias!\p"
	.string	"Much??simas gracias. ??Mi querida\n"
	.string	"ANAPEL se est?? riendo!\p"
	.string	"??Y sabes qu??? No lo parecer??,\n"
	.string	"pero soy uno de los principales\l"
	.string	"investigadores de DEVON S.A.\p"
	.string	"Y me gustar??a hacer algo\n"
	.string	"por ti, pero no s?? qu?????\p"
	.string	"Ya s??, te dar?? m??s dise??os de papel\n"
	.string	"pintado para las CAJAS del Sistema de\l"
	.string	"Almacenamiento de POK??MON del PC.\p"
	.string	"S??lo tendr??s que elegir ???AMIGOS???\n"
	.string	"en el men?? correspondiente. \p"
	.string	"De esa manera podr??s acceder\n"
	.string	"a los nuevos dise??os de papel pintado.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string	"??Es un MU??ECO de peluche\n"
	.string	"con forma de POK??MON!$"

