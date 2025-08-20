#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _A2hh_A_reg(void);
extern void _A2hh_k_reg(void);
extern void _A2hh_na_reg(void);
extern void _Bip_Ca_reg(void);
extern void _Bip_Cad_reg(void);
extern void _Bip_ih_reg(void);
extern void _Bip_Ka_reg(void);
extern void _Bip_Kca_reg(void);
extern void _Bip_Kv_reg(void);
extern void _CaT_reg(void);
extern void _depsyn_reg(void);
extern void _gap_reg(void);
extern void _HCN_reg(void);
extern void _Ifluct_reg(void);
extern void _IinjLT_offcbc_reg(void);
extern void _IinjLT_oncbc_reg(void);
extern void _IinjLT_rbc_reg(void);
extern void _ribbon_syn_reg(void);
extern void _spike_reg(void);
extern void _spike2_reg(void);
extern void _syn_bip_gan_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \".//A2hh_A.mod\"");
    fprintf(stderr, " \".//A2hh_k.mod\"");
    fprintf(stderr, " \".//A2hh_na.mod\"");
    fprintf(stderr, " \".//Bip_Ca.mod\"");
    fprintf(stderr, " \".//Bip_Cad.mod\"");
    fprintf(stderr, " \".//Bip_ih.mod\"");
    fprintf(stderr, " \".//Bip_Ka.mod\"");
    fprintf(stderr, " \".//Bip_Kca.mod\"");
    fprintf(stderr, " \".//Bip_Kv.mod\"");
    fprintf(stderr, " \".//CaT.mod\"");
    fprintf(stderr, " \".//depsyn.mod\"");
    fprintf(stderr, " \".//gap.mod\"");
    fprintf(stderr, " \".//HCN.mod\"");
    fprintf(stderr, " \".//Ifluct.mod\"");
    fprintf(stderr, " \".//IinjLT_offcbc.mod\"");
    fprintf(stderr, " \".//IinjLT_oncbc.mod\"");
    fprintf(stderr, " \".//IinjLT_rbc.mod\"");
    fprintf(stderr, " \".//ribbon_syn.mod\"");
    fprintf(stderr, " \".//spike.mod\"");
    fprintf(stderr, " \".//spike2.mod\"");
    fprintf(stderr, " \".//syn_bip_gan.mod\"");
    fprintf(stderr, "\n");
  }
  _A2hh_A_reg();
  _A2hh_k_reg();
  _A2hh_na_reg();
  _Bip_Ca_reg();
  _Bip_Cad_reg();
  _Bip_ih_reg();
  _Bip_Ka_reg();
  _Bip_Kca_reg();
  _Bip_Kv_reg();
  _CaT_reg();
  _depsyn_reg();
  _gap_reg();
  _HCN_reg();
  _Ifluct_reg();
  _IinjLT_offcbc_reg();
  _IinjLT_oncbc_reg();
  _IinjLT_rbc_reg();
  _ribbon_syn_reg();
  _spike_reg();
  _spike2_reg();
  _syn_bip_gan_reg();
}

#if defined(__cplusplus)
}
#endif
