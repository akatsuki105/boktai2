	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	adds r4, r1, #0
	ldr r0, _080FA344 @ =0x0000021E
	add r0, ip
	ldrh r0, [r0]
	cmp r0, r2
	beq _080FA340
	movs r0, #0x88
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #0
	bne _080FA348
	mov r3, sp
	mov r2, ip
	adds r2, #8
	ldrh r0, [r4]
	mov r1, ip
	ldrh r6, [r1, #8]
	subs r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r5, [r2, #2]
	subs r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r4, [r2, #4]
	subs r0, r0, r4
	strh r0, [r3, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r7, r1, r0
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	cmp r0, #0
	beq _080FA340
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	subs r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	subs r0, r0, r4
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r1, r7
	blt _080FA348
_080FA340:
	movs r0, #1
	b _080FA34A
	.align 2, 0
_080FA344: .4byte 0x0000021E
_080FA348:
	movs r0, #0
_080FA34A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
