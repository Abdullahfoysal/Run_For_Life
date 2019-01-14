#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<string>
#include<time.h>

using namespace sf;
sf::Vector2i soldier_source(0,0);
 int placeEnemySoldier=1;
 bool downpressed=false;
 int manNumber=1;

  bool enemyBack=false;
  bool enemyBackAgain=false;


 //int happyMovement=0;


class bulet
{
public:
    Sprite s_bulet;
    bulet(Texture *texture,Vector2f pos)
    {
        if(soldier_source.y==0)///right
        {

        /*  if(downpressed)
          {

              pos.x=pos.x+120;
              pos.y=pos.y+400;
              // std::cout<<"down shoot";
          }
          else
          {
                pos.x=pos.x+110;
                pos.y=pos.y+55;
          }*/

        }
        else //(soldier_source.y==2)///left
        {

          /* if(downpressed)
            {

              pos.x=pos.x+120;
              pos.y=pos.y+400;

            }
            else
            {
                 pos.x=pos.x-20;
                pos.y=pos.y+55;
            }*/

        }

        s_bulet.setTexture(*texture);
        s_bulet.setScale(1,2);
        s_bulet.setPosition(pos);
      //


    }
};

class enemybulet
{
    public:
    Sprite s_enemybulet;
    enemybulet(Texture *texture,Vector2f pos)
    {
        if(enemyBack)///placeEnemySoldier==1
        {
            pos.x=pos.x+110;
            pos.y=pos.y+40;
        }
        else if(enemyBackAgain)
        {
            pos.x=pos.x;
            pos.y=pos.y+40;
        }
        else if(placeEnemySoldier==1)
        {
            pos.x=pos.x;
            pos.y=pos.y+40;
        }
        else
        {
              pos.x=pos.x+110;
            pos.y=pos.y+40;
        }
       //if(placeEnemySoldier==1)
         //s_enemybulet.setTextureRect(IntRect(1*20,3*25,20,25));
         s_enemybulet.setTexture(*texture);

         s_enemybulet.setScale(1,2);
         s_enemybulet.setPosition(pos);
    }
};

class man
{
public:
    Sprite s_manESC;
    man (Texture *texture,Vector2f pos)
    {
        pos.x=pos.x-50;
        pos.y=300;



        s_manESC.setTexture(*texture);
        s_manESC.setPosition(pos);
    }
};


