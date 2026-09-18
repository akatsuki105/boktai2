	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r4, #0
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08022782
	ldr r4, _080227F0 @ =0x00000FFF
_08022782:
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _08022792
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r4, r0
_08022792:
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080227A2
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r4, r0
_080227A2:
	movs r5, #2
	ldrsh r0, [r2, r5]
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r3, #6
	ldrsh r1, [r2, r3]
	str r1, [sp, #8]
	movs r5, #8
	ldrsh r3, [r2, r5]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	cmp r0, #0
	bne _080227D0
	cmp r1, #0
	bne _080227D0
	cmp r3, #0
	bne _080227D0
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_080227D0:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #3
	cmp r0, #0
	bne _080227DC
	movs r1, #2
_080227DC:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl MapPltt_PushCommand
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080227F0: .4byte 0x00000FFF
