#include <time.h>
#include <glib.h>

#include "util.h"

#define FILENAME1 "some.file.ext"
#define FILENAME2 "some file"

#define CMD1 "ls"
#define CMD2 "not-found"

int main(void)
{
	gchar *tmp, ftime[256];
	gboolean ret;
	time_t now, ts;
	struct tm *tm;
	guint hour, min, sec;
	
	g_print ("Testing to_basename():\n\n");
	
	tmp = to_basename (FILENAME1);
	g_print ("to_basename (" FILENAME1 "): %s\n", tmp);
	g_free (tmp);
	
	tmp = to_basename (FILENAME2);
	g_print ("to_basename (" FILENAME2 "): %s\n", tmp);
	g_free (tmp);
	
	
	
	
	g_print ("\nTesting run_command():\n\n");
	
	ret = command_run (CMD1);
	g_print ("Running " CMD1 " = %d\n", ret);
	
	ret = command_run (CMD2);
	g_print ("Running " CMD2 " = %d\n", ret);
	
	
	
	
	g_print ("\nTesting get_alarm_timestamp()\n\n");
	
	time (&now);
	tm = localtime (&now);
	
	strftime (ftime, sizeof (ftime), "%c", tm);
	
	hour = tm->tm_hour;
	min = tm->tm_min;
	sec = tm->tm_sec;
	
	g_print ("Time: %s\n", ftime);
	ts = get_alarm_timestamp(hour, min, sec - 10);
	
	g_print ("For -10s: %d: %s\n", ts, ctime (&ts));
	ts = get_alarm_timestamp(hour, min, sec + 10);
		
	g_print ("For +10s: %d: %s\n", ts, ctime (&ts));
	
	return 0;
}
