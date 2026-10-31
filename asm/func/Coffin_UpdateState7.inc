	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080890F0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080890A0
	adds r0, r5, #0
	movs r1, #7
	bl Coffin_SetState
_080890A0:
	ldr r1, _080890F4 @ =0x0000032A
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080890FC
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089132
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _080890F8 @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	bl Emote_Show
	str r0, [r4]
	b _08089132
	.align 2, 0
_080890F0: .4byte 0x000001F5
_080890F4: .4byte 0x0000032A
_080890F8: .4byte 0x00000414
_080890FC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _08089118
	ldr r1, _0808913C @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl Emote_Remove
	str r0, [r4]
_08089118:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x3c
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #0x1d
	bls _08089132
	ldr r0, _08089140 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089132:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808913C: .4byte 0x00000414
_08089140: .4byte 0x0000040B
