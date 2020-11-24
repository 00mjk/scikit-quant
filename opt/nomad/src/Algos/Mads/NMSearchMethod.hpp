/*---------------------------------------------------------------------------------*/
/*  NOMAD - Nonlinear Optimization by Mesh Adaptive Direct Search -                */
/*                                                                                 */
/*  NOMAD - Version 4.0.0 has been created by                                      */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  The copyright of NOMAD - version 4.0.0 is owned by                             */
/*                 Sebastien Le Digabel        - Polytechnique Montreal            */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  NOMAD v4 has been funded by Rio Tinto, Hydro-Québec, NSERC (Natural Science    */
/*  and Engineering Research Council of Canada), INOVEE (Innovation en Energie     */
/*  Electrique and IVADO (The Institute for Data Valorization)                     */
/*                                                                                 */
/*  NOMAD v3 was created and developed by Charles Audet, Sebastien Le Digabel,     */
/*  Christophe Tribes and Viviane Rochon Montplaisir and was funded by AFOSR       */
/*  and Exxon Mobil.                                                               */
/*                                                                                 */
/*  NOMAD v1 and v2 were created and developed by Mark Abramson, Charles Audet,    */
/*  Gilles Couture, and John E. Dennis Jr., and were funded by AFOSR and           */
/*  Exxon Mobil.                                                                   */
/*                                                                                 */
/*  Contact information:                                                           */
/*    Polytechnique Montreal - GERAD                                               */
/*    C.P. 6079, Succ. Centre-ville, Montreal (Quebec) H3C 3A7 Canada              */
/*    e-mail: nomad@gerad.ca                                                       */
/*    phone : 1-514-340-6053 #6928                                                 */
/*    fax   : 1-514-340-5665                                                       */
/*                                                                                 */
/*  This program is free software: you can redistribute it and/or modify it        */
/*  under the terms of the GNU Lesser General Public License as published by       */
/*  the Free Software Foundation, either version 3 of the License, or (at your     */
/*  option) any later version.                                                     */
/*                                                                                 */
/*  This program is distributed in the hope that it will be useful, but WITHOUT    */
/*  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or          */
/*  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License    */
/*  for more details.                                                              */
/*                                                                                 */
/*  You should have received a copy of the GNU Lesser General Public License       */
/*  along with this program. If not, see <http://www.gnu.org/licenses/>.           */
/*                                                                                 */
/*  You can find information on the NOMAD software at www.gerad.ca/nomad           */
/*---------------------------------------------------------------------------------*/
#ifndef __NOMAD400_NMSEARCHMETHOD__
#define __NOMAD400_NMSEARCHMETHOD__

#include "../../Algos/Mads/SearchMethod.hpp"

#include "../../nomad_nsbegin.hpp"

/// Class to perform a Search method using Nelder Mead simplex algorithm.
/**
 If Nelder Mead search is enabled (check is done in NMSearchMethod::init), the NMSearchMethod::run function manages the execution (start, run, end) of the NM algorithm. \n
 The new trial points can be generated during a single pass of all Nelder Mead reflective steps (REFLECT, EXPAND, INSIDE_CONTRACTION, OUTSIDE_CONTRACTION) ( generateTrialPoint ) or as a NM optimization.
 */
class NMSearchMethod final : public SearchMethod
{
public:
    /// Constructor
    /**
     /param parentStep      The parent of this search step -- \b IN.
     */
    explicit NMSearchMethod(const Step* parentStep )
      : SearchMethod(parentStep )
    {
        init();
    }

    /**
     Make sure the step by step version of NM algorithm is used.
     */
    virtual void startImp() override;

    /**
     Execute (start, run, end) of the NM algorithm. Returns a \c true flag if the algorithm found better point.
     */
    virtual bool runImp() override ;


private:

    /// Helper for constructor.
    /**
     Test if the NM search is enabled or not.
     */
    void init();

    ///Generate new points (no evaluation)
    /**
     This function is used only when a MADS search based on Nelder Mead with the option to generate all points before evaluation performs one iteration of all reflective steps (Reflect, Expansion, Inside and Outside Contraction).
     */
    void generateTrialPoints() override;

};

#include "../../nomad_nsend.hpp"

#endif // __NOMAD400_NMSEARCHMETHOD__
