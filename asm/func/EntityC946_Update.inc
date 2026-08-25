	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _0820FBF6
	movs r4, #0
	movs r0, #0x28
	adds r0, r0, r6
	mov r8, r0
_0820FBC2:
	movs r0, #0x94
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, r8
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0820FBDE
	adds r0, r1, #0
	adds r0, #0x28
	adds r0, r6, r0
	movs r1, #1
	bl FUN_08055ef8
_0820FBDE:
	adds r4, #1
	cmp r4, #4
	ble _0820FBC2
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0
	b _0820FD52
_0820FBF6:
	movs r4, #0
	movs r1, #0x28
	adds r1, r1, r6
	mov r8, r1
_0820FBFE:
	movs r1, #0x94
	adds r2, r4, #0
	muls r2, r1, r2
	mov r3, r8
	adds r1, r3, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _0820FC1A
	adds r0, r2, #0
	adds r0, #0x28
	adds r0, r6, r0
	movs r1, #1
	bl FUN_08055f1c
_0820FC1A:
	adds r4, #1
	cmp r4, #4
	ble _0820FBFE
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r3, r6, r1
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	ldr r1, [r6, #0x1c]
	lsls r1, r1, #5
	ldr r2, _0820FCCC @ =0x085AF0EC
	adds r7, r1, r2
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r6, r2
	str r7, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r6, r3
	ldrb r1, [r1]
	cmp r1, #0
	beq _0820FC5E
	movs r0, #0
	str r0, [r6, #0x18]
	str r0, [r6, #0x20]
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r6, #0
	bl EntityC946_Update_Helper_0820fb20
_0820FC5E:
	ldr r1, [r7, #0x10]
	cmp r1, #0
	beq _0820FC6A
	adds r0, r6, #0
	bl _call_via_r1
_0820FC6A:
	ldrb r2, [r7, #0xb]
	movs r1, #4
	ands r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	cmp r1, #0
	bne _0820FCB0
	ldrb r0, [r7, #0xa]
	ldr r1, _0820FCD0 @ =0x00000366
	adds r4, r6, r1
	ldr r2, _0820FCD4 @ =0x00000367
	adds r5, r6, r2
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrh r1, [r0]
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	mov r0, r8
	bl FUN_08055b5c
	mov r0, r8
	bl FUN_08055c04
_0820FCB0:
	ldrb r2, [r7, #0xb]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0820FD16
	ldrb r2, [r7, #0x17]
	ldr r1, [r6, #0x18]
	adds r1, r1, r2
	str r1, [r6, #0x18]
	cmp r1, #0
	blt _0820FCD8
	asrs r1, r1, #5
	b _0820FCDE
	.align 2, 0
_0820FCCC: .4byte 0x085AF0EC
_0820FCD0: .4byte 0x00000366
_0820FCD4: .4byte 0x00000367
_0820FCD8:
	rsbs r1, r1, #0
	asrs r1, r1, #5
	rsbs r1, r1, #0
_0820FCDE:
	adds r1, #0x80
	ldrb r4, [r7, #0x16]
	ldr r3, _0820FCFC @ =0x085B0A08
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	cmp r1, #0
	blt _0820FD00
	asrs r4, r1, #0xd
	b _0820FD06
	.align 2, 0
_0820FCFC: .4byte 0x085B0A08
_0820FD00:
	rsbs r1, r1, #0
	asrs r1, r1, #0xd
	rsbs r4, r1, #0
_0820FD06:
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r2, [r1]
	ldr r3, _0820FD2C @ =0x00000356
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r4
	strh r1, [r2, #2]
_0820FD16:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0820FD30
	movs r2, #0xc3
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r2, [r1]
	movs r3, #1
	orrs r2, r3
	str r2, [r1]
	b _0820FD48
	.align 2, 0
_0820FD2C: .4byte 0x00000356
_0820FD30:
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r1, [r7, #0x1c]
	adds r0, r6, #0
	bl FUN_0820fa80
_0820FD48:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r6, r1
	movs r1, #0
	strb r1, [r2]
_0820FD52:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
