#include "Enemy.h"



Enemy::Enemy(const Vector2f& range_, const Vector2f& position, bool vert_ ,const Vector2f &range_size, const Vector2f& range_pos) {

	main.setPosition(position);
	range_a = range_;
	vert = vert_;

	if (vert == true) {
		velocity.x = 0;
		velocity.y = 3;
	}
	else {
		velocity.x = 3;
		velocity.y = 0;
	}

	range.setSize(range_size);
	range.setPosition(range_pos);
	range.setFillColor(Color::Transparent);

	

}

void Enemy::control(Player player) {
	aim.setPosition(main.getPosition());
	aim.setFillColor(Color::Red);

	player_pos = player.main.getPosition();

	current_pos = aim.getPosition();
	if (player.main.getGlobalBounds().intersects(range.getGlobalBounds())&&e_clock_s.getElapsedTime().asSeconds()>0.25) {

					
		if (player_pos.x < current_pos.x && player_pos.y < current_pos.y) {
			shootDir.x = -5  * norm(player_pos, current_pos).x;
			shootDir.y = -5  * norm(player_pos, current_pos).y;
		}
		else
		if (player_pos.x > current_pos.x && player_pos.y < current_pos.y) {
			shootDir.x = 5  * norm(player_pos, current_pos).x;
			shootDir.y = -5 * norm(player_pos, current_pos).y;
		}
		else
		if (player_pos.x < current_pos.x && player_pos.y > current_pos.y) {
			shootDir.x = -5  * norm(player_pos, current_pos).x;
			shootDir.y = 5  * norm(player_pos, current_pos).y;
		}
		else
		if (player_pos.x > current_pos.x && player_pos.y > current_pos.y) {
			shootDir.x = 5  * norm(player_pos, current_pos).x;
			shootDir.y = 5  * norm(player_pos, current_pos).y;
		}
			
		bullets.emplace_back(Bullets(aim.getPosition(), shootDir,main.getPosition()));

		e_clock_s.restart();

	}
	
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].move(bullets[i].velocity);
	}

	for (int i = 0; i < bullets.size(); i++) {

		if (bullets[i].getPosition().x > 700 || bullets[i].getPosition().x < 0 || bullets[i].getPosition().y > 700 || bullets[i].getPosition().y < 0) {
			bullets.erase(bullets.begin() + i);
		}
	}


}


void Enemy::move_() {




	if (vert == false) {

		if (main.getPosition().x < range_a.x) {

			velocity.x = abs(velocity.x);

		}
		if (main.getPosition().x > range_a.y) {

			velocity.x = -abs(velocity.x);

		}

	}
	else {
		if (main.getPosition().y < range_a.x) {

			velocity.y = abs(velocity.y);

		}
		if (main.getPosition().y > range_a.y) {

			velocity.y = -abs(velocity.y);

		}
	}

	main.move(velocity);

}



void Enemy::draw(RenderTarget& target, RenderStates state) const {
	for (int i = 0; i < bullets.size(); i++) {

		target.draw(bullets[i]);
	}
	target.draw(main, state);
	target.draw(aim, state);
	target.draw(range, state);


}






