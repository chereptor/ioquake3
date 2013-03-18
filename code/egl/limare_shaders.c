/*
 * Copyright 2013 Connor Abbott <cwabbott0@gmail.com>
 * Copyright 2011-2013 Luc Verhaegen <libv@skynet.be>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

/*
 * Set this to 0 if you want to use the binary compiler.
 */
#define OGT_MBS_USE 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <limare.h>

#if OGT_MBS_USE
/*
 * Below are MBS files, generated with Connor's Open GPU Tools:
 * https://gitorious.org/~cwabbott/open-gpu-tools/cwabbotts-open-gpu-tools
 *
 * They replace the dependency on the mali binary compiler, they are freely
 * distributable under the MIT license, and they allow for running Q3A without
 * depending on any binary.
 */

/*
 *
 * Vertex shader for single texture and a color.
 *
 */

/*
 * ESSL code: the same shader as used directly.
 */
#ifdef ESSL_CODE

uniform mat4 uMatrix;

attribute vec4 aPosition;
attribute vec4 aColor;
attribute vec2 aTexCoord0;

varying vec4 vColor;
varying vec2 vTexCoord0;

void main()
{
	gl_Position = uMatrix * aPosition;
	vColor = aColor;
	vTexCoord0 = aTexCoord0;
}

#endif /* ESSL_CODE */

/*
 * OGT IR: generated by ogt, then manually optimised.
 */
#ifdef OGT_IR

uniform highp vec4 gl_mali_ViewportTransform[2];
uniform highp mat4 uMatrix;
const highp vec2 __const1 = vec2(-1.0e10, 1.0e10);

attribute highp vec4 aPosition;
attribute highp vec4 aColor;
attribute highp vec2 aTexCoord0;

varying highp vec4 gl_Position;
varying highp vec4 vColor;
varying highp vec2 vTexCoord0;
varying mediump float gl_PointSize;

block_1:
(def_expr result_x
	(add
		(mul (load_attribute 0.x) (load_uniform 2.x))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.x))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.x))
				(mul (load_attribute 0.w) (load_uniform 5.x))))))

(def_expr result_y
	(add
		(mul (load_attribute 0.x) (load_uniform 2.y))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.y))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.y))
				(mul (load_attribute 0.w) (load_uniform 5.y))))))

(def_expr result_z
	(add
		(mul (load_attribute 0.x) (load_uniform 2.z))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.z))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.z))
				(mul (load_attribute 0.w) (load_uniform 5.z))))))

(def_expr result_w
	(add
		(mul (load_attribute 0.x) (load_uniform 2.w))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.w))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.w))
				(mul (load_attribute 0.w) (load_uniform 5.w))))))

(def_expr gl_pos_inv
	(clamp_const 6 (complex1
		(rcp_impl (expr result_w))
		(complex2 (expr result_w))
		(expr result_w))))

(store_varying 0
	x:
	(add
		(mul (mul (expr result_x) (load_uniform 0.x))
			(expr gl_pos_inv))
		(load_uniform 1.x))
	y:
	(add
        (mul (mul (expr result_y) (load_uniform 0.y))
                (expr gl_pos_inv))
        (load_uniform 1.y))
	z:
	(add
        (mul (mul (expr result_z) (load_uniform 0.z))
                (expr gl_pos_inv))
        (load_uniform 1.z))
	w:
	(expr gl_pos_inv))

(store_varying 1
	x: (mov (load_attribute 1.x))
	y: (mov (load_attribute 1.y))
	z: (mov (load_attribute 1.z))
	w: (mov (load_attribute 1.w)))

(store_varying 2
	x: (mov (load_attribute 2.x))
	y: (mov (load_attribute 2.y)))

#endif /* OGT_IR */

/* This dump was created by running: */
#ifdef SHELL_EXAMPLE
//hexdump -C single_texture_vertex.ogt.mbs | * awk '{ print "\t0x"$5$4$3$2
// ", 0x" $9$8$7$6 ", 0x" $13$12$11$10 ", 0x" $17$16$15$14 ", /* " $18 "*/"}'
#endif

/*
 * Resulting MBS, dumped to unsigned int for direct inclusion. This makes
 * loading faster and pretty foolproof.
 */
