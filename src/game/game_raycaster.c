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

#include "game.h"

void  init_player(t_gamedata *gdata)
{
  char initdir;

  initdir = gdata->map->map2d[gdata->map->p_x][gdata->map->p_y];
  gdata->player.dir.x = 0;
  gdata->player.dir.y = 0;
  if (ft_strncmp(&initdir, "N", 1) == 0)
    gdata->player.dir.y = -1;
  if (ft_strncmp(&initdir, "E", 1) == 0)
    gdata->player.dir.x = 1;
  if (ft_strncmp(&initdir, "S", 1) == 0)
    gdata->player.dir.y = 1;
  if (ft_strncmp(&initdir, "W", 1) == 0)
    gdata->player.dir.x = -1;
  gdata->player.plane.x = 0.66;
  gdata->player.plane.y = 0;
  gdata->player.pos.x = gdata->map->p_x;
  gdata->player.pos.y = gdata->map->p_y;
}

static void	wall_side(t_raysdt *ray)
{
	if (ray->sidedist.x < ray->sidedist.y)
	{
		ray->sidedist.x += ray->delta.x;
		ray->map.x += ray->step.x;
		if (ray->step.x == 1)
			ray->side = 0;
		else if (ray->step.x == -1)
			ray->side = 1;
	}
	else
	{
		ray->sidedist.y += ray->delta.y;
		ray->map.y += ray->step.y;
		if (ray->step.y == 1)
			ray->side = 2;
		else if (ray->step.y == -1)
			ray->side = 3;
	}
}

static void		take_a_step(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (gdata->player.pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - gdata->player.pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (gdata->player.pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - gdata->player.pos.y) * ray->delta.y;
	}
}

static void		init_values(t_raysdt *ray, t_gamedata *gdata)
{
	ray->camerax = (2 * ray->pix) / (double)gdata->win_size.x - 1;
	ray->dir.x = gdata->player.dir.x + gdata->player.plane.x * ray->camerax;
	ray->dir.y = gdata->player.dir.y + gdata->player.plane.y * ray->camerax;
	ray->map.x = (int)gdata->player.pos.x;
	ray->map.y = (int)gdata->player.pos.y;
	ray->delta.x = fabs(1 / ray->dir.x);
	ray->delta.y = fabs(1 / ray->dir.y);
	ray->wallhit = 0;
}

void  raycasting(t_gamedata *gdata)
{
	t_raysdt	*ray;
  
  ray = ft_calloc(1, sizeof (t_raysdt));
  init_values(ray, gdata);
	while (ray->pix < gdata->img_size.x)
		{
	take_a_step(ray, gdata);
  ft_putstr_fd("\nPIXEL:",1);
  ft_putnbr_fd(ray->pix, 1);
  printf("%d, %d --- %d", ray->map.x, ray->map.y, gdata->map->map2d[ray->map.y][ray->map.x]);
  if (gdata->map->map2d[ray->map.y][ray->map.x] > 0)
  {
			ray->wallhit = 1;
      ft_putstr_fd("\ngolpe muro",1);
      wall_side(ray);
      raydimension(ray, gdata);
      ft_putstr_fd("\nlinea",1);
      ft_light_rayline(gdata, ray, 8355712);
  }
	
	gdata->imgadd[ray->pix] = ray->walldist;
	//Añadir texturas
  ray->pix++;
    }
    ft_putstr_fd("\n A pintar", 1);
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 0, 0);
}

void		raydimension(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->side == 0 || ray->side == 1)
		ray->walldist = (ray->map.x - gdata->player.pos.x + (1 - ray->step.x) / 2)
		/ ray->dir.x;
	else
		ray->walldist = (ray->map.y - gdata->player.pos.y + (1 - ray->step.y) / 2)
		/ ray->dir.y;
	ray->wallheight = (int)(gdata->img_size.y / ray->walldist);
	ray->start = (-ray->wallheight / 2 + (gdata->img_size.y / 2));
	if (ray->start < 0)
		ray->start = 0;
	ray->end = (ray->wallheight / 2 + (gdata->img_size.y / 2));
	if (ray->end >= gdata->img_size.y)
		ray->end = gdata->img_size.y - 1;
}

