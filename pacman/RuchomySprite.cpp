#include "RuchomySprite.h"
void RuchomySprite::animuj(const Vector2f& velocity) {

	move(velocity);


	if (getPosition().x - getGlobalBounds().width >= 800) {
		setPosition(0, getPosition().y);
	}

	if (getPosition().x + getGlobalBounds().height <= 0) {
		setPosition(800, getPosition().y);

	}
	if (getPosition().y - getGlobalBounds().height >= 800) {
		setPosition(getPosition().x, 0);
	}
	if (getPosition().y + getGlobalBounds().height <= 0) {
		setPosition(getPosition().x, 800);
	}
}