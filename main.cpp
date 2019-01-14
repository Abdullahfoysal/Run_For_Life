#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<string>
#include<time.h>

using namespace std;
using namespace sf;

int win_x=1000;
int win_y=700;
int screenWidth=4160;///border of gamescreen


///score count
Vector2f strength_level(100,10);


float strength=0.f;
int coinCount=0;
int lifeCount=4;
int moneyCount=0;
int my_soldier_hit=0;
int my_soldierHit=4;
bool my_soldier_died=false;
 float diedTime=0.f;


enum Direction {Right,Down,Left,Up};

sf::Vector2i soldier_source(0,0);
Vector2f soldierCurrrentPosition(0,330);
Vector2f soldierPosition(win_x/2,win_y/2);

float frameCounter=0,switchFrame=100,frameSpeed=600;
float movespeed=100.0f;
 float soldierJumpSpeed=5.0f;
   float soldierJumpHeight=200;


   //bulet
   int buletMove=0;
   float my_buletTime=0.f;

   float enemyTime=0.f;
   float enemySoldierSpeed=30.0f;
   bool enemyBack[50],enemyBackAgain[50];
   float  enemybuletTime=0.f;
   std::vector<bool>enemy_direction;
   int enemyHit=5;
   int enemy_hit[50];
   bool enemy_died[50];
   float enemy_diedTime=0.f;

   ///man
   float man_time=0.f;
   int manCry=0;
   bool man_esc=false;
   float manSpeed=100.0f;
   int manNumber=0;
   int happyMovement1=0;
    int happyMovement2=0;
    float manESCTime=0.f,manESCTime2=0.f;


RenderWindow window(VideoMode(win_x,win_y),"Run For Life",Style::Titlebar | Style::Resize | Style::Close);

struct Load
{
	Sprite s_sprite;
 	Texture t_texture;
 	Clock clock;
 	Time time;


};
class bulet
{
public:
    Sprite s_bulet;
    bulet(Texture *texture,Vector2f pos)
    {

        s_bulet.setTexture(*texture);
        s_bulet.setScale(1,2);
        s_bulet.setPosition(pos);
    }
};
class enemybulet
{
    public:
    Sprite s_enemybulet;
    enemybulet(Texture *texture,Vector2f pos,int dir)
    {
        if(enemyBack[dir])///placeEnemySoldier==1
        {
            pos.x=pos.x+110;
            pos.y=pos.y+30;
        }
        else if(enemyBackAgain[dir])
        {
            pos.x=pos.x;
            pos.y=pos.y+30;
        }
        else if(enemy_direction[dir])
        {
            pos.x=pos.x;
            pos.y=pos.y+30;
        }
        else
        {
              pos.x=pos.x+110;
            pos.y=pos.y+30;
        }
       //if(placeEnemySoldier==1)
       //s_enemybulet.setTextureRect(IntRect(1*20,3*25,20,25));
         s_enemybulet.setTexture(*texture);

         s_enemybulet.setScale(1,2);
         s_enemybulet.setPosition(pos);
    }
};

class enemy
{
public:
	Sprite s_enemy;
	enemy(Texture *texture,Vector2f pos)
	{

		s_enemy.setTexture(*texture);
		s_enemy.setPosition(pos);
	}
};
class mann
{
public:
    Sprite s_manESC;
    mann (Texture *texture,Vector2f pos)
    {
        pos.x=pos.x-50;
        pos.y=300+35;



        s_manESC.setTexture(*texture);
        s_manESC.setPosition(pos);
    }
};


void my_soldier_died_Check()
{
	 if(my_soldier_hit>my_soldierHit)
        {
        	strength_level.x-=20;
        	my_soldier_hit=0;
        	if(strength_level.x<10)
        	{
        		lifeCount--;
        		my_soldier_died=true;
        		strength_level.x=100;
        	}

        }
}


void diedtime()
{
	 if(diedTime>5.0)
        {
        	my_soldier_died=false;
        	diedTime=0.f;


        }
}