static unsigned int
mbs_vertex_single_texture[] = {
	0x3153424d, 0x00000340, 0x52455643, 0x00000338, /* |MBS1@...CVER8...| */
	0x00000002, 0x534e4946, 0x0000000c, 0x00000000, /* |....FINS........| */
	0x00000010, 0x0000000f, 0x494e5553, 0x000000b8, /* |........SUNI....| */
	0x00000003, 0x0000001c, 0x494e5556, 0x00000038, /* |........VUNI8...| */
	0x49525453, 0x0000001c, 0x6d5f6c67, 0x5f696c61, /* |STRI....gl_mali_| */
	0x77656956, 0x74726f70, 0x6e617254, 0x726f6673, /* |ViewportTransfor| */
	0x0000006d, 0x00040100, 0x00020004, 0x03100004, /* |m...............| */
	0x00000000, 0xffff0000, 0x494e5556, 0x00000024, /* |........VUNI$...| */
	0x49525453, 0x00000008, 0x74614d75, 0x00786972, /* |STRI....uMatrix.| */
	0x00040400, 0x00000004, 0x03100010, 0x00000000, /* |................| */
	0xffff0008, 0x494e5556, 0x0000003c, 0x49525453, /* |....VUNI<...STRI| */
	0x0000000c, 0x6f635f5f, 0x3174736e, 0x00000000, /* |....__const1....| */
	0x00020100, 0x00000004, 0x03100004, 0x00000000, /* |................| */
	0xffff0018, 0x494e4956, 0x0000000c, 0x00000002, /* |....VINI........| */
	0xd01502f9, 0x501502f9, 0x54544153, 0x00000084, /* |.......PSATT....| */
	0x00000003, 0x54544156, 0x00000024, 0x49525453, /* |....VATT$...STRI| */
	0x0000000c, 0x736f5061, 0x6f697469, 0x0000006e, /* |....aPosition...| */
	0x00040100, 0x00000004, 0x03100004, 0x00000000, /* |................| */
	0x54544156, 0x00000020, 0x49525453, 0x00000008, /* |VATT ...STRI....| */
	0x6c6f4361, 0x0000726f, 0x00040100, 0x00000004, /* |aColor..........| */
	0x03100004, 0x00040000, 0x54544156, 0x00000024, /* |........VATT$...| */
	0x49525453, 0x0000000c, 0x78655461, 0x726f6f43, /* |STRI....aTexCoor| */
	0x00003064, 0x00020100, 0x00000004, 0x03100004, /* |d0..............| */
	0x00080000, 0x52415653, 0x000000c4, 0x00000004, /* |....SVAR........| */
	0x52415656, 0x00000028, 0x49525453, 0x0000000c, /* |VVAR(...STRI....| */
	0x505f6c67, 0x7469736f, 0x006e6f69, 0x00040100, /* |gl_Position.....| */
	0x00000004, 0x03100004, 0x00000000, 0xffff0000, /* |................| */
	0x52415656, 0x00000024, 0x49525453, 0x00000008, /* |VVAR$...STRI....| */
	0x6c6f4376, 0x0000726f, 0x00040100, 0x00000004, /* |vColor..........| */
	0x03100004, 0x00000000, 0xffff0004, 0x52415656, /* |............VVAR| */
	0x00000028, 0x49525453, 0x0000000c, 0x78655476, /* |(...STRI....vTex| */
	0x726f6f43, 0x00003064, 0x00020100, 0x00000004, /* |Coord0..........| */
	0x03100004, 0x00000000, 0xffff0008, 0x52415656, /* |............VVAR| */
	0x0000002c, 0x49525453, 0x00000010, 0x505f6c67, /* |,...STRI....gl_P| */
	0x746e696f, 0x657a6953, 0x00000000, 0x00010100, /* |ointSize........| */
	0x00000004, 0x02100004, 0x00000000, 0xffff000a, /* |................| */
	0x4e494244, 0x00000100, 0xb3cad6b5, 0x03810ab5, /* |DBIN............| */
	0x0007ff80, 0x000ad500, 0xb3078202, 0x43808ab5, /* |...............C| */
	0x0007ff80, 0x000ad500, 0xb3c801c1, 0x4380cab5, /* |...............C| */
	0x0007fd80, 0x000ad500, 0xb30709a2, 0x43812adb, /* |.............*.C| */
	0x0247ff80, 0x000ae900, 0xb6870f01, 0x43816ad6, /* |..G..........j.C| */
	0x0007ff80, 0x000ad500, 0x9ec68de3, 0x438162d8, /* |.............b.C| */
	0x0247ff80, 0x000ce900, 0x96460e22, 0x43814276, /* |..G.....".F.vB.C| */
	0x0247ff80, 0x000c6900, 0x858b6181, 0x4380c272, /* |..G..i...a..r..C| */
	0x0247ff80, 0x000add00, 0x8c8b65a1, 0x4380c216, /* |..G......e.....C| */
	0x0247ff80, 0x000add00, 0xb4470231, 0x43808b76, /* |..G.....1.G.v..C| */
	0x0147ff80, 0x00094530, 0xc1085a56, 0x03808233, /* |..G.0E..VZ..3...| */
	0x0247ff80, 0x0006ed10, 0xb3074680, 0x43800af6, /* |..G......F.....C| */
	0x0007ff80, 0x000ad500, 0x8c8862b5, 0x038182b5, /* |.........b......| */
	0x0007ff80, 0x000d5700, 0xb0ca6db0, 0x47802ac1, /* |.....W...m...*.G| */
	0xc6408700, 0x00010108, 0x74cbeef2, 0x4b8062d7, /* |..@........t.b.K| */
	0x4a47f300, 0x00008100, 0x64cb42d1, 0x038041b2, /* |..GJ.....B.d.A..| */
	0x40026400, 0x000ad508,				/* |.d.@....| */
};

