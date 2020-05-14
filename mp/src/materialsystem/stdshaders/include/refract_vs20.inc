// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH

#ifndef REFRACT_VS20_H
#define REFRACT_VS20_H

#include "shaderapi/ishaderapi.h"
#include "shaderapi/ishadershadow.h"
#include "materialsystem/imaterialvar.h"

class refract_vs20_Static_Index
{
	int m_nMODEL : 3;
	int m_nCOLORMODULATE : 3;
#ifdef _DEBUG
	bool m_bMODEL : 1;
	bool m_bCOLORMODULATE : 1;
#endif	// _DEBUG
public:
	void SetMODEL( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nMODEL = i;
#ifdef _DEBUG
		m_bMODEL = true;
#endif	// _DEBUG
	}

	void SetCOLORMODULATE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCOLORMODULATE = i;
#ifdef _DEBUG
		m_bCOLORMODULATE = true;
#endif	// _DEBUG
	}

	refract_vs20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nMODEL = 0;
		m_nCOLORMODULATE = 0;
#ifdef _DEBUG
		m_bMODEL = false;
		m_bCOLORMODULATE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bMODEL && m_bCOLORMODULATE );
		return ( 4 * m_nMODEL ) + ( 8 * m_nCOLORMODULATE ) + 0;
	}
};

#define shaderStaticTest_refract_vs20 vsh_forgot_to_set_static_MODEL + vsh_forgot_to_set_static_COLORMODULATE


class refract_vs20_Dynamic_Index
{
	int m_nCOMPRESSED_VERTS : 3;
	int m_nSKINNING : 3;
#ifdef _DEBUG
	bool m_bCOMPRESSED_VERTS : 1;
	bool m_bSKINNING : 1;
#endif	// _DEBUG
public:
	void SetCOMPRESSED_VERTS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCOMPRESSED_VERTS = i;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = true;
#endif	// _DEBUG
	}

	void SetSKINNING( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSKINNING = i;
#ifdef _DEBUG
		m_bSKINNING = true;
#endif	// _DEBUG
	}

	refract_vs20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nCOMPRESSED_VERTS = 0;
		m_nSKINNING = 0;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = false;
		m_bSKINNING = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bCOMPRESSED_VERTS && m_bSKINNING );
		return ( 1 * m_nCOMPRESSED_VERTS ) + ( 2 * m_nSKINNING ) + 0;
	}
};

#define shaderDynamicTest_refract_vs20 vsh_forgot_to_set_dynamic_COMPRESSED_VERTS + vsh_forgot_to_set_dynamic_SKINNING


#endif	// REFRACT_VS20_H