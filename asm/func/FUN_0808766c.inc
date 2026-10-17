	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087716
	ldr r2, _080876B4 @ =0x000001F5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08087716
	adds r6, r5, #0
	adds r6, #0x48
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080876AE
	cmp r1, #0
	blt _080876AE
	ldr r0, _080876B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080876AE
	ldr r0, _080876BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080876C0
_080876AE:
	movs r4, #0
	b _080876CE
	.align 2, 0
_080876B4: .4byte 0x000001F5
_080876B8: .4byte 0x030046A8
_080876BC: .4byte 0x030046AC
_080876C0:
	ldr r0, _080876E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080876CE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080876E4
	adds r0, #4
	b _080876F0
	.align 2, 0
_080876E0: .4byte 0x030046A4
_080876E4:
	ldr r0, _08087704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080876F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087708
	cmp r2, #2
	beq _0808770C
	b _08087710
	.align 2, 0
_08087704: .4byte 0x030046A4
_08087708:
	ldrb r0, [r6, #4]
	b _0808770E
_0808770C:
	ldrb r0, [r6]
_0808770E:
	subs r1, r1, r0
_08087710:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r1, [r0]
_08087716:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, _08087784 @ =0x0000031E
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0xa0
	strh r0, [r1]
	subs r1, #0x56
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa2
	strh r0, [r1]
	subs r1, #0x56
	adds r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa4
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xdc
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087780
	cmp r1, #0
	blt _08087780
	ldr r0, _08087788 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087780
	ldr r0, _0808778C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087790
_08087780:
	movs r0, #0
	b _0808779E
	.align 2, 0
_08087784: .4byte 0x0000031E
_08087788: .4byte 0x030046A8
_0808778C: .4byte 0x030046AC
_08087790:
	ldr r0, _080877B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0808779E:
	adds r2, r5, #0
	adds r2, #0xd2
	strh r0, [r2]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080877BC
	adds r2, r0, #4
	b _080877C8
	.align 2, 0
_080877B8: .4byte 0x030046A4
_080877BC:
	ldr r0, _08087810 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r2, r1, r0
_080877C8:
	ldrb r0, [r2]
	lsrs r0, r0, #4
	adds r1, r5, #0
	adds r1, #0xd7
	strb r0, [r1]
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0xd5
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r2, r5, #0
	adds r2, #0xda
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_080875e8
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08087814 @ =0x0000038E
	adds r0, r5, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087810: .4byte 0x030046A4
_08087814: .4byte 0x0000038E
