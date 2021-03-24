#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsRFOutputEnabled
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    The satellite's SV ID
    /// Enabled bool   RF is enabled when value is True
    ///

    class IsRFOutputEnabledResult;
    typedef std::shared_ptr<IsRFOutputEnabledResult> IsRFOutputEnabledResultPtr;
    
    
    class IsRFOutputEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsRFOutputEnabledResult();

      IsRFOutputEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);
  
      static IsRFOutputEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);
      static IsRFOutputEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

