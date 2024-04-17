#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSyncTimeMainInstance.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class GetSyncTimeMainInstanceResult;
    typedef std::shared_ptr<GetSyncTimeMainInstanceResult> GetSyncTimeMainInstanceResultPtr;
    typedef GetSyncTimeMainInstanceResult GetSyncTimeMasterResult;
    typedef std::shared_ptr<GetSyncTimeMasterResult> GetSyncTimeMasterResultPtr;
    
    class GetSyncTimeMainInstanceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSyncTimeMainInstanceResult();

      GetSyncTimeMainInstanceResult(double time);

      GetSyncTimeMainInstanceResult(CommandBasePtr relatedCommand, double time);

      static GetSyncTimeMainInstanceResultPtr create(double time);

      static GetSyncTimeMainInstanceResultPtr create(CommandBasePtr relatedCommand, double time);
      static GetSyncTimeMainInstanceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSyncTimeMainInstanceResult);
  }
}

