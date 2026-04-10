/************************************************
 * Author: Khaled Elwan
 * Date: 2026-04-10  
 * Description: This file contains the standard data types definitions for the project.
 * version: 1.0
 ************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H 

/**< Unsigned integer types */
typedef unsigned char                        u8;           /**< 8-bit unsigned integer type */
typedef unsigned short                       u16;                      /**< 16-bit unsigned integer type */
typedef unsigned int                         u32;          /**< 32-bit unsigned integer type */
typedef unsigned long long                   u64;          /**< 64-bit unsigned integer type */

/**< Signed integer types */
typedef signed char                          s8;            /**< 8-bit signed integer type */
typedef signed short                         s16;           /**< 16-bit signed integer type */
typedef signed int                           s32;           /**< 32-bit signed integer type */
typedef signed long long                     s64;           /**< 64-bit signed integer type */

/**< Floating-point types */
typedef float                                f32;            /**< Single-precision floating-point type */
typedef double                               f64;            /**< Double-precision floating-point type */
typedef long double                          f96;            /**< Extended-precision floating-point type */

typedef u8                                   Std_ReturnType;


 
#define E_OK                            ((Std_ReturnType)0)
#define E_NOT_OK                        ((Std_ReturnType)1)
 /**< Standard return type, typically used for function return values */
#endif /* STD_TYPES_H */