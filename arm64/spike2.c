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
 
#define nrn_init _nrn_init__spike2
#define _nrn_initial _nrn_initial__spike2
#define nrn_cur _nrn_cur__spike2
#define _nrn_current _nrn_current__spike2
#define nrn_jacob _nrn_jacob__spike2
#define nrn_state _nrn_state__spike2
#define _net_receive _net_receive__spike2 
#define evaluate_fct_ca evaluate_fct_ca__spike2 
#define evaluate_fct_nak evaluate_fct_nak__spike2 
#define states states__spike2 
 
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
#define gnabar _p[0]
#define gnabar_columnindex 0
#define gkbar _p[1]
#define gkbar_columnindex 1
#define gcabar _p[2]
#define gcabar_columnindex 2
#define gkcbar _p[3]
#define gkcbar_columnindex 3
#define idrk _p[4]
#define idrk_columnindex 4
#define icak _p[5]
#define icak_columnindex 5
#define m_inf _p[6]
#define m_inf_columnindex 6
#define h_inf _p[7]
#define h_inf_columnindex 7
#define n_inf _p[8]
#define n_inf_columnindex 8
#define c_inf _p[9]
#define c_inf_columnindex 9
#define tau_m _p[10]
#define tau_m_columnindex 10
#define tau_h _p[11]
#define tau_h_columnindex 11
#define tau_n _p[12]
#define tau_n_columnindex 12
#define tau_c _p[13]
#define tau_c_columnindex 13
#define m_exp _p[14]
#define m_exp_columnindex 14
#define h_exp _p[15]
#define h_exp_columnindex 15
#define n_exp _p[16]
#define n_exp_columnindex 16
#define c_exp _p[17]
#define c_exp_columnindex 17
#define gkc _p[18]
#define gkc_columnindex 18
#define m _p[19]
#define m_columnindex 19
#define h _p[20]
#define h_columnindex 20
#define n _p[21]
#define n_columnindex 21
#define c _p[22]
#define c_columnindex 22
#define ena _p[23]
#define ena_columnindex 23
#define ek _p[24]
#define ek_columnindex 24
#define eca _p[25]
#define eca_columnindex 25
#define cao _p[26]
#define cao_columnindex 26
#define cai _p[27]
#define cai_columnindex 27
#define Dm _p[28]
#define Dm_columnindex 28
#define Dh _p[29]
#define Dh_columnindex 29
#define Dn _p[30]
#define Dn_columnindex 30
#define Dc _p[31]
#define Dc_columnindex 31
#define ina _p[32]
#define ina_columnindex 32
#define ik _p[33]
#define ik_columnindex 33
#define ikm _p[34]
#define ikm_columnindex 34
#define ica _p[35]
#define ica_columnindex 35
#define _g _p[36]
#define _g_columnindex 36
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
#define _ion_ek	*_ppvar[3]._pval
#define _ion_ik	*_ppvar[4]._pval
#define _ion_dikdv	*_ppvar[5]._pval
#define _ion_cai	*_ppvar[6]._pval
#define _ion_eca	*_ppvar[7]._pval
#define _ion_cao	*_ppvar[8]._pval
#define _ion_ica	*_ppvar[9]._pval
#define _ion_dicadv	*_ppvar[10]._pval
 
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
 /* declaration of user functions */
 static void _hoc_evaluate_fct_ca(void);
 static void _hoc_evaluate_fct_nak(void);
 static void _hoc_states(void);
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
 "setdata_spike2", _hoc_setdata,
 "evaluate_fct_ca_spike2", _hoc_evaluate_fct_ca,
 "evaluate_fct_nak_spike2", _hoc_evaluate_fct_nak,
 "states_spike2", _hoc_states,
 0, 0
};
 /* declare global and static user variables */
#define ca50 ca50_spike2
 double ca50 = 0.001;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "ca50_spike2", "mM",
 "gnabar_spike2", "mho/cm2",
 "gkbar_spike2", "mho/cm2",
 "gcabar_spike2", "mho/cm2",
 "gkcbar_spike2", "mho/cm2",
 "idrk_spike2", "mA/cm2",
 "icak_spike2", "mA/cm2",
 0,0
};
 static double c0 = 0;
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "ca50_spike2", &ca50_spike2,
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"spike2",
 "gnabar_spike2",
 "gkbar_spike2",
 "gcabar_spike2",
 "gkcbar_spike2",
 0,
 "idrk_spike2",
 "icak_spike2",
 "m_inf_spike2",
 "h_inf_spike2",
 "n_inf_spike2",
 "c_inf_spike2",
 "tau_m_spike2",
 "tau_h_spike2",
 "tau_n_spike2",
 "tau_c_spike2",
 "m_exp_spike2",
 "h_exp_spike2",
 "n_exp_spike2",
 "c_exp_spike2",
 "gkc_spike2",
 0,
 "m_spike2",
 "h_spike2",
 "n_spike2",
 "c_spike2",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 37, _prop);
 	/*initialize range parameters*/
 	gnabar = 0.08;
 	gkbar = 0.05;
 	gcabar = 0.0012;
 	gkcbar = 5e-05;
 	_prop->param = _p;
 	_prop->param_size = 37;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 11, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[3]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[4]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[5]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 1);
 	_ppvar[6]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[7]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[8]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[9]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[10]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _spike2_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	ion_reg("ca", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 37, 11);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 10, "ca_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 spike2 /Users/kitano/Desktop/retina/mod/spike2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "HH style channels for spiking retinal ganglion cells";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct_ca(double);
