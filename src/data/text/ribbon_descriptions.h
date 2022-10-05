﻿const u8 gRibbonDescriptionPart1_Champion[] = _("CINTA del HALL FAMA");
const u8 gRibbonDescriptionPart2_Champion[] = _("por ganar al CAMPEÓN.");
const u8 gRibbonDescriptionPart1_CoolContest[] = _("CONCURSO CARISMA");
const u8 gRibbonDescriptionPart1_BeautyContest[] = _("CONCURSO BELLEZA");
const u8 gRibbonDescriptionPart1_CuteContest[] = _("CONCURSO DULZURA");
const u8 gRibbonDescriptionPart1_SmartContest[] = _("CONCURSO INGENIO");
const u8 gRibbonDescriptionPart1_ToughContest[] = _("CONCURSO DUREZA");
const u8 gRibbonDescriptionPart2_NormalRank[] = _("Ganador nivel normal.");
const u8 gRibbonDescriptionPart2_SuperRank[] = _("Ganador nivel alto.");
const u8 gRibbonDescriptionPart2_HyperRank[] = _("Ganador nivel avanzado.");
const u8 gRibbonDescriptionPart2_MasterRank[] = _("Ganador nivel experto.");
const u8 gRibbonDescriptionPart1_Winning[] = _("CINTA del NIVEL 50");
const u8 gRibbonDescriptionPart2_Winning[] = _("de TORRE BATALLA.");
const u8 gRibbonDescriptionPart1_Victory[] = _("CINTA del NIVEL LIBRE");
const u8 gRibbonDescriptionPart2_Victory[] = _("de TORRE BATALLA.");
const u8 gRibbonDescriptionPart1_Artist[] = _("CINTA ganada por ser");
const u8 gRibbonDescriptionPart2_Artist[] = _("un modelo a seguir.");
const u8 gRibbonDescriptionPart1_Effort[] = _("CINTA ganada por ser");
const u8 gRibbonDescriptionPart2_Effort[] = _("un buen contrincante.");

const u8 *const gRibbonDescriptionPointers[][2] =
{
    [CHAMPION_RIBBON]      = {gRibbonDescriptionPart1_Champion,      gRibbonDescriptionPart2_Champion},
    [COOL_RIBBON_NORMAL]   = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_NormalRank},
    [COOL_RIBBON_SUPER]    = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_SuperRank},
    [COOL_RIBBON_HYPER]    = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_HyperRank},
    [COOL_RIBBON_MASTER]   = {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_MasterRank},
    [BEAUTY_RIBBON_NORMAL] = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_NormalRank},
    [BEAUTY_RIBBON_SUPER]  = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_SuperRank},
    [BEAUTY_RIBBON_HYPER]  = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_HyperRank},
    [BEAUTY_RIBBON_MASTER] = {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_MasterRank},
    [CUTE_RIBBON_NORMAL]   = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_NormalRank},
    [CUTE_RIBBON_SUPER]    = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_SuperRank},
    [CUTE_RIBBON_HYPER]    = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_HyperRank},
    [CUTE_RIBBON_MASTER]   = {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_MasterRank},
    [SMART_RIBBON_NORMAL]  = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_NormalRank},
    [SMART_RIBBON_SUPER]   = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_SuperRank},
    [SMART_RIBBON_HYPER]   = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_HyperRank},
    [SMART_RIBBON_MASTER]  = {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_MasterRank},
    [TOUGH_RIBBON_NORMAL]  = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_NormalRank},
    [TOUGH_RIBBON_SUPER]   = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_SuperRank},
    [TOUGH_RIBBON_HYPER]   = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_HyperRank},
    [TOUGH_RIBBON_MASTER]  = {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_MasterRank},
    [WINNING_RIBBON]       = {gRibbonDescriptionPart1_Winning,       gRibbonDescriptionPart2_Winning},
    [VICTORY_RIBBON]       = {gRibbonDescriptionPart1_Victory,       gRibbonDescriptionPart2_Victory},
    [ARTIST_RIBBON]        = {gRibbonDescriptionPart1_Artist,        gRibbonDescriptionPart2_Artist},
    [EFFORT_RIBBON]        = {gRibbonDescriptionPart1_Effort,        gRibbonDescriptionPart2_Effort},
};