int main()
{
	window.setPosition(Vector2i(200,0));
    window.setKeyRepeatEnabled(false);

    View view;
    view.reset(FloatRect(0,0,win_x,win_y));
    view.setViewport(FloatRect(0,0,1.0f,1.0f));


     RectangleShape strength_rect;
    strength_rect.setSize(strength_level);
    strength_rect.setFillColor(Color::Green);

    std::string Score_str;



    Load background[5],my_soldier,enemy_soldier,my_bulet[2],enemy_bulet[2],
    my_clock,my_buletclock,stab_clock,stab2_clock,life[4],money,man[3];

     Font font1,font2,font3,font4;
    font1.loadFromFile("Resources/Hunters.otf");

    Text life_text,strength_text,coin_text,coinCount_text,
    helpmetxt;

    life_text.setString("Life :");
    life_text.setFont(font1);
    life_text.setCharacterSize(30);
    life_text.setScale(1.5f,1.5f);
    life_text.setColor(Color::Green);


     strength_text.setString("Strength :");
     strength_text.setFont(font1);
     strength_text.setCharacterSize(30);
     strength_text.setScale(1.5f,1.5f);
     strength_text.setColor(Color::Magenta);

     coin_text.setString("Coins:");
     coin_text.setFont(font1);
     coin_text.setCharacterSize(30);
     coin_text.setScale(1.5f,1.5f);
     coin_text.setColor(Color::Yellow);

     coinCount_text.setFont(font1);
     coinCount_text.setCharacterSize(30);
     coinCount_text.setScale(1.f,1.f);
     coinCount_text.setColor(Color::Yellow);

     helpmetxt.setString("Help!");
     helpmetxt.setFont(font1);
     helpmetxt.setCharacterSize(30);
     helpmetxt.setScale(1.0f,1.0f);
     helpmetxt.setColor(Color::White);



    background[0].t_texture.loadFromFile("Resources/background.png");
    background[0].s_sprite.setTexture(background[0].t_texture);

    my_soldier.t_texture.loadFromFile("Resources/soldier.png");
    my_soldier.s_sprite.setTexture(my_soldier.t_texture);
    my_soldier.s_sprite.setPosition(soldierCurrrentPosition.x,soldierCurrrentPosition.y);

    enemy_soldier.t_texture.loadFromFile("Resources/enemySoldier.png");
    enemy_soldier.s_sprite.setTexture(enemy_soldier.t_texture);

//    dragon.t_texture.loadFromFile("Resources/dragon.png");
//    dragon.s_sprite.setTexture(dragon.t_texture);
//
//    animal.t_texture.loadFromFile("Resources/animal.png");
//    animal.s_sprite.setTexture(animal.t_texture);
//
//    man.t_texture.loadFromFile("Resources/man.png");
//    man.s_sprite.setTexture(man.t_texture);
//
//    man_escape.t_texture.loadFromFile("Resources/manESC.png");
//    man_escape.s_sprite.setTexture(man_escape.t_texture);

    my_bulet[1].t_texture.loadFromFile("Resources/mybulet1.png");//front
    my_bulet[1].s_sprite.setTexture(my_bulet[1].t_texture);
    my_bulet[0].t_texture.loadFromFile("Resources/mybulet0.png");//back
    my_bulet[0].s_sprite.setTexture(my_bulet[0].t_texture);

    enemy_bulet[1].t_texture.loadFromFile("Resources/enemybulet1.png");//front  -->
    enemy_bulet[1].s_sprite.setTexture(enemy_bulet[1].t_texture);
    enemy_bulet[0].t_texture.loadFromFile("Resources/enemybulet0.png");// <--
    enemy_bulet[0].s_sprite.setTexture(enemy_bulet[0].t_texture);


    life[0].t_texture.loadFromFile("Resources/life.png");
    life[0].s_sprite.setTexture(life[0].t_texture);
    life[0].s_sprite.setScale(0.02f,0.02f);

    /*life[1].t_texture.loadFromFile("Resources/life.png");
    life[1].s_sprite.setTexture(life[1].t_texture);

    life[2].t_texture.loadFromFile("Resources/life.png");
    life[2].s_sprite.setTexture(life[2].t_texture);

    life[3].t_texture.loadFromFile("Resources/life.png");
    life[3].s_sprite.setTexture(life[3].t_texture);
*/
    money.t_texture.loadFromFile("Resources/money.png");
    money.s_sprite.setTexture(money.t_texture);
    money.s_sprite.setScale(0.5f,0.5f);


    //man escape running
    man[0].t_texture.loadFromFile("Resources/man.png");
    man[0].s_sprite.setTexture(man[0].t_texture);

    man[1].t_texture.loadFromFile("Resources/manESC.png");
    man[1].s_sprite.setTexture(man[1].t_texture);

    man[2].t_texture.loadFromFile("Resources/manESC.png");
    man[2].s_sprite.setTexture(man[2].t_texture);

     man[0].s_sprite.setPosition(my_soldier.s_sprite.getPosition().x+500,soldierCurrrentPosition.y-60);
     man[0].s_sprite.setTextureRect(IntRect(0*165,0*200,165,200));

   // t_man.loadFromFile("Resources/man.png");





//my_soldier bulet
     std::vector<bulet>buletPosition;

    std::vector<bool>soldier_buletDirection;
 //enemy_soldier
    std::vector<enemy>full_enemy;


   std::vector<enemybulet>enemybuletPosition[50];

   ///manEscape
    std::vector<mann>manESCPosition;




	while(window.isOpen())
	{
		window.draw(background[0].s_sprite);


         diedtime();
		 my_soldier_died_Check();
		 if(my_soldier_died)buletPosition.clear();

		 diedTime+=my_clock.clock.getElapsedTime().asSeconds();

		Event event;
		while(window.pollEvent(event))
		{
			 switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if(event.key.code==Keyboard::Escape)
                    window.close();
                break;
            }
		}

        my_buletTime=my_buletclock.clock.getElapsedTime().asSeconds();

	//Down button
           if(my_soldier_died)
		      {
		        if(soldier_source.y==Right)
		        my_soldier.s_sprite.setTextureRect(IntRect(5*110,12*180,170,180));
		        else
		        my_soldier.s_sprite.setTextureRect(IntRect(0*110,14*180,170,180));///edit soldier image for left(image bottom)

		      }

            else if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(1*130,1*180,130,180));
                else my_soldier.s_sprite.setTextureRect(IntRect(0*130,1*180,130,180));


            }
           else if(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::S))
            {
                if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,8*180,130,180));
                else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,9*180,130,180));

              if(my_buletTime>0.2 )
              {

                   if(soldier_source.y==Right)
                   {
                       Vector2f soldierbuletPosition(my_soldier.s_sprite.getPosition().x+110,my_soldier.s_sprite.getPosition().y+80);
                       buletPosition.push_back(bulet(&my_bulet[1].t_texture,soldierbuletPosition));
                       soldier_buletDirection.push_back(true);
                   }


                   else
                   {
                        Vector2f soldierbuletPosition(my_soldier.s_sprite.getPosition().x-20,my_soldier.s_sprite.getPosition().y+80);
                        buletPosition.push_back(bulet(&my_bulet[0].t_texture,soldierbuletPosition));
                        soldier_buletDirection.push_back(false);
                   }


                   my_buletclock.clock.restart();


              }


            }
        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {

             if(Keyboard::isKeyPressed(Keyboard::Right))my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,6*180,130,180));
            else if(Keyboard::isKeyPressed(Keyboard::Left))my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,7*180,130,180));
            else
            {
                if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(3*130,180,130,180));
                else my_soldier.s_sprite.setTextureRect(IntRect(2*130,180,130,180));
            }

        }

        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            soldier_source.y=Right;
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,4*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));

        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            soldier_source.y=Left;
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,5*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));

        }
            ///work for jump
