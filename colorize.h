#ifndef COLORIZE_H
#define COLORIZE_H
#include <QString>
#include "Qsci/qscilexer.h"

class Colorize
{
public:
    Colorize();
    static QsciLexer* getLexer(QString language);
};

#endif // COLORIZE_H
