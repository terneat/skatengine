#ifndef SKATENUMS_H
#define SKATENUMS_H

#include <utility>

namespace skatEngine
{

enum class ColorType {NO, KARO, HERZ, PIK, KREUZ};
enum class ValueType  {NO, SIEBEN, ACHT, NEUN, BUBE, DAME, KOENIG, ZEHN, ASS};
enum class GameType {UNDEFINED, NULLS, KARO, HERZ, PIK, KREUZ, GRAND};
enum class PlayerType {HUMAN, CPU};

enum class GameStage {INITIALIZED, PLAYING_ROUND, FINSIHED, PAUSED};
enum class RoundStage {REIZEN, PLAYING, FINSISHED};

typedef std::pair<skatEngine::ColorType, skatEngine::ValueType> Icard;
}

#endif // SKATENUMS_H

