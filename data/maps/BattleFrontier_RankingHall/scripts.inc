BattleFrontier_RankingHall_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_DomeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PikeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ShowRecords::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall:
	.string	"??ste es el archiconocido\n"
	.string	"HALL de las CLASIFICACIONES.\p"
	.string	"Aqu?? es donde inmortalizamos a los\n"
	.string	"ENTRENADORES que dejan r??cords\l"
	.string	"inolvidables en el FRENTE de BATALLA.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords:
	.string	"R??cords de la C??PULA BATALLA, la\n"
	.string	"SIERPE BATALLA y la F??BRICA BATALLA.$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords:
	.string	"R??cords del PALACIO BATALLA,\n"
	.string	"el DOJO BATALLA y la PIR??MIDE BATALLA.$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList:
	.string	"Oye, ??est??s t?? en esta lista?$"

BattleFrontier_RankingHall_Text_WowThatsSuper:
	.string	"??Guau! ??Impresionante!\n"
	.string	"??Tendr?? que tom??rmelo m??s en serio!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName:
	.string	"Pues ya somos dos.\p"
	.string	"??Seguro que luchar??as con m??s ganas si\n"
	.string	"vieras aqu?? el nombre de un amigo tuyo!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere:
	.string	"Mmm???\n"
	.string	"Aqu?? no est?? mi nombre???\p"
	.string	"Pero, vamos, es normal porque a??n no he\n"
	.string	"participado en ning??n combate, je, je.$"

