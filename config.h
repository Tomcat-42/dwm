/*fib layout */
#include "fibonacci.c"

/* movestack patch */
#include "movestack.c"

/* Teclas especiais */
#include <X11/XF86keysym.h>

#define KP_LEFT 0xff96
#define KP_RIGHT 0xff98
#define KP_BEGIN 0xff9d
#define KP_UP 0xff97
#define KP_DOWN 0xff99
#define KP_DIVIDE 0xffaf
#define KP_NEXT 0xff9b
#define KP_END 0xff9c
#define KP_SUBTRACT 0xffad
#define KP_PRIOR 0xff9a
#define KP_HOME 0xff95
#define KP_DECIMAL
#define KP_ENTER 0xff8d
#define KP_ADD 0xffab
#define KP_INSERT 0xff9e
#define KP_DELETE 0xff9f
#define SND_MUTE 0x1008ff12
#define SND_DEC 0x1008ff11
#define SND_INC 0x1008ff13
#define MIC_MUTE 0x1008ffb2
// #define BRIGH_DEC 0x1008ffb2
// #define BRIGH_DEC 0x1008ffb2
#define MONIT_SEL 0x1008ff59
#define WIFI_TOGGLE 0x1008ff95
#define CONFIG_LAUNCH 0x1008ff81
#define TOOGLE_BT 0x1008ff94
#define FAVORITES 0x1008ff30
#define SUPER 0xffeb

/* Programas */
#define BROWSER "firefox"
#define TERM "st"
#define GUIFM "pcmanfm"
#define CLIFM "ranger"

/* Fontes */
//#define FONT "envypn:size=11"
#define FONT "Terminus:size=12"

/* Cores do pywal */
#define PYWAL 0

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { FONT };
static const char dmenufont[]       = FONT;
static const unsigned int gappx     = 6;        /* gaps between windows */

/* Colorscheme */
#if PYWAL
#include "/home/pablo951_br/.cache/wal/colors-wal-dwm.h"
#else
/*
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
*/

static const char norm_fg[] = "#c4c5c6";
static const char norm_bg[] = "#15181c";
static const char norm_border[] = "#4f5154";

static const char sel_fg[] = "#c4c5c6";
static const char sel_bg[] = "#35538d";
static const char sel_border[] = "#35538d";

//static const char urg_fg[] = "#c5c5c5";
//static const char urg_bg[] = "#264364";
//static const char urg_border[] = "#264364";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
//    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
#endif


