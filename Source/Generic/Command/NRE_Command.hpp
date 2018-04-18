
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
                    /**
                     * Default Constructor
                     */
                    Command();
                    /**
                     * Construct a command with a specified targeted object and his methods
                     * @param target the targeted object
                     * @param method the targeted object's method to call
                     */
                    Command(Receiver* target, void(Receiver::* method)());

                //## Copy-Constructor ##//
                    /**
                     * Copy cmd into this
                     * @param cmd the command to copy the content
                     */
                    Command(Command const& cmd);

                //## Move-Constructor ##//
                    /**
                     * Move cmd into this, leaving cmd empty
                     * @param cmd the command to move
                     */
                    Command(Command && cmd);

                //## Convertor ##//

                //## Deconstructor ##//
                    /**
                     * Command Deconstructor
                     */
                    ~Command();

                //## Getter ##//

                //## Setter ##//

                //## Methods ##//
                    /**
                     * Execute the stored methods from the targeted object
                     */
                    void execute();

                //## Access Operator ##//

                //## Assignment Operator ##//
                    /**
                     * Copy assigment of cmd into this
                     * @param cmd the command to copy into this
                     * @return the reference of himself
                     */
                    Command<Receiver>& operator=(Command<Receiver> const& cmd);
                    /**
                     * Move assigment of cmd into this, leaving cmd empty
                     * @param cmd the command to move into this
                     * @return the reference of himself
                     */
                    Command<Receiver>& operator=(Command<Receiver> && cmd);

                //## Shortcut Operator ##//

                //## Arithmetic Operator ##//

                //## Comparison Operator ##//

                //## BitWise Operator ##//

                //## Shift Operator ##//

            private:
        };
    };

    #include "NRE_Command.tpp"
