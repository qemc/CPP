#include "CustomRectangleShape.h"


void CustomRectangleShape::set_speed() {

	velocity.x = velocity_x;
	velocity.y = velocity_y;

}


void CustomRectangleShape::randomize_move_dir() {

	srand(time(NULL));




	
	int x_dir = float(rand() % 100);
	int y_dir = float(rand() % 100);

	if (x_dir %2 == 0) {
		velocity.x = -abs(velocity.x);
	}
	else {
		velocity.x = velocity.x;
	}

	if (x_dir % 2 != 0) {
		velocity.y = -abs(velocity.y);
	}
	else {
		velocity.y = velocity.y;
		
	}


	

}

Vector3i CustomRectangleShape::randomize_color() {

	srand(time(NULL));

	int r = (rand() % 255) + 1;
	int g = (rand() % 255) + 1;
	int b = (rand() % 255) + 1;

	return Vector3i(r, g, b);


}

void CustomRectangleShape::animate() {

	

	if (getPosition().x + getGlobalBounds().width / 2 >= 1000) {
		velocity.x = -abs(velocity.x);
		setFillColor(Color(
			randomize_color().x,
			randomize_color().y,
			randomize_color().z)
		);
	}

	if (getPosition().x - getGlobalBounds().width / 2 <= 0) {
		velocity.x = abs(velocity.x);
		setFillColor(Color(
			randomize_color().x,
			randomize_color().y,
			randomize_color().z)
		);
	}
	if (getPosition().y + getGlobalBounds().height / 2 >= 1000) {
		velocity.y = -abs(velocity.y);
		setFillColor(Color(
			randomize_color().x,
			randomize_color().y,
			randomize_color().z)
		);
	}
	if (getPosition().y - getGlobalBounds().height / 2 <= 0) {
		velocity.y = abs(velocity.y);
		setFillColor(Color(
			randomize_color().x,
			randomize_color().y,
			randomize_color().z)
		);
	}




}

CustomRectangleShape::CustomRectangleShape(const Vector2f& size, const Vector2f& position) {

	setPosition(position);
	setSize(size);
	setFillColor(Color::Red);
	setOrigin(size.x / 2, size.y / 2);

	

}


void CustomRectangleShape::select() {
	if (getGlobalBounds().contains(get_mouse_pos) && Mouse::isButtonPressed(Mouse::Left)&& is_selected == false) {
		is_selected = true;
		setFillColor(Color::Red);

		



	}

	if (is_selected == true) {
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			velocity.x = -abs(velocity_x)*2;
			velocity.y = 0;
			animate();
			move(velocity);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			velocity.x = abs(velocity_x)*2;
			velocity.y = 0;
			animate();
			move(velocity);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			velocity.y = -abs(velocity_y)*2;
			velocity.x = 0;
			animate();
			move(velocity);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
			velocity.y = abs(velocity_y) * 2;
			velocity.x = 0;
			animate();
			move(velocity);
		}
		
		
	}
	
	

}

void CustomRectangleShape::unselect() {
	if (getGlobalBounds().contains(get_mouse_pos) && Mouse::isButtonPressed(Mouse::Right) && is_selected == true) {
		is_selected = false;
		setFillColor(Color::Magenta);

	}

	if (is_selected == false) {
		move(velocity);
		rotate(1);
	}


	

}



//void CustomRectangleShape::catch_rtc() {
//
//	if (getGlobalBounds().contains(Mouse::getPosition())) {
//
//
//	
//		break;
//	}
//
//
//
//}
