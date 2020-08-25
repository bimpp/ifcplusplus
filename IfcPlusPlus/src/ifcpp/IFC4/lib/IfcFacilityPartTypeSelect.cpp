/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <map>
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/IFC4/include/IfcBridgePartTypeEnum.h"
#include "ifcpp/IFC4/include/IfcFacilityPartCommonTypeEnum.h"
#include "ifcpp/IFC4/include/IfcMarinePartTypeEnum.h"
#include "ifcpp/IFC4/include/IfcRailwayPartTypeEnum.h"
#include "ifcpp/IFC4/include/IfcRoadPartTypeEnum.h"
#include "ifcpp/IFC4/include/IfcFacilityPartTypeSelect.h"

// TYPE IfcFacilityPartTypeSelect = SELECT	(IfcBridgePartTypeEnum	,IfcFacilityPartCommonTypeEnum	,IfcMarinePartTypeEnum	,IfcRailwayPartTypeEnum	,IfcRoadPartTypeEnum);
shared_ptr<IfcFacilityPartTypeSelect> IfcFacilityPartTypeSelect::createObjectFromSTEP( const std::wstring& arg, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	if( arg.empty() ){ return shared_ptr<IfcFacilityPartTypeSelect>(); }
	if( arg.compare(L"$")==0 )
	{
		return shared_ptr<IfcFacilityPartTypeSelect>();
	}
	if( arg.compare(L"*")==0 )
	{
		return shared_ptr<IfcFacilityPartTypeSelect>();
	}
	shared_ptr<IfcFacilityPartTypeSelect> result_object;
	readSelectType( arg, result_object, map );
	return result_object;
}