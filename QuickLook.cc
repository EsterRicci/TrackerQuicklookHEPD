#include <iostream>
#include "LTrackerQuicklook.hh"
#include <stdlib.h>
#include <TSystem.h>

int main(int argc,char *argv[]){

   TSystem namefile;
   
   if (argc==2)
      QuickLook(argv[1]);
  else {
    std::cout<<"Please type: "<<std::endl<<
      "./QuickLook <data_file_path>"<<std::endl;
  }
  return 0; 
}
