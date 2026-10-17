	push {r4, r5, lr}
	sub sp, #0x10
	adds r2, r0, #0
	ldr r0, _0808741C @ =0x00000326
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r1, r0, r1
	strh r1, [r3]
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08087428
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0x96
	lsls r5, r5, #3
	cmp r0, r5
	bls _08087436
	strh r5, [r3]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087436
	ldr r1, _08087420 @ =0x000001F5
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08087436
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08087424 @ =0x00000414
	adds r4, r2, r0
	ldr r0, [r4]
	adds r1, r2, #0
	adds r1, #0x40
	str r3, [sp]
	str r5, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08087436
	.align 2, 0
_0808741C: .4byte 0x00000326
_08087420: .4byte 0x000001F5
_08087424: .4byte 0x00000414
_08087428:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	cmp r0, r1
	bls _08087436
	strh r1, [r3]
_08087436:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