int main()
{
    RenderWindow window;
    Vector2i screenDimentions(1000,700);
    window.create(VideoMode(screenDimentions.x,screenDimentions.y),"Run For Life",Style::Titlebar | Style::Resize | Style::Close);
    ///window.setSize(Vector2u(500,500));
    /// window.setTitle("sfml new title");
    window.setKeyRepeatEnabled(false);
    int screenWidth=4160;
     int happyMovement1=0;
     int happyMovement2=0;




    window.setPosition(Vector2i(200,0));


    enum Direction {Right,Down,Left,Up};

    Texture t_background,t_soldier,t_man,t_animal,t_coin,t_dragon,t_enemySoldier,t_bulet,t_mybulet,t_enemybulet,t_enemybulet1,t_mybulet1,t_fire,t_manESC;
    Sprite s_background,s_soldier,s_man,s_animal,s_coin,s_dragon,s_enemySoldier,s_bulet,s_mybulet,s_enemybulet,s_enemybulet1,s_mybulet1,s_fire,s_manESC;

    std::cout<<"All move works ,Let's Play with arrow key\n";
    std::cout<<"shoot with S button\n";
    std::cout<<"stab with SPACE button\n";

     std::vector<bulet>buletPosition;
     t_mybulet.loadFromFile("Resources/mybulet1.png");
     s_mybulet.setTexture(t_mybulet);
     t_mybulet1.loadFromFile("Resources/mybulet0.png");
     s_mybulet1.setTexture(t_mybulet1);
     std::vector<bool>soldier_buletDirection;


     std::vector<enemybulet>enemybuletPosition;
     t_enemybulet.loadFromFile("Resources/enemybulet0.png");
      //s_enemybulet.setTexture(t_enemybulet);

     t_enemybulet1.loadFromFile("Resources/enemybulet1.png");

     s_enemybulet1.setTexture(t_enemybulet1);

     ///MAN standing on 0-x coordinate

     std::vector<man>manESCPosition;
     t_manESC.loadFromFile("Resources/manESC.png");
     s_manESC.setTexture(t_manESC);

     ///fire
     t_fire.loadFromFile("Resources/fire.png");
     s_fire.setTexture(t_fire);


///load image
    if(!t_background.loadFromFile("Resources/background.png"))
    {
        std::cout<<"Can't load background";
    }
    //t_background2.loadFromFile("background2.png");
    s_background.setScale(1.0f,(float)screenDimentions.y/t_background.getSize().y);

///background
    s_background.setTexture(t_background);
    // s_background2.setTexture(t_background2);
    Vector2i backgroundPosition(0,0);
    s_background.setPosition(backgroundPosition.x,backgroundPosition.y);
///soldier
    t_soldier.loadFromFile("Resources/soldier.png");
// t_soldierSeatDown.loadFromFile("soldierSeatDownShoot.png");
    //Vector2i soldier_source(0,0);

//s_soldierSeatDown.setTexture(t_soldierSeatDown);

    s_soldier.setTexture(t_soldier);
    Vector2f soldierCurrrentPosition(0,330);
    s_soldier.setPosition(soldierCurrrentPosition.x,soldierCurrrentPosition.y);
    // s_soldierSeatDown.setPosition(soldierCurrrentPosition.x,soldierCurrrentPosition.y)
    float soldierJumpSpeed=5.0f;
    float soldierJumpHeight=200;
    int DiedMove=0;


    Vector2f soldierPosition(screenDimentions.x/2,screenDimentions.y/2);

    ///animal

    t_animal.loadFromFile("Resources/animal.png");
    s_animal.setTexture(t_animal);
    s_animal.setPosition(soldierCurrrentPosition.x-30,soldierCurrrentPosition.y+40);

    float animalMoveSpeed=100.0f;
    int animalMove=Right;

    ///dragon
    t_dragon.loadFromFile("Resources/dragon.png");
    s_dragon.setTexture(t_dragon);
    float dragonMoveSpeed=40.0f;
    int dragonMove=0;
    Vector2f dragonPosition(soldierCurrrentPosition.x+500,soldierCurrrentPosition.y+70);
    s_dragon.setPosition(dragonPosition.x,dragonPosition.y);
    int placeDragon=1;
    ///man
    t_man.loadFromFile("Resources/man.png");
    s_man.setTexture(t_man);

    s_man.setPosition(s_soldier.getPosition().x+500,soldierCurrrentPosition.y-60);
    s_man.setTextureRect(IntRect(soldier_source.x*165,0*200,165,200));

    bool esc=false;
    float manSpeed=100.0f;

    ///coin
    t_coin.loadFromFile("Resources/coin.png");
    s_coin.setTexture(t_coin);
    Vector2f coinPosition(400,320);
    s_coin.setPosition(coinPosition.x,coinPosition.y);
    float coinMove=0,pointType=0;

    ///enemySoldier
    t_enemySoldier.loadFromFile("Resources/enemySoldier.png");
    s_enemySoldier.setTexture(t_enemySoldier);
    Vector2f enemySoldierPosition(soldierCurrrentPosition.x+600,soldierCurrrentPosition.y);
    s_enemySoldier.setPosition(enemySoldierPosition.x,enemySoldierPosition.y);

    float enemySoldierSpeed=30.0f;

    ///bulet

    t_bulet.loadFromFile("Resources/bulet.png");
    s_bulet.setTexture(t_bulet);
   s_bulet.setPosition(soldierCurrrentPosition.x+700-150,soldierCurrrentPosition.y+50);
    float buletSpeed=200.0f;
    int buletMove=0;
     s_bulet.setTextureRect(IntRect(buletMove*25,7*20,25,20));




    Clock clock,mybuletclock,downshootclock;
    Time time=seconds(0),time2=seconds(0),time3=seconds(0),Diedtime=seconds(0),enemyTime=seconds(0),buletTime=seconds(0),enemybuletTime=seconds(0),mybuletTime1=seconds(0),manESCTime=seconds(0),manESCTime2=seconds(0);
    float movespeed=100.0f;
    float frameCounter=0,switchFrame=100,frameSpeed=600;
    float jumpSpeed=50.0f;



    View view;
    view.reset(FloatRect(0,0,screenDimentions.x,screenDimentions.y));
    view.setViewport(FloatRect(0,0,1.0f,1.0f));


    ///menu bar
    bool menu=true;
    Text Gamename,newgame,exit,selectArea,About,life;

    while(window.isOpen())
    {
        // clock.restart();
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
        if(menu)
        {
           window.draw(s_background);
            menu=0;
        }

            float mybuletTime=0.f;
            float downshoot=0.f;

        mybuletTime=mybuletclock.getElapsedTime().asSeconds();
        downshoot=downshootclock.getElapsedTime().asSeconds();
        //mybuletclock.restart();

///Down button
            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                if(soldier_source.y==Right)s_soldier.setTextureRect(IntRect(1*130,1*180,130,180));
                else s_soldier.setTextureRect(IntRect(0*130,1*180,130,180));

            }
           else if(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::S))
            {


                if(soldier_source.y==Right)s_soldier.setTextureRect(IntRect(soldier_source.x*130,8*180,130,180));
                else s_soldier.setTextureRect(IntRect(soldier_source.x*130,9*180,130,180));
              if(downshoot>0.2)
              {

                   if(soldier_source.y==Right)
                   {
                       Vector2f soldierbuletPosition(s_soldier.getPosition().x+110,s_soldier.getPosition().y+80);
                       buletPosition.push_back(bulet(&t_mybulet,soldierbuletPosition));
                       soldier_buletDirection.push_back(true);
                   }


                   else
                   {
                        Vector2f soldierbuletPosition(s_soldier.getPosition().x-20,s_soldier.getPosition().y+80);
                        buletPosition.push_back(bulet(&t_mybulet1,soldierbuletPosition));
                        soldier_buletDirection.push_back(false);
                   }


                   downshootclock.restart();

              }


            }
        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {

             if(Keyboard::isKeyPressed(Keyboard::Right))s_soldier.setTextureRect(IntRect(soldier_source.x*130,6*180,130,180));
            else if(Keyboard::isKeyPressed(Keyboard::Left))s_soldier.setTextureRect(IntRect(soldier_source.x*130,7*180,130,180));
            else
            {
                if(soldier_source.y==Right)s_soldier.setTextureRect(IntRect(3*130,180,130,180));
                else s_soldier.setTextureRect(IntRect(2*130,180,130,180));
            }

        }

        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            soldier_source.y=Right;
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)s_soldier.setTextureRect(IntRect(soldier_source.x*130,4*180,130,180));
            else s_soldier.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));

        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            soldier_source.y=Left;
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)s_soldier.setTextureRect(IntRect(soldier_source.x*130,5*180,130,180));
            else s_soldier.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));

        }
        else if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            if(soldier_source.y==Left)s_soldier.setTextureRect(IntRect(soldier_source.x*130,10*180,130,180));
            else s_soldier.setTextureRect(IntRect(soldier_source.x*130,3*180,130,180));

            //if(Keyboard::isKeyPressed(Keyboard::Right))s_soldier.setTextureRect(IntRect(soldier_source.x*130,3*180,130,180));
            // else if(Keyboard::isKeyPressed(Keyboard::Left))s_soldier.setTextureRect(IntRect(soldier_source.x*130,10*180,130,180));


        }
        else if(Keyboard::isKeyPressed(Keyboard::S))
        {

            if(soldier_source.y==Right)s_soldier.setTextureRect(IntRect(soldier_source.x*130,4*180,130,180));
            else s_soldier.setTextureRect(IntRect(soldier_source.x*130,5*180,130,180));
            if( mybuletTime>0.2)
            {
                 if(soldier_source.y==Right)///s_enemySoldier.getPosition().x>s_soldier.getPosition().x
                 {
                     Vector2f soldierbuletPosition(s_soldier.getPosition().x+110,s_soldier.getPosition().y+45);
                     buletPosition.push_back(bulet(&t_mybulet,soldierbuletPosition));
                     soldier_buletDirection.push_back(true);
                 }

                 else
                 {
                     Vector2f soldierbuletPosition(s_soldier.getPosition().x-10,s_soldier.getPosition().y+45);
                     buletPosition.push_back(bulet(&t_mybulet1,soldierbuletPosition));
                     soldier_buletDirection.push_back(false);
                 }
                   mybuletclock.restart();

            }

        }
        else  s_soldier.setTextureRect(IntRect(soldier_source.x,soldier_source.y*180,130,180));
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
    else
    {
          buletPosition.erase(buletPosition.begin()+i);
          soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
    }


  }

    ///remove bulet from vector
   for(int i=0;i<buletPosition.size();i++)
    {
        if(soldier_source.y==Right)
      {
           if(buletPosition[i].s_bulet.getGlobalBounds().intersects(s_enemySoldier.getGlobalBounds()))
            {
                 buletPosition.erase(buletPosition.begin()+i);
                 soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
            }



          else if(buletPosition[i].s_bulet.getPosition().x>s_soldier.getPosition().x+600)
          {
              buletPosition.erase(buletPosition.begin()+i);
              soldier_buletDirection.erase(soldier_buletDirection.begin()+i);

          }


            if(buletPosition[i].s_bulet.getGlobalBounds().intersects(s_enemybulet.getGlobalBounds()))
            {
                buletPosition.erase(buletPosition.begin()+i);
                soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
                ///draw fire here
                s_fire.setPosition(buletPosition[i].s_bulet.getPosition().x,buletPosition[i].s_bulet.getPosition().y);
                window.draw(s_fire);
            }

      }
      else
      {
            if(buletPosition[i].s_bulet.getGlobalBounds().intersects(s_enemySoldier.getGlobalBounds()))
           {
                 buletPosition.erase(buletPosition.begin()+i);
                 soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
           }


            else if(buletPosition[i].s_bulet.getPosition().x<s_soldier.getPosition().x-600)
           {
                buletPosition.erase(buletPosition.begin()+i);
                soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
           }

/*
             if(buletPosition[i].s_bulet.getGlobalBounds().intersects(s_enemybulet.getGlobalBounds()))
            {
                buletPosition.erase(buletPosition.begin()+i);
            }
            */

      }

    }
    ///enemy bulet


