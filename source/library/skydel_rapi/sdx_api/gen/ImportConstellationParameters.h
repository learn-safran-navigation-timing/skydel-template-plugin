#pragma once

#include <memory>
#include "command_base.h"
#include <string>
#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import navigation message file for the specified constellation. This could be Rinex, SEM or YUMA file for GPS. Only Rinex for the others.
    ///
    /// Name     Type         Description
    /// -------- ------------ ----------------------------------------------------------------------------------------------------
    /// System   string       "GPS", "GLONASS", "Galileo", "SBAS", "BeiDou", "QZSS" or "NavIC"
    /// Path     string       File path
    /// Rollover optional int Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.
    ///

    class ImportConstellationParameters;
    typedef std::shared_ptr<ImportConstellationParameters> ImportConstellationParametersPtr;
    
    
    class ImportConstellationParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportConstellationParameters();

      ImportConstellationParameters(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover = {});
  
      static ImportConstellationParametersPtr create(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover = {});
      static ImportConstellationParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** rollover ****
      Sdx::optional<int> rollover() const;
      void setRollover(const Sdx::optional<int>& rollover);
    };
  }
}

