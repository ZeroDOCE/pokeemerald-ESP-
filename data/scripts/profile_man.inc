ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string	"??Hey, hola!\n"
	.string	"Qu?? sonrisa tan bonita tienes???\p"
	.string	"??Sabes? Mi hobby es coleccionar los\n"
	.string	"perfiles de los ENTRENADORES POK??MON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string	"??Qu?? te parece?\n"
	.string	"??Puedo ver tu perfil?$"

ProfileMan_Text_EasyChatExplanation:
	.string	"Para crear tu perfil, debes unir\n"
	.string	"cuatro palabras o locuciones.\p"
	.string	"Para que te hagas una idea, te voy\n"
	.string	"a mostrar un ejemplo de perfil.\p"
	.string	"Puedes cambiar los cuatro elementos\n"
	.string	"por otras palabras que se ajusten\l"
	.string	"mejor a tu personalidad.\p"
	.string	"Hay un mont??n de locuciones que\n"
	.string	"puedes usar.\p"
	.string	"Est??n agrupadas por categor??as,\n"
	.string	"para que sea m??s f??cil encontrarlas.\p"
	.string	"Primero elige una categor??a para\n"
	.string	"ver todas las opciones disponibles.\p"
	.string	"Despu??s elige la palabra o locuci??n\n"
	.string	"que te convenga.\p"
	.string	"Repite esto hasta tener cuatro y\n"
	.string	"habr??s creado tu propio perfil.$"

ProfileMan_Text_LetsSeeItThen:
	.string	"??Genial! ??Gracias!\n"
	.string	"??Estoy deseando verlo!$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string	"??No? ??En serio?\p"
	.string	"Pensaba que alguien como t?? tendr??a\n"
	.string	"un perfil estupendo???$"

ProfileMan_Text_NotIntoItRightNow:
	.string	"??Y eso? ??No te apetece?\p"
	.string	"??Bueno, pues hazlo cuando te\n"
	.string	"venga mejor!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string	"??Hey, hola!\n"
	.string	"Qu?? sonrisa tan bonita tienes???$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string	"??Puedo ver tu nuevo perfil?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string	"??S??! ??Gracias!\p"
	.string	"Espero que sea a??n mejor que el perfil\n"
	.string	"que me ense??aste la otra vez.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string	"Ah, te gusta tu perfil tal como es???\p"
	.string	"No te culpo, es un gran perfil\n"
	.string	"tal como est?? ahora.$"

ProfileMan_Text_FantasticProfile:
	.string	"??Fant??stico!\p"
	.string	"??Tu perfil es maravilloso!\n"
	.string	"Dice todo sobre ti.\p"
	.string	"Vaya, cualquiera que lo oiga caer??\n"
	.string	"rendido a tus pies.\p"
	.string	"??Gracias!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string	"Oh?\n"
	.string	"You know the secret saying!\p"
	.string	"That means you???re now a fellow member\n"
	.string	"of the MYSTERY EVENT CLUB!$"
