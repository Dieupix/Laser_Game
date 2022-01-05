#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

using namespace std;

#define far
#define huge
#define random(range) (rand() % (range))

#ifndef __COLORS
#define __COLORS
enum colors {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
    LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};
#endif

enum write_modes {
    COPY_PUT, XOR_PUT, OR_PUT, AND_PUT, NOT_PUT
};
enum line_styles {
    SOLID_LINE, DOTTED_LINE, CENTER_LINE, DASHED_LINE, USERBIT_LINE
};
enum fill_styles {
    EMPTY_FILL, SOLID_FILL, LINE_FILL, LTSLASH_FILL, SLASH_FILL, BKSLASH_FILL,
    LTBKSLASH_FILL, HATCH_FILL, XHATCH_FILL, INTERLEAVE_FILL, WIDE_DOT_FILL,
    CLOSE_DOT_FILL, USER_FILL
};
enum text_directions {
    HORIZ_DIR, VERT_DIR
};
enum font_types {
    DEFAULT_FONT, TRIPLEX_FONT, SMALL_FONT, SANSSERIF_FONT, GOTHIC_FONT
};

#define LEFT_TEXT					0
#define CENTER_TEXT					1
#define RIGHT_TEXT					2
#define BOTTOM_TEXT					0
#define TOP_TEXT					2

#define NORM_WIDTH					1
#define THICK_WIDTH					3

#define DOTTEDLINE_LENGTH           2
#define CENTRELINE_LENGTH           4

#define USER_CHAR_SIZE				0
#define MAXCOLORS					15

#define CLIP_ON						1
#define CLIP_OFF					0

#define TOP_ON						1
#define TOP_OFF                     0

enum graphics_errors {
	grOk = 0,
	grNoInitGraph = -1,
	grNotDetected = -2,
	grFileNotFound = -3,
	grInvalidDriver	= -4,
	grNoLoadMem = -5,
	grNoScanMem = -6,
	grNoFloodMem = -7,
	grFontNotFound = -8,
	grNoFontMem = -9,
	grInvalidMode =	-10,
	grError = -11,
	grIOerror = -12,
	grInvalidFont = -13,
	grInvalidFontNum = -14,
	grInvalidDeviceNum = -15,
	grInvalidVersion = -18
};

const double pi = 3.14159265358979323846;

/* Graphics drivers constants, includes X11 which is particular to XBGI. */
#define DETECT						0
#define CGA						    1
#define MCGA						2
#define EGA						    3
#define EGA64						4
#define EGAMONO						5
#define IBM8514						6
#define HERCMONO					7
#define ATT400						8
#define VGA						    9
#define PC3270						10

/* Graphics modes constants. */
#define CGAC0						0
#define CGAC1						1
#define CGAC2						2
#define CGAC3						3
#define CGAHI						4

#define MCGAC0						0
#define MCGAC1						1
#define MCGAC2						2
#define MCGAC3						3
#define MCGAMED						4
#define MCGAHI						5

#define EGALO						0
#define EGAHI						1

#define EGA64LO						0
#define EGA64HI						1

#define EGAMONOHI					3

#define HERCMONOHI					0

#define ATT400C0					0
#define ATT400C1					1
#define ATT400C2					2
#define ATT400C3					3
#define ATT400MED					4
#define ATT400HI					5

#define VGALO						0
#define VGAMED						1
#define VGAHI						2
#define VGAMAX                      3

#define PC3270HI					0

#define IBM8514LO					0
#define IBM8514HI					1

typedef struct arccoordstype {
    int x;
    int y;
    int xstart;
    int ystart;
    int xend;
    int yend;
} arccoordstype;

typedef char fillpatterntype[8];

typedef struct fillsettingstype {
    int pattern;
    int color;
} fillsettingstype;

typedef struct linesettingstype {
    int linestyle;
    unsigned int upattern;
    int thickness;
} linesettingstype;

typedef struct palettetype {
    unsigned char size;
    signed char colors[16];
} palettetype;

typedef struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
} textsettingstype;

typedef struct viewporttype {
    int left;
    int top;
    int right;
    int bottom;
    int clip;
} viewporttype;


