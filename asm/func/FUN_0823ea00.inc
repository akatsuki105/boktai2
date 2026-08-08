	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r3, _0823ED74 @ =0x00000000
	ldr r2, _0823ED70 @ =0x40E92B10
	bl __subdf3
	ldr r2, _0823ED78 @ =0x3F4845C7
	ldr r3, _0823ED7C @ =0x0994535F
	bl __adddf3
	ldr r2, _0823ED80 @ =0x40E1D5A0
	ldr r3, _0823ED84 @ =0x00000000
	bl __divdf3
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0823ED88 @ =0x411D5FCF
	ldr r3, _0823ED8C @ =0x863F1412
	bl __muldf3
	ldr r2, _0823ED90 @ =0x406B4A21
	ldr r3, _0823ED94 @ =0x9652BD3C
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823ED98 @ =0x3F589374
	ldr r3, _0823ED9C @ =0xBC6A7EFA
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDA0 @ =0x411D203B
	ldr r3, _0823EDA4 @ =0x78D4FDF4
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EDA8 @ =0x40467B43
	ldr r3, _0823EDAC @ =0x95810625
	bl __adddf3
	ldr r4, _0823EDB0 @ =0x3F91DF46
	ldr r5, _0823EDB4 @ =0xA2529D34
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EDB8 @ =0x401927BB
	ldr r3, _0823EDBC @ =0x2FEC56D6
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDC0 @ =0x41193A5D
	ldr r3, _0823EDC4 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EDC8 @ =0x40257AE1
	ldr r3, _0823EDCC @ =0x47AE147B
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EDD0 @ =0x3FF4624D
	ldr r3, _0823EDD4 @ =0xD2F1A9FC
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDD8 @ =0x412B2D4C
	ldr r3, _0823EDDC @ =0x70A3D70A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EDE0 @ =0x40623666
	ldr r3, _0823EDE4 @ =0x66666666
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EDE8 @ =0x3FE510CB
	ldr r3, _0823EDEC @ =0x295E9E1B
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDF0 @ =0x412D203B
	ldr r3, _0823EDF4 @ =0x7AE147AE
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EDF8 @ =0x40667DC2
	ldr r3, _0823EDFC @ =0x8F5C28F6
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE00 @ =0x3FCB573E
	ldr r3, _0823EE04 @ =0xAB367A10
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE08 @ =0x40E193E1
	ldr r3, _0823EE0C @ =0x9999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE10 @ =0x4055E1EB
	ldr r3, _0823EE14 @ =0x851EB852
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE18 @ =0x3FC7B15B
	ldr r3, _0823EE1C @ =0x573EAB36
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE20 @ =0x412D7E08
	ldr r3, _0823EE24 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE28 @ =0x40714800
	ldr r3, _0823EE2C @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE30 @ =0x3FBD4951
	ldr r3, _0823EE34 @ =0x82A9930C
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE38 @ =0x40EF2EF0
	ldr r3, _0823EE3C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE40 @ =0x405F0CCC
	ldr r3, _0823EE44 @ =0xCCCCCCCD
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE48 @ =0x3FAE1B08
	ldr r3, _0823EE4C @ =0x9A027525
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE50 @ =0x411707E1
	ldr r3, _0823EE54 @ =0x33333333
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE58 @ =0x402A6666
	ldr r3, _0823EE5C @ =0x66666666
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE60 @ =0x3FAD3C36
	ldr r3, _0823EE64 @ =0x113404EA
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE68 @ =0x4134DEB5
	ldr r3, _0823EE6C @ =0x1999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE70 @ =0x40718B33
	ldr r3, _0823EE74 @ =0x33333333
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE78 @ =0x3FAB4A23
	ldr r3, _0823EE7C @ =0x39C0EBEE
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE80 @ =0x412A140E
	ldr r3, _0823EE84 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EE88 @ =0x40628666
	ldr r3, _0823EE8C @ =0x66666666
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EE90 @ =0x3FA77318
	ldr r3, _0823EE94 @ =0xFC504817
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE98 @ =0x411AEDBF
	ldr r3, _0823EE9C @ =0x33333333
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EEA0 @ =0x4047B333
	ldr r3, _0823EEA4 @ =0x33333333
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EEA8 @ =0x3FA4F0D8
	ldr r3, _0823EEAC @ =0x44D013A9
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEB0 @ =0x411B2D4C
	ldr r3, _0823EEB4 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EEB8 @ =0x403BE666
	ldr r3, _0823EEBC @ =0x66666666
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EEC0 @ =0x3FA1C432
	ldr r3, _0823EEC4 @ =0xCA57A787
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEC8 @ =0x411F52B7
	ldr r3, _0823EECC @ =0x9999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EED0 @ =0x406BD000
	ldr r3, _0823EED4 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EED8 @ =0x3F9F212D
	ldr r3, _0823EEDC @ =0x77318FC5
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEE0 @ =0x40F285E0
	ldr r3, _0823EEE4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823EEE8 @ =0x40448000
	ldr r3, _0823EEEC @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823EEF0 @ =0x3F8F8A09
	ldr r3, _0823EEF4 @ =0x02DE00D2
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	b _0823EEF8
	.align 2, 0
