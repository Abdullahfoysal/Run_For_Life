#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using namespace sf;

int win_x=1000;
int win_y=700;
int screenWidth=4160;///border of gamescreen


///score count
Vector2f strength_level(100,10);
 int manNumber=0;
 int enemyNumber=15;
 int creatEnemy=enemyNumber;
 bool creatENEMY=false;

 ///man hit by enemy

 bool ManRun=false;
 int ManHitted=3;
 int ManHitCount=0;
 bool ManDied=false;

 Vector2f ManHealth_level(100,10);





float strength=0.f;
int coinCount=0;
int lifeCount=3;
int moneyCount=0;
int my_soldier_hit=0;
int my_soldierHit=4;
bool my_soldier_died=false;
 float diedTime=0.f;
 float mybuletSpeed=1.5f;



enum Direction {Right,Down,Left,Up};

sf::Vector2i soldier_source(0,0);
Vector2f soldierCurrrentPosition(0,330);
Vector2f soldierPosition(win_x/2,win_y/2);

float frameCounter=0,switchFrame=100,frameSpeed=600;
float movespeed=230.0f;
 float soldierJumpSpeed=5.0f;
   float soldierJumpHeight=200;


   //bulet
   int buletMove=0;
   float my_buletTime=0.f;
    float enemyBuletSpeed=1.0f;

   float enemyTime=0.f;
   float enemySoldierSpeed=30.0f;
   bool enemyBack[50],enemyBackAgain[50];
   float  enemybuletTime=0.f;
   std::vector<bool>enemy_direction;
   int enemyHit=4;
   int enemy_hit[50];
   bool enemy_died[50];
   float enemy_diedTime=0.f;

   ///man
   float man_time=0.f;
   int manCry=0;
   bool man_esc=false;
   float manSpeed=100.0f;

   int happyMovement1=0;
    int happyMovement2=0;
    float manESCTime=0.f,manESCTime2=0.f;

    ///coin
    int coinMove=0,pointType=0;
    int coinNumber=15;
    float coinMovetime=0.f;

    int creatCoinNumber=coinNumber;
    bool creatCoin=false;

    ///menu

    int text_y=50;
    float key=0.f;

    bool home=true;
    bool playy=false;
    bool challenge=false;
    bool soundd=false;
    bool instructions=false;
    bool aboutt=false;
    bool exitt=false;

    bool challenge_select[6];

    ///challenge of game
    int ManCount=5;
 int CoinCount=20;
 ///main three loop
 bool menu=true;
 bool gameover=false;
 bool win=false;

 ///result of game
 int manEscaped=0;
 int coinGain=0;




RenderWindow window(VideoMode(win_x,win_y),"Run For Life",Style::Titlebar | Style::Resize | Style::Close);

struct Load
{
  Sprite s_sprite;
  Texture t_texture;
  Clock clock;
  Time time;


};
class winn
{
  public:
  Font font1;

  Text game_win_text,playAgain,exit_txt,backk;




    void load_end()
    {
         font1.loadFromFile("Resources/Hunters.otf");

         game_win_text.setString("Game Win");
         game_win_text.setFont(font1);
          game_win_text.setCharacterSize(80);
          game_win_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          game_win_text.setPosition(200+80,-30);
          game_win_text.setFillColor(Color::Magenta);

           playAgain.setString("Play Again");
         playAgain.setFont(font1);
          playAgain.setCharacterSize(40);
          playAgain.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          playAgain.setPosition(400,100+text_y*1);
          playAgain.setFillColor(Color::Yellow);



             backk.setString("Back");
         backk.setFont(font1);
          backk.setCharacterSize(40);
          backk.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          backk.setPosition(400,100+text_y*2);
          backk.setFillColor(Color::Yellow);

            exit_txt.setString("Exit");
         exit_txt.setFont(font1);
          exit_txt.setCharacterSize(40);
          exit_txt.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          exit_txt.setPosition(400,100+text_y*3);
          exit_txt.setFillColor(Color::Yellow);

        }

    void end_text_color()
    {
       playAgain.setFillColor(Color::Yellow);
       exit_txt.setFillColor(Color::Yellow);
       backk.setFillColor(Color::Yellow);
    }
    void show_end()
    {
      window.draw(game_win_text);
      window.draw(playAgain);
      window.draw(exit_txt);
      window.draw(backk);
    }

};



class eend
{
public:
  Font font1;

  Text gameover_text,playAgain,exit_txt,backk;




