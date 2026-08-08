	sub sp, #4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xac
	mov r8, r0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #0xcc]
	ldr r3, _0823FDA0 @ =0x00000000
	ldr r2, _0823FD9C @ =0x40768000
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	bl __divdf3
	str r0, [sp, #0x9c]
	str r1, [sp, #0xa0]
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl FUN_0823e850
	ldr r4, _0823FDA4 @ =0x3FD80000
	ldr r5, _0823FDA8 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	str r0, [sp, #0x5c]
	str r1, [sp, #0x60]
	mov r3, sl
	adds r3, #1
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	bl FUN_0823e850
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	str r0, [sp, #0x4c]
	str r1, [sp, #0x50]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	ldr r0, [sp, #0x44]
	ldr r1, [sp, #0x48]
	ldr r2, _0823FDC4 @ =0x3FE00000
	ldr r3, _0823FDC8 @ =0x00000000
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	str r4, [sp, #0x54]
	str r5, [sp, #0x58]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	movs r2, #0
	str r2, [sp, #0x74]
	str r2, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r2, [sp, #0x80]
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	str r0, [sp, #0x84]
	str r1, [sp, #0x88]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r6, [sp, #0x14]
	ldr r7, [sp, #0x18]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl __subdf3
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl __adddf3
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gtdf2
	cmp r0, #0
	ble _0823FDCC
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	b _0823FDD4
	.align 2, 0
_0823FD9C: .4byte 0x40768000
_0823FDA0: .4byte 0x00000000
_0823FDA4: .4byte 0x3FD80000
_0823FDA8: .4byte 0x00000000
_0823FDAC: .4byte 0x40E38800
_0823FDB0: .4byte 0x00000000
_0823FDB4: .4byte 0x3FF00B36
_0823FDB8: .4byte 0xE7D9D4AE
_0823FDBC: .4byte 0x3FE57AFA
_0823FDC0: .4byte 0x7221858C
_0823FDC4: .4byte 0x3FE00000
_0823FDC8: .4byte 0x00000000
_0823FDCC:
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
_0823FDD4:
	bl __subdf3
	ldr r3, _0823FEBC @ =0x66666666
	ldr r2, _0823FEB8 @ =0x3FE66666
	bl __gtdf2
	str r4, [sp, #0x8c]
	str r5, [sp, #0x90]
	cmp r0, #0
	ble _0823FDF0
	ldr r0, _0823FEC0 @ =0xBFF00000
	ldr r1, _0823FEC4 @ =0x00000000
	str r0, [sp, #0x8c]
	str r1, [sp, #0x90]
_0823FDF0:
	ldr r0, [sp, #0x84]
	ldr r1, [sp, #0x88]
	ldr r2, _0823FEC8 @ =0x40E38800
	ldr r3, _0823FECC @ =0x00000000
	bl __subdf3
	ldr r2, _0823FED0 @ =0x3FF00B36
	ldr r3, _0823FED4 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FED8 @ =0x3FE57AFA
	ldr r3, _0823FEDC @ =0x7221858C
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823FEE0 @ =0x40768000
	ldr r3, _0823FEE4 @ =0x00000000
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	bl __divdf3
	str r0, [sp, #0xa4]
	str r1, [sp, #0xa8]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0xa8]
	bl __adddf3
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #3
	ldr r2, [sp, #0x84]
	ldr r3, [sp, #0x88]
	bl FUN_0823f618
	ldr r6, [sp, #0x24]
	ldr r7, [sp, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FEC8 @ =0x40E38800
	ldr r3, _0823FECC @ =0x00000000
	bl __subdf3
	ldr r2, _0823FED0 @ =0x3FF00B36
	ldr r3, _0823FED4 @ =0xE7D9D4AE
	bl __muldf3
	ldr r2, _0823FED8 @ =0x3FE57AFA
	ldr r3, _0823FEDC @ =0x7221858C
	bl __adddf3
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0xa8]
	bl __adddf3
	bl __fixdfsi
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #3
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gtdf2
	cmp r0, #0
	ble _0823FEE8
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	b _0823FEF0
	.align 2, 0
_0823FEB8: .4byte 0x3FE66666
_0823FEBC: .4byte 0x66666666
_0823FEC0: .4byte 0xBFF00000
_0823FEC4: .4byte 0x00000000
_0823FEC8: .4byte 0x40E38800
_0823FECC: .4byte 0x00000000
_0823FED0: .4byte 0x3FF00B36
_0823FED4: .4byte 0xE7D9D4AE
_0823FED8: .4byte 0x3FE57AFA
_0823FEDC: .4byte 0x7221858C
_0823FEE0: .4byte 0x40768000
_0823FEE4: .4byte 0x00000000
_0823FEE8:
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
_0823FEF0:
	bl __subdf3
	ldr r3, _0823FFE0 @ =0x66666666
	ldr r2, _0823FFDC @ =0x3FE66666
	bl __gtdf2
	str r4, [sp, #0x94]
	str r5, [sp, #0x98]
	cmp r0, #0
	ble _0823FF0C
	ldr r0, _0823FFE4 @ =0xBFF00000
	ldr r1, _0823FFE8 @ =0x00000000
	str r0, [sp, #0x94]
	str r1, [sp, #0x98]
_0823FF0C:
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl __fixdfsi
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl __subdf3
	ldr r2, _0823FFEC @ =0x3FD80000
	ldr r3, _0823FFF0 @ =0x00000000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl __gedf2
	cmp r0, #0
	blt _0823FF4C
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
_0823FF4C:
	ldr r4, [sp, #0x44]
	ldr r5, [sp, #0x48]
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gedf2
	cmp r0, #0
	blt _0824003E
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl __ltdf2
	cmp r0, #0
	bge _0824003E
	ldr r2, _0823FFFC @ =0x40380000
	ldr r3, _08240000 @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	ldr r2, _08240004 @ =0x404E0000
	ldr r3, _08240008 @ =0x00000000
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	bl __fixdfsi
	adds r7, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	ldr r2, _0824000C @ =0x3FE00000
	ldr r3, _08240010 @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _08240014
	adds r1, r5, #0
	adds r0, r4, #0
	bl __fixdfsi
	adds r1, r7, #0
	b _08240016
	.align 2, 0
_0823FFDC: .4byte 0x3FE66666
_0823FFE0: .4byte 0x66666666
_0823FFE4: .4byte 0xBFF00000
_0823FFE8: .4byte 0x00000000
_0823FFEC: .4byte 0x3FD80000
_0823FFF0: .4byte 0x00000000
_0823FFF4: .4byte 0x3FF00000
_0823FFF8: .4byte 0x00000000
_0823FFFC: .4byte 0x40380000
_08240000: .4byte 0x00000000
_08240004: .4byte 0x404E0000
_08240008: .4byte 0x00000000
_0824000C: .4byte 0x3FE00000
_08240010: .4byte 0x00000000
_08240014:
	adds r1, r7, #1
_08240016:
	cmp r1, #0x3c
	bne _08240026
	movs r1, #0
	adds r6, #1
	cmp r6, #0x18
	bne _08240026
	movs r6, #0x17
	movs r1, #0x3b
_08240026:
	ldr r0, [sp, #0xdc]
	adds r6, r6, r0
	cmp r6, #0
	bge _08240032
	adds r6, #0x18
	b _08240038
_08240032:
	cmp r6, #0x17
	ble _08240038
	subs r6, #0x18
_08240038:
	adds r0, r6, #0
	bl FUN_0823de38
_0824003E:
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl __fixdfsi
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl __subdf3
	ldr r3, _08240114 @ =0x00000000
	ldr r2, _08240110 @ =0x3FD80000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl __gedf2
	cmp r0, #0
	blt _0824007E
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
_0824007E:
	ldr r4, [sp, #0x44]
	ldr r5, [sp, #0x48]
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	adds r3, r5, #0
	adds r2, r4, #0
	bl __gedf2
	cmp r0, #0
	blt _08240162
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl __ltdf2
	cmp r0, #0
	bge _08240162
	ldr r2, _08240120 @ =0x40380000
	ldr r3, _08240124 @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	ldr r2, _08240128 @ =0x404E0000
	ldr r3, _0824012C @ =0x00000000
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	bl __fixdfsi
	adds r7, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	ldr r2, _08240130 @ =0x3FE00000
	ldr r3, _08240134 @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _08240138
	adds r1, r5, #0
	adds r0, r4, #0
	bl __fixdfsi
	adds r1, r7, #0
	b _0824013A
	.align 2, 0
_08240110: .4byte 0x3FD80000
_08240114: .4byte 0x00000000
_08240118: .4byte 0x3FF00000
_0824011C: .4byte 0x00000000
_08240120: .4byte 0x40380000
_08240124: .4byte 0x00000000
_08240128: .4byte 0x404E0000
_0824012C: .4byte 0x00000000
_08240130: .4byte 0x3FE00000
_08240134: .4byte 0x00000000
_08240138:
	adds r1, r7, #1
_0824013A:
	cmp r1, #0x3c
	bne _0824014A
	movs r1, #0
	adds r6, #1
	cmp r6, #0x18
	bne _0824014A
	movs r6, #0x17
	movs r1, #0x3b
_0824014A:
	ldr r0, [sp, #0xdc]
	adds r6, r6, r0
	cmp r6, #0
	bge _08240156
	adds r6, #0x18
	b _0824015C
_08240156:
	cmp r6, #0x17
	ble _0824015C
	subs r6, #0x18
_0824015C:
	adds r0, r6, #0
	bl FUN_0823df38
_08240162:
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl FUN_0823f3e4
	ldr r3, _082401A0 @ =0x00000000
	ldr r2, _0824019C @ =0x40590000
	bl __muldf3
	bl __fixdfsi
	adds r5, r0, #0
	movs r1, #0xa
	bl Mod
	adds r4, r0, #0
	cmp r4, #4
	ble _082401A4
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	movs r1, #0xa
	bl Div
	adds r4, r0, #1
	b _082401B4
	.align 2, 0
_0824019C: .4byte 0x40590000
_082401A0: .4byte 0x00000000
_082401A4:
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
_082401B4:
	cmp r4, #9
	ble _082401C6
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	adds r0, #1
	movs r4, #0
	b _082401CE
_082401C6:
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
_082401CE:
	adds r1, r4, #0
	bl FUN_0823e470
	movs r0, #0
	add sp, #0xac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r3}
	add sp, #4
	bx r3
