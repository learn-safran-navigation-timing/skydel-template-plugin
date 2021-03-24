#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------
    /// ParamName string Refer to SetGpsEphDoubleParamForSV for accepted names
    ///

    class GetGpsEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetGpsEphDoubleParamForEachSV> GetGpsEphDoubleParamForEachSVPtr;
    
    
    class GetGpsEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphDoubleParamForEachSV();

      GetGpsEphDoubleParamForEachSV(const std::string& paramName);
  
      static GetGpsEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetGpsEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

