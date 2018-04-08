
    /**
     * @file NRE_Command.hpp
     * @brief Declaration of Engine's Object : Command
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "BaseCommand/NRE_BaseCommand.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {

        /**
         * @class Command
         * @brief NRE's Object : A basic template command
         */
        template <class Receiver>
        class Command : public BaseCommand {
            private:
                Receiver* target;
                void(Receiver::* action)();

            public:
                //## Constructor ##//
                Command();
                Command(Receiver* target, void(Receiver::* method)());

                //## Copy-Constructor ##//

                //## Convertor ##//

                //## Deconstructor ##//
                ~Command();

                //## Getter ##//

                //## Setter ##//

                //## Methods ##//
                void execute();

                //## Access Operator ##//

                //## Assignment Operator ##//

                //## Shortcut Operator ##//

                //## Arithmetic Operator ##//

                //## Comparison Operator ##//

                //## BitWise Operator ##//

                //## Shift Operator ##//

            private:
        };
    };

    #include "NRE_Command.tpp"
