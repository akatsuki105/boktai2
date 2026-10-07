	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x74
	ldrb r0, [r5]
	cmp r0, #0
	beq _081D98E6
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D98C8
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D98C8:
	adds r3, r4, #0
	adds r3, #0x6c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D98FC @ =0x00000ECC
	adds r2, r6, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D9900 @ =0x0000FFFF
	strh r0, [r3]
	movs r0, #0
	strb r0, [r5]
_081D98E6:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D98FC: .4byte 0x00000ECC
_081D9900: .4byte 0x0000FFFF
