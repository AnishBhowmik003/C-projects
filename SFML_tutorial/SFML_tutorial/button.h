#ifndef _BUTTON_H
#define _BUTTON_H

#include <SFML/Graphics.hpp>

class button :
	public sf::Drawable
{
public:
	button();
	button(sf::Vector2f size, sf::Vector2f pos);

	bool pollEvent(sf::Event event);
	void updatePointers();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::Vector2f m_size;
	sf::Vector2f m_pos;

	sf::RectangleShape m_back;
	sf::Text m_text;
	sf::Font m_font;
};

void button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_back, states);
	target.draw(m_text, states);
}

button::button(sf::Vector2f size, sf::Vector2f pos) {
	m_pos = pos;
	m_size = size;

	m_back = sf::RectangleShape(m_size);
	m_text = sf::Text();
	m_font = sf::Font();
}

bool button::pollEvent(sf::Event event)
{
	bool val = false;

	if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == sf::Mouse::Left)
			if (m_back.getGlobalBounds().contains(sf::Vector2f(
				event.mouseButton.x,
				event.mouseButton.y
				)))
				val = true;

	return val;
}

void button::updatePointers()
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_text.setFont(m_font);
	m_text.setString("Allah");
	m_text.setFillColor(sf::Color::Black);
}

#endif