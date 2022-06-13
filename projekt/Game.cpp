
#include "Game.h"
#include "Fireplace.h"


Game::Game(const Texture& texture) {

	setTexture(texture);
	setScale(0.5, 0.5);

}




void Game::shoot(Player& player, Enemy& enemy) {

	for (auto s = player.bullets_.begin(); s != player.bullets_.end();) {
		if(s->getGlobalBounds().intersects(enemy.main.getGlobalBounds())) {
			cout << "ala - enemy" << endl;
			
			s = player.bullets_.erase(s);
			enemy.hp--;
			if (enemy.hp == 0) {

				cout << "NIEZYJE" << endl;



			}

		}
		else {
			++s;
		}
	}
	

	for (auto s = enemy.bullets.begin(); s != enemy.bullets.end();) {
		if (s->getGlobalBounds().intersects(player.main.getGlobalBounds())) {
			cout << "ala - player" << endl;

			player.hp--;

			if (player.hp == 0) {

				cout << "PRZEGRALES" << endl;

			}

			s = enemy.bullets.erase(s);


		}
		else {
			++s;
		}
	}



	if (player.main.getGlobalBounds().intersects(this->getGlobalBounds())) {

		cout << "WYGRALES" << endl;
		win = true;

	}


	




}
