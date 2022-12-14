.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string	"Buenos d??as. Est??s en DEVON S.A.\p"
	.string	"Somos los orgullosos fabricantes\n"
	.string	"de miles de objetos y medicinas\l"
	.string	"que hacen la vida m??s f??cil.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string	"Uno de nuestros cient??ficos se ha\n"
	.string	"dejado robar un paquete de lo m??s\l"
	.string	"importante.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string	"Eh, esas DEPORTIVAS las hemos\n"
	.string	"fabricado nosotros.\p"
	.string	"??Siempre es un placer ver a uno\n"
	.string	"de nuestros clientes!$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string	"Ese paquete que han robado???\p"
	.string	"es muy importante, cierto, pero no es\n"
	.string	"algo que pueda usar cualquiera.\p"
	.string	"En mi opini??n, ese ladr??n no era\n"
	.string	"muy listo que digamos???$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string	"Parece que alguien ha recuperado\n"
	.string	"las PIEZAS DEVON que robaron.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string	"Lo siento, s??lo el personal autorizado\n"
	.string	"puede entrar aqu??.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string	"??C??mo hemos podido ser tan tontos????\n"
	.string	"????C??mo nos hemos dejado robar?!$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string	"??Anda, hola!\n"
	.string	"??Tenerte aqu?? es siempre un placer!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string	"En la urna de cristal se exponen\n"
	.string	"muestras de rocas y metales.\p"
	.string	"Hay un cartel con algo escrito???\p"
	.string	"???DEVON S.A. se dedicaba en sus\n"
	.string	"inicios a extraer rocas de canteras.???\p"
	.string	"???Tambi??n produc??a hierro a partir de\n"
	.string	"las limaduras que hab??a en la arena.???\p"
	.string	"???A pesar de tan humildes or??genes,\n"
	.string	"DEVON logr?? crecer como empresa.???\p"
	.string	"???DEVON fabrica en la actualidad una\n"
	.string	"amplia gama de productos industriales.???$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string	"En la urna de cristal se exponen\n"
	.string	"prototipos y productos de prueba.\p"
	.string	"Hay un cartel con algo escrito???\p"
	.string	"???Adem??s de productos industriales,\n"
	.string	"DEVON comercializa art??culos varios\l"
	.string	"e incluso productos farmac??uticos.???\p"
	.string	"???Desde hace poco, DEVON tambi??n vende\n"
	.string	"art??culos para ENTRENADORES POK??MON,\l"
	.string	"como POK?? BALLS y POK??NAVEGADORES.???$"

