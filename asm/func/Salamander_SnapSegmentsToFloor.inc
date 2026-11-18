	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AB6C4
	b _081AB7EE
_081AB6C4:
	movs r0, #0
	mov sb, r0
	ldr r0, _081AB6F0 @ =0x00000CAA
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	blt _081AB6D6
	b _081AB7EE
_081AB6D6:
	ldr r7, _081AB6F4 @ =0x00000676
	add r7, r8
	ldr r6, _081AB6F8 @ =0x00000674
	add r6, r8
	ldr r3, _081AB6FC @ =0x00000705
	add r3, r8
_081AB6E2:
	movs r1, #2
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081AB700
	movs r0, #1
	b _081AB702
	.align 2, 0
_081AB6F0: .4byte 0x00000CAA
_081AB6F4: .4byte 0x00000676
_081AB6F8: .4byte 0x00000674
_081AB6FC: .4byte 0x00000705
_081AB700:
	movs r0, #0
_081AB702:
	cmp r0, #0
	beq _081AB7D6
	movs r1, #1
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081AB714
	movs r0, #1
	b _081AB716
_081AB714:
	movs r0, #0
_081AB716:
	cmp r0, #0
	bne _081AB7D6
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AB73E
	cmp r1, #0
	blt _081AB73E
	ldr r0, _081AB744 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AB73E
	ldr r0, _081AB748 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AB74C
_081AB73E:
	movs r4, #0
	b _081AB75A
	.align 2, 0
_081AB744: .4byte 0x030046A8
_081AB748: .4byte 0x030046AC
_081AB74C:
	ldr r0, _081AB770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AB75A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp]
	bl Map_FindTileOverride
	ldr r3, [sp]
	cmp r0, #0
	beq _081AB774
	adds r0, #4
	b _081AB780
	.align 2, 0
_081AB770: .4byte 0x030046A4
_081AB774:
	ldr r0, _081AB794 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AB780:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AB798
	cmp r2, #2
	beq _081AB79C
	b _081AB7A0
	.align 2, 0
_081AB794: .4byte 0x030046A4
_081AB798:
	ldrb r0, [r5, #4]
	b _081AB79E
_081AB79C:
	ldrb r0, [r5]
_081AB79E:
	subs r1, r1, r0
_081AB7A0:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	beq _081AB7D6
	cmp r0, r1
	bge _081AB7C4
	subs r0, r1, r0
	cmp r0, #0
	bge _081AB7B4
	rsbs r0, r0, #0
_081AB7B4:
	cmp r0, #0xff
	ble _081AB7C0
	mov r1, sl
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _081AB7D6
_081AB7C0:
	strh r1, [r7]
	b _081AB7D6
_081AB7C4:
	subs r0, r1, r0
	movs r1, #0xa
	str r3, [sp]
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r7]
	ldr r3, [sp]
_081AB7D6:
	adds r7, #0xd0
	adds r6, #0xd0
	adds r3, #0xd0
	movs r2, #1
	add sb, r2
	ldr r0, _081AB800 @ =0x00000CAA
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	bge _081AB7EE
	b _081AB6E2
_081AB7EE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB800: .4byte 0x00000CAA