//       else if (Keyboard::isKeyPressed(Keyboard::Up))
//       //if (event.key.code == sf::Keyboard::Up)
//        {
//            if(soldier_source.y==Left)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,10*180,130,180));
//            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,3*180,130,180));
//
//        }
        else if(Keyboard::isKeyPressed(Keyboard::S))
        {

            if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,4*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,5*180,130,180));
	            if( my_buletTime>0.2)
	            {
	                 if(soldier_source.y==Right)///s_enemySoldier.getPosition().x>s_soldier.getPosition().x
	                 {
	                     Vector2f soldierbuletPosition(my_soldier.s_sprite.getPosition().x+110,my_soldier.s_sprite.getPosition().y+45);
	                     buletPosition.push_back(bulet(&my_bulet[1].t_texture,soldierbuletPosition));
	                     soldier_buletDirection.push_back(true);
	                 }

	                 else
	                 {
	                     Vector2f soldierbuletPosition(my_soldier.s_sprite.getPosition().x-10,my_soldier.s_sprite.getPosition().y+45);
	                     buletPosition.push_back(bulet(&my_bulet[0].t_texture,soldierbuletPosition));
	                     soldier_buletDirection.push_back(false);
	                 }
	                   my_buletclock.clock.restart();

	            }

        }

        else  my_soldier.s_sprite.setTextureRect(IntRect(1,soldier_source.y*180,130,180));//straight stand_up




