	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081057E8 @ =0x000001DF
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #8
	bne _081057C4
	b _081058EE
_081057C4:
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08105826
	ldrb r0, [r2]
	cmp r0, #6
	beq _08105806
	cmp r0, #6
	bgt _081057EC
	cmp r0, #5
	beq _081057F2
	b _081058EE
	.align 2, 0
_081057E8: .4byte 0x000001DF
_081057EC:
	cmp r0, #7
	beq _081058A4
	b _081058EE
_081057F2:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x76
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x30
	b _081058C2
_08105806:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x78
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x32
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x24
	b _081058C2
_08105826:
	ldrb r0, [r2]
	cmp r0, #6
	beq _08105850
	cmp r0, #6
	bgt _08105836
	cmp r0, #5
	beq _0810583C
	b _081058EE
_08105836:
	cmp r0, #7
	beq _0810589A
	b _081058EE
_0810583C:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	b _081058C2
_08105850:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0810587A
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x78
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x32
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x24
	b _081058C2
_0810587A:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #8
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x21
	b _081058C2
_0810589A:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _081058CA
_081058A4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x7a
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x34
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x2a
_081058C2:
	movs r3, #0
	bl Enemy_SetAnimEntry
	b _081058EE
_081058CA:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xa
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x27
	movs r3, #0
	bl Enemy_SetAnimEntry
_081058EE:
	pop {r4}
	pop {r0}
	bx r0
