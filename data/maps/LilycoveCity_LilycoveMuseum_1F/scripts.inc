.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string	"Hola. Est??s en el MUSEO de CALAGUA.\p"
	.string	"Te rogamos que entres y disfrutes\n"
	.string	"de nuestra extraordinaria colecci??n\l"
	.string	"de arte sobre tem??tica POK??MON.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string	"Soy el DIRECTOR de este MUSEO\n"
	.string	"de Bellas Artes.\p"
	.string	"Me llena de alegr??a ver que alguien tan\n"
	.string	"joven como t?? se interesa por el arte.\p"
	.string	"??Ya has visto nuestra colecci??n\n"
	.string	"de pintura?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string	"Entonces no te molesto m??s.\n"
	.string	"T??mate el tiempo que quieras.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string	"??Ah, s??? Tengo entendido que\n"
	.string	"entrenas POK??MON.\p"
	.string	"??Tambi??n te gusta el arte?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string	"Oh, qu?? pena???\p"
	.string	"En cualquier caso te agradezco que\n"
	.string	"hayas venido a visitar el MUSEO.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string	"??Espl??ndido!\p"
	.string	"En ese caso, ??te importar??a\n"
	.string	"acompa??arme?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string	"??ste es un cuadro muy antiguo.\n"
	.string	"Necesita una buena restauraci??n???$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string	"Plasma un paisaje de tiempos antiguos.\n"
	.string	"La escena es extra??a y misteriosa.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string	"Es un cuadro de una hermosa mujer\n"
	.string	"con un POK??MON en su regazo.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string	"Es una pintura de un POK??MON\n"
	.string	"legendario de tiempos remotos.\p"
	.string	"Es pura creaci??n art??stica.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string	"Es una imagen de unos POK??MON PLANTA\n"
	.string	"que se dejan mecer por una suave brisa.\p"
	.string	"Parecen muy felices.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string	"Plasma un cesto de BAYAS\n"
	.string	"con un aspecto delicioso.\p"
	.string	"??am, ??am, ??qu?? hambre!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string	"Es una r??plica de una escultura\n"
	.string	"muy famosa que representa a\l"
	.string	"un antiguo POK??MON P??JARO.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string	"Es una gran POK?? BALL esculpida\n"
	.string	"en roca bas??ltica.\p"
	.string	"Al parecer se usaba en los festivales\n"
	.string	"que se celebraban antiguamente.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string	"Es una gran losa de piedra cincelada\n"
	.string	"con POK??MON y gran cantidad de\l"
	.string	"peque??os caracteres pertenecientes\l"
	.string	"a un antiguo y desconocido idioma.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string	"Hmmm???\n"
	.string	"What works of great magnificence???$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string	"Combatir con POK??MON es\n"
	.string	"divertido, cierto.\p"
	.string	"Pero no por eso hay que olvidarse\n"
	.string	"de alimentar nuestro esp??ritu\l"
	.string	"contemplando obras de arte.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string	"Este MUSEO de ARTE alberga\n"
	.string	"una gran colecci??n de pintura.\p"
	.string	"Y el DIRECTOR es muy amable.\p"
	.string	"Para los artistas como yo, este MUSEO\n"
	.string	"es una fuente de inspiraci??n.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string	"??Qu?? se??ora tan guapa!\n"
	.string	"??Es casi tan guapa como mam??!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string	"??Qu?? POK??MON tan encantador!\n"
	.string	"??Casi tanto como mi ni??o!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string	"Me han dicho que han ampliado\n"
	.string	"la colecci??n de este MUSEO de ARTE.\p"
	.string	"Por eso he venido a toda m??quina.\p"
	.string	"??Los nuevos cuadros est??n\n"
	.string	"en el primer piso!$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string	"??ltimamente el DIRECTOR\n"
	.string	"est?? m??s contento de lo normal.\p"
	.string	"Seguro que le ha pasado algo\n"
	.string	"muy bueno. Sin duda.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string	"He venido aqu?? a ver muchas grandes\n"
	.string	"obras y aprender de los maestros.\p"
	.string	"Mi sue??o ser??a exponer mis\n"
	.string	"cuadros aqu??.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string	"El MUSEO de ARTE recibe cada vez\n"
	.string	"m??s turistas.\p"
	.string	"Le viene muy bien a CALAGUA.\n"
	.string	"??No, le viene bien a todo HOENN!\p"
	.string	"Y me han dicho que un ENTRENADOR\n"
	.string	"ha sido quien ha conseguido las obras.$"

