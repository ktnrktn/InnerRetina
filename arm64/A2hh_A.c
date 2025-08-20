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
 
#define nrn_init _nrn_init__A
#define _nrn_initial _nrn_initial__A
#define nrn_cur _nrn_cur__A
#define _nrn_current _nrn_current__A
#define nrn_jacob _nrn_jacob__A
#define nrn_state _nrn_state__A
#define _net_receive _net_receive__A 
#define _f_rate _f_rate__A 
#define rate rate__A 
#define states states__A 
 
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
#define gIAbar _p[0]
#define gIAbar_columnindex 0
#define ik _p[1]
#define ik_columnindex 1
#define m _p[2]
#define m_columnindex 2
#define h1 _p[3]
#define h1_columnindex 3
#define h2 _p[4]
#define h2_columnindex 4
#define c _p[5]
#define c_columnindex 5
#define ek _p[6]
#define ek_columnindex 6
#define Dm _p[7]
#define Dm_columnindex 7
#define Dh1 _p[8]
#define Dh1_columnindex 8
#define Dh2 _p[9]
#define Dh2_columnindex 9
#define Dc _p[10]
#define Dc_columnindex 10
#define _g _p[11]
#define _g_columnindex 11
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
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
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_c_func(void);
 static void _hoc_h2_tau(void);
 static void _hoc_h1_tau(void);
 static void _hoc_h_inf(void);
 static void _hoc_m_inf(void);
 static void _hoc_rate(void);
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

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_A", _hoc_setdata,
 "c_func_A", _hoc_c_func,
 "h2_tau_A", _hoc_h2_tau,
 "h1_tau_A", _hoc_h1_tau,
 "h_inf_A", _hoc_h_inf,
 "m_inf_A", _hoc_m_inf,
 "rate_A", _hoc_rate,
 0, 0
};
#define c_func c_func_A
#define h2_tau h2_tau_A
#define h1_tau h1_tau_A
#define h_inf h_inf_A
#define m_inf m_inf_A
 extern double c_func( double );
 extern double h2_tau( double );
 extern double h1_tau( double );
 extern double h_inf( double );
 extern double m_inf( double );
 /* declare global and static user variables */
#define cfunc cfunc_A
 double cfunc = 0;
#define h2tau h2tau_A
 double h2tau = 0;
#define h1tau h1tau_A
 double h1tau = 0;
#define hinf hinf_A
 double hinf = 0;
#define minf minf_A
 double minf = 0;
#define usetable usetable_A
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "gIAbar_A", 0, 1e+09,
 "usetable_A", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "h1tau_A", "ms",
 "h2tau_A", "ms",
 "cfunc_A", "mV",
 "gIAbar_A", "mho/cm2",
 "ik_A", "mA/cm2",
 0,0
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h20 = 0;
 static double h10 = 0;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "minf_A", &minf_A,
 "hinf_A", &hinf_A,
 "h1tau_A", &h1tau_A,
 "h2tau_A", &h2tau_A,
 "cfunc_A", &cfunc_A,
 "usetable_A", &usetable_A,
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
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"A",
 "gIAbar_A",
 0,
 "ik_A",
 0,
 "m_A",
 "h1_A",
 "h2_A",
 "c_A",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	gIAbar = 0.00026;
 	_prop->param = _p;
 	_prop->param_size = 12;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _A2hh_A_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 12, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 A /Users/kitano/Desktop/retina/mod/A2hh_A.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double _ztmp1 , _ztmp2 ;
 static double *_t_minf;
 static double *_t_hinf;
 static double *_t_h1tau;
 static double *_t_h2tau;
 static double *_t_c;
static int _reset;
static char *modelname = "HH k channel channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_rate(double);
static int rate(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static void _n_rate(double);
 static int _slist1[3], _dlist1[3];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
   Dm = ( minf - m ) / 1.0 ;
   Dh1 = ( hinf - h1 ) / h1tau ;
   Dh2 = ( hinf - h2 ) / h2tau ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rate ( _threadargscomma_ v * 1.0 ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / 1.0 )) ;
 Dh1 = Dh1  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h1tau )) ;
 Dh2 = Dh2  / (1. - dt*( ( ( ( - 1.0 ) ) ) / h2tau )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / 1.0)))*(- ( ( ( minf ) ) / 1.0 ) / ( ( ( ( - 1.0 ) ) ) / 1.0 ) - m) ;
    h1 = h1 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h1tau)))*(- ( ( ( hinf ) ) / h1tau ) / ( ( ( ( - 1.0 ) ) ) / h1tau ) - h1) ;
    h2 = h2 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / h2tau)))*(- ( ( ( hinf ) ) / h2tau ) / ( ( ( ( - 1.0 ) ) ) / h2tau ) - h2) ;
   }
  return 0;
}
 