    void load_end()
    {
         font1.loadFromFile("Resources/Hunters.otf");

         gameover_text.setString("Game Over");
         gameover_text.setFont(font1);
          gameover_text.setCharacterSize(80);
          gameover_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          gameover_text.setPosition(200,-30);
          gameover_text.setFillColor(Color::Red);

           playAgain.setString("Play Again");
         playAgain.setFont(font1);
          playAgain.setCharacterSize(40);
          playAgain.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          playAgain.setPosition(400,100+text_y*1);
          playAgain.setFillColor(Color::Yellow);



             backk.setString("Back");
         backk.setFont(font1);
          backk.setCharacterSize(40);
          backk.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          backk.setPosition(400,100+text_y*2);
          backk.setFillColor(Color::Yellow);

            exit_txt.setString("Exit");
         exit_txt.setFont(font1);
          exit_txt.setCharacterSize(40);
          exit_txt.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          exit_txt.setPosition(400,100+text_y*3);
          exit_txt.setFillColor(Color::Yellow);






    }
    void end_text_color()
    {
       playAgain.setFillColor(Color::Yellow);
       exit_txt.setFillColor(Color::Yellow);
       backk.setFillColor(Color::Yellow);
    }
    void show_end()
    {
      window.draw(gameover_text);
      window.draw(playAgain);
      window.draw(exit_txt);
      window.draw(backk);
    }




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

class coint
{
    public:
    Sprite s_coint;
    coint (Texture *texture)
    {

        s_coint.setTexture(*texture);

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
std::string To_string(int n)
   {
      std::string s="";
      if(n==0)return "0";
      while(n)
      {
        s+=(n%10+'0');
        n/=10;
      }
      reverse(s.begin(),s.end());
      return s;
   }


void diedtime()
{
   if(diedTime>5.0)
        {
          my_soldier_died=false;
          diedTime=0.f;


        }
}
//my_soldier bulet
     std::vector<bulet>buletPosition;

    std::vector<bool>soldier_buletDirection;
 //enemy_soldier
    std::vector<enemy>full_enemy;


   std::vector<enemybulet>enemybuletPosition[50];

   ///manEscape
    std::vector<mann>manESCPosition;

    ///coin vector
    std::vector<coint>cointPosition;



void init()
{


    for(int i=0;i<full_enemy.size();i++)
    {

      enemybuletPosition[i].clear();

    }
    for(int i=0;i<50;i++)
    {

        enemy_hit[i]=0;
        enemy_died[i]=false;
         enemyBack[i]=false;
      enemyBackAgain[i]=false;
    }
     enemyHit=3;
    full_enemy.clear();
     enemy_direction.clear();
      creatEnemy=enemyNumber;

     /* creatENEMY=true;
      creatEnemy<=3*/


}

class game_menu
{
   public:
  Font font1;
  Text game_text, play_text,challenge_text,sound_txt,instruction_text,about_text,exit_text;
  Text c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,backk;
  Text challenge_view,coin_view,man_view,coin_view2,man_view2,challenge_viewCount;
  Text go_back_man;

  Texture t_menu[3];
  Sprite s_menu[3];

  void load_menu_background()
  {
    t_menu[0].loadFromFile("Resources/menubackground.jpg");
    s_menu[0].setTexture(t_menu[0]);

    t_menu[1].loadFromFile("Resources/menu11.png");
    s_menu[1].setTexture(t_menu[1]);
    s_menu[1].setPosition(0,390);

    t_menu[2].loadFromFile("Resources/menu2.png");
    s_menu[2].setTexture(t_menu[2]);
    s_menu[2].setPosition(700,420);


  }
  void menu_background_show()
  {
    window.draw(s_menu[0]);
    window.draw(s_menu[1]);
    window.draw(s_menu[2]);
  }

    void load_text()
    {
       font1.loadFromFile("Resources/Hunters.otf");


        game_text.setString("Run For Life");
         game_text.setFont(font1);
          game_text.setCharacterSize(80);
          game_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          game_text.setPosition(200,-30);
          game_text.setFillColor(Color::Red);
          game_text.setOutlineThickness(2);
          game_text.setOutlineColor(Color::Black);

         play_text.setString("Play");
         play_text.setFont(font1);
          play_text.setCharacterSize(40);
          play_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          play_text.setPosition(400,100+text_y*1);
          play_text.setFillColor(Color::Yellow);

            play_text.setOutlineThickness(2);
          play_text.setOutlineColor(Color::Black);

          challenge_text.setString("Challenge");
         challenge_text.setFont(font1);
          challenge_text.setCharacterSize(40);
          challenge_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          challenge_text.setPosition(400-25,100+text_y*2);
          challenge_text.setFillColor(Color::Yellow);

           challenge_text.setOutlineThickness(2);
           challenge_text.setOutlineColor(Color::Black);

            sound_txt.setString("Sound");
         sound_txt.setFont(font1);
          sound_txt.setCharacterSize(40);
          sound_txt.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          sound_txt.setPosition(400,100+text_y*3);
          sound_txt.setFillColor(Color::Yellow);
            sound_txt.setOutlineThickness(2);
            sound_txt.setOutlineColor(Color::Black);


            instruction_text.setString("Instructions");
         instruction_text.setFont(font1);
          instruction_text.setCharacterSize(40);
          instruction_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          instruction_text.setPosition(400-25,100+text_y*4);
          instruction_text.setFillColor(Color::Yellow);

          instruction_text.setOutlineThickness(2);
            instruction_text.setOutlineColor(Color::Black);

            about_text.setString("About");
         about_text.setFont(font1);
          about_text.setCharacterSize(40);
          about_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          about_text.setPosition(400,100+text_y*5);
          about_text.setFillColor(Color::Yellow);

          about_text.setOutlineThickness(2);
            about_text.setOutlineColor(Color::Black);

            exit_text.setString("Quit");
         exit_text.setFont(font1);
          exit_text.setCharacterSize(40);
          exit_text.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          exit_text.setPosition(400,100+text_y*6);
          exit_text.setFillColor(Color::Yellow);

             exit_text.setOutlineThickness(2);
             exit_text.setOutlineColor(Color::Black);


            challenge_view.setString("Mission:");
         challenge_view.setFont(font1);
          challenge_view.setCharacterSize(40);
          challenge_view.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          challenge_view.setFillColor(Color::Red);

            challenge_view.setOutlineThickness(2);
             challenge_view.setOutlineColor(Color::Black);



         challenge_viewCount.setFont(font1);
          challenge_viewCount.setCharacterSize(40);
          challenge_viewCount.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          challenge_viewCount.setFillColor(Color::Red);

          coin_view.setString("Money :");
         coin_view.setFont(font1);
          coin_view.setCharacterSize(30);
          coin_view.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          coin_view.setFillColor(Color::Yellow);

          man_view.setString("Man :");
          man_view.setFont(font1);
          man_view.setCharacterSize(30);
          man_view.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          man_view.setFillColor(Color::Green);


          coin_view2.setFont(font1);
          coin_view2.setCharacterSize(30);
          coin_view2.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          coin_view2.setFillColor(Color::Red);


          man_view2.setFont(font1);
          man_view2.setCharacterSize(30);
          man_view2.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          man_view2.setFillColor(Color::Red);

           go_back_man.setString("Ready to Run.. ");
         go_back_man.setFont(font1);
          go_back_man.setCharacterSize(30);
          go_back_man.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          go_back_man.setFillColor(Color::Green);










    }
    void text_color(char colour)
    {


       if(colour=='G')
      {

      play_text.setFillColor(Color::Green);
      challenge_text.setFillColor(Color::Green);
      sound_txt.setFillColor(Color::Green);
      instruction_text.setFillColor(Color::Green);
      about_text.setFillColor(Color::Green);
      exit_text.setFillColor(Color::Green);

      }
      else
      {
         play_text.setFillColor(Color::Yellow);
      challenge_text.setFillColor(Color::Yellow);
      sound_txt.setFillColor(Color::Yellow);
      instruction_text.setFillColor(Color::Yellow);
      about_text.setFillColor(Color::Yellow);
      exit_text.setFillColor(Color::Yellow);

      }
    }
    void show_text()
    {

      window.draw(game_text);
      window.draw(play_text);
      window.draw(challenge_text);
      window.draw(sound_txt);
      window.draw(instruction_text);
      window.draw(about_text);
      window.draw(exit_text);
    }

    void challenge_full_text()
    {
         c1.setString("Mission:1-> Escape 5 Man and Earn Coins 20");
         c1.setFont(font1);
          c1.setCharacterSize(40);
          c1.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          c1.setPosition(100,100+text_y*1);
          c1.setFillColor(Color::Yellow);

          c2.setString("Mission:2-> Escape 10 Man and Earn Coins 40");
         c2.setFont(font1);
          c2.setCharacterSize(40);
          c2.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          c2.setPosition(100,100+text_y*2);
          c2.setFillColor(Color::Yellow);

           c3.setString("Mission:3-> Escape 15 Man and Earn Coins 60");
         c3.setFont(font1);
          c3.setCharacterSize(40);
          c3.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          c3.setPosition(100,100+text_y*3);
          c3.setFillColor(Color::Yellow);

          c4.setString("Mission:4-> Escape 20 Man and Earn Coins 80");
          c4.setFont(font1);
          c4.setCharacterSize(40);
          c4.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          c4.setPosition(100,100+text_y*4);
          c4.setFillColor(Color::Yellow);


          c5.setString("Mission:5-> Escape 30 Man and Earn Coins 100");
          c5.setFont(font1);
          c5.setCharacterSize(40);
          c5.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          c5.setPosition(100,100+text_y*5);
          c5.setFillColor(Color::Yellow);

        backk.setString("Back");
         backk.setFont(font1);
          backk.setCharacterSize(40);
          backk.setScale(1.5f,1.5f);
          //gametxt.setFillColor(Color::Red);
          backk.setPosition(400,100+text_y*6);
          backk.setFillColor(Color::Yellow);
    }
    void challenge_text_color()
    {
      c1.setFillColor(Color::Yellow);
      c2.setFillColor(Color::Yellow);
      c3.setFillColor(Color::Yellow);
      c4.setFillColor(Color::Yellow);
      c5.setFillColor(Color::Yellow);
      backk.setFillColor(Color::Yellow);

    }

    void challenge_text_show()
    {
      window.draw(c1);
      window.draw(c2);
      window.draw(c3);
      window.draw(c4);
      window.draw(c5);
      window.draw(backk);
    }

};

class GameMusic
{
   public:
  Music menu_music,game_music,shoot_music,enemyshoot,enemystab,mystab,coin_music,end_music;

  void load_music()
  {
     menu_music.openFromFile("Resources/menu_music.wav");
     menu_music.setVolume(1000);

     game_music.openFromFile("Resources/game_music.wav");
     game_music.setVolume(80);

     shoot_music.openFromFile("Resources/gunshoot.wav");
     shoot_music.setVolume(1000);

     enemyshoot.openFromFile("Resources/enemybulet2.wav");

     enemystab.openFromFile("Resources/enemystab.wav");
     enemystab.setVolume(20);

     mystab.openFromFile("Resources/my_stab.wav");
     mystab.setVolume(1000);

     coin_music.openFromFile("Resources/coin.wav");
     coin_music.setVolume(1000);

     end_music.openFromFile("Resources/endmusic.wav");
     end_music.setVolume(1000);



  }




};

void play_Again()
{

    for(int i=0;i<full_enemy.size();i++)
    {

      enemybuletPosition[i].clear();

    }
    for(int i=0;i<50;i++)
    {

        enemy_hit[i]=0;
        enemy_died[i]=false;
         enemyBack[i]=false;
      enemyBackAgain[i]=false;
    }
     enemyHit=4;
    full_enemy.clear();
     enemy_direction.clear();
      creatEnemy=enemyNumber;


      manNumber=0;

      coinCount=0;
     lifeCount=3;
    moneyCount=0;

    ///strength full  ///man full strength
    strength_level.x=100;
    my_soldier_hit=0;
    diedTime=0.f;
    my_soldier_died=false;
     diedTime=0.f;

//result ==0
    manEscaped=0;
   coinGain=0;

///escaped man[0]
///man hit by enemy

   manESCPosition.clear();
  ManRun=false;
  ManHitted=3;
  ManHitCount=0;
  ManDied=false;

 Vector2f ManHealth_level(100,10);

///coin=0
    cointPosition.clear();
    creatCoinNumber=4;///then creat coin


///clear all enemy and their direction and bullet
     init();
     ///clock restart









}


int main()
{
  ///score
   challenge_select[1]=true;

    window.setPosition(Vector2i(200,0));
    window.setKeyRepeatEnabled(false);

    View view;
    view.reset(FloatRect(0,0,win_x,win_y));
    view.setViewport(FloatRect(0,0,1.0f,1.0f));


     RectangleShape strength_rect,ManHealth_rect;
    strength_rect.setSize(strength_level);
    strength_rect.setFillColor(Color::Green);

    ManHealth_rect.setSize(strength_level);
    ManHealth_rect.setFillColor(Color::Green);
    ManHealth_rect.setOutlineThickness(2.0f);
    ManHealth_rect.setOutlineColor(Color::Black);



    std::string Score_str;



    Load background[5],my_soldier,enemy_soldier,my_bulet[2],enemy_bulet[2],
    my_clock,my_buletclock,stab_clock,stab2_clock,life[4],money,man[3],coin;

    Clock menu_clock;

     Font font1,font2,font3,font4;
    font1.loadFromFile("Resources/Hunters.otf");
////score count

    Text life_text,strength_text,coin_text,coinCount_text,manCount_text,
    helpmetxt;

    life_text.setString("Life :");
    life_text.setFont(font1);
    life_text.setCharacterSize(30);
    life_text.setScale(1.5f,1.5f);
    life_text.setFillColor(Color::Green);


     strength_text.setString("Strength :");
     strength_text.setFont(font1);
     strength_text.setCharacterSize(30);
     strength_text.setScale(1.5f,1.5f);
     strength_text.setFillColor(Color::Magenta);

     coin_text.setString("Money:");
     coin_text.setFont(font1);
     coin_text.setCharacterSize(30);
     coin_text.setScale(1.5f,1.5f);
     coin_text.setFillColor(Color::Yellow);

     coinCount_text.setFont(font1);
     coinCount_text.setCharacterSize(40);
     coinCount_text.setScale(1.f,1.f);
     coinCount_text.setFillColor(Color::Yellow);

     manCount_text.setFont(font1);
     manCount_text.setCharacterSize(80);
     manCount_text.setScale(1.f,1.f);
     manCount_text.setFillColor(Color::Green);

     helpmetxt.setString("Help!");
     helpmetxt.setFont(font1);
     helpmetxt.setCharacterSize(30);
     helpmetxt.setScale(1.0f,1.0f);
     helpmetxt.setFillColor(Color::White);

    background[0].t_texture.loadFromFile("Resources/background.png");
    background[0].s_sprite.setTexture(background[0].t_texture);

    my_soldier.t_texture.loadFromFile("Resources/soldier.png");
    my_soldier.s_sprite.setTexture(my_soldier.t_texture);
    my_soldier.s_sprite.setPosition(soldierCurrrentPosition.x,soldierCurrrentPosition.y);
    my_soldier.t_texture.setSmooth(true);

    enemy_soldier.t_texture.loadFromFile("Resources/enemySoldier.png");
    enemy_soldier.s_sprite.setTexture(enemy_soldier.t_texture);
    enemy_soldier.t_texture.setSmooth(true);

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
    money.t_texture.loadFromFile("Resources/manESC2.png");
    money.s_sprite.setTexture(money.t_texture);
    money.s_sprite.setScale(0.5f,0.5f);
    money.s_sprite.setRotation(-360.f);


    //man escape running
    man[0].t_texture.loadFromFile("Resources/man.png");
    man[0].s_sprite.setTexture(man[0].t_texture);
    man[0].t_texture.setSmooth(true);

    man[1].t_texture.loadFromFile("Resources/manESC.png");
    man[1].s_sprite.setTexture(man[1].t_texture);
    man[1].t_texture.setSmooth(true);

    man[2].t_texture.loadFromFile("Resources/manESC.png");
    man[2].s_sprite.setTexture(man[2].t_texture);

     man[0].s_sprite.setPosition(my_soldier.s_sprite.getPosition().x+500,soldierCurrrentPosition.y-60);
     man[0].s_sprite.setTextureRect(IntRect(0*165,0*200,165,200));

   // t_man.loadFromFile("Resources/man.png");
    ///coin
   coin.t_texture.loadFromFile("Resources/coin.png");
   coin.s_sprite.setTexture(coin.t_texture);
   coin.s_sprite.setScale(0.6f,0.6f);
   coin.t_texture.setSmooth(true);

    Vector2f coinPosition(500,400);
    coin.s_sprite.setPosition(coinPosition.x,coinPosition.y);

      srand(time(NULL));

     for(int i=0;i<coinNumber;i++)
            {
                cointPosition.push_back(coint(&coin.t_texture));

                 float pos=rand()%(screenWidth+150);

                cointPosition[i].s_coint.setPosition(pos,coinPosition.y);

                for(int j=i+1;j<cointPosition.size();j++)
                {
                  if(abs(cointPosition[i].s_coint.getPosition().x-cointPosition[j].s_coint.getPosition().x<30))
                  {
                    cointPosition.erase(cointPosition.begin()+j);
                    creatCoinNumber--;
                  }

                }

            }


            GameMusic music;
            music.load_music();

            music.menu_music.play();

        game_menu menu_text;
         menu_text.load_text();
         menu_text.challenge_full_text();
         menu_text.load_menu_background();

         eend End;
         End.load_end();

         winn Win;
         Win.load_end();


       unsigned menuselect=1;



  while(window.isOpen())
  {


    Event event;
    while(window.pollEvent(event))
    {
       switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            /*case Event::KeyPressed:
                if(event.key.code==Keyboard::Escape)
                    window.close();
                break;*/
            }
    }

 if(menu)
  {
            music.menu_music.setLoop(true);
            menu_text.menu_background_show();


           key=menu_clock.getElapsedTime().asSeconds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && key>0.2)
            {
                menuselect++;
                menu_clock.restart();

            }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && key>0.2)
            {
                menuselect--;
               menu_clock.restart();
            }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && key>0.2)
            {
                menu=true;
               menu_clock.restart();
            }
      else if(Keyboard::isKeyPressed(Keyboard::BackSpace)  && key>0.2)
            {
                menu_clock.restart();

              if(playy)
              {

                playy=false;
                home=true;

              }
              else if(challenge)
              {
                challenge=false;
                home=true;
              }
              else if(soundd)
              {
                soundd=false;
                home=true;
              }
              else if(instructions)
              {
                instructions=false;
                home=true;
              }
              else if(aboutt)
              {
                aboutt=false;
                home=true;
              }
              else if(exitt)
              {
                exitt=false;
                home=true;
              }

            }
       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && key>0.2)
       {
          menu_clock.restart();
          if(!playy && !challenge && !soundd && !instructions && !aboutt )
          {
            if(menuselect%6==1)
            {
               menu=false;
               music.menu_music.stop();
               music.game_music.play();

            }
            else if(menuselect%6==2)
            {
              challenge=true;
              home=false;
              menuselect=1;
            }
            else if(menuselect%6==3)
            {
              soundd=true;
              home=false;
            }
            else if(menuselect%6==4)
            {
              instructions=true;
              home=false;
            }
            else if(menuselect%6==5)
            {
              aboutt=true;
              home=false;
            }
            else if(menuselect%6==0)
            {
              exitt=true;
              home=false;
              window.close();
            }

          }
          else if(challenge)
          {



            if(menuselect%6==1)
            {
              ManCount=5;
              CoinCount=20;
              for(int i=0;i<5;i++)
              {
                challenge_select[i]=false;

              }
               challenge_select[menuselect%6]=true;
               play_Again();
            }
            else if(menuselect%6==2)
            {
              ManCount=10;
              CoinCount=40;
              for(int i=0;i<5;i++)
              {
                challenge_select[i]=false;
              }

               challenge_select[menuselect%6]=true;
               play_Again();
            }
            else if(menuselect%6==3)
            {
              ManCount=15;
              CoinCount=60;
              for(int i=0;i<5;i++)
              {
                challenge_select[i]=false;
              }

               challenge_select[menuselect%6]=true;
               play_Again();
            }
            else if(menuselect%6==4)
            {
              ManCount=20;
              CoinCount=80;
              for(int i=0;i<5;i++)
              {
                challenge_select[i]=false;
              }

               challenge_select[menuselect%6]=true;
               play_Again();
            }
            else if(menuselect%6==5)
            {
              ManCount=30;
              CoinCount=100;
              for(int i=0;i<5;i++)
              {
                challenge_select[i]=false;
              }

               challenge_select[menuselect%6]=true;
               play_Again();
            }
            else if(menuselect%6==0)
            {
              home=true;
              challenge=false;
              menuselect=2;
            }

          }
       }