///my soldier move

///move just close to last area my soldier

        if(Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Space) && !my_soldier_died)
        {
            if(my_soldier.s_sprite.getPosition().x+150<screenWidth)
            {

                my_soldier.s_sprite.move(movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);

                  if(Keyboard::isKeyPressed(Keyboard::Up))
                   my_soldier.s_sprite.move(movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);

            }

        }

        if(Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Space) && !my_soldier_died)
            {
                if(my_soldier.s_sprite.getPosition().x>10)
                {
                    my_soldier.s_sprite.move(-movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);

                   if(Keyboard::isKeyPressed(Keyboard::Up))
                   my_soldier.s_sprite.move(-movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }

            }

///UP button
        if(Keyboard::isKeyPressed(Keyboard::Up) && (my_soldier.s_sprite.getPosition().x>10) && !my_soldier_died)
        {
            if(my_soldier.s_sprite.getPosition().x+150<screenWidth)
            {
                if(Keyboard::isKeyPressed(Keyboard::Right))
                {
                    my_soldier.s_sprite.move(0,-soldierJumpSpeed*movespeed*my_clock.clock.getElapsedTime().asSeconds());
                   // my_soldier.s_sprite.move(movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Left))
                {
                    my_soldier.s_sprite.move(0,-soldierJumpSpeed*movespeed*my_clock.clock.getElapsedTime().asSeconds());
                   // my_soldier.s_sprite.move(-movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }
                else
                {
                    my_soldier.s_sprite.move(0,-soldierJumpSpeed*movespeed*my_clock.clock.getElapsedTime().asSeconds());
//                    if(soldier_source.y==Left) my_soldier.s_sprite.move(-movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);
//                    else my_soldier.s_sprite.move(movespeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }

            }
        }
        if(my_soldier.s_sprite.getPosition().y>50)soldierCurrrentPosition.y=330;



 ///my soldier bulet
///texture crop & movement
///bulet move + collision
for(int i=0;i<buletPosition.size();i++)
  {
     if(soldier_buletDirection[i])///s_enemySoldier.getPosition().x>s_soldier.getPosition().x && soldier_source.y==Right
     {
       buletPosition[i].s_bulet.move(1.f,0.f);
     }
     else if(soldier_buletDirection[i]==false)  /// s_enemySoldier.getPosition().x<s_soldier.getPosition().x && soldier_source.y==Left
        buletPosition[i].s_bulet.move(-1.f,0.f);
	 /*else
	  {
	    buletPosition.erase(buletPosition.begin()+i);
	    soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
	  }*/

  }

///stabed  my soldier
  for(int i=0;i<full_enemy.size();i++)
  {
  	float stab2=stab2_clock.clock.getElapsedTime().asSeconds();
  	if(my_soldier.s_sprite.getGlobalBounds().intersects(full_enemy[i].s_enemy.getGlobalBounds()) && stab2>0.2 )
  	{
           if(!my_soldier_died) my_soldier_hit++;
            stab2_clock.clock.restart();
  	}

  }

///stabing enemy

  		 float stab=stab_clock.clock.getElapsedTime().asSeconds();

  		 enemy_diedTime+=my_clock.clock.getElapsedTime().asSeconds();

            if(Keyboard::isKeyPressed(Keyboard::Space) && stab>0.2)
            {
                for(int i=0;i<full_enemy.size();i++)
                {

                		if(my_soldier.s_sprite.getGlobalBounds().intersects(full_enemy[i].s_enemy.getGlobalBounds()) && !enemy_died[i])
                		{
                			enemy_hit[i]++;
                			if(enemy_hit[i]>=enemyHit)
                			{
                				enemy_died[i]=true;
                				 enemy_hit[i]=0;
                				 //enemy_died_Check();

/*
                				 full_enemy.erase(full_enemy.begin()+i);
				                 enemy_direction.erase(enemy_direction.begin()+i);

				                    enemybuletPosition[i].clear();*/
                			}

                			 //if(buletPosition[i].s_bulet.getGlobalBounds().intersects(full_enemy[j].s_enemy.getGlobalBounds()))
                		}

                }
                stab_clock.clock.restart();

            }


    ///remove bulet from vector & collision "MY bulet"



   for(int i=0;i<buletPosition.size();i++)
    {
    	for(int j=0;j<full_enemy.size();j++)
    	{

	           if(buletPosition[i].s_bulet.getGlobalBounds().intersects(full_enemy[j].s_enemy.getGlobalBounds()) && !enemy_died[j])
	            {
	                 buletPosition.erase(buletPosition.begin()+i);
	                 soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
	                 enemy_hit[j]++;
	                 if(enemy_hit[j]>=enemyHit)//check enemy is dead
	                 {
	                 	enemy_died[i]=true;
                		enemy_hit[i]=0;

                      /*full_enemy.erase(full_enemy.begin()+j);
	                   enemy_direction.erase(enemy_direction.begin()+j);

	                    enemybuletPosition[j].clear();*/

	                }

	            }



    	}

    }

   for(int i=0;i<buletPosition.size();i++)
    {

    	      if(buletPosition[i].s_bulet.getPosition().x>my_soldier.s_sprite.getPosition().x+550)
		         {
		            buletPosition.erase(buletPosition.begin()+i);
		            soldier_buletDirection.erase(soldier_buletDirection.begin()+i);

		         }


	         else if(buletPosition[i].s_bulet.getPosition().x<my_soldier.s_sprite.getPosition().x-550)
	           {
	                buletPosition.erase(buletPosition.begin()+i);
	                soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
	           }

    }


  //enemy placed here
  //enemyTime+=clock.getElapsedTime();
  enemyTime += my_clock.clock.getElapsedTime().asSeconds();

  if(enemyTime>5.0)///work for placing enemy
        {
           //std::srand(time(NULL));
             int placeEnemySoldier=rand()%2;
             enemy_direction.push_back(placeEnemySoldier);//direction

            enemyTime=0.f;



            if(placeEnemySoldier==1)
            {
                Vector2f enemyPosition(my_soldier.s_sprite.getPosition().x+500,soldierCurrrentPosition.y);
            	full_enemy.push_back(enemy(&enemy_soldier.t_texture,enemyPosition));

            }
            else
            {
                 //placeEnemySoldier=0;

            	Vector2f enemyPosition(my_soldier.s_sprite.getPosition().x-500,soldierCurrrentPosition.y);

            	full_enemy.push_back(enemy(&enemy_soldier.t_texture,enemyPosition));

            }

        }

        //enemy bulet load
        enemybuletTime+=my_clock.clock.getElapsedTime().asSeconds();

        for(int i=0;i<full_enemy.size();i++)
        {
        	if(enemybuletTime>0.5 && abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)<400 && abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)>100 && !enemy_died[i])
        	{
        		if(my_soldier.s_sprite.getPosition().x < full_enemy[i].s_enemy.getPosition().x)
        		{
        			enemybuletPosition[i].push_back(enemybulet(&enemy_bulet[1].t_texture,full_enemy[i].s_enemy.getPosition(),i));
        		}
        		else enemybuletPosition[i].push_back(enemybulet(&enemy_bulet[0].t_texture,full_enemy[i].s_enemy.getPosition(),i));



        		enemybuletTime=0;
        	}


        }

        //enemy bulet set texture & move
        for(int i=0;i<full_enemy.size();i++)
        {
        	for(int j=0;j<enemybuletPosition[i].size();j++)
		    {
		        if(enemyBack[i])
		        {

		           enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[1].t_texture);
		           enemybuletPosition[i][j].s_enemybulet.move(.5f,0.f);
		        }
		        else if(enemyBackAgain[i])
		        {

		             enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[0].t_texture);
		           enemybuletPosition[i][j].s_enemybulet.move(-.5f,0.f);


		        }
		        else if(enemy_direction[i])
		        {

		             enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[0].t_texture);
		           enemybuletPosition[i][j].s_enemybulet.move(-.5f,0.f);
		        }
		        else {

		            enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[1].t_texture);
		           enemybuletPosition[i][j].s_enemybulet.move(0.5f,0.f);
		        }


		    }
        }

