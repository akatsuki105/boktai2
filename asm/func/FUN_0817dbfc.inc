	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r3, [r6, #8]
	ldr r4, [r6, #0xc]
	str r3, [sp, #0x10]
	str r4, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x66
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0817DC64 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0817DC68 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r2, _0817DC6C @ =0x0000079C
	adds r1, r5, r2
	str r3, [r1]
	str r4, [r1, #4]
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r0, _0817DC70 @ =0x0000079E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #0xf0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, #0xfc
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817DC74
	movs r0, #1
	b _0817DC76
	.align 2, 0
_0817DC64: .4byte 0xFFFF0000
_0817DC68: .4byte 0x0000FFFF
_0817DC6C: .4byte 0x0000079C
_0817DC70: .4byte 0x0000079E
_0817DC74:
	movs r0, #0
_0817DC76:
	cmp r0, #0
	beq _0817DC84
	ldr r1, _0817DC80 @ =0x000007A4
	b _0817DCA8
	.align 2, 0
_0817DC80: .4byte 0x000007A4
_0817DC84:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0817DC9C @ =0x00000898
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0817DCA0
	movs r0, #1
	b _0817DCA2
	.align 2, 0
_0817DC9C: .4byte 0x00000898
_0817DCA0:
	movs r0, #0
_0817DCA2:
	cmp r0, #0
	beq _0817DCB4
	ldr r1, _0817DCB0 @ =0x000007A5
_0817DCA8:
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0817DCDA
	.align 2, 0
_0817DCB0: .4byte 0x000007A5
_0817DCB4:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817DCC4
	movs r0, #1
	b _0817DCC6
_0817DCC4:
	movs r0, #0
_0817DCC6:
	cmp r0, #0
	beq _0817DCD8
	ldr r2, _0817DCD4 @ =0x000007A6
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0817DCDA
	.align 2, 0
_0817DCD4: .4byte 0x000007A6
_0817DCD8:
	movs r1, #0
_0817DCDA:
	add r0, sp, #0x10
	str r0, [sp]
	ldr r2, _0817DD04 @ =0x0000079C
	adds r0, r5, r2
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl ItemIconPopupManager_AddIcon
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0817DD04: .4byte 0x0000079C
