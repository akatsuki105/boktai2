	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814442E
	b _08144600
_0814442E:
	ldr r2, _08144448 @ =0x00000553
	adds r0, r4, r2
	ldrb r2, [r0]
	cmp r2, #0
	beq _08144440
	cmp r2, #0x24
	beq _08144440
	cmp r2, #0x25
	bne _0814444C
_08144440:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	b _0814452C
	.align 2, 0
_08144448: .4byte 0x00000553
_0814444C:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144526
	cmp r2, #0x22
	bne _08144532
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08144486
	cmp r1, #0
	blt _08144486
	ldr r0, _0814448C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144486
	ldr r0, _08144490 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144494
_08144486:
	movs r5, #0
	b _081444A2
	.align 2, 0
_0814448C: .4byte 0x030046A8
_08144490: .4byte 0x030046AC
_08144494:
	ldr r0, _081444B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081444A2:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081444B8
	adds r0, #4
	b _081444C4
	.align 2, 0
_081444B4: .4byte 0x030046A4
_081444B8:
	ldr r0, _081444FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081444C4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, #0x7e
	adds r1, r1, r2
	cmp r0, r1
	bge _08144526
	ldr r1, _08144500 @ =gSineTable
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08144504
	asrs r2, r0, #0xc
	b _0814450A
	.align 2, 0
_081444FC: .4byte 0x030046A4
_08144500: .4byte gSineTable
_08144504:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814450A:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xce
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _08144526
	adds r0, #1
	strb r0, [r1]
_08144526:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
_0814452C:
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	b _08144600
_08144532:
	ldr r2, _08144560 @ =0x00000472
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r3, #0xa
	ldrsh r0, [r4, r3]
	ldr r2, _08144564 @ =0xFFFFFEC0
	adds r0, r0, r2
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _0814454A
	rsbs r0, r1, #0
_0814454A:
	cmp r0, #0x10
	ble _08144574
	cmp r1, #0
	bge _08144568
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #2
	b _08144572
	.align 2, 0
_08144560: .4byte 0x00000472
_08144564: .4byte 0xFFFFFEC0
_08144568:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #2
_08144572:
	strh r0, [r1]
_08144574:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldr r2, _081445A4 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08144600
	ldr r3, [r4, #0x44]
	adds r2, r3, #0
	adds r2, #0x48
	ldrh r0, [r2, #8]
	cmp r0, #4
	bhi _08144600
	lsls r0, r0, #2
	ldr r1, _081445A8 @ =_081445AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081445A4: .4byte 0x00000553
_081445A8: .4byte _081445AC
_081445AC: @ jump table
	.4byte _081445C0 @ case 0
	.4byte _081445C6 @ case 1
	.4byte _081445D4 @ case 2
	.4byte _081445E4 @ case 3
	.4byte _081445F2 @ case 4
_081445C0:
	ldrh r0, [r3, #0x1e]
	adds r0, #0x18
	b _081445FE
_081445C6:
	ldrh r1, [r3, #0x1e]
	adds r1, #0x18
	ldrh r0, [r2, #0xe]
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r1, [r3, #0x1e]
	b _08144600
_081445D4:
	ldrh r0, [r3, #0x1e]
	adds r0, #0x3e
	ldrh r2, [r2, #0xe]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r0, r0, r1
	b _081445FE
_081445E4:
	ldrh r1, [r3, #0x1e]
	adds r1, #2
	ldrh r0, [r2, #0xe]
	lsls r0, r0, #3
	subs r1, r1, r0
	strh r1, [r3, #0x1e]
	b _08144600
_081445F2:
	ldrh r0, [r3, #0x1e]
	subs r0, #0x16
	ldrh r2, [r2, #0xe]
	lsls r1, r2, #3
	subs r1, r1, r2
	adds r0, r0, r1
_081445FE:
	strh r0, [r3, #0x1e]
_08144600:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
