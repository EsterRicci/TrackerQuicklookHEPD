#include "LEvRec0File.hh"


LEvRec0File::LEvRec0File(const char *inpFile) {
  inputCalib=TFile::Open(inpFile, "READ");
  //calibration run processing...
  treeCalib=(TTree*)inputCalib->Get("T");
  Tmd = (TTree*)inputCalib->Get("Tmd");
  //unsigned short run_id, boot_nr;
  // Tmd->SetBranchAddress("run_id", &run_id);
  // Tmd->SetBranchAddress("boot_nr", &boot_nr);
  // Tmd->GetEntry(0);
  // bootNr = static_cast<int>(boot_nr);
  // RunId = static_cast<int>(run_id);
}


int LEvRec0File::SetTheEventPointer(LEvRec0 &ev) {
  treeCalib->SetBranchAddress("strip[4608]",&ev.strip);
  treeCalib->SetBranchAddress("trigger_index", &ev.trigger_index);
  treeCalib->SetBranchAddress("hepd_time", &ev.hepd_time);
  treeCalib->SetBranchAddress("event_index", &ev.event_index);
  treeCalib->SetBranchAddress("event_length", &ev.event_length);
  treeCalib->SetBranchAddress("pmt_high[64]", &ev.pmt_high);
  treeCalib->SetBranchAddress("pmt_low[64]", &ev.pmt_low);
  treeCalib->SetBranchAddress("rate_meter[9]", &ev.rate_meter);
  treeCalib->SetBranchAddress("trigger_flag[64]", &ev.trigger_flag);
  treeCalib->SetBranchAddress("alive_time", &ev.alive_time);
  treeCalib->SetBranchAddress("dead_time", &ev.dead_time);

  treeCalib->SetBranchStatus("*",kFALSE);
  treeCalib->SetBranchStatus("strip[4608]",kTRUE);
  treeCalib->SetBranchStatus("event_index",kTRUE);

  return 0;
}

int LEvRec0File::SetTmdPointer(LEvRec0Md &metaData) {
   Tmd->SetBranchAddress("boot_nr", &metaData.boot_nr);
   Tmd->SetBranchAddress("run_id", &metaData.run_id);
   Tmd->SetBranchAddress("run_type", &metaData.run_type);
   Tmd->SetBranchAddress("run_duration", &metaData.run_duration);
   Tmd->SetBranchAddress("orbitZone", &metaData.orbit_Zone);
   Tmd->SetBranchAddress("ladderOn", &metaData.ladder_on);
   Tmd->SetBranchAddress("ladderMask", &metaData.ladder_mask);
   Tmd->SetBranchAddress("plane_HV[2]", &metaData.plane_HV[0]);
   Tmd->SetBranchAddress("adj_strip", &metaData.adj_strip);
   Tmd->SetBranchAddress("zero_supp_thrd", &metaData.zero_supp_thrd);
   Tmd->SetBranchAddress("thrd_CN_HIGH", &metaData.thrd_CN_HIGH);
   Tmd->SetBranchAddress("thrd_CN_LOW", &metaData.thrd_CN_LOW);
   Tmd->SetBranchAddress("gauss_check", &metaData.gauss_check);
   Tmd->SetBranchAddress("trigger_mask[2]", &metaData.trigger_mask[2]);
   Tmd->SetBranchAddress("calib_event_CN", &metaData.calib_event_CN);
   Tmd->SetBranchAddress("calib_event_ped", &metaData.calib_event_ped);
   Tmd->SetBranchAddress("calib_event_RMS", &metaData.calib_event_RMS);
   Tmd->SetBranchAddress("calib_event_gauss", &metaData.calib_event_gauss);
   Tmd->SetBranchAddress("easiroc[118]", &metaData.easiroc_config[0]);
   Tmd->SetBranchAddress("PMT_mask[64]", &metaData.PMT_mask[0]);
   Tmd->SetBranchAddress("HV_mask[12]", &metaData.HV_mask[12]);
   Tmd->SetBranchAddress("HV_value[10]", &metaData.HV_value[0]);
   Tmd->SetBranchAddress("gen_trig_mask[4]", &metaData.gen_trig_mask[0]);

   Tmd->SetBranchStatus("*",kFALSE);
   Tmd->SetBranchStatus("boot_nr", &metaData.boot_nr);
   Tmd->SetBranchStatus("run_id", &metaData.run_id);

   return 0;
}


int LEvRec0File::GetEntry(int iEntry) {
  treeCalib->GetEntry(iEntry);
  Tmd->GetEntry(iEntry);
  return 0;
}

int LEvRec0File::GetEntries() {
  return treeCalib->GetEntries();
}


int LEvRec0File::GetTmdEntries() {
  return Tmd->GetEntries();
}

void LEvRec0File::Close() {
  if(inputCalib) {
    treeCalib = 0;
    Tmd = 0;
    inputCalib->Close();
    inputCalib = 0;
  }
  return;
}

LEvRec0File::~LEvRec0File() {
  if(inputCalib) {
     treeCalib = 0;
     Tmd = 0;
    inputCalib->Close();
  }
}
