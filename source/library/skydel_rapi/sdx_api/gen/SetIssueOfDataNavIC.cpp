
#include "SetIssueOfDataNavIC.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIssueOfDataNavIC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIssueOfDataNavIC::CmdName = "SetIssueOfDataNavIC";
    const char* const SetIssueOfDataNavIC::Documentation = "Set NavIC Issue of data, Ephemeris and Clock (IODEC)\n"
      "\n"
      "Name              Type          Description\n"
      "----------------- ------------- -------------------------------------------------------\n"
      "EphemerisAndClock int           Issue of data, ephemeris and clock\n"
      "OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True";
    const char* const SetIssueOfDataNavIC::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIssueOfDataNavIC);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIssueOfDataNavIC);


    SetIssueOfDataNavIC::SetIssueOfDataNavIC()
      : CommandBase(CmdName, TargetId)
    {}

    SetIssueOfDataNavIC::SetIssueOfDataNavIC(int ephemerisAndClock, const std::optional<bool>& overrideRinex)
      : CommandBase(CmdName, TargetId)
    {

      setEphemerisAndClock(ephemerisAndClock);
      setOverrideRinex(overrideRinex);
    }

    SetIssueOfDataNavICPtr SetIssueOfDataNavIC::create(int ephemerisAndClock, const std::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetIssueOfDataNavIC>(ephemerisAndClock, overrideRinex);
    }

    SetIssueOfDataNavICPtr SetIssueOfDataNavIC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIssueOfDataNavIC>(ptr);
    }

    bool SetIssueOfDataNavIC::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["EphemerisAndClock"])
          && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetIssueOfDataNavIC::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIssueOfDataNavIC::fieldNames() const 
    { 
      static const std::vector<std::string> names {"EphemerisAndClock", "OverrideRinex"}; 
      return names; 
    }


    int SetIssueOfDataNavIC::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIssueOfDataNavIC::ephemerisAndClock() const
    {
      return parse_json<int>::parse(m_values["EphemerisAndClock"]);
    }

    void SetIssueOfDataNavIC::setEphemerisAndClock(int ephemerisAndClock)
    {
      m_values.AddMember("EphemerisAndClock", parse_json<int>::format(ephemerisAndClock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<bool> SetIssueOfDataNavIC::overrideRinex() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetIssueOfDataNavIC::setOverrideRinex(const std::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