///enemy bulet collision

        for(int i=0;i<full_enemy.size();i++)
        {
        	for(int j=0;j<enemybuletPosition[i].size();j++)
        	{
        		if(Keyboard::isKeyPressed(Keyboard::Down));///do nothing with bulet

        	  else if(enemybuletPosition[i][j].s_enemybulet.getGlobalBounds().intersects(my_soldier.s_sprite.getGlobalBounds()))
        		{
        			enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
        			if(!my_soldier_died) my_soldier_hit++;//my soldier hit bulet
        		}

        		/*else if(enemybuletPosition[i][j].s_enemybulet.getPosition().x+300<my_soldier.s_sprite.getPosition().x)
        		{
        			enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
        		}
        		else if(enemybuletPosition[i][j].s_enemybulet.getPosition().x-300>my_soldier.s_sprite.getPosition().x)
        		{
        			enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
        		}*/
        	}


        }

        for(int i=0;i<full_enemy.size();i++)
        {
        	for(int j=0;j<enemybuletPosition[i].size();j++)
        	{
        		if(enemybuletPosition[i][j].s_enemybulet.getPosition().x>my_soldier.s_sprite.getPosition().x+400 )
        		{
        			enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
        		}
        		else if(enemybuletPosition[i][j].s_enemybulet.getPosition().x+400<my_soldier.s_sprite.getPosition().x)
        		{
        			enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
        		}
        	}
        }


        for(int i=0;i<full_enemy.size();i++)
        {
        	if(enemy_died[i])
        	{
        		if(enemyBack[i] || !enemy_direction[i])
        		full_enemy[i].s_enemy.setTextureRect(IntRect(4*130,11*180,170,180));
        		else if(enemyBackAgain[i] || enemy_direction[i])
        		{
        			full_enemy[i].s_enemy.setTextureRect(IntRect(4*130,12*180,170,180));
        		}
        	}
        	else if(abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)<100)
        	{


        		if(enemyBack[i])
                {
                    full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,1*180,110,180));

                }
                else if(enemyBackAgain[i])
                {
                  full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,6*180,110,180));
                }
        		else if(enemy_direction[i])
        		{
        			full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,6*180,110,180));
        		}
        		else
        		full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,1*180,110,180));
        	}
        	else if(abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)<600)
        	{
        		 if(enemyBack[i])
                {
                    full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,2*180,110,180));
        	        full_enemy[i].s_enemy.move(enemySoldierSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }
                else if(enemyBackAgain[i])
                {
                    full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,7*180,110,180));
        			full_enemy[i].s_enemy.move(-enemySoldierSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
                }

        		else if(enemy_direction[i])
        		{
        			full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,7*180,110,180));
        			full_enemy[i].s_enemy.move(-enemySoldierSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
        		}
        		else if(enemy_direction[i]==false)
        		{

        		    full_enemy[i].s_enemy.setTextureRect(IntRect(soldier_source.x*110,2*180,110,180));
        	        full_enemy[i].s_enemy.move(enemySoldierSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
        		}

        	}
        	else
        	{
        		 if(enemyBack[i])
                {
                    full_enemy[i].s_enemy.setTextureRect(IntRect(3*110,4*180,110,180));

                }
                else if(enemyBackAgain[i])
                {
                   full_enemy[i].s_enemy.setTextureRect(IntRect(2*110,4*180,110,180));
                }
        		else if(enemy_direction[i])
        		{
        			full_enemy[i].s_enemy.setTextureRect(IntRect(2*110,4*180,110,180));
        		}
        		else if(enemy_direction[i]==false)
        		{
        			full_enemy[i].s_enemy.setTextureRect(IntRect(3*110,4*180,110,180));

        		}


        	}

        if((full_enemy[i].s_enemy.getPosition().x+300<=my_soldier.s_sprite.getPosition().x)) {enemyBack[i]=true;enemyBackAgain[i]=false;}///range of back 300-x  enemybuletPosition.clear();

        if((full_enemy[i].s_enemy.getPosition().x>=my_soldier.s_sprite.getPosition().x+300)){ enemyBackAgain[i]=true; enemyBack[i]=false;}//enemybuletPosition.clear();



        }

        enemy_diedTime+=my_clock.clock.getElapsedTime().asSeconds();

        if(enemy_diedTime>6.0)
        {
        	 for(int i=0;i<full_enemy.size();i++)
		        {
		        	if(enemy_died[i])
		        	{
		        		 full_enemy.erase(full_enemy.begin()+i);
	                     enemy_direction.erase(enemy_direction.begin()+i);
	                     enemybuletPosition[i].clear();
	                     enemy_died[i]=false;
		        	}
		        }
		        enemy_diedTime=0;

        }


        ///man moving on cage
        if(abs(my_soldier.s_sprite.getPosition().x-man[0].s_sprite.getPosition().x)<5)
        {
             man_esc=true;
             man[0].s_sprite.setPosition(man[0].s_sprite.getPosition().x,soldierCurrrentPosition.y);
        }
        if(man_esc)
        {
              man[0].s_sprite.setTextureRect(IntRect(manCry*165,1*200,165,160));

              man[0].s_sprite.move(-manSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
               // s_man.move(-manSpeed*clock.getElapsedTime().asSeconds(),0);

        }
        else if(abs(my_soldier.s_sprite.getPosition().x-man[0].s_sprite.getPosition().x)<300)
        {
             man[0].s_sprite.setTextureRect(IntRect(manCry*165,0*200,165,200));
             helpmetxt.setPosition(man[0].s_sprite.getPosition().x,man[0].s_sprite.getPosition().y-50);

             window.draw(helpmetxt);


        }
        else  man[0].s_sprite.setTextureRect(IntRect(0*165,0*200,165,200));


        if(man[0].s_sprite.getPosition().x-manNumber*130<= 0 )
        {
            manESCPosition.push_back(mann(&man[1].t_texture,man[0].s_sprite.getPosition()));
            manNumber++;
            man_esc=false;

            Vector2f manCurrentPosition(my_soldier.s_sprite.getPosition().x+500,man[0].s_sprite.getPosition().y);
            //man(&t_man,manCurrentPosition);
            man[0].s_sprite.setPosition(manCurrentPosition.x,soldierCurrrentPosition.y-60);
        }
         for(int i=0;i<manESCPosition.size();i++)
        {
            if(i%2==0)
            manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement1*100,0*150,100,150));

            else manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement2*100,0*150,100,150));


        }
        manESCTime+=my_clock.clock.getElapsedTime().asSeconds();
        manESCTime2+=my_clock.clock.getElapsedTime().asSeconds();

        if(manESCTime>0.35)
        {
            manESCTime=0;
            happyMovement1++;

            if(happyMovement1>2){happyMovement1=0;}
        }
        if(manESCTime2>0.25)
        {
            manESCTime2=0;
             happyMovement2++;
             if(happyMovement2>2)happyMovement2=0;

        }
        for(int i=0;i<manESCPosition.size();i++)
        {
            window.draw(manESCPosition[i].s_manESC);
        }

        man_time+=my_clock.clock.getElapsedTime().asSeconds();
         helpmetxt.setColor(Color::White);
        if(man_time>0.25)
        {
            man_time=0;
            manCry++;
             helpmetxt.setColor(Color::Red);
            if(manCry>2)
            {

                manCry=0;
            }
        }



          ///screen scrolling

        if(my_soldier.s_sprite.getPosition().x+win_x/2+150<screenWidth)
        {
	       if(my_soldier.s_sprite.getPosition().x+100>win_x/2)
	        {
	            soldierPosition.x=my_soldier.s_sprite.getPosition().x+100;
	        }
	        else soldierPosition.x=win_x/2;
        }



      ///my soldier setPosition here

        view.setCenter(soldierPosition);

        my_soldier.s_sprite.setPosition(soldierCurrrentPosition.x+my_soldier.s_sprite.getPosition().x,soldierCurrrentPosition.y);
       if(my_soldier.s_sprite.getPosition().x+win_x/2+150<screenWidth)
        window.setView(view);




        frameCounter+=frameSpeed*my_clock.clock.restart().asSeconds();
        if(frameCounter>=switchFrame)
        {
            frameCounter=0;
            soldier_source.x++;
            if(soldier_source.x>3)soldier_source.x=0;

            // if(soldier_source.x*130>=t_soldier.getSize().x && soldier_source.x>3)soldier_source.x=0;
        }



      window.draw(man[0].s_sprite);


      for(int i=0;i<full_enemy.size();i++)
      {
      	for(int j=0;j<enemybuletPosition[i].size();j++)
      		window.draw(enemybuletPosition[i][j].s_enemybulet);
      }


	  for(int i=0;i<full_enemy.size();i++)
      {
      	window.draw(full_enemy[i].s_enemy);

      }
      for(int i=0;i<buletPosition.size();i++)
      {
        window.draw(buletPosition[i].s_bulet);
      }


      for(int i=0;i<lifeCount;i++)
      {

	    life[0].s_sprite.setPosition(soldierPosition.x-400+i*25,0+8);

      	window.draw(life[0].s_sprite);
      }

	      money.s_sprite.setPosition(soldierPosition.x+400,0-10);
	      window.draw(money.s_sprite);


        life_text.setPosition(soldierPosition.x-500,0-20);
        strength_text.setPosition(soldierPosition.x-500,0-20+30);
        coin_text.setPosition(soldierPosition.x-500,0-20+30+30);

        strength_rect.setPosition(soldierPosition.x-500+150,0-20+30+30);
        strength_rect.setSize(strength_level);
        window.draw(strength_rect);
        window.draw(life_text);
        window.draw(strength_text);
        window.draw(coin_text);

            Score_str =coinCount-'0';

        //Score_str = std::to_string(coinCount);
        coinCount_text.setString(Score_str);
        coinCount_text.setPosition(soldierPosition.x-400,0-20+30+30+10);
        window.draw(coinCount_text);


        window.draw(my_soldier.s_sprite);
        window.draw(coinCount_text);

	window.display();
	window.clear();



	}

}