double m_inf (  double _lv ) {
   double _lm_inf;
 _lm_inf = 1.0 / ( 1.0 + exp ( - ( _lv + 10.0 ) / 7.0 ) ) ;
   
return _lm_inf;
 }
 
static void _hoc_m_inf(void) {
  double _r;
   _r =  m_inf (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double h_inf (  double _lv ) {
   double _lh_inf;
 _lh_inf = 0.83 * ( 1.0 / ( 1.0 + exp ( ( _lv + 40.5 ) / 2.0 ) ) ) + 0.17 ;
   
return _lh_inf;
 }
 
static void _hoc_h_inf(void) {
  double _r;
   _r =  h_inf (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double h1_tau (  double _lv ) {
   double _lh1_tau;
 _lh1_tau = 1.0 / ( 25.0 - 20.0 / ( 1.0 + exp ( - ( _lv + 35.0 ) / 6.0 ) ) ) ;
   
return _lh1_tau;
 }
 
static void _hoc_h1_tau(void) {
  double _r;
   _r =  h1_tau (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double h2_tau (  double _lv ) {
   double _lh2_tau;
 _ztmp1 = ( ( ( _lv + 17.0 ) * ( _lv + 17.0 ) ) / 4.0 ) + 26.0 ;
   _ztmp2 = 100.0 ;
   if ( _ztmp1 < _ztmp2 ) {
     _lh2_tau = _ztmp1 ;
     }
   else {
     _lh2_tau = _ztmp2 ;
     }
   
return _lh2_tau;
 }
 
static void _hoc_h2_tau(void) {
  double _r;
   _r =  h2_tau (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double c_func (  double _lv ) {
   double _lc_func;
 c = 1.0 / ( 1.0 + exp ( - ( _lv + 45.0 ) / 15.0 ) ) ;
   
return _lc_func;
 }
 
static void _hoc_c_func(void) {
  double _r;
   _r =  c_func (  *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_rate, _tmin_rate;
 static void _check_rate();
 static void _check_rate() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  100.0 ;
   _dx = (_tmax - _tmin_rate)/200.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 201; _x += _dx, _i++) {
    _f_rate(_x);
    _t_minf[_i] = minf;
    _t_hinf[_i] = hinf;
    _t_h1tau[_i] = h1tau;
    _t_h2tau[_i] = h2tau;
    _t_c[_i] = c;
   }
  }
 }

 static int rate(double _lv){ _check_rate();
 _n_rate(_lv);
 return 0;
 }

 static void _n_rate(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rate(_lv); return; 
}
 _xi = _mfac_rate * (_lv - _tmin_rate);
 if (isnan(_xi)) {
  minf = _xi;
  hinf = _xi;
  h1tau = _xi;
  h2tau = _xi;
  c = _xi;
  return;
 }
 if (_xi <= 0.) {
 minf = _t_minf[0];
 hinf = _t_hinf[0];
 h1tau = _t_h1tau[0];
 h2tau = _t_h2tau[0];
 c = _t_c[0];
 return; }
 if (_xi >= 200.) {
 minf = _t_minf[200];
 hinf = _t_hinf[200];
 h1tau = _t_h1tau[200];
 h2tau = _t_h2tau[200];
 c = _t_c[200];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 minf = _t_minf[_i] + _theta*(_t_minf[_i+1] - _t_minf[_i]);
 hinf = _t_hinf[_i] + _theta*(_t_hinf[_i+1] - _t_hinf[_i]);
 h1tau = _t_h1tau[_i] + _theta*(_t_h1tau[_i+1] - _t_h1tau[_i]);
 h2tau = _t_h2tau[_i] + _theta*(_t_h2tau[_i+1] - _t_h2tau[_i]);
 c = _t_c[_i] + _theta*(_t_c[_i+1] - _t_c[_i]);
 }

 
static int  _f_rate (  double _lv ) {
   h1tau = h1_tau ( _threadargscomma_ _lv ) ;
   h2tau = h2_tau ( _threadargscomma_ _lv ) ;
   minf = m_inf ( _threadargscomma_ _lv ) ;
   hinf = h_inf ( _threadargscomma_ _lv ) ;
   cfunc = c_func ( _threadargscomma_ _lv ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
    _r = 1.;
 rate (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 3;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 3; ++_i) {
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
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  c = c0;
  h2 = h20;
  h1 = h10;
  m = m0;
 {
   rate ( _threadargscomma_ v * 1.0 ) ;
   m = minf ;
   h1 = hinf ;
   h2 = hinf ;
   c = cfunc ;
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
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ik = gIAbar * m * ( c * h1 + ( 1.0 - c ) * h2 ) * ( v - ek ) ;
   }
 _current += ik;

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
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
  ek = _ion_ek;
 { error =  states();
 if(error){fprintf(stderr,"at line 46 in file A2hh_A.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = m_columnindex;  _dlist1[0] = Dm_columnindex;
 _slist1[1] = h1_columnindex;  _dlist1[1] = Dh1_columnindex;
 _slist1[2] = h2_columnindex;  _dlist1[2] = Dh2_columnindex;
   _t_minf = makevector(201*sizeof(double));
   _t_hinf = makevector(201*sizeof(double));
   _t_h1tau = makevector(201*sizeof(double));
   _t_h2tau = makevector(201*sizeof(double));
   _t_c = makevector(201*sizeof(double));
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/kitano/Desktop/retina/mod/A2hh_A.mod";
static const char* nmodl_file_text = 
  "TITLE HH k channel channel\n"
  ": Hodgkin - Huxley A channel\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX A\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE gIAbar, ik\n"
  "	GLOBAL minf, hinf, cfunc, h1tau, h2tau\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gIAbar=.00026 (mho/cm2) <0,1e9>\n"
  "	ek = -77 (mV) :suggested, default set by NEURON\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m h1 h2 c\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	celsius (degC) : 16\n"
  "	ik (mA/cm2)\n"
  "	minf\n"
  "    hinf\n"
  "    h1tau (ms)\n"
  "    h2tau (ms)\n"
  "    cfunc (mV)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    rate(v*1(/mV))\n"
  "	m = minf\n"
  "    h1 = hinf\n"
  "    h2 = hinf\n"
  "    c = cfunc\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "    ik = gIAbar*m*(c*h1+(1-c)*h2)*(v - ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {	: exact when v held constant\n"
  "	rate(v*1(/mV))\n"
  "	m' = (minf - m)/1\n"
  "    h1' = (hinf - h1)/h1tau\n"
  "    h2' = (hinf - h2)/h2tau\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "FUNCTION m_inf(v(mV)) {\n"
  "    m_inf = 1/(1+exp(-( v + 10 ) / 7))\n"
  "}\n"
  "\n"
  "FUNCTION h_inf(v(mV)) {\n"
  "    h_inf = 0.83 * (1/(1+exp(( v + 40.5 ) / 2))) + 0.17\n"
  "}\n"
  "\n"
  "FUNCTION h1_tau(v(mV)) { :phi=0.039\n"
  "    h1_tau = 1/(25 - 20/(1 + exp(-( v + 35 ) / 6)))\n"
  "}\n"
  "\n"
  "LOCAL tmp1, tmp2\n"
  "\n"
  "FUNCTION h2_tau(v(mV)) { :phi=0.039\n"
  "    tmp1 = (((v+17)*(v+17)) / 4) + 26 \n"
  "    tmp2 = 100\n"
  "    if(tmp1<tmp2){\n"
  "        h2_tau = tmp1\n"
  "    }else{\n"
  "        h2_tau = tmp2\n"
  "    }\n"
  "}\n"
  "\n"
  "FUNCTION c_func(v(mV)) {\n"
  "    c = 1/(1+exp(-( v + 45 ) / 15))\n"
  "}\n"
  "\n"
  "PROCEDURE rate(v(mV)) {\n"
  "	TABLE minf,hinf,h1tau,h2tau,c FROM -100 TO 100 WITH 200\n"
  "		h1tau = h1_tau(v)\n"
  "        h2tau = h2_tau(v)\n"
  "        minf = m_inf(v)\n"
  "        hinf = h_inf(v)\n"
  "        cfunc = c_func(v)\n"
  "}\n"
  "UNITSON\n"
  ;
#endif
