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

    Texture t_background,t_soldier,t_man,t_animal,t_coin;
    Sprite s_background,s_soldier,s_man,s_animal,s_coin;
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


      Vector2f soldierPosition(screenDimentions.x/2,screenDimentions.y/2);

    ///animal

    t_animal.loadFromFile("Resources/animal.png");
    s_animal.setTexture(t_animal);
    s_animal.setPosition(soldierCurrrentPosition.x-30,soldierCurrrentPosition.y+40);

    float animalMoveSpeed=100.0f;
     int animalMove=Right;

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





    Clock clock;
    Time time=seconds(0),time2=seconds(0);
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
                 else {
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
           if(s_soldier.getPosition().x<screenWidth/2)
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
           else if(abs(s_soldier.getPosition().x-s_man.getPosition().x )<450)
           {
              //  s_man.setPosition(1203,200);
                 s_man.setTextureRect(IntRect(soldier_source.x*255,0*265,255,265));

           }
           else s_man.setTextureRect(IntRect(1*255,0*265,255,265));

           ///coin
       if(abs(coinPosition.x-s_soldier.getPosition().x)<3)
       {
           coinPosition.x+=500;
           if(coinPosition.x>screenWidth)coinPosition.x=400;

       }
        s_coin.setPosition(coinPosition.x,soldierCurrrentPosition.y);

           s_coin.setTextureRect(IntRect(coinMove*85,pointType*120,85,120));


        time2=clock.getElapsedTime();
        time+=time2;
        if(time.asSeconds()>=0.15)
        {
            coinMove++;
           if(coinMove>9)coinMove=0;
           time=seconds(0);

        }





 frameCounter+=frameSpeed*clock.restart().asSeconds();
        if(frameCounter>=switchFrame)
        {
            frameCounter=0;
            soldier_source.x++;
            if(soldier_source.x*125>=t_soldier.getSize().x)soldier_source.x=0;

        }
        ///screen scrolling
       if(s_soldier.getPosition().x+10>screenDimentions.x/2)
       soldierPosition.x=s_soldier.getPosition().x+10;
       else soldierPosition.x=screenDimentions.x/2;


       view.setCenter(soldierPosition);
        s_soldier.setPosition(soldierCurrrentPosition.x+s_soldier.getPosition().x,soldierCurrrentPosition.y);



        window.setView(view);
        window.draw(s_background);
       // window.draw(s_background2);
       window.draw(s_man);

        window.draw(s_animal);
        window.draw(s_coin);
         window.draw(s_soldier);
        //window.setView(window.getDefaultView());



        window.display();
        window.clear();


    }

    return 0;
}
