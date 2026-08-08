	push {r4, lr}
	ldr r0, _0822ED60 @ =0x0300449C
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _0822EE28
	ldr r2, _0822ED64 @ =0x03004498
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _0822ED6C
	ldr r0, _0822ED68 @ =0x04000008
	ldrh r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strh r1, [r0]
	b _0822ED76
	.align 2, 0
_0822ED60: .4byte 0x0300449C
_0822ED64: .4byte 0x03004498
_0822ED68: .4byte 0x04000008
_0822ED6C:
	ldr r2, _0822ED8C @ =0x04000008
	ldrh r1, [r2]
	ldr r0, _0822ED90 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
_0822ED76:
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0822ED98
	ldr r0, _0822ED94 @ =0x0400000A
	ldrh r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strh r1, [r0]
	b _0822EDA2
	.align 2, 0
_0822ED8C: .4byte 0x04000008
_0822ED90: .4byte 0x0000FFBF
_0822ED94: .4byte 0x0400000A
_0822ED98:
	ldr r2, _0822EDB8 @ =0x0400000A
	ldrh r1, [r2]
	ldr r0, _0822EDBC @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
_0822EDA2:
	ldrb r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0822EDC4
	ldr r0, _0822EDC0 @ =0x0400000C
	ldrh r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strh r1, [r0]
	b _0822EDCE
	.align 2, 0
_0822EDB8: .4byte 0x0400000A
_0822EDBC: .4byte 0x0000FFBF
_0822EDC0: .4byte 0x0400000C
_0822EDC4:
	ldr r2, _0822EDE4 @ =0x0400000C
	ldrh r1, [r2]
	ldr r0, _0822EDE8 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
_0822EDCE:
	ldrb r1, [r3]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0822EDF0
	ldr r0, _0822EDEC @ =0x0400000E
	ldrh r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strh r1, [r0]
	b _0822EDFA
	.align 2, 0
_0822EDE4: .4byte 0x0400000C
_0822EDE8: .4byte 0x0000FFBF
_0822EDEC: .4byte 0x0400000E
_0822EDF0:
	ldr r2, _0822EE0C @ =0x0400000E
	ldrh r1, [r2]
	ldr r0, _0822EE10 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
_0822EDFA:
	ldrb r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0822EE1C
	ldr r0, _0822EE14 @ =0x0400004C
	ldr r1, _0822EE18 @ =0x030044B4
	ldrb r1, [r1]
	b _0822EE22
	.align 2, 0
_0822EE0C: .4byte 0x0400000E
_0822EE10: .4byte 0x0000FFBF
_0822EE14: .4byte 0x0400004C
_0822EE18: .4byte 0x030044B4
_0822EE1C:
	ldr r0, _0822EE30 @ =0x0400004C
	ldr r1, _0822EE34 @ =0x030044B4
	ldrh r1, [r1]
_0822EE22:
	strh r1, [r0]
	movs r0, #0
	strh r0, [r4]
_0822EE28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822EE30: .4byte 0x0400004C
_0822EE34: .4byte 0x030044B4