#if defined(__cplusplus)
extern "C" {
#endif

//
// Setting this variable to 0 increase speed of drawing but
// correct redraw is not possible. By default this variable is initialized by 1
//
extern int bgiemu_handle_redraw;

//
// Default mode choosed by WinBGI if DETECT value is specified for
// device parameter of initgraoh(). Default value is VGAMAX which
// cause creation of maximized window (resolution depends on display mode)
//
extern int bgiemu_default_mode;

void _graphfreemem (void *ptr, unsigned int size);
void* _graphgetmem (unsigned int size);
void arc (int x, int y, int start_angle, int end_angle, int radius);
void bar (int left, int top, int right, int bottom);
void bar3d (int left, int top, int right, int bottom, int depth, int topflag);
void circle (int x, int y, int radius);
void cleardevice (void);
void clearviewport (void);
void closegraph (void);
void detectgraph (int *, int *);
void drawpoly (int, int *);
void ellipse (int x, int y, int start_angle, int end_angle, int rx, int ry);
void fillellipse (int x, int y, int rx, int ry);
void fillpoly (int, int *);
void fillrect(int, int, int, int, int c = WHITE);
void filltriangle(int x0, int y0, int x1, int y1, int x2, int y2, int c = WHITE);
void floodfill (int x, int y, int border);
void getarccoords (arccoordstype *);
void getaspectratio (int *, int *);
int getbkcolor (void);
int getcolor (void);
palettetype* getdefaultpalette (void);
const char* getdrivername (void);
void getfillpattern (char const *);
void getfillsettings (fillsettingstype *);
int getgraphmode (void);
void getimage (int, int, int, int, void *);
void getlinesettings (linesettingstype *);
int getmaxcolor (void);
int getmaxmode (void);
int getmaxx (void);
int getmaxy (void);
char* getmodename (int);
void getmoderange (int, int *, int *);
void getpalette (palettetype *);
int getpalettesize (void);
unsigned int getpixel (int x, int y);
void gettextsettings (textsettingstype *);
void getviewsettings (viewporttype *);
int getx (void);
int gety (void);
void graphdefaults (void);
char* grapherrormsg (int);
int graphresult (void);
unsigned int imagesize (int, int, int, int);
void initgraph (int *, int *, char const *);
int installuserdriver (char const *, int *);
int installuserfont (char const *);
void line (int x0, int y0, int x1, int y1);
void linerel (int dx, int dy);
void lineto (int x, int y);
void moverel (int dx, int dy);
void moveto (int x, int y);
void outtext (char const *);
void outtextxy (int, int, char const *);
void pieslice (int x, int y, int start_angle, int end_angle, int radius);
void putimage (int, int, void *, int);
void putpixel (int x, int y, int c);
void plot (int x, int y);
void rectangle (int left, int top, int right, int bottom);
int registerbgidriver (void *);
int registerbgifont (void *);
void restorecrtmode (void);
void sector (int x, int y, int start_angle, int end_angle, int rx, int ry);
void setactivepage (int);
void setallpalette (palettetype *);
void setaspectratio (int ax, int ay);
void setbkcolor (int color);
void setcolor (int c);
void setfillpattern (char const *, int);
void setfillstyle (int, int);
unsigned int setgraphbufsize (unsigned int);
void setgraphmode (int);
void setlinestyle (int, unsigned int, int);
void setpalette (int, int);
void setrgbpalette (int, int, int, int);
void settextjustify (int, int);
void settextstyle (int, int, int);
void setusercharsize (int, int, int, int);
void setviewport (int, int, int, int, int);
void setvisualpage (int);
void setwritemode (int);
int textheight (char const *);
int textwidth (char const *);
void triangle(int x0, int y0, int x1, int y1, int x2, int y2, int c = WHITE);
int getch (void);
int kbhit (void);

void delay (unsigned msec);
void restorecrtmode (void);

// ajouts

void opengraph (void);
void opengraphsize (int width,int height);
int keypressed (void);

int buttonhit (void);
void getmouse (int& x,int& y);
void clearMouseQueue(void);
bool isMouseQueueEmpty(void);
int buttonpressed (void);
void waituntilkeypressed();
void waituntilbuttonpressed();

#if defined(__cplusplus)
}
#endif




#endif
