/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcAdvancedFace.h"
#include "ifcpp/IFC4/include/IfcBoolean.h"
#include "ifcpp/IFC4/include/IfcFaceBound.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcSurface.h"
#include "ifcpp/IFC4/include/IfcTextureMap.h"

// ENTITY IfcAdvancedFace 
IfcAdvancedFace::IfcAdvancedFace() {}
IfcAdvancedFace::IfcAdvancedFace( int id ) { m_entity_id = id; }
IfcAdvancedFace::~IfcAdvancedFace() {}
shared_ptr<BuildingObject> IfcAdvancedFace::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcAdvancedFace> copy_self( new IfcAdvancedFace() );
	for( size_t ii=0; ii<m_Bounds.size(); ++ii )
	{
		auto item_ii = m_Bounds[ii];
		if( item_ii )
		{
			copy_self->m_Bounds.push_back( dynamic_pointer_cast<IfcFaceBound>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_FaceSurface ) { copy_self->m_FaceSurface = dynamic_pointer_cast<IfcSurface>( m_FaceSurface->getDeepCopy(options) ); }
	if( m_SameSense ) { copy_self->m_SameSense = dynamic_pointer_cast<IfcBoolean>( m_SameSense->getDeepCopy(options) ); }
	return copy_self;
}
void IfcAdvancedFace::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCADVANCEDFACE" << "(";
	writeEntityList( stream, m_Bounds );
	stream << ",";
	if( m_FaceSurface ) { stream << "#" << m_FaceSurface->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcAdvancedFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcAdvancedFace::toString() const { return L"IfcAdvancedFace"; }
void IfcAdvancedFace::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcAdvancedFace, expecting 3, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_Bounds, map );
	readEntityReference( args[1], m_FaceSurface, map );
	m_SameSense = IfcBoolean::createObjectFromSTEP( args[2], map );
}
void IfcAdvancedFace::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcFaceSurface::getAttributes( vec_attributes );
}
void IfcAdvancedFace::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcFaceSurface::getAttributesInverse( vec_attributes_inverse );
}
void IfcAdvancedFace::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcFaceSurface::setInverseCounterparts( ptr_self_entity );
}
void IfcAdvancedFace::unlinkFromInverseCounterparts()
{
	IfcFaceSurface::unlinkFromInverseCounterparts();
}
