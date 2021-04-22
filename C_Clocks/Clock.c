#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define X(x) x*2
#define index(x,y,w) (y) * (w) + (x)

int width = 85;
int height = 13;

char bar = '|';
char *output;

void T(int x, int y);
void L1(int x, int y);
void L2(int x, int y);
void M(int x, int y);
void R1(int x, int y);
void R2(int x, int y);
void B(int x, int y);

void ClearNumber(int x, int y);

#define Zero(x,y) T(x,y); L1(x,y); L2(x,y); B(x,y); R1(x,y); R2(x,y);
#define One(x,y) R1(x,y); R2(x,y);
#define Two(x,y) T(x,y); R1(x,y); M(x,y); L2(x,y); B(x,y);
#define Three(x,y) T(x,y); R1(x,y); R2(x,y); M(x,y); B(x,y);
#define Four(x,y) L1(x,y); M(x,y); R1(x,y); R2(x,y);
#define Five(x,y) T(x,y); L1(x,y); M(x,y); R2(x,y); B(x,y);
#define Six(x,y) T(x,y); L1(x,y); M(x,y); R2(x,y); B(x,y); L2(x,y);
#define Seven(x,y) T(x,y); R1(x,y); R2(x,y);
#define Eight(x,y) T(x,y); L1(x,y); L2(x,y); M(x,y); R1(x,y); R2(x,y); B(x,y);
#define Nine(x,y) T(x,y); L1(x,y); M(x,y); R1(x,y); R2(x,y); B(x,y);

void drawLine(int Point1X, int Point1Y, int Point2X, int Point2Y, char c);

void printblockC(int x, int y, char c)
{
	output[index(x,y,width)] = c;
	output[index(x+1,y,width)] = c;
}

void printblock(int x, int y)
{
	printblockC(x,y,bar);
	printblockC(x+1,y,bar);
}

void printblocktip(int x, int y)
{
	printblockC(x,y,'/');
	printblockC(x+1,y,'\\');
}

void printblocktale(int x, int y)
{	
	printblockC(x,y,'\\');
	printblockC(x+1,y,'/');
}

void printblockH(int x, int y)
{	
	printblockC(x,y,'=');
	printblockC(x+1,y,'=');
}

void printblockHTip(int x, int y)
{	
	printblockC(x,y,'<');
	printblockC(x+1,y,'=');
}

void printblockHTale(int x, int y)
{	
	printblockC(x,y,'=');
	printblockC(x+1,y,'>');
}

void setBrackLine(char *arr)
{
	
	for(int i = 0; i < height; i++)
	{
		arr[index(width-1,i,width)] = '\n';
	}

}

void drawFrame(char *arr)
{

	for(int i = 0; i < height; i++)
	{
		arr[index(0,i,width)] = '#';
		arr[index(width-2,i,width)] = '#';
	}
	for(int i = 0; i < width-1; i++)
	{
		arr[index(i,0,width)] = '#';
		arr[index(i,height-1,width)] = '#';
	}

	//for(int i = 0; i < width*height; i++)
	//{
		//if(output[i] == ' ')
		//{
			//output[i] = '?';
		//}
	//}

}

void printOutput(char *arr)
{
	printf("\033[%d;%dH%s",0,0, arr);
}

int getDigit(int number, int digit)
{
	int i = 10;
	for(int j = 1; j < digit; j++)
	{
		i *= i;
	}
	if(digit == 0)
	{
		i = 1;
	}

	return ((int)(number / i))%10;
}

void drawNumber(int x, int y, int i)
{

	switch(i)
	{
		case 0:
			Zero(x,y);
			break;
		case 1:
			One(x,y);
			break;
		case 2:
			Two(x,y);
			break;
		case 3:
			Three(x,y);
			break;
		case 4:
			Four(x,y);
			break;
		case 5:
			Five(x,y);
			break;
		case 6:
			Six(x,y);
			break;
		case 7:
			Seven(x,y);
			break;
		case 8:
			Eight(x,y);
			break;
		case 9:
			Nine(x,y);
		break;
		default:
			break;
	}

}

void printnumber(int x, int y, int i)
{

	if(i > 99 || i < 0)
	{
		return;
	}

	if(i > 9)
	{
		drawNumber(x, y, getDigit(i,1));
		drawNumber(x + X(6), y, getDigit(i,0));
	}
	else
	{
		Zero(x,y)
		drawNumber(x + X(6), y, i);
	}

}

void calculate_Draw_Clock_Arm(int n, int n_max, float off, int max_length, char c)
{
	int x = width/2;
	int y = height/2;
	float x2 = width/2;
	float y2 = (height/2)-max_length;

	float delta = ((float)n/(float)n_max)*2*3.1415f;
	delta = delta + off;
	float x2n = (x2-x) * cos(delta) - (y2-y) * sin(delta);
	float y2n = (x2-x) * sin(delta) + (y2-y) * cos(delta);
	drawLine(x, y, X(x2n)+x, y2n+y, c);

}

