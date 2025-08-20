/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__ribbon_syn
#define _nrn_initial _nrn_initial__ribbon_syn
#define nrn_cur _nrn_cur__ribbon_syn
#define _nrn_current _nrn_current__ribbon_syn
#define nrn_jacob _nrn_jacob__ribbon_syn
#define nrn_state _nrn_state__ribbon_syn
#define _net_receive _net_receive__ribbon_syn 
#define states states__ribbon_syn 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg(int);
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define tau_1A _p[0]
#define tau_1A_columnindex 0
#define tau_A3 _p[1]
#define tau_A3_columnindex 1
#define tau_32 _p[2]
#define tau_32_columnindex 2
#define tau_21 _p[3]
#define tau_21_columnindex 3
#define e _p[4]
#define e_columnindex 4
#define g_max _p[5]
#define g_max_columnindex 5
#define v_slp _p[6]
#define v_slp_columnindex 6
#define v_th _p[7]
#define v_th_columnindex 7
#define alpha _p[8]
#define alpha_columnindex 8
#define beta _p[9]
#define beta_columnindex 9
#define i _p[10]
#define i_columnindex 10
#define isyn _p[11]
#define isyn_columnindex 11
#define ca _p[12]
#define ca_columnindex 12
#define u _p[13]
#define u_columnindex 13
#define acm _p[14]
#define acm_columnindex 14
#define act _p[15]
#define act_columnindex 15
#define P1 _p[16]
#define P1_columnindex 16
#define P2 _p[17]
#define P2_columnindex 17
#define w _p[18]
#define w_columnindex 18
#define g _p[19]
#define g_columnindex 19
#define Dact _p[20]
#define Dact_columnindex 20
#define DP1 _p[21]
#define DP1_columnindex 21
#define DP2 _p[22]
#define DP2_columnindex 22
#define Dw _p[23]
#define Dw_columnindex 23
#define _g _p[24]
#define _g_columnindex 24
#define _nd_area  *_ppvar[0]._pval
#define v_pre	*_ppvar[2]._pval
#define _p_v_pre	_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 0, 0
};
 /* declare global and static user variables */
#define P2max P2max_ribbon_syn
 double P2max = 0.04;
#define P1max P1max_ribbon_syn
 double P1max = 0.01;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau_1A", "ms",
 "tau_A3", "ms",
 "tau_32", "ms",
 "tau_21", "ms",
 "e", "millvolts",
 "g_max", "umho",
 "v_slp", "millvolts",
 "v_th", "millvolts",
 "alpha", "1/ms",
 "beta", "1/ms",
 "i", "nanoamp",
 "isyn", "naonamp",
 "v_pre", "millivolt",
 0,0
};
 static double P20 = 0;
 static double P10 = 0;
 static double act0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 static double w0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "P1max_ribbon_syn", &P1max_ribbon_syn,
 "P2max_ribbon_syn", &P2max_ribbon_syn,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ribbon_syn",
 "tau_1A",
 "tau_A3",
 "tau_32",
 "tau_21",
 "e",
 "g_max",
 "v_slp",
 "v_th",
 "alpha",
 "beta",
 0,
 "i",
 "isyn",
 "ca",
 "u",
 "acm",
 0,
 "act",
 "P1",
 "P2",
 "w",
 0,
 "v_pre",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 25, _prop);
 	/*initialize range parameters*/
 	tau_1A = 2;
 	tau_A3 = 10000;
 	tau_32 = 2000;
 	tau_21 = 28;
 	e = 0;
 	g_max = 0.00256;
 	v_slp = 10;
 	v_th = -40;
 	alpha = 1;
 	beta = 1.1;
  }
 	_prop->param = _p;
 	_prop->param_size = 25;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ribbon_syn_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 25, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ribbon_syn /Users/kitano/Desktop/retina/mod/ribbon_syn.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static double *_temp1;
 static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   u = ( 1.0 + tanh ( ( v_pre - v_th ) / v_slp ) ) / 2.0 ;
   Dact = u * P1 / tau_1A - act / tau_A3 ;
   DP2 = ( 1.0 - P1 - P2 - act ) * ( P2max - P2 ) / tau_32 - P2 * ( P1max - P1 ) / tau_21 ;
   DP1 = P2 * ( P1max - P1 ) / tau_21 - u * P1 / tau_1A ;
   Dw = alpha * u * P1 / P1max - beta * w ;
   acm = acm + alpha * u * P1 / P1max ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 u = ( 1.0 + tanh ( ( v_pre - v_th ) / v_slp ) ) / 2.0 ;
 Dact = Dact  / (1. - dt*( ( - ( 1.0 ) / tau_A3 ) )) ;
 DP2 = DP2  / (1. - dt*( ( (( ( ( - 1.0 ) ) )*( ( P2max - P2 ) ) + ( ( 1.0 - P1 - P2 - act ) )*( ( ( - 1.0 ) ) )) ) / tau_32 - ( ( 1.0 )*( ( P1max - P1 ) ) ) / tau_21 )) ;
 DP1 = DP1  / (1. - dt*( ( ( P2 )*( ( ( - 1.0 ) ) ) ) / tau_21 - ( ( u )*( 1.0 ) ) / tau_1A )) ;
 Dw = Dw  / (1. - dt*( ( - ( beta )*( 1.0 ) ) )) ;
 acm = acm + alpha * u * P1 / P1max ;
  return 0;
}
 /*END CVODE*/
 