/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
//static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Sxiv",     NULL,       NULL,       0     ,       1,           -1 },
	{ "mpv",      NULL,       NULL,       0     ,       1,           -1 },
	{ TERM ,      NULL,       CLIFM,      1 << 1,       0,           -1 },
	{ "Pcmanfm",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "qutebrowser",NULL,     NULL,       1 << 2,       0,           -1 },
	{ "Tor Browser",NULL,     NULL,       1 << 2,       0,           -1 },
	{ TERM ,      NULL,       "ncmpcpp",  1 << 3,       0,           -1 },
	{ NULL,       NULL,       "spotify",  1 << 3,       0,           -1 },
	{ "feh",      NULL,       NULL,       1 << 3,       0,           -1 },
	{ "vlc",      NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Minetest",NULL,        NULL,       1 << 4,       0,           -1 },
	//xonotic
	{ "Darkplaces",NULL,      NULL,       1 << 4,       0,           -1 },
	{ "retroarch",NULL,       NULL,       1 << 4,       0,           -1 },
	//shiginima
	{ "net-mc-main-Main",NULL,NULL,       1 << 4,       0,           -1 },
	//minecraft
	{ "^.*\\b(Minecraft)\\b.*$",NULL,NULL,1 << 4,       0,           -1 },
	{ "Steam" ,   NULL,       NULL,       1 << 4,       0,           -1 },
	//arduino-ide
	{ "PCSX2" ,   NULL,       NULL,       1 << 4,       0,           -1 },
	//{ "MPlayer",  NULL,       NULL,       1 << 5,       1,           -1 },
	{ "MPlayer",  NULL,       NULL,       0,            1,           -1 },
	{ "ffplay",   NULL,       NULL,       1 << 5,       1,           -1 },
	{ "Gimp",     NULL,       NULL,       1 << 6,       0,           -1 },
	{ "Leafpad",  NULL,       NULL,       1 << 6,       0,           -1 },
	{ "Libreoffice",NULL,     NULL,       1 << 6,       0,           -1 },
	{ "Libreoffice-writer",NULL, NULL,    1 << 6,       0,           -1 },
	{ "Libreoffice-impress",NULL, NULL,   1 << 6,       0,           -1 },
	{ "Pavucontrol",NULL,     NULL,       1 << 7,       0,           -1 },
	{ "qpaeq" ,   NULL,       NULL,       1 << 7,       0,           -1 },
	{ "Lxappearance",NULL,    NULL,       1 << 7,       0,           -1 },
	{ "Gparted",  NULL,       NULL,       1 << 7,       0,           -1 },
	{ "Gsmartcontrol",NULL,   NULL,       1 << 7,       0,           -1 },
	{ "Filezilla",NULL,       NULL,       1 << 8,       0,           -1 },
	{ TERM ,      NULL,       "newsboat", 1 << 8,       0,           -1 },
	{ TERM ,      NULL,       "clima",    1 << 8,       0,           -1 },
	{ TERM ,      NULL,       "calendario",1 << 8,      0,           -1 },
	{ "processing-app-Base" , NULL, NULL, 1 << 8,       0,           -1 },
	{ TERM ,      NULL,       "nload",    1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[@]",      spiral },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[\\]",      dwindle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { TERM, NULL };
static const char *shellpythoncmd[]  = { TERM, "-t", "Shell_python", "-e", "python",  NULL };
static const char *browsercmd[]  = { BROWSER, NULL };
static const char *guiFMcmd[]  = { GUIFM, NULL };
static const char *cliFMcmd[]  = { TERM, "-t", "ranger", "-e", CLIFM, NULL };
static const char *ncmpcpp[]  = { TERM, "-t", "ncmpcpp", "-e", "ncmpcpp", NULL };
static const char *netmngr[]  = { "networkmanager_dmenu", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	
	//mpd keys
	{ MODKEY|ControlMask,             XK_u,      spawn,          SHCMD("mpc prev")},
	{ MODKEY|ControlMask,             XK_o,      spawn,          SHCMD("mpc next")},
	{ MODKEY|ControlMask,             XK_i,      spawn,          SHCMD("mpc toggle")},
	{ MODKEY|ControlMask,             XK_l,      spawn,          SHCMD("mpc seek +5")},
	{ MODKEY|ControlMask,             XK_j,      spawn,          SHCMD("mpc seek -5")},
	{ MODKEY|ControlMask,             XK_semicolon, spawn,          SHCMD("mpc random")},
	{ MODKEY|ControlMask,             XK_p,      spawn,          SHCMD("mpc stop")},
	//{ 0,                            KP_SUBTRACT,  spawn,       SHCMD("mpc shuffle")},
	//{ 0,                            KP_DECIMAL,   spawn,          SHCMD("mpc consume")},
	{ MODKEY|ControlMask,             XK_bracketright,  spawn,          SHCMD("mpc volume -5")},
	{ MODKEY|ControlMask,             XK_bracketleft,   spawn,          SHCMD("mpc volume +5")},
	//{ 0,                            KP_ENTER,  spawn,          SHCMD("mpc single")},
	//volume keys
	{ 0,                            SND_INC,     spawn,          SHCMD("amixer set Master -q 5%+")},
	{ 0,                            SND_DEC,   spawn,          SHCMD("amixer set Master -q 5%-")},
	{ 0,                            SND_MUTE, spawn,          SHCMD("amixer -q sset Master,0 toggle")},
	{ 0,                            MIC_MUTE, spawn,          SHCMD("amixer set Capture toggle")},
	{ 0,                            MONIT_SEL, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/displayselect")},
	{ 0,                            WIFI_TOGGLE, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/toggle_wifi")},
	{ 0,                            FAVORITES,     spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/ducksearch")},
	{ MODKEY,                       XK_period, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/mpdnotify")},
	
	//F1-F12 keys
	{ MODKEY,                       XK_F1,     spawn,          SHCMD(TERM " -t newsboat -e newsboat")},
	{ MODKEY,                       XK_F2,     spawn,          SHCMD(TERM " -t clima -e 'curl wttr.in'")},
	{ MODKEY,                       XK_F3,     spawn,          SHCMD(TERM " -t calendario -e 'bash /home/pablo951_br/Downloads/scripts/binding_calcurse.sh'")},
	{ MODKEY,                       XK_F5,     spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/dmenu_mount")},
	{ MODKEY,                       XK_F6,     spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/dmenu_umount")},
	{ MODKEY,                       XK_F8,     spawn,          SHCMD(TERM " -t nload -e nload")},
	{ MODKEY,                       XK_F9,     spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/webcam")},
	{ MODKEY,                       XK_F10,    spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/dmenu_record")},


	//Outros
	//{ MODKEY|ControlMask,           XK_k,      spawn,          SHCMD("setxkbmap -model abnt2 -layout br ; xset r rate 280 35") },
	{ MODKEY|ControlMask,           XK_l,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/lock_n_off.sh") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/desligar_monitor.sh off") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/lock_n_off_n_suspend.sh") },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/redshift_dmenu") },
	{ MODKEY|ControlMask,           XK_b,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/tlp_dmenu") },
	{ 0,                            CONFIG_LAUNCH,spawn,       SHCMD("/home/pablo951_br/Downloads/scripts/toggletouchpad") },
	//{ MODKEY,                  XK_Tab,      spawn,          SHCMD("rofi -show window -i -lines 10 -eh 1 -width 50 -padding 50 -opacity "85" -font \"Droid Sans 16\" ") },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_f,      spawn,          {.v = browsercmd} },
	{ MODKEY,                       XK_p,      spawn,          {.v = shellpythoncmd} },
	{ MODKEY,                       XK_m,      spawn,          {.v = guiFMcmd} },
	{ MODKEY,                       XK_r,      spawn,          {.v = cliFMcmd} },
	{ MODKEY,                       XK_n,      spawn,          {.v = ncmpcpp} },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          {.v = netmngr} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_Insert, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/showclip") },
	{ MODKEY,                       XK_Pause,  spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/xcqr") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD( TERM " -t weechat -e weechat")},
	{ MODKEY,                       XK_c,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/chcolor_gui") },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/toggle_caffeine") },
	{ MODKEY,                       XK_z,      spawn,              SHCMD("scrot /home/pablo951_br/`date +%Y-%m-%d_%H:%M:%S`.png") },
	{ MODKEY|ShiftMask,             XK_z,      spawn,          SHCMD("scrot -u /home/pablo951_br/`date +%Y-%m-%d_%H:%M:%S`.png") },
	{ MODKEY|ControlMask,           XK_z,      spawn,          SHCMD("scrot -s /home/pablo951_br/`date +%Y-%m-%d_%H:%M:%S`.png") },
	{ MODKEY,                       XK_Delete, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/dmenu_computer") },
	{ MODKEY,                       XK_x, spawn,          SHCMD("/home/pablo951_br/Downloads/scripts/mpdmenu :: -l 3") },
	
	//teclas especiais
	{ 0,                            XF86XK_MonBrightnessDown, spawn, SHCMD("xbacklight -dec 10") },
	{ 0,                            XF86XK_MonBrightnessUp, spawn, SHCMD("xbacklight -inc 10") },
	//{ 0,                            XF86XK_AudioPlay, spawn, SHCMD("mpc toggle") },
	{ 0,                            XF86XK_Sleep, spawn, SHCMD("/home/pablo951_br/Downloads/scripts/lock_n_off.sh") },
	
	//layouts
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	// bottomstach
	//{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	//{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	//{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ 0     ,                       SUPER,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	//{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	//{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
