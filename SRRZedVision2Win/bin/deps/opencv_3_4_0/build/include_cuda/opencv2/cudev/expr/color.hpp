/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#pragma once

#ifndef OPENCV_CUDEV_EXPR_COLOR_HPP
#define OPENCV_CUDEV_EXPR_COLOR_HPP

#include "../common.hpp"
#include "../ptr2d/traits.hpp"
#include "../ptr2d/transform.hpp"
#include "../functional/color_cvt.hpp"
#include "expr.hpp"

namespace cv { namespace cudev {

//! @addtogroup cudev
//! @{

#define CV_CUDEV_EXPR_CVTCOLOR_INST(name) \
    template <class SrcPtr> \
    __host__ Expr<UnaryTransformPtrSz<typename PtrTraits<SrcPtr>::ptr_type, name ## _func<typename VecTraits<typename PtrTraits<SrcPtr>::value_type>::elem_type> > > \
    name ## _(const SrcPtr& src) \
    { \
        return makeExpr(transformPtr(src, name ## _func<typename VecTraits<typename PtrTraits<SrcPtr>::value_type>::elem_type>())); \
    }

CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_RGBA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_GRAY)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_GRAY)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_GRAY)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_GRAY)

CV_CUDEV_EXPR_CVTCOLOR_INST(GRAY_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(GRAY_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_YUV)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_YUV)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_YUV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_YUV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_YUV)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_YUV)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_YUV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_YUV4)

CV_CUDEV_EXPR_CVTCOLOR_INST(YUV_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(YUV4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_YCrCb)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_YCrCb)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_YCrCb4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_YCrCb4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_YCrCb)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_YCrCb)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_YCrCb4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_YCrCb4)

CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(YCrCb4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_XYZ)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_XYZ)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_XYZ4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_XYZ4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_XYZ)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_XYZ)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_XYZ4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_XYZ4)

CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(XYZ4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HSV)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HSV)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HSV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HSV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HSV)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HSV)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HSV4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HSV4)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HSV_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HSV_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HSV4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HSV4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HSV_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HSV_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HSV4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HSV4_FULL)

CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_RGB_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_RGBA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_RGB_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_RGBA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_BGR_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV_to_BGRA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_BGR_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HSV4_to_BGRA_FULL)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HLS)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HLS)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HLS4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HLS4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HLS)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HLS)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HLS4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HLS4)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HLS_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HLS_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_HLS4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_HLS4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HLS_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HLS_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_HLS4_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_HLS4_FULL)

CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_RGB_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_RGBA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_RGB_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_RGBA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_BGR_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS_to_BGRA_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_BGR_FULL)
CV_CUDEV_EXPR_CVTCOLOR_INST(HLS4_to_BGRA_FULL)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_Lab4)

CV_CUDEV_EXPR_CVTCOLOR_INST(LRGB_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGBA_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGB_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGBA_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGR_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGRA_to_Lab)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGR_to_Lab4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGRA_to_Lab4)

CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_LRGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_LRGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_LRGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_LRGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_LBGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_LBGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab_to_LBGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Lab4_to_LBGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGB_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(RGBA_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGR_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(BGRA_to_Luv4)

CV_CUDEV_EXPR_CVTCOLOR_INST(LRGB_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGBA_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGB_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LRGBA_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGR_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGRA_to_Luv)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGR_to_Luv4)
CV_CUDEV_EXPR_CVTCOLOR_INST(LBGRA_to_Luv4)

CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_RGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_RGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_BGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_BGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_BGRA)

CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_LRGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_LRGB)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_LRGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_LRGBA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_LBGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_LBGR)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv_to_LBGRA)
CV_CUDEV_EXPR_CVTCOLOR_INST(Luv4_to_LBGRA)

#undef CV_CUDEV_EXPR_CVTCOLOR_INST

//! @}

}}

#endif