    if(home)
    {
         menu_text.text_color('Y');

        if(menuselect%6==1)
        {
          menu_text.play_text.setFillColor(Color::Green);

        }
        else if(menuselect%6==2)
        {
          menu_text.challenge_text.setFillColor(Color::Green);
        }
        else if(menuselect%6==3)
        {
          menu_text.sound_txt.setFillColor(Color::Green);
        }
        else if(menuselect%6==4)
        {
          menu_text.instruction_text.setFillColor(Color::Green);
        }
        else if(menuselect%6==5)
        {
          menu_text.about_text.setFillColor(Color::Green);
        }
       else if(menuselect%6==0)
        {
          menu_text.exit_text.setFillColor(Color::Green);
        }


        menu_text.show_text();
    }
    else if(challenge)
    {
         menu_text.challenge_text_color();

        if(menuselect%6==1)
        {
          menu_text.c1.setFillColor(Color::Green);
        }
        else if(menuselect%6==2)
        {
          menu_text.c2.setFillColor(Color::Green);
        }
        else if(menuselect%6==3)
        {
          menu_text.c3.setFillColor(Color::Green);
        }
        else if(menuselect%6==4)
        {
          menu_text.c4.setFillColor(Color::Green);
        }
        else if(menuselect%6==5)
        {
          menu_text.c5.setFillColor(Color::Green);
        }
        else if(menuselect%6==0)
        {
          menu_text.backk.setFillColor(Color::Red);
        }



         if(challenge_select[1]) menu_text.c1.setFillColor(Color::Red);
         else if(challenge_select[2]) menu_text.c2.setFillColor(Color::Red);
         else if(challenge_select[3]) menu_text.c3.setFillColor(Color::Red);
         else if(challenge_select[4]) menu_text.c4.setFillColor(Color::Red);
         else if(challenge_select[5]) menu_text.c5.setFillColor(Color::Red);

         menu_text.challenge_text_show();

    }
    else if(soundd)
    {

    }
    else if(instructions)
    {

    }
    else if(aboutt)
    {

    }



  }
