#pragma once

#include <memory>
#include "command_base.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use GetQzssL1DataHealthForSV.
    /// 
    /// Get QZSS L1 C/A nav data health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssSatelliteL1DataHealth;
    typedef std::shared_ptr<GetQzssSatelliteL1DataHealth> GetQzssSatelliteL1DataHealthPtr;
    
    
    class GetQzssSatelliteL1DataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssSatelliteL1DataHealth();

      GetQzssSatelliteL1DataHealth(int svId, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetQzssSatelliteL1DataHealthPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssSatelliteL1DataHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

