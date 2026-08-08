	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080F6B9C @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _080F6BA0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F6BA0
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080F6BA0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0x83
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x24
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0x24
	bl Div
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_080f897c
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080e81dc
	movs r0, #1
	b _080F6BA2
	.align 2, 0
_080F6B9C: .4byte 0x000001DF
_080F6BA0:
	movs r0, #0
_080F6BA2:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
