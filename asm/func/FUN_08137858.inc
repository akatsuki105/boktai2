	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r7, r5, r4
	ldr r1, _08137874 @ =0x00000B4A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _081378AC
	b _081378F4
	.align 2, 0
_08137874: .4byte 0x00000B4A
_08137878:
	adds r0, r4, r1
	lsls r0, r0, #5
	adds r4, r7, r0
	adds r0, r4, #0
	adds r0, #0x98
	bl Hitbox_Unregister
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _081378A8 @ =0x00000B4A
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_08138504
	movs r0, #1
	b _081378F6
	.align 2, 0
_081378A8: .4byte 0x00000B4A
_081378AC:
	ldr r1, _081378DC @ =0x00000B3A
	adds r0, r5, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r0, #1
	cmp r1, #0
	blt _081378F4
	movs r0, #5
	mov ip, r0
	lsls r2, r1, #3
	adds r0, r2, r1
	lsls r0, r0, #5
	adds r0, #0xfd
	adds r3, r0, r7
	ldr r6, _081378E0 @ =0xFFFFFEE0
_081378CA:
	ldrb r0, [r3]
	mov r4, ip
	ands r0, r4
	adds r4, r2, #0
	cmp r0, #0
	beq _081378E4
	movs r0, #1
	b _081378E6
	.align 2, 0
_081378DC: .4byte 0x00000B3A
_081378E0: .4byte 0xFFFFFEE0
_081378E4:
	movs r0, #0
_081378E6:
	cmp r0, #0
	beq _08137878
	subs r2, #8
	adds r3, r3, r6
	subs r1, #1
	cmp r1, #0
	bge _081378CA
_081378F4:
	movs r0, #0
_081378F6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