/*
 *
 * Vertex shader for dual textures and a color.
 *
 */

/*
 * ESSL code: the same shader as used directly.
 */
#ifdef ESSL_CODE

uniform mat4 uMatrix;

attribute vec4 aPosition;
attribute vec4 aColor;
attribute vec2 aTexCoord0;
attribute vec2 aTexCoord1;

varying vec4 vColor;
varying vec2 vTexCoord0;
varying vec2 vTexCoord1;

void main()
{
	gl_Position = uMatrix * aPosition;
	vColor = aColor;
	vTexCoord0 = aTexCoord0;
	vTexCoord1 = aTexCoord1;
}

#endif /* ESSL_CODE */

/*
 * OGT IR: generated by ogt, then manually optimised.
 */
#ifdef OGT_IR

uniform highp vec4 gl_mali_ViewportTransform[2];
uniform highp mat4 uMatrix;
const highp vec2 __const1 = vec2(-1.0e10, 1.0e10);

attribute highp vec4 aPosition;
attribute highp vec4 aColor;
attribute highp vec2 aTexCoord0;
attribute highp vec2 aTexCoord1;

varying highp vec4 gl_Position;
varying highp vec4 vColor;
varying highp vec2 vTexCoord0;
varying highp vec2 vTexCoord1;
varying mediump float gl_PointSize;

block_1:
(def_expr result_x
	(add
		(mul (load_attribute 0.x) (load_uniform 2.x))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.x))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.x))
				(mul (load_attribute 0.w) (load_uniform 5.x))))))

(def_expr result_y
	(add
		(mul (load_attribute 0.x) (load_uniform 2.y))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.y))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.y))
				(mul (load_attribute 0.w) (load_uniform 5.y))))))

(def_expr result_z
	(add
		(mul (load_attribute 0.x) (load_uniform 2.z))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.z))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.z))
				(mul (load_attribute 0.w) (load_uniform 5.z))))))

(def_expr result_w
	(add
		(mul (load_attribute 0.x) (load_uniform 2.w))
		(add
			(mul (load_attribute 0.y) (load_uniform 3.w))
			(add
				(mul (load_attribute 0.z) (load_uniform 4.w))
				(mul (load_attribute 0.w) (load_uniform 5.w))))))

(def_expr gl_pos_inv
	(clamp_const 6 (complex1
		(rcp_impl (expr result_w))
		(complex2 (expr result_w))
		(expr result_w))))

(store_varying 0
	x:
	(add
		(mul (mul (expr result_x) (load_uniform 0.x))
			(expr gl_pos_inv))
		(load_uniform 1.x))
	y:
	(add
        (mul (mul (expr result_y) (load_uniform 0.y))
                (expr gl_pos_inv))
        (load_uniform 1.y))
	z:
	(add
        (mul (mul (expr result_z) (load_uniform 0.z))
                (expr gl_pos_inv))
        (load_uniform 1.z))
	w:
	(expr gl_pos_inv))

(store_varying 1
	x: (mov (load_attribute 1.x))
	y: (mov (load_attribute 1.y))
	z: (mov (load_attribute 1.z))
	w: (mov (load_attribute 1.w)))

