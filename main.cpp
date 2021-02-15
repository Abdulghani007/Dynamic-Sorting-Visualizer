
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#define SORT_NO 4 // Number of sorting algorithms
#define MAX 50	  // Number of values in the array
#define SPEED 700 // Speed of sorting, must be greater than MAX always
int a[MAX];		  // Array
int swapflag = 0; // Flag to check if swapping has occured
int i = 0, j = 0; // To iterate through the array
int flag = 0;	  // For Insertion Sort
int dirflag = 0;  // For Ripple Sort, to change direction at the ends
int count = 1;	  // For Ripple Sort, to keep count of how many are sorted at the end
int k = 0;		  // To Switch from Welcome screen to Main Screen
int sorting = 0;  // 1 if Sorted
char *sort_string[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Ripple Sort"};
int sort_count = 0; // To cycle through the string

int bb1 = 0;
int bb2 = 1;
int speed = 500;
// Function to display text on screen char by char
void bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

// Function to integer to string
void int_str(int rad, char r[])
{
	//itoa(rad,r,10);
	sprintf(r, "%d", rad);
}

void display_text()
{
	glColor3f(0.0, 0.7, 0.0);
	bitmap_output(210, 720, "Demonstration of Sorting Algorithms", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(210, 700, "--------------------------", GLUT_BITMAP_TIMES_ROMAN_24);

	// other text small font
	glColor3f(0.619, 0.431, 0.239);
	bitmap_output(10, 630, "This program sorts a random set of numbers in ascending order displaying them graphically as ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(10, 600, "bars with varying height", GLUT_BITMAP_TIMES_ROMAN_24);

	if (sorting == 0) // if not sorting display menu
	{

		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(10, 520.0);
		glVertex2f(10, 570);
		glVertex2f(75, 570);
		glVertex2f(75, 520.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(20, 535, "Sort [s]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(85, 520.0);
		glVertex2f(85, 570);
		glVertex2f(150, 570);
		glVertex2f(150, 520.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(95, 535, "Next [n]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(160, 520.0);
		glVertex2f(160, 570);
		glVertex2f(250, 570);
		glVertex2f(250, 520.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(170, 535, "Generate [g]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.364, 0.811, 0.937);

		glBegin(GL_QUADS);
		glVertex2f(260, 520.0);
		glVertex2f(260, 570);
		glVertex2f(335, 570);
		glVertex2f(335, 520.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(270, 535, "Quit [Esc]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.7, 0, 0.7);
		bitmap_output(85, 465, *(sort_string + sort_count), GLUT_BITMAP_9_BY_15);
	}
	else if (sorting == 1) // while sorting
	{
		glColor3f(0.5, 0.5, 0.5);
		bitmap_output(10, 555, "Sorting in progress...", GLUT_BITMAP_9_BY_15);
		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(10, 490.0);
		glVertex2f(10, 540);
		glVertex2f(85, 540);
		glVertex2f(85, 490.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(20, 510, "Pause [p]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(95, 490.0);
		glVertex2f(95, 540);
		glVertex2f(180, 540);
		glVertex2f(180, 490.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(105, 510, "Increase [+]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.364, 0.811, 0.937);
		glBegin(GL_QUADS);
		glVertex2f(190, 490.0);
		glVertex2f(190, 540);
		glVertex2f(280, 540);
		glVertex2f(280, 490.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		bitmap_output(200, 510, "Decrease [-]", GLUT_BITMAP_HELVETICA_18);

		glColor3f(0.0, 0.0, 0.0);
	}
}

void front()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 825.0);
	glVertex2f(1280.0, 825.0);
	glVertex2f(1280.0, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.7);
	bitmap_output(220, 700, "HKBK COLLEGE OF ENGINEERING", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(200, 650, "DEPARTMENT OF COMPUTER SCIENCE", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.619, 0.431, 0.239);
	bitmap_output(280, 520, "MINI PROJECT ON", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 0.7, 0.0);
	bitmap_output(225, 470, "Demonstration of Sorting Algorithms", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(225, 450, "--------------------------", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.8, 0.0, 0.8);
	bitmap_output(50, 320, "By,", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(70, 275, "Abdul Ghani [1HK17CS004]", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(500, 275, "Guide: Prof. Pushpa.T", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.364, 0.811, 0.937);
	glBegin(GL_QUADS);
	glVertex2f(170, 100.0);
	glVertex2f(170, 170);
	glVertex2f(346, 170);
	glVertex2f(346, 100.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	bitmap_output(190, 125, "Press Enter to continue", GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.364, 0.811, 0.937);
	glBegin(GL_QUADS);
	glVertex2f(420, 100.0);
	glVertex2f(420, 170);
	glVertex2f(560, 170);
	glVertex2f(560, 100.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	bitmap_output(440, 125, "Press Esc to quit", GLUT_BITMAP_HELVETICA_18);
}

void Initialize()
{
	int temp1;
	bb1 = 0;
	bb2 = 1;
	speed = 500;
	// Reset the array
	for (temp1 = 0; temp1 < MAX; temp1++)
	{
		a[temp1] = rand() % 100 + 1;
		printf("%d ", a[temp1]);
	}

	// Reset all values
	i = j = 0;
	dirflag = 0;
	count = 1;
	flag = 0;

	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 699, 0, 799);
}

// Return 1 if not sorted
int notsorted()
{
	int q;
	for (q = 0; q < MAX - 1; q++)
	{
		if (a[q] > a[q + 1])
			return 1;
	}
	return 0;
}

// Main function for display
void display()
{
	int ix, temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if (k == 0)
		front();
	else
	{
		display_text();
		char text[10];
		int gap = 4;
		for (ix = 0; ix < MAX; ix++)
		{
			if (bb1 == ix)
				glColor3f(1.0, 0.0, 0.0);
			else if (bb2 == ix)
				glColor3f(0.0, 1.0, 0.0);
			else
				glColor3f(0.4, 0.4, 0.7);

			// glColor3f(1, 0, 0);
			// glColor3f(0.4, 0.4, 0.7);
			// glBegin(GL_LINE_LOOP);
			glBegin(GL_QUADS);
			glVertex2f(10 + (700 / (MAX + 1)) * ix + gap, 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (ix + 1), 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (ix + 1), 50 + a[ix] * 4);
			glVertex2f(10 + (700 / (MAX + 1)) * ix + gap, 50 + a[ix] * 4);
			glEnd();

			int_str(a[ix], text);
			//printf("\n%s",text);
			glColor3f(0, 0, 0);
			bitmap_output(12 + (700 / (MAX + 1)) * ix + gap, 35, text, GLUT_BITMAP_TIMES_ROMAN_10);
		}
	}
	glFlush();
}

// Insertion Sort
void insertionsort()
{
	int temp;

	while (i < MAX)
	{
		if (flag == 0)
		{
			j = i;
			flag = 1;
		}
		while (j < MAX - 1)
		{
			if (a[j] > a[j + 1])
			{
				swapflag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				bb1 = j - 1;
				bb2 = j;

				goto A;
			}
			j++;
			if (j == MAX - 1)
			{
				flag = 0;
			}
			printf("swap %d and %d\n", a[j], a[j + 1]);
		}
		i++;
	}
	sorting = 0;
A:
	i = j = 0;
}

// Selection Sort
void selectionsort()
{
	int temp, j, min, pos;

	while (notsorted())
	{

		while (i < MAX - 1)
		{
			min = a[i + 1];
			pos = i + 1;
			if (i != MAX - 1)
			{
				for (j = i + 2; j < MAX; j++)
				{
					if (min > a[j])
					{
						min = a[j];
						pos = j;
					}
				}
			}
			printf("\ni=%d min=%d at %d", i, min, pos);
			printf("\nchecking %d and %d", min, a[i]);
			if (min < a[i])
			{

				//j=pos;
				printf("\nswapping %d and %d", min, a[i]);
				temp = a[pos];
				a[pos] = a[i];
				a[i] = temp;
				bb1 = pos;
				bb2 = i;
				goto A;
			}
			i++;
		}
	}
	sorting = 0;
	i = j = 0;
A:
	printf("");
}

//Bubble Sort
void bubblesort()
{
	int temp;
	while (notsorted())
	{
		while (j < MAX - 1)
		{

			// bb1 = j + 1;
			// bb2 = j + 2;
			if (a[j] > a[j + 1])
			{
				bb1 = j + 1;
				bb2 = j + 2;
				swapflag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				goto A;
			}
			else
			{
				bb1 = j + 1;
				bb2 = j + 2;
			}
			j++;
			if (j == MAX - 1)
				j = 0;
			printf("swap %d and %d\n", a[j], a[j + 1]);
		}
	}
	sorting = 0;
A:
	printf("");
}

//Ripple Sort
void ripplesort()
{
	int temp;
	while (notsorted() && sorting)
	{
		if (dirflag == 0)
		{
			while (j < MAX - 1)
			{
				if (j < MAX - 1)
				{
					bb1 = j + 1;
					bb2 = j + 2;
				}
				if (a[j] > a[j + 1])
				{
					swapflag = 1;
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;

					goto A;
				}
				j++;
				if (j == MAX - 1)
				{
					count++;
					j = MAX - count;
					dirflag = 1;
				}
				printf("j=%d forward swap %d and %d\n", j, a[j], a[j + 1]);
			}
		}
		else
		{
			while (j >= 0)
			{

				bb1 = j - 1;
				bb2 = j;
				if (a[j] > a[j + 1])
				{
					swapflag = 1;
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;

					goto A;
				}
				j--;
				if (j == 0)
				{
					dirflag = 0;
				}
				printf("j=%d backward swap %d and %d\n", j, a[j], a[j + 1]);
			}
		}
	}
	sorting = 0;
A:
	printf("");
}

// Timer Function, takes care of sort selection
void makedelay(int)
{
	if (sorting)
	{
		switch (sort_count)
		{
		case 0:
			bubblesort();
			break;
		case 1:
			selectionsort();
			break;
		case 2:
			insertionsort();
			break;
		case 3:
			ripplesort();
			break;
		}
	}
	glutPostRedisplay();
	// glutTimerFunc(SPEED / MAX, makedelay, 1);
	glutTimerFunc(speed, makedelay, 1);
}

// Keyboard Function
void keyboard(unsigned char key, int x, int y)
{
	if (key == 13)
		k = 1;
	else if (key == 27)
		exit(0);
	if (k == 1 && sorting != 1)
	{
		switch (key)
		{
		case 27:
			exit(0); // 27 is the ascii code for the ESC key
		case 's':
			sorting = 1;
			break;
		case 'g':
			Initialize();
			break;
		case 'n':
			sort_count = (sort_count + 1) % SORT_NO;
			break;
		}
	}
	if (k == 1 && sorting == 1)
		if (key == 'p')
			sorting = 0;
		else if (key == '-' and speed + 50 <= 1000)
			speed += 50;
		else if (key == '+' and speed - 50 >= 50)
			speed -= 50;
}

// Main Function
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Demonstration of Sorting Algorithms");
	Initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, makedelay, 1);
	glutMainLoop();
	return 0;
}
