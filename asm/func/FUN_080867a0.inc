	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, _080867D4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _0808683E
	ldr r1, _080867D8 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r4, r0, #0
	cmp r4, #1
	bne _080867E0
	adds r0, r5, #0
	bl FUN_08086080
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	strh r4, [r0]
	ldr r0, _080867DC @ =0x000003B6
	adds r1, r5, r0
	movs r0, #0x96
	lsls r0, r0, #1
	b _08086814
	.align 2, 0
_080867D4: .4byte 0x03002C00
_080867D8: .4byte 0x000001F5
_080867DC: .4byte 0x000003B6
_080867E0:
	cmp r4, #0
	beq _080867FE
	cmp r4, #2
	beq _080867FE
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0808683E
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808683E
_080867FE:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	bl FUN_080860cc
	ldr r0, _08086848 @ =0x000003B6
	adds r1, r5, r0
	movs r3, #0
	movs r0, #0x96
	lsls r0, r0, #2
_08086814:
	strh r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808684C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	bl Emote_Show
	str r0, [r4]
_0808683E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086848: .4byte 0x000003B6
_0808684C: .4byte 0x00000414
