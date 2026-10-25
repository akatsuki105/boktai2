	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r4, r7, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C9858
	movs r2, #0
	strb r2, [r6]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x10
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C9858:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080C993C
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	cmp r0, #0x1d
	ble _080C993C
	ldr r1, _080C98C0 @ =0x00001918
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _080C98C4 @ =0x0000260C
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C98E4
	subs r1, #0x20
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _080C98C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C98CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C98D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C98D8
	ldr r1, _080C98D4 @ =FUN_080c86ac
	movs r0, #0x14
	b _080C990A
	.align 2, 0
_080C98C0: .4byte 0x00001918
_080C98C4: .4byte 0x0000260C
_080C98C8: .4byte 0x030046B8
_080C98CC: .4byte 0x000003FF
_080C98D0: .4byte 0x0203B400
_080C98D4: .4byte FUN_080c86ac
_080C98D8:
	ldr r1, _080C98E0 @ =FUN_080c898c
	movs r0, #0x17
	b _080C990A
	.align 2, 0
_080C98E0: .4byte FUN_080c898c
_080C98E4:
	cmp r3, #1
	bne _080C9924
	ldr r0, _080C98FC @ =0x000025C9
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9904
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080C9900 @ =FUN_080c7e54
	movs r0, #0xb
	b _080C990A
	.align 2, 0
_080C98FC: .4byte 0x000025C9
_080C9900: .4byte FUN_080c7e54
_080C9904:
	strb r3, [r1]
	ldr r1, _080C9920 @ =FUN_080c81e0
	movs r0, #0xf
_080C990A:
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	strb r3, [r6]
	b _080C993C
	.align 2, 0
_080C9920: .4byte FUN_080c81e0
_080C9924:
	ldr r1, _080C9948 @ =FUN_080c8cc8
	movs r0, #0x1b
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	movs r0, #1
	strb r0, [r6]
_080C993C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9948: .4byte FUN_080c8cc8
