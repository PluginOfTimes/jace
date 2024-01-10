#pragma once

#include <cstdint>


class Board {
public:
	Board() = default;
	~Board() = default;

	uint64_t operator[] (Color _c) { return m_Color[_c]; }
	uint64_t operator[] (Piece _p) { return m_Piece[_p]; }
	Color& stm() { return m_Stm; }

private:
	uint64_t m_Color[2] // [white, black]
	{
		0xffff,
		0xffff000000000000
	};
	uint64_t m_Piece[6] // [pawn, knight, bishop, rook, queen, king]
	{
		0x00ff00000000ff00,
		0x4200000000000042,
		0x2400000000000024,
		0x8100000000000081,
		0x0800000000000008,
		0x1000000000000010
	};
	Color m_Stm = Color(0);
};

enum Color: uint8_t {
	White,
	Black
};

enum Piece: uint8_t {
	Pawn,
	Knight,
	Bishop,
	Rook,
	Queen,
	King
};