	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	mov r6, sp
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080d21d0
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080D2294
	cmp r1, #0
	blt _080D2294
	ldr r0, _080D229C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080D2294
	ldr r0, _080D22A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D22A8
_080D2294:
	movs r4, #0
	ldr r2, _080D22A4 @ =0x030046A4
	b _080D22B6
	.align 2, 0
_080D229C: .4byte 0x030046A8
_080D22A0: .4byte 0x030046AC
_080D22A4: .4byte 0x030046A4
_080D22A8:
	ldr r2, _080D22C4 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080D22B6:
	ldr r0, [r2]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _080D22C8
	movs r0, #0
	b _080D22CE
	.align 2, 0
_080D22C4: .4byte 0x030046A4
_080D22C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r0, r2, r0
_080D22CE:
	mov r5, sp
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D22E2
	movs r0, #1
	b _080D2304
_080D22E2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D2302
	adds r0, #4
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D2302
	movs r0, #2
	b _080D2304
_080D2302:
	movs r0, #0
_080D2304:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
