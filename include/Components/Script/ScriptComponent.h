#ifndef SCRIPTCOMPONENT_H
#define SCRIPTCOMPONENT_H

#include "Components/ComponentBase.h"

// TODO (Thomas Luppi#1#04/29/14): LUA Compiller

///Component type which provides additionally functionality not given elsewhere
class ScriptComponent : public ComponentBase
{
    public:
        ScriptComponent() : ComponentBase() {}
        ScriptComponent(unsigned int ID);
        virtual ~ScriptComponent();
        virtual bool isActive() {return active;}
        virtual void enable() {active = true;}
        virtual void disable() {active = false;}
    protected:
        bool active;
    private:
};

#endif // SCRIPTCOMPONENT_H