else if(win)
{
   window.draw(menu_text.s_menu[0]);
   Win.end_text_color();

    key=menu_clock.getElapsedTime().asSeconds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && key>0.2)
            {
                menuselect++;
                menu_clock.restart();

            }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && key>0.2)
            {
                menuselect--;
               menu_clock.restart();
            }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && key>0.2)
            {

              menu_clock.restart();

              if(menuselect%3==1)
              {
                 Win.playAgain.setFillColor(Color::Red);

                 win=false;
                 menu=false;
                 play_Again();
                 music.game_music.play();
              }
              else if(menuselect%3==2)
              {
                Win.backk.setFillColor(Color::Red);
                home=true;
                win=false;
                menu=true;

                 play_Again();
                 menuselect=1;

                 /*music.end_music.stop();
                 music.menu_music.play();*/
              }
              else if(menuselect%3==0)
              {
                Win.exit_txt.setFillColor(Color::Red);
                window.close();
              }

            }

            if(menuselect%3==1)
              {
                 Win.playAgain.setFillColor(Color::Green);
              }
              else if(menuselect%3==2)
              {
                Win.backk.setFillColor(Color::Red);

              }
              else if(menuselect%3==0)
              {
                Win.exit_txt.setFillColor(Color::Red);

              }




  Win.show_end();


       manESCTime+=my_clock.clock.getElapsedTime().asSeconds();
        manESCTime2+=my_clock.clock.getElapsedTime().asSeconds();


         for(int i=0;i<manESCPosition.size();i++)
        {
            if(i%2==0)
            manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement1*100,0*150,100,150));

            else manESCPosition[i].s_manESC.setTextureRect(IntRect(happyMovement2*100,0*150,100,150));


        }

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
             manESCPosition[i].s_manESC.setPosition(manESCPosition[i].s_manESC.getPosition().x,soldierCurrrentPosition.y+225);
            window.draw(manESCPosition[i].s_manESC);
        }


