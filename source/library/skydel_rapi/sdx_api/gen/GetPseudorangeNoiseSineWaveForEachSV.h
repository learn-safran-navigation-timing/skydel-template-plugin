#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise sine wave attributes for all satellites.
    ///
    /// Name     Type   Description
    /// -------- ------ --------------------------------------------------------------------------
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SineWave int    Sine wave number (0 or 1)
    ///

    class GetPseudorangeNoiseSineWaveForEachSV;
    typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForEachSV> GetPseudorangeNoiseSineWaveForEachSVPtr;
    
    
    class GetPseudorangeNoiseSineWaveForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeNoiseSineWaveForEachSV();

      GetPseudorangeNoiseSineWaveForEachSV(const std::string& system, int sineWave);

      static GetPseudorangeNoiseSineWaveForEachSVPtr create(const std::string& system, int sineWave);
      static GetPseudorangeNoiseSineWaveForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** sineWave ****
      int sineWave() const;
      void setSineWave(int sineWave);
    };
    
  }
}

