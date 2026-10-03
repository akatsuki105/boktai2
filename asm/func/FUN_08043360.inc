	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08043388
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043388:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080433A0
	b _0804349E
_080433A0:
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r6, #0x82
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r0, [r0]
	mov r8, r3
	mov ip, r4
	cmp r1, r0
	bhi _080433E6
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08043496
_080433E6:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08043418 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov sb, r3
	cmp r0, #0
	blt _0804341C
	asrs r1, r0, #0xc
	b _08043422
	.align 2, 0
_08043418: .4byte 0x085B0A08
_0804341C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08043422:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0804343A
	asrs r0, r0, #0xc
	b _08043440
_0804343A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08043440:
	strh r0, [r4, #4]
	mov r3, ip
	movs r4, #0
	ldrsh r0, [r3, r4]
	mov r6, r8
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r4, sb
	strb r2, [r4]
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
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043496:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080414fc
_0804349E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
