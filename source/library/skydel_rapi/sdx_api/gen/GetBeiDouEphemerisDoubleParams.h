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
    /// Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForEachSV.
    /// 
    /// Please note the command GetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get BeiDou ephemeris parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetBeiDouEphDoubleParamForSV for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouEphemerisDoubleParams;
    typedef std::shared_ptr<GetBeiDouEphemerisDoubleParams> GetBeiDouEphemerisDoubleParamsPtr;
    
    
    class GetBeiDouEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetBeiDouEphemerisDoubleParams();

      GetBeiDouEphemerisDoubleParams(const std::string& paramName, const std::optional<std::string>& dataSetName = {});

      static GetBeiDouEphemerisDoubleParamsPtr create(const std::string& paramName, const std::optional<std::string>& dataSetName = {});
      static GetBeiDouEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

