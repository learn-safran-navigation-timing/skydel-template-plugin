#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataGalileo.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------------
    /// Navigation    int           Issue of data, navigation
    /// Almanac       int           Issue of data, almanac
    /// OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True
    ///

    class GetIssueOfDataGalileoResult;
    typedef std::shared_ptr<GetIssueOfDataGalileoResult> GetIssueOfDataGalileoResultPtr;
    
    
    class GetIssueOfDataGalileoResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataGalileoResult();

      GetIssueOfDataGalileoResult(int navigation, int almanac, const std::optional<bool>& overrideRinex = {});

      GetIssueOfDataGalileoResult(CommandBasePtr relatedCommand, int navigation, int almanac, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataGalileoResultPtr create(int navigation, int almanac, const std::optional<bool>& overrideRinex = {});

      static GetIssueOfDataGalileoResultPtr create(CommandBasePtr relatedCommand, int navigation, int almanac, const std::optional<bool>& overrideRinex = {});
      static GetIssueOfDataGalileoResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** navigation ****
      int navigation() const;
      void setNavigation(int navigation);


      // **** almanac ****
      int almanac() const;
      void setAlmanac(int almanac);


      // **** overrideRinex ****
      std::optional<bool> overrideRinex() const;
      void setOverrideRinex(const std::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIssueOfDataGalileoResult);
  }
}

