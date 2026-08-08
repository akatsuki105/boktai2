	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235F6C
	cmp r1, #0
	blt _08235F6C
	ldr r0, _08235F70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235F6C
	ldr r0, _08235F74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235F78
_08235F6C:
	movs r4, #0
	b _08235F86
	.align 2, 0
_08235F70: .4byte 0x030046A8
_08235F74: .4byte 0x030046AC
_08235F78:
	ldr r0, _08235F98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235F86:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235F9C
	adds r0, #4
	b _08235FA8
	.align 2, 0
_08235F98: .4byte 0x030046A4
_08235F9C:
	ldr r0, _08235FC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235FA8:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08235FC4
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235a84
	b _08235FC8
	.align 2, 0
_08235FC0: .4byte 0x030046A4
_08235FC4:
	movs r0, #0
	strh r0, [r6]
_08235FC8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