/*
// Función para calcular el raycasting
void  calculateRay(t_gamedata *gdata)
{
    t_raysdtsdt  ry;
    int       i;
    
    i = 0;
    while ( i < gdata->win_size.x)
    {
    ry.camerax = 2 * i / (double)gdata->win_size.x - 1; // [-1, 1]
      ry.dir.x = gdata->player.dir.x + gdata->player.plane.x * ry.camerax;
      ry.dir.y = gdata->player.dir.y + gdata->player.plane.y * ry.camerax;


    ry.posray = gdata->player.pos;
    ry.delta.x = fabs(1 / gdata->player.dir.x);
    ry.delta.y = fabs(1 / gdata->player.dir.y);
    ry.wallhit = 0; // Se convierte en 1 cuando el rayo golpea un muro
    ry.map.x = (int)ry.posray.x;
    ry.map.y = (int)ry.posray.y;
    // Determinar el tamaño del paso e inicializar sideDistX, sideDistY
    if (ry.delta.x < ry.delta.y)
        ry.stepSize = ry.delta.x;
    else
        ry.stepSize = ry.delta.y;

if (ry.dir.x < 0) {
    ry.step.x = -1;
    ry.sideDist.x = (ry.posray.x - ry.map.x) * ry.deltaDist.x;
} else {
    ry.step.x = 1;
    ry.sideDist.x = (ry.map.x + 1.0 - ry.posray.x) * ry.deltaDist.x;
}

if (ry.dir.y < 0) {
    ry.step.y = -1;
    ry.sideDist.y = (ry.posray.y - ry.map.y) * ry.deltaDist.y;
} else {
    ry.step.y = 1;
    ry.sideDist.y = (ry.map.y + 1.0 - ry.posray.y) * ry.deltaDist.y;
}
    while (!ry.wallhit) 
    {
        // Mover el rayo al siguiente punto
        ry.posray.x += gdata->player.dir.x * ry.stepSize;
        ry.posray.y += gdata->player.dir.y * ry.stepSize;
        ry.map.x = (int)ry.posray.x;
        ry.map.y = (int)ry.posray.y;

        // Verificar si el rayo ha golpeado un muro
        if (gdata->map->map2d[ry.map.x][ry.map.y] > 0)
         {
            ry.wallhit = 1;
            //ry.walldist = sqrt(pow(ry.posray.x - gdata->player.pos.x, 2) + pow(ry.posray.y - gdata->player.pos.y, 2));
            if (abs(ry.dir.x) > abs(ry.dir.y)) 
                ry.walldist = abs((ry.map.x - gdata->player.pos.x + (1 - ry.step.x) / 2) / ry.dir.x);
            else 
                ry.walldist = abs((ry.map.y - gdata->player.pos.y + (1 - ry.step.y) / 2) / ry.dir.y);
          }
            // Aquí puedes calcular la altura del muro basándote en wallDist
//            printf("Muro golpeado en: (%f, %f) con una distancia de: %f\n", ry.posray.x, ry.posray.y, ry.walldist);
            //ry.wallheight = DISTANCE_TO_PROJECTION_PLANE / ry.walldist;
            ry.wallheight = (int)(gdata->map->h_map / ry.walldist);
    i++;
    }
  }
}
*/