(store_varying 2
	x: (mov (load_attribute 2.x))
	y: (mov (load_attribute 2.y))
	z: (mov (load_attribute 3.x))
	w: (mov (load_attribute 3.y)))

#endif /* OGT_IR */

/*
 * Resulting MBS, dumped to unsigned int for direct inclusion. This makes
 * loading faster and pretty foolproof.
 */
static unsigned int
mbs_vertex_dual_texture[] = {
	0x3153424d, 0x0000039c, 0x52455643, 0x00000394, /* |MBS1....CVER....| */
	0x00000002, 0x534e4946, 0x0000000c, 0x00000000, /* |....FINS........| */
	0x00000010, 0x0000000e, 0x494e5553, 0x000000b8, /* |........SUNI....| */
	0x00000003, 0x0000001c, 0x494e5556, 0x00000038, /* |........VUNI8...| */
	0x49525453, 0x0000001c, 0x6d5f6c67, 0x5f696c61, /* |STRI....gl_mali_| */
	0x77656956, 0x74726f70, 0x6e617254, 0x726f6673, /* |ViewportTransfor| */
	0x0000006d, 0x00040100, 0x00020004, 0x03100004, /* |m...............| */
	0x00000000, 0xffff0000, 0x494e5556, 0x00000024, /* |........VUNI$...| */
	0x49525453, 0x00000008, 0x74614d75, 0x00786972, /* |STRI....uMatrix.| */
	0x00040400, 0x00000004, 0x03100010, 0x00000000, /* |................| */
	0xffff0008, 0x494e5556, 0x0000003c, 0x49525453, /* |....VUNI<...STRI| */
	0x0000000c, 0x6f635f5f, 0x3174736e, 0x00000000, /* |....__const1....| */
	0x00020100, 0x00000004, 0x03100004, 0x00000000, /* |................| */
	0xffff0018, 0x494e4956, 0x0000000c, 0x00000002, /* |....VINI........| */
	0xd01502f9, 0x501502f9, 0x54544153, 0x000000b0, /* |.......PSATT....| */
	0x00000004, 0x54544156, 0x00000024, 0x49525453, /* |....VATT$...STRI| */
	0x0000000c, 0x736f5061, 0x6f697469, 0x0000006e, /* |....aPosition...| */
	0x00040100, 0x00000004, 0x03100004, 0x00000000, /* |................| */
	0x54544156, 0x00000020, 0x49525453, 0x00000008, /* |VATT ...STRI....| */
	0x6c6f4361, 0x0000726f, 0x00040100, 0x00000004, /* |aColor..........| */
	0x03100004, 0x00040000, 0x54544156, 0x00000024, /* |........VATT$...| */
	0x49525453, 0x0000000c, 0x78655461, 0x726f6f43, /* |STRI....aTexCoor| */
	0x00003064, 0x00020100, 0x00000004, 0x03100004, /* |d0..............| */
	0x00080000, 0x54544156, 0x00000024, 0x49525453, /* |....VATT$...STRI| */
	0x0000000c, 0x78655461, 0x726f6f43, 0x00003164, /* |....aTexCoord1..| */
	0x00020100, 0x00000004, 0x03100004, 0x000c0000, /* |................| */
	0x52415653, 0x000000f4, 0x00000005, 0x52415656, /* |SVAR........VVAR| */
	0x00000028, 0x49525453, 0x0000000c, 0x505f6c67, /* |(...STRI....gl_P| */
	0x7469736f, 0x006e6f69, 0x00040100, 0x00000004, /* |osition.........| */
	0x03100004, 0x00000000, 0xffff0000, 0x52415656, /* |............VVAR| */
	0x00000024, 0x49525453, 0x00000008, 0x6c6f4376, /* |$...STRI....vCol| */
	0x0000726f, 0x00040100, 0x00000004, 0x03100004, /* |or..............| */
	0x00000000, 0xffff0004, 0x52415656, 0x00000028, /* |........VVAR(...| */
	0x49525453, 0x0000000c, 0x78655476, 0x726f6f43, /* |STRI....vTexCoor| */
	0x00003064, 0x00020100, 0x00000004, 0x03100004, /* |d0..............| */
	0x00000000, 0xffff0008, 0x52415656, 0x00000028, /* |........VVAR(...| */
	0x49525453, 0x0000000c, 0x78655476, 0x726f6f43, /* |STRI....vTexCoor| */
	0x00003164, 0x00020100, 0x00000004, 0x03100004, /* |d1..............| */
	0x00000000, 0xffff000a, 0x52415656, 0x0000002c, /* |........VVAR,...| */
	0x49525453, 0x00000010, 0x505f6c67, 0x746e696f, /* |STRI....gl_Point| */
	0x657a6953, 0x00000000, 0x00010100, 0x00000004, /* |Size............| */
	0x02100004, 0x00000000, 0xffff000c, 0x4e494244, /* |............DBIN| */
	0x00000100, 0xb3cb0ac1, 0x47812ac3, 0xc6416b00, /* |.........*.G.kA.| */
	0x000a8108, 0xad478202, 0x438082b5, 0x0007fd80, /* |......G....C....| */
	0x000ad500, 0xb3c685c1, 0x4380ead2, 0x0007e780, /* |...........C....| */
	0x000ad500, 0xb34805c2, 0x43812acc, 0x0007ff80, /* |......H..*.C....| */
	0x000ad500, 0xb6c70de3, 0x43816ada, 0x0007ff80, /* |.........j.C....| */
	0x000ad500, 0x9e868f02, 0x438162d9, 0x0247ff80, /* |.........b.C..G.| */
	0x0008ed00, 0xd1460e22, 0x43814272, 0x0247ff80, /* |....".F.rB.C..G.| */
	0x000c5900, 0x858b6181, 0x4380c272, 0x0247ff80, /* |.Y...a..r..C..G.| */
	0x000add00, 0x8c8b65c0, 0x43808204, 0x0247ff80, /* |.....e.....C..G.| */
	0x000b5d00, 0xb4460231, 0x43808b74, 0x0147ff80, /* |.]..1.F.t..C..G.| */
	0x000b4530, 0xc4c85a56, 0x0380823a, 0x0247ff80, /* |0E..VZ..:.....G.| */
	0x0006ed10, 0xb3074680, 0x43800af6, 0x0007ff80, /* |.....F.....C....| */
	0x000ad500, 0x8c8862b5, 0x4f8182b5, 0x0007ff80, /* |.....b.....O....| */
	0x000d5700, 0xb04a6db0, 0x4b802adc, 0x4a442300, /* |.W...mJ..*.K.#DJ| */
	0x000e8109, 0x74cbeef2, 0x038062d7, 0x0007ff80, /* |.......t.b......| */
	0x000ad500, 0x64cb42d1, 0x038041b2, 0x40026400, /* |.....B.d.A...d.@| */
	0x000ad508,					/* |....| */
};

