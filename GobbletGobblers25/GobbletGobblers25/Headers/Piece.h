#pragma once

// TODO: Consider constraining the template type to specific identifier types only 
template<typename T>
class Piece
{
public:
    explicit Piece(T identifier);

    T getIdentifier() const;
    void setIdentifier(T identifier);

private:
    T m_identifier;
};

#include "../Details/Piece.inl"