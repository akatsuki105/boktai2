	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_08017b70
	cmp r0, #0
	beq _08001C98
	ldr r0, _08001CA4 @ =0x0000064A
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08001C42
	ldr r1, _08001CA8 @ =0x085AA624
	ldr r2, _08001CAC @ =0x00000644
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08001C42:
	ldr r7, _08001CB0 @ =0x00000642
	adds r3, r6, r7
	ldr r0, _08001CB4 @ =0x00000643
	adds r1, r6, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08001C5E
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi _08001C7E
_08001C5E:
	movs r5, #0
	movs r4, #0xd0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x34
	ldr r7, _08001CB8 @ =0x00000434
	adds r2, r6, r7
	ldrb r3, [r3]
	str r5, [sp]
	str r4, [sp, #4]
	bl FUN_08001884
	mov r0, r8
	strh r5, [r0]
_08001C7E:
	ldr r2, _08001CB0 @ =0x00000642
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08001C90
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r0, r6, r7
	str r0, [r6, #0x30]
_08001C90:
	ldrb r1, [r1]
	ldr r2, _08001CB4 @ =0x00000643
	adds r0, r6, r2
	strb r1, [r0]
_08001C98:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001CA4: .4byte 0x0000064A
_08001CA8: .4byte 0x085AA624
_08001CAC: .4byte 0x00000644
_08001CB0: .4byte 0x00000642
_08001CB4: .4byte 0x00000643
_08001CB8: .4byte 0x00000434
