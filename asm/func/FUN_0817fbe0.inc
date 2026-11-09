	push {lr}
	adds r2, r0, #0
	ldr r0, _0817FBF8 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FBFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FBFE
	.align 2, 0
_0817FBF8: .4byte 0x0000046D
_0817FBFC:
	movs r0, #0
_0817FBFE:
	cmp r0, #0
	beq _0817FC12
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _0817FC20 @ =0x0000089C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
_0817FC12:
	adds r0, r2, #0
	movs r1, #0x16
	bl Enemy_PlayAnim
	pop {r0}
	bx r0
	.align 2, 0
_0817FC20: .4byte 0x0000089C
