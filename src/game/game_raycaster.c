/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:16:15 by javi              #+#    #+#             */
/*   Updated: 2024/02/22 17:16:36 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h";


#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void  init_map(t_gamedata gdata)

int raycasting(t_gamedata gdata)
{

  gdata.level.pos.x = 22;
  gdata.level.pos.y = 12;  //x and y start position
  gdata.level.dir.x = -1;
  gdata.level.dir.y = 0; //initial direction vector
  gdata.level.camplane.x = 0;
  gdata.level.camplane.y = 0.66; //the 2d raycaster version of camera plane

  gdata.level.time = 0; //gdata.level.time of current frame
  gdata.level.oldtime = 0; //gdata.level.time of previous frame

  t_raysdt  r;

  //screen(screenWidth, screenHeight, 0, "Raycaster"); // esto es el loop del juego en si, no del raycaster
  while(!done())
  {
    for(int x = 0; x < gdata.map.w_map; x++) 
    {
      //calculate ray position and direction
      r.camerax = 2 * x / gdata.map.w_map - 1; //x-coordinate in camera space
      r.ray.x = gdata.level.dir.x + gdata.level.camplane.x * r.camerax;
      r.ray.y = gdata.level.dir.y + gdata.level.camplane.y * r.camerax;
      //which box of the map we're in
      r.map.x = (int)gdata.level.pos.x;
      r.map.y = (int)gdata.level.pos.y;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //raylenfromto.x = sqrt(1 + (ray.y * ray.y  / (ray.x * ray.x))
      //raylenfromto.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y )
      //which can be simplified to abs(|rayDir| / ray.x) and abs(|rayDir| / ray.y 
      //where |rayDir| is the length of the vector (ray.x, ray.y . Its length,
      //unlike (gdata.level.dir.x, gdata.level.dir.y) is not 1, however this does not matter, only the
      //ratio between raylenfromto.x and raylenfromto.y matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.
      if (r.ray.x == 0) 
          r.raylenfromto.x = 1e30;
      else
          r.raylenfromto.x = fabs(1 / r.ray.x);
      if (r.ray.y == 0) 
          r.raylenfromto.y = 1e30;
      else
          r.raylenfromto.y = fabs(1 / r.ray.y);

       

    
      r.wallhit = 0; //was there a wall hit?
    
      //calculate step and initial sideDist
      if(r.ray.x < 0)
      {
        r.step.x = -1;
        r.raylento.x = (gdata.level.pos.x - r.map.x) * r.raylenfromto.x;
      }
      else
      {
        r.step.x = 1;
        r.raylento.x = (r.map.x + 1.0 - gdata.level.pos.x) * r.raylenfromto.x;
      }
      if(r.ray.y < 0)
      {
        r.step.y = -1;
        r.raylento.y = (gdata.level.pos.y - r.map.y) * r.raylenfromto.y;
      }
      else
      {
        r.step.y = 1;
        r.raylento.y = (r.map.y + 1.0 - gdata.level.pos.y) * r.raylenfromto.y;
      }
      //perform DDA
      while(r.wallhit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(r.raylento.x < r.raylento.y)
        {
          r.raylento.x += r.raylenfromto.x;
          r.map.x += r.step.x;
          r.side = 0;
        }
        else
        {
          r.raylento.y += r.raylenfromto.y;
          r.map.y += r.step.y;
          r.side = 1;
        }
        //Check if ray has hit a wall
        if(gdata.map.map2d[(int)r.map.x][(int)r.map.y] > 0) 
          r.wallhit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (map.x - gdata.level.pos.x + (1 - step.x) / 2) / ray.x for side == 0, or same formula with y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(r.side == 0) 
          r.perpWallDist = (r.raylento.x - r.raylenfromto.x);
      else
          r.perpWallDist = (r.raylento.y - r.raylenfromto.y);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(gdata.map.h_map / r.perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + gdata.map.h_map / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + gdata.map.h_map / 2;
      if(drawEnd >= gdata.map.h_map) drawEnd = gdata.map.h_map - 1;

      //choose wall color
     /* ColorRGB color;
      switch(worldMap[map.x][map.y])
      {
        case 1:  color = RGB_Red;    break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_yellow; break; //yellow
      }*/

      //give x and y sides different brightness
     // if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }
    //timing for input and FPS counter
   /* gdata.level.oldtime = gdata.level.time;
    gdata.level.time = getTicks();
    double framegdata.level.time = (gdata.level.time - gdata.level.oldtime) / 1000.0; //framegdata.level.time is the gdata.level.time this frame has taken, in seconds
    print(1.0 / framegdata.level.time); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = framegdata.level.time * 5.0; //the constant value is in squares/second
    double rotSpeed = framegdata.level.time * 3.0; //the constant value is in radians/second
    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(gdata.level.pos.x + gdata.level.dir.x * moveSpeed)][int(gdata.level.pos.y)] == false) gdata.level.pos.x += gdata.level.dir.x * moveSpeed;
      if(worldMap[int(gdata.level.pos.x)][int(gdata.level.pos.y + gdata.level.dir.y * moveSpeed)] == false) gdata.level.pos.y += gdata.level.dir.y * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(gdata.level.pos.x - gdata.level.dir.x * moveSpeed)][int(gdata.level.pos.y)] == false) gdata.level.pos.x -= gdata.level.dir.x * moveSpeed;
      if(worldMap[int(gdata.level.pos.x)][int(gdata.level.pos.y - gdata.level.dir.y * moveSpeed)] == false) gdata.level.pos.y -= gdata.level.dir.y * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldgdata.level.dir.x = gdata.level.dir.x;
      gdata.level.dir.x = gdata.level.dir.x * cos(-rotSpeed) - gdata.level.dir.y * sin(-rotSpeed);
      gdata.level.dir.y = oldgdata.level.dir.x * sin(-rotSpeed) + gdata.level.dir.y * cos(-rotSpeed);
      double oldgdata.level.camplane.x = gdata.level.camplane.x;
      gdata.level.camplane.x = gdata.level.camplane.x * cos(-rotSpeed) - gdata.level.camplane.y * sin(-rotSpeed);
      gdata.level.camplane.y = oldgdata.level.camplane.x * sin(-rotSpeed) + gdata.level.camplane.y * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldgdata.level.dir.x = gdata.level.dir.x;
      gdata.level.dir.x = gdata.level.dir.x * cos(rotSpeed) - gdata.level.dir.y * sin(rotSpeed);
      gdata.level.dir.y = oldgdata.level.dir.x * sin(rotSpeed) + gdata.level.dir.y * cos(rotSpeed);
      double oldgdata.level.camplane.x = gdata.level.camplane.x;
      gdata.level.camplane.x = gdata.level.camplane.x * cos(rotSpeed) - gdata.level.camplane.y * sin(rotSpeed);
      gdata.level.camplane.y = oldgdata.level.camplane.x * sin(rotSpeed) + gdata.level.camplane.y * cos(rotSpeed);
    }*/
  }
}

