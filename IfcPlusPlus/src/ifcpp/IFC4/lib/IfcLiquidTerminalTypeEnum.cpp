/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4/include/IfcLiquidTerminalTypeEnum.h"

// TYPE IfcLiquidTerminalTypeEnum = ENUMERATION OF	(LOADINGARM	,HOSEREEL	,USERDEFINED	,NOTDEFINED);
shared_ptr<BuildingObject> IfcLiquidTerminalTypeEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcLiquidTerminalTypeEnum> copy_self( new IfcLiquidTerminalTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcLiquidTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCLIQUIDTERMINALTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_LOADINGARM:	stream << ".LOADINGARM."; break;
		case ENUM_HOSEREEL:	stream << ".HOSEREEL."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
const std::wstring IfcLiquidTerminalTypeEnum::toString() const
{
	switch( m_enum ) 
	{
		case ENUM_LOADINGARM:	return L"LOADINGARM";
		case ENUM_HOSEREEL:	return L"HOSEREEL";
		case ENUM_USERDEFINED:	return L"USERDEFINED";
		case ENUM_NOTDEFINED:	return L"NOTDEFINED";
	}
	return L"";
}
shared_ptr<IfcLiquidTerminalTypeEnum> IfcLiquidTerminalTypeEnum::createObjectFromSTEP( const std::wstring& arg, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcLiquidTerminalTypeEnum>(); }
	if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcLiquidTerminalTypeEnum>(); }
	shared_ptr<IfcLiquidTerminalTypeEnum> type_object( new IfcLiquidTerminalTypeEnum() );
	if( std_iequal( arg, L".LOADINGARM." ) )
	{
		type_object->m_enum = IfcLiquidTerminalTypeEnum::ENUM_LOADINGARM;
	}
	else if( std_iequal( arg, L".HOSEREEL." ) )
	{
		type_object->m_enum = IfcLiquidTerminalTypeEnum::ENUM_HOSEREEL;
	}
	else if( std_iequal( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcLiquidTerminalTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcLiquidTerminalTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}