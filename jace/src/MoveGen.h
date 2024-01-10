#pragma once

#include <vector>
#include <bit>
#include <Board.h>


struct Move {
	Move() = default;
	Move(uint8_t _from, uint8_t _to, uint8_t _flags, Piece _piece) : from(_from), to(_to), flags(_flags), piece(_piece) {};
	uint8_t from, to, flags;
	Piece piece;
};

void GenPawnMoves(Board& _board, std::vector<Move>& _moves) {
	uint64_t us = _board[_board.stm()];
	uint64_t them = _board[Color(!_board.stm())];
	uint64_t pawns = _board[Pawn] & us;

	uint64_t empty = ~(us | them);

	uint64_t singleMoves = pawns & (empty >> 8);
	uint64_t doubleMoves = singleMoves & (empty >> 16) & 0xff00;

	uint64_t leftMoves = pawns & ((them & 0x7f7f7f7f7f7f0000) >> 7);
	uint64_t rightMoves = pawns & ((them & 0xfefefefefefe0000) >> 9);

	while (singleMoves) {
		int bit = std::countr_zero(singleMoves);
		_moves.push_back(Move(bit, bit + 8, 0, Pawn));
		singleMoves &= singleMoves - 1;
	}
	while (doubleMoves) {
		int bit = std::countr_zero(doubleMoves);
		_moves.push_back(Move(bit, bit + 16, 0, Pawn));
		doubleMoves &= doubleMoves - 1;
	}
	while (leftMoves) {
		int bit = std::countr_zero(leftMoves);
		_moves.push_back(Move(bit, bit + 7, 0, Pawn));
		leftMoves &= leftMoves - 1;
	}
	while (rightMoves) {
		int bit = std::countr_zero(rightMoves);
		_moves.push_back(Move(bit, bit + 9, 0, Pawn));
		rightMoves &= rightMoves - 1;
	}

}
void GenKnightMoves(Board& _board, std::vector<Move>& _moves) {
	uint64_t us = _board[_board.stm()];
	uint64_t them = _board[Color(!_board.stm())];
	uint64_t knights = _board[Knight] & us;

	uint64_t empty = ~(us | them);

	while (knights) {
		int bit = std::countr_zero(knights);
		uint64_t knight = 1 >> bit;
		knights &= knights - 1;
	}
}