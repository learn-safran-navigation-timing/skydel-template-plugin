#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get various boolean parameters in the QZSS ephemeris
    /// 
    ///   ParamName
    /// "IscL1CaAvailable"
    /// "IscL2CAvailable"
    /// "IscL5I5Available"
    /// "IscL5Q5Available"
    /// "IscL1CPAvailable"
    /// "IscL1CDAvailable"
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForSV;
    typedef std::shared_ptr<GetQzssEphBoolParamForSV> GetQzssEphBoolParamForSVPtr;
    
    
    class GetQzssEphBoolParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetQzssEphBoolParamForSV();

      GetQzssEphBoolParamForSV(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {});

      static GetQzssEphBoolParamForSVPtr create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {});
      static GetQzssEphBoolParamForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

