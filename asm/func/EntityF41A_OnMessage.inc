	push {r4, lr}
	sub sp, #0x10
	adds r3, r1, #0
	ldr r4, [r0, #0x38]
	cmp r3, #0
	bne _080CBBB4
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	beq _080CBBD4
	cmp r2, #0
	ble _080CBBA6
	ldr r1, _080CBBB0 @ =0xFFFF0000
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0xb8
	adds r3, r4, #0
	adds r3, #0x24
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_0805fe7c
_080CBBA6:
	adds r0, r4, #0
	movs r1, #1
	bl EntityF41A_SetState
	b _080CBBD4
	.align 2, 0
_080CBBB0: .4byte 0xFFFF0000
_080CBBB4:
	cmp r3, #1
	bne _080CBBD4
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1, #4]
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r4, #0
	movs r1, #2
	bl EntityF41A_SetState
_080CBBD4:
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
