// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//


#ifndef BOOST_RANGE_DETAIL_SIZE_HPP
#define BOOST_RANGE_DETAIL_SIZE_HPP

#include <boost/range/detail/implementation_help.hpp>
#include <boost/range/detail/size_type.hpp>
#include <boost/range/detail/common.hpp>
#include <iterator>

namespace boost 
{
    namespace range_detail
    {
        template< typename T >
        struct collection_size;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct collection_size<std_container_>
        {
            template< typename C >
            static BOOST_CT_DEDUCED_TYPENAME C::size_type fun( const C& c )
            {
                return c.size();
            };
        };
                    
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct collection_size<std_pair_>
        {
            template< typename P >
            static BOOST_CT_DEDUCED_TYPENAME size_type_of<P>::type fun( const P& p )
            {
                return std::distance( p.first, p.second );
            }
        };
 
        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct collection_size<array_>
        {
            template< typename T, std::size_t sz >
            static std::size_t fun( T BOOST_ARRAY_REF[sz] )
            {
                return sz;
            }
        };
        
        template<>
        struct collection_size<char_array_>
        {
            template< typename T, std::size_t sz >
            static std::size_t fun( T BOOST_ARRAY_REF[sz] )
            {
                return boost::range_detail::array_size( array );
            }
        };
        
        template<>
        struct collection_size<wchar_t_array_>
        {
            template< typename T, std::size_t sz >
            static std::size_t fun( T BOOST_ARRAY_REF[sz] )
            {
                return boost::range_detail::array_size( array );
            }
        };

        //////////////////////////////////////////////////////////////////////
        // string
        //////////////////////////////////////////////////////////////////////

        template<>
        struct collection_size<char_ptr_>
        {
            static std::size_t fun( const char* s )
            {
                return boost::range_detail::str_size( s );
            }
        };

        template<>
        struct collection_size<const_char_ptr_>
        {
            static std::size_t fun( const char* s )
            {
                return boost::range_detail::str_size( s );
            }
        };
        
        template<>
        struct collection_size<wchar_t_ptr_>
        {
            static std::size_t fun( const wchar_t* s )
            {
                return boost::range_detail::str_size( s );
            }
        };

        template<>
        struct collection_size<const_wchar_t_ptr_>
        {
            static std::size_t fun( const wchar_t* s )
            {
                return boost::range_detail::str_size( s );
            }
        };
  
    } // namespace 'range_detail'
    

    template< typename C >
    BOOST_CT_DEDUCED_TYPENAME size_type_of<C>::type 
    size( const C& c )
    {
        return range_detail::collection_size<  BOOST_CT_DEDUCED_TYPENAME range_detail::collection<C>::type >::fun( c );
    }
    
} // namespace 'boost'


#endif
