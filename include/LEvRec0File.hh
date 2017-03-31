#ifndef __LEVREC0FILE__
#define __LEVREC0FILE__ 1

#include "LEvRec0.hh"

#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLeaf.h"


class LEvRec0File {
public:
   LEvRec0File(const char *inpFile);
   int SetTheEventPointer(LEvRec0 &ev);
   int SetTmdPointer(LEvRec0Md &metaData);

   // bool GetEntry(int iEntry, LEvRec0 &event); // for future... NO ROOT!
   int GetEntry(int iEntry);
   int GetTmdEntry(int iEntry);
   int GetEntries();
   int GetTmdEntries();

   
   void Close();
   inline bool IsOpen() {return inputCalib->IsOpen();}
   inline int GetRunID(int iEntry){return RunId[iEntry];}; 
   int RunIDtoEntry(unsigned short runid);
      
   ~LEvRec0File();
  
private:
   TFile *inputCalib;
   TTree *treeCalib;
   TTree *Tmd;
   //unsigned short RunId;
   unsigned short *RunId;


   
};


#endif
