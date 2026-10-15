	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E5384 @ =0x000014AC
	adds r7, r6, r0
	ldr r1, _081E5388 @ =0x00001614
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5342
	ldr r2, _081E538C @ =0x00001599
	adds r4, r6, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r3, _081E5390 @ =0x00000E4C
	adds r1, r1, r3
	adds r1, r6, r1
	adds r0, r7, #0
	movs r2, #0xd
	bl FUN_0822f588
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _081E5394 @ =0x00000E86
	adds r0, r0, r1
	movs r2, #0
	mov r8, r2
	movs r2, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, _081E5398 @ =0x00000E94
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r0, _081E539C @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xb8
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _081E53A0 @ =0x000015B4
	adds r1, r6, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r3, _081E53A4 @ =0x000015B6
	adds r1, r6, r3
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E53A8 @ =0x0000159A
	adds r0, r6, r1
	strh r2, [r0]
	ldr r0, _081E53AC @ =0x0000038A
	bl PlaySound_082406e0
	mov r2, r8
	strb r2, [r5]
_081E5342:
	ldr r3, _081E53B0 @ =0x000014CC
	adds r1, r6, r3
	ldr r0, _081E53A0 @ =0x000015B4
	adds r2, r6, r0
	adds r3, #0xce
	adds r4, r6, r3
	ldrh r3, [r4]
	movs r0, #5
	str r0, [sp]
	adds r0, r1, #0
	bl LerpVec3
	ldrh r0, [r4]
	cmp r0, #0xb
	bls _081E53C0
	movs r0, #0x30
	strh r0, [r7, #0x20]
	movs r0, #0x48
	strh r0, [r7, #0x22]
	ldr r0, _081E53B4 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r6, #0x18]
	ldr r0, _081E5388 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E53B8 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E53BC @ =0x00000111
	bl PlaySound_082406e0
	b _081E53D2
	.align 2, 0
_081E5384: .4byte 0x000014AC
_081E5388: .4byte 0x00001614
_081E538C: .4byte 0x00001599
_081E5390: .4byte 0x00000E4C
_081E5394: .4byte 0x00000E86
_081E5398: .4byte 0x00000E94
_081E539C: .4byte 0x03003584
_081E53A0: .4byte 0x000015B4
_081E53A4: .4byte 0x000015B6
_081E53A8: .4byte 0x0000159A
_081E53AC: .4byte 0x0000038A
_081E53B0: .4byte 0x000014CC
_081E53B4: .4byte FUN_081e6f28
_081E53B8: .4byte 0x00001616
_081E53BC: .4byte 0x00000111
_081E53C0:
	ldr r2, _081E53E0 @ =0x00000808
	adds r0, r6, r2
	ldr r3, _081E53E4 @ =0x00000AC8
	adds r1, r6, r3
	bl MainSprite_AdvanceAnim
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E53D2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E53E0: .4byte 0x00000808
_081E53E4: .4byte 0x00000AC8