my_clock.clock.restart();

}
else if(gameover)
{
    music.end_music.setLoop(true);

  window.draw(menu_text.s_menu[0]);
  End.end_text_color();

     key=menu_clock.getElapsedTime().asSeconds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && key>0.2)
            {
                menuselect++;
                menu_clock.restart();

            }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && key>0.2)
            {
                menuselect--;
               menu_clock.restart();
            }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && key>0.2)
            {

              menu_clock.restart();
              if(menuselect%3==1)
              {
                 End.playAgain.setFillColor(Color::Red);
              
                 gameover=false;
                 menu=false;

                    play_Again();
                  music.end_music.stop();
                  music.game_music.play();


              }
              else if(menuselect%3==2)
              {
                End.backk.setFillColor(Color::Red);
                menu=true;
                home=true;
                gameover=false;
                menuselect=1;

                 play_Again();

                 music.end_music.stop();
                 music.menu_music.play();

              }
              else if(menuselect%3==0)
              {
                End.exit_txt.setFillColor(Color::Red);
                window.close();
              }
            }

             if(menuselect%3==1)
              {
                 End.playAgain.setFillColor(Color::Green);
              }
              else if(menuselect%3==2)
              {
                End.backk.setFillColor(Color::Green);

              }
              else if(menuselect%3==0)
              {
                End.exit_txt.setFillColor(Color::Green);

              }




  End.show_end();
}
else if(!menu)
  {
        ///go to game over
        if(lifeCount<0)
        {
          my_soldier.s_sprite.setPosition(soldierCurrrentPosition);
          gameover=true;
          music.game_music.stop();
          music.end_music.play();
          menuselect=1;
             my_clock.clock.restart();
             enemyTime=0.f;
        }
        else if(ManCount<=manEscaped && CoinCount<=coinGain)
        {
           my_soldier.s_sprite.setPosition(soldierCurrrentPosition);
           win=true;
           music.game_music.stop();
           menuselect=1;

              my_clock.clock.restart();
              enemyTime=0.f;

        }









        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            menu=true;
            music.game_music.stop();
            music.menu_music.play();

            my_soldier.s_sprite.setPosition(soldierCurrrentPosition);
          }

      music.game_music.setLoop(true);

      window.draw(background[0].s_sprite);


     diedtime();
     my_soldier_died_Check();

     if(my_soldier_died)
         {
             buletPosition.clear();
             soldier_buletDirection.clear();
         }

     diedTime+=my_clock.clock.getElapsedTime().asSeconds();

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
                if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,8*180+2,130,180));
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

                     music.shoot_music.play();

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
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,0*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));

             if(Keyboard::isKeyPressed(Keyboard::S) && !my_soldier_died && my_buletTime>0.2)
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

                     music.shoot_music.play();
                     //music.shoot_music.setVolume(1000);

              }

        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            soldier_source.y=Left;
            if(event.type==Event::KeyReleased && event.key.code==Keyboard::S)my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,2*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(soldier_source.x*130,soldier_source.y*180,130,180));
             if(Keyboard::isKeyPressed(Keyboard::S) && !my_soldier_died && my_buletTime>0.2)
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

                       music.shoot_music.play();

              }
        }

        else if(Keyboard::isKeyPressed(Keyboard::S))
        {

            if(soldier_source.y==Right)my_soldier.s_sprite.setTextureRect(IntRect(0*130,0*180,130,180));
            else my_soldier.s_sprite.setTextureRect(IntRect(0*130,2*180,130,180));
              if(!my_soldier_died && my_buletTime>0.2)
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

                      music.shoot_music.play();


              }

        }

        else  my_soldier.s_sprite.setTextureRect(IntRect(0*130,soldier_source.y*180,130,180));//straight stand_up


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


