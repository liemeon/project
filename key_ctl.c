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

    case ' ':
      set_ticker(0);
      do {
         ch = getch();
      }while(ch != ' ');
      set_ticker(500);
      break;

    case 'Q': // it will be more specific
    case 'q':
      Game_Over();
      break;

    default:break;
  }
}
