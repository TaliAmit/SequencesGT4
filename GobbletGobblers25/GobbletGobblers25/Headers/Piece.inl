

template<typename T>
inline Piece<T>::Piece(T identifier)
: m_identifier{ identifier }
{
}

template<typename T>
inline T Piece<T>::getIdentifier() const
{
    return m_identifier;
}

template<typename T>
inline void Piece<T>::setIdentifier(T identifier)
{
    m_identifier = identifier;
}