///stabed  my soldier

  ///my_soldier_hit here
  for(int i=0;i<full_enemy.size();i++)
  {
    float stab2=stab2_clock.clock.getElapsedTime().asSeconds();
    if(my_soldier.s_sprite.getGlobalBounds().intersects(full_enemy[i].s_enemy.getGlobalBounds()) && stab2>0.2 )
    {
           if(!my_soldier_died && !enemy_died[i])
           {
              my_soldier_hit++;
              music.enemystab.play();
           }

            stab2_clock.clock.restart();
    }

  }



///stabing enemy

   ///enemy died function

       float stab=stab_clock.clock.getElapsedTime().asSeconds();

       enemy_diedTime+=my_clock.clock.getElapsedTime().asSeconds();

            if(Keyboard::isKeyPressed(Keyboard::Space) && stab>0.2)
            {
                for(int i=0;i<full_enemy.size();i++)
                {

                    if(!my_soldier_died && !enemy_died[i] && my_soldier.s_sprite.getGlobalBounds().intersects(full_enemy[i].s_enemy.getGlobalBounds()))
                    {
                      enemy_hit[i]++;
                      if(enemy_hit[i]>=enemyHit)
                      {
                        enemy_died[i]=true;
                         enemy_hit[i]=0;

                      }

                       //if(buletPosition[i].s_bulet.getGlobalBounds().intersects(full_enemy[j].s_enemy.getGlobalBounds()))
                    }

                }

                stab_clock.clock.restart();

                music.mystab.play();

            }


  for(int i=0;i<buletPosition.size();i++)
  {
     if(soldier_buletDirection[i])///s_enemySoldier.getPosition().x>s_soldier.getPosition().x && soldier_source.y==Right
     {
       buletPosition[i].s_bulet.move(mybuletSpeed*1.f,0.f);
     }
     else if(soldier_buletDirection[i]==false)  /// s_enemySoldier.getPosition().x<s_soldier.getPosition().x && soldier_source.y==Left
        buletPosition[i].s_bulet.move(mybuletSpeed*-1.f,0.f);


  }





            for(int i=0;i+1<full_enemy.size();i++)
            {

                 if(full_enemy[i].s_enemy.getGlobalBounds().intersects(full_enemy[i+1].s_enemy.getGlobalBounds()))
                  {
                    full_enemy.erase(full_enemy.begin()+i+1);
                  }


            }

   for(int i=0;i<buletPosition.size();i++)
    {
      for(int j=0;j<full_enemy.size();j++)
      {
            if(!my_soldier_died && !enemy_died[j] && buletPosition[i].s_bulet.getGlobalBounds().intersects(full_enemy[j].s_enemy.getGlobalBounds()) )
              {
                   buletPosition.erase(buletPosition.begin()+i);
                   soldier_buletDirection.erase(soldier_buletDirection.begin()+i);
                   enemy_hit[j]++;
                   if(enemy_hit[j]>=enemyHit)//check enemy is dead
                   {

                      enemy_died[j]=true;
                      enemy_hit[j]=0;

                  }
                  break;


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



  enemyTime += my_clock.clock.getElapsedTime().asSeconds();

/*if(creatENEMY)
{
  if(creatEnemy<=3)
  {

    init();

  }
  creatENEMY=false;
}*/


  if(enemyTime>5.0)///work for placing enemy
        {
           //std::srand(time(NULL));
             int placeEnemySoldier=rand()%2;
             enemy_direction.push_back(placeEnemySoldier);//direction
             creatEnemy--;

            enemyTime=0.f;



            if(placeEnemySoldier==1)
            {
                Vector2f enemyPosition(my_soldier.s_sprite.getPosition().x+550,soldierCurrrentPosition.y);
              full_enemy.push_back(enemy(&enemy_soldier.t_texture,enemyPosition));

            }
            else
            {
                 //placeEnemySoldier=0;

              Vector2f enemyPosition(my_soldier.s_sprite.getPosition().x-550,soldierCurrrentPosition.y);

              full_enemy.push_back(enemy(&enemy_soldier.t_texture,enemyPosition));

            }

        }

        //enemy bulet load
        enemybuletTime+=my_clock.clock.getElapsedTime().asSeconds();

        for(int i=0;i<full_enemy.size();i++)
        {
          if(enemybuletTime>0.5 && abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)<500 && abs(full_enemy[i].s_enemy.getPosition().x-my_soldier.s_sprite.getPosition().x)>100 && !enemy_died[i])
          {
            if(my_soldier.s_sprite.getPosition().x < full_enemy[i].s_enemy.getPosition().x)
            {
              enemybuletPosition[i].push_back(enemybulet(&enemy_bulet[1].t_texture,full_enemy[i].s_enemy.getPosition(),i));
            }
            else enemybuletPosition[i].push_back(enemybulet(&enemy_bulet[0].t_texture,full_enemy[i].s_enemy.getPosition(),i));

            enemybuletTime=0;

            music.enemyshoot.play();
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
                 enemybuletPosition[i][j].s_enemybulet.move(enemyBuletSpeed,0.f);
              }
              else if(enemyBackAgain[i])
              {

                   enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[0].t_texture);
                 enemybuletPosition[i][j].s_enemybulet.move(-enemyBuletSpeed,0.f);


              }
              else if(enemy_direction[i])
              {

                   enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[0].t_texture);
                 enemybuletPosition[i][j].s_enemybulet.move(-enemyBuletSpeed,0.f);
              }
              else {

                  enemybuletPosition[i][j].s_enemybulet.setTexture(enemy_bulet[1].t_texture);
                 enemybuletPosition[i][j].s_enemybulet.move(enemyBuletSpeed,0.f);
              }


          }
        }

