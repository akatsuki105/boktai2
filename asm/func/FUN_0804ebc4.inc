	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EC44 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC22
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r0, r4, #0
	bl FUN_0804ea1c
	bl FUN_0804e5bc
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_0804ead0
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EC1A
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x20]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x20]
	bl TextPanel_Start
_0804EC1A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804EC22:
	ldr r2, [r4, #0x1c]
	cmp r2, #0x3b
	bls _0804EC4C
	ldr r0, _0804EC48 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804EC4C
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	b _0804EC50
	.align 2, 0
_0804EC44: .4byte 0x030044BC
_0804EC48: .4byte 0x030044E0
_0804EC4C:
	adds r0, r2, #1
	str r0, [r4, #0x1c]
_0804EC50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
