	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	ldr r2, _080EC4A0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080EC4A4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080EC4A8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r7, #0
_080EC466:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl GetNormalItemID
	mov r1, r8
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080EC480
	cmp r0, #0x14
	bne _080EC4AC
_080EC480:
	adds r0, r4, #1
	movs r1, #0x10
	bl Mod
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble _080EC466
	movs r0, #0
	b _080EC4BC
	.align 2, 0
_080EC4A0: .4byte 0x030046B8
_080EC4A4: .4byte 0x000003FF
_080EC4A8: .4byte 0x0203B400
_080EC4AC:
	strh r5, [r6]
	movs r1, #0
	ldrsh r0, [r6, r1]
	bl GetRotCount
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_080EC4BC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