///enemy bulet collision
        ///my_soldier_hit

        for(int i=0;i<full_enemy.size();i++)
        {
          for(int j=0;j<enemybuletPosition[i].size();j++)
          {
            if(Keyboard::isKeyPressed(Keyboard::Down));///do nothing with bulet

            else if(!my_soldier_died && enemybuletPosition[i][j].s_enemybulet.getGlobalBounds().intersects(my_soldier.s_sprite.getGlobalBounds()))
            {
              enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
              if(!my_soldier_died) my_soldier_hit++;//my soldier hit bulet
            }

            else if(enemybuletPosition[i][j].s_enemybulet.getPosition().x>my_soldier.s_sprite.getPosition().x+550 )
              {
                enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
              }
            else if(enemybuletPosition[i][j].s_enemybulet.getPosition().x+550<my_soldier.s_sprite.getPosition().x)
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

                       creatEnemy--;

              }
            }
            enemy_diedTime=0;
        }
///man hit by enemy again

        if(ManRun)
        {
            for(int i=0;i<full_enemy.size();i++)
            {
                for(int j=0;j<enemybuletPosition[i].size();j++)
                {
                    if(man[0].s_sprite.getGlobalBounds().intersects(enemybuletPosition[i][j].s_enemybulet.getGlobalBounds()))
                    {

                        enemybuletPosition[i].erase(enemybuletPosition[i].begin()+j);
                        ManHitCount++;
                        ManHealth_level.x-=30;
                        if(ManHealth_level.x<=0)
                        {
                             ManHealth_level.x=5;

                        }
                        if(ManHitCount>=ManHitted)
                        {
                           // manESCPosition.erase(manESCPosition.begin()+manESCPosition.size()-1);

                            ManDied=true;

                            ManHitCount=0;

                            ManRun=false;
                            ManHealth_rect.setFillColor(Color::Red);
                        }
                    }
                }

            }



        }

        ///man moving on cage
        if(abs(my_soldier.s_sprite.getPosition().x-man[0].s_sprite.getPosition().x)<5 && !ManRun)
        {
             man_esc=true;
             man[0].s_sprite.setPosition(man[0].s_sprite.getPosition().x,soldierCurrrentPosition.y);
             ManRun=true;


        }
        if(man_esc)
        {
              man[0].s_sprite.setTextureRect(IntRect(manCry*165,1*200,165,160));

              man[0].s_sprite.move(-manSpeed*my_clock.clock.getElapsedTime().asSeconds(),0);
               // s_man.move(-manSpeed*clock.getElapsedTime().asSeconds(),0);
               ManHealth_rect.setSize(ManHealth_level);
               ManHealth_rect.setPosition(man[0].s_sprite.getPosition().x,man[0].s_sprite.getPosition().y-20);
               window.draw(ManHealth_rect);

        }
        else if(abs(my_soldier.s_sprite.getPosition().x-man[0].s_sprite.getPosition().x)<300)
        {
             man[0].s_sprite.setTextureRect(IntRect(manCry*165,0*200,165,200));
             helpmetxt.setPosition(man[0].s_sprite.getPosition().x,man[0].s_sprite.getPosition().y-50);

             window.draw(helpmetxt);

               if(soldier_source.y==Right)
             menu_text.go_back_man.setPosition(my_soldier.s_sprite.getPosition().x+100,my_soldier.s_sprite.getPosition().y-160);
            else  menu_text.go_back_man.setPosition(my_soldier.s_sprite.getPosition().x,my_soldier.s_sprite.getPosition().y-160);
             window.draw(menu_text.go_back_man);



        }
        else  man[0].s_sprite.setTextureRect(IntRect(0*165,0*200,165,200));


        if(man[0].s_sprite.getPosition().x-manNumber*110<= 10)
        {
            if(!ManDied)
            {
                manESCPosition.push_back(mann(&man[1].t_texture,man[0].s_sprite.getPosition()));
                manNumber++;
                manEscaped++;
            }

            man_esc=false;

            ManRun=false;
            ManDied=false;
             ManHealth_level.x=100;
            ManHealth_rect.setFillColor(Color::Green);


            //man(&t_man,manCurrentPosition);

            Vector2f manCurrentPosition(my_soldier.s_sprite.getPosition().x+500*manNumber,man[0].s_sprite.getPosition().y);

           if(manCurrentPosition.x>manNumber*110.0 && manCurrentPosition.x<screenWidth-200)
            {
                   man[0].s_sprite.setPosition(manCurrentPosition.x,soldierCurrrentPosition.y-60);

            }

            else  man[0].s_sprite.setPosition(screenWidth/2,soldierCurrrentPosition.y-60);




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

             menu_text.go_back_man.setFillColor(Color::Yellow);



        }
        if(manESCTime2>0.25)
        {
            manESCTime2=0;
             happyMovement2++;
             if(happyMovement2>2)happyMovement2=0;

              menu_text.go_back_man.setFillColor(Color::Green);

        }
        for(int i=0;i<manESCPosition.size();i++)
        {
            window.draw(manESCPosition[i].s_manESC);
        }

        man_time+=my_clock.clock.getElapsedTime().asSeconds();
         helpmetxt.setFillColor(Color::White);
        if(man_time>0.25)
        {
            man_time=0;
            manCry++;
             helpmetxt.setFillColor(Color::Red);
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

      ///coin

      if(creatCoinNumber<=5)
      {
        creatCoin=true;
        creatCoinNumber=coinNumber;
      }
      else creatCoin=false;

          srand(time(NULL));


         if(creatCoin)
         {

            //std::cout<<creatCoinNumber<<std::endl;
            for(int i=0;i<coinNumber;i++)
            {
                cointPosition.push_back(coint(&coin.t_texture));

                 int pos=rand()%(screenWidth+150);

                cointPosition[i].s_coint.setPosition(pos,coinPosition.y);

                for(int j=i+1;j<cointPosition.size();j++)
                {
                  if(cointPosition[i].s_coint.getGlobalBounds().intersects(cointPosition[j].s_coint.getGlobalBounds()))
                  {
                    cointPosition.erase(cointPosition.begin()+j);
                    creatCoinNumber--;
                  }

                }

            }


         }





    for(int i=0;i<cointPosition.size();i++)
    {
        cointPosition[i].s_coint.setTextureRect(IntRect(coinMove*85,pointType*120,85,120));

        cointPosition[i].s_coint.setScale(0.6f,0.6f);
        // cointPosition[i].s_coint.setOrigin(42.5,20);

    }


      for(int i=0;i<cointPosition.size();i++)
      {
        if(cointPosition[i].s_coint.getGlobalBounds().intersects(my_soldier.s_sprite.getGlobalBounds()))
        {
          coinCount++;
          cointPosition.erase(cointPosition.begin()+i);
          //std::cout<<cointPosition.size()<<std::endl;
          creatCoinNumber--;

          if(!my_soldier_died)
          {
            music.coin_music.play();
            coinGain++;
          }

        }
      }


      for(int i=0;i<cointPosition.size();i++)
      {


          window.draw(cointPosition[i].s_coint);

      }
      coinMovetime+=my_clock.clock.getElapsedTime().asSeconds();

        if(coinMovetime>0.002)
        {
            coinMove++;

            if(coinMove>9)coinMove=0;

            coinMovetime=0;



        }




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


        money.s_sprite.setTextureRect(IntRect(happyMovement1*100,0*150,100,150));
        money.s_sprite.setPosition(soldierPosition.x+400,0);
        window.draw(money.s_sprite);

///man count on screen


        life_text.setPosition(soldierPosition.x-500,0-20);
        strength_text.setPosition(soldierPosition.x-500,0-20+30);
        coin_text.setPosition(soldierPosition.x-500-10,0-20+30+30-2);

        strength_rect.setPosition(soldierPosition.x-500+150,0-20+30+30);
        strength_rect.setSize(strength_level);
        window.draw(strength_rect);
        window.draw(life_text);
        window.draw(strength_text);
        window.draw(coin_text);

           // Score_str =coinCount-'0';

        Score_str = To_string(coinCount);
        coinCount_text.setString(Score_str);
        coinCount_text.setPosition(soldierPosition.x-400,0-20+30+30);
        window.draw(coinCount_text);

        ///man count


        Score_str = To_string(manNumber);
        manCount_text.setString(Score_str);
         manCount_text.setPosition(soldierPosition.x+400-50,0-20);
        window.draw(manCount_text);

///challenge show

         Score_str = To_string(CoinCount);
        menu_text.coin_view2.setString(Score_str);
          menu_text.coin_view2.setPosition(soldierPosition.x-120+110,20);
        window.draw(menu_text.coin_view2);

         Score_str = To_string(ManCount);
        menu_text.man_view2.setString(Score_str);
          menu_text.man_view2.setPosition(soldierPosition.x-120+110+150,20);
        window.draw( menu_text.man_view2);

        menu_text.coin_view.setPosition(soldierPosition.x-120-5,20);
        menu_text.man_view.setPosition(soldierPosition.x+50,20);

        window.draw(menu_text.coin_view);
        window.draw( menu_text.man_view);



///mission no
         menu_text.challenge_view.setPosition(soldierPosition.x-60,0-30);
         window.draw(menu_text.challenge_view);


         for(int i=1;i<=5;i++)
         {
          if(challenge_select[i])
          {
               Score_str=To_string(i);
               break;
          }

         }

         menu_text.challenge_viewCount.setString(Score_str);
           menu_text.challenge_viewCount.setPosition(soldierPosition.x-60+160,0-30);
           window.draw(menu_text.challenge_viewCount);



        window.draw(my_soldier.s_sprite);
        window.draw(coinCount_text);
  }



  window.display();
  window.clear();



  }

}
