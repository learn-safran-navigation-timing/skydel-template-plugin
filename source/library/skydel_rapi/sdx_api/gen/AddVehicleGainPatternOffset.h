#pragma once

#include <memory>
#include "command_base.h"

#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add an offset (in db) for all values of the pattern.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// Offset      double          Power offset
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class AddVehicleGainPatternOffset;
    typedef std::shared_ptr<AddVehicleGainPatternOffset> AddVehicleGainPatternOffsetPtr;
    
    
    class AddVehicleGainPatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddVehicleGainPatternOffset();

      AddVehicleGainPatternOffset(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});

      static AddVehicleGainPatternOffsetPtr create(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});
      static AddVehicleGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** antennaName ****
      std::optional<std::string> antennaName() const;
      void setAntennaName(const std::optional<std::string>& antennaName);
    };
    
  }
}

