MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special GetHipsterSpokenFlag
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string	"Hola, soy el CANJEADOR.\n"
	.string	"??Quieres intercambiar objetos\l"
	.string	"de decoraci??n conmigo?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string	"Ay???\n"
	.string	"Nadie me quiere???$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string	"Un momento??? ??Si t?? y yo ya hemos\n"
	.string	"intercambiado adornos!$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string	"Si entre mis objetos ves alguno\n"
	.string	"que te guste, habla sin miedo.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string	"????Que no quieres nada?!\n"
	.string	"Nadie me quiere???$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string	"Ese objeto de decoraci??n sol??a\n"
	.string	"pertenecer a {STR_VAR_1}.\p"
	.string	"??Lo quieres?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string	"Eh??? Un momento??? ??Si t?? no tienes\n"
	.string	"ni un solo objeto de decoraci??n!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string	"Vale, escoge el adorno que quieres\n"
	.string	"intercambiar conmigo???$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string	"????Que no quieres intercambiar nada?!\n"
	.string	"Nadie me quiere???$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string	"Tienes de esto para aburrir???\n"
	.string	"No te queda sitio para m??s.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string	"Vale, cambiamos mi {STR_VAR_3}\n"
	.string	"por tu {STR_VAR_2}, ??no?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string	"??Pero si est??s usando ese objeto!\n"
	.string	"????C??mo vas a intercambiarlo?!$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string	"??Trato hecho!\n"
	.string	"Te enviar?? el adorno a tu PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string	"??Huy, huy, huy, lo siento!\n"
	.string	"Ese adorno es muy poco com??n.\l"
	.string	"??No lo puedo intercambiar!\p"
	.string	"??No te interesa ninguna otra cosa?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string	"Soy el CUENTALEYENDAS.\n"
	.string	"Te contar?? historias sobre\l"
	.string	"ENTRENADORES legendarios.\p"
	.string	"??Quieres o??r una?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string	"No tienes ninguna consideraci??n???\n"
	.string	"Ay, qu?? sofoco???$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string	"S?? todas estas leyendas.\n"
	.string	"??Cu??l quieres o??r?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string	"El caso es que en realidad no s?? nada\n"
	.string	"sobre ENTRENADORES legendarios, je???\p"
	.string	"Porque ??d??nde se puede encontrar a\n"
	.string	"un ENTRENADOR de leyenda, a ver?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string	"??Andaaa!\n"
	.string	"??T??? ??De verdad?\p"
	.string	"{STR_VAR_2}\n"
	.string	"??Cu??ntas veces? ????{STR_VAR_1}?!\p"
	.string	"??Es magn??fico!\n"
	.string	"??El nacimiento de una leyenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string	"Ahora que lo pienso??? ??Habr?? otros\n"
	.string	"ENTRENADORES con leyendas a??n\l"
	.string	"m??s impresionantes por descubrir?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string	"??T?? entrenas POK??MON?\p"
	.string	"Pues dime, ??tienes alguna historia\n"
	.string	"que suene remotamente legendaria?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally??? Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string	"Mmmm???\n"
	.string	"No me gusta del todo???\p"
	.string	"Espero que puedas contarme pronto\n"
	.string	"algo mucho m??s emocionante que eso???$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string	"Ojal?? que la gente se interese cada\n"
	.string	"vez m??s por o??r mis ??picas historias\l"
	.string	"sobre ENTRENADORES legendarios???$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string	"???El ENTRENADOR guardador???$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string	"Guardaste la partida???$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} guard?? la partida???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"tuviera tanto cuidado como {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string	"???El ENTRENADOR mol??n???$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string	"Creaste tendencias???$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} cre?? modas???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"m??s a la ??ltima que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string	"???El ENTRENADOR plantabayas???$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string	"Plantaste BAYAS???$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} plant?? BAYAS???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"amante de las BAYAS que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string	"???El ENTRENADOR sobre ruedas???$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string	"Cambiaste de BICI???$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} cambi?? de BICI???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"amante de las BICIS que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string	"???El ENTRENADOR estrella???$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string	"Concediste entrevistas???$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"A {STR_VAR_3} le entrevistaron???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"llamara m??s la atenci??n que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string	"???El ENTRENADOR pele??n???$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string	"Entablaste combate???$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} combati?????\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"aceptara m??s combates que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string	"???El ENTRENADOR cazador???$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string	"Atrapaste POK??MON???$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"??{STR_VAR_3} atrap?? {STR_VAR_1} POK??MON!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"cazara tantos POK??MON salvajes\l"
	.string	"como {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string	"???El ENTRENADOR pescador???$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string	"Pescaste POK??MON con CA??A???$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"??{STR_VAR_3} atrap?? {STR_VAR_1} POK??MON\n"
	.string	"pescando!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"manejara mejor la CA??A que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string	"???El ENTRENADOR empoll??n???$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string	"Lograste incubar HUEVOS???$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"??{STR_VAR_3} se hizo con {STR_VAR_1}\n"
	.string	"POK??MON incubando HUEVOS!\p"
	.string	"??Nunca se supo de nadie que rompiera\n"
	.string	"cascarones mejor que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string	"???El ENTRENADOR evolutivo???$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string	"Hiciste evolucionar POK??MON???$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"??{STR_VAR_3} logr?? hacer evolucionar\n"
	.string	"{STR_VAR_1} POK??MON!\p"
	.string	"??Nunca se supo de nadie que supiera\n"
	.string	"m??s de evoluci??n que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string	"???El ENTRENADOR curandero???$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string	"Usaste los CENTROS POK??MON???$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} cur?? POK??MON en los\n"
	.string	"CENTROS POK??MON???\l"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"amante de estos sitios que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string	"???El ENTRENADOR casero???$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string	"Curaste POK??MON en casa???$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} cur?? POK??MON en su casa???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"amante de su hogar que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string	"???El ENTRENADOR aventurero???$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string	"Entraste en la ZONA SAFARI???$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} fue a la ZONA SAFARI???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie con\n"
	.string	"un lado m??s salvaje que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string	"???El ENTRENADOR le??ador???$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string	"Usaste CORTE???$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? CORTE???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"???cortante??? que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string	"???El ENTRENADOR picapedrero???$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string	"Usaste GOLPE ROCA???$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? GOLPE ROCA???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie m??s\n"
	.string	"tritura-rocas que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string	"???El ENTRENADOR n??mada???$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string	"Te mudaste de BASE SECRETA???$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} cambi?? de BASE SECRETA???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"se mudara m??s que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string	"???El ENTRENADOR salpic??n???$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string	"Usaste SALPICADURA???$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? SALPICADURA???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"que salpicara m??s que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string	"???El ENTRENADOR tenaz???$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string	"Usaste COMBATE???$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? COMBATE???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"m??s perseverante que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string	"???El rey de las TRAGAPERRAS???$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string	"Ganaste el premio gordo???$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} gan?? el premio gordo\n"
	.string	"en las TRAGAPERRAS???\l"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie con\n"
	.string	"m??s suerte en el juego que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string	"???El rey de las RULETAS???$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string	"Ganaste en la RULETA???$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"??{STR_VAR_3} gan?? en la RULETA\n"
	.string	"{STR_VAR_1} veces seguidas!\p"
	.string	"??En HOENN nunca se supo de nadie con\n"
	.string	"m??s mano en el juego que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string	"???El palad??n de la TORRE BATALLA???$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string	"Luchaste en la TORRE BATALLA???$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} acept?? el desaf??o de la\n"
	.string	"TORRE BATALLA???\l"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie con m??s\n"
	.string	"esp??ritu de superaci??n que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string	"???El ENTRENADOR licuador???$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string	"Hiciste {POKEBLOCK}S???$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} hizo {POKEBLOCK}S???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie que usara la\n"
	.string	"LICUABAYAS mejor que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string	"???El ENTRENADOR concursante???$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string	"Participaste en los CONCURSOS???$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} particip?? en CONCURSOS???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie con m??s\n"
	.string	"af??n de protagonismo que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string	"???El rey de los CONCURSOS???$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string	"Ganaste en los CONCURSOS???$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} gan?? CONCURSOS???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"se exhibiera mejor que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string	"???El ENTRENADOR consumista???$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string	"Te fuiste de compras???$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} compr?? cosas en tiendas???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"que gastara m??s que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string	"???El ENTRENADOR detective???$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string	"Usaste un BUSCAOBJETOS???$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? un BUSCAOBJETOS???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie que escarbara\n"
	.string	"y hurgara m??s que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string	"???El ENTRENADOR empapado???$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string	"Te cay?? un chaparr??n???$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} se moj?? bajo la lluvia???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie que atrajera\n"
	.string	"m??s nubarrones que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string	"???El lector de POK??DEX???$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string	"Consultaste la POK??DEX???$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} consult?? la POK??DEX???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie m??s amante de\n"
	.string	"las listas de POK??MON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string	"???El coleccionista de CINTAS???$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string	"Recibiste CINTAS???$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} recibi?? CINTAS???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"las coleccionara m??s que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string	"???El ENTRENADOR saltar??n???$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string	"Saltaste los desniveles???$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} salt?? desniveles???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie que\n"
	.string	"saltara m??s y mejor que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string	"???El ENTRENADOR teleadicto???$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string	"Viste la tele???$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} vio la tele???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie m??s amante\n"
	.string	"de la caja tonta que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string	"???El ENTRENADOR relojero???$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string	"Miraste la hora???$"
	
MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} mir?? la hora???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"m??s puntual que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string	"???El rey de la LOTER??A POK??MON???$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string	"Ganaste a la LOTER??A POK??MON???$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} gan?? a la LOTER??A POK??MON???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??Nunca se supo de nadie que cambiara\n"
	.string	"tantos POK??MON como {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string	"???El ENTRENADOR impaciente???$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string	"Dejaste POK??MON en la GUARDER??A???$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} dej?? POK??MON en la\n"
	.string	"GUARDER??A???\l"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"con m??s ambici??n que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string	"???El ENTRENADOR escalador???$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string	"Te montaste en el TELEF??RICO???$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} se mont?? en el TELEF??RICO???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie\n"
	.string	"tan incansable como {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string	"???El ENTRENADOR ba??ista???$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string	"Usaste los ba??os termales???$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string	"??rase una vez {STR_VAR_3}.\p"
	.string	"{STR_VAR_3} us?? los ba??os termales???\n"
	.string	"??Sabes cu??ntas veces? ??{STR_VAR_1}!\p"
	.string	"??En HOENN nunca se supo de nadie con\n"
	.string	"una piel m??s suave que {STR_VAR_3}!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string	"??Soy CHARLAT??N!\n"
	.string	"??Y tengo algo que contarte!\p"
	.string	"??Quieres o??rlo?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string	"Pues vaya???\n"
	.string	"Me has dejado chafado???$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string	"Estaba pensando que???$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string	"Pues eso, estaba pensando que???\p"
	.string	"??Que tendr??amos que seguir\n"
	.string	"charlando otro d??a! ??Hasta lueguito!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string	"Hola, soy el BARDO.\n"
	.string	"??Quieres o??r mi canci??n?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string	"Oh??? Me has dejado m??s\n"
	.string	"triste que el alpiste???$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string	"Es una canci??n tan conmovedora???\n"
	.string	"Podr??a cantarla sin parar???$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string	"??Y????\n"
	.string	"??Te gusta mi canci??n?\p"
	.string	"Pero la letra no me acaba de\n"
	.string	"convencer. Le falta algo???\p"
	.string	"??Querr??as escribir otra letra\n"
	.string	"para m??, por favor?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string	"Oh??? Me has dejado m??s\n"
	.string	"triste que el alpiste???$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string	"??Qu?? inspiraci??n!\n"
	.string	"D??jame que te la cante???$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string	"??Es as?? como quer??as que sonara\n"
	.string	"tu canci??n?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string	"Vale, pues ya est??.\n"
	.string	"Cantar?? esta canci??n un rato.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string	"??Hola! ??Soy el FARD??N!\n"
	.string	"Te voy a ense??ar lo que m??s mola.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string	"Eh, si ya te he ense??ado lo\n"
	.string	"que m??s molaba???\p"
	.string	"??Yo quiero compartir las modas\n"
	.string	"con m??s gente, no s??lo contigo!$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string	"Eh, pero si t?? ya sabes mogoll??n de\n"
	.string	"todo lo que est?? a la ??ltima???\p"
	.string	"??No puedo ense??arte nada!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string	"Eh, ??has o??do hablar de\n"
	.string	"???{STR_VAR_1}????\p"
	.string	"??Que qu?? significa? Si no lo sabes???,\n"
	.string	"??preg??ntaselo a tus amigos!$"
