	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0xff
	movs r2, #0
	ldr r3, _08136C28 @ =0x00000B3A
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _08136C42
	movs r3, #4
	mov ip, r3
	adds r4, r0, #0
	movs r3, #0
	movs r5, #0xcb
	lsls r5, r5, #3
	mov r8, r5
_08136C14:
	adds r0, r3, r6
	add r0, r8
	adds r0, #0xfd
	ldrb r0, [r0]
	mov r5, ip
	ands r0, r5
	cmp r0, #0
	beq _08136C2C
	movs r0, #1
	b _08136C2E
	.align 2, 0
_08136C28: .4byte 0x00000B3A
_08136C2C:
	movs r0, #0
_08136C2E:
	cmp r0, #0
	beq _08136C36
	adds r7, r2, #0
	b _08136C42
_08136C36:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r2, #1
	cmp r2, r4
	blt _08136C14
_08136C42:
	cmp r7, #0xff
	beq _08136C8C
	ldr r2, _08136C98 @ =0x00000AEC
	adds r5, r6, r2
	ldrh r1, [r1]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r7, #3
	adds r4, r4, r7
	lsls r4, r4, #5
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r4, r4, r3
	adds r4, r6, r4
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl Mover_Init
	ldr r1, _08136C9C @ =0x00000B14
	adds r0, r6, r1
	str r4, [r0]
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #1
	movs r3, #0xb3
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08136C8C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136C98: .4byte 0x00000AEC
_08136C9C: .4byte 0x00000B14
