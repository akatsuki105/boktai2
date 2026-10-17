	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08088310
	cmp r1, #0
	blt _08088310
	ldr r0, _08088314 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088310
	ldr r0, _08088318 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808831C
_08088310:
	movs r4, #0
	b _0808832A
	.align 2, 0
_08088314: .4byte 0x030046A8
_08088318: .4byte 0x030046AC
_0808831C:
	ldr r0, _0808833C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808832A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08088340
	adds r0, #4
	b _0808834C
	.align 2, 0
_0808833C: .4byte 0x030046A4
_08088340:
	ldr r0, _08088374 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808834C:
	ldrh r1, [r0, #2]
	ands r5, r1
	cmp r5, #0
	bne _08088426
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08088386
	movs r1, #0x10
	ldr r0, _08088378 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0808837C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08088380
	movs r0, #1
	b _08088382
	.align 2, 0
_08088374: .4byte 0x030046A4
_08088378: .4byte 0x030046A0
_0808837C: .4byte 0x00000934
_08088380:
	movs r0, #0
_08088382:
	cmp r0, #0
	bne _08088426
_08088386:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080883AA
	cmp r1, #0
	blt _080883AA
	ldr r0, _080883B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080883AA
	ldr r0, _080883B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080883B8
_080883AA:
	movs r4, #0
	b _080883C6
	.align 2, 0
_080883B0: .4byte 0x030046A8
_080883B4: .4byte 0x030046AC
_080883B8:
	ldr r0, _080883D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080883C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080883DC
	adds r0, #4
	b _080883E8
	.align 2, 0
_080883D8: .4byte 0x030046A4
_080883DC:
	ldr r0, _080883FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080883E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088400
	cmp r2, #2
	beq _08088404
	b _08088408
	.align 2, 0
_080883FC: .4byte 0x030046A4
_08088400:
	ldrb r0, [r6, #4]
	b _08088406
_08088404:
	ldrb r0, [r6]
_08088406:
	subs r1, r1, r0
_08088408:
	movs r2, #2
	ldrsh r0, [r7, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088414
	rsbs r0, r0, #0
_08088414:
	cmp r0, #0x32
	bgt _08088426
	adds r0, r6, #0
	bl Elevator_FindAtPos
	cmp r0, #0
	bne _08088426
	movs r0, #1
	b _08088428
_08088426:
	movs r0, #0
_08088428:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