/*
 *
 * Fragment shader for a single texture and a color.
 *
 */

/*
 * ESSL code: the same shader as used directly.
 */
#ifdef ESSL_CODE

precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord0;

uniform sampler2D uTexture0;

void main()
{
	gl_FragColor =
		clamp(vColor * texture2D(uTexture0, vTexCoord0), 0.0, 1.0);
}

#endif /* ESSL_CODE */

/*
 * IR: written directly.
 */
#ifdef OGT_IR

varying mediump vec4 vColor;
varying mediump vec2 vTexCoord0;

uniform lowp sampler2D uTexture0;

$0 = varying[0];

varying[1].xy,
^texture = sampler2D(0),
$0 = clamp($0 * ^texture, 0.0, 1.0),
sync,
stop;
#endif /* OGT_IR */

static unsigned int
mbs_fragment_single_texture[] = {
	0x3153424d, 0x0000010c, 0x41524643, 0x00000104, /* |MBS1....CFRA....| */
	0x00000005, 0x41545346, 0x00000008, 0x00000001, /* |....FSTA........| */
	0x00000001, 0x53494446, 0x00000004, 0x00000000, /* |....FDIS........| */
	0x55554246, 0x00000008, 0x00000100, 0x00000000, /* |FBUU............| */
	0x494e5553, 0x00000038, 0x00000001, 0x00000004, /* |SUNI8...........| */
	0x494e5556, 0x00000028, 0x49525453, 0x0000000c, /* |VUNI(...STRI....| */
	0x78655475, 0x65727574, 0x00000030, 0x00020500, /* |uTexture0.......| */
	0x00000001, 0x01100001, 0x00000000, 0xffff0000, /* |................| */
	0x52415653, 0x00000060, 0x00000002, 0x52415656, /* |SVAR`.......VVAR| */
	0x00000024, 0x49525453, 0x00000008, 0x6c6f4376, /* |$...STRI....vCol| */
	0x0000726f, 0x00040100, 0x00000004, 0x02100004, /* |or..............| */
	0x00000000, 0xffff0000, 0x52415656, 0x00000028, /* |........VVAR(...| */
	0x49525453, 0x0000000c, 0x78655476, 0x726f6f43, /* |STRI....vTexCoor| */
	0x00003064, 0x00020100, 0x00000002, 0x02100002, /* |d0..............| */
	0x00000000, 0xffff0004, 0x4e494244, 0x00000024, /* |........DBIN$...| */
	0x02300083, 0xf0003c60, 0x00000000, 0x000005e6, /* |..0.`<..........| */
	0x1f083c20, 0x00000000, 0x39001000, 0x03900e4e, /* | <.........9N...| */
	0x0000001f,					/* |....| */
};

