	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _08004D04 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004CF0
	ldr r0, _08004D08 @ =0x00002153
	movs r1, #0
	bl Entity08004fac_Create
	cmp r0, #0
	beq _08004D98
_08004CF0:
	movs r0, #0x24
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _08004D0C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004D9A
	.align 2, 0
_08004D04: .4byte 0x03000024
_08004D08: .4byte 0x00002153
_08004D0C:
	adds r0, r5, #0
	movs r1, #0x24
	bl ClearMemory
	strh r6, [r5]
	movs r0, #1
	strb r0, [r5, #2]
	strb r7, [r5, #3]
	mov r0, r8
	strb r0, [r5, #4]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004D44
	cmp r1, #0
	blt _08004D44
	ldr r0, _08004D48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004D44
	ldr r0, _08004D4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004D50
_08004D44:
	movs r0, #0
	b _08004D5E
	.align 2, 0
_08004D48: .4byte 0x030046A8
_08004D4C: .4byte 0x030046AC
_08004D50:
	ldr r0, _08004D6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08004D5E:
	strh r0, [r5, #8]
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08004D70
	asrs r0, r0, #8
	b _08004D76
	.align 2, 0
_08004D6C: .4byte 0x030046A4
_08004D70:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08004D76:
	strb r0, [r5, #5]
	ldr r0, [sp, #0x20]
	strh r0, [r5, #6]
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
	adds r0, r5, #0
	bl Entity08004fac_LinkNode
_08004D98:
	movs r0, #0
_08004D9A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
