#include "colorize.h"
#include "LexersHeader.h"
#include <Qsci/qscilexercustom.h>

Colorize::Colorize()
{
}

QsciLexer* Colorize::getLexer(QString language)
{
    QsciLexer *lexer = 0;
    if(language == "Bash")
        lexer = new QsciLexerBash;
    if(language == "Batch")
        lexer = new QsciLexerBatch;
    if(language == "CMake")
        lexer = new QsciLexerCMake;
    if(language == "C/C++")
        lexer = new QsciLexerCPP;
    if(language == "C#")
        lexer = new QsciLexerCSharp;
    if(language == "CSS")
        lexer = new QsciLexerCSS;
    if(language == "D")
        lexer = new QsciLexerD;
    if(language == "Diff")
        lexer = new QsciLexerDiff;
    if(language == "Fortran")
        lexer = new QsciLexerFortran;
    if(language == "Fortran77")
        lexer = new QsciLexerFortran77;
    if(language == "HTML" || language == "PHP")
        lexer = new QsciLexerHTML;
    if(language == "IDL")
        lexer = new QsciLexerIDL;
    if(language == "Java")
        lexer = new QsciLexerJava;
    if(language == "JavaScript")
        lexer = new QsciLexerJavaScript;
    if(language == "Lua")
        lexer = new QsciLexerLua;
    if(language == "Makefile")
        lexer = new QsciLexerMakefile;
    if(language == "Pascal")
        lexer = new QsciLexerPascal;
    if(language == "Perl")
        lexer = new QsciLexerPerl;
    if(language == "PostScript")
        lexer = new QsciLexerPostScript;
    if(language == "POV")
        lexer = new QsciLexerPOV;
    if(language == "Properties")
        lexer = new QsciLexerProperties;
    if(language == "Python")
        lexer = new QsciLexerPython;
    if(language == "Ruby")
        lexer = new QsciLexerRuby;
    if(language == "Spice")
        lexer = new QsciLexerSpice;
    if(language == "SQL")
        lexer = new QsciLexerSQL;
    if(language == "Tcl")
        lexer = new QsciLexerTCL;
    if(language == "Tex")
        lexer = new QsciLexerTeX;
    if(language == "VeriLog")
        lexer = new QsciLexerVerilog;
    if(language == "VHDL")
        lexer = new QsciLexerVHDL;
    if(language == "XML")
        lexer = new QsciLexerXML;
    if(language == "YAML")
        lexer = new QsciLexerYAML;


    return lexer;
}
