#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICSHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.
    /// Health      bool            S health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICSHealthForSVResult;
    typedef std::shared_ptr<GetNavICSHealthForSVResult> GetNavICSHealthForSVResultPtr;
    
    
    class GetNavICSHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNavICSHealthForSVResult();

      GetNavICSHealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      GetNavICSHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetNavICSHealthForSVResultPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetNavICSHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static GetNavICSHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICSHealthForSVResult);
  }
}

