// hello people this is the port of my famous and queit frankly my first repo's port from pthon to c++ this game is called "midnight-chaser-cpp"
// this code can be used by beginners looking to learn c++ by making something rewarding and fun logic is simple and can be made under 1 hour !!
// thanks for checking out my code this code may have bugs becacuse i am a beginner and a 13 year old.

//importing libaray

#include <iostream>
#include "raylib.h"
#include <cmath>
#include <cstdio>

// defining const that dont need to change and these will be used in whole code so global variables

const int width = 800;
const int height = 800;
// fuctions that calculates the collision between two circles by useing pythagoures theroum
bool collision(float posx, float posy, float posx1 , float posy1)
{
   float dx = posx - posx1; // calculates distance on x axis 
   float dy = posy - posy1; // calculates distance on y axis
   float distance = std::sqrt(dy*dy + dx*dx); // caculates direct distance between the two circle centers
   if(distance <= radius + radius1){return true;} // checks that if the direct distance exceeds the sum of the two circles bam collision !!
   else{return false;}
}
int main()
{
    // variable declation these variables dont need to be global variables.
    // i used float for speed because it is easy to find the sweet spot where you dont get cooked or you dont cook he AI
    // some values are const because THEY DONT NEED TO GODDAMN CHANGE.
    float posx = 500;
    float posy = 500;
    float posx1 = 100;
    float posy1 = 100;
    const int radius = 45;
    const int radius1 = 45;
    float player_speed = 6.0;
    float enemy_speed = 3.6;
    bool is_collided = false;
    float start_time;
    float final_time;
    bool is_game_over = false;
    InitWindow(width,height,"midnight_chaser"); // initalize window
    SetTargetFPS(60); // sets fps without this ball and enemy would be gods on steriods don't belive me remove this line.
    start_time = GetTime(); // gets the time at the start of the game for score and if your cuerious brain asks me why dont do this at the time of iniziation becuase you can't use any raylib fuctions till calling the init than after you can use it 
    while(! WindowShouldClose())
    {
        is_collided = collision(posx,posy,posx1,posy1); // puts the result of the fuctions in a bool variable
        
        BeginDrawing(); // starts drawing (note: this is essential to draw anything)
        if(is_collided == true) // this block of code check if the circles have collided or not 
        {
            if(is_game_over == false) // i have used another variable to not make the score go up after the game is over because this is c++ not python get used to it (as the famous saying goes"if you want to shoot your self in the leg with c++ your gun wount work but when it would it would blow your lower body")
            {
                final_time = std::round(GetTime() - start_time); // this is just a basic scoring system bascially for how much time you were alive 
                is_game_over = true; // and my fellas if you think this line is use less NIEN! figure it out i am not your dad 
                           
            }
            ClearBackground(GREEN); // clears background green
            DrawText(TextFormat("%.1f", final_time),50,50,50,WHITE);
            DrawText("Press R to restart",50,100,50,WHITE); // prints options on what player has after getting caught by a AI that is dummer than a amobea 
            DrawText("Press ESC to quit",50,150,50,WHITE);
            if(IsKeyDown(KEY_R)) // this block exists to reset all the variables like just restarting your phone 
            {
                 posx = 500;
                 posy = 500;
                 posx1 = 100;
                 posy1 = 100;
                 is_collided = false;
                 start_time = GetTime();
            }
            
        }
        
        else
        {
            // this section of code is to move the the player 
            if(IsKeyDown(KEY_W)){posy -=player_speed;}
            if(IsKeyDown(KEY_S)){posy +=player_speed;}
            if(IsKeyDown(KEY_D)){posx +=player_speed;}
            if(IsKeyDown(KEY_A)){posx -=player_speed;}
            // this section of code is to apply boundaries
            if(posx + radius > width){posx = width - radius;}
            if(posy + radius > height){posy = height - radius;}
            if(posx < radius){posx = radius;}
            if(posy < radius){posy = radius;}
            // this section of code is the AI for the blue circle on your ass 
            if(posx1 < posx){posx1 += enemy_speed;}
            if(posx1 > posx){posx1 -= enemy_speed;}
            if(posy1 < posy){posy1 += enemy_speed;}
            if(posy1 > posy){posy1 -= enemy_speed;}
            ClearBackground(RED);
            DrawCircle(posx,posy,radius,WHITE); // draws the circles after all the logic bullshit above
            DrawCircle(posx1,posy1,radius1,BLUE);
        }
        
        EndDrawing(); // ends drawing just like everything has to come to an end ex - end of windows 7 
    }

}
