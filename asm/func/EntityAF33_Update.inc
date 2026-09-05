	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	cmp r0, #0
	beq _08050804
	movs r0, #0
	str r0, [r1]
	movs r0, #7
	bl FUN_0809c08c
	ldr r1, _080507F8 @ =FUN_0822db5c
	ldr r2, _080507FC @ =FUN_0822aaac
	ldr r3, _08050800 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _080507F0
	movs r1, #0
	bl Script_ExecById
_080507F0:
	adds r0, r4, #0
	bl KillEntity
	b _0805083A
	.align 2, 0
_080507F8: .4byte FUN_0822db5c
_080507FC: .4byte FUN_0822aaac
_08050800: .4byte FUN_0822f204
_08050804:
	bl FUN_0804e59c
	adds r6, r0, #0
	cmp r6, #0
	bne _0805083A
	ldr r1, _08050844 @ =0x085AB6A4
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r5, r4, #0
	adds r5, #0x2a
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805083A
	adds r0, r4, #0
	adds r0, #0x54
	bl FUN_0804e514
	cmp r0, #0
	blt _0805083A
	strb r6, [r5]
_0805083A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08050844: .4byte 0x085AB6A4
