void key_ctl()
{
  int ch = getch();
  switch(ch)
  {
    case 'W':
    case 'w':
      if(dir_x == 0)
        break;
      dir_x = 0;
      dir_y = -1;
      break;

    case 'S':
    case 's':
      if(dir_x == 0)
        break;
      dir_x = 0;
      dir_y = 1;
      break;

    case 'A':
    case 'a':
      if(dir_y == 0)
        break;
      dir_y = 0;
      dir_x = -1;
      break;

    case 'D':
    case 'd':
      if(dir_y == 0)
        break;
      dir_y = 0;
      dir_x = 1;
      break;
    default:break;
  }
}
