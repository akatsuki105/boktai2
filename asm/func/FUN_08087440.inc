	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	ldr r0, _0808748C @ =0x00000326
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08087484
	subs r0, #1
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08087484
	movs r4, #0xc9
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	strh r3, [r2]
	ldr r0, _08087490 @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_08087484:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808748C: .4byte 0x00000326
_08087490: .4byte 0x00000414
