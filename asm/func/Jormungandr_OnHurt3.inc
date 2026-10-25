	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r4, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C4784
	adds r0, r6, #0
	bl Hitbox_ApplyDamage
	ldr r0, _080C478C @ =0x00001912
	adds r1, r5, r0
	ldrh r0, [r4, #0x3e]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080C4790 @ =0x0000191C
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf
	strh r0, [r7]
	ldr r2, _080C4794 @ =0x000025C3
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080C4798 @ =0x000025F9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080c3d14
	ldr r2, _080C479C @ =0x000025CC
	adds r1, r5, r2
	ldrh r0, [r6, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x3e]
	ldr r1, [r6, #0x34]
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
_080C4784:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C478C: .4byte 0x00001912
_080C4790: .4byte 0x0000191C
_080C4794: .4byte 0x000025C3
_080C4798: .4byte 0x000025F9
_080C479C: .4byte 0x000025CC