/*
 *
 * Fragment shader for dual textures and a color.
 *
 */

/*
 * ESSL code: the same shader as used directly.
 */
#ifdef ESSL_CODE

precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord0;
varying vec2 vTexCoord1;

uniform sampler2D uTexture0;
uniform sampler2D uTexture1;

void main()
{
	gl_FragColor = clamp(vColor * texture2D(uTexture0, vTexCoord0) *
			     texture2D(uTexture1, vTexCoord1), 0.0, 1.0);
}

#endif /* ESSL_CODE */

/*
 * IR: written directly.
 */
#ifdef OGT_IR

varying mediump vec4 vColor;
varying mediump vec2 vTexCoord0;
varying mediump vec2 vTexCoord1;

uniform lowp sampler2D uTexture0;
uniform lowp sampler2D uTexture1;

$0 = varying[0];

varying[1].xy,
^texture = sampler2D(0),
$0 = $0 * ^texture,
sync;

varying[1].zw,
^texture = sampler2D(1),
$0 = clamp($0 * ^texture, 0.0, 1.0),
sync,
stop;

#endif /* OGT_IR */

static unsigned int
mbs_fragment_dual_texture[] = {
	0x3153424d, 0x00000184, 0x41524643, 0x0000017c, /* |MBS1....CFRA|...| */
	0x00000005, 0x41545346, 0x00000008, 0x00000001, /* |....FSTA........| */
	0x00000001, 0x53494446, 0x00000004, 0x00000000, /* |....FDIS........| */
	0x55554246, 0x00000008, 0x00000100, 0x00000000, /* |FBUU............| */
	0x494e5553, 0x00000068, 0x00000002, 0x00000004, /* |SUNIh...........| */
	0x494e5556, 0x00000028, 0x49525453, 0x0000000c, /* |VUNI(...STRI....| */
	0x78655475, 0x65727574, 0x00000030, 0x00020500, /* |uTexture0.......| */
	0x00000001, 0x01100001, 0x00000000, 0xffff0000, /* |................| */
	0x494e5556, 0x00000028, 0x49525453, 0x0000000c, /* |VUNI(...STRI....| */
	0x78655475, 0x65727574, 0x00000031, 0x00020500, /* |uTexture1.......| */
	0x00000001, 0x01100001, 0x00000000, 0xffff0001, /* |................| */
	0x52415653, 0x00000090, 0x00000003, 0x52415656, /* |SVAR........VVAR| */
	0x00000024, 0x49525453, 0x00000008, 0x6c6f4376, /* |$...STRI....vCol| */
	0x0000726f, 0x00040100, 0x00000004, 0x02100004, /* |or..............| */
	0x00000000, 0xffff0000, 0x52415656, 0x00000028, /* |........VVAR(...| */
	0x49525453, 0x0000000c, 0x78655476, 0x726f6f43, /* |STRI....vTexCoor| */
	0x00003064, 0x00020100, 0x00000002, 0x02100002, /* |d0..............| */
	0x00000000, 0xffff0004, 0x52415656, 0x00000028, /* |........VVAR(...| */
	0x49525453, 0x0000000c, 0x78655476, 0x726f6f43, /* |STRI....vTexCoor| */
	0x00003164, 0x00020100, 0x00000002, 0x02100002, /* |d1..............| */
	0x00000000, 0xffff0005, 0x4e494244, 0x0000003c, /* |........DBIN<...| */
	0x02300083, 0xf0003c60, 0x00000000, 0x023005c6, /* |..0.`<........0.| */
	0x7f083c20, 0x00000000, 0x39001000, 0x03900e4e, /* | <.........9N...| */
	0x0000000f, 0x000005e6, 0x7f0c3c20, 0x00000000, /* |........ <......| */
	0x39001001, 0x03900e4e, 0x0000001f,		/* |...9N.......| */
};