static int evaluate_fct_nak(double);
static int states();
 
static int  states (  ) {
   double _lsigmas ;
 evaluate_fct_nak ( _threadargscomma_ v ) ;
   evaluate_fct_ca ( _threadargscomma_ v ) ;
   m = m + m_exp * ( m_inf - m ) ;
   h = h + h_exp * ( h_inf - h ) ;
   n = n + n_exp * ( n_inf - n ) ;
   c = c + c_exp * ( c_inf - c ) ;
   
/*VERBATIM*/
	return 0;
  return 0; }
 
static void _hoc_states(void) {
  double _r;
   _r = 1.;
 states (  );
 hoc_retpushx(_r);
}
 
static int  evaluate_fct_ca (  double _lv ) {
   double _la , _lb ;
 _la = ( - 1.362 * ( _lv + 13.0 ) ) / ( exp ( - 0.1 * ( _lv + 13.0 ) ) - 1.0 ) ;
   _lb = 45.41 * exp ( - 1.0 * ( _lv + 38.0 ) / 18.0 ) ;
   tau_c = 1.0 / ( _la + _lb ) ;
   c_inf = _la * tau_c ;
   c_exp = 1.0 - exp ( - dt / tau_c ) ;
    return 0; }
 
static void _hoc_evaluate_fct_ca(void) {
  double _r;
   _r = 1.;
 evaluate_fct_ca (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int  evaluate_fct_nak (  double _lv ) {
   double _la , _lb ;
 _la = ( - 2.725 * ( _lv + 35.0 ) ) / ( exp ( - 0.1 * ( _lv + 35.0 ) ) - 1.0 ) ;
   _lb = 90.83 * exp ( - 1.0 * ( _lv + 60.0 ) / 18.0 ) ;
   tau_m = 1.0 / ( _la + _lb ) ;
   m_inf = _la * tau_m ;
   m_exp = 1.0 - exp ( - dt / tau_m ) ;
   _la = 1.817 * exp ( - 1.0 * ( _lv + 52.0 ) / 20.0 ) ;
   _lb = 27.25 / ( 1.0 + exp ( - 0.1 * ( _lv + 22.0 ) ) ) ;
   tau_h = 1.0 / ( _la + _lb ) ;
   h_inf = _la * tau_h ;
   h_exp = 1.0 - exp ( - dt / tau_h ) ;
   _la = ( - 0.09575 * ( _lv + 37.0 ) ) / ( exp ( - 0.1 * ( _lv + 37.0 ) ) - 1.0 ) ;
   _lb = 1.915 * exp ( - 1.0 * ( _lv + 47.0 ) / 80.0 ) ;
   tau_n = 1.0 / ( _la + _lb ) ;
   n_inf = _la * tau_n ;
   n_exp = 1.0 - exp ( - dt / tau_n ) ;
    return 0; }
 
static void _hoc_evaluate_fct_nak(void) {
  double _r;
   _r = 1.;
 evaluate_fct_nak (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("spike2", "cannot be used with CVODE"); return 0;}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 3, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 5, 4);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 6, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 7, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 8, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 9, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 10, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  c = c0;
  h = h0;
  m = m0;
  n = n0;
 {
   m = 0.0345 ;
   h = 0.8594 ;
   n = 0.1213 ;
   c = 0.0038 ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 initmodel();
   }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ina = gnabar * m * m * m * h * ( v - ena ) ;
   idrk = gkbar * n * n * n * n * ( v - ek ) ;
   gkc = ( cai * cai ) / ( ca50 * ca50 + cai * cai ) ;
   icak = gkcbar * gkc * ( v - ek ) ;
   ik = idrk + icak ;
   ica = gcabar * c * c * c * ( v - eca ) ;
   }
 _current += ina;
 _current += ik;
 _current += ica;

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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 _g = _nrn_current(_v + .001);
 	{ double _dica;
 double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
  _dica = ica;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
  _ion_ica += ica ;
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
  ena = _ion_ena;
  ek = _ion_ek;
  cai = _ion_cai;
  eca = _ion_eca;
  cao = _ion_cao;
 { error =  states();
 if(error){fprintf(stderr,"at line 81 in file spike2.mod:\n	SOLVE states\n"); nrn_complain(_p); abort_run(error);}
 }   }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/kitano/Desktop/retina/mod/spike2.mod";
static const char* nmodl_file_text = 
  "TITLE HH style channels for spiking retinal ganglion cells\n"
  ":\n"
  ": Modified from Fohlmeister et al, 1990, Brain Res 510, 343-345\n"
  ": by TJ Velte March 17, 1995\n"
  ": must be used with calcium pump mechanism, i.e. capump.mod\n"
  ":\n"
  ":\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX spike2\n"
  "	USEION na READ ena WRITE ina\n"
  "	USEION k READ ek WRITE ik\n"
  "	USEION ca READ cai, eca, cao WRITE ica\n"
  "	RANGE gnabar, gkbar, gcabar, gkcbar, gkc\n"
  "	RANGE m_inf, h_inf, n_inf, c_inf\n"
  "	RANGE tau_m, tau_h, tau_n, tau_c\n"
  "	RANGE m_exp, h_exp, n_exp, c_exp\n"
  "	RANGE idrk, icak\n"
  "	GLOBAL ca50\n"
  "}\n"
  "\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gnabar	= 0.08	(mho/cm2)\n"
  "	gkbar	= 0.05 (mho/cm2)\n"
  "	gcabar	= 0.0012	(mho/cm2)\n"
  "	gkcbar	= 0.00005 (mho/cm2)\n"
  "	ena	= 65	(mV)\n"
  "	ek	= -100	(mV)\n"
  "	eca		(mV)\n"
  "	cao	= 1.8	(mM)\n"
  "	cai     = 0.0001 (mM)\n"
  "	dt              (ms)\n"
  "	v               (mV)\n"
  "	ca50    = 0.001	(mM)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m h n c\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  ": The initial values were determined at a resting value of -66.3232 mV in a single-compartment\n"
  ":	m = 0.0155\n"
  ":	h = 0.9399\n"
  ":	n = 0.0768\n"
  ":	p = 0.0398\n"
  ":	q = 0.4526\n"
  ":	c = 0.0016\n"
  ": at -60 mV\n"
  "        m = 0.0345\n"
  "        h = 0.8594\n"
  "        n = 0.1213\n"
  "        c = 0.0038\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ina	(mA/cm2)\n"
  "	ik	(mA/cm2)\n"
  "         idrk    (mA/cm2)\n"
  "         icak    (mA/cm2)\n"
  "		 ikm	 (mA/cm2)\n"
  "	ica	(mA/cm2)\n"
  "	m_inf h_inf n_inf c_inf\n"
  "	tau_m tau_h tau_n tau_c\n"
  "	m_exp h_exp n_exp c_exp\n"
  "	gkc\n"
  "\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states\n"
  "	ina = gnabar * m*m*m*h * (v - ena)\n"
  "	idrk = gkbar * n*n*n*n * (v - ek)\n"
  ":	gkc=((cai / ca50)/ (1 + (cai / ca50)))\n"
  "	gkc=(cai*cai)/ (ca50*ca50 + cai*cai)\n"
  "	icak = gkcbar * gkc * (v - ek)\n"
  "	ik = idrk + icak\n"
  "	ica = gcabar * c*c*c * (v - eca)\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE states() {	: exact when v held constant\n"
  "	LOCAL sigmas\n"
  "	evaluate_fct_nak(v)\n"
  "	evaluate_fct_ca(v)\n"
  "	m = m + m_exp * (m_inf - m)\n"
  "	h = h + h_exp * (h_inf - h)\n"
  "	n = n + n_exp * (n_inf - n)\n"
  "	c = c + c_exp * (c_inf - c)\n"
  "\n"
  "	VERBATIM\n"
  "	return 0;\n"
  "	ENDVERBATIM\n"
  "\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "PROCEDURE evaluate_fct_ca(v(mV)) { LOCAL a,b\n"
  ":CA channel\n"
  "	a = (-1.362 * (v+13)) / (exp(-0.1*(v+13)) - 1)\n"
  "	b = 45.41 * exp(-1*(v + 38)/18)\n"
  "	tau_c = 1 / (a + b)\n"
  "	c_inf = a * tau_c\n"
  "	c_exp = 1 - exp(-dt/tau_c)	\n"
  "\n"
  "}\n"
  "PROCEDURE evaluate_fct_nak(v(mV)) { LOCAL a,b\n"
  "	\n"
  ":NA m\n"
  "	a = (-2.725 * (v+35)) / (exp(-0.1*(v+35)) - 1)\n"
  "	b = 90.83 * exp(-1*(v+60)/18)\n"
  "	tau_m = 1 / (a + b)\n"
  "	m_inf = a * tau_m\n"
  "	m_exp = 1 - exp(-dt/tau_m)\n"
  "\n"
  ":NA h\n"
  "	a = 1.817 * exp(-1*(v+52)/20)\n"
  "	b = 27.25 / ( 1 + exp(-0.1 *(v+22)))\n"
  "	tau_h = 1 / (a + b)\n"
  "	h_inf = a * tau_h\n"
  "	h_exp = 1 - exp(-dt/tau_h)\n"
  "\n"
  ":K n (non-inactivating, delayed rectifier)\n"
  "	a = (-0.09575 * (v+37)) / (exp(-0.1*(v+37)) - 1)\n"
  "	b = 1.915 * exp(-1*(v + 47)/80)\n"
  "	tau_n = 1 / (a + b)\n"
  "	n_inf = a * tau_n\n"
  "	n_exp = 1 - exp(-dt/tau_n)\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  ;
#endif
