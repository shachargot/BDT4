#if!defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>                  // access to gROOT, entry point to ROOT system
#include <TSystem.h>                // interface to OS
#include <TFile.h>                  // file handle class
#include <TTree.h>                  // class to access ntuples
#include <TClonesArray.h>           // ROOT array class
#include <TBenchmark.h>             // class to track macro running statistics
#include <TVector2.h>               // 2D vector class
#include <TVector3.h>               // 2D vector class
#include <Math/Vector3D.h>
#include <TMath.h>                  // ROOT math library
#include <vector>                   // STL vector class
#include <utility>
#include <iostream>                 // standard I/O
#include <iomanip>                  // functions to format standard I/O
#include <fstream>                  // functions forfile I/O
#include <bitset>
#include "TLorentzVector.h"         // 4-vector class
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TF1.h>
#include <TStopwatch.h>
#include <TMatrixD.h>
#include <TArrayD.h>
#include <TMatrixDEigen.h>
#include <TVectorD.h>
#include "TH1D.h"
#include "TH2F.h"
#include "TRandom3.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include "TMath.h"
#include "ROOT/RDataFrame.hxx"
// C++ tool
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <xgboost/c_api.h> 
#include <cassert>
#endif

void FillHistogram(TH1F* hist1_1, TH1F* hist1_2, TH1F* hist1_3, TH1F* hist1_4, TH1F* hist1_5, TH1F* hist1_6, TH1F* hist1_7, TH1F* hist1_8, TH1F* hist1_9, TH1F* hist1_10,
										TH1F* hist1_11, TH1F* hist1_12, TH1F* hist1_13, TH1F* hist1_14, TH1F* hist1_15, TH1F* hist1_16, TH1F* hist1_17, TH1F* hist1_18, TH1F* hist1_19, TH1F* hist1_20,
										TH1F* hist1_21, TH1F* hist1_22, TH1F* hist1_23, TH1F* hist1_24, TH1F* hist1_25, TH1F* hist1_26, TH1F* hist1_27, TH1F* hist1_28, TH1F* hist1_29, TH1F* hist1_30,
										TH1F* hist1_31, TH1F* hist1_32, TH1F* hist1_33, TH1F* hist1_34, TH1F* hist1_35, TH1F* hist1_36, TH1F* hist1_37, TH1F* hist1_38, TH1F* hist1_39, TH1F* hist1_40,
										TH1F* hist1_41, TH1F* hist1_42, TH1F* hist1_43, TH1F* hist1_44, TH1F* hist1_45, TH1F* hist1_46, TH1F* hist1_47, TH1F* hist1_48, TH1F* hist1_49, TH1F* hist1_50, TH1F* hist1_51, TH1F* hist1_52, TH1F* hist1_53, TH2F* hist2d_1_1,
										TString filename,
										int mode, int ifile, std::string outpath, std::string name) {
											
		// Open GBDT file
		BoosterHandle h_booster;
    DMatrixHandle h_test;
		XGBoosterCreate(NULL, 0, &h_booster);
		XGBoosterLoadModel(h_booster, "models/model_trk0p5_eta1p4_cos0p8_SRm5-5p4_CV6_BayesianOptimization_33var_fold_0.bin");
    // Open the ROOT file
    TFile* file = TFile::Open(filename);
    if(!file || file->IsZombie()) {
        // Handle file open error
        return;
    }

    // Get the TTree containing the data (replace "Events" with your tree name)
    TTree* tree = dynamic_cast<TTree*>(file->Get("Events"));
    if(!tree) {
        // Handle tree retrieval error
        file->Close();
        return;
    }
		std::string path = outpath;
		if (outpath.back() != '/') {
			path += '/';
		}
		TString outname = path + name + "_" + std::to_string(ifile) + ".root";
		std::cout << "outname: " << outname << std::endl;
		TFile* outputFile = new TFile(outname,"RECREATE");
		
		TTree* outputTree = tree->CloneTree(0);

		Float_t output_BCand_quad_BDT = 0;
		Float_t quad_BDT_scores[1000];
		Int_t b_nBToKEE;
		
		outputTree->Branch("nBToKEE", &b_nBToKEE, "nBToKEE/I");
		TBranch* branch = outputTree->Branch("BToKEE_quad_BDT", quad_BDT_scores, "BToKEE_quad_BDT[nBToKEE]/F");

		TTreeReader reader(tree);
		
                TTreeReaderValue<UInt_t> run(reader, "run");
		TTreeReaderValue<UInt_t> luminosityBlock(reader, "luminosityBlock");
		TTreeReaderValue<ULong64_t> event(reader, "event");
		TTreeReaderValue<UInt_t> bunchCrossing(reader, "bunchCrossing");
		TTreeReaderValue<Int_t> nBToKEE(reader, "nBToKEE");
		TTreeReaderArray<Float_t> BToKEE_mass(reader, "BToKEE_mass");
		TTreeReaderArray<Float_t> BToKEE_fit_mass(reader, "BToKEE_fit_mass");
		TTreeReaderArray<Float_t> BToKEE_fit_massErr(reader, "BToKEE_fit_massErr");
		TTreeReaderArray<Float_t> BToKEE_fit_pt(reader, "BToKEE_fit_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_eta(reader, "BToKEE_fit_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_phi(reader, "BToKEE_fit_phi");
		TTreeReaderArray<Float_t> BToKEE_fit_k_pt(reader, "BToKEE_fit_k_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_k_eta(reader, "BToKEE_fit_k_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_k_phi(reader, "BToKEE_fit_k_phi");
		TTreeReaderArray<Float_t> BToKEE_fit_cos2D(reader, "BToKEE_fit_cos2D");
		TTreeReaderArray<Float_t> BToKEE_svprob(reader, "BToKEE_svprob");
		TTreeReaderArray<Float_t> BToKEE_vtx_x(reader, "BToKEE_vtx_x");
		TTreeReaderArray<Float_t> BToKEE_vtx_y(reader, "BToKEE_vtx_y");
		TTreeReaderArray<Float_t> BToKEE_vtx_z(reader, "BToKEE_vtx_z");
		TTreeReaderArray<Float_t> BToKEE_l_xy(reader, "BToKEE_l_xy");
		TTreeReaderArray<Float_t> BToKEE_l_xy_unc(reader, "BToKEE_l_xy_unc");
    		TTreeReaderArray<Float_t> BToKEE_mll_raw(reader, "BToKEE_mll_raw");
		TTreeReaderArray<Float_t> BToKEE_mll_charge(reader, "BToKEE_mll_charge");
		TTreeReaderArray<Float_t> BToKEE_mll_fullfit(reader, "BToKEE_mll_fullfit");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_pt(reader, "BToKEE_fit_l1_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_eta(reader, "BToKEE_fit_l1_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_phi(reader, "BToKEE_fit_l1_phi");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_pt(reader, "BToKEE_fit_l2_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_eta(reader, "BToKEE_fit_l2_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_phi(reader, "BToKEE_fit_l2_phi");
    		TTreeReaderArray<Int_t>   BToKEE_l1Idx(reader, "BToKEE_l1Idx");
	    	TTreeReaderArray<Int_t>   BToKEE_l2Idx(reader, "BToKEE_l2Idx");
		TTreeReaderArray<Int_t>   BToKEE_kIdx(reader, "BToKEE_kIdx");
		TTreeReaderArray<Float_t> BToKEE_k_svip3d(reader, "BToKEE_k_svip3d");
		TTreeReaderArray<Float_t> BToKEE_k_svip3d_err(reader, "BToKEE_k_svip3d_err");
		TTreeReaderArray<Float_t> BToKEE_l1_iso04(reader, "BToKEE_l1_iso04");
		TTreeReaderArray<Float_t> BToKEE_l2_iso04(reader, "BToKEE_l2_iso04");
		TTreeReaderArray<Float_t> BToKEE_k_iso04(reader, "BToKEE_k_iso04");
		TTreeReaderArray<Float_t> BToKEE_b_iso04(reader, "BToKEE_b_iso04");
		
		TTreeReaderValue<Int_t> nBToKsEE(reader, "nBToKsEE");
		TTreeReaderArray<Float_t> BToKsEE_mass(reader, "BToKsEE_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_mass(reader, "BToKsEE_fit_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_pt(reader, "BToKsEE_fit_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_eta(reader, "BToKsEE_fit_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_phi(reader, "BToKsEE_fit_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_pt(reader, "BToKsEE_fit_l1_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_eta(reader, "BToKsEE_fit_l1_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_phi(reader, "BToKsEE_fit_l1_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_pt(reader, "BToKsEE_fit_l2_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_eta(reader, "BToKsEE_fit_l2_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_phi(reader, "BToKsEE_fit_l2_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_pt(reader, "BToKsEE_fit_trk1_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_eta(reader, "BToKsEE_fit_trk1_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_phi(reader, "BToKsEE_fit_trk1_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_pt(reader, "BToKsEE_fit_trk2_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_eta(reader, "BToKsEE_fit_trk2_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_phi(reader, "BToKsEE_fit_trk2_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_eta(reader, "BToKsEE_fit_kstar_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_mass(reader, "BToKsEE_fit_kstar_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_phi(reader, "BToKsEE_fit_kstar_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_pt(reader, "BToKsEE_fit_kstar_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_cos2D(reader, "BToKsEE_fit_cos2D");
		TTreeReaderArray<Float_t> BToKsEE_svprob(reader, "BToKsEE_svprob");
		TTreeReaderArray<Float_t> BToKsEE_vtx_x(reader, "BToKsEE_vtx_x");
		TTreeReaderArray<Float_t> BToKsEE_vtx_y(reader, "BToKsEE_vtx_y");
		TTreeReaderArray<Float_t> BToKsEE_vtx_z(reader, "BToKsEE_vtx_z");
		TTreeReaderArray<Float_t> BToKsEE_l_xy(reader, "BToKsEE_l_xy");
		TTreeReaderArray<Float_t> BToKsEE_l_xy_unc(reader, "BToKsEE_l_xy_unc");
	    	TTreeReaderArray<Float_t> BToKsEE_mll_raw(reader, "BToKsEE_mll_raw");
		TTreeReaderArray<Float_t> BToKsEE_mll_charge(reader, "BToKsEE_mll_charge");
		TTreeReaderArray<Float_t> BToKsEE_mll_fullfit(reader, "BToKsEE_mll_fullfit");
    		TTreeReaderArray<Int_t>   BToKsEE_l1_idx(reader, "BToKsEE_l1_idx");
    		TTreeReaderArray<Int_t>   BToKsEE_l2_idx(reader, "BToKsEE_l2_idx");
		TTreeReaderArray<Int_t>   BToKsEE_trk1_idx(reader, "BToKsEE_trk1_idx");
		TTreeReaderArray<Int_t>   BToKsEE_trk2_idx(reader, "BToKsEE_trk2_idx");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip2d(reader, "BToKsEE_trk1_svip2d");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip2d_err(reader, "BToKsEE_trk1_svip2d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip3d(reader, "BToKsEE_trk1_svip3d");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip3d_err(reader, "BToKsEE_trk1_svip3d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip2d(reader, "BToKsEE_trk2_svip2d");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip2d_err(reader, "BToKsEE_trk2_svip2d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip3d(reader, "BToKsEE_trk2_svip3d");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip3d_err(reader, "BToKsEE_trk2_svip3d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk1_iso04(reader, "BToKsEE_trk1_iso04");
		TTreeReaderArray<Float_t> BToKsEE_trk2_iso04(reader, "BToKsEE_trk2_iso04");
		TTreeReaderArray<Float_t> BToKsEE_l1_iso04(reader, "BToKsEE_l1_iso04");
		TTreeReaderArray<Float_t> BToKsEE_l2_iso04(reader, "BToKsEE_l2_iso04");
		
		TTreeReaderValue<Int_t>   nElectron(reader, "nElectron");
		TTreeReaderArray<Int_t>   Electron_charge(reader, "Electron_charge");
		TTreeReaderArray<Float_t> Electron_pt(reader, "Electron_pt");
		TTreeReaderArray<Float_t> Electron_eta(reader, "Electron_eta");
		TTreeReaderArray<Float_t> Electron_phi(reader, "Electron_phi");
    		TTreeReaderArray<Bool_t>  Electron_isPF(reader, "Electron_isPF");
		TTreeReaderArray<Bool_t>  Electron_isPFoverlap(reader, "Electron_isPFoverlap");
		TTreeReaderArray<Bool_t>  Electron_convVeto(reader, "Electron_convVeto");
		TTreeReaderArray<Bool_t>  Electron_PFEleMvaID_Fall17NoIsoV2wpLoose(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wpLoose");
    		TTreeReaderArray<Bool_t>  Electron_PFEleMvaID_Fall17NoIsoV2wp80(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wp80");
		TTreeReaderArray<Bool_t>  Electron_PFEleMvaID_Fall17NoIsoV2wp90(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wp90");
		TTreeReaderArray<Float_t> Electron_PFEleMvaID_Fall17NoIsoV2RawValue(reader, "Electron_PFEleMvaID_Fall17NoIsoV2RawValue");
		TTreeReaderArray<Float_t> Electron_PFEleMvaID_RetrainedRawValue(reader, "Electron_PFEleMvaID_RetrainedRawValue");
		TTreeReaderArray<Float_t> Electron_vz(reader, "Electron_vz");
		
		TTreeReaderValue<Int_t>   nProbeTracks(reader, "nProbeTracks");
		TTreeReaderArray<Float_t> ProbeTracks_pt(reader, "ProbeTracks_pt");
		TTreeReaderArray<Float_t> ProbeTracks_eta(reader, "ProbeTracks_eta");
		TTreeReaderArray<Float_t> ProbeTracks_phi(reader, "ProbeTracks_phi");
		TTreeReaderArray<Float_t> ProbeTracks_vz(reader, "ProbeTracks_vz");
		
		TTreeReaderArray<Float_t> PV_x(reader, "PV_x");
		TTreeReaderArray<Float_t> PV_y(reader, "PV_y");
		TTreeReaderArray<Float_t> PV_z(reader, "PV_z");

		TTreeReaderValue<Int_t> nSV(reader, "nSV");
		TTreeReaderValue<Int_t> nTrigObj(reader, "nTrigObj");
		
		TTreeReaderValue<UChar_t> L1_DoubleEG11_er1p2_dR_Max0p6(reader, "L1_DoubleEG11_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG10p5_er1p2_dR_Max0p6(reader, "L1_DoubleEG10p5_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG10_er1p2_dR_Max0p6(reader, "L1_DoubleEG10_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG9p5_er1p2_dR_Max0p6(reader, "L1_DoubleEG9p5_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG9_er1p2_dR_Max0p7(reader, "L1_DoubleEG9_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG8p5_er1p2_dR_Max0p7(reader, "L1_DoubleEG8p5_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG8_er1p2_dR_Max0p7(reader, "L1_DoubleEG8_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG7p5_er1p2_dR_Max0p7(reader, "L1_DoubleEG7p5_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG7_er1p2_dR_Max0p8(reader, "L1_DoubleEG7_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG6p5_er1p2_dR_Max0p8(reader, "L1_DoubleEG6p5_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG6_er1p2_dR_Max0p8(reader, "L1_DoubleEG6_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG5p5_er1p2_dR_Max0p8(reader, "L1_DoubleEG5p5_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG5_er1p2_dR_Max0p9(reader, "L1_DoubleEG5_er1p2_dR_Max0p9");
		TTreeReaderValue<UChar_t> L1_DoubleEG4p5_er1p2_dR_Max0p9(reader, "L1_DoubleEG4p5_er1p2_dR_Max0p9");
		TTreeReaderValue<UChar_t> L1_DoubleEG4_er1p2_dR_Max0p9(reader, "L1_DoubleEG4_er1p2_dR_Max0p9");
		
		TTreeReaderValue<UChar_t> HLT_DoubleEle10_eta1p22_mMax6(reader, "HLT_DoubleEle10_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle9p5_eta1p22_mMax6(reader, "HLT_DoubleEle9p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle9_eta1p22_mMax6(reader, "HLT_DoubleEle9_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle8p5_eta1p22_mMax6(reader, "HLT_DoubleEle8p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle8_eta1p22_mMax6(reader, "HLT_DoubleEle8_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle7p5_eta1p22_mMax6(reader, "HLT_DoubleEle7p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle7_eta1p22_mMax6(reader, "HLT_DoubleEle7_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle6p5_eta1p22_mMax6(reader, "HLT_DoubleEle6p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle6_eta1p22_mMax6(reader, "HLT_DoubleEle6_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle5p5_eta1p22_mMax6(reader, "HLT_DoubleEle5p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle5_eta1p22_mMax6(reader, "HLT_DoubleEle5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle4p5_eta1p22_mMax6(reader, "HLT_DoubleEle4p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle4_eta1p22_mMax6(reader, "HLT_DoubleEle4_eta1p22_mMax6");
		
		
		TH1F* dR_l = new TH1F("dR_l", "dR_l", 500, 0, 0.5);
		TH1F* dR_K = new TH1F("dR_K", "dR_K", 500, 0, 0.5);
		int counter1=0, counter2=0, counter3=0, counter4=0, counter5=0, counter6=0, counter7=0, counter8=0, counter9=0, counter10=0, counter11=0, counter12=0;
    	// Loop through the entries
    	Long64_t numEntries = tree->GetEntries();
    	cout<<"Total: "<<numEntries<<endl;
    	for(Long64_t ievt = 0; ievt < numEntries; ++ievt) {
		// for(Long64_t ievt = 0; ievt < 100; ++ievt) {
		counter1++;
		reader.SetEntry(ievt);
        	if(ievt % 1000 == 0) {
        	    std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        	}

        	tree->GetEntry(ievt);
				
		b_nBToKEE = *nBToKEE;

		for(size_t iB = 0; iB < BToKEE_mass.GetSize(); ++iB) {
			counter3++;
			int l1_index = BToKEE_l1Idx[iB];
			int l2_index = BToKEE_l2Idx[iB];
			int k_index = BToKEE_kIdx[iB];
			counter4++;
			l1_index = BToKEE_l1Idx[iB];
			l2_index = BToKEE_l2Idx[iB];
			k_index = BToKEE_kIdx[iB];
			
			counter11++;
				
			std::vector<float> quad_BDT_list;
			bool isAssQuad = false;
			for(size_t iBKStaree = 0; iBKStaree < BToKsEE_mass.GetSize(); ++iBKStaree) {
		     				if((BToKsEE_l1_idx[iBKStaree] == l1_index && BToKsEE_l2_idx[iBKStaree] == l2_index && BToKsEE_trk1_idx[iBKStaree] == k_index) ||
		     					(BToKsEE_l1_idx[iBKStaree] == l1_index && BToKsEE_l2_idx[iBKStaree] == l2_index && BToKsEE_trk2_idx[iBKStaree] == k_index) ||
		     					(BToKsEE_l1_idx[iBKStaree] == l2_index && BToKsEE_l2_idx[iBKStaree] == l1_index && BToKsEE_trk1_idx[iBKStaree] == k_index) ||
		     					(BToKsEE_l1_idx[iBKStaree] == l2_index && BToKsEE_l2_idx[iBKStaree] == l1_index && BToKsEE_trk2_idx[iBKStaree] == k_index)) {
		     							// prepare eval dataset
		     							isAssQuad = true;
		     							std::vector<float> evalData;
		     							
		     							int l1_Ks_index = BToKsEE_l1_idx[iBKStaree];
		     							int l2_Ks_index = BToKsEE_l2_idx[iBKStaree];
		     							int trk1_Ks_index = BToKsEE_trk1_idx[iBKStaree];
		     							int trk2_Ks_index = BToKsEE_trk2_idx[iBKStaree];
		     							
		     							cout<<ievt<<" "<<iBKStaree<<" "<<BToKsEE_fit_mass[iBKStaree]<<" "<<l1_Ks_index<<" "<<l2_Ks_index<<" "<<trk1_Ks_index<<" "<<trk2_Ks_index<<endl;
		     							
		     							TLorentzVector Ksp4, B_Ks_p4, l1p4_Ks, l2p4_Ks, trk1_Ks_p4, trk2_Ks_p4;
		     							l1p4_Ks.SetPtEtaPhiM(BToKsEE_fit_l1_pt[iBKStaree], BToKsEE_fit_l1_eta[iBKStaree], BToKsEE_fit_l1_phi[iBKStaree], 0.000511);
		     							l2p4_Ks.SetPtEtaPhiM(BToKsEE_fit_l2_pt[iBKStaree], BToKsEE_fit_l2_eta[iBKStaree], BToKsEE_fit_l2_phi[iBKStaree], 0.000511);
		     							trk1_Ks_p4.SetPtEtaPhiM(BToKsEE_fit_trk1_pt[iBKStaree], BToKsEE_fit_trk1_eta[iBKStaree], BToKsEE_fit_trk1_phi[iBKStaree], 0.493677);
		     							trk2_Ks_p4.SetPtEtaPhiM(BToKsEE_fit_trk2_pt[iBKStaree], BToKsEE_fit_trk2_eta[iBKStaree], BToKsEE_fit_trk2_phi[iBKStaree], 0.493677);
		     							Ksp4.SetPtEtaPhiM(BToKsEE_fit_kstar_pt[iBKStaree], BToKsEE_fit_kstar_eta[iBKStaree], BToKsEE_fit_kstar_phi[iBKStaree], BToKsEE_fit_kstar_mass[iBKStaree]);
		     							B_Ks_p4.SetPtEtaPhiM(BToKsEE_fit_pt[iBKStaree],BToKsEE_fit_eta[iBKStaree],BToKsEE_fit_phi[iBKStaree],BToKsEE_fit_mass[iBKStaree]);
		     							TLorentzVector ll_Ksp4;
		     							ll_Ksp4 = l1p4_Ks + l2p4_Ks;
		     							ROOT::Math::XYZVector Bp3Vector(B_Ks_p4.Px(), B_Ks_p4.Py(), B_Ks_p4.Pz());
		     							ROOT::Math::XYZVector llp3Vector(ll_Ksp4.Px(),ll_Ksp4.Py(),ll_Ksp4.Pz());
		     							ROOT::Math::XYZVector trk1p3Vector(trk1_Ks_p4.Px(),trk1_Ks_p4.Py(),trk1_Ks_p4.Pz());
		     							ROOT::Math::XYZVector trk2p3Vector(trk2_Ks_p4.Px(),trk2_Ks_p4.Py(),trk2_Ks_p4.Pz());
		     							ROOT::Math::XYZVector Ksp3Vector(Ksp4.Px(),Ksp4.Py(),Ksp4.Pz());
		     							ROOT::Math::XYZVector BVtxVector(BToKsEE_vtx_x[iBKStaree] - PV_x[0], BToKsEE_vtx_y[iBKStaree] - PV_y[0], BToKsEE_vtx_z[iBKStaree] - PV_z[0]);
		     							ROOT::Math::XYZVector unitBVtxVector = BVtxVector / BVtxVector.R();
		     							
		     							float output_BCand_fit_l1_pt_norm = BToKsEE_fit_l1_pt[iBKStaree] / BToKsEE_fit_mass[iBKStaree];
		     							evalData.push_back(output_BCand_fit_l1_pt_norm);
		     							
		     							float output_BCand_fit_l2_pt_norm = BToKsEE_fit_l2_pt[iBKStaree] / BToKsEE_fit_mass[iBKStaree];
		     							evalData.push_back(output_BCand_fit_l2_pt_norm); 
		     							
		     							float output_BCand_fit_trk1_pt_norm = BToKsEE_fit_trk1_pt[iBKStaree] / BToKsEE_fit_mass[iBKStaree];
		     							evalData.push_back(output_BCand_fit_trk1_pt_norm); 
		     							
		     							float output_BCand_fit_trk2_pt_norm = BToKsEE_fit_trk2_pt[iBKStaree] / BToKsEE_fit_mass[iBKStaree];
		     							evalData.push_back(output_BCand_fit_trk2_pt_norm); 
		     							
		     							float output_BCand_fit_pt_norm = BToKsEE_fit_pt[iBKStaree] / BToKsEE_fit_mass[iBKStaree];
		     							evalData.push_back(output_BCand_fit_pt_norm); 
		     							
		     							float output_BCand_fit_cos2D = BToKsEE_fit_cos2D[iBKStaree];
		     							evalData.push_back(output_BCand_fit_cos2D); 
		     							
		     							float output_BCand_cosAlpha3D = BVtxVector.Dot(Bp3Vector) / (BVtxVector.R() * Bp3Vector.R());
		     							evalData.push_back(output_BCand_cosAlpha3D); 
		     							
		     							float output_BCand_svprob = BToKsEE_svprob[iBKStaree];
		     							evalData.push_back(output_BCand_svprob); 
		     							
		     							float output_BCand_sigLxy = BToKsEE_l_xy[iBKStaree] / BToKsEE_l_xy_unc[iBKStaree];
		     							evalData.push_back(output_BCand_sigLxy);
		     							
		     							float output_BCand_dR_ll = l1p4_Ks.DeltaR(l2p4_Ks);
		     							evalData.push_back(output_BCand_dR_ll);
		     							
		     							float output_BCand_MomenAsym_lltrk1 = ((llp3Vector.Cross(unitBVtxVector)).R() - (trk1p3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (trk1p3Vector.Cross(unitBVtxVector)).R());
		     							evalData.push_back(output_BCand_MomenAsym_lltrk1);
		     							
		     							float output_BCand_MomenAsym_lltrk2 = ((llp3Vector.Cross(unitBVtxVector)).R() - (trk2p3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (trk2p3Vector.Cross(unitBVtxVector)).R());
		     							evalData.push_back(output_BCand_MomenAsym_lltrk2);
		     							
		     							float output_BCand_MomenAsym_llKs = ((llp3Vector.Cross(unitBVtxVector)).R() - (Ksp3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (Ksp3Vector.Cross(unitBVtxVector)).R());
		     							evalData.push_back(output_BCand_MomenAsym_llKs);
		     							
		     							float output_BCand_iso04_l1_norm = BToKsEE_l1_iso04[iBKStaree] / BToKsEE_fit_l1_pt[iBKStaree];
		     							evalData.push_back(output_BCand_iso04_l1_norm);
		     							
		     							float output_BCand_iso04_l2_norm = BToKsEE_l2_iso04[iBKStaree] / BToKsEE_fit_l2_pt[iBKStaree];
		     							evalData.push_back(output_BCand_iso04_l2_norm); 
		     							
		     							float output_BCand_iso04_trk1_norm = BToKsEE_trk1_iso04[iBKStaree] / BToKsEE_fit_trk1_pt[iBKStaree];
		     							evalData.push_back(output_BCand_iso04_trk1_norm); 
		     							
		     							float output_BCand_iso04_trk2_norm = BToKsEE_trk2_iso04[iBKStaree] / BToKsEE_fit_trk2_pt[iBKStaree];
		     							evalData.push_back(output_BCand_iso04_trk2_norm); 
		     							
		     							float output_BCand_sigImpact_lltrk1 = BToKsEE_trk1_svip3d[iBKStaree]/BToKsEE_trk1_svip3d_err[iBKStaree];
		     							evalData.push_back(output_BCand_sigImpact_lltrk1); 
		     							
		     							float output_BCand_sigImpact_lltrk2 = BToKsEE_trk2_svip3d[iBKStaree]/BToKsEE_trk2_svip3d_err[iBKStaree];
		     							evalData.push_back(output_BCand_sigImpact_lltrk2);
		     							
		     							float output_BCand_dR_l1trk1 = l1p4_Ks.DeltaR(trk1_Ks_p4);
		     							evalData.push_back(output_BCand_dR_l1trk1);
		     							
		     							float output_BCand_dR_l1trk2 = l1p4_Ks.DeltaR(trk2_Ks_p4);
		     							evalData.push_back(output_BCand_dR_l1trk2);
		     							
		     							float output_BCand_dR_l2trk1 = l2p4_Ks.DeltaR(trk1_Ks_p4);
		     							evalData.push_back(output_BCand_dR_l2trk1);
		     							
		     							float output_BCand_dR_l2trk2 = l2p4_Ks.DeltaR(trk2_Ks_p4);
		     							evalData.push_back(output_BCand_dR_l2trk2);
		     							
		     							float output_BCand_dR_trk1trk2 = trk1_Ks_p4.DeltaR(trk2_Ks_p4);
		     							evalData.push_back(output_BCand_dR_trk1trk2);
		     							
		     							float output_BCand_dz_l1trk1 = Electron_vz[l1_Ks_index] - ProbeTracks_vz[trk1_Ks_index];
		     							evalData.push_back(output_BCand_dz_l1trk1);
		     							
		     							float output_BCand_dz_l1trk2 = Electron_vz[l1_Ks_index] - ProbeTracks_vz[trk2_Ks_index];
		     							evalData.push_back(output_BCand_dz_l1trk2);
		     							
		     							float output_BCand_dz_l2trk1 = Electron_vz[l2_Ks_index] - ProbeTracks_vz[trk1_Ks_index];
		     							evalData.push_back(output_BCand_dz_l2trk1);
		     							
		     							float output_BCand_dz_l2trk2 = Electron_vz[l2_Ks_index] - ProbeTracks_vz[trk2_Ks_index];
		     							evalData.push_back(output_BCand_dz_l2trk2);
		     							
		     							float output_BCand_dz_trk1trk2 = ProbeTracks_vz[trk1_Ks_index] - ProbeTracks_vz[trk2_Ks_index];
		     							evalData.push_back(output_BCand_dz_trk1trk2);
		     							
		     							float output_BCand_l1_ID = Electron_PFEleMvaID_RetrainedRawValue[l1_Ks_index];
		     							evalData.push_back(output_BCand_l1_ID);
		     							
		     							float output_BCand_l2_ID = Electron_PFEleMvaID_RetrainedRawValue[l2_Ks_index];
		     							evalData.push_back(output_BCand_l2_ID);
		     							
		     							float output_BCand_evt_nTri = *nBToKEE;
		     							evalData.push_back(output_BCand_evt_nTri);
		     							
		     							float output_BCand_evt_nQuad = *nBToKsEE;
		     							evalData.push_back(output_BCand_evt_nQuad);

		     							float* dtest = evalData.data();
		     							XGDMatrixCreateFromMat(dtest, 1, evalData.size(), -99, &h_test);
		     							bst_ulong outlen; // bst_ulong is a typedef of unsigned long
		     							const float *f; // array to store predictions
		     							XGBoosterPredict(h_booster,h_test,1,0,0,&outlen,&f);// lower version API
		     							
		     							quad_BDT_list.push_back(f[0]);
		     					 }
		     		}
		     		
		     		if(quad_BDT_list.size() > 0){
		     			output_BCand_quad_BDT = *(std::max_element(quad_BDT_list.begin(), quad_BDT_list.end()));
		     			std::cout << "Prediction: "<< output_BCand_quad_BDT << std::endl;
		     		}
		     		else if(isAssQuad == true && quad_BDT_list.size() == 0){
		     			output_BCand_quad_BDT = -88;
		     		}
		     		else{
		     			output_BCand_quad_BDT = -99;
		     		}
		     		hist1_42->Fill(output_BCand_quad_BDT);
		     		quad_BDT_scores[iB] = output_BCand_quad_BDT;
		     		
		     		l1_index = BToKEE_l1Idx[iB];
		     		l2_index = BToKEE_l2Idx[iB];
		     		k_index = BToKEE_kIdx[iB];
		     		TLorentzVector Kp4, Bp4;
		     		TLorentzVector l1p4, l2p4, kp4;
		     		l1p4.SetPtEtaPhiM(BToKEE_fit_l1_pt[iB], BToKEE_fit_l1_eta[iB], BToKEE_fit_l1_phi[iB], 0.000511);
		     		l2p4.SetPtEtaPhiM(BToKEE_fit_l2_pt[iB], BToKEE_fit_l2_eta[iB], BToKEE_fit_l2_phi[iB], 0.000511);
		     		Kp4.SetPtEtaPhiM(BToKEE_fit_k_pt[iB], BToKEE_fit_k_eta[iB], BToKEE_fit_k_phi[iB], 0.493677);
		     		Bp4.SetPtEtaPhiM(BToKEE_fit_pt[iB],BToKEE_fit_eta[iB],BToKEE_fit_phi[iB],BToKEE_fit_mass[iB]);
		     		TLorentzVector llp4;
		     		llp4 = l1p4 + l2p4;
		     		ROOT::Math::XYZVector Bp3Vector(Bp4.Px(), Bp4.Py(), Bp4.Pz());
		     		ROOT::Math::XYZVector llp3Vector(llp4.Px(),llp4.Py(),llp4.Pz());
		     		ROOT::Math::XYZVector Kp3Vector(Kp4.Px(),Kp4.Py(),Kp4.Pz());
		     		ROOT::Math::XYZVector BVtxVector(BToKEE_vtx_x[iB] - PV_x[0], BToKEE_vtx_y[iB] - PV_y[0], BToKEE_vtx_z[iB] - PV_z[0]);
		     		ROOT::Math::XYZVector unitBVtxVector = BVtxVector / BVtxVector.R();
				
			}	

                outputTree->Fill();

		}//end event loop

		cout<<"counters: "<<counter1<<" "<<counter2<<" "<<counter3<<" "<<counter4<<" "<<counter5<<" "<<counter6<<" "<<counter7<<" "<<counter8<<" "<<counter9<<" "<<counter10<<" "<<counter11<<" "<<counter12<<endl;
		outputTree->Write();
	
		
		cout<<"Done: " << outname << endl;  

		outputFile->Close();
    		file->Close();
		
}

void analyzer_Data_131_triplets(TString filename, std::string outpath, std::string outname, int ifile, int mode) {
    // Create histograms to store muon pt values
    TH1F* hist1_1 = new TH1F("hist1_1", "B mass", 1000, 4.2, 6.2);
		TH1F* hist1_2 = new TH1F("hist1_2", "ll mass", 1200, 0, 6);
		TH1F* hist1_3 = new TH1F("hist1_3", "ll mass normalized", 1000, 0, 1);
		TH1F* hist1_4 = new TH1F("hist1_4", "l1 p_{T}", 1000, 0,100);
		TH1F* hist1_5 = new TH1F("hist1_5", "l2 p_{T}", 1000, 0,100);
		TH1F* hist1_6 = new TH1F("hist1_6", "l1 p_{T} normalized", 1500, 0,15);
		TH1F* hist1_7 = new TH1F("hist1_7", "l2 p_{T} normalized", 1500, 0,15);
		TH1F* hist1_8 = new TH1F("hist1_8", "trk1 p_{T}", 1500, 0,30);
		TH1F* hist1_9 = new TH1F("hist1_9", "trk2 p_{T}", 1500, 0,30);
		TH1F* hist1_10 = new TH1F("hist1_10", "trk1 p_{T} normalized", 1000, 0,10);
		TH1F* hist1_11 = new TH1F("hist1_11", "trk2 p_{T} normalized", 1000, 0,10);
		TH1F* hist1_12 = new TH1F("hist1_12", "B p_{T}", 1000, 0,100);
		TH1F* hist1_13 = new TH1F("hist1_13", "B p_{T} normalized", 1000, 0,20);
		TH1F* hist1_14 = new TH1F("hist1_14", "cos #alpha_{3D}", 1000, -1,1);
		TH1F* hist1_15 = new TH1F("hist1_15", "Prob(SV fit)", 1000, 0,1);
		TH1F* hist1_16 = new TH1F("hist1_16", "sig(Lxy)", 1000, 0,500);
		TH1F* hist1_17 = new TH1F("hist1_17", "cos 2D fit", 1000, 0.9,1);
		TH1F* hist1_18 = new TH1F("hist1_18", "Momentum asymmetry ll-trk1", 1000, -1,1);
		TH1F* hist1_19 = new TH1F("hist1_19", "Momentum asymmetry ll-trk2", 1000, -1,1);
		TH1F* hist1_20 = new TH1F("hist1_20", "Momentum asymmetry ll-Ks", 1000, -1,1);
		TH1F* hist1_21 = new TH1F("hist1_21", "Impact parameter trk1", 1000, 0,60);
		TH1F* hist1_22 = new TH1F("hist1_22", "Impact parameter trk2", 1000, 0,60);
		TH1F* hist1_23 = new TH1F("hist1_23", "Isolation l1_iso04 normalized", 1000, 0,1);
		TH1F* hist1_24 = new TH1F("hist1_24", "Isolation l2_iso04 normalized", 1000, 0,1);
		TH1F* hist1_25 = new TH1F("hist1_25", "Isolation trk1_iso04 normalized", 1000, 0,1);
		TH1F* hist1_26 = new TH1F("hist1_26", "Isolation trk2_iso04 normalized", 1000, 0,1);
		TH1F* hist1_27 = new TH1F("hist1_27", "#Delta R (ll)", 1000, 0,3);
		TH1F* hist1_28 = new TH1F("hist1_28", "#Delta R (l1-trk1)", 1000, 0,4);
		TH1F* hist1_29 = new TH1F("hist1_29", "#Delta R (l1-trk2)", 1000, 0,4);
		TH1F* hist1_30 = new TH1F("hist1_30", "#Delta R (l2-trk1)", 1000, 0,4);
		TH1F* hist1_31 = new TH1F("hist1_31", "#Delta R (l2-trk2)", 1000, 0,4);
		TH1F* hist1_32 = new TH1F("hist1_32", "#Delta R (trk-trk)", 1000, 0,4);
		TH1F* hist1_33 = new TH1F("hist1_33", "#Delta z (l1-trk1)", 1000, -3,3);
		TH1F* hist1_34 = new TH1F("hist1_34", "#Delta z (l1-trk2)", 1000, -3,3);
		TH1F* hist1_35 = new TH1F("hist1_35", "#Delta z (l2-trk1)", 1000, -3,3);
		TH1F* hist1_36 = new TH1F("hist1_36", "#Delta z (l2-trk2)", 1000, -3,3);
		TH1F* hist1_37 = new TH1F("hist1_37", "#Delta z (trk-trk)", 1000, -3,3);
		TH1F* hist1_38 = new TH1F("hist1_38", "l1 ID", 2000, -10,10);
		TH1F* hist1_39 = new TH1F("hist1_39", "l2 ID", 2000, -10,10);
		TH1F* hist1_40 = new TH1F("hist1_40", "nTriplets", 100, 0,100);
		TH1F* hist1_41 = new TH1F("hist1_41", "nQuadruplets", 30, 0,30);
		TH1F* hist1_42 = new TH1F("hist1_42", "Associated quadruplets BDT", 1000, -10,10);
		TH1F* hist1_43 = new TH1F("hist1_43", "ll charge", 6, -3, 3);
		TH1F* hist1_44 = new TH1F("hist1_44", "run", 1000, 0, INT_MAX);
		TH1F* hist1_45 = new TH1F("hist1_45", "luminosity block", 1000, 0, INT_MAX);
		TH1F* hist1_46 = new TH1F("hist1_46", "event", 1000, 0, INT_MAX);
		TH1F* hist1_47 = new TH1F("hist1_47", "bunch crossing", 1000, 0, INT_MAX);
		TH1F* hist1_48 = new TH1F("hist1_48", "l1 eta", 1000, -6, 6);
		TH1F* hist1_49 = new TH1F("hist1_49", "l1 phi", 1000, -4, 4);
                TH1F* hist1_50 = new TH1F("hist1_50", "l2 eta", 1000, -6, 6);
		TH1F* hist1_51 = new TH1F("hist1_51", "l2 phi", 1000, -4, 4);
		TH1F* hist1_52 = new TH1F("hist1_52", "nElectron", 100, 0, 100);
		TH1F* hist1_53 = new TH1F("hist1_53", "nProbeTracks", 1000, 0, 1000);
		
		TH2F* hist2d_1_1  = new TH2F("hist2d_1_1","Trigger map",15,3.75,11.25,13,3.75,10.25);

		FillHistogram(hist1_1, hist1_2, hist1_3, hist1_4, hist1_5, hist1_6, hist1_7, hist1_8,hist1_9, hist1_10,
									hist1_11, hist1_12, hist1_13, hist1_14, hist1_15, hist1_16, hist1_17, hist1_18, hist1_19, hist1_20,
									hist1_21, hist1_22, hist1_23, hist1_24, hist1_25, hist1_26, hist1_27, hist1_28, hist1_29, hist1_30,
									hist1_31, hist1_32, hist1_33, hist1_34, hist1_35, hist1_36, hist1_37, hist1_38, hist1_39, hist1_40,
									hist1_41, hist1_42, hist1_43, hist1_44, hist1_45, hist1_46, hist1_47, hist1_48, hist1_49, hist1_50, hist1_51, hist1_52, hist1_53, 
									hist2d_1_1, 
									filename,
									mode, ifile, outpath, outname);
		
}
