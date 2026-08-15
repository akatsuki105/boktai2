	push {r4, r5, lr}
	sub sp, #0x30
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E6732
	ldr r3, _080E6688 @ =0x00000256
	adds r0, r4, r3
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E668C
	adds r0, #4
	b _080E6698
	.align 2, 0
_080E6688: .4byte 0x00000256
_080E668C:
	ldr r0, _080E673C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E6698:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080E6732
	ldr r1, _080E6740 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _080E6732
	ldr r3, _080E6744 @ =0x00000256
	adds r0, r4, r3
	ldrh r0, [r0]
	movs r1, #1
	bl FUN_08234224
	adds r1, r0, #0
	cmp r1, #0
	bne _080E6732
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _080E6732
	movs r3, #8
	ldrsh r0, [r4, r3]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r1, _080E6748 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _080E674C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_080E6732:
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E673C: .4byte 0x030046A4
_080E6740: .4byte 0x00000472
_080E6744: .4byte 0x00000256
_080E6748: .4byte 0x000001DF
_080E674C: .4byte 0xFFFF0000
