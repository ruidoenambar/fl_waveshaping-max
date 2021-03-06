#ifndef fl_ws_hfolder_h
#define fl_ws_hfolder_h

#include "ext.h"
#include "z_dsp.h"
#include "ext_obex.h"

#include <math.h>

#define EPSILON_PARAM 0.001
#define DEFAULT_PARAM 0.

/* object structure */
typedef struct _fl_ws_hfolder {

	t_pxobject obj;

	short param_connected;

	float param;

} t_fl_ws_hfolder;

/* inlets/outlets */
enum INLETS { I_INPUT, I_PARAM, NUM_INLETS };
enum OUTLETS { O_OUTPUT, NUM_OUTLETS };

/* class pointer */
static t_class *fl_ws_hfolder_class;

/* function prototypes */
void *fl_ws_hfolder_new(t_symbol *s, short argc, t_atom *argv);
void fl_ws_hfolder_float(t_fl_ws_hfolder *x, double farg);
void fl_ws_hfolder_assist(t_fl_ws_hfolder *x, void *b, long msg, long arg, char *dst);

	/* memory */
void fl_ws_hfolder_free(t_fl_ws_hfolder *x);

	/* audio */
void fl_ws_hfolder_dsp64(t_fl_ws_hfolder *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags);
void fl_ws_hfolder_perform64(t_fl_ws_hfolder *x, t_object *dsp64, double **inputs, long numinputs, double **outputs, long numoutputs, long vectorsize, long flags, void *userparams);

#endif /* fl_ws_hfolder_h */