_0823ED70: .4byte 0x40E92B10
_0823ED74: .4byte 0x00000000
_0823ED78: .4byte 0x3F4845C7
_0823ED7C: .4byte 0x0994535F
_0823ED80: .4byte 0x40E1D5A0
_0823ED84: .4byte 0x00000000
_0823ED88: .4byte 0x411D5FCF
_0823ED8C: .4byte 0x863F1412
_0823ED90: .4byte 0x406B4A21
_0823ED94: .4byte 0x9652BD3C
_0823ED98: .4byte 0x3F589374
_0823ED9C: .4byte 0xBC6A7EFA
_0823EDA0: .4byte 0x411D203B
_0823EDA4: .4byte 0x78D4FDF4
_0823EDA8: .4byte 0x40467B43
_0823EDAC: .4byte 0x95810625
_0823EDB0: .4byte 0x3F91DF46
_0823EDB4: .4byte 0xA2529D34
_0823EDB8: .4byte 0x401927BB
_0823EDBC: .4byte 0x2FEC56D6
_0823EDC0: .4byte 0x41193A5D
_0823EDC4: .4byte 0x66666666
_0823EDC8: .4byte 0x40257AE1
_0823EDCC: .4byte 0x47AE147B
_0823EDD0: .4byte 0x3FF4624D
_0823EDD4: .4byte 0xD2F1A9FC
_0823EDD8: .4byte 0x412B2D4C
_0823EDDC: .4byte 0x70A3D70A
_0823EDE0: .4byte 0x40623666
_0823EDE4: .4byte 0x66666666
_0823EDE8: .4byte 0x3FE510CB
_0823EDEC: .4byte 0x295E9E1B
_0823EDF0: .4byte 0x412D203B
_0823EDF4: .4byte 0x7AE147AE
_0823EDF8: .4byte 0x40667DC2
_0823EDFC: .4byte 0x8F5C28F6
_0823EE00: .4byte 0x3FCB573E
_0823EE04: .4byte 0xAB367A10
_0823EE08: .4byte 0x40E193E1
_0823EE0C: .4byte 0x9999999A
_0823EE10: .4byte 0x4055E1EB
_0823EE14: .4byte 0x851EB852
_0823EE18: .4byte 0x3FC7B15B
_0823EE1C: .4byte 0x573EAB36
_0823EE20: .4byte 0x412D7E08
_0823EE24: .4byte 0x00000000
_0823EE28: .4byte 0x40714800
_0823EE2C: .4byte 0x00000000
_0823EE30: .4byte 0x3FBD4951
_0823EE34: .4byte 0x82A9930C
_0823EE38: .4byte 0x40EF2EF0
_0823EE3C: .4byte 0x00000000
_0823EE40: .4byte 0x405F0CCC
_0823EE44: .4byte 0xCCCCCCCD
_0823EE48: .4byte 0x3FAE1B08
_0823EE4C: .4byte 0x9A027525
_0823EE50: .4byte 0x411707E1
_0823EE54: .4byte 0x33333333
_0823EE58: .4byte 0x402A6666
_0823EE5C: .4byte 0x66666666
_0823EE60: .4byte 0x3FAD3C36
_0823EE64: .4byte 0x113404EA
_0823EE68: .4byte 0x4134DEB5
_0823EE6C: .4byte 0x1999999A
_0823EE70: .4byte 0x40718B33
_0823EE74: .4byte 0x33333333
_0823EE78: .4byte 0x3FAB4A23
_0823EE7C: .4byte 0x39C0EBEE
_0823EE80: .4byte 0x412A140E
_0823EE84: .4byte 0x66666666
_0823EE88: .4byte 0x40628666
_0823EE8C: .4byte 0x66666666
_0823EE90: .4byte 0x3FA77318
_0823EE94: .4byte 0xFC504817
_0823EE98: .4byte 0x411AEDBF
_0823EE9C: .4byte 0x33333333
_0823EEA0: .4byte 0x4047B333
_0823EEA4: .4byte 0x33333333
_0823EEA8: .4byte 0x3FA4F0D8
_0823EEAC: .4byte 0x44D013A9
_0823EEB0: .4byte 0x411B2D4C
_0823EEB4: .4byte 0x66666666
_0823EEB8: .4byte 0x403BE666
_0823EEBC: .4byte 0x66666666
_0823EEC0: .4byte 0x3FA1C432
_0823EEC4: .4byte 0xCA57A787
_0823EEC8: .4byte 0x411F52B7
_0823EECC: .4byte 0x9999999A
_0823EED0: .4byte 0x406BD000
_0823EED4: .4byte 0x00000000
_0823EED8: .4byte 0x3F9F212D
_0823EEDC: .4byte 0x77318FC5
_0823EEE0: .4byte 0x40F285E0
_0823EEE4: .4byte 0x00000000
_0823EEE8: .4byte 0x40448000
_0823EEEC: .4byte 0x00000000
_0823EEF0: .4byte 0x3F8F8A09
_0823EEF4: .4byte 0x02DE00D2
_0823EEF8:
	ldr r3, _0823F12C @ =0x00000000
	ldr r2, _0823F128 @ =0x41360713
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F130 @ =0x404A0000
	ldr r3, _0823F134 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F138 @ =0x3F899999
	ldr r3, _0823F13C @ =0x9999999A
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F140 @ =0x411DDBD4
	ldr r3, _0823F144 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F148 @ =0x4061C000
	ldr r3, _0823F14C @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F150 @ =0x3F86872B
	ldr r3, _0823F154 @ =0x020C49BA
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F158 @ =0x4133E53E
	ldr r3, _0823F15C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F160 @ =0x406EC000
	ldr r3, _0823F164 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F168 @ =0x3F85E9E1
	ldr r3, _0823F16C @ =0xB089A027
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F170 @ =0x4135D82D
	ldr r3, _0823F174 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F178 @ =0x4073B000
	ldr r3, _0823F17C @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F180 @ =0x3F847AE1
	ldr r3, _0823F184 @ =0x47AE147B
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F188 @ =0x41293A5E
	ldr r3, _0823F18C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F190 @ =0x405BC000
	ldr r3, _0823F194 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F198 @ =0x3F816872
	ldr r3, _0823F19C @ =0xB020C49C
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1A0 @ =0x411B6CD8
	ldr r3, _0823F1A4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F1A8 @ =0x40678000
	ldr r3, _0823F1AC @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F1B0 @ =0x3F802DE0
	ldr r3, _0823F1B4 @ =0x0D1B7176
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1B8 @ =0x412C468A
	ldr r3, _0823F1BC @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F1C0 @ =0x40743000
	ldr r3, _0823F1C4 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F1C8 @ =0x3F7BDA51
	ldr r3, _0823F1CC @ =0x19CE075F
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1D0 @ =0x40DF2F00
	ldr r3, _0823F1D4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F1D8 @ =0x405AC000
	ldr r3, _0823F1DC @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F1E0 @ =0x3F754C98
	ldr r3, _0823F1E4 @ =0x5F06F694
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1E8 @ =0x411D5FC8
	ldr r3, _0823F1EC @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	ldr r2, _0823F1F0 @ =0x4069A000
	ldr r3, _0823F1F4 @ =0x00000000
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823F1F8 @ =0x3F747AE1
	ldr r3, _0823F1FC @ =0x47AE147B
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F200 @ =0x40768000
	ldr r5, _0823F204 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl fdlibm_fmod
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F208 @ =0x00000000
	ldr r3, _0823F20C @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _0823F11C
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
_0823F11C:
	adds r1, r7, #0
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F128: .4byte 0x41360713
_0823F12C: .4byte 0x00000000
_0823F130: .4byte 0x404A0000
_0823F134: .4byte 0x00000000
_0823F138: .4byte 0x3F899999
_0823F13C: .4byte 0x9999999A
_0823F140: .4byte 0x411DDBD4
_0823F144: .4byte 0x00000000
_0823F148: .4byte 0x4061C000
_0823F14C: .4byte 0x00000000
_0823F150: .4byte 0x3F86872B
_0823F154: .4byte 0x020C49BA
_0823F158: .4byte 0x4133E53E
_0823F15C: .4byte 0x00000000
_0823F160: .4byte 0x406EC000
_0823F164: .4byte 0x00000000
_0823F168: .4byte 0x3F85E9E1
_0823F16C: .4byte 0xB089A027
_0823F170: .4byte 0x4135D82D
_0823F174: .4byte 0x00000000
_0823F178: .4byte 0x4073B000
_0823F17C: .4byte 0x00000000
_0823F180: .4byte 0x3F847AE1
_0823F184: .4byte 0x47AE147B
_0823F188: .4byte 0x41293A5E
_0823F18C: .4byte 0x00000000
_0823F190: .4byte 0x405BC000
_0823F194: .4byte 0x00000000
_0823F198: .4byte 0x3F816872
_0823F19C: .4byte 0xB020C49C
_0823F1A0: .4byte 0x411B6CD8
_0823F1A4: .4byte 0x00000000
_0823F1A8: .4byte 0x40678000
_0823F1AC: .4byte 0x00000000
_0823F1B0: .4byte 0x3F802DE0
_0823F1B4: .4byte 0x0D1B7176
_0823F1B8: .4byte 0x412C468A
_0823F1BC: .4byte 0x00000000
_0823F1C0: .4byte 0x40743000
_0823F1C4: .4byte 0x00000000
_0823F1C8: .4byte 0x3F7BDA51
_0823F1CC: .4byte 0x19CE075F
_0823F1D0: .4byte 0x40DF2F00
_0823F1D4: .4byte 0x00000000
_0823F1D8: .4byte 0x405AC000
_0823F1DC: .4byte 0x00000000
_0823F1E0: .4byte 0x3F754C98
_0823F1E4: .4byte 0x5F06F694
_0823F1E8: .4byte 0x411D5FC8
_0823F1EC: .4byte 0x00000000
_0823F1F0: .4byte 0x4069A000
_0823F1F4: .4byte 0x00000000
_0823F1F8: .4byte 0x3F747AE1
_0823F1FC: .4byte 0x47AE147B
_0823F200: .4byte 0x40768000
_0823F204: .4byte 0x00000000
_0823F208: .4byte 0x00000000
_0823F20C: .4byte 0x00000000
