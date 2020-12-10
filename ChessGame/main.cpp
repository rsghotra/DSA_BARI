#include<iostream>
using namespace std;

enum PieceType {
    None, Pawn, King, Queen, Knight, Bishop, Rook
};

enum PieceColor {
    White, Black
};

struct Piece {
    PieceType Type;
    PieceColor Color;
};

class Square {
    public:
        int X;
        int Y;
};

//Finally we have to compose Move, board
// and finally Game


class Board {
     public:
        Square squareSet[8][8];
        Piece pieceSet[]


}
