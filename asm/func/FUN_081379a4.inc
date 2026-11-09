	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r2, r0
	ldr r1, _081379F8 @ =0x00000B4A
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08137A22
	subs r1, #0x10
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _08137A22
	movs r0, #1
	mov r8, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r1, #0x98
	adds r6, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
	ldr r1, _081379F8 @ =0x00000B4A
	adds r7, r2, r1
_081379E8:
	ldrb r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _081379FC
	movs r0, #1
	b _081379FE
	.align 2, 0
_081379F8: .4byte 0x00000B4A
_081379FC:
	movs r0, #0
_081379FE:
	cmp r0, #0
	bne _08137A16
	adds r0, r6, #0
	bl Hitbox_Unregister
	ldrb r0, [r4]
	mov r1, r8
	orrs r1, r0
	strb r1, [r4]
	ldrb r0, [r7]
	subs r0, #1
	strb r0, [r7]
_08137A16:
	ldr r0, _08137A2C @ =0xFFFFFEE0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _081379E8
_08137A22:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08137A2C: .4byte 0xFFFFFEE0
