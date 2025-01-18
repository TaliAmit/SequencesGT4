//#include "Player.h"

template<typename T>
inline Player<T>::Player(PlayerType playerType, T playerIdentfier)
	: m_playerType(playerType)
	, m_playerIdentifier(playerIdentfier)
{
}

template<typename T>
inline PlayerType Player<T>::getType() const
{
	return m_playerType;
}

template<typename T>
inline void Player<T>::setType(PlayerType type)
{
	m_playerType = type;
}

template<typename T>
inline T Player<T>::getIdentifier() const
{
	return m_playerIdentifier;
}

template<typename T>
inline void Player<T>::setIdentifier(T playerIdentifier)
{
	m_playerIdentifier = playerIdentifier;
}