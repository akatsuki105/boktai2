	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E43B0
	cmp r1, #0
	blt _080E43B0
	ldr r0, _080E43B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E43B0
	ldr r0, _080E43B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E43BC
_080E43B0:
	movs r1, #0
	b _080E43CA
	.align 2, 0
_080E43B4: .4byte 0x030046A8
_080E43B8: .4byte 0x030046AC
_080E43BC:
	ldr r0, _080E4410 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080E43CA:
	ldr r2, _080E4414 @ =0x00000256
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	bne _080E4436
	mov r2, sp
	adds r3, r5, #0
	adds r3, #8
	ldrh r0, [r4]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldrb r4, [r5, #5]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	subs r3, r0, r4
	cmp r3, #0x80
	ble _080E441C
	ldr r0, _080E4418 @ =0xFFFFFF00
	adds r3, r3, r0
	b _080E442A
	.align 2, 0
_080E4410: .4byte 0x030046A4
_080E4414: .4byte 0x00000256
_080E4418: .4byte 0xFFFFFF00
_080E441C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r3, r0
	bge _080E442A
	movs r1, #0x80
	lsls r1, r1, #1
	adds r3, r3, r1
_080E442A:
	adds r0, r3, #0
	cmp r0, #0
	bge _080E4432
	rsbs r0, r0, #0
_080E4432:
	cmp r0, #0x30
	ble _080E443A
_080E4436:
	movs r0, #0
	b _080E443C
_080E443A:
	movs r0, #1
_080E443C:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
