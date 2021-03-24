#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouSatelliteHealthInfo is deprecated since 21.3. You may use BeiDouHealthInfoForSV.
    /// 
    /// Get BeiDou satellite health info
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouSatelliteHealthInfo;
    typedef std::shared_ptr<GetBeiDouSatelliteHealthInfo> GetBeiDouSatelliteHealthInfoPtr;
    
    
    class GetBeiDouSatelliteHealthInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteHealthInfo();

      GetBeiDouSatelliteHealthInfo(int prn);
  
      static GetBeiDouSatelliteHealthInfoPtr create(int prn);
      static GetBeiDouSatelliteHealthInfoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

