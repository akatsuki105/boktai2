	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A340
	b _0814A5D6
_0814A340:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0814A354
	b _0814A5B6
_0814A354:
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	subs r3, #0xc
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0814A3A0
	ldr r0, _0814A39C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814A3AE
	.align 2, 0
_0814A39C: .4byte 0xFFFFFF00
_0814A3A0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814A3AE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814A3AE:
	adds r0, r1, #0
	cmp r0, #0
	bge _0814A3B6
	rsbs r0, r0, #0
_0814A3B6:
	adds r3, r0, #0
	cmp r3, #0x17
	ble _0814A3BE
	b _0814A594
_0814A3BE:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _0814A3CE
	cmp r0, #4
	bne _0814A474
_0814A3CE:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r3, _0814A444 @ =0x000006AC
	adds r1, r6, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A460
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A460
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814A448 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0814A44C @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _0814A450 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0814A454 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A458 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _0814A45C @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x6f
	bl Enemy_ClearPendingState
	b _0814A5D6
	.align 2, 0
_0814A444: .4byte 0x000006AC
_0814A448: .4byte 0x00000469
_0814A44C: .4byte 0x0000046A
_0814A450: .4byte 0x00000484
_0814A454: .4byte Enemy_ClearStateBegun
_0814A458: .4byte 0x0000046B
_0814A45C: .4byte 0x082520E4
_0814A460:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A472
	b _0814A5A4
_0814A472:
	b _0814A5A8
_0814A474:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _0814A4E8 @ =0x000006AC
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A504
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A504
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814A4EC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0814A4F0 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _0814A4F4 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0814A4F8 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A4FC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _0814A500 @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x7c
	bl Enemy_ClearPendingState
	b _0814A5D6
	.align 2, 0
_0814A4E8: .4byte 0x000006AC
_0814A4EC: .4byte 0x00000469
_0814A4F0: .4byte 0x0000046A
_0814A4F4: .4byte 0x00000484
_0814A4F8: .4byte Enemy_ClearStateBegun
_0814A4FC: .4byte 0x0000046B
_0814A500: .4byte 0x082520E4
_0814A504:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A460
	cmp r3, #5
	bgt _0814A460
	ldr r3, _0814A57C @ =0x000006CA
	adds r0, r6, r3
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A460
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _0814A580 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0814A584 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _0814A588 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A58C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _0814A590 @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x81
	bl Enemy_ClearPendingState
	b _0814A5D6
	.align 2, 0
_0814A57C: .4byte 0x000006CA
_0814A580: .4byte 0x00000469
_0814A584: .4byte 0x00000484
_0814A588: .4byte Enemy_ClearStateBegun
_0814A58C: .4byte 0x0000046B
_0814A590: .4byte 0x082520E4
_0814A594:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A5A8
_0814A5A4:
	movs r0, #1
	b _0814A5AA
_0814A5A8:
	movs r0, #0
_0814A5AA:
	cmp r0, #0
	bne _0814A5D6
	adds r0, r5, #0
	bl enemy_dog_0814b500
	b _0814A5D6
_0814A5B6:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A5CA
	movs r0, #1
	b _0814A5CC
_0814A5CA:
	movs r0, #0
_0814A5CC:
	cmp r0, #0
	bne _0814A5D6
	adds r0, r5, #0
	bl enemy_dog_0814b500
_0814A5D6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
