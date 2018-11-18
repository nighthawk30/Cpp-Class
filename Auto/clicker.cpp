/*
Nathan Taylor
Auto Clicker: 90.21cps Average
Start: Delete
Stop: Home
Terminate: Page Up
 */
#include <windows.h>

int main()
{
  while (true)
    {
      //start
      if (GetAsyncKeyState(VK_DELETE))
	{
	  while (true)
	    {
	      mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	      mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	      Sleep(10);
	      //stop
	      if (GetAsyncKeyState(VK_HOME))
		{
		  break;
		}
	    }
	}
      //terminate
      if (GetAsyncKeyState(VK_PRIOR))
	{
	  exit(0);
	}
    }
  return 0;
}
