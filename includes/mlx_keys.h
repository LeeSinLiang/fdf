/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:44:35 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:44:36 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H


#define MOUSE_LEFT_CLICK 1
#define MOUSE_RIGHT_CLICK 3
#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define ENTERWINDOWMASK (1L<<4)
# define LEAVEWINDOWMASK (1L<<5)
# define POINTERMOTIONMASK (1L<<6)
# define POINTERMOTIONHINTMASK (1L<<7)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYMAPSTATEMASK (1L<<14)
# define EXPOSUREMASK (1L<<15)
# define VISIBILITYCHANGEMASK (1L<<16)
# define STRUCTURENOTIFYMASK (1L<<17)
# define RESIZEREDIRECTMASK (1L<<18)
# define SUBSTRUCTURENOTIFYMASK (1L<<19)
# define SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define FOCUSCHANGEMASK (1L<<21)
# define PROPERTYCHANGEMASK (1L<<22)
# define COLORMAPCHANGEMASK (1L<<23)
# define OWNERGRABBUTTONMASK (1L<<24)

# if defined(__APPLE__) || defined(__MACH__)

/*
** Keyboard keys
*/

/*
** Letters keys
*/

# define A_KEY 0
# define B_KEY 11
# define C_KEY 8
# define D_KEY 2
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 1
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 13
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6

/*
** Numbers (not numeric keypad ones)
*/

# define K1_KEY 18
# define K2_KEY 19
# define K3_KEY 20
# define K4_KEY 21
# define K5_KEY 23
# define K6_KEY 22
# define K7_KEY 26
# define K8_KEY 28
# define K9_KEY 25
# define K0_KEY 29

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the point (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

# define SP_KEY 49
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44

/*
** Functions keys, you might use fn key to use them
** I didn't find the F11_KEY value
*/

# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80

/*
** Arrow keys
*/

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

# define ESC_KEY 53
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71

/*
** Numeric keyboard keys, preceded by NK
** NKEQ_KEY is the equal (=) key
** NKSL_KEY is the slash (/) key
** NKWC_KEY is the wildcard (*) key
** NKMN_KEY is the minus (-) key
** NKPL_KEY is the plus (+) key
** NKPT_KEY is the point (.) key
** NKNTR_KEY is the enter key
*/

# define NK1_KEY 83
# define NK2_KEY 84
# define NK3_KEY 85
# define NK4_KEY 86
# define NK5_KEY 87
# define NK6_KEY 88
# define NK7_KEY 89
# define NK8_KEY 91
# define NK9_KEY 92
# define NK0_KEY 82
# define NKEQ_KEY 81
# define NKSL_KEY 75
# define NKWC_KEY 67
# define NKMN_KEY 78
# define NKPL_KEY 69
# define NKPT_KEY 65
# define NKNTR_KEY 76

# elif defined(__linux__) || defined(__unix__)

# define XK_LATIN1
# define XK_MISCELLANY
# include <X11/keysymdef.h>

/*
** Keyboard keys
*/

/*
** Letters keys
*/

# define A_KEY XK_a
# define B_KEY XK_b
# define C_KEY XK_c
# define D_KEY XK_d
# define E_KEY XK_e
# define F_KEY XK_f
# define G_KEY XK_g
# define H_KEY XK_h
# define I_KEY XK_i
# define J_KEY XK_j
# define K_KEY XK_k
# define L_KEY XK_l
# define M_KEY XK_m
# define N_KEY XK_n
# define O_KEY XK_o
# define P_KEY XK_p
# define Q_KEY XK_q
# define R_KEY XK_r
# define S_KEY XK_s
# define T_KEY XK_t
# define U_KEY XK_u
# define V_KEY XK_v
# define W_KEY XK_w
# define X_KEY XK_x
# define Y_KEY XK_y
# define Z_KEY XK_z

/*
** Numbers (not numeric keypad ones)
*/

# define K1_KEY XK_1
# define K2_KEY XK_2
# define K3_KEY XK_3
# define K4_KEY XK_4
# define K5_KEY XK_5
# define K6_KEY XK_6
# define K7_KEY XK_7
# define K8_KEY XK_8
# define K9_KEY XK_9
# define K0_KEY XK_0

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the period (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

# define SP_KEY XK_space
# define BQ_KEY XK_grave
# define MN_KEY XK_minus
# define PL_KEY XK_plus
# define SBO_KEY XK_bracketleft
# define SBC_KEY XK_bracketright
# define BSL_KEY XK_backslash
# define SC_KEY XK_semicolon
# define SQ_KEY XK_quoteright
# define CM_KEY XK_comma
# define PT_KEY XK_period
# define SL_KEY XK_slash

/*
** Functions keys, you might use fn key to use them
** I didn't find the F11_KEY value
*/

# define F1_KEY XK_F1
# define F2_KEY XK_F2
# define F3_KEY XK_F3
# define F4_KEY XK_F4
# define F5_KEY XK_F5
# define F6_KEY XK_F6
# define F7_KEY XK_F7
# define F8_KEY XK_F8
# define F9_KEY XK_F9
# define F10_KEY XK_F10
# define F11_KEY XK_F11
# define F12_KEY XK_F12
# define F13_KEY XK_F13
# define F14_KEY XK_F14
# define F15_KEY XK_F15
# define F16_KEY XK_F16
# define F17_KEY XK_F17
# define F18_KEY XK_F18
# define F19_KEY XK_F19

/*
** Arrow keys
*/

# define UP_KEY XK_Up
# define DOWN_KEY XK_Down
# define RIGHT_KEY XK_Right
# define LEFT_KEY XK_Left

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

# define ESC_KEY XK_Escape
# define TAB_KEY XK_Tab
# define CL_KEY XK_Caps_Lock
# define LSFT_KEY XK_Shift_L
# define LCTRL_KEY XK_Control_L
# define LOPT_KEY
# define LCMD_KEY 
# define LDEL_KEY XK_Delete
# define RTN_KEY XK_Return
# define RSFT_KEY XK_Shift_R
# define RCTRL_KEY XK_Control_R
# define ROPT_KEY
# define RCMD_KEY
# define EJ_KEY
# define FN_KEY XK_function
# define RDEL_KEY
# define HOME_KEY XK_Home
# define END_KEY XK_End
# define PUP_KEY XK_Page_Up
# define PDOWN_KEY XK_Page_Down
# define CLR_KEY XK_Clear

/*
** Numeric keyboard keys, preceded by NK
** NKEQ_KEY is the equal (=) key
** NKSL_KEY is the slash (/) key
** NKWC_KEY is the wildcard (*) key
** NKMN_KEY is the minus (-) key
** NKPL_KEY is the plus (+) key
** NKPT_KEY is the point (.) key
** NKNTR_KEY is the enter key
*/

# define NK1_KEY XK_KP_0
# define NK2_KEY XK_KP_1
# define NK3_KEY XK_KP_2
# define NK4_KEY XK_KP_3
# define NK5_KEY XK_KP_4
# define NK6_KEY XK_KP_5
# define NK7_KEY XK_KP_6
# define NK8_KEY XK_KP_7
# define NK9_KEY XK_KP_8
# define NK0_KEY XK_KP_9
# define NKEQ_KEY XK_KP_Equal
# define NKSL_KEY XK_KP_Divide
# define NKWC_KEY XK_KP_Multiply
# define NKMN_KEY XK_KP_Subtract
# define NKPL_KEY XK_KP_Add
# define NKPT_KEY XK_KP_Decimal
# define NKNTR_KEY XK_KP_Enter

# endif
#endif
