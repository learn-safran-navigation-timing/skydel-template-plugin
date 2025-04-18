#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes all interference signals.
    ///
    /// 
    ///

    class RemoveAllInterferences;
    typedef std::shared_ptr<RemoveAllInterferences> RemoveAllInterferencesPtr;
    
    
    class RemoveAllInterferences : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllInterferences();

      static RemoveAllInterferencesPtr create();
      static RemoveAllInterferencesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

