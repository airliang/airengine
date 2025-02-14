#include "stdafx.h"
#include "AISForceFeedBack.h"


using namespace AIS;

//VC7.1 had a problem with these not getting included.. 
//Perhaps a case of a crazy extreme optimizer :/ (moved to header)
//const unsigned int Effect::AIS_INFINITE = 0xFFFFFFFF;

//------------------------------------------------------------------------------//
static const char* pszEForceString[] = 
{ 
	"UnknownForce",
	"ConstantForce", 
	"RampForce", 
	"PeriodicForce", 
	"ConditionalForce", 
	"CustomForce" 
};

const char* Effect::getForceTypeName(Effect::EForce eValue)
{
	return (eValue >= 0 && eValue < _ForcesNumber) ? pszEForceString[eValue] : "<Bad force type>";
}

static const char* pszETypeString[] = 
{ 
	"Unknown",
	"Constant",
	"Ramp",
	"Square", "Triangle", "Sine", "SawToothUp", "SawToothDown",
	"Friction", "Damper", "Inertia", "Spring",
	"Custom" 
};

const char* Effect::getEffectTypeName(Effect::EType eValue)
{
	return (eValue >= 0 && eValue < _TypesNumber) ? pszETypeString[eValue] : "<Bad effect type>";
}

static const char* pszEDirectionString[] = 
{ "NorthWest", "North", "NorthEast", "East", "SouthEast", "South", "SouthWest", "West"};

const char* Effect::getDirectionName(Effect::EDirection eValue)
{
	return (eValue >= 0 && eValue < _DirectionsNumber) ? pszEDirectionString[eValue] : "<Bad direction>";
}

//------------------------------------------------------------------------------//
Effect::Effect() : 
force(UnknownForce), 
type(Unknown),
effect(0),
axes(1)
{
}

//------------------------------------------------------------------------------//
Effect::Effect(EForce ef, EType et) : 
force(ef), 
type(et),
direction(North), 
trigger_button(-1),
trigger_interval(0),
replay_length(Effect::AIS_INFINITE),
replay_delay(0),
_handle(-1),
axes(1)
{
	effect = 0;

	switch( ef )
	{
	case ConstantForce:    effect = new ConstantEffect(); break;
	case RampForce:	       effect = new RampEffect(); break;
	case PeriodicForce:    effect = new PeriodicEffect(); break;
	case ConditionalForce: effect = new ConditionalEffect(); break;
	default: break;
	}
}

//------------------------------------------------------------------------------//
Effect::~Effect()
{
	delete effect;
}

//------------------------------------------------------------------------------//
ForceEffect* Effect::getForceEffect() const
{
	//If no effect was created in constructor, then we raise an error here
	if( effect == 0 )
		AIS_EXCEPT( E_NotSupported, "Requested ForceEffect is null!" );

	return effect;
}

//------------------------------------------------------------------------------//
void Effect::setNumAxes(short nAxes)
{
	//Can only be set before a handle was assigned (effect created)
	if( _handle != -1 )
		axes = nAxes;
}

//------------------------------------------------------------------------------//
short Effect::getNumAxes() const
{
	return axes;
}


//--------------------------------------------------------------------------------------------------


//-------------------------------------------------------------//
ForceFeedback::ForceFeedback() : mSetGainSupport(false), mSetAutoCenterSupport(false)
{
}

//-------------------------------------------------------------//
void ForceFeedback::_addEffectTypes( Effect::EForce force, Effect::EType type )
{
	if( force <= Effect::UnknownForce || force >= Effect::_ForcesNumber
		|| type <= Effect::Unknown || type >= Effect::_TypesNumber )
		AIS_EXCEPT( E_General, "Can't add unknown effect Force/Type to the supported list" );

	mSupportedEffects.insert(std::pair<Effect::EForce, Effect::EType>(force, type));
}

//-------------------------------------------------------------//
void ForceFeedback::_setGainSupport( bool on )
{
	mSetGainSupport = on;
}

//-------------------------------------------------------------//
void ForceFeedback::_setAutoCenterSupport( bool on )
{
	mSetAutoCenterSupport = on;
}

//-------------------------------------------------------------//
const ForceFeedback::SupportedEffectList& ForceFeedback::getSupportedEffects() const
{
	return mSupportedEffects;
}

//-------------------------------------------------------------//
bool ForceFeedback::supportsEffect(Effect::EForce force, Effect::EType type) const
{
	const std::pair<SupportedEffectList::const_iterator, SupportedEffectList::const_iterator> 
		iterRange = mSupportedEffects.equal_range(force);
	SupportedEffectList::const_iterator iter;
	for (iter = iterRange.first; iter != iterRange.second; iter++)
	{
		if ((*iter).second == type)
			return true;
	}

	return false;
}
