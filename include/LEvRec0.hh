#include "detector_const.hh"
#include "analysis_const.hh"

#ifndef __LEVREC0__
#define __LEVREC0__ 1

class LEvRec0 {

public:
  LEvRec0();
  
  short            strip[NCHAN];
  unsigned int     trigger_index;
  unsigned int     hepd_time;
  unsigned int     event_index;
  unsigned short   event_length;
  unsigned short   pmt_high[NPMT];
  unsigned short   pmt_low[NPMT];
  unsigned short   rate_meter[NRATEMETER];
  bool             trigger_flag[NPMT];
  unsigned int     alive_time;
  unsigned int     dead_time;

  void DumpStrip(void);
  void DumpEventIndex();
};


class LEvRec0Md {

public:
  LEvRec0Md();
   
   unsigned short     boot_nr;
   unsigned short     run_id;
   unsigned short     run_type;
   unsigned short     run_duration;
   unsigned short     orbit_Zone;
   unsigned char      ladder_on;
   unsigned char      ladder_mask; 
   unsigned short     plane_HV[2];
   unsigned short     adj_strip;
   unsigned short     zero_supp_thrd; 
   unsigned char      thrd_CN_HIGH;
   unsigned char      thrd_CN_LOW;
   unsigned short     calib_event_CN;
   unsigned short     calib_event_ped;
   unsigned short     calib_event_RMS;
   unsigned short     calib_event_gauss;
   unsigned short     gauss_check;
   unsigned char      trigger_mask[4];
   unsigned char      easiroc_config[120];
   bool               PMT_mask[64]; 
   bool               HV_mask[12]; 
   unsigned short     HV_value[10]; 
   unsigned char      gen_trig_mask[4];
   
};


#endif
