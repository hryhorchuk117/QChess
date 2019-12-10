//
// Created by ivan on 10.12.19.
//

#include "MoveNotation.h"

MoveNotation::MoveNotation(Move move, bool check, bool checkmate, bool capture, int castle) :_move(move), _check(check),
                                                            _checkmate(checkmate), _capture(capture), _castle(castle) {}

char chessVertical(int n){
    return char('a' + n);
}

char chessFigureNotation(Figure* fg){
    if (typeid(*fg).name() == typeid(Knight).name())
        return 'N';
    if (typeid(*fg).name() == typeid(Bishop).name())
        return 'B';
    if (typeid(*fg).name() == typeid(Rook).name())
        return 'R';
    if (typeid(*fg).name() == typeid(Queen).name())
        return 'Q';
    return 'i';
}

std::string MoveNotation::getNotation() {
    if (_castle == 1)
        return "0-0";
    if (_castle == 2)
        return "0-0-0";
    std::string begining = "";
    if (typeid(*_move.getFigure()).name() == typeid(Pawn).name()){
        if (_capture)
            begining = chessVertical(_move.getBegin().first) + '-' + chessVertical(_move.getEnd().first);
        else
            begining = chessCoordinates(_move.getEnd());
    }
    else {
        begining = chessFigureNotation(_move.getFigure());
        if (_capture)
            begining += 'x';
        begining += chessCoordinates(_move.getEnd());
    }
    if (_checkmate)
        begining += '#';
    else if (_check)
        begining += '+';
    return begining;
}