/////////////////////// ANTIGUO , INTENTO DESDE EL LOVCE //////////////////////////* 
/*
t_gamecoord raycasting(t_gamedata *gdata)
{

  t_raysdtsdt  r;
  t_gamecoord rray;

   r.camplane.x = 0;
  r.camplane.y = 0.66; //the 2d raycaster version of camera plane

  r.time = 0; //r.time of current frame
  r.oldtime = 0; //r.time of previous frame


  //screen(screenWidth, screenHeight, 0, "Raycaster"); // esto es el loop del juego en si, no del raycaster
    for(int x = 0; x < gdata->map->w_map; x++) 
    {
      //calculate ray position and direction
      r.camerax = 2 * x / gdata->map->w_map - 1; //x-coordinate in camera space
      r.ray.x = gdata->player.dir.x + r.camplane.x * r.camerax;
      r.ray.y = gdata->player.dir.y + r.camplane.y * r.camerax;
      //which box of the map we're in
      r.map.x = gdata->map->p_x;
      r.map.y = gdata->map->p_y;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //raylenfromto.x = sqrt(1 + (ray.y * ray.y  / (ray.x * ray.x))
      //raylenfromto.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y )
      //which can be simplified to abs(|rayDir| / ray.x) and abs(|rayDir| / ray.y 
      //where |rayDir| is the length of the vector (ray.x, ray.y . Its length,
      //unlike (gdata->player.dir.x, gdata->player.dir.y) is not 1, however this does not matter, only the
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
        r.raylento.x = (gdata->map->p_x - r.map.x) * r.raylenfromto.x;
      }
      else
      {
        r.step.x = 1;
        r.raylento.x = (r.map.x + 1.0 - gdata->map->p_x) * r.raylenfromto.x;
      }
      if(r.ray.y < 0)
      {
        r.step.y = -1;
        r.raylento.y = (gdata->map->p_y - r.map.y) * r.raylenfromto.y;
      }
      else
      {
        r.step.y = 1;
        r.raylento.y = (r.map.y + 1.0 - gdata->map->p_y) * r.raylenfromto.y;
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
        if(gdata->map->map2d[(int)r.map.x][(int)r.map.y] > 0) 
          r.wallhit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (map->x - gdata->map->map2d.pos.x + (1 - step.x) / 2) / ray.x for side == 0, or same formula with y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(r.side == 0) 
          r.perpWallDist = (r.raylento.x - r.raylenfromto.x);
      else
          r.perpWallDist = (r.raylento.y - r.raylenfromto.y);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(gdata->map->h_map / r.perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      rray.x = -lineHeight / 2 + gdata->map->h_map / 2;
      if(rray.x < 0)
         rray.x = 0;
      rray.y = lineHeight / 2 + gdata->map->h_map / 2;
      if(rray.y >= gdata->map->h_map) 
          rray.y = gdata->map->h_map - 1;


      //choose wall color
      ColorRGB color;
      switch(worldMap[map->x][map->y])
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
      //verLine(x, drawStart, drawEnd, color);
      
  //  }
    //timing for input and FPS counter
   /* r.oldtime = r.time;
    r.time = getTicks();
    double framer.time = (r.time - r.oldtime) / 1000.0; //framer.time is the r.time this frame has taken, in seconds
    print(1.0 / framer.time); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = framer.time * 5.0; //the constant value is in squares/second
    double rotSpeed = framer.time * 3.0; //the constant value is in radians/second
    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(gdata->map->map2d.pos.x + gdata->player.dir.x * moveSpeed)][int(gdata->map->map2d.pos.y)] == false) gdata->map->map2d.pos.x += gdata->player.dir.x * moveSpeed;
      if(worldMap[int(gdata->map->map2d.pos.x)][int(gdata->map->map2d.pos.y + gdata->player.dir.y * moveSpeed)] == false) gdata->map->map2d.pos.y += gdata->player.dir.y * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(gdata->map->map2d.pos.x - gdata->player.dir.x * moveSpeed)][int(gdata->map->map2d.pos.y)] == false) gdata->map->map2d.pos.x -= gdata->player.dir.x * moveSpeed;
      if(worldMap[int(gdata->map->map2d.pos.x)][int(gdata->map->map2d.pos.y - gdata->player.dir.y * moveSpeed)] == false) gdata->map->map2d.pos.y -= gdata->player.dir.y * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldgdata->player.dir.x = gdata->player.dir.x;
      gdata->player.dir.x = gdata->player.dir.x * cos(-rotSpeed) - gdata->player.dir.y * sin(-rotSpeed);
      gdata->player.dir.y = oldgdata->player.dir.x * sin(-rotSpeed) + gdata->player.dir.y * cos(-rotSpeed);
      double oldr.camplane.x = r.camplane.x;
      r.camplane.x = r.camplane.x * cos(-rotSpeed) - r.camplane.y * sin(-rotSpeed);
      r.camplane.y = oldr.camplane.x * sin(-rotSpeed) + r.camplane.y * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldgdata->player.dir.x = gdata->player.dir.x;
      gdata->player.dir.x = gdata->player.dir.x * cos(rotSpeed) - gdata->player.dir.y * sin(rotSpeed);
      gdata->player.dir.y = oldgdata->player.dir.x * sin(rotSpeed) + gdata->player.dir.y * cos(rotSpeed);
      double oldr.camplane.x = r.camplane.x;
      r.camplane.x = r.camplane.x * cos(rotSpeed) - r.camplane.y * sin(rotSpeed);
      r.camplane.y = oldr.camplane.x * sin(rotSpeed) + r.camplane.y * cos(rotSpeed);
    }
    return (rray);
  }
*/

