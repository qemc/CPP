#include "Enemy.h"



Enemy::Enemy() {

	main.setPosition(200, 200);
	

}

void Enemy::control(Player player) {
	aim.setPosition(main.getPosition());
	aim.setFillColor(Color::Red);

	range.setFillColor(Color::Transparent);
	range.setRadius(200);
	range.setOutlineThickness(2);
	range.setOutlineColor(Color::White);
	range.setPosition(main.getPosition());


	if (main.getPosition().x < 201 ) {
		velocity.x = 3;
		velocity.y = 0;
	}
	else if(main.getPosition().x > 600) {
		velocity.x = -3;
		velocity.y = 0;
	}

	main.move(velocity);

	player_pos = player.main.getPosition();

	//Vector2f dirVec_(player_pos.x - main.getPosition().x, player_pos.y - main.getPosition().y);
	//dirVec = dirVec_;

	current_pos = aim.getPosition();
	if (player.main.getGlobalBounds().intersects(range.getGlobalBounds())&&e_clock_s.getElapsedTime().asSeconds()>0.25) {

		


		cout << bullets.size() << endl;

		


					
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

		if (bullets[i].getPosition().x > 800 || bullets[i].getPosition().x < 0 || bullets[i].getPosition().y > 800 || bullets[i].getPosition().y < 0) {
			bullets.erase(bullets.begin() + i);
		}



		//cout << bullets_.size() << endl;

	}


}

void Enemy::draw(RenderTarget& target, RenderStates state) const {
	for (int i = 0; i < bullets.size(); i++) {

		target.draw(bullets[i]);
	}
	target.draw(main, state);
	target.draw(aim, state);
	target.draw(range, state);


}