if((s_enemySoldier.getPosition().x+400<=s_soldier.getPosition().x)) {enemyBack=true;enemyBackAgain=false;enemybuletPosition.clear();}///range of back 300-x

if((s_enemySoldier.getPosition().x>=s_soldier.getPosition().x+400)){ enemyBackAgain=true; enemyBack=false;enemybuletPosition.clear();}

    enemybuletTime+=clock.getElapsedTime();
    if(enemybuletTime.asSeconds()>0.4 && abs(s_enemySoldier.getPosition().x-s_soldier.getPosition().x)<400 && abs(s_enemySoldier.getPosition().x-s_soldier.getPosition().x)>90)
    {
        enemybuletTime=seconds(0);
       // if(placeEnemySoldier==1)
        enemybuletPosition.push_back(enemybulet(&t_bulet,s_enemySoldier.getPosition()));
       // else enemybuletPosition.push_back(enemybulet(&t_bulet,s_enemySoldier.getPosition()));

    }
    ///Enemy bulet move
    for(int i=0;i<enemybuletPosition.size();i++)
    {
        if(enemyBack)
        {
           enemybuletPosition[i].s_enemybulet.setTextureRect(IntRect(0*20,2*25,20,25));
           enemybuletPosition[i].s_enemybulet.move(1.f,0.f);
        }
        else if(enemyBackAgain)
        {
            enemybuletPosition[i].s_enemybulet.setTextureRect(IntRect(1*20,2*25,20,25));
            enemybuletPosition[i].s_enemybulet.move(-1.f,0.f);
        }
        else if(placeEnemySoldier==1)
        {
            enemybuletPosition[i].s_enemybulet.setTextureRect(IntRect(1*20,2*25,20,25));
            enemybuletPosition[i].s_enemybulet.move(-1.f,0.f);
        }
        else {
            enemybuletPosition[i].s_enemybulet.setTextureRect(IntRect(0*20,2*25,20,25));
            enemybuletPosition[i].s_enemybulet.move(1.f,0.f);
        }

//         if(placeEnemySoldier==1 )enemybuletPosition[i].s_enemybulet.move(-1.f,0.f);
//         else if(placeEnemySoldier==0) enemybuletPosition[i].s_enemybulet.move(1.f,0.f);
//         else  enemybuletPosition.erase(enemybuletPosition.begin()+i);
    }

    ///remove bulet
      for(int i=0;i<enemybuletPosition.size();i++)
    {
        if( s_enemySoldier.getPosition().x>s_soldier.getPosition().x )
         {
             if(Keyboard::isKeyPressed(Keyboard::Down));///do nothing with bulet


             else  if(enemybuletPosition[i].s_enemybulet.getGlobalBounds().intersects(s_soldier.getGlobalBounds()))
             enemybuletPosition.erase(enemybuletPosition.begin()+i);
             else if(enemybuletPosition[i].s_enemybulet.getPosition().x+300<s_soldier.getPosition().x)
                enemybuletPosition.erase(enemybuletPosition.begin()+i);

            if(enemybuletPosition[i].s_enemybulet.getGlobalBounds().intersects(s_mybulet.getGlobalBounds()))
            {
                enemybuletPosition.erase(enemybuletPosition.begin()+i);
            }



          /*else if(buletPosition[i].s_bulet.getPosition().x>s_soldier.getPosition().x+600)
            buletPosition.erase(buletPosition.begin()+i);
            */
         }
      else
          {
               if(Keyboard::isKeyPressed(Keyboard::Down));///do nothing with bulet

           else if(enemybuletPosition[i].s_enemybulet.getGlobalBounds().intersects(s_soldier.getGlobalBounds()))
            enemybuletPosition.erase(enemybuletPosition.begin()+i);
            else if(enemybuletPosition[i].s_enemybulet.getPosition().x-300>s_soldier.getPosition().x)
                enemybuletPosition.erase(enemybuletPosition.begin()+i);
             if(enemybuletPosition[i].s_enemybulet.getGlobalBounds().intersects(s_mybulet.getGlobalBounds()))
            {
                enemybuletPosition.erase(enemybuletPosition.begin()+i);
            }


          /*  else if(buletPosition[i].s_bulet.getPosition().x<s_soldier.getPosition().x-600)
            buletPosition.erase(buletPosition.begin()+i);
            */
         }

    }






