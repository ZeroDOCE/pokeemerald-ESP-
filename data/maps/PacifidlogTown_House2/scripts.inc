PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string	"Soy la persona m??s importante del CLUB\n"
	.string	"de FANS de POK??MON: el hermano menor\l"
	.string	"de nuestro PRESIDENTE.\p"
	.string	"Estoy aqu?? disfrutando de unas\n"
	.string	"merecidas vacaciones con mis POK??MON.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string	"??Ah!\n"
	.string	"Tu POK??MON???$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string	"te quiere mucho. Salta a la vista.\p"
	.string	"Un POK??MON tan cari??oso y adorable\n"
	.string	"se merece una MT como ??sta, ??no?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string	"Mmmm???\n"
	.string	"No est?? mal, pero tampoco muy bien.\p"
	.string	"Tendr??as que esforzarte un\n"
	.string	"poco m??s, ??no te parece?$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string	"tiene una mirada que da miedo.\p"
	.string	"Un POK??MON terror??fico como ??ste\n"
	.string	"se merece una MT como ??sta.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string	"Si un POK??MON te quiere mucho,\n"
	.string	"el poder de RETROCESO se potencia.\p"
	.string	"Si no te quiere, el poder de\n"
	.string	"FRUSTRACI??N es el que aumenta.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string	"Ah, s??. En {STR_VAR_1} d??as o as??,\n"
	.string	"recibir?? un par de MT flipantes.\p"
	.string	"Deber??as venir a verme entonces.\n"
	.string	"Te dar?? la MT que convenga mejor\l"
	.string	"a tu POK??MON.$"

PacifidlogTown_House2_Text_Rurii:
	.string	"AZURILL: Azu, azuriril???$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string	"Parece que se lleva muy bien\n"
	.string	"con su ENTRENADOR.$"

PacifidlogTown_House2_Text_Rururi:
	.string	"AZURILL: Azuz??, azuzuz?????$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string	"Parece que no se lleva muy bien\n"
	.string	"con su ENTRENADOR.$"

