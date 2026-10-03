	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BA5A8 @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA5B0
	ldr r2, _080BA5AC @ =0x0000140B
	adds r6, r5, r2
	ldrb r0, [r6]
	bl GetNormalItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BA610
	ldrb r0, [r6]
	bl FUN_080ba288
	adds r6, r0, #0
	movs r7, #1
	b _080BA5E4
	.align 2, 0
_080BA5A8: .4byte 0x00001409
_080BA5AC: .4byte 0x0000140B
_080BA5B0:
	cmp r0, #7
	bhi _080BA5DC
	ldr r1, _080BA5D4 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA5D8 @ =0x000012E4
	adds r0, r0, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BA610
	adds r0, r4, #0
	bl FUN_080ba220
	adds r6, r0, #0
	b _080BA5E2
	.align 2, 0
_080BA5D4: .4byte 0x0000140B
_080BA5D8: .4byte 0x000012E4
_080BA5DC:
	movs r4, #1
	rsbs r4, r4, #0
	movs r6, #0
_080BA5E2:
	movs r7, #0
_080BA5E4:
	cmp r4, #0
	blt _080BA610
	ldr r1, _080BA608 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BA60C @ =0x00000E58
	adds r1, r5, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_080b9658
	b _080BA618
	.align 2, 0
_080BA608: .4byte 0x0000140B
_080BA60C: .4byte 0x00000E58
_080BA610:
	ldr r1, _080BA620 @ =0x00000E58
	adds r0, r5, r1
	bl FUN_080b9724
_080BA618:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA620: .4byte 0x00000E58
