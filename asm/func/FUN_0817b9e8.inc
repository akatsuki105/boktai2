	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ldr r2, _0817BA08 @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BA0C
	movs r0, #1
	b _0817BA0E
	.align 2, 0
_0817BA08: .4byte 0x00000898
_0817BA0C:
	movs r0, #0
_0817BA0E:
	cmp r0, #0
	beq _0817BA44
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x19
	movs r3, #0
	bl Enemy_SetAnimEntry
	b _0817BA74
_0817BA44:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xe
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x1b
	movs r3, #0
	bl Enemy_SetAnimEntry
_0817BA74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