///move just close to last area my soldier

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            if(s_soldier.getPosition().x+200<screenWidth)
            {

                s_soldier.move(movespeed*clock.getElapsedTime().asSeconds(),0);

            }

        }


        if(Keyboard::isKeyPressed(Keyboard::Left))
            if(s_soldier.getPosition().x>0)
                s_soldier.move(-movespeed*clock.getElapsedTime().asSeconds(),0);
///UP button
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            if(s_soldier.getPosition().x+200<screenWidth)
            {
                if(Keyboard::isKeyPressed(Keyboard::Right))
                {
                    s_soldier.move(0,-soldierJumpSpeed*movespeed*clock.getElapsedTime().asSeconds());
                    s_soldier.move(movespeed*clock.getElapsedTime().asSeconds(),0);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Left))
                {
                    s_soldier.move(0,-soldierJumpSpeed*movespeed*clock.getElapsedTime().asSeconds());
                    s_soldier.move(-movespeed*clock.getElapsedTime().asSeconds(),0);
                }
                else
                {
                    s_soldier.move(0,-soldierJumpSpeed*movespeed*clock.getElapsedTime().asSeconds());
                    if(soldier_source.y==Left) s_soldier.move(-movespeed*clock.getElapsedTime().asSeconds(),0);
                    else s_soldier.move(movespeed*clock.getElapsedTime().asSeconds(),0);
                }

            }
        }
        if(s_soldier.getPosition().y<150)soldierCurrrentPosition.y=330;

        // std::cout<<s_soldier.getPosition().x<<std::endl;
        ///animal move


        ///animal move
        //int goback=s_animal.getPosition().x;
        if(s_soldier.getPosition().x<screenWidth/2 || soldier_source.y==Right)
        {
            animalMove=Right;
            if(abs(s_soldier.getPosition().x-s_animal.getPosition().x)<200)animalMove=Left;
            s_animal.move(animalMoveSpeed*clock.getElapsedTime().asSeconds(),0);
        }
        else
        {

            animalMove=Down;
            if(abs(s_soldier.getPosition().x-s_animal.getPosition().x)<200)animalMove=Up;
            s_animal.move(-animalMoveSpeed*clock.getElapsedTime().asSeconds(),0);
        }

        s_animal.setTextureRect(IntRect(soldier_source.x*152,animalMove*117,150,115));

        ///man move first

        if(abs(s_soldier.getPosition().x-s_man.getPosition().x)<10) esc=true;

        if(esc)
        {
           s_man.setTextureRect(IntRect(soldier_source.x*165,1*200,165,160));
           s_man.move(-manSpeed*clock.getElapsedTime().asSeconds(),0);

        }
        else if(abs(s_soldier.getPosition().x-s_man.getPosition().x )<300)
        {
            //  s_man.setPosition(1203,200);
            s_man.setTextureRect(IntRect(soldier_source.x*170,0*200,170,200));

        }
         else s_man.setTextureRect(IntRect(1*170,0*200,170,200));



        if(s_man.getPosition().x-manNumber*130<= 0 )
        {
            manESCPosition.push_back(man(&t_manESC,s_man.getPosition()));
            manNumber++;
            esc=false;

            Vector2f manCurrentPosition(s_soldier.getPosition().x+500,s_man.getPosition().y);
            //man(&t_man,manCurrentPosition);
            s_man.setPosition(manCurrentPosition);
        }

        for(int i=0;i<manESCPosition.size();i++)
        {
            if(i%2==0)
            manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement1*130,0*180,130,180));

            else manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement2*130,0*180,130,180));


        }
        manESCTime+=clock.getElapsedTime();
        manESCTime2+=clock.getElapsedTime();

        if(manESCTime.asSeconds()>0.3)
        {
            manESCTime=seconds(0);
            happyMovement1++;

            if(happyMovement1>3){happyMovement1=0;}
        }
        if(manESCTime2.asSeconds()>0.2)
        {
            manESCTime2=seconds(0);
             happyMovement2++;
             if(happyMovement2>3)happyMovement2=0;

        }

        ///dragon
        if(abs(s_soldier.getPosition().x-s_dragon.getPosition().x)<600 && placeDragon==1)
        {
            if(placeDragon==1)
                s_dragon.setTextureRect(IntRect(dragonMove*180,1*110,180,110));
            else  s_dragon.setTextureRect(IntRect(dragonMove*180,0*110,180,110));

            s_dragon.move(-dragonMoveSpeed*clock.getElapsedTime().asSeconds(),0);
        }

        else if(abs(s_soldier.getPosition().x-s_dragon.getPosition().x)<600 && placeDragon==0)
        {
            if(placeDragon==0)
                s_dragon.setTextureRect(IntRect(dragonMove*180,0*110,180,110));
            else   s_dragon.setTextureRect(IntRect(dragonMove*180,1*110,180,110));

            s_dragon.move(dragonMoveSpeed*clock.getElapsedTime().asSeconds(),0);
        }


        if(time3.asSeconds()>40.0)
        {
            time3=seconds(0);
            placeDragon=rand()%2;
            if(placeDragon==1)
            {


                s_dragon.setPosition(s_soldier.getPosition().x+500,soldierCurrrentPosition.y+70);
            }
            else
            {
                //placeDragon=0;
                s_dragon.setPosition(s_soldier.getPosition().x-500,soldierCurrrentPosition.y+70);
            }

        }
        ///SOldier die here
        if(abs(s_dragon.getPosition().x-s_soldier.getPosition().x)<100 )
        {
            if(soldier_source.y==Right)
                s_soldier.setTextureRect(IntRect(DiedMove*180,12*180,180,180));
            else s_soldier.setTextureRect(IntRect(DiedMove*180,14*180,180,180));

            if(Diedtime.asSeconds()>0.5)
            {
                DiedMove++;
                if(DiedMove>4)
                {
                    if(soldier_source.y==Right)
                        s_soldier.setTextureRect(IntRect(4*180,12*180,180,180));
                    else s_soldier.setTextureRect(IntRect(4*180,14*180,180,180));

                }


            }
        }


        ///coin
        if(abs(coinPosition.x-s_soldier.getPosition().x)<3)
        {
            coinPosition.x+=500;
            if(coinPosition.x>screenWidth)coinPosition.x=400;

        }
        s_coin.setPosition(coinPosition.x,soldierCurrrentPosition.y);

        s_coin.setTextureRect(IntRect(coinMove*85,pointType*120,85,120));

        ///enemySoldier 's texture



            if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<100)
            {
                if(enemyBack)
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,1*180,110,180));
                }
                else if(enemyBackAgain)
                {
                    s_enemySoldier.setTextureRect((IntRect(soldier_source.x*110,6*180,110,180)));
                }

               else if(placeEnemySoldier==1)///
                s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,6*180,110,180));
                else
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,1*180,110,180));
                }
            }
            else if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<400)///shoot bulet
            {
                if(enemyBack)
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,0*180,110,180));
                    s_bulet.setTextureRect(IntRect(0*25,3*20,25,20));///bulet.png image
                   // s_bulet.move(buletSpeed*clock.getElapsedTime().asSeconds(),0);
                }
                else if(enemyBackAgain)
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,5*180,110,180));
                    s_bulet.setTextureRect(IntRect(1*25,3*20,25,20));///bulet.png image
                  //  s_bulet.move(-buletSpeed*clock.getElapsedTime().asSeconds(),0);
                }
                else  if(placeEnemySoldier==1)///
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,5*180,110,180));
                    s_bulet.setTextureRect(IntRect(1*25,3*20,25,20));///bulet.png image
                 }

                 else
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,0*180,110,180));
                    s_bulet.setTextureRect(IntRect(0*25,3*20,25,20));
                 }

            }

            else
            {
                if(enemyBack)
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,2*180,110,180));
                }
                else if(enemyBackAgain)
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,7*180,110,180));
                }
                else if(placeEnemySoldier==1)
                s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,7*180,110,180));
                else
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,2*180,110,180));
                 }
            }

         ///   enemy bulet && enemy_move

            if(enemyBack)
            {
                s_enemySoldier.move(enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
               // s_bulet.move(buletSpeed*clock.getElapsedTime().asSeconds(),0);
            }
            else if(enemyBackAgain)
            {
                s_enemySoldier.move(-enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
                //s_bulet.move(-buletSpeed*clock.getElapsedTime().asSeconds(),0);
            }


            else if(placeEnemySoldier==1)
            {

                    s_enemySoldier.move(-enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
                    //s_bulet.move(-buletSpeed*clock.getElapsedTime().asSeconds(),0);
            }
            else
            {
                    s_enemySoldier.move(enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
                   // s_bulet.move(buletSpeed*clock.getElapsedTime().asSeconds(),0);

            }



///  Enemy soldier place time




        if(enemyTime.asSeconds()>25.0)
        {
           //std::srand(time(NULL));
             placeEnemySoldier=rand()%2;
                 enemyBack=false;
                 enemyBackAgain=false;

            enemybuletPosition.clear();///clear all bulet

            enemyTime=seconds(0);



            if(placeEnemySoldier==1)
            {


                 s_enemySoldier.setPosition(s_soldier.getPosition().x+700,soldierCurrrentPosition.y);
            }
            else
            {
                 //placeEnemySoldier=0;
                 s_enemySoldier.setPosition(s_soldier.getPosition().x-700,soldierCurrrentPosition.y);

            }

            if(enemyBack)
            {
                s_enemybulet.setPosition(s_enemySoldier.getPosition().x+110,soldierCurrrentPosition.y+50);
            }
            else if(enemyBackAgain)
            {
                s_enemybulet.setPosition(s_enemySoldier.getPosition().x,soldierCurrrentPosition.y+50);
            }

           else if(placeEnemySoldier==1)s_bulet.setPosition(s_enemySoldier.getPosition().x,soldierCurrrentPosition.y+50);

            else s_bulet.setPosition(s_enemySoldier.getPosition().x+110,soldierCurrrentPosition.y+50);

        }
///work for this later
//        if(abs(s_bulet.getPosition().x-s_soldier.getPosition().x)<3 )///
//        {
//              if(placeEnemySoldier==1)s_bulet.setPosition(s_enemySoldier.getPosition().x,soldierCurrrentPosition.y+50);
//              else s_bulet.setPosition(s_enemySoldier.getPosition().x+110,soldierCurrrentPosition.y+50);
//        }

        enemyTime+=clock.getElapsedTime();

        /// bulet
        if(buletTime.asSeconds()>.20)
        {
            buletTime=seconds(0);
            buletMove++;
            if(buletMove>4)buletMove=0;

        }
        buletTime+=clock.getElapsedTime();

        time+=clock.getElapsedTime();

        if(dragonMove>4)dragonMove=0;

        if(time.asSeconds()>=0.15)
        {
            coinMove++;
            if(coinMove>9)coinMove=0;
            time=seconds(0);

        }
        time2+=clock.getElapsedTime();
        if(time2.asSeconds()>=0.1)
        {
            dragonMove++;
            time2=seconds(0);
        }


        time3+=clock.getElapsedTime();
        Diedtime+=clock.getElapsedTime();



        frameCounter+=frameSpeed*clock.restart().asSeconds();
        if(frameCounter>=switchFrame)
        {
            frameCounter=0;
            soldier_source.x++;
            if(soldier_source.x>3)soldier_source.x=0;

            // if(soldier_source.x*130>=t_soldier.getSize().x && soldier_source.x>3)soldier_source.x=0;

        }
        ///screen scrolling

        if(s_soldier.getPosition().x+100>screenDimentions.x/2)
        {
            soldierPosition.x=s_soldier.getPosition().x+100;
        }

        else soldierPosition.x=screenDimentions.x/2;


///my soldier setPosition here

        view.setCenter(soldierPosition);

        s_soldier.setPosition(soldierCurrrentPosition.x+s_soldier.getPosition().x,soldierCurrrentPosition.y);

        window.setView(view);
        window.draw(s_background);
        // window.draw(s_background2);
         for(int i=0;i<manESCPosition.size();i++)
        {
            window.draw(manESCPosition[i].s_manESC);
        }
        window.draw(s_man);

        window.draw(s_animal);
        window.draw(s_coin);
        if(time3.asSeconds()<12.0)
        {
            window.draw(s_dragon);
        }
        if(enemyTime.asSeconds()<20.0)
        {
            window.draw(s_enemySoldier);
          //  window.draw(s_bulet);
        }
        else enemybuletPosition.clear();

     /*   if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<300)///shoot
        window.draw(s_bulet);
        */

         for(int i=0;i<enemybuletPosition.size();i++)
        {
            window.draw(enemybuletPosition[i].s_enemybulet);
        }
        for(int i=0;i<buletPosition.size();i++)
        {
            window.draw(buletPosition[i].s_bulet);

        }


      //  if(enemybuletPosition.size()>5)enemybuletPosition.clear();




        window.draw(s_soldier);
        //window.setView(window.getDefaultView());



        window.display();
        window.clear();


    }

    return 0;
}
