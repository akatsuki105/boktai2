	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	bl FUN_080091d0
	ldr r0, [r7, #0x24]
	cmp r0, #0
	beq _08009640
	movs r0, #6
	ldr r1, _0800960C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08009640
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08009640
	movs r1, #0x1c
	ldrsh r0, [r6, r1]
	movs r2, #0x28
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r6, r3]
	movs r3, #0x2c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r2, r1, #3
	movs r1, #7
	ands r2, r1
	ldr r1, [r6, #0x10]
	cmp r4, r1
	bhs _08009640
	ldrb r1, [r6, #2]
	cmp r1, #0
	beq _08009610
	movs r3, #0
	movs r4, #1
	movs r5, #2
	b _08009616
	.align 2, 0
_0800960C: .4byte 0x03002BC0
_08009610:
	movs r3, #6
	movs r4, #7
	movs r5, #0
_08009616:
	cmp r3, r2
	beq _08009622
	cmp r4, r2
	beq _08009622
	cmp r5, r2
	bne _08009640
_08009622:
	ldr r1, [r7, #0x24]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #1
	cmp r3, r1
	beq _0800963C
	cmp r4, r1
	beq _0800963C
	cmp r5, r1
	beq _0800963C
	movs r2, #0
_0800963C:
	cmp r2, #0
	bne _0800964A
_08009640:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080091c4
	movs r0, #0
_0800964A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
