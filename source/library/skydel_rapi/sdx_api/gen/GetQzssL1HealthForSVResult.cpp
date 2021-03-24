#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1HealthForSVResult
///
#include "gen/GetQzssL1HealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1HealthForSVResult::CmdName = "GetQzssL1HealthForSVResult";
    const char* const GetQzssL1HealthForSVResult::Documentation = "Result of GetQzssL1HealthForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssL1HealthForSVResult);


    GetQzssL1HealthForSVResult::GetQzssL1HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL1HealthForSVResult::GetQzssL1HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetQzssL1HealthForSVResultPtr GetQzssL1HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return GetQzssL1HealthForSVResultPtr(new GetQzssL1HealthForSVResult(relatedCommand, svId, health));
    }

    GetQzssL1HealthForSVResultPtr GetQzssL1HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1HealthForSVResult>(ptr);
    }

    bool GetQzssL1HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetQzssL1HealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL1HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL1HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL1HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
