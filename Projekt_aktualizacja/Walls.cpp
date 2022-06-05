#include "Walls.h"



Walls::Walls(const Vector2f& position, const Vector2f& size) {


	setSize(size);
	setPosition(position);
	Color color(255, 0, 0);
	setFillColor(Color::Green);
	
	






}



void Walls::collision(Player &player) {
	
	

				this->playerBounds = player.main.getGlobalBounds();
				this->playerBounds.left = playerBounds.left + playerBounds.width / 2;
				this->playerBounds.top = playerBounds.top + playerBounds.height / 2;
				this->rectangleBounds = this->getGlobalBounds();

				//bottom

				//cout << "w: " << player.main.getGlobalBounds().width << "h: " << player.main.getGlobalBounds().height << "t: " << player.main.getGlobalBounds().top << " l: " << player.main.getGlobalBounds().left << endl;
				
				if (playerBounds.top  < rectangleBounds.top 
					&& playerBounds.top + playerBounds.height < rectangleBounds.top + rectangleBounds.height
					&& playerBounds.left< rectangleBounds.left + rectangleBounds.width
					&& playerBounds.left + playerBounds.width>rectangleBounds.left) {

					player.velocity.y = 0.f;
					player.velocity.x = 0.f;
					player.main.setPosition(playerBounds.left, rectangleBounds.top - playerBounds.height/2);
				}
				//top
				if (playerBounds.top > rectangleBounds.top
					&& playerBounds.top + playerBounds.height > rectangleBounds.top + rectangleBounds.height
					&& playerBounds.left<rectangleBounds.left + rectangleBounds.width
					&& playerBounds.left + playerBounds.width>rectangleBounds.left) {

					player.velocity.y = 0.f;
					player.velocity.x = 0.f;
					player.main.setPosition(playerBounds.left, rectangleBounds.top + rectangleBounds.height + playerBounds.height / 2);
				}
				//right
				if (playerBounds.left < rectangleBounds.left
					&& playerBounds.left + playerBounds.width < rectangleBounds.left + rectangleBounds.width
					&& playerBounds.top<rectangleBounds.top + rectangleBounds.height
					&& playerBounds.top + playerBounds.height>rectangleBounds.top) {

					player.velocity.x = 0.f;
					player.velocity.y = 0.f;
					player.main.setPosition(rectangleBounds.left - playerBounds.width/2, playerBounds.top);
				}
				//left
				if (playerBounds.left > rectangleBounds.left
					&& playerBounds.left + playerBounds.width > rectangleBounds.left + rectangleBounds.width
					&& playerBounds.top<rectangleBounds.top + rectangleBounds.height
					&& playerBounds.top + playerBounds.height>rectangleBounds.top) {
					player.velocity.y = 0.f;
					player.velocity.x = 0.f;
					player.main.setPosition(rectangleBounds.left + rectangleBounds.width + playerBounds.height / 2, playerBounds.top);
				}





			



					




}


void Walls::bullet_collision(Player& player) {

	for (int i = 0; i < player.bullets_.size(); i++) {



		if (player.bullets_[i].getGlobalBounds().intersects(this->getGlobalBounds())) {

			//Vector2f b_pos = player.bullets_[i].getPosition();

			//Vector2f p_pos = player.bullets_[i].player_shoot_pos;
			//
			////cout << "dziala" << endl;

			//float top_rectangle(this->getPosition().y - this->getGlobalBounds().height / 2);
			//float bottom_rectangle(this->getPosition().y + this->getGlobalBounds().height / 2);
			//float left_rectangle(this->getPosition().x + this->getGlobalBounds().width / 2);
			//float right_rectangle(this->getPosition().x - this->getGlobalBounds().width / 2);



			//if (p_pos.x <= b_pos.x && p_pos.y <= b_pos.y && b_pos.y <= top_rectangle) {
			//	player.bullets_[i].velocity.x = abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = -abs(player.bullets_[i].velocity.y);
			//}

			//if (p_pos.x >= b_pos.x && p_pos.y <= b_pos.y && b_pos.y <= top_rectangle) {
			//	player.bullets_[i].velocity.x = -abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = -abs(player.bullets_[i].velocity.y);
			//}


			//if (p_pos.x <= b_pos.x && p_pos.y >= b_pos.y && b_pos.y >= bottom_rectangle) {
			//	player.bullets_[i].velocity.x = abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = abs(player.bullets_[i].velocity.y);
			//}
		
			//if (p_pos.x >= b_pos.x && p_pos.y >= b_pos.y && b_pos.y >= bottom_rectangle) {
			//	player.bullets_[i].velocity.x = -abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = abs(player.bullets_[i].velocity.y);
			//}



			//if (p_pos.y >= b_pos.y && p_pos.x >= b_pos.x && b_pos.x >= left_rectangle) {
			//	player.bullets_[i].velocity.x = abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = -abs(player.bullets_[i].velocity.y);
			//}
			//
			//if (p_pos.y <= b_pos.y && p_pos.x >= b_pos.x && b_pos.x >= left_rectangle) {
			//	player.bullets_[i].velocity.x = abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = abs(player.bullets_[i].velocity.y);
			//}
			//
			////RIGHT
			//if (p_pos.y >= b_pos.y && p_pos.x <= b_pos.x && b_pos.x <= right_rectangle) {
			//	player.bullets_[i].velocity.x = -abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = -abs(player.bullets_[i].velocity.y);
			//}
			//
			//if (p_pos.y <= b_pos.y && p_pos.x <= b_pos.x && b_pos.x <= right_rectangle) {
			//	player.bullets_[i].velocity.x = -abs(player.bullets_[i].velocity.x);
			//	player.bullets_[i].velocity.y = abs(player.bullets_[i].velocity.y);

			//}


			//player.bullets_[i].bullets_hp--;
			player.bullets_.erase(player.bullets_.begin() + i); // dodane
		}
		//if (player.bullets_[i].bullets_hp ==1) {
		//	player.bullets_[i].setFillColor(Color::Red);
		//}
		//

		//if (player.bullets_[i].bullets_hp < 0) {
		//	player.bullets_.erase(player.bullets_.begin() + i);
		//}
		
	}

	


	if (player.main.getPosition().x - player.main.getGlobalBounds().width / 2 < 0) {
		player.main.setPosition(0 + player.main.getGlobalBounds().width / 2, player.main.getPosition().y);
	}

	if (player.main.getPosition().x + player.main.getGlobalBounds().width / 2 > 700) {
		player.main.setPosition(700 - player.main.getGlobalBounds().width / 2, player.main.getPosition().y);
	}

	if (player.main.getPosition().y - player.main.getGlobalBounds().width / 2 < 0) {
		player.main.setPosition(player.main.getPosition().x, 0 + player.main.getGlobalBounds().width / 2);
	}
	if (player.main.getPosition().y + player.main.getGlobalBounds().width / 2 > 700) {
		player.main.setPosition(player.main.getPosition().x, 700 - player.main.getGlobalBounds().width / 2);
	}



}