int
program_single_texture_load(struct limare_state *state, unsigned int *program)
{
	int ret;

	*program = limare_program_new(state);

	ret = vertex_shader_attach_mbs_stream(state, *program,
					      mbs_vertex_single_texture,
					      sizeof(mbs_vertex_single_texture)
					      );
	if (ret)
		return ret;

	ret = fragment_shader_attach_mbs_stream(state, *program,
						mbs_fragment_single_texture,
						sizeof(mbs_fragment_single_texture)
						);
	if (ret)
		return ret;

	ret = limare_link(state);
	if (ret)
		return ret;

	return 0;
}

int
program_dual_texture_load(struct limare_state *state, unsigned int *program)
{
	int ret;

	*program = limare_program_new(state);

	ret = vertex_shader_attach_mbs_stream(state, *program,
					      mbs_vertex_dual_texture,
					      sizeof(mbs_vertex_dual_texture)
					      );
	if (ret)
		return ret;

	ret = fragment_shader_attach_mbs_stream(state, *program,
						mbs_fragment_dual_texture,
						sizeof(mbs_fragment_dual_texture)
						);
	if (ret)
		return ret;

	ret = limare_link(state);
	if (ret)
		return ret;

	return 0;
}


#else /* OGT_MBS_USE */

int
program_single_texture_load(struct limare_state *state, unsigned int *program)
{
	static const char* vertex_source =
		"uniform mat4 uMatrix;\n"
		"\n"
		"attribute vec4 aPosition;\n"
		"attribute vec4 aColor;\n"
		"attribute vec2 aTexCoord0;\n"
		"\n"
		"varying vec4 vColor;\n"
		"varying vec2 vTexCoord0;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = uMatrix * aPosition;\n"
		"    vColor = aColor;\n"
		"    vTexCoord0 = aTexCoord0;\n"
		"}\n";

	static const char* fragment_source =
		"precision mediump float;\n"
		"\n"
		"varying vec4 vColor;\n"
		"varying vec2 vTexCoord0;\n"
		"\n"
		"uniform sampler2D uTexture0;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = clamp(vColor * texture2D(uTexture0,"
		" vTexCoord0), 0.0, 1.0);\n"
		"}\n";
	int ret;

	*program = limare_program_new(state);

	vertex_shader_attach(state, *program, vertex_source);

	fragment_shader_attach(state, *program, fragment_source);

	ret = limare_link(state);
	if (ret)
		return ret;

	return 0;
}

int
program_dual_texture_load(struct limare_state *state, unsigned int *program)
{
	static const char* vertex_source =
		"uniform mat4 uMatrix;\n"
		"\n"
		"attribute vec4 aPosition;\n"
		"attribute vec4 aColor;\n"
		"attribute vec2 aTexCoord0;\n"
		"attribute vec2 aTexCoord1;\n"
		"\n"
		"varying vec4 vColor;\n"
		"varying vec2 vTexCoord0;\n"
		"varying vec2 vTexCoord1;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = uMatrix * aPosition;\n"
		"    vColor = aColor;\n"
		"    vTexCoord0 = aTexCoord0;\n"
		"    vTexCoord1 = aTexCoord1;\n"
		"}\n";

	static const char* fragment_source =
		"precision mediump float;\n"
		"\n"
		"varying vec4 vColor;\n"
		"varying vec2 vTexCoord0;\n"
		"varying vec2 vTexCoord1;\n"
		"\n"
		"uniform sampler2D uTexture0;\n"
		"uniform sampler2D uTexture1;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = clamp(vColor * "
		"texture2D(uTexture0, vTexCoord0) *"
		"texture2D(uTexture1, vTexCoord1),"
		" 0.0, 1.0);\n"
		"}\n";
	int ret;

	*program = limare_program_new(state);

	vertex_shader_attach(state, *program, vertex_source);

	fragment_shader_attach(state, *program, fragment_source);

	ret = limare_link(state);
	if (ret)
		return ret;

	return 0;
}
#endif /* OGT_MBS_USE */
