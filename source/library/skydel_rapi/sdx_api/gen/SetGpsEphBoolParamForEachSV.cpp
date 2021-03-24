#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphBoolParamForEachSV
///
#include "gen/SetGpsEphBoolParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphBoolParamForEachSV::CmdName = "SetGpsEphBoolParamForEachSV";
    const char* const SetGpsEphBoolParamForEachSV::Documentation = "Please note the command SetGpsEphemerisBoolParams is deprecated since 21.3. You may use SetGpsEphBoolParamForEachSV.\n\nSet GPS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetGpsEphBoolParamForEachSV);


    SetGpsEphBoolParamForEachSV::SetGpsEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetGpsEphBoolParamForEachSV::SetGpsEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
    }


    SetGpsEphBoolParamForEachSVPtr SetGpsEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val)
    {
      return SetGpsEphBoolParamForEachSVPtr(new SetGpsEphBoolParamForEachSV(paramName, val));
    }

    SetGpsEphBoolParamForEachSVPtr SetGpsEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphBoolParamForEachSV>(ptr);
    }

    bool SetGpsEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGpsEphBoolParamForEachSV::documentation() const { return Documentation; }


    int SetGpsEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetGpsEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetGpsEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
