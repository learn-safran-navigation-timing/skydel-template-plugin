#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSatellitePseudorangeNoiseGaussMarkov
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Process int    Gauss-Markov Process number (0 or 1)
    /// Enabled bool   If true, Gauss-Markov process is enabled
    /// Sigma   double Standard devition in meters [0..5000]
    /// Time    double Time constant [1..2000]
    /// Seed    int    Random seed
    ///

    class GetSatellitePseudorangeNoiseGaussMarkovResult;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseGaussMarkovResult> GetSatellitePseudorangeNoiseGaussMarkovResultPtr;
    
    
    class GetSatellitePseudorangeNoiseGaussMarkovResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseGaussMarkovResult();

      GetSatellitePseudorangeNoiseGaussMarkovResult(CommandBasePtr relatedCommand, const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed);
  
      static GetSatellitePseudorangeNoiseGaussMarkovResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed);
      static GetSatellitePseudorangeNoiseGaussMarkovResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** process ****
      int process() const;
      void setProcess(int process);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** sigma ****
      double sigma() const;
      void setSigma(double sigma);


      // **** time ****
      double time() const;
      void setTime(double time);


      // **** seed ****
      int seed() const;
      void setSeed(int seed);
    };
  }
}

