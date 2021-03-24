#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GalileoEphemerisDoubleParam is deprecated since 21.3. You may use GalileoEphDoubleParamForSV.
    /// 
    /// Get various parameters in the Galileo ephemeris
    /// 
    ///   ParamName         Unit
    ///   "ClockBias"       sec
    ///   "ClockDrift"      sec/sec
    ///   "ClockDriftRate"  sec/sec^2
    ///   "Crs"             meter
    ///   "Crc"             meter
    ///   "Cis"             rad
    ///   "Cic"             rad
    ///   "Cus"             rad
    ///   "Cuc"             rad
    ///   "DeltaN"          rad/sec
    ///   "M0"              rad
    ///   "Eccentricity"    -
    ///   "SqrtA"           sqrt(meter)
    ///   "BigOmega"        rad
    ///   "I0"              rad
    ///   "LittleOmega"     rad
    ///   "BigOmegaDot"     rad/sec
    ///   "Idot"            rad/sec
    ///   "Accuracy"        meter
    ///   "Adot"            meters/sec
    ///   "DeltaN0dot"      rad/sec^2
    ///   "Tgd"             sec
    ///   "BgdE1E5a"        ns
    ///   "BgdE1E5b"        ns
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetGalileoEphemerisDoubleParam;
    typedef std::shared_ptr<GetGalileoEphemerisDoubleParam> GetGalileoEphemerisDoubleParamPtr;
    
    
    class GetGalileoEphemerisDoubleParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphemerisDoubleParam();

      GetGalileoEphemerisDoubleParam(int prn, const std::string& paramName);
  
      static GetGalileoEphemerisDoubleParamPtr create(int prn, const std::string& paramName);
      static GetGalileoEphemerisDoubleParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