static int states () {_reset=0;
 {
   u = ( 1.0 + tanh ( ( v_pre - v_th ) / v_slp ) ) / 2.0 ;
   Dact = u * P1 / tau_1A - act / tau_A3 ;
   DP2 = ( 1.0 - P1 - P2 - act ) * ( P2max - P2 ) / tau_32 - P2 * ( P1max - P1 ) / tau_21 ;
   DP1 = P2 * ( P1max - P1 ) / tau_21 - u * P1 / tau_1A ;
   Dw = alpha * u * P1 / P1max - beta * w ;
   acm = acm + alpha * u * P1 / P1max ;
   }
 return _reset;}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  P2 = P20;
  P1 = P10;
  act = act0;
  w = w0;
 {
   act = 0.047 ;
   P1 = 0.00447 ;
   P2 = 0.028 ;
   w = 0.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = g_max * w ;
   isyn = g * ( v - e ) ;
   i = isyn ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 { error =  euler(_ninits, 4, _slist1, _dlist1, _p, &t, dt, states, &_temp1);
 if(error){fprintf(stderr,"at line 43 in file ribbon_syn.mod:\n    SOLVE states METHOD euler\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 4; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = act_columnindex;  _dlist1[0] = Dact_columnindex;
 _slist1[1] = P2_columnindex;  _dlist1[1] = DP2_columnindex;
 _slist1[2] = P1_columnindex;  _dlist1[2] = DP1_columnindex;
 _slist1[3] = w_columnindex;  _dlist1[3] = Dw_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/kitano/Desktop/retina/mod/ribbon_syn.mod";
static const char* nmodl_file_text = 
  ": four-state depressing synapse model for graded membrane potential\n"
  "\n"
  "NEURON {\n"
  "    POINT_PROCESS ribbon_syn\n"
  "    POINTER v_pre\n"
  "    RANGE e, tau_1A, tau_A3, tau_32, tau_21\n"
  "    RANGE v_th, v_slp, ca, acm\n"
  "    RANGE g_max, u, isyn, alpha, beta\n"
  "    NONSPECIFIC_CURRENT i\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    tau_1A = 2.0 (ms)\n"
  "    tau_A3 = 10000 (ms)\n"
  "    tau_32 = 2000 (ms)\n"
  "    tau_21 = 28 (ms)\n"
  "    P1max = 0.01\n"
  "    P2max = 0.04\n"
  "    e = 0 (millvolts)\n"
  "    g_max = 0.00256 (umho)  : maximal conductance\n"
  "    v_slp = 10.0 (millvolts) :10\n"
  "    v_th = -40.0 (millvolts) :-40\n"
  "    alpha = 1.0 (1/ms)\n"
  "    beta = 1.1 (1/ms)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    v (millivolt)\n"
  "    v_pre (millivolt)\n"
  "    i (nanoamp)\n"
  "    isyn (naonamp)\n"
  "    ca\n"
  "    u\n"
  "    g\n"
  "    acm\n"
  "}\n"
  "\n"
  "STATE {\n"
  "    act P1 P2 w\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE states METHOD euler\n"
  "    g = g_max * w\n"
  "    isyn = g * (v - e)\n"
  "    i = isyn\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  " act = 0.047\n"
  " P1 = 0.00447\n"
  " P2 = 0.028\n"
  " w = 0.0\n"
  ":    P3 = 0.9\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    u = (1.0+tanh((v_pre - v_th)/v_slp))/2.0\n"
  "    :ca = 0.038/(exp(-(v_pre-(-34))/6) + exp((v_pre-(23))/40))\n"
  "    :u = ca*ca*ca/(ca*ca*ca + 0.087*0.087*0.087)\n"
  "\n"
  "    act' = u*P1/tau_1A - act/tau_A3\n"
  "    P2' = (1-P1-P2-act)*(P2max-P2)/tau_32 - P2*(P1max-P1)/tau_21\n"
  "    P1' = P2*(P1max-P1)/tau_21 - u*P1/tau_1A\n"
  "\n"
  "    w' = alpha*u*P1/P1max -beta*w\n"
  "    acm = acm + alpha*u*P1/P1max\n"
  "}\n"
  ;
#endif
