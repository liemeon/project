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

  if((char)inch() == '*')
    Game_Over();

  if((char)inch() == 'o')
  {
    move(head->y, head->x);
    addch('*');
    refresh();
    tmp = (Snake)malloc(sizeof(SNAKE));
    tmp->x = head->x + dir_x;
    tmp->y = head->y + dir_y;
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
    do
    {
      food.x = rand() % //size of x;
      food.y = rand() % //size of y;
      move(food.y, food.x);
    }
    while(((char)inch()) == '*');
    move(food.y, food.x);
    addch('o');
    refresh();
  }

  move(head->y, head->x);
  addch('*');
  refresh();
  move(tail->y, tail->x);
  addch(' ');
  refresh();

}

