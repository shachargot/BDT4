// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIsdIsgottliedICMSSW_13_1_0dIsrcdIBDT4dIanalyzer_Data_131_triplets_C_ACLiC_dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/afs/cern.ch/user/s/sgottlie/CMSSW_13_1_0/src/BDT4/./analyzer_Data_131_triplets.C"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_analyzer_Data_131_triplets_C_ACLiC_dict_Impl() {
    static const char* headers[] = {
"./analyzer_Data_131_triplets.C",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/include",
"/afs/cern.ch/user/s/sgottlie/CMSSW_13_1_0/src",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/cms/cmssw/CMSSW_13_1_0/src",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/mctester/1.25.1-4a0a9e0c55f47fef72f293e02201e92a/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hydjet2/2.4.3-3ee1806ea12aa6bbe2bd86d5d98470a3/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/dd4hep/v01-23x-e596f23667a8735ac9ed3cfbb05afef6/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/herwig7/7.2.2-8368e8c5883c52d1979a64f947e59f1d/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/tauolapp/1.1.8-a4202ffb73998f33a5ada8e072abc676/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/sherpa/2.2.15-98b110038831ef24fb9b4f7bbe80d538/include/SHERPA-MC",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/lwtnn/2.13-2fe16f202d2fd28cd8f0245d6817d0ed/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/thepeg/2.2.2-3fb9f1b0598ef1ef085afaad56d048a1/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/pythia8/306-5067ec5c31d712c48a1c72580e436635/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/xrootd/5.5.3-f4e55df854eb17c5ac44e62310d7c34d/include/xrootd/private",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/starlight/r193-bbc8ef0fe46b9698867bbb0f62a5211f/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/rivet/3.1.7-51ecba7ad57de6703d99ca3cabc00d05/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/highfive/2.3.1-00c7c64bd820ab30f517acd4945f6525/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/geant4/11.1.1-ac161db70c0e3e3108ae225f93d223a6/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/classlib/3.1.3-52a2fe4d34a5f733d734f75ee05cb886/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/lhapdf/6.4.0-da19eccd1d2ff8231a1e0f9696ddd595/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/alpaka/develop-20230215-8f5cee8e785b1994803c3730968f8681/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/tkonlinesw/4.2.0-1_gcc7-e73ea8c22e242a4f276a672fd5c988b7/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/pcre2/10.36-88c59c64ebe54b36ea4626d5827d6026/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libungif/4.1.4-6b4f3e28660c3a9d4e75854eb8da0012/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libtiff/4.0.10-8798bda88f99b734bd8c86bf87e202e6/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libpng/1.6.37-a2ff0f76300cbef7e51b77d816ff554a/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/frontier_client/2.10.1-6679ac5847fdba5d019fa0762efab61d/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/pcre/8.43-5dcc901acc02f624b22dd9840b2357e8/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/zstd/1.5.2-4341c217fdb8259db5ea57a7c59a8008/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/cms/vdt/0.4.3-b2ab7c000c16e419f85e9fb6284d3681/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/valgrind/3.17.0-7ca83817e7379e83453f913e11e14834/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/utm/utm_0.11.2-7320d0f24d79805aa3ee736be565f1ee/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/sigcpp/3.2.0-aa26ce8063258bda618dfc2c25b06c89/include/sigc++-3.0",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/sqlite/3.36.0-0f26675926fd468efdd431be2b62785e/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/pacparser/1.4.0-61065e1467f00b52cab735f5c96a2599/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/oracle/19.11.0.0.0dbru-092ba337a70a02c4734616a84f842897/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/py3-numpy/1.23.5-b4049f532057a81548c5dda2b52ca7da/c-api/core/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/meschach/1.2.pCMS1-a6c940d49300e01334c28ef7c2460c02/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/lz4/1.9.2-031da253be076d002e4d6af36bc64212/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libuuid/2.34-0451b31e1b9a58c6aeefab41c18eea34/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libjpeg-turbo/2.0.2-0670ec17b6dbf72d9c70c3a287cf2ce2/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/ktjet/1.06-e9501e53aabaf5b3d345c0fc2c4f2647/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/jemalloc-prof/5.3.0-6b462afcab2681c6c8cb1a38e972147b/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/jemalloc-debug/5.3.0-e4b496fe0ff01aa9263cde101072abeb/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/jemalloc/5.3.0-1441ab8f6489a591662292c655ed11d3/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hls/2019.08-fd724004387c2a6770dc3517446d30d9/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/madgraph5amcatnlo/2.7.3-005b0817180f42ecf1001b011284e542",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/heppdt/3.04.01-d3274e9c1f96c4ccfe0580cc854a414f/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hector/1.3.4_patch1-83b2a667f5c8f9f7a6e0eacc5daab560/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/protobuf/3.15.1-afbf0e4e62db8d179f85b9eef7a9fbab/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libunwind/1.6.2-master-5661dca2c54f6802e98cc3676ea0f0d6/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/giflib/5.2.0-e928fbc1a732191ff28d8dfbf2e6ee63/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/gdbm/1.10-94fd72446cd6c73834b291fb1d1c6f46/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/freetype/2.10.0-7c6fc6af284a6e94f5e435c9ea3767b9/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/fftw3/3.3.8-5f403c3dc6c4147769a1f10565ec7e26/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/fftjet/1.5.0-1cd7b7c71b42be65b840b68281156a1e/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/fastjet/3.4.1-6ccef2e7f09390c07c8ec83301e11824/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/expat/2.1.0-5f6457b4c04e97afec6079bd7d2db998/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/vecgeom/v1.2.1-d92ce96afe8fcfdf821b0e3277815aae/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/vecgeom/v1.2.1-d92ce96afe8fcfdf821b0e3277815aae/include/VecGeom",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/xerces-c/3.1.3-96261f23c7d6fbfb7d59be544bd882f3/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/xz/5.2.5-83d0a00b575efd1701e07bedf7977343/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/dcap/2.47.12-ef79ca4ec7d517ad93018edfef3356c2/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/libxml2/2.9.10-0a5b015a5590b04cf3087955ff42a243/include/libxml2",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/curl/7.79.0-5e48e0bf013ba13376a33ec8da72dabc/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/cppunit/1.15.x-c4570d64b509e2e0614dc83d98c1df8c/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/cms/coral/CORAL_2_3_21-a5dad611a3e2329b06e9b744bf0b888e/include/LCG",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/clhep/2.4.6.0-a4e46555f840df7cd8747ba64c6e914f/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/zlib/1.2.11-3dfb2715f3608466b74431b80eb9d788/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/pythia6/426-154c9fa9309a9a96c7e05f80622d33eb/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hepmc/2.06.10-8d052e96205063f65fddfc4cbf40f506/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/gsl/2.6-fcf47bcbedd800ca8386c7e2920fa474/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/bz2lib/1.0.6-2c1f18484cb66c30aba7929f2be5e7d4/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/tbb/v2021.8.0-4e779f195a25a0aba119b27519937ba0/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/rocm-rocrand/5.4.3-e3475a4b3c5a437af6279c98f00344a9/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/cuda/11.5.2-66a9473808e7d5863d5bbec0824e2c4a/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/boost/1.80.0-7f4aeae1bffcf24aa4723f09435633c2/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/xgboost/1.7.5-611ab76f026fa95bda74817cae4b33e8/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/tinyxml2/6.2.0-c2bad61e58f94d6db8f640afbd739be2/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/rdma-core/39.1-aefa2bc3a4e0072c5fe93d506402ac71/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/ittnotify/16.06.18-55dda586bd53ea172280a0e952fdff95/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/gosamcontrib/2.0-20150803-001c255025c150fdbe081040c1f49536/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/fmt/8.0.1-43b841663c2a0d6622910a1ad66d228d/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/eigen/82dd3710dac619448f50331c1d6a35da673f764a-9ac4aed18ac60d0189693c592862694d/include/eigen3",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/rocm/5.4.3-54a49cd5963d1f81136e5ec29a9fc8d7/include",
"/usr/local/include",
"/usr/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/etc/",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/etc//cling",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/etc//cling/plugins/include",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/include/",
"/cvmfs/cms.cern.ch/el8_amd64_gcc11/lcg/root/6.26.11-4a51300109b5113a50c0e8e0c0ebe1d1/include/",
"/afs/cern.ch/user/s/sgottlie/CMSSW_13_1_0/src/BDT4/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "analyzer_Data_131_triplets_C_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "analyzer_Data_131_triplets_C_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./analyzer_Data_131_triplets.C"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"FillHistogram", payloadCode, "@",
"analyzer_Data_131_triplets", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("analyzer_Data_131_triplets_C_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_analyzer_Data_131_triplets_C_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_analyzer_Data_131_triplets_C_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_analyzer_Data_131_triplets_C_ACLiC_dict() {
  TriggerDictionaryInitialization_analyzer_Data_131_triplets_C_ACLiC_dict_Impl();
}
