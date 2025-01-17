#pragma once

// TODO: Consider constraining the template type to specific identifier types only 
template<typename T>
class Piece
{
public:
    explicit Piece(T identifier);

    /**
    * @brief Gets the identifier of the Piece.
    * @return The current identifier of the Piece (T type).
    */
    T getIdentifier() const;

    /**
     * @brief Sets the identifier of the Piece.
     * @param identifier The identifier to set for the Piece (T type).
     */
    void setIdentifier(T identifier);

private:
    T m_identifier;
};

#include "Piece.inl"