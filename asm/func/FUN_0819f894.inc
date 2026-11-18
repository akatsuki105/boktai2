	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0]
	movs r1, #0x40
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0819F8CA
	ldr r0, _0819F8D0 @ =0x00000EAD
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0819F8CA
	ldr r1, _0819F8D4 @ =0x00000EAE
	adds r0, r3, r1
	ldrb r0, [r0]
	bl Camera_Shake
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_0819F8CA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819F8D0: .4byte 0x00000EAD
_0819F8D4: .4byte 0x00000EAE
