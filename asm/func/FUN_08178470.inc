	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r6, r0
	ldr r1, _081784B4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, #1
	cmp r2, #0
	blt _081784F6
	movs r7, #1
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1c
	adds r5, r1, r3
	adds r1, #0x7c
	adds r1, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
_081784A8:
	ldrb r0, [r4]
	ands r0, r7
	cmp r0, #0
	beq _081784B8
	movs r0, #1
	b _081784BA
	.align 2, 0
_081784B4: .4byte 0x00001012
_081784B8:
	movs r0, #0
_081784BA:
	cmp r0, #0
	bne _081784E8
	adds r0, r1, #0
	bl Hitbox_Unregister
	ldrb r1, [r4]
	adds r0, r7, #0
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _081784E4 @ =0x00001022
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_08176530
	movs r0, #1
	b _081784F8
	.align 2, 0
_081784E4: .4byte 0x00001022
_081784E8:
	ldr r0, _08178500 @ =0xFFFFFEDC
	adds r5, r5, r0
	adds r1, r1, r0
	adds r4, r4, r0
	subs r2, #1
	cmp r2, #0
	bge _081784A8
_081784F6:
	movs r0, #0
_081784F8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08178500: .4byte 0xFFFFFEDC
