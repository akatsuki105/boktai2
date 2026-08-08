	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x90
	mov r8, r0
	mov sb, r1
	adds r5, r3, #0
	adds r4, r2, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823f210
	str r0, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823f3d4
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823e948
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r5, _0823F8FC @ =0x1A63C200
	ldr r4, _0823F8F8 @ =0x404CA5DC
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl fdlibm_cos
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl fdlibm_sin
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl fdlibm_sin
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r1, r7, #0
	adds r0, r6, #0
	bl fdlibm_sin
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl fdlibm_cos
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl __adddf3
	bl fdlibm_asin
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r1, r7, #0
	adds r0, r6, #0
	bl fdlibm_cos
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl fdlibm_cos
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl fdlibm_cos
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl fdlibm_sin
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl fdlibm_cos
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	adds r1, r7, #0
	adds r0, r6, #0
	bl fdlibm_sin
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl fdlibm_sin
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	ldr r2, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	bl __divdf3
	bl fdlibm_atan
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F900 @ =0x00000000
	ldr r5, _0823F904 @ =0x00000000
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0823F7B2
	ldr r2, _0823F908 @ =0x400921FB
	ldr r3, _0823F90C @ =0x54442D11
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
_0823F7B2:
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0823F7D2
	ldr r2, _0823F910 @ =0x401921FB
	ldr r3, _0823F914 @ =0x54442D11
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
_0823F7D2:
	ldr r2, _0823F918 @ =0x3F91DF46
	ldr r3, _0823F91C @ =0xA2529D34
	ldr r0, [sp, #0xb8]
	ldr r1, [sp, #0xbc]
	bl __muldf3
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	bl fdlibm_tan
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl fdlibm_tan
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	adds r1, r5, #0
	adds r0, r4, #0
	bl __negdf2
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __muldf3
	str r0, [sp, #0x58]
	str r1, [sp, #0x5c]
	ldr r0, _0823F920 @ =0x3FF95EBF
	ldr r1, _0823F924 @ =0x446C12C1
	bl fdlibm_cos
	str r0, [sp, #0x60]
	str r1, [sp, #0x64]
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	bl fdlibm_cos
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl fdlibm_cos
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x60]
	ldr r1, [sp, #0x64]
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x5c]
	bl __adddf3
	bl fdlibm_acos
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __subdf3
	ldr r4, _0823F910 @ =0x401921FB
	ldr r5, _0823F914 @ =0x54442D11
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	str r0, [sp, #0x68]
	str r1, [sp, #0x6c]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	str r0, [sp, #0x70]
	str r1, [sp, #0x74]
	mov r3, r8
	str r0, [r3, #0x20]
	str r1, [r3, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl __adddf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __divdf3
	str r0, [sp, #0x78]
	str r1, [sp, #0x7c]
	mov r4, r8
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r0, [sp, #0xac]
	bl __floatsidf
	adds r7, r1, #0
	adds r6, r0, #0
	mov r0, sb
	cmp r0, #1
	bne _0823F97C
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x68]
	ldr r3, [sp, #0x6c]
	bl __adddf3
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x4c]
	bl __ltdf2
	cmp r0, #0
	bge _0823F930
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne _0823F930
	ldr r2, _0823F928 @ =0x3FF00000
	ldr r3, _0823F92C @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [r4, #0x60]
	adds r0, #1
	str r0, [r4, #0x60]
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	b _0823FAA8
	.align 2, 0
_0823F8F8: .4byte 0x404CA5DC
_0823F8FC: .4byte 0x1A63C200
_0823F900: .4byte 0x00000000
_0823F904: .4byte 0x00000000
_0823F908: .4byte 0x400921FB
_0823F90C: .4byte 0x54442D11
_0823F910: .4byte 0x401921FB
_0823F914: .4byte 0x54442D11
_0823F918: .4byte 0x3F91DF46
_0823F91C: .4byte 0xA2529D34
_0823F920: .4byte 0x3FF95EBF
_0823F924: .4byte 0x446C12C1
_0823F928: .4byte 0x3FF00000
_0823F92C: .4byte 0x00000000
_0823F930:
	adds r1, r7, #0
	adds r0, r6, #0
	mov r4, r8
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x1c]
	bl __adddf3
	ldr r2, [r4, #0x50]
	ldr r3, [r4, #0x54]
	bl __gtdf2
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	cmp r0, #0
	bgt _0823F950
	b _0823FAA8
_0823F950:
	mov r1, r8
	ldr r0, [r1, #0x60]
	cmp r0, #0
	beq _0823F95A
	b _0823FAA8
_0823F95A:
	ldr r3, _0823F978 @ =0x00000000
	ldr r2, _0823F974 @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
	b _0823FAA8
	.align 2, 0
_0823F974: .4byte 0x3FF00000
_0823F978: .4byte 0x00000000
_0823F97C:
	mov r3, sb
	cmp r3, #2
	bne _0823F9F4
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x70]
	ldr r3, [sp, #0x74]
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	mov r0, r8
	ldr r2, [r0, #0x48]
	ldr r3, [r0, #0x4c]
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0823F9C4
	ldr r3, _0823F9C0 @ =0x00000000
	ldr r2, _0823F9BC @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	b _0823FAA8
	.align 2, 0
_0823F9BC: .4byte 0x3FF00000
_0823F9C0: .4byte 0x00000000
_0823F9C4:
	mov r1, r8
	ldr r2, [r1, #0x50]
	ldr r3, [r1, #0x54]
	adds r1, r5, #0
	adds r0, r4, #0
	bl __gtdf2
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	cmp r0, #0
	ble _0823FAA8
	ldr r3, _0823F9F0 @ =0x00000000
	ldr r2, _0823F9EC @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	b _0823FAA8
	.align 2, 0
_0823F9EC: .4byte 0x3FF00000
_0823F9F0: .4byte 0x00000000
_0823F9F4:
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	mov r2, sb
	cmp r2, #3
	bne _0823FAA8
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl __gtdf2
	cmp r0, #0
	ble _0823FA20
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl __subdf3
	mov r3, r8
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
_0823FA20:
	mov r4, r8
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	str r0, [sp, #0x88]
	str r1, [sp, #0x8c]
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x4c]
	bl __ltdf2
	cmp r0, #0
	bge _0823FA68
	ldr r0, [r4, #0x6c]
	cmp r0, #0
	bne _0823FA68
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [r4, #0x68]
	adds r0, #1
	str r0, [r4, #0x68]
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	b _0823FAA8
	.align 2, 0
_0823FA60: .4byte 0x3FF00000
_0823FA64: .4byte 0x00000000
_0823FA68:
	mov r0, r8
	ldr r2, [r0, #0x28]
	ldr r3, [r0, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	mov r4, r8
	ldr r2, [r4, #0x50]
	ldr r3, [r4, #0x54]
	bl __gtdf2
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	cmp r0, #0
	ble _0823FAA8
	mov r1, r8
	ldr r0, [r1, #0x68]
	cmp r0, #0
	bne _0823FAA8
	ldr r3, _0823FB6C @ =0x00000000
	ldr r2, _0823FB68 @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x6c]
	adds r0, #1
	str r0, [r2, #0x6c]
_0823FAA8:
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823FB78 @ =0x40768000
	ldr r3, _0823FB7C @ =0x00000000
	ldr r0, [sp, #0xb0]
	ldr r1, [sp, #0xb4]
	bl __divdf3
	str r0, [sp, #0x80]
	str r1, [sp, #0x84]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl __subdf3
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl __divdf3
	ldr r4, _0823FB88 @ =0x40E38800
	ldr r5, _0823FB8C @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, [r3, #0x20]
	ldr r3, [r3, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl __subdf3
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl __subdf3
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl __divdf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r3, [r2, #0x2c]
	ldr r2, [r2, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl __subdf3
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl __subdf3
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl __divdf3
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	mov r3, r8
	str r0, [r3, #0x10]
	str r1, [r3, #0x14]
	add sp, #0x90
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823FB68: .4byte 0x3FF00000
_0823FB6C: .4byte 0x00000000
_0823FB70: .4byte 0x3FE57AFA
_0823FB74: .4byte 0x7221858C
_0823FB78: .4byte 0x40768000
_0823FB7C: .4byte 0x00000000
_0823FB80: .4byte 0x3FF00B36
_0823FB84: .4byte 0xE7D9D4AE
_0823FB88: .4byte 0x40E38800
_0823FB8C: .4byte 0x00000000
