/* 
 * File:   swap.h
 * Author: kd
 *
 * Created on 13 styczeń 2010, 14:30
 */

#ifndef _SWAP_H
#define	_SWAP_H

#include "board.h"

#define SWAP 10000

namespace Hex {

    namespace {
        const bool _swap[] = {
            //  a  b  c  d  e  f  g  h  i  j  k
                0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, // 1
                 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, // 2
                  0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, // 3
                   0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, // 4
                    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, // 5
                     0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, // 6
                      0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, // 7
                       0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, // 8
                        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, // 9
                         1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, // 10
                          1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 11
        };
    }

    class Swap {
        
    public:
        static bool ShouldSwap (const Location& loc) {
            uint x, y;
            Location::ToCoords(loc.GetPos(), x, y);
            x--;
            y--;
            return _swap[y * kBoardSize + x];
        }
    };

}


#endif	/* _SWAP_H */

