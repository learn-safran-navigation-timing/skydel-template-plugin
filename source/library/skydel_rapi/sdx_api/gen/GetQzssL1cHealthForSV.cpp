#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1cHealthForSV
///
#include "gen/GetQzssL1cHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1cHealthForSV::CmdName = "GetQzssL1cHealthForSV";
    const char* const GetQzssL1cHealthForSV::Documentation = "Please note the command GetQzssSatelliteL1cHealth is deprecated since 21.3. You may use GetQzssL1cHealthForSV.\n\nGet QZSS L1C health (Health of L1C signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL1cHealthForSV);


    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL1cHealthForSV::GetQzssL1cHealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::create(int svId)
    {
      return GetQzssL1cHealthForSVPtr(new GetQzssL1cHealthForSV(svId));
    }

    GetQzssL1cHealthForSVPtr GetQzssL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1cHealthForSV>(ptr);
    }

    bool GetQzssL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssL1cHealthForSV::documentation() const { return Documentation; }


    int GetQzssL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
