#include "skatEngine/skatenums.h"
#include "interface/qskatengine.h"

using namespace skatEngine;
QString QSkatEngine::getNameFromEnum(Icard pcard)
{

    ColorType ccol = pcard.first;
    ValueType ctyp = pcard.second;
    QString filename = "";
    if( ctyp == ValueType::BUBE && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuzbube";
    else if( ctyp == ValueType::BUBE && ccol == ColorType::PIK) filename = ":/cardPics/pikbube";
    else if( ctyp == ValueType::BUBE && ccol == ColorType::HERZ) filename = ":/cardPics/herzbube";
    else if( ctyp == ValueType::BUBE && ccol == ColorType::KARO) filename = ":/cardPics/karobube";
    else if( ctyp == ValueType::DAME && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuzdame";
    else if( ctyp == ValueType::DAME && ccol == ColorType::PIK) filename = ":/cardPics/pikdame";
    else if( ctyp == ValueType::DAME && ccol == ColorType::HERZ) filename = ":/cardPics/herzdame";
    else if( ctyp == ValueType::DAME && ccol == ColorType::KARO) filename = ":/cardPics/karodame";
    else if( ctyp == ValueType::KOENIG && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuzkoenig";
    else if( ctyp == ValueType::KOENIG && ccol == ColorType::PIK) filename = ":/cardPics/pikkoenig";
    else if( ctyp == ValueType::KOENIG && ccol == ColorType::HERZ) filename = ":/cardPics/herzkoenig";
    else if( ctyp == ValueType::KOENIG && ccol == ColorType::KARO) filename = ":/cardPics/karokoenig";
    else if( ctyp == ValueType::ASS && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuzass";
    else if( ctyp == ValueType::ASS && ccol == ColorType::PIK) filename = ":/cardPics/pikass";
    else if( ctyp == ValueType::ASS && ccol == ColorType::HERZ) filename = ":/cardPics/herzass";
    else if( ctyp == ValueType::ASS && ccol == ColorType::KARO) filename = ":/cardPics/karoass";
    else if( ctyp == ValueType::SIEBEN && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuz7";
    else if( ctyp == ValueType::SIEBEN && ccol == ColorType::PIK) filename = ":/cardPics/pik7";
    else if( ctyp == ValueType::SIEBEN && ccol == ColorType::HERZ) filename = ":/cardPics/herz7";
    else if( ctyp == ValueType::SIEBEN && ccol == ColorType::KARO) filename = ":/cardPics/karo7";
    else if( ctyp == ValueType::ACHT && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuz8";
    else if( ctyp == ValueType::ACHT && ccol == ColorType::PIK) filename = ":/cardPics/pik8";
    else if( ctyp == ValueType::ACHT && ccol == ColorType::HERZ) filename = ":/cardPics/herz8";
    else if( ctyp == ValueType::ACHT && ccol == ColorType::KARO) filename = ":/cardPics/karo8";
    else if( ctyp == ValueType::NEUN && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuz9";
    else if( ctyp == ValueType::NEUN && ccol == ColorType::PIK) filename = ":/cardPics/pik9";
    else if( ctyp == ValueType::NEUN && ccol == ColorType::HERZ) filename = ":/cardPics/herz9";
    else if( ctyp == ValueType::NEUN && ccol == ColorType::KARO) filename = ":/cardPics/karo9";
    else if( ctyp == ValueType::ZEHN && ccol == ColorType::KREUZ) filename = ":/cardPics/kreuz10";
    else if( ctyp == ValueType::ZEHN && ccol == ColorType::PIK) filename = ":/cardPics/pik10";
    else if( ctyp == ValueType::ZEHN && ccol == ColorType::HERZ) filename = ":/cardPics/herz10";
    else if( ctyp == ValueType::ZEHN && ccol == ColorType::KARO) filename = ":/cardPics/karo10";
    else filename = ":/cardPics/back";

    return filename;
}
