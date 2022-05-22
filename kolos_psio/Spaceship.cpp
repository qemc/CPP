#include "Spaceship.h"
#include "Fly.h"

Vector2f normalize(const Vector2f& x, const Vector2f& y) {

	Vector2f all(abs(x.x - y.x), abs(x.y - y.y));


	float sqr = sqrt(((y.x - x.x) * (y.x - x.x)) + (y.y - x.y) * (y.y - x.y));

	return Vector2f(all.x / sqr, all.y / sqr);


}


Spaceship::Spaceship(const Texture& texture) {

	setTexture(texture);
	setScale(0.125, 0.125);
	setOrigin(32, 32);
	setPosition(380, 380);
}

void Spaceship::colision() {


	if (getPosition().x >= 800) {
		setPosition(0, getPosition().y);
	}

	if (getPosition().x + getGlobalBounds().height <= 0) {
		setPosition(800, getPosition().y);

	}
	if (getPosition().y >= 800) {
		setPosition(getPosition().x, 0);
	}
	if (getPosition().y + getGlobalBounds().height <= 0) {
		setPosition(getPosition().x, 800);
	}


}



void Spaceship::move_(){
	if (rusz == true) {

		if (mouse_pos.x < getPosition().x && mouse_pos.y < getPosition().y) {
			move(movement);
			movement.x = -500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).x;
			movement.y = -500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).y;

		}
		else
		if (mouse_pos.x > getPosition().x && mouse_pos.y < getPosition().y) {
			move(movement);
			movement.x = 500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).x;
			movement.y = -500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).y;
		}
		else
		if (mouse_pos.x < getPosition().x && mouse_pos.y > getPosition().y) {
			move(movement);
			movement.x = -500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).x;
			movement.y = 500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).y;

		}
		else
		if (mouse_pos.x > getPosition().x && mouse_pos.y > getPosition().y) {
			move(movement);
			movement.x = 500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).x;
			movement.y = 500 * AnimatedSprite::a_time.asSeconds() * normalize(mouse_pos, getPosition()).y;
		}
	}

		
}

bool Spaceship::rectangle_collisiotn(const RectangleShape& rectangle) {

	if (getGlobalBounds().intersects(rectangle.getGlobalBounds())) {
		points++;
		return true;
	}
	return false;
}
