#include "board.h"
#include "board.cpp"
#include "playout.cpp"

#include <iostream>
#include <cstdlib>

using namespace Hex;

int playouts_number = 100000;

int main(int argc, char* argv[]) {

	if (argc > 1)
		playouts_number = atoi(argv[1]);        

        for (int i = 0; i < 10000; i++) {
                for (uint i = 1; i <= kBoardSize; ++i) {
                        for (uint j = 1; j <= kBoardSize; ++j) {
                                Board board = Board::Empty();
                                uint pos = i * kBoardSizeAligned + j;
                                Location loc = Location(pos);
                                board.PlayLegal(Move(Player::First(), loc));

                                std::cout << loc.ToCoords() << ": starting "
                                        << playouts_number << " random playouts" << std::endl;

                                uint n = Hex::DoPlayouts(board, playouts_number);
                                std::cout << n << " " << playouts_number - n << std::endl;
                        }
                }
        }
	return 0;
}
