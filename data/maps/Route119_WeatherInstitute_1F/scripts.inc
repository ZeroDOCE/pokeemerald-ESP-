.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string	"El JEFE est?? interesado en la\n"
	.string	"investigaci??n que est??n realizando\l"
	.string	"aqu??, por eso nos ha enviado.\p"
	.string	"??Qu??tate de en medio!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string	"No me lo creo???\n"
	.string	"Me has vencido, mequetrefe???$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string	"No hay nada que nuestro\n"
	.string	"JEFE no sepa???\p"
	.string	"Pero yo s??lo soy un SOLDADO. ??C??mo\n"
	.string	"voy a saber lo que tiene en mente?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string	"??Eh?\n"
	.string	"??Qu?? haces t?? aqu???$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string	"??Yo?\n"
	.string	"??He perdido? ????Yo?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string	"Oh, no???\n"
	.string	"Qu?? bronca me va a caer???\p"
	.string	"Creo que voy a echarme una siesta\n"
	.string	"para olvidar todo esto???$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string	"??Mientras dorm??a, alguien se col??\n"
	.string	"arriba!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string	"??Guau, qu?? fuerte eres!\p"
	.string	"??Ojal?? pudiera ser un ENTRENADOR\n"
	.string	"POK??MON tan bueno como t??!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string	"Al PROFESOR le encanta la lluvia.\n"
	.string	"Eso es un hecho.\p"
	.string	"Pero si sigue lloviendo as??, tendremos\n"
	.string	"problemas. Eso tambi??n es un hecho.\p"
	.string	"Por eso el PROFESOR est?? estudiando\n"
	.string	"c??mo hacer buen uso de esta lluvia.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string	"En el primer piso del INSTITUTO\n"
	.string	"estudiamos los fen??menos atmosf??ricos\l"
	.string	"de la regi??n de HOENN.\p"
	.string	"??ltimamente, estamos detectando casos\n"
	.string	"aislados de sequ??a e inundaciones???$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string	"??Hola!\n"
	.string	"??Nos has salvado!\p"
	.string	"Lo que no logro entender es lo que\n"
	.string	"pretenden los del EQUIPO AQUA???$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string	"Mira, una cama???\n"
	.string	"??A descansar!$"

