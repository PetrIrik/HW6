#include <sstream>
#include "Card.h"

Card::Card(const Value eValue, const Suit sSuit, const bool bShow)
{
	m_eValue = eValue;
	m_eSuit = sSuit;
	m_bShow = bShow;
}

const Value Card::GetValue() const
{
	return m_eValue;
}
const Suit Card::GetSuit() const
{
	return m_eSuit;
}

const bool Card::GetState() const 
{
	return m_bShow;
}

std::string Card::SuitToString(const Suit eSuit)
{
	switch (eSuit) {
	case Suit::CLUBS:
		return "����";
		break;

	case Suit::DIAMONDS:
		return "�����";
		break;

	case Suit::HEARTS:
		return "������";
		break;

	case Suit::SPADES:
		return "���";
		break;
	}

	return "undefined";
}

std::string Card::ValueToString(const Value eValue)
{
	switch (eValue) {
	case Value::TWO:
		return "������";
		break;

	case Value::THREE:
		return "������";
		break;

	case Value::FOUR:
		return "�������";
		break;

	case Value::FIVE:
		return "������";
		break;

	case Value::SIX:
		return "�������";
		break;

	case Value::SEVEN:
		return "������";
		break;

	case Value::EIGHT:
		return "��������";
		break;

	case Value::NINE:
		return "�������";
		break;

	case Value::TEN:
		return "�������";
		break;

	case Value::JACK:
		return "�����";
		break;

	case Value::QUEEN:
		return "����";
		break;

	case Value::KING:
		return "������";
		break;

	case Value::ACE:
		return "���";
		break;
	}

	return "undefined";
}

int Card::ValueToScore(const Value eValue)
{
	switch (eValue)
	{
	case Value::TEN:
	case Value::JACK:
	case Value::QUEEN:
	case Value::KING:
		return 10;
		break;

	case Value::ACE:
		return 11;
		break;
	}

	return static_cast<int>(eValue);
}

const std::string Card::toString() const
{
	return Card::ValueToString(m_eValue) + ' ' + Card::SuitToString(m_eSuit);
}


void Card::Filp() {
	m_bShow = !m_bShow;
}

std::ostream& operator<< (std::ostream& out, const Card& c) {
	return out << (c.GetState() ? c.toString() : "XX");
}