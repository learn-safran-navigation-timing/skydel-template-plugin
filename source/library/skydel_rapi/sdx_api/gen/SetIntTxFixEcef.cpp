
#include "SetIntTxFixEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxFixEcef::CmdName = "SetIntTxFixEcef";
    const char* const SetIntTxFixEcef::Documentation = "Set interference transmitter static position and orientation\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------------\n"
      "X     double ECEF X (m)\n"
      "Y     double ECEF Y (m)\n"
      "Z     double ECEF Z (m)\n"
      "Yaw   double Yaw (rad)\n"
      "Pitch double Pitch (rad)\n"
      "Roll  double Roll (rad)\n"
      "Id    string Transmitter unique identifier.";
    const char* const SetIntTxFixEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxFixEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxFixEcef);


    SetIntTxFixEcef::SetIntTxFixEcef()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxFixEcef::SetIntTxFixEcef(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }

    SetIntTxFixEcefPtr SetIntTxFixEcef::create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<SetIntTxFixEcef>(x, y, z, yaw, pitch, roll, id);
    }

    SetIntTxFixEcefPtr SetIntTxFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxFixEcef>(ptr);
    }

    bool SetIntTxFixEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxFixEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxFixEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
      return names; 
    }


    int SetIntTxFixEcef::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxFixEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetIntTxFixEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFixEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetIntTxFixEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFixEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetIntTxFixEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFixEcef::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetIntTxFixEcef::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFixEcef::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetIntTxFixEcef::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIntTxFixEcef::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetIntTxFixEcef::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxFixEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxFixEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