void draw_Clock_Numbers()
{
	return;
	int x = width/2;
	int y = (height/2);

	for(int i = 0; i < 12; i++)
	{
		float delta = ((float)i/(float)11)*2*3.1415f;
		float x2 = 10 * sin(delta);
		float y2 = 10 * cos(delta);
		int ind = index(x2+x, y2+y, width);
		int ind2 = index(x2+x+1, y2+y, width);
		if(ind > width*height || ind < 0) {
			printf("Ind out of range: %d", ind);
			return;
		}
		if(ind2 > width*height || ind2 < 0) {
			printf("Ind2 out of range: %d", ind2);
			return;
		}
		output[ind] = (char)getDigit(i+1, 1);
		output[ind2] = (char)getDigit(i+1, 0);
	}
}

void PrintDigital(struct tm *info, char *arr)
{
	printnumber(2,2,(info->tm_hour+2)%24);
	printnumber(32,2,info->tm_min);
	printnumber(60,2,info->tm_sec);
	setBrackLine(arr);
	drawFrame(arr);
	printOutput(arr);
}

void PrintAnalogClock(struct tm *info, char *arr)
{
	//draw_Clock_Numbers();
	calculate_Draw_Clock_Arm(info->tm_sec, 60, 0.0f, 20, 's');
	calculate_Draw_Clock_Arm(info->tm_min, 60, 0.0f, 16, 'm');
	calculate_Draw_Clock_Arm((info->tm_hour+2)%24, 12, (float)info->tm_min/60.0f, 14, 'h');
	setBrackLine(arr);
	drawFrame(arr);
	printOutput(arr);

}

int main(int argc, char **argv)
{

	//printf("\033[mtest\n");
	//return 0;
	int digital = 0;
	if(argc < 2) digital = 1;

	if(argc == 2)
	{
		if(strcmp(argv[1], "-d") == 0)
		{
			digital = 1;
			output = malloc(width*height);
		}
		else if(strcmp(argv[1], "-a") == 0)
		{
			digital = 0;
			height = width/2;
			output = malloc(width*height);
		}
		else
		{
			printf("Args:\n\t-d\t->\tDigital Clock\n\t-a\t->\tAnalog Clock\n\t-h\t->\tHelp\n\n");
			return 0;
		}

	}
			
	
	if(output == NULL)
	{
		printf("Output == null\n");
		return 0;
	}

	time_t rawtime;
	struct tm *info;

	int spref = 0;
	
	while(1)
	{
		time(&rawtime);
		info = gmtime(&rawtime);

		if(spref != info->tm_sec)
		{
			spref = info->tm_sec;
			for(int i = 0; i < width*height; i++)
			{
				output[i] = ' ';
			}
			
			if(digital) 
			{
				PrintDigital(info, output);
			}

			if(!digital)
			{
				PrintAnalogClock(info, output);
				//printf("W: %d, H: %d\n", width, height);
			}

			//return 0;
		}

	}
	
	printf("\n");

	return 0;
}

void T(int x, int y)
{
	printblockHTip(x+X(1),y);
	printblockH(x+X(2),y);
	printblockHTale(x+X(3),y);
}

void L1(int x, int y)
{
	printblocktip(x,y+1);
	printblock(x,y+2);
	printblocktale(x,y+3);	
}

void L2(int x, int y)
{
	printblocktip(x,y+5);	
	printblock(x,y+6);
	printblocktale(x,y+7);
}

void M(int x, int y)
{
	printblockHTip(x+X(1),y+4);
	printblockH(x+X(2),y+4);
	printblockHTale(x+X(3),y+4);
}

void R1(int x, int y)
{
	printblocktip(x+X(4),y+1);
	printblock(x+X(4),y+2);
	printblocktale(x+X(4),y+3);
}

void R2(int x, int y)
{
	printblocktip(x+X(4),y+5);
	printblock(x+X(4),y+6);
	printblocktale(x+X(4),y+7);
}

void B(int x, int y)
{
	printblockHTip(x+X(1),y+8);
	printblockH(x+X(2),y+8);
	printblockHTale(x+X(3),y+8);
}


void drawLine(int x, int y, int x2, int y2, char c) {
	
	if(x < 0 || x > width || y < 0 || y > height) return;
	if(x2 < 0 || x2 > width || y2 < 0 || y2 > height) return;

	int w = x2 - x;
	int h = y2 - y;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if (w < 0)
		dx1 = -1;
	else if (w > 0)
		dx1 = 1;
	if (h < 0)
		dy1 = -1;
	else if (h > 0)
		dy1 = 1;
	if (w < 0)
		dx2 = -1;
	else if (w > 0)
		dx2 = 1;
	int longest = abs(w);
	int shortest = abs(h);
	if (!(longest > shortest)) {
		longest = abs(h);
		shortest = abs(w);
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}
	int numerator = longest >> 1;
	for (int i = 0; i <= longest; i++) {
		int ind = index(x, y, width);
		int ind2 = index(x+1, y, width);
		if(ind > width*height || ind2 > width*height) break;
		output[ind] = c;
		output[ind2] = c;
		numerator += shortest;
		if (!(numerator < longest)) {
			numerator -= longest;
			x += dx1;
			y += dy1;
		} else {
			x += dx2;
			y += dy2;
		}
	}

}
