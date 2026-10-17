	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DBAC0
	ldr r3, _081DBAB4 @ =0x0000039A
	adds r0, r2, r3
	ldr r1, _081DBAB8 @ =0x00006739
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, _081DBABC @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	b _081DBC08
	.align 2, 0
_081DBAB4: .4byte 0x0000039A
_081DBAB8: .4byte 0x00006739
_081DBABC: .4byte 0x03004290
_081DBAC0:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	movs r3, #0x1f
	cmp r0, #9
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x11
	bls _081DBAE8
	movs r3, #0x12
	cmp r0, #0x19
	bls _081DBAE8
	movs r3, #0xa
	cmp r0, #0x21
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x29
	bhi _081DBAE8
	movs r3, #0x12
_081DBAE8:
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DBB02
	movs r0, #0
	strh r0, [r1]
_081DBB02:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB20
	ldr r0, _081DBB18 @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB1C @ =0x00006739
	b _081DBB26
	.align 2, 0
_081DBB18: .4byte 0x0000039A
_081DBB1C: .4byte 0x00006739
_081DBB20:
	ldr r0, _081DBB3C @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB40 @ =0x000035B4
_081DBB26:
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB4C
	ldr r0, _081DBB44 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB48 @ =0x00006739
	b _081DBB52
	.align 2, 0
_081DBB3C: .4byte 0x0000039A
_081DBB40: .4byte 0x000035B4
_081DBB44: .4byte 0x0000039E
_081DBB48: .4byte 0x00006739
_081DBB4C:
	ldr r0, _081DBB68 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB6C @ =0x000035B4
_081DBB52:
	strh r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB78
	ldr r0, _081DBB70 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB74 @ =0x00006739
	b _081DBB7E
	.align 2, 0
_081DBB68: .4byte 0x0000039E
_081DBB6C: .4byte 0x000035B4
_081DBB70: .4byte 0x000003A2
_081DBB74: .4byte 0x00006739
_081DBB78:
	ldr r0, _081DBB94 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB98 @ =0x000035B4
_081DBB7E:
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBBA4
	ldr r0, _081DBB9C @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBA0 @ =0x00006739
	b _081DBBAA
	.align 2, 0
_081DBB94: .4byte 0x000003A2
_081DBB98: .4byte 0x000035B4
_081DBB9C: .4byte 0x000003A6
_081DBBA0: .4byte 0x00006739
_081DBBA4:
	ldr r0, _081DBBC4 @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBC8 @ =0x000035B4
_081DBBAA:
	strh r0, [r1]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _081DBBDC
	cmp r0, #1
	bgt _081DBBCC
	cmp r0, #0
	beq _081DBBD6
	b _081DBBFA
	.align 2, 0
_081DBBC4: .4byte 0x000003A6
_081DBBC8: .4byte 0x000035B4
_081DBBCC:
	cmp r0, #2
	beq _081DBBE2
	cmp r0, #3
	beq _081DBBE8
	b _081DBBFA
_081DBBD6:
	movs r1, #0xeb
	lsls r1, r1, #2
	b _081DBBEC
_081DBBDC:
	movs r1, #0xec
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE2:
	movs r1, #0xed
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE8:
	movs r1, #0xee
	lsls r1, r1, #2
_081DBBEC:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DBBFA
	subs r1, #0x12
	adds r0, r2, r1
	strh r3, [r0]
_081DBBFA:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r1, _081DBC10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
_081DBC08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBC10: .4byte 0x03004290
