
#include "GetVehicleAntennaGain.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaGain::CmdName = "GetVehicleAntennaGain";
    const char* const GetVehicleAntennaGain::Documentation = "Get Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.\n"
      "\n"
      "Name Type            Description\n"
      "---- --------------- --------------------\n"
      "Band GNSSBand        Frequency band\n"
      "Name optional string Vehicle antenna name";
    const char* const GetVehicleAntennaGain::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaGain);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleAntennaGain);


    GetVehicleAntennaGain::GetVehicleAntennaGain()
      : CommandBase(CmdName, TargetId)
    {}

    GetVehicleAntennaGain::GetVehicleAntennaGain(const Sdx::GNSSBand& band, const std::optional<std::string>& name)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setName(name);
    }

    GetVehicleAntennaGainPtr GetVehicleAntennaGain::create(const Sdx::GNSSBand& band, const std::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaGain>(band, name);
    }

    GetVehicleAntennaGainPtr GetVehicleAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaGain>(ptr);
    }

    bool GetVehicleAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaGain::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleAntennaGain::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Name"}; 
      return names; 
    }


    int GetVehicleAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetVehicleAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetVehicleAntennaGain::name() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaGain::setName(const std::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
