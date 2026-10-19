	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08204E86
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08204E86:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08204F8C
	adds r3, r5, #0
	adds r3, #0x64
	adds r2, r5, #0
	adds r2, #0x54
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	adds r6, r3, #0
	cmp r1, r0
	bgt _08204EDA
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08204F8C
_08204EDA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl ArcTan2_8
	strb r0, [r5, #0x1b]
	add r3, sp, #4
	ldrb r4, [r5, #0x1b]
	ldr r2, _08204F04 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _08204F08
	asrs r1, r0, #0xc
	b _08204F0E
	.align 2, 0
_08204F04: .4byte gSineTable
_08204F08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08204F0E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08204F2C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _08204F30
	asrs r0, r0, #0xc
	b _08204F36
	.align 2, 0
_08204F2C: .4byte gSineTable
_08204F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08204F36:
	strh r0, [r3, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08204F8C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
