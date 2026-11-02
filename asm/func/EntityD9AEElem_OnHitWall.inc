	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r4, #0x10]
	adds r0, r4, #0
	bl EntityD9AEElem_IsFacingWall
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003484
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _08003408
	cmp r0, #1
	bgt _080033E2
	cmp r0, #0
	beq _080033EC
	b _0800345A
_080033E2:
	cmp r0, #2
	beq _08003428
	cmp r0, #3
	beq _08003444
	b _0800345A
_080033EC:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003404 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0xb0
	b _0800345A
	.align 2, 0
_08003404: .4byte 0xFFFF0000
_08003408:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003424 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x10
	rsbs r1, r1, #0
	b _0800345A
	.align 2, 0
_08003424: .4byte 0xFFFF0000
_08003428:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003440 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0x30
	b _0800345A
	.align 2, 0
_08003440: .4byte 0xFFFF0000
_08003444:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800348C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x70
_0800345A:
	str r1, [sp]
	movs r0, #0x1f
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #2
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015ce0
	ldrb r0, [r4]
	bl EntityD9AE_PlayHitWallSound
_08003484:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800348C: .4byte 0xFFFF0000
