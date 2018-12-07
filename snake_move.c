void Snake_Move()
{
   Snake p, tmp;

   for(p = tail; p != head; p = p->prev)
   {
     p->x = p->prev->x;
     p->y = p->prev->y;
   }
   p->x += dir_x;
   p->y += dir_y;

  if(head->x > //size of x)
     head->x = 0;
  
  if(head->x < 0)
     head->x =// size of x;
  
  if(head->y > //size of y)
     head->y = 0;
  
  if(head->y < 0)
     head->y = //size of y;
  // maybe don't have to add {} cause for readability.

  move(head->y, head->x);
}
