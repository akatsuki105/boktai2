	push {r4, r5, r6, r7, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08004EAC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004EB0
	movs r0, #1
	rsbs r0, r0, #0
	b _08004EE6
	.align 2, 0
_08004EAC: .4byte 0x03000024
_08004EB0:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004EE4
_08004EB6:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	cmp r0, r7
	bne _08004EDE
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _08004EDE
	movs r0, #1
	strb r0, [r5, #2]
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234270
_08004EDE:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004EB6
_08004EE4:
	movs r0, #0
_08004EE6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
