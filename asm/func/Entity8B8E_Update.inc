	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x10
	ldr r2, _081E8404 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E8408
	movs r0, #1
	b _081E840A
	.align 2, 0
_081E8404: .4byte 0x00001610
_081E8408:
	movs r0, #0
_081E840A:
	cmp r0, #0
	bne _081E8414
	ldr r1, _081E8434 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E8414:
	bl LinkShopManager_IsFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E8454
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, _081E8438 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E843C
	movs r0, #1
	b _081E843E
	.align 2, 0
_081E8434: .4byte 0x030047B8
_081E8438: .4byte 0x00001610
_081E843C:
	movs r0, #0
_081E843E:
	cmp r0, #0
	bne _081E8454
	adds r0, r4, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081E8462
_081E8454:
	ldr r1, [r4, #0x18]
	cmp r1, #0
	beq _081E8460
	adds r0, r4, #0
	bl _call_via_r1
_081E8460:
	movs r0, #1
_081E8462:
	pop {r4}
	pop {r1}
	bx r1
