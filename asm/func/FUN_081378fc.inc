	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0xcb
	lsls r2, r2, #3
	add r2, r8
	ldr r0, _08137954 @ =0x00000B4A
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813798E
	ldr r0, _08137958 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0813798E
	movs r0, #1
	mov sb, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r1, #0x1c
	adds r7, r1, r2
	adds r1, #0x7c
	adds r6, r1, r2
	adds r0, #0xfd
	adds r4, r0, r2
_08137944:
	ldrb r0, [r4]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0813795C
	movs r0, #1
	b _0813795E
	.align 2, 0
_08137954: .4byte 0x00000B4A
_08137958: .4byte 0x00000B3A
_0813795C:
	movs r0, #0
_0813795E:
	cmp r0, #0
	bne _08137980
	adds r0, r6, #0
	bl Hitbox_Unregister
	ldrb r1, [r4]
	mov r0, sb
	orrs r0, r1
	strb r0, [r4]
	ldr r1, _0813799C @ =0x00000B4A
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08138504
_08137980:
	ldr r0, _081379A0 @ =0xFFFFFEE0
	adds r7, r7, r0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08137944
_0813798E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813799C: .4byte 0x00000B4A
_081379A0: .4byte 0xFFFFFEE0
