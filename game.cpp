#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<string>

using namespace sf;


int main()
{
    RenderWindow window;
    Vector2i screenDimentions(1000,700);
    window.create(VideoMode(screenDimentions.x,screenDimentions.y),"Run For Life",Style::Titlebar | Style::Resize | Style::Close);
    ///window.setSize(Vector2u(500,500));
    /// window.setTitle("sfml new title");
    window.setKeyRepeatEnabled(false);
    int screenWidth=4160;

    window.setPosition(Vector2i(200,0));


    enum Direction {Right,Down,Left,Up};

    Texture t_background,t_soldier,t_man,t_animal,t_coin,t_dragon,t_enemySoldier,t_bulet;
    Sprite s_background,s_soldier,s_man,s_animal,s_coin,s_dragon,s_enemySoldier,s_bulet;
    std::cout<<"All move works ,Let's Play with arrow key";

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
    Vector2i soldier_source(0,0);

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
    s_man.setPosition(1203,soldierCurrrentPosition.y-105);
    s_man.setTextureRect(IntRect(soldier_source.x*255,0*265,255,265));
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
    int placeEnemySoldier=1;
    float enemySoldierSpeed=30.0f;

    ///bulet

    t_bulet.loadFromFile("Resources/bulet.png");
    s_bulet.setTexture(t_bulet);
 s_bulet.setPosition(soldierCurrrentPosition.x+700-150,soldierCurrrentPosition.y+50);
    float buletSpeed=200.0f;
    int buletMove=0;
     s_bulet.setTextureRect(IntRect(buletMove*25,7*20,25,20));




    Clock clock;
    Time time=seconds(0),time2=seconds(0),time3=seconds(0),Diedtime=seconds(0),enemyTime=seconds(0),buletTime=seconds(0);
    float movespeed=100.0f;
    float frameCounter=0,switchFrame=100,frameSpeed=600;
    float jumpSpeed=50.0f;

    View view;
    view.reset(FloatRect(0,0,screenDimentions.x,screenDimentions.y));
    view.setViewport(FloatRect(0,0,1.0f,1.0f));

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


        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)
            {
                if(soldier_source.y==Right)s_soldier.setTextureRect(IntRect(soldier_source.x*130,8*180,130,180));
                else s_soldier.setTextureRect(IntRect(soldier_source.x*130,9*180,130,180));
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))s_soldier.setTextureRect(IntRect(soldier_source.x*130,6*180,130,180));
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
        }
        else  s_soldier.setTextureRect(IntRect(soldier_source.x,soldier_source.y*180,130,180));

///texture crop & movement




///move

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

        ///man move
        if(abs(s_soldier.getPosition().x-s_man.getPosition().x)<10) esc=true;


        if(esc)
        {

            if(s_soldier.getPosition().x>screenWidth/2)
            {
                s_man.setTextureRect(IntRect(soldier_source.x*255,1*265,255,265));
                s_man.move(manSpeed*clock.getElapsedTime().asSeconds(),0);

            }
            else

            {
                s_man.setTextureRect(IntRect(soldier_source.x*255,2*265,255,265));
                s_man.move(-manSpeed*clock.getElapsedTime().asSeconds(),0);
            }



        }
        else if(abs(s_soldier.getPosition().x-s_man.getPosition().x )<400)
        {
            //  s_man.setPosition(1203,200);
            s_man.setTextureRect(IntRect(soldier_source.x*255,0*265,255,265));

        }
        else s_man.setTextureRect(IntRect(1*255,0*265,255,265));

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
            if(soldier_source.y==Right)
            {
                placeDragon=1;

                s_dragon.setPosition(s_soldier.getPosition().x+500,soldierCurrrentPosition.y+70);
            }
            else
            {
                placeDragon=0;
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

        ///enemySoldier

            if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<100)
            {
                if(placeEnemySoldier==1)
                s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,6*180,110,180));
                else
                {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,1*180,110,180));
                }
            }
            else if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<400)///shoot
            {
                 if(placeEnemySoldier==1)
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,5*180,110,180));
                    s_bulet.setTextureRect(IntRect(buletMove*25,7*20,25,20));
                 }

                 else
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,0*180,110,180));
                    s_bulet.setTextureRect(IntRect(buletMove*25,0*20,25,20));
                 }

            }
            else
            {
                if(placeEnemySoldier==1)
                s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,7*180,110,180));
                 else
                 {
                    s_enemySoldier.setTextureRect(IntRect(soldier_source.x*110,2*180,110,180));
                 }
            }

            if(placeEnemySoldier==1)
            {

                    s_enemySoldier.move(-enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
                    s_bulet.move(-buletSpeed*clock.getElapsedTime().asSeconds(),0);
            }
            else
            {
                    s_enemySoldier.move(enemySoldierSpeed*clock.getElapsedTime().asSeconds(),0);
                    s_bulet.move(buletSpeed*clock.getElapsedTime().asSeconds(),0);

            }




        if(enemyTime.asSeconds()>20.0)
        {
            enemyTime=seconds(0);
            if(soldier_source.y==Right)
            {
                 placeEnemySoldier=1;
                 s_enemySoldier.setPosition(s_soldier.getPosition().x+700,soldierCurrrentPosition.y);

            }
            else
            {
                 placeEnemySoldier=0;
                 s_enemySoldier.setPosition(s_soldier.getPosition().x-700,soldierCurrrentPosition.y);

            }

            if(placeEnemySoldier==1)s_bulet.setPosition(s_enemySoldier.getPosition().x,soldierCurrrentPosition.y+50);
            else s_bulet.setPosition(s_enemySoldier.getPosition().x+110,soldierCurrrentPosition.y+50);

        }

        if(abs(s_bulet.getPosition().x-s_soldier.getPosition().x)<3 )
        {
              if(placeEnemySoldier==1)s_bulet.setPosition(s_enemySoldier.getPosition().x,soldierCurrrentPosition.y+50);
              else s_bulet.setPosition(s_enemySoldier.getPosition().x+110,soldierCurrrentPosition.y+50);
        }

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


        view.setCenter(soldierPosition);
        s_soldier.setPosition(soldierCurrrentPosition.x+s_soldier.getPosition().x,soldierCurrrentPosition.y);

        window.setView(view);
        window.draw(s_background);
        // window.draw(s_background2);
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
            window.draw(s_bulet);
        }
        if(abs(s_soldier.getPosition().x-s_enemySoldier.getPosition().x)<300)///shoot
        window.draw(s_bulet);




        window.draw(s_soldier);
        //window.setView(window.getDefaultView());



        window.display();
        window.clear();


    }

    return 0;
}
