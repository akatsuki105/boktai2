	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r0, r1, #0
	adds r7, r3, #0
	cmp r2, #2
	bgt _0823E864
	subs r5, r0, #1
	adds r6, r2, #0
	adds r6, #0xc
	b _0823E868
_0823E864:
	adds r5, r0, #0
	adds r6, r2, #0
_0823E868:
	adds r0, r5, #0
	bl __floatsidf
	cmp r5, #0
	bge _0823E87A
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl __adddf3
_0823E87A:
	ldr r2, _0823E930 @ =0x4076D400
	ldr r3, _0823E934 @ =0x00000000
	bl __muldf3
	bl __fixunsdfsi
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r5, #0
	bl __udivsi3
	adds r4, r4, r0
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	subs r4, r4, r0
	adds r0, r4, #0
	bl __floatsidf
	str r0, [sp]
	str r1, [sp, #4]
	cmp r4, #0
	bge _0823E8B8
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl __adddf3
	str r0, [sp]
	str r1, [sp, #4]
_0823E8B8:
	subs r4, r6, #2
	adds r0, r4, #0
	bl __floatsidf
	cmp r4, #0
	bge _0823E8CC
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl __adddf3
_0823E8CC:
	ldr r2, _0823E938 @ =0x403E970A
	ldr r3, _0823E93C @ =0x3D70A3D7
	bl __muldf3
	bl __fixunsdfsi
	adds r4, r0, #0
	bl __floatsidf
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r4, #0
	bge _0823E8F2
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl __adddf3
	adds r6, r1, #0
	adds r5, r0, #0
_0823E8F2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r6, #0
	adds r2, r5, #0
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r7, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	ldr r2, _0823E940 @ =0x4124B800
	ldr r3, _0823E944 @ =0x00000000
	bl __subdf3
	str r0, [sp]
	str r1, [sp, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823E928: .4byte 0x41F00000
_0823E92C: .4byte 0x00000000
_0823E930: .4byte 0x4076D400
_0823E934: .4byte 0x00000000
_0823E938: .4byte 0x403E970A
_0823E93C: .4byte 0x3D70A3D7
_0823E940: .4byte 0x4124B800
_0823E944: .4byte 0x00000000
